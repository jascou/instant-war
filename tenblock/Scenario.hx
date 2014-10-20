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
	
	private var scAI:Array<String>;
	private var scAIp1:Array<Int>;
	private var scAIp2:Array<Int>;
	
	private var csrX:Array<Int>;
	private var csrY:Array<Int>;
	private var csrFlag:Array<Int>;
	private var csrWeight:Array<Int>;
	private var csrDepth:Array<Int>;
	private var csrAnc:Array<Int>;	
	
	private var scX:Array<Int>;
	private var scY:Array<Int>;
	
	private var scPack:SpritePack;
	private var scMap:GameMap;
	private var scCanvas:Sprite;
	private var scCount:Int;
	
	private var movesX:Array<Int>;
	private var movesY:Array<Int>;
	private var movesDp:Array<Int>;
	private var movesWt:Array<Int>;
	
	public function new(cfile:String) 
	{
		scNames = new Array();
		scSides = new Array();
		scStartX = new Array();
		scStartY = new Array();
		scX = new Array();
		scY = new Array();
		scCounters = new Array();
		
		scAI = new Array();
		scAIp1 = new Array();
		scAIp2 = new Array();
		
		movesX = new Array();
		movesY = new Array();
		movesDp = new Array();
		movesWt = new Array();
		movesX[0] = -1;
		
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
		
			if (scSides[i] == "e")
			{
				scAI[i] = q.node.ai.innerData;
				
				if (scAI[i] == "patrol")
				{
					scAIp1[i] = Std.parseInt(q.node.range.innerData);
				}
				else if (scAI[i] == "chase")
				{
					scAIp1[i] = Std.parseInt(q.node.range.innerData);
					scAIp2[i] = Std.parseInt(q.node.maxattack.innerData);
				}
				else if (scAI[i] == "march")
				{
					scAIp1[i] = Std.parseInt(q.node.speed.innerData);
					scAIp2[i] = Std.parseInt(q.node.maxattack.innerData);
				}
			}
			else
			{
				scAI[i] = "na";
			}

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

	public function dropCounter(cnum:Int, cx:Int, cy:Int)
	{
		scCounters[cnum].dropOnSq(cx, cy);
		scX[cnum] = cx;
		scY[cnum] = cy;
	}
	
	public function setCMP(ccanvas: Sprite, cmap: GameMap, cpack:SpritePack)
	{
		scCanvas = ccanvas;
		scMap = cmap;
		scPack = cpack;
	}
	
	public function counterCount()
	{
		return scX.length;
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

	public function getName(cnum:Int):String
	{
		return scNames[cnum];
	}
	
	public function getCounter(cx: Int, cy: Int, cnum: Int):Int
	{
		var i:Int;
		var ccount:Int;
		
		i = 0;
		ccount = 0;
		
		while (i < scCount)
		{
			if (scX[i] == cx && scY[i] == cy)
				ccount++;
			
			if (ccount == cnum) return i;
				
			i++;
		}
		
		return -1;
	}
	
	public function getMovement(ccounter:Int):Int
	{
		return(scPack.getMovement(scNames[ccounter]));
	}
	
	public function findPath(cfromx: Int, cfromy: Int, ctox: Int, ctoy: Int, ctype:String, cflag: Int, cresults:Array<Int>)
	{
		var i:Int;
		var j:Int;
		var k:Int;
		var l:Int;
		var m:Int;
		var cweight: Int;
		
		var x1:Int;
		var y1:Int;
		var depth:Int;
		var zeroflag:Int;
		
		var ccount:Int;
		var cmax:Int;
		
		csrX = new Array();
		csrY = new Array();
		csrFlag = new Array();
		csrWeight = new Array();
		csrDepth = new Array();
		csrAnc = new Array();
		
		csrX[0] = cfromx;
		csrY[0] = cfromy;
		csrFlag[0] = 1;
		csrWeight[0] = 0;
		csrDepth[0] = 0;
		csrAnc[0] = -1;
	
		cresults[0] = -1;
		cresults[1] = -1;
		cresults[2] = 9999;
		cresults[3] = 0;
		
		x1 = 0;
		y1 = 0;
		l = 0;
		m = 0;
		depth = 0;
		zeroflag = 0;
		
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
			depth++;
			
			while (k < cmax)
			{
				cweight = 9999;
				j = 0;
				i = k;
				k++;
				
				if (csrX[i] == ctox && csrY[i] == ctoy && csrWeight[i] <= cresults[2])
				{
					l = i;

					while (csrAnc[l] != 0)
					{
						l = csrAnc[l];
					}

					cresults[0] = csrX[l];
					cresults[1] = csrY[l];
					cresults[2] = csrWeight[i];
					cresults[3] = csrDepth[i];
				}
				else if (csrFlag[i] == 1)
				{
					csrFlag[i] = -1;
					j = 0;
				
					for(j in 0...6)
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
							
						if ((scMap.isValid(x1, y1, ctype) || cflag == 1) && csrWeight[i] < 50)
						{
							l = this.getNode(x1, y1, csrWeight[i] + scMap.getWeightXY(x1, y1));

							if (l != -1)
							{	
								csrX[l] = x1;
								csrY[l] = y1;
								csrFlag[l] = 1;
								csrWeight[l] = csrWeight[i] + scMap.getWeightXY(x1, y1);
								csrDepth[l] = depth;
								csrAnc[l] = i;
								ccount = 1;
							}
						}
							
						//j++;
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
			if (csrX[i] == cx && csrY[i] == cy && csrWeight[i] <= cweight)
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
	
	public function findAttack(cnum:Int, cx:Int, cy:Int, cmax:Int, cresults:Array<Int>)
	{
		var cresults2:Array<Int>;	
		
		cresults2 = new Array();
		
		cresults2[0] = -1;
		cresults2[1] = -1;
		cresults2[2] = 9999;
		cresults2[3] = 9999;
		
		if (scSides[cnum] == "e")
		{
			if (doDistance(cx, cy, scX[cnum], scY[cnum]) <= cmax + 4)
			{
				findPath(cx, cy, scX[cnum], scY[cnum], scNames[cnum], 0, cresults2);
				
				if (cresults2[3] <= cmax)
				{
					cresults[0] = scX[cnum];
					cresults[1] = scY[cnum];
				}
			}
		}
	}
	
	public function runAI():Void
	{
		var cresults:Array<Int>;
		var i:Int;
		var j:Int;
		var k:Int;
		var l:Int;
		
		var cx:Int;
		var cy:Int;
		var crange:Int;
		
		var selectX:Int;
		var selectY:Int;
		var selectNum:Int;
		
		i = 0;
		j = 0;
		k = 0;
		l = 0;
		
		cresults = new Array();
		cresults[0] = -1;
		cresults[1] = -1;
		cresults[2] = 9999;
		
		while (l < scX.length)
		{
			if (scSides[l] == "e")
			{
				cx = scX[l];
				cy = scY[l];
				k = 0;
				movesX[k] = -1;
				
				crange = this.getMovement(this.getCounter(cx, cy, 1));	
				i = cy - (crange * 2 + 1);
					
				selectX = cx;
				selectY = cy;
				selectNum = i;
										
				while (i < cy + (crange * 2 + 1)) 
				{
					j = cx - (crange * 2 + 1);
					
					while (j < cx + (crange * 2 + 1))
					{
						if (i == cy && j == cx)
						{
							// do nothing
						}
						else
						{
							cresults[0] = -1;
							cresults[1] = -1;
							cresults[2] = 9999;
							cresults[3] = 9999;
								
							this.findPath(cx, cy, j, i, scPack.getType(scNames[l]), 0, cresults);
								
							if (cresults[2] <= crange * 10 || cresults[3] == 1)
							{
								movesX[k] = j;
								movesY[k] = i;
								movesDp[k] = cresults[3];
								movesWt[k] = cresults[2];
								
								movesX[k + 1] = -1;
								k++;
							}
						}
						
						j++;
					}
					
					i++;
				}
				
				if (scAI[l] == "patrol")
				{
					this.doPatrol(l);
				}
				else if (scAI[l] == "chase")
				{
					this.doChase(l);
				}
				else if (scAI[l] == "march")
				{
					this.doMarch(l);
				}
			}
			
			l++;
		}
	}
	
	private function doPatrol(cnum:Int)
	{
		var cresults:Array<Int>;
		var i:Int;
		
		var goX:Array<Int>;
		var goY:Array<Int>;
		
		goX = new Array();
		goY = new Array();
		
		cresults = new Array();
		cresults[0] = -1;
		cresults[1] = -1;
		cresults[2] = 9999;
		
		i = 0;
		
		while (i < movesX.length)
		{
			if (doDistance(scStartX[cnum], scStartY[cnum], movesX[i], movesY[i]) <= scAIp1[cnum])
			{
				this.findPath(scStartX[cnum], scStartY[cnum], movesX[i], movesY[i], scPack.getType(scNames[cnum]), 0, cresults);
				
				if (cresults[3] <= scAIp1[cnum])
				{
					goX[goX.length] = movesX[i];
					goY[goY.length] = movesY[i];
				}
			}
			
			i++;
		}
		
		i = Std.int(Math.random() * goX.length);
		this.dropCounter(cnum, goX[i], goY[i]);
	}
	
	private function doChase(cnum:Int)
	{
		var chaseX:Int;
		var chaseY:Int;
		var chaseDist:Int;
		var goX:Int;
		var goY:Int;
		var goDist:Int;
		
		var i:Int;
		
		chaseX = -1;
		chaseY = -1;
		chaseDist = 9999;
		
		i = 0;
		
		while (i < scX.length)
		{
			if (scSides[i] == "a")
			{
				if (doDistance(scX[cnum], scY[cnum], scX[i], scY[i]) < chaseDist && doDistance(scStartX[cnum], scStartY[cnum], scX[i], scY[i]) < scAIp1[cnum])
				{
					chaseX = scX[i];
					chaseY = scY[i];
					chaseDist = doDistance(scX[cnum], scY[cnum], scX[i], scY[i]);
				}
			}
			
			i++;
		}
		
		goX = -1;
		goY = -1;
		goDist = 9999;
		
		i = 0;
		
		while (movesX[i] != -1)
		{
			if (doDistance(movesX[i], movesY[i], chaseX, chaseY) < goDist)
			{
				goX = movesX[i];
				goY = movesY[i];
				goDist = doDistance(movesX[i], movesY[i], chaseX, chaseY);
			}
					
			i++;
		}
		
		this.dropCounter(cnum, goX, goY);
	}
	
	private function doMarch(cnum:Int)
	{
		var chaseX:Int;
		var chaseY:Int;
		var chaseDist:Int;
		var goX:Int;
		var goY:Int;
		var goDist:Int;
		
		var i:Int;
		
		chaseX = -1;
		chaseY = -1;
		chaseDist = 9999;
		
		i = 0;
		
		while (i < scX.length)
		{
			if (scSides[i] == "a")
			{
				if (doDistance(scX[cnum], scY[cnum], scX[i], scY[i]) < chaseDist)
				{
					chaseX = scX[i];
					chaseY = scY[i];
					chaseDist = doDistance(scX[cnum], scY[cnum], scX[i], scY[i]);
				}
			}
			
			i++;
		}
		
		goX = -1;
		goY = -1;
		goDist = 9999;
		
		i = 0;
		
		while (movesX[i] != -1)
		{
			if (doDistance(movesX[i], movesY[i], chaseX, chaseY) < goDist && doDistance(movesX[i], movesY[i], scX[cnum], scY[cnum]) <= scAIp1[cnum])
			{
				goX = movesX[i];
				goY = movesY[i];
				goDist = doDistance(movesX[i], movesY[i], chaseX, chaseY);
			}
					
			i++;
		}
		
		this.dropCounter(cnum, goX, goY);
	}
	
	private function doDistance(startx:Int, starty:Int, destx:Int, desty: Int):Int
	{
		var dx:Float;
		var dy:Float;
		
		if (startx == destx)
			return Std.int(Math.abs(desty - starty));
		else if (starty == desty)
			return Std.int(Math.abs(destx - startx));
		else
		{
			dx = Math.abs(destx - startx);
			dy = Math.abs(desty - starty);
			
			if (starty < desty)
				return Std.int(dx + dy - Std.int(Math.ceil(dx / 2.0)));
			else
				return Std.int(dx + dy - Std.int(Math.floor(dx / 2.0)));
		}
	}
}