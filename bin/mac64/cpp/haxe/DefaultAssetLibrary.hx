package;


import haxe.Timer;
import haxe.Unserializer;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.MovieClip;
import openfl.events.Event;
import openfl.text.Font;
import openfl.media.Sound;
import openfl.net.URLRequest;
import openfl.utils.ByteArray;
import openfl.Assets;

#if (flash || js)
import openfl.display.Loader;
import openfl.events.Event;
import openfl.net.URLLoader;
#end

#if sys
import sys.FileSystem;
#end

#if ios
import openfl.utils.SystemPath;
#end


@:access(openfl.media.Sound)
class DefaultAssetLibrary extends AssetLibrary {
	
	
	public var className (default, null) = new Map <String, Dynamic> ();
	public var path (default, null) = new Map <String, String> ();
	public var type (default, null) = new Map <String, AssetType> ();
	
	private var lastModified:Float;
	private var timer:Timer;
	
	
	public function new () {
		
		super ();
		
		#if flash
		
		path.set ("img/EgoStrike.png", "img/EgoStrike.png");
		type.set ("img/EgoStrike.png", AssetType.IMAGE);
		path.set ("img/EgoStrike.psd", "img/EgoStrike.psd");
		type.set ("img/EgoStrike.psd", AssetType.BINARY);
		path.set ("img/highlight.png", "img/highlight.png");
		type.set ("img/highlight.png", AssetType.IMAGE);
		path.set ("img/MainPlayer.png", "img/MainPlayer.png");
		type.set ("img/MainPlayer.png", AssetType.IMAGE);
		path.set ("img/MainPlayer2.png", "img/MainPlayer2.png");
		type.set ("img/MainPlayer2.png", AssetType.IMAGE);
		path.set ("img/MainPlayer3.png", "img/MainPlayer3.png");
		type.set ("img/MainPlayer3.png", AssetType.IMAGE);
		path.set ("img/MainPlayer3.psd", "img/MainPlayer3.psd");
		type.set ("img/MainPlayer3.psd", AssetType.BINARY);
		path.set ("img/MainStrike.png", "img/MainStrike.png");
		type.set ("img/MainStrike.png", AssetType.IMAGE);
		path.set ("img/MainStrike.psd", "img/MainStrike.psd");
		type.set ("img/MainStrike.psd", AssetType.BINARY);
		path.set ("img/move.png", "img/move.png");
		type.set ("img/move.png", AssetType.IMAGE);
		path.set ("img/NPC1.png", "img/NPC1.png");
		type.set ("img/NPC1.png", AssetType.IMAGE);
		path.set ("img/NPC2.png", "img/NPC2.png");
		type.set ("img/NPC2.png", AssetType.IMAGE);
		path.set ("img/NPC2.psd", "img/NPC2.psd");
		type.set ("img/NPC2.psd", AssetType.BINARY);
		path.set ("img/NPC3.png", "img/NPC3.png");
		type.set ("img/NPC3.png", AssetType.IMAGE);
		path.set ("img/Player2.png", "img/Player2.png");
		type.set ("img/Player2.png", AssetType.IMAGE);
		path.set ("img/select.png", "img/select.png");
		type.set ("img/select.png", AssetType.IMAGE);
		path.set ("img/spider.png", "img/spider.png");
		type.set ("img/spider.png", AssetType.IMAGE);
		path.set ("img/spider.psd", "img/spider.psd");
		type.set ("img/spider.psd", AssetType.BINARY);
		path.set ("img/spider1.png", "img/spider1.png");
		type.set ("img/spider1.png", AssetType.IMAGE);
		path.set ("xml/gamemap.xml", "xml/gamemap.xml");
		type.set ("xml/gamemap.xml", AssetType.TEXT);
		path.set ("xml/gamesprites.xml", "xml/gamesprites.xml");
		type.set ("xml/gamesprites.xml", AssetType.TEXT);
		path.set ("xml/scenario1.xml", "xml/scenario1.xml");
		type.set ("xml/scenario1.xml", AssetType.TEXT);
		path.set ("tiles/filtereffect.psd", "tiles/filtereffect.psd");
		type.set ("tiles/filtereffect.psd", AssetType.BINARY);
		path.set ("tiles/filtereffect2.psd", "tiles/filtereffect2.psd");
		type.set ("tiles/filtereffect2.psd", AssetType.BINARY);
		path.set ("tiles/filtereffect3.psd", "tiles/filtereffect3.psd");
		type.set ("tiles/filtereffect3.psd", AssetType.BINARY);
		path.set ("tiles/floor.png", "tiles/floor.png");
		type.set ("tiles/floor.png", AssetType.IMAGE);
		path.set ("tiles/grass_new.png", "tiles/grass_new.png");
		type.set ("tiles/grass_new.png", AssetType.IMAGE);
		path.set ("tiles/hex_blank.png", "tiles/hex_blank.png");
		type.set ("tiles/hex_blank.png", AssetType.IMAGE);
		path.set ("tiles/hex_border.png", "tiles/hex_border.png");
		type.set ("tiles/hex_border.png", AssetType.IMAGE);
		path.set ("tiles/hex_grass1.png", "tiles/hex_grass1.png");
		type.set ("tiles/hex_grass1.png", AssetType.IMAGE);
		path.set ("tiles/hex_grass1.psd", "tiles/hex_grass1.psd");
		type.set ("tiles/hex_grass1.psd", AssetType.BINARY);
		path.set ("tiles/hex_riverse.png", "tiles/hex_riverse.png");
		type.set ("tiles/hex_riverse.png", AssetType.IMAGE);
		path.set ("tiles/hex_water1.png", "tiles/hex_water1.png");
		type.set ("tiles/hex_water1.png", AssetType.IMAGE);
		path.set ("tiles/road_ew.png", "tiles/road_ew.png");
		type.set ("tiles/road_ew.png", AssetType.IMAGE);
		path.set ("tiles/road_ew_n.png", "tiles/road_ew_n.png");
		type.set ("tiles/road_ew_n.png", AssetType.IMAGE);
		path.set ("tiles/road_ew_s.png", "tiles/road_ew_s.png");
		type.set ("tiles/road_ew_s.png", AssetType.IMAGE);
		path.set ("tiles/road_ne.png", "tiles/road_ne.png");
		type.set ("tiles/road_ne.png", AssetType.IMAGE);
		path.set ("tiles/road_ns.png", "tiles/road_ns.png");
		type.set ("tiles/road_ns.png", AssetType.IMAGE);
		path.set ("tiles/road_ns_e.png", "tiles/road_ns_e.png");
		type.set ("tiles/road_ns_e.png", AssetType.IMAGE);
		path.set ("tiles/road_ns_w.png", "tiles/road_ns_w.png");
		type.set ("tiles/road_ns_w.png", AssetType.IMAGE);
		path.set ("tiles/stonebricks.png", "tiles/stonebricks.png");
		type.set ("tiles/stonebricks.png", AssetType.IMAGE);
		path.set ("sprites/a_inf1.png", "sprites/a_inf1.png");
		type.set ("sprites/a_inf1.png", AssetType.IMAGE);
		path.set ("sprites/a_tank1.png", "sprites/a_tank1.png");
		type.set ("sprites/a_tank1.png", AssetType.IMAGE);
		path.set ("sprites/e_inf1.png", "sprites/e_inf1.png");
		type.set ("sprites/e_inf1.png", AssetType.IMAGE);
		path.set ("sprites/e_tank1.png", "sprites/e_tank1.png");
		type.set ("sprites/e_tank1.png", AssetType.IMAGE);
		path.set ("sprites/NPC1.png", "sprites/NPC1.png");
		type.set ("sprites/NPC1.png", AssetType.IMAGE);
		path.set ("sprites/NPC2.png", "sprites/NPC2.png");
		type.set ("sprites/NPC2.png", AssetType.IMAGE);
		
		
		#elseif html5
		
		var id;
		
		
		#else
		
		#if (windows || mac || linux)
		
		var useManifest = false;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		useManifest = true;
		
		
		if (useManifest) {
			
			loadManifest ();
			
			if (Sys.args ().indexOf ("-livereload") > -1) {
				
				var path = FileSystem.fullPath ("manifest");
				lastModified = FileSystem.stat (path).mtime.getTime ();
				
				timer = new Timer (2000);
				timer.run = function () {
					
					var modified = FileSystem.stat (path).mtime.getTime ();
					
					if (modified > lastModified) {
						
						lastModified = modified;
						loadManifest ();
						
						if (eventCallback != null) {
							
							eventCallback (this, "change");
							
						}
						
					}
					
				}
				
			}
			
		}
		
		#else
		
		loadManifest ();
		
		#end
		#end
		
	}
	
	
	public override function exists (id:String, type:AssetType):Bool {
		
		var assetType = this.type.get (id);
		
		#if pixi
		
		if (assetType == IMAGE) {
			
			return true;
			
		} else {
			
			return false;
			
		}
		
		#end
		
		if (assetType != null) {
			
			if (assetType == type || ((type == SOUND || type == MUSIC) && (assetType == MUSIC || assetType == SOUND))) {
				
				return true;
				
			}
			
			#if flash
			
			if ((assetType == BINARY || assetType == TEXT) && type == BINARY) {
				
				return true;
				
			} else if (path.exists (id)) {
				
				return true;
				
			}
			
			#else
			
			if (type == BINARY || type == null) {
				
				return true;
				
			}
			
			#end
			
		}
		
		return false;
		
	}
	
	
	public override function getBitmapData (id:String):BitmapData {
		
		#if pixi
		
		return BitmapData.fromImage (path.get (id));
		
		#elseif (flash)
		
		return cast (Type.createInstance (className.get (id), []), BitmapData);
		
		#elseif openfl_html5
		
		return BitmapData.fromImage (ApplicationMain.images.get (path.get (id)));
		
		#elseif js
		
		return cast (ApplicationMain.loaders.get (path.get (id)).contentLoaderInfo.content, Bitmap).bitmapData;
		
		#else
		
		if (className.exists(id)) return cast (Type.createInstance (className.get (id), []), BitmapData);
		else return BitmapData.load (path.get (id));
		
		#end
		
	}
	
	
	public override function getBytes (id:String):ByteArray {
		
		#if (flash)
		
		return cast (Type.createInstance (className.get (id), []), ByteArray);

		#elseif (js || openfl_html5 || pixi)
		
		var bytes:ByteArray = null;
		var data = ApplicationMain.urlLoaders.get (path.get (id)).data;
		
		if (Std.is (data, String)) {
			
			bytes = new ByteArray ();
			bytes.writeUTFBytes (data);
			
		} else if (Std.is (data, ByteArray)) {
			
			bytes = cast data;
			
		} else {
			
			bytes = null;
			
		}

		if (bytes != null) {
			
			bytes.position = 0;
			return bytes;
			
		} else {
			
			return null;
		}
		
		#else
		
		if (className.exists(id)) return cast (Type.createInstance (className.get (id), []), ByteArray);
		else return ByteArray.readFile (path.get (id));
		
		#end
		
	}
	
	
	public override function getFont (id:String):Font {
		
		#if pixi
		
		return null;
		
		#elseif (flash || js)
		
		return cast (Type.createInstance (className.get (id), []), Font);
		
		#else
		
		if (className.exists(id)) {
			var fontClass = className.get(id);
			Font.registerFont(fontClass);
			return cast (Type.createInstance (fontClass, []), Font);
		} else return new Font (path.get (id));
		
		#end
		
	}
	
	
	public override function getMusic (id:String):Sound {
		
		#if pixi
		
		return null;
		
		#elseif (flash)
		
		return cast (Type.createInstance (className.get (id), []), Sound);
		
		#elseif openfl_html5
		
		var sound = new Sound ();
		sound.__buffer = true;
		sound.load (new URLRequest (path.get (id)));
		return sound; 
		
		#elseif js
		
		return new Sound (new URLRequest (path.get (id)));
		
		#else
		
		if (className.exists(id)) return cast (Type.createInstance (className.get (id), []), Sound);
		else return new Sound (new URLRequest (path.get (id)), null, true);
		
		#end
		
	}
	
	
	public override function getPath (id:String):String {
		
		#if ios
		
		return SystemPath.applicationDirectory + "/assets/" + path.get (id);
		
		#else
		
		return path.get (id);
		
		#end
		
	}
	
	
	public override function getSound (id:String):Sound {
		
		#if pixi
		
		return null;
		
		#elseif (flash)
		
		return cast (Type.createInstance (className.get (id), []), Sound);
		
		#elseif js
		
		return new Sound (new URLRequest (path.get (id)));
		
		#else
		
		if (className.exists(id)) return cast (Type.createInstance (className.get (id), []), Sound);
		else return new Sound (new URLRequest (path.get (id)), null, type.get (id) == MUSIC);
		
		#end
		
	}
	
	
	public override function getText (id:String):String {
		
		#if js
		
		var bytes:ByteArray = null;
		var data = ApplicationMain.urlLoaders.get (path.get (id)).data;
		
		if (Std.is (data, String)) {
			
			return cast data;
			
		} else if (Std.is (data, ByteArray)) {
			
			bytes = cast data;
			
		} else {
			
			bytes = null;
			
		}
		
		if (bytes != null) {
			
			bytes.position = 0;
			return bytes.readUTFBytes (bytes.length);
			
		} else {
			
			return null;
		}
		
		#else
		
		var bytes = getBytes (id);
		
		if (bytes == null) {
			
			return null;
			
		} else {
			
			return bytes.readUTFBytes (bytes.length);
			
		}
		
		#end
		
	}
	
	
	public override function isLocal (id:String, type:AssetType):Bool {
		
		#if flash
		
		if (type != AssetType.MUSIC && type != AssetType.SOUND) {
			
			return className.exists (id);
			
		}
		
		#end
		
		return true;
		
	}
	
	
	public override function list (type:AssetType):Array<String> {
		
		var items = [];
		
		for (id in this.type.keys ()) {
			
			if (type == null || exists (id, type)) {
				
				items.push (id);
				
			}
			
		}
		
		return items;
		
	}
	
	
	public override function loadBitmapData (id:String, handler:BitmapData -> Void):Void {
		
		#if pixi
		
		handler (getBitmapData (id));
		
		#elseif (flash || js)
		
		if (path.exists (id)) {
			
			var loader = new Loader ();
			loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event:Event) {
				
				handler (cast (event.currentTarget.content, Bitmap).bitmapData);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {
			
			handler (getBitmapData (id));
			
		}
		
		#else
		
		handler (getBitmapData (id));
		
		#end
		
	}
	
	
	public override function loadBytes (id:String, handler:ByteArray -> Void):Void {
		
		#if pixi
		
		handler (getBytes (id));
		
		#elseif (flash || js)
		
		if (path.exists (id)) {
			
			var loader = new URLLoader ();
			loader.addEventListener (Event.COMPLETE, function (event:Event) {
				
				var bytes = new ByteArray ();
				bytes.writeUTFBytes (event.currentTarget.data);
				bytes.position = 0;
				
				handler (bytes);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {
			
			handler (getBytes (id));
			
		}
		
		#else
		
		handler (getBytes (id));
		
		#end
		
	}
	
	
	public override function loadFont (id:String, handler:Font -> Void):Void {
		
		#if (flash || js)
		
		/*if (path.exists (id)) {
			
			var loader = new Loader ();
			loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event) {
				
				handler (cast (event.currentTarget.content, Bitmap).bitmapData);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {*/
			
			handler (getFont (id));
			
		//}
		
		#else
		
		handler (getFont (id));
		
		#end
		
	}
	
	
	#if (!flash && !html5)
	private function loadManifest ():Void {
		
		try {
			
			#if blackberry
			var bytes = ByteArray.readFile ("app/native/manifest");
			#elseif tizen
			var bytes = ByteArray.readFile ("../res/manifest");
			#elseif emscripten
			var bytes = ByteArray.readFile ("assets/manifest");
			#else
			var bytes = ByteArray.readFile ("manifest");
			#end
			
			if (bytes != null) {
				
				bytes.position = 0;
				
				if (bytes.length > 0) {
					
					var data = bytes.readUTFBytes (bytes.length);
					
					if (data != null && data.length > 0) {
						
						var manifest:Array<Dynamic> = Unserializer.run (data);
						
						for (asset in manifest) {
							
							if (!className.exists (asset.id)) {
								
								path.set (asset.id, asset.path);
								type.set (asset.id, Type.createEnum (AssetType, asset.type));
								
							}
							
						}
						
					}
					
				}
				
			} else {
				
				trace ("Warning: Could not load asset manifest (bytes was null)");
				
			}
		
		} catch (e:Dynamic) {
			
			trace ('Warning: Could not load asset manifest (${e})');
			
		}
		
	}
	#end
	
	
	public override function loadMusic (id:String, handler:Sound -> Void):Void {
		
		#if (flash || js)
		
		/*if (path.exists (id)) {
			
			var loader = new Loader ();
			loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event) {
				
				handler (cast (event.currentTarget.content, Bitmap).bitmapData);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {*/
			
			handler (getMusic (id));
			
		//}
		
		#else
		
		handler (getMusic (id));
		
		#end
		
	}
	
	
	public override function loadSound (id:String, handler:Sound -> Void):Void {
		
		#if (flash || js)
		
		/*if (path.exists (id)) {
			
			var loader = new Loader ();
			loader.contentLoaderInfo.addEventListener (Event.COMPLETE, function (event) {
				
				handler (cast (event.currentTarget.content, Bitmap).bitmapData);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {*/
			
			handler (getSound (id));
			
		//}
		
		#else
		
		handler (getSound (id));
		
		#end
		
	}
	
	
	public override function loadText (id:String, handler:String -> Void):Void {
		
		#if js
		
		if (path.exists (id)) {
			
			var loader = new URLLoader ();
			loader.addEventListener (Event.COMPLETE, function (event:Event) {
				
				handler (event.currentTarget.data);
				
			});
			loader.load (new URLRequest (path.get (id)));
			
		} else {
			
			handler (getText (id));
			
		}
		
		#else
		
		var callback = function (bytes:ByteArray):Void {
			
			if (bytes == null) {
				
				handler (null);
				
			} else {
				
				handler (bytes.readUTFBytes (bytes.length));
				
			}
			
		}
		
		loadBytes (id, callback);
		
		#end
		
	}
	
	
}


#if pixi
#elseif flash


















































#elseif html5


















































#elseif (windows || mac || linux)




#end
