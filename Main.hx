package ;

import flash.display.Bitmap;
import flash.display.Sprite;
import flash.events.Event;
import flash.events.KeyboardEvent;
import flash.events.MouseEvent;
import flash.geom.Rectangle;
import flash.system.Capabilities;
import flash.text.TextField;
import flash.text.TextFieldType;
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
	
	// GameSprite arrays that hold hex highlights for movement and attacks
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
	private var alertbox:Bitmap;
	private var boxx:Int;
	private var boxy:Int;
	
	private var _xmlLoader:URLLoader;

	private var selectX:Int;
	private var selectY:Int;
	private var selectNum:Int;

	// name of SpritePack and Scenario files
	private var packName:String;
	private var scName:String;
	
	// Int arrays to hold potential move and attack locations for player
	private var movesX:Array<Int>;
	private var movesY:Array<Int>;
	private var attacksX:Array<Int>;
	private var attacksY:Array<Int>;
	private var attacksNum:Array<Int>;
	
	// flags to indicate whether moves or attacks have been performed for given counter
	private var moveFlag:Array<Int>;
	private var attackFlag:Array<Int>;
	
	private var toolUp:Array<Bitmap>;
	private var toolDown:Array<Bitmap>;
	private var toolX:Array<Int>;
	private var toolY:Array<Int>;
	
	private var lastX:Int;
	private var lastY:Int;
	
	private var ts:TextFormat;
	private var ts1:TextFormat;
	private var p:TextField;
	private var console:TextField;
	private var cout:TextField;
	
	private var gameTurn:Int;
	
	function resize(e) 
	{
		if (!inited) init();
		// else (resize or orientation change)
	}
	
	function init() 
	{
		var dirs : Array<Int> = [2,0,1,3];
		var i:Int;
		
		// set location of alertbox
		boxx = 410;
		boxy = 250;
		
		// set width of player hex highlighter
		egoWidth = 65;
		egoHeight = 75;
		
		if (inited) return;
		inited = true;

		stage.scaleMode = NO_SCALE;
		if (Capabilities.screenResolutionX == 13660)
			stage.displayState = FULL_SCREEN;
		else
			stage.displayState = NORMAL;
		
		// load and draw initial GameMap
		gameMap = new GameMap("xml/gamemap.xml");
		gameMap.setAnchorX(10);
		gameMap.setAnchorY(0);
		gameMap.setCanvas(this);
		gameMap.drawMap();
		
		// load initial SpritePack and Scenario
		packName = "xml/gamesprites.xml";
		scName = "xml/scenario1.xml";
		sprPack = new SpritePack(packName);
		gameSc = new Scenario(scName);
		
		// pass canvas, gameMap, and SpritePack to Scenario, then initialize Scenario
		gameSc.setCMP(this, gameMap, sprPack);
		gameSc.doDraw();
		
		MainPl = new Sprite();
		
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
		
		// initialize, then hide, movement hex highlights
		while (i < 100)
		{
			gameMoves[i] = new GameSprite(new Bitmap (Assets.getBitmapData ("img/move.png")), "move1", "move", 3, 4, 65, 75);
			gameMoves[i].setCanvas(this);
			gameMoves[i].setMap(gameMap);
			gameMoves[i].drawAt( -150, -150);

			i++;
		}

		i = 0;
		
		// initialize, then hide, attack hex highlights
		while (i < 50)
		{
			gameAttacks[i] = new GameSprite(new Bitmap (Assets.getBitmapData ("img/attack.png")), "attack1", "attack", 3, 4, 65, 75);
			gameAttacks[i].setCanvas(this);
			gameAttacks[i].setMap(gameMap);
			gameAttacks[i].drawAt( -150, -150);

			i++;
		}
		
		gameEgoStrike = new GameSprite(new Bitmap (Assets.getBitmapData ("img/select.png")), "estrike1", "estrike", 3, 4, 65, 75);
		gameEgoStrike.setCanvas(this);
		gameEgoStrike.setMap(gameMap);
		gameEgoStrike.drawAt(-100, -100);
		
		// initialize, then hide, player hex highlighter
		gameEgo = new GameEgo(new Bitmap (Assets.getBitmapData ("img/highlight.png")), "ego1", "ego", 3, 4, 65, 75);
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
		
		// add alert box image, hide
		alertbox = new Bitmap (Assets.getBitmapData ("img/alertbox.png"));
		this.addChild(alertbox);
		alertbox.x = -1000;
		alertbox.y = boxy;
		//alertbox.z = 10000;
		
		lastX = -1;
		lastY = -1;
		
		// set mouse and keyboard events
		stage.addEventListener (KeyboardEvent.KEY_DOWN, onKeyDown);
		stage.addEventListener(MouseEvent.MOUSE_MOVE, onMouseMove);
		stage.addEventListener(MouseEvent.MOUSE_DOWN, onMouseDown);
		stage.addEventListener (MouseEvent.MOUSE_UP, onMouseUp);
			
		// initialize TextField, with TextFormat format
		ts = new flash.text.TextFormat();
        ts.font = "Courier";
        ts.size = 16;
        ts.color=0xFFFFFF;
        p = new flash.text.TextField();
        p.text = "";
        p.setTextFormat(ts);
		p.x = 0;
		p.y = 0;
		p.width = 800;
		p.height = 200;
		p.mouseEnabled = false;

		ts1 = new TextFormat();
        ts1.font = "Courier";
        ts1.size = 16;
        ts1.color = 0xEEEEEE;

		console = new TextField();
		console.x = 0;
		console.y = 628;
		console.width = 1200;
		console.height = 50;
		console.background = true;
		console.backgroundColor = 0x01399f;
		console.mouseEnabled = true;
		console.type = TextFieldType.INPUT;
		console.defaultTextFormat = ts1;
		
		this.addChild(console);
		console.text = "> ";
		console.setTextFormat(ts1);
		
		cout = new TextField();
		cout.x = 0;
		cout.y = 650;
		cout.width = 1200;
		cout.height = 50;
		cout.mouseEnabled = false;
		cout.defaultTextFormat = ts1;
		
		this.addChild(cout);
		cout.text = "Welcome to Instant War. Click beside prompt above to enter command. Type 'help' for list of commands.";
		
        this.addChild(p);
		gameSc.setText(p, ts);
		
		gameTurn = 1;
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
	
	private function parseInput()
	{
		var ctext:String;
		
		ctext = console.text;
		
		if (ctext.charAt(0) == ">") ctext = ctext.substr(1, ctext.length - 1);
		if (ctext.charAt(0) == " ") ctext = ctext.substr(1, ctext.length - 1);
		
		if (gameSide == 1)
		{
			if (ctext == "next" || ctext == "nextturn")
			{
				doNextPhase();
				cout.text = "Turn #" + gameTurn + " ended.  Turn #" + (gameTurn + 1) + " begins.";
				gameTurn++;
			}
			else if (ctext == "new" || ctext == "newgame")
			{
				cout.text = "Start a new game (y/n)?";
				gameSide = 3;
			}
			else
			{
				cout.text = "Command not recognized.";
			}
		}
		else if (gameSide == 3)
		{
			if (ctext == "y")
			{
				reset();
				cout.text = "New game started.";
				gameSide = 1;
			}
		}
		
		console.text = "> ";
	}

	function doNextPhase()
	{
		var j:Int;
		
		// clear the TextField
		p.text = "";
					
		// revive all dispersed enemy units
		j = 0;
					
		while (j < moveFlag.length)
		{
			if (gameSc.getSides(j) == "a" && gameSc.getDisperse(j) == 1)
				gameSc.doRevive(j);
					
			j++;
		}					
					
		// flip gameSide to enemy
		gameSide = 2;
					
		// run AI for enemy units
		gameSc.runAI();
				
		// revive all dispersed player units
		j = 0;
					
		while (j < moveFlag.length)
		{
			moveFlag[j] = 1;
			attackFlag[j] = 1;
						
			if (gameSc.getSides(j) == "e" && gameSc.getDisperse(j) == 1)
				gameSc.doRevive(j);
						
			j++;
		}
					
		// flip gameSide to player
		gameSide = 1;
	}
	
	// handles directional keys and scrolls map
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
		
		if (e.keyCode == 8)
		{
			if (console.text.substr(0, 2) != "> ") 
			{
				console.text = "> ";
			}
		}
		
		if (e.keyCode == 13)
		{
			parseInput();
		}
		
		if (e.keyCode >= 37 && e.keyCode <= 40)
		{
			// right arrow, moves map to the left
			if (e.keyCode == 39)
			{
				xs = -cmult;
				ys = 0;
				
				// stops moving if map is scrolled all the way to the left
				if (1275 - this.x > (gameEgo.getMap().getWidth() + 1) * gameEgo.getMap().getTileWidth())
					xs = 0;
			}
			// down arrow, moves map up
			else if (e.keyCode == 40)
			{
				xs = 0;
				ys = -cmult;
				
				// stops moving if map is scrolled all the way to the top
				if (673 - this.y > gameEgo.getMap().getHeight() * gameEgo.getMap().getTileWidth() * 0.86)
					ys = 0;
			}
			// left arrow, moves map to the right
			else if (e.keyCode == 37)
			{
				xs = cmult;
				ys = 0;
				
				if (this.x == 0) xs = 0;
			}
			// up arrow, moves map down
			else if (e.keyCode == 38)
			{
				xs = 0;
				ys = cmult;
				
				if (this.y == 0) ys = 0;
			}
			
			// moves the map based on cmult value
			this.x += xs;
			this.y += ys;
			
			// shift console TextFields to compensate for map movement
			console.x = -this.x;
			console.y = -this.y + 628;
			cout.x = -this.x;
			cout.y = -this.y + 650;
			
			// shifts TextField to compensat for map movement
			p.x = -this.x;
			p.y = -this.y;
			
			// shifts toolbar buttons to compensate for map movement
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

	// sets lastX and lastY values to -1 to cancel scrolling via onMouseMove
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
		
		if (lastX >= 0 && gameSide == 1)
		{
			// if mouse is down (i.e. lastX is not -1), calculate amount mouse has moved
			chgX = Std.int((Std.int(e.stageX) - lastX) / 1);
			chgY = Std.int((Std.int(e.stageY) - lastY) / 1);
			
			// cancels out accidental extreme movements
			if (chgX > 50) chgX = 0;
			if (chgY > 50) chgY = 0;
			
			// move map based on how much mouse has moved
			this.x += chgX;
			this.y += chgY;
			
			// reset movement if it goes beyond bounds of map border
			if (this.x > 0) this.x = 0;
			else if (this.x < 1275 - (gameEgo.getMap().getWidth() + 1) * gameEgo.getMap().getTileWidth())
				this.x = 1275 - (gameEgo.getMap().getWidth() + 1) * gameEgo.getMap().getTileWidth();
			
			if (this.y > 0) this.y = 0;
			else if (this.y < 623 - (gameEgo.getMap().getHeight() * gameEgo.getMap().getTileWidth() * 0.86))
				this.y = 623 - (gameEgo.getMap().getHeight() * gameEgo.getMap().getTileWidth() * 0.86);
				
			// shift TextField to compensate for map movement
			p.x = -this.x;
			p.y = -this.y;
			
			// shift console TextFields to compensate for map movement
			console.x = -this.x;
			console.y = -this.y + 628;
			
			cout.x = -this.x;
			cout.y = -this.y + 650;
			
			i = 0;
			
			// assign current mouse position to lastX and lastY
			lastX = Std.int(e.stageX);
			lastY = Std.int(e.stageY);
		}
	
		// if mouse not over console, move hex highlighter to hex that mouse is over
		if (e.stageY < 623)
		{
			cx = gameEgo.getMap().getCoord("x", Std.int(e.stageX) - Std.int(this.x), Std.int(e.stageY) - Std.int(this.y));
			cy = gameEgo.getMap().getCoord("y", Std.int(e.stageX) - Std.int(this.x), Std.int(e.stageY) - Std.int(this.y));
			
			// positions are different for odd and even rows
			if (cy % 2 == 0)
				gameEgo.moveTo(cx * 64 + 10, Std.int(cy * 54.5) - 0);
			else
				gameEgo.moveTo(cx * 64 + 10 - 32, Std.int(cy * 54.5) - 0);
		}
	}
	
	private function onMouseDown(e:MouseEvent)
	{
		var cresults:Array<Int>;
		var crange:Int;
		var crange2:Int;
		var arange:Int;
		var i:Int;
		var j:Int;
		var k:Int;
		
		var cx:Int;
		var cy:Int;
		var mPoint:Int;
		
		// set lastX and lastY for purposes of onMouseMove
		lastX = Std.int(e.stageX);
		lastY = Std.int(e.stageY);
		
		// get position of mouse relative to window, not map
		cx = Std.int(e.stageX) - Std.int(this.x);
		cy = Std.int(e.stageY) - Std.int(this.y);
		
		i = 0;
		j = 0;
		
		if (gameSide == 1)
		{
			// get hex coordinates from mouse location
			cx = gameEgo.getMap().getCoord("x", Std.int(e.stageX) - Std.int(this.x), Std.int(e.stageY) - Std.int(this.y));
			cy = gameEgo.getMap().getCoord("y", Std.int(e.stageX) - Std.int(this.x), Std.int(e.stageY) - Std.int(this.y));
			
			// initialize cresults for possible use
			cresults = new Array();
			cresults[0] = -1;
			cresults[1] = -1;
			cresults[2] = 9999;
			
			i = 0;
			
			// clear all move and attack hex highlights
			while (i < 100)
			{
				gameMoves[i].dropOnSq( -5, -5);
				if (i < 50) gameAttacks[i].dropOnSq( -5, -5);  
				i++;
			}
			
			// if previously selected player counter is clicked, clear highlights
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
				
				// if a player counter was clicked, begin process to show move and attack highlights
				if (gameSc.getCount(cx, cy, "a") > 0)
				{
					// get movement range for counter (crange2), then convert range to hexes (crange)
					crange2 = gameSc.getMovement(gameSc.getCounter(cx, cy, 1));	
					crange = Std.int(crange2 / 10) + 1;	
					
					// set selectX and selectY to current hex, and selectNum to counter on hex
					selectX = cx;
					selectY = cy;
					selectNum = gameSc.getCounter(cx, cy, 1);
					
					// initialize movesX array
					movesX[0] = -1;
					
					// if counter has not moved or attacked, and is not dispersed, determine movement hexes
					if (moveFlag[selectNum] == 1 && gameSc.getDisperse(selectNum) == 0)
					{
						// check double of movement range along both axes
						i = cy - (crange * 2 + 1);
						
						while (i < cy + (crange * 2 + 1)) 
						{
							j = cx - (crange * 2 + 1);
							while (j < cx + (crange * 2 + 1))
							{
								// set green hex highlight on counter hex
								if (i == cy && j == cx)
								{
									gameEgoStrike.dropOnSq(j, i);
								}
								else
								{
									// reset cresults array
									cresults[0] = -1;
									cresults[1] = -1;
									cresults[2] = 9999;
									cresults[3] = 9999;
									
									// call pathfinding algorithm to check from counter position to current (j. i) coordinate;
									// passes name of counter for weight calculations, cresults to collect results
									gameSc.findPath(cx, cy, j, i, gameSc.getName(selectNum), 0, 50, cresults);
									
									// if weight within range or square is adjacent to counter, highlight hex
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
					
					// initialize attacksX array
					attacksX[0] = -1;
					
					// if counter has not attacked, and is not dispersed, determine movement hexes
					if (attackFlag[selectNum] == 1 && gameSc.getDisperse(selectNum) == 0)
					{
						i = 0;
						k = 0;
						
						// retrieve attacking range of counter
						arange = gameSc.getRange(gameSc.getCounter(cx, cy, 1));
						
						// cycle through counters to determine potential targets
						while (i < gameSc.counterCount())
						{
							// reset cresults array
							cresults[0] = -1;
							cresults[1] = -1;
							cresults[2] = 9999;
							cresults[3] = 9999;
							
							// call pathfinding function for attack squares; looking for counter #i, within attack range arange;
							// store results in cresults
							gameSc.findAttack("e", i, cx, cy, arange, cresults);
							
							// if path found, highlight hex with attack highlight
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
				// if empty hex was selected after a counter was selected, check if hightlighted; move or attack if needed
				else if (selectNum != -1)
				{
					j = 0;
					k = 0;
					
					// check array of potential moves to see if selected hex matches
					while (movesX[k] != -1)
					{
						if (movesX[k] == cx && movesY[k] == cy)
							j = 1;
						
						k++;
					}
					
					// if there is a match, move counter to that hex
					if (j == 1)
					{
						gameSc.dropCounter(selectNum, cx, cy);
						moveFlag[selectNum] = -1;
					}
					
					j = -1;
					k = 0;

					// check array of potential attacks to see if selected hex matches
					while (attacksX[k] != -1)
					{
						if (attacksX[k] == cx && attacksY[k] == cy)
							j = k;
						
						k++;
					}
					
					// if there is a match, call the attack function against counter on hex
					if (j != -1)
					{
						p.text = "";
						gameSc.doAttack(selectNum, attacksNum[j]);
						attackFlag[selectNum] = -1;
						moveFlag[selectNum] = -1;
					}
					
					// clear counter hex highlight
					gameEgoStrike.dropOnSq( -5, -5);
					selectX = -1;
					selectY = -1;
					selectNum = -1;
				}
				else
				{
					// clear counter hex highlight
					gameEgoStrike.dropOnSq( -5, -5);
					selectX = -1;
					selectY = -1;
					selectNum = -1;
				}
			}
		}
	}
	
	function reset()
	{
		var i:Int;
		
		this.x = 0;
		this.y = 0;
		
		alertbox.x = -1000;
		gameSide = 1;
		
		gameMap.drawMap();
		gameSc.doDraw();
		
		gameEgo.redrawSprite();
		gameEgoStrike.redrawSprite();
		
		i = 0;
		
		while (i < 100)
		{
			gameMoves[i].redrawSprite();
			if (i < 50) gameAttacks[i].redrawSprite();
			
			i++;
		}

		i = 0;
		
		while (i < moveFlag.length)
		{
			moveFlag[i] = 1;
			attackFlag[i] = 1;
						
			if (gameSc.getDisperse(i) == 1 || gameSc.getDisperse(i) == -1)
				gameSc.doRevive(i);
				
			i++;
		}
		
		p.x = 0;
		p.y = 0;
		p.text = "";
		this.removeChild(p);
		this.addChild(p);
		
		console.x = 0;
		console.y = 628;
		this.removeChild(console);
		this.addChild(console);
		
		cout.x = 0;
		cout.y = 650;
		this.removeChild(cout);
		this.addChild(cout);
	}
}
