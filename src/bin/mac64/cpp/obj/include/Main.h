#ifndef INCLUDED_Main
#define INCLUDED_Main

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/display/Sprite.h>
HX_DECLARE_CLASS0(Main)
HX_DECLARE_CLASS1(haxe,Timer)
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,display,Sprite)
HX_DECLARE_CLASS2(openfl,events,Event)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS2(openfl,events,KeyboardEvent)
HX_DECLARE_CLASS2(openfl,events,MouseEvent)
HX_DECLARE_CLASS2(openfl,net,URLLoader)
HX_DECLARE_CLASS1(tenblock,CharSprite)
HX_DECLARE_CLASS1(tenblock,GameEgo)
HX_DECLARE_CLASS1(tenblock,GameMap)
HX_DECLARE_CLASS1(tenblock,GameSprite)
HX_DECLARE_CLASS1(tenblock,Scenario)
HX_DECLARE_CLASS1(tenblock,SpritePack)


class HXCPP_CLASS_ATTRIBUTES  Main_obj : public ::openfl::display::Sprite_obj{
	public:
		typedef ::openfl::display::Sprite_obj super;
		typedef Main_obj OBJ_;
		Main_obj();
		Void __construct();

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Main_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Main_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Main"); }

		bool inited;
		Array< ::Dynamic > gameImages;
		Array< ::Dynamic > gameMoves;
		::openfl::display::Sprite MainPl;
		int MainFr;
		int gameTime;
		int animTime;
		::haxe::Timer doAnim;
		::tenblock::GameEgo gameEgo;
		::tenblock::GameSprite gameEgoStrike;
		::tenblock::GameMap gameMap;
		::tenblock::SpritePack sprPack;
		::tenblock::Scenario gameSc;
		int egoWidth;
		int egoHeight;
		::openfl::net::URLLoader _xmlLoader;
		virtual Void resize( Dynamic e);
		Dynamic resize_dyn();

		virtual Void init( );
		Dynamic init_dyn();

		virtual Void added( Dynamic e);
		Dynamic added_dyn();

		virtual Void doSpriteOrder( Array< ::Dynamic > csprs);
		Dynamic doSpriteOrder_dyn();

		virtual Void this_onEnterFrame( ::openfl::events::Event event);
		Dynamic this_onEnterFrame_dyn();

		virtual Void stage_onKeyDown( ::openfl::events::KeyboardEvent event);
		Dynamic stage_onKeyDown_dyn();

		virtual Void stage_onKeyUp( ::openfl::events::KeyboardEvent event);
		Dynamic stage_onKeyUp_dyn();

		virtual Void _loadXML( );
		Dynamic _loadXML_dyn();

		virtual Void _onXMLLoaded( ::openfl::events::Event e);
		Dynamic _onXMLLoaded_dyn();

		virtual Void onMouseMove( ::openfl::events::MouseEvent e);
		Dynamic onMouseMove_dyn();

		virtual Void onMouseDown( ::openfl::events::MouseEvent e);
		Dynamic onMouseDown_dyn();

		static Void main( );
		static Dynamic main_dyn();

};


#endif /* INCLUDED_Main */ 
