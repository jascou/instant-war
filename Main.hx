package ;

import flash.display.Bitmap;
import flash.display.Sprite;
import flash.events.Event;
import flash.events.KeyboardEvent;
import flash.events.MouseEvent;
import flash.geom.Rectangle;
import flash.system.Capabilities;
import flash.text.TextField;
import flash.text.TextFormat;
import flash.ui.Keyboard;
import flash.system.Capabilities.screenResolutionX;
import flash.system.Capabilities.screenResolutionY;
import flash.Lib;
import haxe.Timer;
import openfl.Assets;

import flash.net.URLLoader;
import flash.net.URLRequest;

import tenblock.*;

class Main extends Sprite 
{
	var inited:Bool;
	private var gameImages:Array<GameSprite>;
	private var gameMoves:Array<GameSprite>;
	private var gameAttacks:Array<GameSprite>;
	
	private var MainPl:Sprite;
	private var MainFr:Int;
	
	private var gameTime:Int;
	private var animTime:Int;
	private var doAnim:haxe.Timer;
	
	private var gameEgo:GameEgo;
	private var gameEgoStrike:GameSprite;
	private var gameMap:GameMap;
	private var sprPack:SpritePack;
	private var gameSc:Scenario;
	
	private var egoWidth:Int;
	private var egoHeight:Int;
	
	private var gameSide:Int;
	private var toolbar:Bitmap;
	
	private var _xmlLoader:URLLoader;

	private var selectX:Int;
	private var selectY:Int;
	private var selectNum:Int;
	private var movesX:Array<Int>;
	private var movesY:Array<Int>;
	private var attacksX:Array<Int>;
	private var attacksY:Array<Int>;
	private var attacksNum:Array<Int>;
	
	private var moveFlag:Array<Int>;
	private var attackFlag:Array<Int>;
	
	private var toolUp:Array<Bitmap>;
	private var toolDown:Array<Bitmap>;
	private var toolX:Array<Int>;
	private var toolY:Array<Int>;
	
	private var lastX:Int;
	private var lastY:Int;
	
	private var ts:TextFormat;
	private var p:TextField;
	
	/* ENTRY POINT */
	
	function resize(e) 
	{
		if (!inited) init();
		// else (resize or orientation change)
	}
	
	function init() 
	{
		var dirs : Array<Int> = [2,0,1,3];
		var i:Int;
		
		egoWidth = 65;
		egoHeight = 75;
		
		if (inited) return;
		inited = true;

		stage.scaleMode = NO_SCALE;
		if (Capabilities.screenResolutionX == 13660)
			stage.displayState = FULL_SCREEN;
		else
			stage.displayState = NORMAL;
		
		// (your code here)
		var gameMap = new GameMap("xml/gamemap.xml");
		gameMap.setAnchorX(10);
		gameMap.setAnchorY(0);
		gameMap.setCanvas(this);
		gameMap.drawMap();
		
		sprPack = new SpritePack("xml/gamesprites.xml");
		gameSc = new Scenario("xml/scenario1.xml");
		gameSc.setCMP(this, gameMap, sprPack);
		gameSc.doDraw();
		
		MainPl = new Sprite();
		gameImages = new Array();
		gameMoves = new Array();
		gameAttacks = new Array();
	
		movesX = new Array();
		movesY = new Array();
		moveFlag = new Array();
		attackFlag = new Array();
		movesX[0] = -1;
		
		attacksX = new Array();
		attacksY = new Array();
		attacksNum = new Array();
		attacksX[0] = -1;
		
		toolUp = new Array();
		toolDown = new Array();
		toolX = new Array();
		toolY = new Array();
		
		selectX = -1;
		selectY = -1;
		selectNum = -1;
		
		i = 0;
		
		while (i < 100)
		{
			gameMoves[i] = new GameSprite(new Bitmap (Assets.getBitmapData ("img/move.png")), "move1", "move", 3, 4, 65, 75);
			gameMoves[i].setCanvas(this);
			gameMoves[i].setMap(gameMap);
			gameMoves[i].drawAt( -150, -150);

			i++;
		}

		i = 0;
		
		while (i < 50)
		{
			gameAttacks[i] = new GameSprite(new Bitmap (Assets.getBitmapData ("img/attack.png")), "attack1", "attack", 3, 4, 65, 75);
			gameAttacks[i].setCanvas(this);
			gameAttacks[i].setMap(gameMap);
			gameAttacks[i].drawAt( -150, -150);

			i++;
		}
		
		gameEgoStrike = new GameSprite(new Bitmap (Assets.getBitmapData ("img/select.png")), "estrike1", "estrike", 3, 4, 65, 75);
		gameEgo = new GameEgo(new Bitmap (Assets.getBitmapData ("img/highlight.png")), "ego1", "ego", 3, 4, 65, 75);
		
		gameEgoStrike.setCanvas(this);
		gameEgoStrike.setMap(gameMap);
		gameEgoStrike.drawAt(-100, -100);
		
		gameEgo.setMap(gameMap);
		gameEgo.setCanvas(this);
		gameEgo.drawAt(350, 250);
			
		MainFr = 0;
		
		gameTime = 0;
		animTime = 1;
		gameSide = 1;
		
		i = 0;
		
		while (i < 100)
		{
			moveFlag[i] = 1;
			attackFlag[i] = 1;
			i++;
		}
		
		toolbar = new Bitmap (Assets.getBitmapData ("img/toolbar.png"));
		this.addChild(toolbar);
		toolbar.x = 1200;
		toolbar.y = 0;
		
		addTool(0, "img/next_up.png", "img/next_down.png", 1213, 10);
				
		lastX = -1;
		lastY = -1;
		
		stage.addEventListener (KeyboardEvent.KEY_DOWN, onKeyDown);
		stage.addEventListener(MouseEvent.MOUSE_MOVE, onMouseMove);
		stage.addEventListener(MouseEvent.MOUSE_DOWN, onMouseDown);
		stage.addEventListener (MouseEvent.MOUSE_UP, onMouseUp);
			
		ts = new flash.text.TextFormat();
        ts.font = "Courier"; // set the font
        ts.size = 16;                // set the font size
        ts.color=0xFFFFFF;           // set the color
        p = new flash.text.TextField();
        p.text = "";
        p.setTextFormat(ts);
		p.x = 0;
		p.y = 0;
		p.width = 500;
        this.addChild(p);
		
		gameSc.setText(p, ts);
	}

	public function addTool(cnum:Int, cup:String, cdown:String, cx:Int, cy:Int)
	{
		toolUp[cnum] = new Bitmap (Assets.getBitmapData (cup));
		toolDown[cnum] = new Bitmap (Assets.getBitmapData (cdown));
		toolX[cnum] = cx;
		toolY[cnum] = cy;
		this.addChild(toolUp[cnum]);
		this.addChild(toolDown[cnum]);
		toolUp[cnum].x = toolX[cnum];
		toolUp[cnum].y = toolY[cnum];
		toolDown[cnum].x = -500;
		toolDown[cnum].y = -500;
	}
	
	public function new() 
	{
		super();	
		addEventListener(Event.ADDED_TO_STAGE, added);
	}

	function added(e) 
	{
		removeEventListener(Event.ADDED_TO_STAGE, added);
		stage.addEventListener(Event.RESIZE, resize);
		#if ios
		haxe.Timer.delay(init, 100); // iOS 6
		#else
		init();
		#end
	}
	
	public static function main() 
	{
		// static entry point
		Lib.current.stage.align = flash.display.StageAlign.TOP_LEFT;
		Lib.current.stage.scaleMode = flash.display.StageScaleMode.NO_SCALE;
		Lib.current.addChild(new Main());
	}

	private function doSpriteOrder(csprs:Array<GameSprite>)
	{
		var i:Int;
		var j:Int;
		var k:Int;
		var l:Int;
		var cln:Int;
		var cmark:Array<Int> = new Array();
		
		i = 0;
		while (i < csprs.length)
		{
			cmark[i] = 0;
			i++;
		}
		
		i = 1;
		j = 0;
		k = -1;
		l = 0;
		
		while (l != -1)
		{
			j = 0;
			l = -1;
			
			while (j < csprs.length)
			{
				if (csprs[j].getFeetY() > k && cmark[j] == 0)
				{
					l = j;
					k = csprs[j].getFeetY();
				}
				
				j++;
			}
			
			if (l != -1)
			{
				cmark[l] = 1;
				this.setChildIndex(csprs[l], this.numChildren - i);
				i++;
				k = -1;
			}
		}
	}
		
	private function this_onEnterFrame (event:Event):Void 
	{
		
		if (gameTime >= animTime) {

			if (animTime < gameTime) animTime = gameTime;
			
			MainFr++;
			if (MainFr > 3) MainFr = 0;
			
			//gameEgo.setFrame(MainFr);
			
			if (MainFr < 3) {
				gameImages[0].x = -(60 * MainFr);
			} else {
				gameImages[0].x = -(60 * (4 - MainFr));
			}
			
			animTime++;
		}
		
	}
	
	private function _loadXML():Void
	{
		trace( "Main._loadXML" );
		_xmlLoader = new URLLoader( );
		_xmlLoader.addEventListener( Event.COMPLETE, _onXMLLoaded );
		_xmlLoader.load(new URLRequest("assets/xml/sample.xml"));
	}

	private function _onXMLLoaded(e:Event):Void 
	{
		trace( e.target.data );
	}
	
	private function onKeyDown (e:KeyboardEvent):Void 
	{
		var i:Int;
		var xs:Int;
		var ys:Int;
		var cmult:Int;
		
		i = 0;
		xs = 0;
		ys = 0;
		cmult = 10;
		
		if (e.keyCode >= 37 && e.keyCode <= 40)
		{
			if (e.keyCode == 39)
			{
				xs = -cmult;
				ys = 0;
				
				if (1275 - this.x > (gameEgo.getMap().getWidth() + 1) * gameEgo.getMap().getTileWidth())
					xs = 0;
			}
			else if (e.keyCode == 40)
			{
				xs = 0;
				ys = -cmult;
				
				if (673 - this.y > gameEgo.getMap().getHeight() * gameEgo.getMap().getTileWidth() * 0.86)
					ys = 0;
			}
			else if (e.keyCode == 37)
			{
				xs = cmult;
				ys = 0;
				
				if (this.x == 0) xs = 0;
			}
			else if (e.keyCode == 38)
			{
				xs = 0;
				ys = cmult;
				
				if (this.y == 0) ys = 0;
			}
			
			
			this.x += xs;
			this.y += ys;
			
			toolbar.x = 1200 - this.x;
			toolbar.y = -this.y;
			
			while (i < toolUp.length)
			{
				toolUp[i].x = toolX[i] - this.x;
				toolUp[i].y = toolY[i] - this.y;
				
				if (toolDown[i].x > 0) 
				{
					toolDown[i].x = toolX[i] - this.x;
					toolDown[i].y = toolY[i] - this.y;
				}
				
				i++;
			}
		}
	}

	private function onMouseUp (e:MouseEvent)
	{
		lastX = -1;
		lastY = -1;
	}
		
	private function onMouseMove(e:MouseEvent) 
	{
		var i:Int;
		
		var cx:Int;
		var cy:Int;
		
		var chgX:Int;
		var chgY:Int;
		
		if (lastX >= 0)
		{
			chgX = Std.int((Std.int(e.stageX) - lastX) / 1);
			chgY = Std.int((Std.int(e.stageY) - lastY) / 1);
			
			if (chgX > 50) chgX = 0;
			if (chgY > 50) chgY = 0;
			
			this.x += chgX;
			this.y += chgY;
			
			if (this.x > 0) this.x = 0;
			else if (this.x < 1275 - (gameEgo.getMap().getWidth() + 1) * gameEgo.getMap().getTileWidth())
				this.x = 1275 - (gameEgo.getMap().getWidth() + 1) * gameEgo.getMap().getTileWidth();
			
			if (this.y > 0) this.y = 0;
			else if (this.y < 673 - (gameEgo.getMap().getHeight() * gameEgo.getMap().getTileWidth() * 0.86))
				this.y = 673 - (gameEgo.getMap().getHeight() * gameEgo.getMap().getTileWidth() * 0.86);
			
			toolbar.x = 1200 - this.x;
			toolbar.y = -this.y;
			
			i = 0;
			
			while (i < toolUp.length)
			{
				toolUp[i].x = toolX[i] - this.x;
				toolUp[i].y = toolY[i] - this.y;
				
				if (toolDown[i].x > 0) 
				{
					toolDown[i].x = toolX[i] - this.x;
					toolDown[i].y = toolY[i] - this.y;
				}
				
				i++;
			}
			
			lastX = Std.int(e.stageX);
			lastY = Std.int(e.stageY);
		}
		
		if (e.stageX < 1200)
		{
			cx = gameEgo.getMap().getCoord("x", Std.int(e.stageX) - Std.int(this.x), Std.int(e.stageY) - Std.int(this.y));
			cy = gameEgo.getMap().getCoord("y", Std.int(e.stageX) - Std.int(this.x), Std.int(e.stageY) - Std.int(this.y));
			
			if (cy % 2 == 0)
				gameEgo.moveTo(cx * 64 + 10, Std.int(cy * 54.5) - 0);
			else
				gameEgo.moveTo(cx * 64 + 10 - 32, Std.int(cy * 54.5) - 0);
		}
		
		cx = Std.int(e.stageX) - Std.int(this.x);
		cy = Std.int(e.stageY) - Std.int(this.y);
		i = 0;
			
		while (i < toolUp.length)
		{
			if (cx >= toolX[i] - this.x && cx <= toolX[i] - this.x + 50 && cy >= toolY[i] - this.y && cy <= toolY[i] - this.y + 50)
			{
				toolDown[i].x = toolX[i] - this.x;
				toolDown[i].y = toolY[i] - this.y;
			}
			else
			{
				toolDown[i].x = -1000;
				toolDown[i].y = -1000;
			}
				
			i++;
		}
	}
	
	private function onMouseDown(e:MouseEvent)
	{
		var cresults:Array<Int>;
		var crange:Int;
		var crange2:Int;
		var i:Int;
		var j:Int;
		var k:Int;
		
		var cx:Int;
		var cy:Int;
		var mPoint:Int;
		
		lastX = Std.int(e.stageX);
		lastY = Std.int(e.stageY);
		
		cx = Std.int(e.stageX) - Std.int(this.x);
		cy = Std.int(e.stageY) - Std.int(this.y);
		i = 0;
		j = 0;
			
		while (i < toolUp.length)
		{
			if (cx >= toolX[i] - this.x && cx <= toolX[i] - this.x + 50 && cy >= toolY[i] - this.y && cy <= toolY[i] - this.y + 50)
			{
				if (i == 0) 
				{
					gameSide = 2;
					gameSc.runAI();
				
					j = 0;
					while (j < moveFlag.length)
					{
						moveFlag[j] = 1;
						attackFlag[j] = 1;
						
						if (gameSc.getSides(j) == "e" && gameSc.getDisperse(j) == 1)
							gameSc.doRevive(j);
						
						j++;
					}
					
					gameSide = 1;
				}
			}
				
			i++;
		}

		cx = gameEgo.getMap().getCoord("x", Std.int(e.stageX) - Std.int(this.x), Std.int(e.stageY) - Std.int(this.y));
		cy = gameEgo.getMap().getCoord("y", Std.int(e.stageX) - Std.int(this.x), Std.int(e.stageY) - Std.int(this.y));
		
		if (gameSide == 1)
		{			
			cresults = new Array();
			cresults[0] = -1;
			cresults[1] = -1;
			cresults[2] = 9999;
			
			i = 0;
			
			while (i < 100)
			{
				gameMoves[i].dropOnSq( -5, -5);
				if (i < 50) gameAttacks[i].dropOnSq( -5, -5);  
				i++;
			}
			
			if (cx == selectX && cy == selectY)
			{
				gameEgoStrike.dropOnSq( -5, -5);
				selectX = -1;
				selectY = -1;
				selectNum = -1;
			}
			else
			{	
				k = 0;
				
				if (gameSc.getCount(cx, cy, "a") > 0)
				{
					crange2 = gameSc.getMovement(gameSc.getCounter(cx, cy, 1));	
					crange = Std.int(crange2 / 10) + 1;	
					
					i = cy - (crange * 2 + 1);
					
					selectX = cx;
					selectY = cy;
					selectNum = gameSc.getCounter(cx, cy, 1);
					
					if (moveFlag[selectNum] == 1 && gameSc.getDisperse(selectNum) == 0)
					{						
						while (i < cy + (crange * 2 + 1)) 
						{
							j = cx - (crange * 2 + 1);
							while (j < cx + (crange * 2 + 1))
							{
								if (i == cy && j == cx)
								{
									gameEgoStrike.dropOnSq(j, i);
								}
								else
								{
									cresults[0] = -1;
									cresults[1] = -1;
									cresults[2] = 9999;
									cresults[3] = 9999;
									
									gameSc.findPath(cx, cy, j, i, gameSc.getName(selectNum), 0, cresults);
									
									if (cresults[2] <= crange2 || cresults[3] == 1)
									{
										gameMoves[k].dropOnSq(j, i);
										movesX[k] = j;
										movesY[k] = i;
										movesX[k + 1] = -1;
										k++;
									}
								}
								
								j++;
							}
							i++;
						}
					}
					
					if (attackFlag[selectNum] == 1)
					{
						i = 0;
						k = 0;
						
						while (i < gameSc.counterCount())
						{
							cresults[0] = -1;
							cresults[1] = -1;
							cresults[2] = 9999;
							cresults[3] = 9999;
							
							gameSc.findAttack(i, cx, cy, 1, cresults);
							
							if (cresults[0] != -1)
							{
								gameAttacks[k].dropOnSq(cresults[0], cresults[1]);
								attacksX[k] = cresults[0];
								attacksY[k] = cresults[1];
								attacksNum[k] = i;
								attacksX[k + 1] = -1;
								
								k++;
							}
							
							i++;
						}
					}
				}
				else if (selectNum != -1)
				{
					j = 0;
					k = 0;
					
					while (movesX[k] != -1)
					{
						if (movesX[k] == cx && movesY[k] == cy)
							j = 1;
						
						k++;
					}
					
					if (j == 1)
					{
						gameSc.dropCounter(selectNum, cx, cy);
						moveFlag[selectNum] = -1;
					}
					
					j = -1;
					k = 0;

					while (attacksX[k] != -1)
					{
						if (attacksX[k] == cx && attacksY[k] == cy)
							j = k;
						
						k++;
					}
					
					if (j != -1)
					{
						gameSc.doAttack(selectNum, attacksNum[j]);
						attackFlag[selectNum] = -1;
					}
					
					gameEgoStrike.dropOnSq( -5, -5);
					selectX = -1;
					selectY = -1;
					selectNum = -1;
				}
				else
				{
					gameEgoStrike.dropOnSq( -5, -5);
					selectX = -1;
					selectY = -1;
					selectNum = -1;
				}
			}
		}
	}
}
