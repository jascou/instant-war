package lime;


import lime.utils.Assets;


class AssetData {

	private static var initialized:Bool = false;
	
	public static var library = new #if haxe3 Map <String, #else Hash <#end LibraryType> ();
	public static var path = new #if haxe3 Map <String, #else Hash <#end String> ();
	public static var type = new #if haxe3 Map <String, #else Hash <#end AssetType> ();	
	
	public static function initialize():Void {
		
		if (!initialized) {
			
			path.set ("img/EgoStrike.png", "img/EgoStrike.png");
			type.set ("img/EgoStrike.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("img/EgoStrike.psd", "img/EgoStrike.psd");
			type.set ("img/EgoStrike.psd", Reflect.field (AssetType, "binary".toUpperCase ()));
			path.set ("img/highlight.png", "img/highlight.png");
			type.set ("img/highlight.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("img/MainPlayer.png", "img/MainPlayer.png");
			type.set ("img/MainPlayer.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("img/MainPlayer2.png", "img/MainPlayer2.png");
			type.set ("img/MainPlayer2.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("img/MainPlayer3.png", "img/MainPlayer3.png");
			type.set ("img/MainPlayer3.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("img/MainPlayer3.psd", "img/MainPlayer3.psd");
			type.set ("img/MainPlayer3.psd", Reflect.field (AssetType, "binary".toUpperCase ()));
			path.set ("img/MainStrike.png", "img/MainStrike.png");
			type.set ("img/MainStrike.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("img/MainStrike.psd", "img/MainStrike.psd");
			type.set ("img/MainStrike.psd", Reflect.field (AssetType, "binary".toUpperCase ()));
			path.set ("img/move.png", "img/move.png");
			type.set ("img/move.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("img/NPC1.png", "img/NPC1.png");
			type.set ("img/NPC1.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("img/NPC2.png", "img/NPC2.png");
			type.set ("img/NPC2.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("img/NPC2.psd", "img/NPC2.psd");
			type.set ("img/NPC2.psd", Reflect.field (AssetType, "binary".toUpperCase ()));
			path.set ("img/NPC3.png", "img/NPC3.png");
			type.set ("img/NPC3.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("img/Player2.png", "img/Player2.png");
			type.set ("img/Player2.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("img/select.png", "img/select.png");
			type.set ("img/select.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("img/spider.png", "img/spider.png");
			type.set ("img/spider.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("img/spider.psd", "img/spider.psd");
			type.set ("img/spider.psd", Reflect.field (AssetType, "binary".toUpperCase ()));
			path.set ("img/spider1.png", "img/spider1.png");
			type.set ("img/spider1.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("xml/gamemap.xml", "xml/gamemap.xml");
			type.set ("xml/gamemap.xml", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("xml/gamesprites.xml", "xml/gamesprites.xml");
			type.set ("xml/gamesprites.xml", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("xml/scenario1.xml", "xml/scenario1.xml");
			type.set ("xml/scenario1.xml", Reflect.field (AssetType, "text".toUpperCase ()));
			path.set ("tiles/filtereffect.psd", "tiles/filtereffect.psd");
			type.set ("tiles/filtereffect.psd", Reflect.field (AssetType, "binary".toUpperCase ()));
			path.set ("tiles/filtereffect2.psd", "tiles/filtereffect2.psd");
			type.set ("tiles/filtereffect2.psd", Reflect.field (AssetType, "binary".toUpperCase ()));
			path.set ("tiles/filtereffect3.psd", "tiles/filtereffect3.psd");
			type.set ("tiles/filtereffect3.psd", Reflect.field (AssetType, "binary".toUpperCase ()));
			path.set ("tiles/floor.png", "tiles/floor.png");
			type.set ("tiles/floor.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("tiles/grass_new.png", "tiles/grass_new.png");
			type.set ("tiles/grass_new.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("tiles/hex_blank.png", "tiles/hex_blank.png");
			type.set ("tiles/hex_blank.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("tiles/hex_border.png", "tiles/hex_border.png");
			type.set ("tiles/hex_border.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("tiles/hex_grass1.png", "tiles/hex_grass1.png");
			type.set ("tiles/hex_grass1.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("tiles/hex_grass1.psd", "tiles/hex_grass1.psd");
			type.set ("tiles/hex_grass1.psd", Reflect.field (AssetType, "binary".toUpperCase ()));
			path.set ("tiles/hex_riverse.png", "tiles/hex_riverse.png");
			type.set ("tiles/hex_riverse.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("tiles/hex_water1.png", "tiles/hex_water1.png");
			type.set ("tiles/hex_water1.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("tiles/road_ew.png", "tiles/road_ew.png");
			type.set ("tiles/road_ew.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("tiles/road_ew_n.png", "tiles/road_ew_n.png");
			type.set ("tiles/road_ew_n.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("tiles/road_ew_s.png", "tiles/road_ew_s.png");
			type.set ("tiles/road_ew_s.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("tiles/road_ne.png", "tiles/road_ne.png");
			type.set ("tiles/road_ne.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("tiles/road_ns.png", "tiles/road_ns.png");
			type.set ("tiles/road_ns.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("tiles/road_ns_e.png", "tiles/road_ns_e.png");
			type.set ("tiles/road_ns_e.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("tiles/road_ns_w.png", "tiles/road_ns_w.png");
			type.set ("tiles/road_ns_w.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("tiles/stonebricks.png", "tiles/stonebricks.png");
			type.set ("tiles/stonebricks.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("sprites/a_inf1.png", "sprites/a_inf1.png");
			type.set ("sprites/a_inf1.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("sprites/a_tank1.png", "sprites/a_tank1.png");
			type.set ("sprites/a_tank1.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("sprites/e_inf1.png", "sprites/e_inf1.png");
			type.set ("sprites/e_inf1.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("sprites/e_tank1.png", "sprites/e_tank1.png");
			type.set ("sprites/e_tank1.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("sprites/NPC1.png", "sprites/NPC1.png");
			type.set ("sprites/NPC1.png", Reflect.field (AssetType, "image".toUpperCase ()));
			path.set ("sprites/NPC2.png", "sprites/NPC2.png");
			type.set ("sprites/NPC2.png", Reflect.field (AssetType, "image".toUpperCase ()));
			
			
			initialized = true;
			
		} //!initialized
		
	} //initialize
	
	
} //AssetData
