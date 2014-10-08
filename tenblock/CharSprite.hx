package tenblock;

import flash.display.Bitmap;
import flash.display.Sprite;
import flash.events.Event;
import flash.geom.Rectangle;
import flash.Lib;
import haxe.Timer;
import openfl.Assets;

class CharSprite extends Sprite
{
	private var csSheet:Bitmap;
	private var csX:Int;
	private var csY:Int;
	private var csWd:Int;
	private var csHt:Int;
	private var csDir:Int;
	private var csSpeed:Int;
	private var dirMap:Array<Int>;
	
	public function new(csheet:Bitmap, cx:Int, cy:Int, cwd:Int, cht:Int) 
	{
		super();
		
		csSheet = new Bitmap();
		csSheet = csheet;
		csSheet.smoothing = true;
		
		csX = cx;
		csY = cy;
		csWd = cwd;
		csHt = cht;
		csDir = 0;
		
		dirMap = new Array();
		dirMap[0] = 0;
		dirMap[1] = 1;
		dirMap[2] = 2;
		dirMap[3] = 3;
		
		this.scrollRect = new Rectangle(0, 0, csWd, csHt);
		this.addChild(csSheet);
	}
	
	public function getSheetWidth():Int
	{
		return csX;
	}

	public function getSpriteWidth()
	{
		return csWd;
	}
	
	public function getSpriteHeight()
	{
		return csHt;
	}
	
	public function getSheetHeight():Int
	{
		return csY;
	}
	
	public function setFrame(cframe:Int)
	{
		if (cframe < csX) {
			csSheet.x = -(csWd * cframe);
		} else {
			csSheet.x = -(csWd * ((csX + 1) - cframe));
		}
	}
	
	public function setDir(cdir:Int)
	{
		csDir = dirMap[cdir];
		csSheet.y = -(csDir * csHt);
	}
	
	public function getDir():Int
	{
		var i:Int;
		
		i = 0;
		while (i < 4)
		{
			if (dirMap[i] == csDir) return i;
			i++;
		}
		
		return -1;
	}
	
	public function setSpeed(cspd:Int)
	{
		csSpeed = cspd;
	}
	
	public function getSpeed():Int
	{
		return csSpeed;
	}
	
	public function setDirMap(cdirs:Array<Int>)
	{
		var i:Int;
		
		for (i in 0...3) {
			dirMap[i] = cdirs[i];
		}
	}
}