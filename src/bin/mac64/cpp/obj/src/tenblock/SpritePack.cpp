#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_haxe_xml_Fast
#include <haxe/xml/Fast.h>
#endif
#ifndef INCLUDED_haxe_xml__Fast_NodeAccess
#include <haxe/xml/_Fast/NodeAccess.h>
#endif
#ifndef INCLUDED_haxe_xml__Fast_NodeListAccess
#include <haxe/xml/_Fast/NodeListAccess.h>
#endif
#ifndef INCLUDED_openfl_Assets
#include <openfl/Assets.h>
#endif
#ifndef INCLUDED_openfl_display_Bitmap
#include <openfl/display/Bitmap.h>
#endif
#ifndef INCLUDED_openfl_display_BitmapData
#include <openfl/display/BitmapData.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObject
#include <openfl/display/DisplayObject.h>
#endif
#ifndef INCLUDED_openfl_display_DisplayObjectContainer
#include <openfl/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_openfl_display_IBitmapDrawable
#include <openfl/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_openfl_display_InteractiveObject
#include <openfl/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_openfl_display_PixelSnapping
#include <openfl/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_tenblock_CharSprite
#include <tenblock/CharSprite.h>
#endif
#ifndef INCLUDED_tenblock_GameSprite
#include <tenblock/GameSprite.h>
#endif
#ifndef INCLUDED_tenblock_SpritePack
#include <tenblock/SpritePack.h>
#endif
namespace tenblock{

Void SpritePack_obj::__construct(::String cfile)
{
HX_STACK_FRAME("tenblock.SpritePack","new",0x6ac329ee,"tenblock.SpritePack.new","tenblock/SpritePack.hx",31,0xe6be40a1)
HX_STACK_THIS(this)
HX_STACK_ARG(cfile,"cfile")
{
	HX_STACK_LINE(32)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(33)
	::String cxml = ::openfl::Assets_obj::getText(cfile);		HX_STACK_VAR(cxml,"cxml");
	HX_STACK_LINE(34)
	::Xml xml = ::Xml_obj::parse(cxml);		HX_STACK_VAR(xml,"xml");
	HX_STACK_LINE(35)
	::Xml _g = xml->firstElement();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(35)
	::haxe::xml::Fast fast = ::haxe::xml::Fast_obj::__new(_g);		HX_STACK_VAR(fast,"fast");
	HX_STACK_LINE(37)
	Array< ::String > _g1 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(37)
	this->gspNames = _g1;
	HX_STACK_LINE(38)
	Array< ::String > _g2 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(38)
	this->gspTypes = _g2;
	HX_STACK_LINE(39)
	Array< ::String > _g3 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(39)
	this->gspFiles = _g3;
	HX_STACK_LINE(40)
	Array< ::String > _g4 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(40)
	this->gspCodes = _g4;
	HX_STACK_LINE(41)
	Array< Float > _g5 = Array_obj< Float >::__new();		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(41)
	this->gspIntervals = _g5;
	HX_STACK_LINE(43)
	Array< int > _g6 = Array_obj< int >::__new();		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(43)
	this->gspAttack = _g6;
	HX_STACK_LINE(44)
	Array< int > _g7 = Array_obj< int >::__new();		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(44)
	this->gspDefence = _g7;
	HX_STACK_LINE(45)
	Array< int > _g8 = Array_obj< int >::__new();		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(45)
	this->gspMovement = _g8;
	HX_STACK_LINE(47)
	this->anchorX = (int)0;
	HX_STACK_LINE(48)
	this->anchorY = (int)0;
	HX_STACK_LINE(49)
	this->gspTotal = (int)0;
	HX_STACK_LINE(51)
	i = (int)0;
	HX_STACK_LINE(53)
	::haxe::xml::Fast chars = fast->node->resolve(HX_CSTRING("chars"));		HX_STACK_VAR(chars,"chars");
	HX_STACK_LINE(55)
	i = (int)0;
	HX_STACK_LINE(57)
	for(::cpp::FastIterator_obj< ::haxe::xml::Fast > *__it = ::cpp::CreateFastIterator< ::haxe::xml::Fast >(chars->nodes->resolve(HX_CSTRING("char"))->iterator());  __it->hasNext(); ){
		::haxe::xml::Fast q = __it->next();
		{
			HX_STACK_LINE(59)
			this->gspNames[i] = q->node->resolve(HX_CSTRING("name"))->get_innerData();
			HX_STACK_LINE(60)
			this->gspTypes[i] = q->node->resolve(HX_CSTRING("type"))->get_innerData();
			HX_STACK_LINE(61)
			this->gspFiles[i] = q->node->resolve(HX_CSTRING("file"))->get_innerData();
			HX_STACK_LINE(63)
			::String _g9 = q->node->resolve(HX_CSTRING("attack"))->get_innerData();		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(63)
			this->gspAttack[i] = ::Std_obj::parseInt(_g9);
			HX_STACK_LINE(64)
			::String _g10 = q->node->resolve(HX_CSTRING("defence"))->get_innerData();		HX_STACK_VAR(_g10,"_g10");
			HX_STACK_LINE(64)
			this->gspDefence[i] = ::Std_obj::parseInt(_g10);
			HX_STACK_LINE(65)
			::String _g11 = q->node->resolve(HX_CSTRING("movement"))->get_innerData();		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(65)
			this->gspMovement[i] = ::Std_obj::parseInt(_g11);
			HX_STACK_LINE(67)
			for(::cpp::FastIterator_obj< ::haxe::xml::Fast > *__it = ::cpp::CreateFastIterator< ::haxe::xml::Fast >(q->nodes->resolve(HX_CSTRING("safe"))->iterator());  __it->hasNext(); ){
				::haxe::xml::Fast r = __it->next();
				{
					HX_STACK_LINE(69)
					::String _g12 = r->get_innerData();		HX_STACK_VAR(_g12,"_g12");
					HX_STACK_LINE(69)
					this->gspCodes[i] = (this->gspCodes->__get(i) + _g12);
				}
;
			}
			HX_STACK_LINE(72)
			(this->gspTotal)++;
			HX_STACK_LINE(73)
			(i)++;
		}
;
	}
}
;
	return null();
}

//SpritePack_obj::~SpritePack_obj() { }

Dynamic SpritePack_obj::__CreateEmpty() { return  new SpritePack_obj; }
hx::ObjectPtr< SpritePack_obj > SpritePack_obj::__new(::String cfile)
{  hx::ObjectPtr< SpritePack_obj > result = new SpritePack_obj();
	result->__construct(cfile);
	return result;}

Dynamic SpritePack_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SpritePack_obj > result = new SpritePack_obj();
	result->__construct(inArgs[0]);
	return result;}

int SpritePack_obj::getTotal( ){
	HX_STACK_FRAME("tenblock.SpritePack","getTotal",0x6104a700,"tenblock.SpritePack.getTotal","tenblock/SpritePack.hx",79,0xe6be40a1)
	HX_STACK_THIS(this)
	HX_STACK_LINE(79)
	return this->gspTotal;
}


HX_DEFINE_DYNAMIC_FUNC0(SpritePack_obj,getTotal,return )

::tenblock::GameSprite SpritePack_obj::makeSprite( int cInd){
	HX_STACK_FRAME("tenblock.SpritePack","makeSprite",0xaa7ec4c5,"tenblock.SpritePack.makeSprite","tenblock/SpritePack.hx",83,0xe6be40a1)
	HX_STACK_THIS(this)
	HX_STACK_ARG(cInd,"cInd")
	HX_STACK_LINE(84)
	::tenblock::GameSprite c_sprite;		HX_STACK_VAR(c_sprite,"c_sprite");
	HX_STACK_LINE(85)
	::openfl::display::BitmapData _g = ::openfl::Assets_obj::getBitmapData(this->gspFiles->__get(cInd),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(85)
	::openfl::display::Bitmap _g1 = ::openfl::display::Bitmap_obj::__new(_g,null(),null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(85)
	::tenblock::GameSprite _g2 = ::tenblock::GameSprite_obj::__new(_g1,this->gspNames->__get(cInd),this->gspTypes->__get(cInd),(int)3,(int)4,(int)45,(int)45);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(85)
	c_sprite = _g2;
	HX_STACK_LINE(87)
	return c_sprite;
}


HX_DEFINE_DYNAMIC_FUNC1(SpritePack_obj,makeSprite,return )

int SpritePack_obj::getNum( ::String cname){
	HX_STACK_FRAME("tenblock.SpritePack","getNum",0x59edaa82,"tenblock.SpritePack.getNum","tenblock/SpritePack.hx",91,0xe6be40a1)
	HX_STACK_THIS(this)
	HX_STACK_ARG(cname,"cname")
	HX_STACK_LINE(92)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(94)
	i = (int)0;
	HX_STACK_LINE(96)
	while((true)){
		HX_STACK_LINE(96)
		if ((!(((i < this->gspTotal))))){
			HX_STACK_LINE(96)
			break;
		}
		HX_STACK_LINE(98)
		if (((this->gspNames->__get(i) == cname))){
			HX_STACK_LINE(99)
			return i;
		}
		HX_STACK_LINE(101)
		(i)++;
	}
	HX_STACK_LINE(104)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC1(SpritePack_obj,getNum,return )


SpritePack_obj::SpritePack_obj()
{
}

void SpritePack_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SpritePack);
	HX_MARK_MEMBER_NAME(gspNames,"gspNames");
	HX_MARK_MEMBER_NAME(gspTypes,"gspTypes");
	HX_MARK_MEMBER_NAME(gspFiles,"gspFiles");
	HX_MARK_MEMBER_NAME(gspCodes,"gspCodes");
	HX_MARK_MEMBER_NAME(gspIntervals,"gspIntervals");
	HX_MARK_MEMBER_NAME(gspAttack,"gspAttack");
	HX_MARK_MEMBER_NAME(gspDefence,"gspDefence");
	HX_MARK_MEMBER_NAME(gspMovement,"gspMovement");
	HX_MARK_MEMBER_NAME(anchorX,"anchorX");
	HX_MARK_MEMBER_NAME(anchorY,"anchorY");
	HX_MARK_MEMBER_NAME(gspTotal,"gspTotal");
	HX_MARK_MEMBER_NAME(gspCanvas,"gspCanvas");
	HX_MARK_END_CLASS();
}

void SpritePack_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(gspNames,"gspNames");
	HX_VISIT_MEMBER_NAME(gspTypes,"gspTypes");
	HX_VISIT_MEMBER_NAME(gspFiles,"gspFiles");
	HX_VISIT_MEMBER_NAME(gspCodes,"gspCodes");
	HX_VISIT_MEMBER_NAME(gspIntervals,"gspIntervals");
	HX_VISIT_MEMBER_NAME(gspAttack,"gspAttack");
	HX_VISIT_MEMBER_NAME(gspDefence,"gspDefence");
	HX_VISIT_MEMBER_NAME(gspMovement,"gspMovement");
	HX_VISIT_MEMBER_NAME(anchorX,"anchorX");
	HX_VISIT_MEMBER_NAME(anchorY,"anchorY");
	HX_VISIT_MEMBER_NAME(gspTotal,"gspTotal");
	HX_VISIT_MEMBER_NAME(gspCanvas,"gspCanvas");
}

Dynamic SpritePack_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"getNum") ) { return getNum_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"anchorX") ) { return anchorX; }
		if (HX_FIELD_EQ(inName,"anchorY") ) { return anchorY; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"gspNames") ) { return gspNames; }
		if (HX_FIELD_EQ(inName,"gspTypes") ) { return gspTypes; }
		if (HX_FIELD_EQ(inName,"gspFiles") ) { return gspFiles; }
		if (HX_FIELD_EQ(inName,"gspCodes") ) { return gspCodes; }
		if (HX_FIELD_EQ(inName,"gspTotal") ) { return gspTotal; }
		if (HX_FIELD_EQ(inName,"getTotal") ) { return getTotal_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"gspAttack") ) { return gspAttack; }
		if (HX_FIELD_EQ(inName,"gspCanvas") ) { return gspCanvas; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"gspDefence") ) { return gspDefence; }
		if (HX_FIELD_EQ(inName,"makeSprite") ) { return makeSprite_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"gspMovement") ) { return gspMovement; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"gspIntervals") ) { return gspIntervals; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SpritePack_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"anchorX") ) { anchorX=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"anchorY") ) { anchorY=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"gspNames") ) { gspNames=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gspTypes") ) { gspTypes=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gspFiles") ) { gspFiles=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gspCodes") ) { gspCodes=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gspTotal") ) { gspTotal=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"gspAttack") ) { gspAttack=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gspCanvas") ) { gspCanvas=inValue.Cast< ::openfl::display::Sprite >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"gspDefence") ) { gspDefence=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"gspMovement") ) { gspMovement=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"gspIntervals") ) { gspIntervals=inValue.Cast< Array< Float > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SpritePack_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("gspNames"));
	outFields->push(HX_CSTRING("gspTypes"));
	outFields->push(HX_CSTRING("gspFiles"));
	outFields->push(HX_CSTRING("gspCodes"));
	outFields->push(HX_CSTRING("gspIntervals"));
	outFields->push(HX_CSTRING("gspAttack"));
	outFields->push(HX_CSTRING("gspDefence"));
	outFields->push(HX_CSTRING("gspMovement"));
	outFields->push(HX_CSTRING("anchorX"));
	outFields->push(HX_CSTRING("anchorY"));
	outFields->push(HX_CSTRING("gspTotal"));
	outFields->push(HX_CSTRING("gspCanvas"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(SpritePack_obj,gspNames),HX_CSTRING("gspNames")},
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(SpritePack_obj,gspTypes),HX_CSTRING("gspTypes")},
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(SpritePack_obj,gspFiles),HX_CSTRING("gspFiles")},
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(SpritePack_obj,gspCodes),HX_CSTRING("gspCodes")},
	{hx::fsObject /*Array< Float >*/ ,(int)offsetof(SpritePack_obj,gspIntervals),HX_CSTRING("gspIntervals")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(SpritePack_obj,gspAttack),HX_CSTRING("gspAttack")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(SpritePack_obj,gspDefence),HX_CSTRING("gspDefence")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(SpritePack_obj,gspMovement),HX_CSTRING("gspMovement")},
	{hx::fsInt,(int)offsetof(SpritePack_obj,anchorX),HX_CSTRING("anchorX")},
	{hx::fsInt,(int)offsetof(SpritePack_obj,anchorY),HX_CSTRING("anchorY")},
	{hx::fsInt,(int)offsetof(SpritePack_obj,gspTotal),HX_CSTRING("gspTotal")},
	{hx::fsObject /*::openfl::display::Sprite*/ ,(int)offsetof(SpritePack_obj,gspCanvas),HX_CSTRING("gspCanvas")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("gspNames"),
	HX_CSTRING("gspTypes"),
	HX_CSTRING("gspFiles"),
	HX_CSTRING("gspCodes"),
	HX_CSTRING("gspIntervals"),
	HX_CSTRING("gspAttack"),
	HX_CSTRING("gspDefence"),
	HX_CSTRING("gspMovement"),
	HX_CSTRING("anchorX"),
	HX_CSTRING("anchorY"),
	HX_CSTRING("gspTotal"),
	HX_CSTRING("gspCanvas"),
	HX_CSTRING("getTotal"),
	HX_CSTRING("makeSprite"),
	HX_CSTRING("getNum"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SpritePack_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SpritePack_obj::__mClass,"__mClass");
};

#endif

Class SpritePack_obj::__mClass;

void SpritePack_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tenblock.SpritePack"), hx::TCanCast< SpritePack_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void SpritePack_obj::__boot()
{
}

} // end namespace tenblock
