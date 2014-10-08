#ifndef INCLUDED_tenblock_CharSprite
#define INCLUDED_tenblock_CharSprite

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/display/Sprite.h>
HX_DECLARE_CLASS2(openfl,display,Bitmap)
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,display,Sprite)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS1(tenblock,CharSprite)
namespace tenblock{


class HXCPP_CLASS_ATTRIBUTES  CharSprite_obj : public ::openfl::display::Sprite_obj{
	public:
		typedef ::openfl::display::Sprite_obj super;
		typedef CharSprite_obj OBJ_;
		CharSprite_obj();
		Void __construct(::openfl::display::Bitmap csheet,int cx,int cy,int cwd,int cht);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< CharSprite_obj > __new(::openfl::display::Bitmap csheet,int cx,int cy,int cwd,int cht);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~CharSprite_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("CharSprite"); }

		::openfl::display::Bitmap csSheet;
		int csX;
		int csY;
		int csWd;
		int csHt;
		int csDir;
		int csSpeed;
		Array< int > dirMap;
		virtual int getSheetWidth( );
		Dynamic getSheetWidth_dyn();

		virtual int getSpriteWidth( );
		Dynamic getSpriteWidth_dyn();

		virtual int getSpriteHeight( );
		Dynamic getSpriteHeight_dyn();

		virtual int getSheetHeight( );
		Dynamic getSheetHeight_dyn();

		virtual Void setFrame( int cframe);
		Dynamic setFrame_dyn();

		virtual Void setDir( int cdir);
		Dynamic setDir_dyn();

		virtual int getDir( );
		Dynamic getDir_dyn();

		virtual Void setSpeed( int cspd);
		Dynamic setSpeed_dyn();

		virtual int getSpeed( );
		Dynamic getSpeed_dyn();

		virtual Void setDirMap( Array< int > cdirs);
		Dynamic setDirMap_dyn();

};

} // end namespace tenblock

#endif /* INCLUDED_tenblock_CharSprite */ 
