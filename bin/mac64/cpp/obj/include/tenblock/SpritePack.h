#ifndef INCLUDED_tenblock_SpritePack
#define INCLUDED_tenblock_SpritePack

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
HX_DECLARE_CLASS1(tenblock,CharSprite)
HX_DECLARE_CLASS1(tenblock,GameSprite)
HX_DECLARE_CLASS1(tenblock,SpritePack)
namespace tenblock{


class HXCPP_CLASS_ATTRIBUTES  SpritePack_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SpritePack_obj OBJ_;
		SpritePack_obj();
		Void __construct(::String cfile);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< SpritePack_obj > __new(::String cfile);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~SpritePack_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SpritePack"); }

		Array< ::String > gspNames;
		Array< ::String > gspTypes;
		Array< ::String > gspFiles;
		Array< ::String > gspCodes;
		Array< Float > gspIntervals;
		Array< int > gspAttack;
		Array< int > gspDefence;
		Array< int > gspMovement;
		int anchorX;
		int anchorY;
		int gspTotal;
		::openfl::display::Sprite gspCanvas;
		virtual int getTotal( );
		Dynamic getTotal_dyn();

		virtual ::tenblock::GameSprite makeSprite( int cInd);
		Dynamic makeSprite_dyn();

		virtual int getNum( ::String cname);
		Dynamic getNum_dyn();

};

} // end namespace tenblock

#endif /* INCLUDED_tenblock_SpritePack */ 
