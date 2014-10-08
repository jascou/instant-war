#ifndef INCLUDED_tenblock_GameSprite
#define INCLUDED_tenblock_GameSprite

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tenblock/CharSprite.h>
HX_DECLARE_CLASS1(haxe,Timer)
HX_DECLARE_CLASS2(openfl,display,Bitmap)
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,display,Sprite)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS1(tenblock,CharSprite)
HX_DECLARE_CLASS1(tenblock,GameMap)
HX_DECLARE_CLASS1(tenblock,GameSprite)
namespace tenblock{


class HXCPP_CLASS_ATTRIBUTES  GameSprite_obj : public ::tenblock::CharSprite_obj{
	public:
		typedef ::tenblock::CharSprite_obj super;
		typedef GameSprite_obj OBJ_;
		GameSprite_obj();
		Void __construct(::openfl::display::Bitmap csheet,::String cname,::String ctype,int cx,int cy,int cwd,int cht);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< GameSprite_obj > __new(::openfl::display::Bitmap csheet,::String cname,::String ctype,int cx,int cy,int cwd,int cht);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~GameSprite_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("GameSprite"); }

		::String gsName;
		::String gsType;
		::openfl::display::Sprite gsCanvas;
		::haxe::Timer doAnim;
		Float gsFrame;
		int runFlag;
		Float gsIncr;
		int gsTargetX;
		int gsTargetY;
		int gsMoveSqX;
		int gsMoveSqY;
		::tenblock::GameMap gsMap;
		::String gsGoodCodes;
		Array< int > gsSeq;
		int gsFlag;
		int gsTileWidth;
		virtual Void setCanvas( ::openfl::display::Sprite ccanvas);
		Dynamic setCanvas_dyn();

		virtual ::openfl::display::Sprite getCanvas( );
		Dynamic getCanvas_dyn();

		virtual Void setMap( ::tenblock::GameMap cmap);
		Dynamic setMap_dyn();

		virtual ::tenblock::GameMap getMap( );
		Dynamic getMap_dyn();

		virtual Void setInterval( Float cincr);
		Dynamic setInterval_dyn();

		virtual Void setGoodCodes( ::String cgood);
		Dynamic setGoodCodes_dyn();

		virtual Void drawAt( int cx,int cy);
		Dynamic drawAt_dyn();

		virtual Void moveTo( int cx,int cy);
		Dynamic moveTo_dyn();

		virtual Void setMid( int cmidx,int cmidy);
		Dynamic setMid_dyn();

		virtual int getX( );
		Dynamic getX_dyn();

		virtual int getY( );
		Dynamic getY_dyn();

		virtual int getMidX( );
		Dynamic getMidX_dyn();

		virtual int getMidY( );
		Dynamic getMidY_dyn();

		virtual Void setTileWidth( int cwidth);
		Dynamic setTileWidth_dyn();

		virtual int getXSq( );
		Dynamic getXSq_dyn();

		virtual int getYSq( );
		Dynamic getYSq_dyn();

		virtual int getFeetY( );
		Dynamic getFeetY_dyn();

		virtual Void setMidX( int cmidx);
		Dynamic setMidX_dyn();

		virtual Void setMidY( int cmidy);
		Dynamic setMidY_dyn();

		virtual Void setFeetY( int cmidy);
		Dynamic setFeetY_dyn();

		virtual Void dropOnSq( int csqx,int csqy);
		Dynamic dropOnSq_dyn();

		virtual Void setTarget( int ctx,int cty);
		Dynamic setTarget_dyn();

		virtual int getTargetX( );
		Dynamic getTargetX_dyn();

		virtual int getTargetY( );
		Dynamic getTargetY_dyn();

		virtual ::String getName( );
		Dynamic getName_dyn();

		virtual ::String getType( );
		Dynamic getType_dyn();

		virtual int getDistance( int cx1,int cy1,int cx2,int cy2);
		Dynamic getDistance_dyn();

		virtual int getDistFrom( ::tenblock::GameSprite cSpr);
		Dynamic getDistFrom_dyn();

		virtual Void doSequence( Array< ::String > cSeq);
		Dynamic doSequence_dyn();

		virtual Void doMovement( );
		Dynamic doMovement_dyn();

		virtual Void doMoveTarget( bool reverse);
		Dynamic doMoveTarget_dyn();

		virtual Void correctSq( );
		Dynamic correctSq_dyn();

		virtual Void doAnimate( int cinterval);
		Dynamic doAnimate_dyn();

		virtual Void doNextFrame( );
		Dynamic doNextFrame_dyn();

		virtual Void doNextMove( );
		Dynamic doNextMove_dyn();

		virtual Void doCheckMove( );
		Dynamic doCheckMove_dyn();

		virtual bool isGood( ::String ccode);
		Dynamic isGood_dyn();

		virtual ::String getMoveCode1( int cdir,bool inSq);
		Dynamic getMoveCode1_dyn();

		virtual ::String getMoveCode2( int cdir,bool inSq);
		Dynamic getMoveCode2_dyn();

		virtual Void doStop( );
		Dynamic doStop_dyn();

		virtual Void doStand( int cframe);
		Dynamic doStand_dyn();

		virtual Void doFrames( );
		Dynamic doFrames_dyn();

};

} // end namespace tenblock

#endif /* INCLUDED_tenblock_GameSprite */ 
