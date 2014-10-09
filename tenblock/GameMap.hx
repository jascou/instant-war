package tenblock;

import flash.display.Bitmap;
import flash.display.Sprite;
import flash.events.Event;
import flash.events.KeyboardEvent;
import flash.geom.Rectangle;
import flash.Lib;
import haxe.Timer;
import openfl.Assets;
import flash.events.MouseEvent;

class GameMap
{
	private var gmRows:Array<String>;
	
	private var gmCodes:Array<String>;
	private var gmNames:Array<String>;
	private var gmTypes:Array<String>;
	private var gmBlocks:Array<String>;
	private var gmWeights:Array<Int>;
	private var gmFiles:Array<String>;
	private var gmWidths:Array<Int>;
	private var gmHeights:Array<Int>;
	
	private var tileWidth:Int;
	private var tileHeight:Int;
	
	private var anchorX:Int;
	private var anchorY:Int;
	
	private var gmWidth:Int;
	private var gmHeight:Int;
	
	private var gmCanvas:Sprite;
	
	public function new(cfile:String) 
	{	
		var i:Int;
		var cxml = Assets.getText(cfile);
		var xml = Xml.parse(cxml);
		var fast = new haxe.xml.Fast(xml.firstElement());

		var rows = fast.node.rows;
	
		gmRows = new Array();
		
		gmCodes = new Array();
		gmNames = new Array();
		gmTypes = new Array();
		gmBlocks = new Array();
		gmWeights = new Array();
		gmFiles = new Array();
		gmWidths = new Array();
		gmHeights = new Array();
		
		anchorX = 10;
		anchorY = -50;
		
		i = 0;
		
		for (p in rows.nodes.row) {
			gmRows[i] = p.innerData;
			i++;
		}
		
		gmHeight = i;
		gmWidth = gmRows[i - 1].length;
		
		var tiles = fast.node.tiles;
		tileWidth = Std.parseInt(fast.node.tilewidth.innerData);
		tileHeight = Std.parseInt(fast.node.tileheight.innerData);
		
		i = 0;
		
		for (q in tiles.nodes.tile) 
		{
			gmCodes[i] = q.node.code.innerData;
			gmNames[i] = q.node.name.innerData;
			gmTypes[i] = q.node.type.innerData;
			gmBlocks[i] = q.node.block.innerData;
			gmWeights[i] = Std.parseInt(q.node.weight.innerData);
			gmFiles[i] = q.node.file.innerData;
			
			i++;
		}
	}

	public function getTileWidth()
	{
		return tileWidth;
	}
	
	public function getWidth()
	{
		return gmWidth;
	}
	
	public function getHeight()
	{
		return gmHeight;
	}
	
	public function setAnchorX(cax:Int):Void
	{
		anchorX = cax;
	}
	
	public function setAnchorY(cay:Int):Void
	{
		anchorY = cay;
	}
	
	public function setCanvas(ccanvas:Sprite)
	{
		gmCanvas = ccanvas;
	}
	
	public function getCanvas()
	{
		return gmCanvas;
	}
	
	public function getMidSqX(csqx:Int):Int
	{
		return Std.int(anchorX + (csqx * tileWidth) + (tileWidth / 2));
	}
	
	public function getMidSqY(csqy:Int):Int
	{
		return Std.int(anchorY + (csqy * tileWidth * 0.85) + (tileHeight / 2));
	}
	
	public function getSqX(cx:Int):Int
	{
		return Std.int(cx / tileWidth);
	}
	
	public function getSqY(cy:Int):Int
	{
		return Std.int(cy / tileWidth);
	}
	
	public function getCode(cx:Int, cy:Int):String
	{
		return gmRows[cy].substr(cx, 1);
	}
	
	public function getType(ccode:String):String
	{
		var i:Int;
		
		i = 0;
		while (i < gmCodes.length) 
		{
			if (ccode == gmCodes[i]) return gmTypes[i];
			i++;
		}
		
		return "";
	}
	
	public function getBlock(ccode:String):String
	{
		var i:Int;
		
		i = 0;
		while (i < gmCodes.length) 
		{
			if (ccode == gmCodes[i]) return gmBlocks[i];
			i++;
		}
		
		return "";
	}
	
	public function getWeight(ccode:String):Int
	{
		var i:Int;
		
		i = 0;
		while (i < gmCodes.length) 
		{
			if (ccode == gmCodes[i]) return gmWeights[i];
			i++;
		}
		
		return -1;
	}
	
	public function isValid(cx:Int, cy:Int, ctype:String):Bool
	{
		if (cx < 0 || cy < 0)
			return false;
		else if (cx >= gmWidth || cy >= gmHeight)
			return false;
		else if (this.getBlock(this.getCode(cx, cy)) == ctype || this.getBlock(this.getCode(cx, cy)) == "all")
			return false;
		else
			return true;
	}
	
	public function getWeightXY(cx:Int, cy:Int):Int
	{
		return this.getWeight(this.getCode(cx, cy));
	}
	
	public function getCoord(ccoord:String, cx:Int, cy:Int):Int
	{
		var i:Int;
		var j:Int;
		var finalx:Int;
		var finaly:Int;
		
		var cxstart:Int;
		var cystart:Int;
		var ytemp:Int;
		
		i = 0;
		j = 0;
		finalx = 0;
		finaly = 0;
		cxstart = 0;
		cystart = 0;
		
		while (i < gmRows.length)
		{
			j = 0;
			
			while (j < gmRows[0].length)
			{
				cxstart = j * tileWidth + anchorX;
				if (i % 2 != 0) cxstart = cxstart - Std.int(tileWidth / 2);
				
				cystart = i * 53 + anchorY;
				
				if (cx >= cxstart && cx < cxstart + tileWidth && cy >= cystart && cy < cystart + tileHeight)
				{
					if (cy - cystart < 21)
					{
						if (cx - cxstart <= 32)
						{
							ytemp = Std.int(((cx - cxstart) / 32) * 21);
							
							if (cy - cystart >= (21 - ytemp))
							{
								finalx = j;
								finaly = i;
							}
						}
						else
						{
							ytemp = Std.int(((cx - cxstart - 32) / 32) * 21);
							
							if (cy - cystart >= ytemp)
							{
								finalx = j;
								finaly = i;
							}
						}
					}
					else if (cy - cystart >= 53)  
					{
						if (cx - cxstart <= 32)
						{
							ytemp = Std.int(((cx - cxstart) / 32) * 21);
							
							if (cy - cystart - 53 <= ytemp)
							{
								finalx = j;
								finaly = i;
							}
						}
						else
						{
							ytemp = Std.int(((cx - cxstart - 32) / 32) * 21);
							
							if (cy - cystart - 53 <= (21 - ytemp))
							{
								finalx = j;
								finaly = i;
							}
						}
					}
					else
					{
						finalx = j;
						finaly = i;
					}
				}
				
				j++;
			}
			
			i++;
		}
		
		if (ccoord == "x") return finalx;
		else return finaly;
	}
	
	public function drawMap():Void
	{
		var i:Int;
		var j:Int;
		var k:Int;
		var ccode:Int;
		
		i = 0;
		while (i < gmRows.length) 
		{
			j = 0;
			
			while (j < gmRows[0].length)
			{
				k = 0;
				ccode = -1;
				
				while (k < gmCodes.length) 
				{
					if (gmRows[i].charAt(j) == gmCodes[k]) 
					{
						ccode = k;
						k = gmCodes.length;
					}
					
					k++;
				}
				
				if (ccode != -1)
				{
					var mapBitmap = new Bitmap (Assets.getBitmapData (gmFiles[ccode]));
					mapBitmap.smoothing = true;
					gmCanvas.addChild(mapBitmap);
					
					if (i % 2 == 0)
					{
						mapBitmap.x = (j * tileWidth) + anchorX;
						mapBitmap.y = (i * tileWidth * 0.85) + anchorY;
					}
					else 
					{
						mapBitmap.x = (j * tileWidth - Std.int(tileWidth / 2)) + anchorX;
						mapBitmap.y = (i * tileWidth * 0.85) + anchorY;
					}

				}
				
				j++;
			}
			
			i++;
		}
	}
}
