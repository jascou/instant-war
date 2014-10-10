package ;

import flash.display.Bitmap;
import flash.display.Sprite;
import flash.events.Event;
import flash.events.KeyboardEvent;
import flash.events.MouseEvent;
import flash.geom.Rectangle;
import flash.system.Capabilities;
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
	
	private var _xmlLoader:URLLoader;

	private var selectX:Int;
	private var selectY:Int;
	private var selectNum:Int;
	private var movesX:Array<Int>;
	private var movesY:Array<Int>;
	
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
	
		movesX = new Array();
		movesY = new Array();
		movesX[0] = -1;
		
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
		
		//stage.addEventListener (KeyboardEvent.KEY_DOWN, stage_onKeyDown);
		//stage.addEventListener (KeyboardEvent.KEY_UP, stage_onKeyUp);
		stage.addEventListener(MouseEvent.MOUSE_MOVE, onMouseMove);
		stage.addEventListener(MouseEvent.MOUSE_DOWN, onMouseDown);
			
	}

	/* SETUP */

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
	
	private function stage_onKeyDown (event:KeyboardEvent):Void 
	{
		gameEgo.sendCode(event.keyCode);
	}

	
	private function stage_onKeyUp (event:KeyboardEvent):Void {
		gameEgo.stopCode();
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
	
	private function onMouseMove(e:MouseEvent) 
	{
		var cx:Int;
		var cy:Int;
		
		cx = gameEgo.getMap().getCoord("x", Std.int(e.stageX), Std.int(e.stageY));
		cy = gameEgo.getMap().getCoord("y", Std.int(e.stageX), Std.int(e.stageY));
		
		if (cy % 2 == 0)
			gameEgo.moveTo(cx * 64 + 10, Std.int(cy * 54.5) - 0);
		else
			gameEgo.moveTo(cx * 64 + 10 - 32, Std.int(cy * 54.5) - 0);
	}
	
	private function onMouseDown(e:MouseEvent)
	{
		var cresults:Array<Int>;
		var crange:Int;
		var i:Int;
		var j:Int;
		var k:Int;
		
		var cx:Int;
		var cy:Int;
		var mPoint:Int;
		
		cresults = new Array();
		cresults[0] = -1;
		cresults[1] = -1;
		cresults[2] = 9999;
		
		cx = gameEgo.getMap().getCoord("x", Std.int(e.stageX), Std.int(e.stageY));
		cy = gameEgo.getMap().getCoord("y", Std.int(e.stageX), Std.int(e.stageY));
		
		i = 0;
		
		while (i < 100)
		{
			gameMoves[i].dropOnSq( -5, -5);
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
				crange = gameSc.getMovement(gameSc.getCounter(cx, cy, 1));
				
				i = cy - (crange + 2);
				selectX = cx;
				selectY = cy;
				selectNum = gameSc.getCounter(cx, cy, 1);
				
				while (i < cy + (crange + 2)) 
				{
					j = cx - (crange + 2);
					while (j < cx + (crange + 2))
					{
						if (i == cy && j == cx)
						{
							gameEgoStrike.dropOnSq(j, i);
							j++;
						}
						else
						{
							cresults[0] = -1;
							cresults[1] = -1;
							cresults[2] = 9999;
							cresults[3] = 9999;
						
							gameSc.findPath(cx, cy, j, i, 0, cresults);
							
							if (cresults[2] < (crange + 1) || cresults[3] == 1)
							{
								gameMoves[k].dropOnSq(j, i);
								movesX[k] = j;
								movesY[k] = i;
								movesX[k + 1] = -1;
								k++;
							}
						
							j++;
						}
					}
					i++;
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
