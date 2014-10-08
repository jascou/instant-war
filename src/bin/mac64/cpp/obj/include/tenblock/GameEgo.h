#ifndef INCLUDED_tenblock_GameEgo
#define INCLUDED_tenblock_GameEgo

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <tenblock/GameSprite.h>
HX_DECLARE_CLASS2(openfl,display,Bitmap)
HX_DECLARE_CLASS2(openfl,display,DisplayObject)
HX_DECLARE_CLASS2(openfl,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(openfl,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,display,InteractiveObject)
HX_DECLARE_CLASS2(openfl,display,Sprite)
HX_DECLARE_CLASS2(openfl,events,EventDispatcher)
HX_DECLARE_CLASS2(openfl,events,IEventDispatcher)
HX_DECLARE_CLASS1(tenblock,CharSprite)
HX_DECLARE_CLASS1(tenblock,GameEgo)
HX_DECLARE_CLASS1(tenblock,GameSprite)
namespace tenblock{


class HXCPP_CLASS_ATTRIBUTES  GameEgo_obj : public ::tenblock::GameSprite_obj{
	public:
		typedef ::tenblock::GameSprite_obj super;
		typedef GameEgo_obj OBJ_;
		GameEgo_obj();
		Void __construct(::openfl::display::Bitmap csheet,::String cname,::String ctype,int cx,int cy,int cwd,int cht);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< GameEgo_obj > __new(::openfl::display::Bitmap csheet,::String cname,::String ctype,int cx,int cy,int cwd,int cht);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~GameEgo_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("GameEgo"); }

		int egSpeed;
		int egMax;
		::tenblock::GameSprite egStrike;
		virtual Void setStrike( ::tenblock::GameSprite cstrike);
		Dynamic setStrike_dyn();

		virtual Void sendCode( int ccode);
		Dynamic sendCode_dyn();

		virtual Void stopCode( );
		Dynamic stopCode_dyn();

		virtual Void egoMove( );
		Dynamic egoMove_dyn();

};

} // end namespace tenblock

#endif /* INCLUDED_tenblock_GameEgo */ 
