package tenblock;

import flash.display.Bitmap;
import flash.display.Sprite;
import flash.events.Event;
import flash.geom.Rectangle;
import flash.Lib;
import haxe.Timer;
import openfl.Assets;

class GameSprite extends CharSprite
{
	private var gsName:String;
	private var gsType:String;
	
	private var gsCanvas:Sprite;
	private var doAnim:haxe.Timer;
	private var gsFrame:Float;	
	private var runFlag:Int;
	private var gsIncr:Float;
	
	private var gsTargetX:Int;
	private var gsTargetY:Int;
	private var gsMoveSqX:Int;
	private var gsMoveSqY:Int;

	private var gsMap:GameMap;
	private var gsGoodCodes:String;
	
	private var gsSeq:Array<Int>;
	private var gsFlag:Int;
	private var gsTileWidth: Int;
	
	public function new(csheet:Bitmap, cname:String, ctype:String, cx:Int, cy:Int, cwd:Int, cht:Int) 
	{	
		super(csheet, cx, cy, cwd, cht);
		
		gsName = cname;
		gsType = ctype;
		
		gsFrame = 0;
		runFlag = 0;
		gsIncr = 1;
		
		gsMoveSqX = -1;
		gsMoveSqY = -1;
		gsFlag = 0;
		gsSeq = new Array();
	}
	
	public function setCanvas(ccanvas:Sprite)
	{
		gsCanvas = ccanvas;
	}
	
	public function getCanvas():Sprite
	{
		return gsCanvas;
	}
	
	public function setMap(cmap:GameMap)
	{
		gsMap = cmap;
	}
	
	public function getMap():GameMap
	{
		return gsMap;
	}
	
	public function setInterval(cincr:Float)
	{
		gsIncr = cincr;
	}
	
	public function setGoodCodes(cgood:String)
	{
		gsGoodCodes = cgood;
	}
	
	public function drawAt(cx:Int, cy:Int)
	{
		gsCanvas.addChild(this);
		this.x = cx;
		this.y = cy;
	}

	public function moveTo(cx:Int, cy:Int)
	{
		this.x = cx;
		this.y = cy;
	}
	
	public function setMid(cmidx:Int, cmidy:Int)
	{
		this.x = Std.int(cmidx - (csWd / 2));
		this.y = Std.int(cmidy - (csHt / 2));	
	}
	
	public function getX():Int
	{
		return Std.int(this.x);
	}
	
	public function getY():Int
	{
		return Std.int(this.y);
	}
	
	public function getMidX():Int
	{
		return Std.int(this.x + Std.int(csWd / 2));
	}
	
	public function getMidY():Int
	{
		return Std.int(this.y + (this.csHt / 2));
	}
	
	public function setTileWidth(cwidth:Int):Void
	{
		this.gsTileWidth = cwidth;
	}
	
	public function getXSq():Int
	{
		return Std.int(this.x / this.gsTileWidth);
	}

	public function getYSq():Int
	{
		return Std.int(this.y / this.gsTileWidth);
	}
	
	public function getFeetY():Int
	{
		return Std.int(this.y + this.csHt);
	}
	
	public function setMidX(cmidx:Int):Void
	{
		this.x = Std.int(cmidx - (csWd / 2));
	}
	
	public function setMidY(cmidy:Int):Void
	{
		this.y = Std.int(cmidy - (csHt / 2));
	}
	
	public function setFeetY(cmidy:Int):Void
	{
		this.y = Std.int(cmidy - csHt);
	}
	
	public function dropOnSq(csqx:Int, csqy:Int)
	{
		var cx = gsMap.getMidSqX(csqx) - (32 * (csqy % 2));
		var cy = gsMap.getMidSqY(csqy);
		
		this.setMid(cx, cy);
	}
	
	public function setTarget(ctx:Int, cty:Int):Void
	{
		gsTargetX = ctx;
		gsTargetY = cty;
	}

	public function getTargetX():Int
	{
		return gsTargetX;
	}
	
	public function getTargetY():Int
	{
		return gsTargetY;
	}
	
	public function getName():String
	{
		return gsName;
	}
	
	public function getType():String
	{
		return gsType;
	}
	
	public function getDistance(cx1:Int, cy1:Int, cx2:Int, cy2:Int):Int
	{
		return Std.int(Math.sqrt(Math.pow(cx2 - cx1, 2) + Math.pow(cy2 - cy1, 2)));
	}
	
	public function getDistFrom(cSpr:GameSprite):Int
	{
		return this.getDistance(this.getMidX(), this.getMidY(), cSpr.getMidX(), cSpr.getMidY());
	}
	
	public function doSequence(cSeq:Array<String>):Void
	{	
		var i:Int;
		
		for (i in 0...cSeq.length)
			gsSeq[i] = Std.parseInt(cSeq[i]);
		
		if (this.getXSq() == gsSeq[gsFlag] && this.getYSq() == gsSeq[gsFlag + 1])
		{
			gsFlag = gsFlag + 2;
			if (gsFlag >= gsSeq.length)
				gsFlag = 0;
		}
		
		this.setTarget((gsSeq[gsFlag] * gsTileWidth) + Std.int(gsTileWidth / 2), (gsSeq[gsFlag + 1] * gsTileWidth) + Std.int(gsTileWidth / 2));
	}
	
	public function doMovement():Void
	{
			if (this.gsType == "spider")
			{
				this.doMoveTarget(true);
			}
	}
	
	public function doMoveTarget(reverse:Bool):Void
	{
		var i:Int;
		var j:Int;
		
		var tx:Int;
		var ty:Int;
		var cx:Int;
		var cy:Int;
		var cmidy:Int;
		var mx:Int;
		var my:Int;
		var cdir:Int;
		
		var idir:Int;
		var imult:Int;
		//var cx, cy, cdir, mx, my, spd, midx, midy, ccode;
		//var i, j, imult, idir;
		
		tx = this.gsTargetX;
		ty = this.gsTargetY;
		
		cx = this.getMidX();
		cy = this.getFeetY();
		cmidy = this.getMidY();
		cdir = this.getDir();
		
		mx = gsMap.getSqX(cx);
		my = gsMap.getSqY(cy);
		//trace(cx + " " + cy + " " + gsMap.getMidSqX(mx) + " " + gsMap.getMidSqY(my));
		
		if (mx == this.gsMoveSqX && my == this.gsMoveSqY && cdir != 0)
			return;
		else if (this.getDistance(cx, cy, gsMap.getMidSqX(mx), gsMap.getMidSqY(my)) > 10)
			return;
		else 
		{
			this.gsMoveSqX = mx;
			this.gsMoveSqY = my;
			
			idir = 0;
			imult = 1000000;
			i = 0;
			j = 1000000;
			
			while (i < 4) 
			{
				if (i==0 && (cdir != 2 || reverse == true) && this.isGood(gsMap.getCode(mx + 1, my)))
					j = this.getDistance(cx + 20, cy, tx, ty);
				else if (i==1 && (cdir != 3 || reverse == true) && this.isGood(gsMap.getCode(mx, my + 1)))
					j = this.getDistance(cx, cy + 20, tx, ty);
				else if (i==2 && (cdir != 0 || reverse == true) && this.isGood(gsMap.getCode(mx - 1, my)))
					j = this.getDistance(cx - 20, cy, tx, ty);
				else if (i==3 && (cdir != 1 || reverse == true) && this.isGood(gsMap.getCode(mx, my - 1)))
					j = this.getDistance(cx, cy - 20, tx, ty);
					
				if (j < imult) { 
					idir = i;
					imult = j;
				}
				
				i++;
			}
		}
			
			//if (idir != cdir) this.correctSq();
			this.setDir(idir);
	}
	
	public function correctSq():Void
	{
		var cx:Int;
		var cy:Int; 
		var mx:Int; 
		var my:Int;
		
		cx = this.getMidX();
		cy = this.getFeetY();
		mx = gsMap.getSqX(cx);
		my = gsMap.getSqY(cy);

		this.setMidX(gsMap.getMidSqX(mx));
		this.setFeetY(gsMap.getMidSqY(my));
	}
	
	public function doAnimate(cinterval:Int):Void
	{
		if (runFlag == 0) {
			doAnim = new haxe.Timer(cinterval);
			doAnim.run = doFrames;
			runFlag = 1;
		}
	}
	
	public function doNextFrame()
	{
		this.doFrames();
	}
	
	public function doNextMove()
	{
		if (this.getDir() == 0)
		{
			this.x += this.getSpeed();
		} 
		else if (this.getDir() == 1)
		{
			this.y += this.getSpeed();
		} 
		else if (this.getDir() == 2)
		{
			this.x -= this.getSpeed();
		} 
		else if (this.getDir() == 3)
		{
			this.y -= this.getSpeed();
		}
		
		this.doNextFrame();
	}
	
	public function doCheckMove()
	{
		var ccode1:String;
		var ccode2:String;
		
		ccode1 = this.getMoveCode1(this.getDir(), true);
		ccode2 = this.getMoveCode2(this.getDir(), true);
		
		if (this.isGood(ccode1) && this.isGood(ccode2))
		{
			this.doNextMove();
		}
		else
		{
			//this.setDir(-1);
		}
	}
	
	public function isGood(ccode:String):Bool
	{
		var i:Int;
		
		if (gsGoodCodes.indexOf(gsMap.getType(ccode)) != -1)
			return true;
		else
			return false;
			
		return false;
	}
	
	public function getMoveCode1(cdir:Int, inSq:Bool):String
	{
		var cx:Int = this.getMidX() - Std.int(this.csWd / 2);
		var cy:Int = this.getFeetY();
		var spd:Int = this.getSpeed();
		
		var mx:Int = gsMap.getSqX(cx);
		var my:Int = gsMap.getSqY(cy);
		var midx:Int = gsMap.getMidSqX(mx);
		var midy:Int = gsMap.getMidSqY(my);
		
		var ccode:String = "";
		
		if (cdir == 0) 
		{
			if ((cx + spd + (csWd / 2)) > midx + 32 || inSq == false)
				ccode = gsMap.getCode(mx + 1, my);
			else
				ccode = gsMap.getCode(mx, my);
		}
		else if (cdir == 1) 
		{
			if ((cy + spd) > midy + (gsMap.getTileWidth() / 2) - (gsMap.getTileWidth() * 0.1) || inSq == false)
				ccode = gsMap.getCode(mx, my + 1);
			else
				ccode = gsMap.getCode(mx, my);
		} 
		else if (cdir == 2) 
		{
			if ((cx - spd) < midx || inSq == false)
				ccode = gsMap.getCode(mx - 1, my);
			else
				ccode = gsMap.getCode(mx, my);
		} 
		else if (cdir == 3) 
		{
			if ((cy - spd) < midy - (gsMap.getTileWidth() / 2) + (gsMap.getTileWidth() * 0.25) || inSq == false)
				ccode = gsMap.getCode(mx, my - 1);
			else
				ccode = gsMap.getCode(mx, my);
		}
		
		return ccode;
	}
	
	public function getMoveCode2(cdir:Int, inSq:Bool):String
	{
		var cx:Int = this.getMidX() + Std.int(this.csWd / 2);
		var cy:Int = this.getFeetY();
		var spd:Int = this.getSpeed();
		
		var mx:Int = gsMap.getSqX(cx);
		var my:Int = gsMap.getSqY(cy);
		var midx:Int = gsMap.getMidSqX(mx);
		var midy:Int = gsMap.getMidSqY(my);
		
		var ccode:String = "";
		
		if (cdir == 0) 
		{
			if ((cx + spd + (csWd / 2)) > midx + 32 || inSq == false)
				ccode = gsMap.getCode(mx + 1, my);
			else
				ccode = gsMap.getCode(mx, my);
		}
		else if (cdir == 1) 
		{
			if ((cy + spd) > midy + (gsMap.getTileWidth() / 2) - (gsMap.getTileWidth() * 0.1) || inSq == false)
				ccode = gsMap.getCode(mx, my + 1);
			else
				ccode = gsMap.getCode(mx, my);
		} 
		else if (cdir == 2) 
		{
			if ((cx - spd) < midx || inSq == false)
				ccode = gsMap.getCode(mx - 1, my);
			else
				ccode = gsMap.getCode(mx, my);
		} 
		else if (cdir == 3) 
		{
			if ((cy - spd) < midy - (gsMap.getTileWidth() / 2) + (gsMap.getTileWidth() * 0.25) || inSq == false)
				ccode = gsMap.getCode(mx, my - 1);
			else
				ccode = gsMap.getCode(mx, my);
		}
		
		return ccode;
	}
	
	public function doStop()
	{
		if (runFlag == 1) doAnim.stop();
		runFlag = 0;
	}
	
	public function doStand(cframe:Int)
	{
		if (runFlag == 1) doAnim.stop();
		runFlag = 0;
		this.setFrame(cframe);
	}
	
	private function doFrames():Void
	{
		gsFrame = gsFrame + gsIncr;
		if (gsFrame >= (this.getSheetWidth() + 1)) gsFrame = 0;
		this.setFrame(Std.int(gsFrame));		
	}
}