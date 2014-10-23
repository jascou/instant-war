package tenblock;

import flash.display.Bitmap;
import flash.display.Sprite;
import flash.events.Event;
import flash.events.KeyboardEvent;
import flash.geom.Rectangle;
import flash.Lib;
import haxe.Timer;
import openfl.Assets;

class SpritePack
{
	private var gspNames:Array<String>;
	private var gspTypes:Array<String>;
	private var gspFiles:Array<String>;
	private var gspCodes:Array<String>;
	private var gspIntervals:Array<Float>;
	
	private var gspAttack:Array<Int>;
	private var gspDefence:Array<Int>;
	private var gspMovement:Array<Int>;
	private var gspTType:Array<String>;
	private var gspTCost:Array<Int>;
	
	private var anchorX:Int;
	private var anchorY:Int;
	private var gspTotal:Int;
	
	private var gspCanvas:Sprite;
	
	public function new(cfile:String) 
	{	
		var i:Int;
		var j:Int;
		var cxml = Assets.getText(cfile);
		var xml = Xml.parse(cxml);
		var fast = new haxe.xml.Fast(xml.firstElement());

		gspNames = new Array();
		gspTypes = new Array();
		gspFiles = new Array();
		gspCodes = new Array();
		gspIntervals = new Array();
		
		gspAttack = new Array();
		gspDefence = new Array();
		gspMovement = new Array();
		gspTType = new Array();
		gspTCost = new Array();
		
		anchorX = 0;
		anchorY = 0;
		gspTotal = 0;
		
		i = 0;
		
		var chars = fast.node.chars;
		
		i = 0;
		
		for (q in chars.nodes.char) 
		{
			gspNames[i] = q.node.name.innerData;
			gspTypes[i] = q.node.type.innerData;
			gspFiles[i] = q.node.file.innerData;
			
			gspAttack[i] = Std.parseInt(q.node.attack.innerData);
			gspDefence[i] = Std.parseInt(q.node.defence.innerData);
			gspMovement[i] = Std.parseInt(q.node.movement.innerData);
			
			j = 0;
			
			for (r in q.nodes.terrain)
			{
				gspTType[(i * 100) + j] = r.node.type.innerData;
				gspTCost[(i * 100) + j] = Std.parseInt(r.node.cost.innerData);
				j++;
			}
			
			gspTotal++;
			i++;
		}
	}

	public function getTotal()
	{
		return gspTotal;
	}

	public function getWeight(cname:String, ctype:String):Int
	{
		var i:Int;
		var j:Int;
		
		i = 0;
		j = 0;
		
		while (i < gspNames.length)
		{
			if (gspNames[i] == cname) j = i;
			i++;
		}
		
		i = j * 100;
		
		while (gspTType[i] != ctype)
		{
			//if (i > 12) trace(ctype + " " + gspTType[i]);
			i++;
		}
		
		return gspTCost[i];
	}
	
	public function getType(cname:String):String
	{
		var i:Int;
		
		i = 0;
		
		while (i < gspTotal)
		{
			if (gspNames[i] == cname)
				return gspTypes[i];
			i++;
		}
		
		return "none";
	}
	
	public function getAttack(cname:String):Int
	{
		var i:Int;
		
		i = 0;
		
		while (i < gspTotal)
		{
			if (gspNames[i] == cname)
				return gspAttack[i];
			i++;
		}
		
		return -1;
	}

	public function getDefend(cname:String):Int
	{
		var i:Int;
		
		i = 0;
		
		while (i < gspTotal)
		{
			if (gspNames[i] == cname)
				return gspDefence[i];
			i++;
		}
		
		return -1;
	}
	
	public function makeSprite(cInd:Int)
	{
		var c_sprite:GameSprite;
		c_sprite = new GameSprite(new Bitmap (Assets.getBitmapData (gspFiles[cInd])), gspNames[cInd], gspTypes[cInd], 3, 4, 45, 45);
		
		return c_sprite;
	}
	
	public function getNum(cname:String):Int
	{
		var i:Int;
		
		i = 0;
		
		while (i < gspTotal)
		{
			if (gspNames[i] == cname)
				return i;
				
			i++;
		}
		
		return -1;
	}
	
	public function getMovement(cname:String):Int
	{
		var i:Int;
		
		i = 0;
		
		while (i < gspTotal)
		{
			if (gspNames[i] == cname)
				return gspMovement[i];
				
			i++;
		}
		
		return -1;		
	}
}