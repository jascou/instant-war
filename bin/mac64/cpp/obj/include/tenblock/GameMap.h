#ifndef INCLUDED_tenblock_GameMap
#define INCLUDED_tenblock_GameMap

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,display,Sprite)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS1(tenblock,GameMap)
namespace tenblock{


class HXCPP_CLASS_ATTRIBUTES  GameMap_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef GameMap_obj OBJ_;
		GameMap_obj();
		Void __construct(::String cfile);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< GameMap_obj > __new(::String cfile);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~GameMap_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("GameMap"); }

		Array< ::String > gmRows;
		Array< ::String > gmCodes;
		Array< ::String > gmNames;
		Array< ::String > gmTypes;
		Array< ::String > gmBlocks;
		Array< ::String > gmFiles;
		Array< int > gmWidths;
		Array< int > gmHeights;
		int tileWidth;
		int tileHeight;
		int anchorX;
		int anchorY;
		int gmWidth;
		int gmHeight;
		::openfl::display::Sprite gmCanvas;
		virtual int getTileWidth( );
		Dynamic getTileWidth_dyn();

		virtual int getWidth( );
		Dynamic getWidth_dyn();

		virtual int getHeight( );
		Dynamic getHeight_dyn();

		virtual Void setAnchorX( int cax);
		Dynamic setAnchorX_dyn();

		virtual Void setAnchorY( int cay);
		Dynamic setAnchorY_dyn();

		virtual Void setCanvas( ::openfl::display::Sprite ccanvas);
		Dynamic setCanvas_dyn();

		virtual ::openfl::display::Sprite getCanvas( );
		Dynamic getCanvas_dyn();

		virtual int getMidSqX( int csqx);
		Dynamic getMidSqX_dyn();

		virtual int getMidSqY( int csqy);
		Dynamic getMidSqY_dyn();

		virtual int getSqX( int cx);
		Dynamic getSqX_dyn();

		virtual int getSqY( int cy);
		Dynamic getSqY_dyn();

		virtual ::String getCode( int cx,int cy);
		Dynamic getCode_dyn();

		virtual ::String getType( ::String ccode);
		Dynamic getType_dyn();

		virtual ::String getBlock( ::String ccode);
		Dynamic getBlock_dyn();

		virtual bool isValid( int cx,int cy,::String ctype);
		Dynamic isValid_dyn();

		virtual int getCoord( ::String ccoord,int cx,int cy);
		Dynamic getCoord_dyn();

		virtual Void drawMap( );
		Dynamic drawMap_dyn();

};

} // end namespace tenblock

#endif /* INCLUDED_tenblock_GameMap */ 
