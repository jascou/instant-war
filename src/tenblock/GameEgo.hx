package tenblock;

import flash.display.Bitmap;
import flash.display.Sprite;
import flash.events.Event;
import flash.events.KeyboardEvent;
import flash.geom.Rectangle;
import flash.Lib;
import haxe.Timer;
import openfl.Assets;

class GameEgo extends GameSprite
{

	private var egSpeed:Int;
	private var egMax:Int;
	private var egStrike:GameSprite;
	
	public function new(csheet:Bitmap, cname:String, ctype:String, cx:Int, cy:Int, cwd:Int, cht:Int) 
	{
		super(csheet, cname, ctype, cx, cy, cwd, cht);
		egMax = 3;
		egSpeed = 0;
	}

	public function setStrike(cstrike:GameSprite)
	{
		egStrike = cstrike;
	}
	
	public function sendCode(ccode:Int)
	{
		//trace(ccode);
		
		if (ccode == 39) 
		{
			if (egSpeed == egMax && this.getDir() == 0)
				egSpeed = 0;
			else
				egSpeed = egMax;
				
			this.setDir(0);
		} 
		else if (ccode == 40) 
		{
			if (egSpeed == egMax && this.getDir() == 1)
				egSpeed = 0;
			else
				egSpeed = egMax;
				
			this.setDir(1);
		} 
		else if (ccode == 37) 
		{
			if (egSpeed == egMax && this.getDir() == 2)
				egSpeed = 0;
			else
				egSpeed = egMax;
				
			this.setDir(2);
		} 
		else if (ccode == 38) 
		{
			if (egSpeed == egMax && this.getDir() == 3)
				egSpeed = 0;
			else
				egSpeed = egMax;
				
			this.setDir(3);
		}
		else if (ccode == 13 || ccode == 32)
		{
			if (this.getX() != -100)
			{
				egSpeed = 0;
				egStrike.setDir(this.getDir());
				
				if (egStrike.getDir() == 0)
					egStrike.drawAt(this.getX() + 8, this.getY() - 20);
				else if (egStrike.getDir() == 1)
					egStrike.drawAt(this.getX() - 7, this.getY());
				else if (egStrike.getDir() == 2)
					egStrike.drawAt(this.getX() - 22, this.getY() - 20);
				else if (egStrike.getDir() == 3)
					egStrike.drawAt(this.getX() - 10, this.getY() - 24);
				
				//this.x = -100;
				//this.y = -100;
				this.visible = false;
			}
		}
		
	}
	
	public function stopCode()
	{
		this.doStop();
		
		if (this.visible == false) 
		{
			this.visible = true;
			egStrike.x = -100;
			egStrike.y = -100;
		}
		/*if (this.getX() == -100)
		{
			if (this.getDir() == 0)
			{
				this.drawAt(egStrike.getX() - 8, egStrike.getY() + 20);
				egStrike.x = -100;
				egStrike.y = -100;
			}
			else if (this.getDir() == 1)
			{
				this.drawAt(egStrike.getX() + 7, egStrike.getY());
				egStrike.x = -100;
				egStrike.y = -100;
			}
			else if (this.getDir() == 2)
			{
				this.drawAt(egStrike.getX() + 22, egStrike.getY() + 20);
				egStrike.x = -100;
				egStrike.y = -100;
			}
			else if (this.getDir() == 3)
			{
				this.drawAt(egStrike.getX() + 10, egStrike.getY() + 24);
				this.visible = true;
				egStrike.x = -100;
				egStrike.y = -100;
			}
		}
		*/
	}
	
	public function egoMove()
	{
		var ccode1:String;
		var ccode2:String;
		
		ccode1 = this.getMoveCode1(this.getDir(), true);
		ccode2 = this.getMoveCode2(this.getDir(), true);
		
		if (this.isGood(ccode1) && this.isGood(ccode2))
		{
			if (this.getDir() == 0 && egSpeed > 0)
			{
				this.doNextFrame();
				if ((this.x - this.getCanvas().x) >= 1266/2) this.getCanvas().x -= egSpeed;
				this.x += egSpeed;			
			}
			else if (this.getDir() == 1 && egSpeed > 0)
			{
				this.doNextFrame();
				if ((this.y - this.getCanvas().y) >= 668/2) this.getCanvas().y -= egSpeed;
				this.y += egSpeed;
			} 
			else if (this.getDir() == 2 && egSpeed > 0) 
			{
				this.doNextFrame();
				if (this.getCanvas().x < -egSpeed) this.getCanvas().x += egSpeed;
				this.x -= egSpeed;
			}
			else if (this.getDir() == 3 && egSpeed > 0)
			{
				this.doNextFrame();
				if (this.getCanvas().y < -egSpeed) this.getCanvas().y += egSpeed;
				this.y -= egSpeed;
			}
		}
	}
}