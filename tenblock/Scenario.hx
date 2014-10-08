package tenblock;

import flash.display.Bitmap;
import flash.display.Sprite;
import flash.events.Event;
import flash.events.KeyboardEvent;
import flash.geom.Rectangle;
import flash.Lib;
import haxe.macro.Expr.Constant;
import haxe.Timer;
import openfl.Assets;

class Scenario 
{
	private var scName:String;
	private var scNames:Array<String>;
	private var scSides:Array<String>;
	private var scStartX:Array<Int>;
	private var scStartY:Array<Int>;
	private var scCounters:Array<GameSprite>;
	
	private var csrX:Array<Int>;
	private var csrY:Array<Int>;
	private var csrFlag:Array<Int>;
	private var csrWeight:Array<Int>;
	private var csrAnc:Array<Int>;	
	
	private var scX:Array<Int>;
	private var scY:Array<Int>;
	
	private var scPack:SpritePack;
	private var scMap:GameMap;
	private var scCanvas:Sprite;
	private var scCount:Int;
	
	public function new(cfile:String) 
	{
		scNames = new Array();
		scSides = new Array();
		scStartX = new Array();
		scStartY = new Array();
		scX = new Array();
		scY = new Array();
		scCounters = new Array();
		
		scX = new Array();
		scY = new Array();
		
		var i:Int;
		var cxml = Assets.getText(cfile);
		var xml = Xml.parse(cxml);
		var fast = new haxe.xml.Fast(xml.firstElement());
		
		i = 0;
		
		scName = fast.node.name.innerData;
		var counters = fast.node.counters;
		
		for (q in counters.nodes.counter) 
		{
			scNames[i] = q.node.name.innerData;
			scSides[i] = q.node.side.innerData;
			scStartX[i] = Std.parseInt(q.node.startx.innerData);
			scStartY[i] = Std.parseInt(q.node.starty.innerData);
			
			scX[i] = scStartX[i];
			scY[i] = scStartY[i];
			
			i++;
		}
		
		scCount = i;
	}
	
	public function doDraw()
	{
		var i:Int;
		
		i = 0;
		
		while (i < scCount)
		{
			scCounters.push(scPack.makeSprite(scPack.getNum(scNames[i])));

			scCounters[i].setMap(scMap);
			scCounters[i].setCanvas(scCanvas);
			scCounters[i].setTileWidth(45);
			
			scCounters[i].drawAt(-150, -150);
			scCounters[i].dropOnSq(scStartX[i], scStartY[i]);
			scX[i] = scStartX[i];
			scY[i] = scStartY[i];
			
			i++;
		}
	}
	
	public function setCMP(ccanvas: Sprite, cmap: GameMap, cpack:SpritePack)
	{
		scCanvas = ccanvas;
		scMap = cmap;
		scPack = cpack;
	}
	
	public function getCount(cx: Int, cy: Int, cside: String):Int
	{
		var i:Int;
		var ccount:Int;
		
		i = 0;
		ccount = 0;
		
		while (i < scCount)
		{
			if (scX[i] == cx && scY[i] == cy && scSides[i] == cside)
				ccount++;
			
			i++;
		}
		
		return ccount;
	}
	
	public function findPath(cfromx: Int, cfromy: Int, ctox: Int, ctoy: Int, cinit: Int, cresults:Array<Int>)
	{
		
		var i:Int;
		var j:Int;
		var k:Int;
		var l:Int;
		var cweight: Int;
		
		var x1:Int;
		var y1:Int;
		
		var ccount:Int;
		var cmax:Int;
		
		csrX = new Array();
		csrY = new Array();
		csrFlag = new Array();
		csrWeight = new Array();
		csrAnc = new Array();
		
		csrX[0] = cfromx;
		csrY[0] = cfromy;
		csrFlag[0] = 1;
		csrWeight[0] = cinit;
		csrAnc[0] = -1;
	
		cresults[0] = -1;
		cresults[1] = -1;
		cresults[2] = 9999;
		
		x1 = 0;
		y1 = 0;
		l = 0;
		
		do
		{
			ccount = 0;
			cmax = csrX.length;
			
			k = 0;
			while (k < cmax)
			{
				if (csrFlag[k] == 0) csrFlag[k] = 1;
				k++;
			}
			
			k = 0;
			
			while (k < cmax)
			{
				cweight = 9999;
				j = 0;
				i = k;
				k++;
				
				if (csrX[i] == ctox && csrY[i] == ctoy && csrWeight[i] <= cresults[2])
				{
					cresults[0] = csrX[csrAnc[i]];
					cresults[1] = csrY[csrAnc[i]];
					cresults[2] = csrWeight[i];
				}
				else if (csrFlag[i] == 1)
				{
					csrFlag[i] = -1;
					j = 0;
				
					while (j < 6)
					{	
						if (j == 0 || j == 4)
						{
							if (csrY[i] % 2 == 0)
								x1 = csrX[i];
							else
								x1 = csrX[i] - 1;
						}
						else if (j == 2)
							x1 = csrX[i] - 1;
						else if (j == 3)
							x1 = csrX[i] + 1;
						else if (j == 1 ||  j == 5)
						{
							if (csrY[i] % 2 == 0)
								x1 = csrX[i] + 1;
							else
								x1 = csrX[i];
						}
						
						if (j == 0 || j == 1)
							y1 = csrY[i] - 1;
						else if (j == 2 || j == 3)
							y1 = csrY[i];
						else
							y1 = csrY[i] + 1;

						if (scMap.isValid(x1, y1, "test") && csrWeight[i] < 4)
						{
							//trace("check " + x1 + " " + y1);
							l = this.getNode(x1, y1, csrWeight[i] + 1);
							if (l != -1)
							{	
								csrX[l] = x1;
								csrY[l] = y1;
								csrFlag[l] = 0;
								csrWeight[l] = csrWeight[i] + 1;
								csrAnc[l] = i;
								ccount = 1;
							}
						}
							
						j++;
					}
				}	
			}
		} 
		while (ccount > 0);
	}
	
	function getNode(cx:Int, cy:Int, cweight: Int):Int
	{
		var i:Int;
		
		i = 0;
	
		while (i < csrX.length)
		{
			if (csrX[i] == cx && csrY[i] == cy && csrWeight[i] > cweight)
				return i;
			if (csrX[i] == cx && csrY[i] == cy && csrWeight[i] < cweight)
				return -1;
				
			i++;
		}
		
		i = 0;
		
		while (i < scCounters.length)
		{
			if (scX[i] == cx && scY[i] == cy)
				return -1;
			
			i++;
		}
		
		return csrX.length;
	}
}