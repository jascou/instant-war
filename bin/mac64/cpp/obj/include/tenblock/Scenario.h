#ifndef INCLUDED_tenblock_Scenario
#define INCLUDED_tenblock_Scenario

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
HX_DECLARE_CLASS1(tenblock,GameMap)
HX_DECLARE_CLASS1(tenblock,GameSprite)
HX_DECLARE_CLASS1(tenblock,Scenario)
HX_DECLARE_CLASS1(tenblock,SpritePack)
namespace tenblock{


class HXCPP_CLASS_ATTRIBUTES  Scenario_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Scenario_obj OBJ_;
		Scenario_obj();
		Void __construct(::String cfile);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Scenario_obj > __new(::String cfile);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Scenario_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Scenario"); }

		::String scName;
		Array< ::String > scNames;
		Array< ::String > scSides;
		Array< int > scStartX;
		Array< int > scStartY;
		Array< ::Dynamic > scCounters;
		Array< int > csrX;
		Array< int > csrY;
		Array< int > csrFlag;
		Array< int > csrWeight;
		Array< int > csrAnc;
		Array< int > scX;
		Array< int > scY;
		::tenblock::SpritePack scPack;
		::tenblock::GameMap scMap;
		::openfl::display::Sprite scCanvas;
		int scCount;
		virtual Void doDraw( );
		Dynamic doDraw_dyn();

		virtual Void setCMP( ::openfl::display::Sprite ccanvas,::tenblock::GameMap cmap,::tenblock::SpritePack cpack);
		Dynamic setCMP_dyn();

		virtual int getCount( int cx,int cy,::String cside);
		Dynamic getCount_dyn();

		virtual Void findPath( int cfromx,int cfromy,int ctox,int ctoy,int cinit,Array< int > cresults);
		Dynamic findPath_dyn();

		virtual int getNode( int cx,int cy,int cweight);
		Dynamic getNode_dyn();

};

} // end namespace tenblock

#endif /* INCLUDED_tenblock_Scenario */ 
