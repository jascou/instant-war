package tenblock;

import flash.display.Bitmap;
import flash.display.Sprite;
import flash.events.Event;
import flash.events.KeyboardEvent;
import flash.geom.Rectangle;
import flash.Lib;
import flash.text.TextField;
import flash.text.TextFormat;
import haxe.macro.Expr.Constant;
import haxe.Timer;
import openfl.Assets;
import haxe.io.Eof;
import sys.io.File;
import sys.io.FileInput;
import sys.io.FileOutput;

class Scenario 
{
	private var scName:String;
	private var scNames:Array<String>;
	private var scSides:Array<String>;
	private var scStartX:Array<Int>;
	private var scStartY:Array<Int>;
	private var scDisperse:Array<Int>;
	private var scCounters:Array<GameSprite>;
	private var scAtFlags:Array<Int>;
	
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
	
	private var scOdds:Array<Float>;
	private var scStartDie:Int;
	private var scRows:Array<String>;
	
	private var scText:TextField;
	private var scFormat:TextFormat;
	
	public function new(cfile:String) 
	{
		scNames = new Array();
		scSides = new Array();
		scStartX = new Array();
		scStartY = new Array();
		scX = new Array();
		scY = new Array();
		scDisperse = new Array();
		scCounters = new Array();
		scAtFlags = new Array();
		
		scAI = new Array();
		scAIp1 = new Array();
		scAIp2 = new Array();
		
		movesX = new Array();
		movesY = new Array();
		movesDp = new Array();
		movesWt = new Array();
		movesX[0] = -1;
		
		scOdds = new Array();
		scRows = new Array();
		
		var i:Int;
		var cxml = Assets.getText(cfile);
		var xml = Xml.parse(cxml);
		var fast = new haxe.xml.Fast(xml.firstElement());
		
		i = 0;
		
		scName = fast.node.name.innerData;
		var counters = fast.node.counters;
		var crt = fast.node.crt;
		
		for (q in crt.nodes.odds)
		{
			scOdds[i] = Std.parseFloat(q.innerData);
			i++;
		}
		
		scStartDie = Std.parseInt(fast.node.crt.node.startdie.innerData);
		
		i = 0;

		for (q in crt.nodes.row)
		{
			scRows[i] = q.innerData;
			i++;
		}
		
		i = 0;
		
		for (q in counters.nodes.counter) 
		{
			scNames[i] = q.node.name.innerData;
			scSides[i] = q.node.side.innerData;
			scStartX[i] = Std.parseInt(q.node.startx.innerData);
			scStartY[i] = Std.parseInt(q.node.starty.innerData);
			scDisperse[i] = 0;
			
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
	
	public function setText(ctextfield: TextField, cformat: TextFormat)
	{
		scText = ctextfield;
		scFormat = cformat;
	}
	
	public function counterCount()
	{
		return scX.length;
	}
	
	public function getDisperse(cnum:Int):Int
	{
		return scDisperse[cnum];
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
	
	public function doAttack(cattack:Int, cdefend:Int)
	{
		var i: Int;
		var j: Int;
		var k: Int;
		var crto: Float;
		
		var ratio:Float;
		var cratio: Float;
		var croll:Int;
		var coutcome:String;
		
		//trace(scPack.getAttack(scNames[cattack]) + " " + scPack.getDefend(scNames[cdefend]));
		ratio = scPack.getAttack(scNames[cattack]) / scPack.getDefend(scNames[cdefend]);
		
		i = 0;
		j = -1;
		crto = 9999;
		
		while (i < scOdds.length)
		{
			if (Math.abs(ratio - scOdds[i]) < crto && ratio - scOdds[i] >= 0)
			{
				j = i;
				crto = Math.abs(ratio - scOdds[j]);
			}
			
			i++;
		}
		
		cratio = scOdds[j];		
		croll = Std.int(Math.random() * 6) + 1;
		
		if (scDisperse[cdefend] == 1)
			croll = croll - 2;
	
		if (scMap.getTypeXY(scX[cdefend], scY[cdefend]) == "town")
			croll = croll + 1;
			
		k = leveldif(scMap.getLevel(scX[cattack], scY[cattack]), scMap.getLevel(scX[cdefend], scY[cdefend]));
		
		if (k > 0)
			croll = Std.int(croll / 2);
		else if (k < 0)
			croll = croll + 2;
			
		if (croll < scStartDie) croll = scStartDie;
		
		coutcome = scRows[croll - scStartDie].substr(j, 1);
		
		scText.text = scText.text + "Counter #" + cattack + " attacks counter #" + cdefend + ". Roll: " + croll + ". ";
		
		if (coutcome == "d") 
		{
			scText.text = scText.text + "Result: Dispersal.\n";
			doDisperse(cdefend);
		}
		else if (coutcome == "D")
		{
			doSpecial(cdefend);
		}
		else if (coutcome == "x")
		{
			scText.text = scText.text + "Result: Kill.\n";
			doKill(cdefend);
		}
		else 
		{
			scText.text = scText.text + "Result: No effect.\n";
		}
		
		scText.setTextFormat(scFormat);
	}
	
	public function getMovement(ccounter:Int):Int
	{
		return(scPack.getMovement(scNames[ccounter]));
	}
	
	public function getRange(ccounter:Int):Int
	{
		return(scPack.getRange(scNames[ccounter]));
	}
	
	public function getSides(cnum:Int):String
	{
		return scSides[cnum];
	}
	
	public function doDisperse(cnum:Int)
	{
		scDisperse[cnum] = 1;
		scCounters[cnum].alpha = 0.5;
	}
	
	public function doRevive(cnum:Int)
	{
		scDisperse[cnum] = 0;
		scCounters[cnum].alpha = 1;
	}
	
	public function doKill(cnum:Int)
	{
		scDisperse[cnum] = -1;
		scX[cnum] = -5;
		scY[cnum] = -5;
		scCounters[cnum].dropOnSq(scX[cnum], scY[cnum]);
	}
	
	public function doSpecial(cnum:Int)
	{
		if (scDisperse[cnum] == 0)
		{
			scText.text = scText.text + "Result: DD (Dispersal).\n";
			this.doDisperse(cnum);
		}
		else if (scDisperse[cnum] == 1)
		{
			scText.text = scText.text + "Result: DD (Kill).\n";
			this.doKill(cnum);
		}
	}
	
	public function doUndisperse(cnum:Int)
	{
		scDisperse[cnum] = 0;
		scCounters[cnum].alpha = 1;
	}
	
	public function findPath(cfromx: Int, cfromy: Int, ctox: Int, ctoy: Int, cname:String, cflag: Int, cmaxdist: Int, cresults:Array<Int>)
	{
		var i:Int;
		var j:Int;
		var k:Int;
		var l:Int;
		var m:Int;
		var n:Int;
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
	
						n = scMap.getLevel(csrX[i], csrY[i]);
							
						if (scMap.isValid(x1, y1, cflag) && this.getWeightXY(cname, x1, y1, n) > -1 && csrWeight[i] < cmaxdist)
						{
							l = this.getNode(x1, y1, csrWeight[i] + this.getWeightXY(cname, x1, y1, n), cflag);

							if (l != -1)
							{	
								csrX[l] = x1;
								csrY[l] = y1;
								csrFlag[l] = 1;
								csrWeight[l] = csrWeight[i] + this.greater(this.getWeightXY(cname, csrX[i], csrY[i], n), this.getWeightXY(cname, x1, y1, n));
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

	function levelmult(cnum1:Int, cnum2:Int):Float
	{
		if (cnum1 == cnum2)
			return 1;
		else if (cnum1 < cnum2)
			return 2 * (cnum2 - cnum1);
		else if (cnum2 < cnum1)
			return 0.5;
			
		return 1;
	}
	
	function leveldif(cnum1:Int, cnum2:Int):Int
	{
		return cnum1 - cnum2;
	}
	
	function greater(cnum1:Int, cnum2:Int): Int
	{
		if (cnum1 >= cnum2)
			return cnum1;
		else
			return cnum2;
	}
	
	function getWeightXY(cname:String, cx:Int, cy:Int, clevel:Int):Int
	{
		var cweight:Int;
		
		cweight = Std.int(scPack.getWeight(cname, scMap.getTypeXY(cx, cy)) * levelmult(clevel, scMap.getLevel(cx, cy)));
		return cweight;
	}
	
	function getNode(cx:Int, cy:Int, cweight: Int, cflag:Int):Int
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
		
		if (cflag == 1) return csrX.length;
		
		i = 0;
		
		while (i < scCounters.length)
		{
			if (scX[i] == cx && scY[i] == cy)
				return -1;
			
			i++;
		}
		
		return csrX.length;
	}

	public function loadGame(cname:String, cmove:Array<Int>, cattack:Array<Int>)
	{
		var i:Int;
		var ccounters:Int;
		var fin = File.read(cname, false);
    
        ccounters = Std.parseInt(fin.readLine());
		
		i = 0;
		while (i < ccounters)
		{
			scX[i] = Std.parseInt(fin.readLine());
			scY[i] = Std.parseInt(fin.readLine());
			scDisperse[i] = Std.parseInt(fin.readLine());
			scCounters[i].dropOnSq(scX[i], scY[i]);
			cmove[i] = Std.parseInt(fin.readLine());
			cattack[i] = Std.parseInt(fin.readLine());
			
			if (scDisperse[i] == 1) this.doDisperse(i);
			
			i++;
		}
		
		fin.close();
	}
	
	public function saveGame(cname:String, cmove:Array<Int>, cattack:Array<Int>)
	{
		var i:Int;
		var fout = File.write(cname, false);

		fout.writeString(scX.length + "\n");
		
		i = 0;
		
		while (i < scX.length)
		{
			fout.writeString(scX[i] + "\n");
			fout.writeString(scY[i] + "\n");
			fout.writeString(scDisperse[i] + "\n"); 
			fout.writeString(cmove[i] + "\n"); 
			fout.writeString(cattack[i] + "\n");
			
			i++;
		}
		
		fout.close();
	}
	
	public function findAttack(cside:String, cnum:Int, cx:Int, cy:Int, cmax:Int, cresults:Array<Int>)
	{
		var cresults2:Array<Int>;
		var side:String;
		
		cresults2 = new Array();
		
		cresults2[0] = -1;
		cresults2[1] = -1;
		cresults2[2] = 9999;
		cresults2[3] = 9999;
		
		if (scSides[cnum] == cside)
		{
			if (doDistance(cx, cy, scX[cnum], scY[cnum]) <= cmax + 1)
			{
				findPath(cx, cy, scX[cnum], scY[cnum], scNames[cnum], 1, 50, cresults2);

				if (cresults2[3] <= cmax && cresults2[3] > 0)
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
		var crange2:Int;
		
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
			if (scSides[l] == "e" && scDisperse[l] == 0)
			{
				cx = scX[l];
				cy = scY[l];
				k = 0;
				movesX[k] = -1;
				
				crange2 = this.getMovement(this.getCounter(cx, cy, 1));	
				crange = Std.int(crange2 / 10) + 1;
				
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
								
							this.findPath(cx, cy, j, i, scNames[l], 0, 50, cresults);
								
							if (cresults[2] <= crange2 || cresults[3] == 1)
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
				
				scAtFlags[l] = 0;
				this.doFire(l);
				
				if (scAtFlags[l] == 0)
				{
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
					
					this.doFire(l);
				}
			}
			
			l++;
		}
	}
	
	private function doFire(cnum)
	{
		var i:Int;
		var j:Int;
		var k:Int;
		var l:Int;
		
		var cx:Int;
		var cy:Int;
		var crange:Int;
		
		var cresults:Array<Int>;
		var attackNum:Array<Int>;
		
		i = 0;
		k = 0;
		
		cx = scX[cnum];
		cy = scY[cnum];

		cresults = new Array();
		attackNum = new Array();
		attackNum[0] = -1;
		
		crange = this.getRange(this.getCounter(cx, cy, 1));
		
		while (i < this.counterCount())
		{
			cresults[0] = -1;
			cresults[1] = -1;
			cresults[2] = 9999;
			cresults[3] = 9999;
							
			this.findAttack("a", i, cx, cy, crange, cresults);
			
			if (cresults[0] != -1)
			{
				attackNum[k] = i;
				attackNum[k + 1] = -1;
				k++;
			}
							
			i++;
		}
		
		i = 0;
		j = -1;
		k = 0;
		
		while (attackNum[i] != -1)
		{
			//trace(i);
			k = attackNum[i];

			if (scDisperse[k] == 1)
				j = i;
			
			i++;
		}
		
		if (j != -1)
		{
			scAtFlags[cnum] = 1;
			this.doAttack(cnum, attackNum[j]);
		}
		else
		{
			i = 0;
			j = 9999;
			l = -1;
			
			while (attackNum[i] != -1)
			{
				if (attackNum[i] != -1)
				{
					k = attackNum[i];
					
					if (scPack.getAttack(scNames[k]) < j)
					{
						l = i;
						j = scPack.getAttack(scNames[k]);
					}
				}
				
				i++;
			}
			
			if (l != -1)
			{
				scAtFlags[cnum] = 1;
				this.doAttack(cnum, attackNum[l]);
			}
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
				this.findPath(scStartX[cnum], scStartY[cnum], movesX[i], movesY[i], scPack.getType(scNames[cnum]), 0, 50, cresults);
				
				if (cresults[3] <= scAIp1[cnum])
				{
					goX[goX.length] = movesX[i];
					goY[goY.length] = movesY[i];
				}
			}
			
			i++;
		}
		
		if (goX.length > 0)
		{
			i = Std.int(Math.random() * goX.length);
			this.dropCounter(cnum, goX[i], goY[i]);
		}
	}
	
	private function doChase(cnum:Int)
	{
		var chaseX:Int;
		var chaseY:Int;
		var chaseDist:Int;
		var goX:Int;
		var goY:Int;
		var goDist:Int;
		var cresults2:Array<Int>;
		
		var i:Int;
		
		chaseX = -1;
		chaseY = -1;
		chaseDist = 9999;
		cresults2 = new Array();
		
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
		
		this.findPath(scX[cnum], scY[cnum], chaseX, chaseY, this.getName(cnum), 0, 1200, cresults2);
		goX = cresults2[0];
		goY = cresults2[1];
		
		if (goX == -1 || (goX == 0 && goY == 0))
		{
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
		var cresults2:Array<Int>;
		
		var i:Int;
		
		chaseX = -1;
		chaseY = -1;
		chaseDist = 9999;
		cresults2 = new Array();
		
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
		
		this.findPath(scX[cnum], scY[cnum], chaseX, chaseY, this.getName(cnum), 0, 1200, cresults2);
		goX = cresults2[0];
		goY = cresults2[1];
		
		if (goX == -1)
		{
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