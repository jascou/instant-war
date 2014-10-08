#include <hxcpp.h>

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
#ifndef INCLUDED_openfl_geom_Rectangle
#include <openfl/geom/Rectangle.h>
#endif
#ifndef INCLUDED_tenblock_CharSprite
#include <tenblock/CharSprite.h>
#endif
namespace tenblock{

Void CharSprite_obj::__construct(::openfl::display::Bitmap csheet,int cx,int cy,int cwd,int cht)
{
HX_STACK_FRAME("tenblock.CharSprite","new",0xbfd41a6b,"tenblock.CharSprite.new","tenblock/CharSprite.hx",23,0x732daec4)
HX_STACK_THIS(this)
HX_STACK_ARG(csheet,"csheet")
HX_STACK_ARG(cx,"cx")
HX_STACK_ARG(cy,"cy")
HX_STACK_ARG(cwd,"cwd")
HX_STACK_ARG(cht,"cht")
{
	HX_STACK_LINE(24)
	super::__construct();
	HX_STACK_LINE(26)
	::openfl::display::Bitmap _g = ::openfl::display::Bitmap_obj::__new(null(),null(),null());		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(26)
	this->csSheet = _g;
	HX_STACK_LINE(27)
	this->csSheet = csheet;
	HX_STACK_LINE(28)
	this->csSheet->set_smoothing(true);
	HX_STACK_LINE(30)
	this->csX = cx;
	HX_STACK_LINE(31)
	this->csY = cy;
	HX_STACK_LINE(32)
	this->csWd = cwd;
	HX_STACK_LINE(33)
	this->csHt = cht;
	HX_STACK_LINE(34)
	this->csDir = (int)0;
	HX_STACK_LINE(36)
	Array< int > _g1 = Array_obj< int >::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(36)
	this->dirMap = _g1;
	HX_STACK_LINE(37)
	this->dirMap[(int)0] = (int)0;
	HX_STACK_LINE(38)
	this->dirMap[(int)1] = (int)1;
	HX_STACK_LINE(39)
	this->dirMap[(int)2] = (int)2;
	HX_STACK_LINE(40)
	this->dirMap[(int)3] = (int)3;
	HX_STACK_LINE(42)
	::openfl::geom::Rectangle _g2 = ::openfl::geom::Rectangle_obj::__new((int)0,(int)0,this->csWd,this->csHt);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(42)
	this->set_scrollRect(_g2);
	HX_STACK_LINE(43)
	this->addChild(this->csSheet);
}
;
	return null();
}

//CharSprite_obj::~CharSprite_obj() { }

Dynamic CharSprite_obj::__CreateEmpty() { return  new CharSprite_obj; }
hx::ObjectPtr< CharSprite_obj > CharSprite_obj::__new(::openfl::display::Bitmap csheet,int cx,int cy,int cwd,int cht)
{  hx::ObjectPtr< CharSprite_obj > result = new CharSprite_obj();
	result->__construct(csheet,cx,cy,cwd,cht);
	return result;}

Dynamic CharSprite_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< CharSprite_obj > result = new CharSprite_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4]);
	return result;}

int CharSprite_obj::getSheetWidth( ){
	HX_STACK_FRAME("tenblock.CharSprite","getSheetWidth",0x1bdd24e8,"tenblock.CharSprite.getSheetWidth","tenblock/CharSprite.hx",48,0x732daec4)
	HX_STACK_THIS(this)
	HX_STACK_LINE(48)
	return this->csX;
}


HX_DEFINE_DYNAMIC_FUNC0(CharSprite_obj,getSheetWidth,return )

int CharSprite_obj::getSpriteWidth( ){
	HX_STACK_FRAME("tenblock.CharSprite","getSpriteWidth",0x220d96a0,"tenblock.CharSprite.getSpriteWidth","tenblock/CharSprite.hx",53,0x732daec4)
	HX_STACK_THIS(this)
	HX_STACK_LINE(53)
	return this->csWd;
}


HX_DEFINE_DYNAMIC_FUNC0(CharSprite_obj,getSpriteWidth,return )

int CharSprite_obj::getSpriteHeight( ){
	HX_STACK_FRAME("tenblock.CharSprite","getSpriteHeight",0x6025ae0d,"tenblock.CharSprite.getSpriteHeight","tenblock/CharSprite.hx",58,0x732daec4)
	HX_STACK_THIS(this)
	HX_STACK_LINE(58)
	return this->csHt;
}


HX_DEFINE_DYNAMIC_FUNC0(CharSprite_obj,getSpriteHeight,return )

int CharSprite_obj::getSheetHeight( ){
	HX_STACK_FRAME("tenblock.CharSprite","getSheetHeight",0xfbf29ec5,"tenblock.CharSprite.getSheetHeight","tenblock/CharSprite.hx",63,0x732daec4)
	HX_STACK_THIS(this)
	HX_STACK_LINE(63)
	return this->csY;
}


HX_DEFINE_DYNAMIC_FUNC0(CharSprite_obj,getSheetHeight,return )

Void CharSprite_obj::setFrame( int cframe){
{
		HX_STACK_FRAME("tenblock.CharSprite","setFrame",0xf3d84f40,"tenblock.CharSprite.setFrame","tenblock/CharSprite.hx",68,0x732daec4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cframe,"cframe")
		HX_STACK_LINE(68)
		if (((cframe < this->csX))){
			HX_STACK_LINE(69)
			this->csSheet->set_x(-(((this->csWd * cframe))));
		}
		else{
			HX_STACK_LINE(71)
			this->csSheet->set_x(-(((this->csWd * (((this->csX + (int)1) - cframe))))));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CharSprite_obj,setFrame,(void))

Void CharSprite_obj::setDir( int cdir){
{
		HX_STACK_FRAME("tenblock.CharSprite","setDir",0x50f319a0,"tenblock.CharSprite.setDir","tenblock/CharSprite.hx",76,0x732daec4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cdir,"cdir")
		HX_STACK_LINE(77)
		this->csDir = this->dirMap->__get(cdir);
		HX_STACK_LINE(78)
		this->csSheet->set_y(-(((this->csDir * this->csHt))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CharSprite_obj,setDir,(void))

int CharSprite_obj::getDir( ){
	HX_STACK_FRAME("tenblock.CharSprite","getDir",0x84aac52c,"tenblock.CharSprite.getDir","tenblock/CharSprite.hx",82,0x732daec4)
	HX_STACK_THIS(this)
	HX_STACK_LINE(83)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(85)
	i = (int)0;
	HX_STACK_LINE(86)
	while((true)){
		HX_STACK_LINE(86)
		if ((!(((i < (int)4))))){
			HX_STACK_LINE(86)
			break;
		}
		HX_STACK_LINE(88)
		if (((this->dirMap->__get(i) == this->csDir))){
			HX_STACK_LINE(88)
			return i;
		}
		HX_STACK_LINE(89)
		(i)++;
	}
	HX_STACK_LINE(92)
	return (int)-1;
}


HX_DEFINE_DYNAMIC_FUNC0(CharSprite_obj,getDir,return )

Void CharSprite_obj::setSpeed( int cspd){
{
		HX_STACK_FRAME("tenblock.CharSprite","setSpeed",0x6ebe6e9a,"tenblock.CharSprite.setSpeed","tenblock/CharSprite.hx",97,0x732daec4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cspd,"cspd")
		HX_STACK_LINE(97)
		this->csSpeed = cspd;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CharSprite_obj,setSpeed,(void))

int CharSprite_obj::getSpeed( ){
	HX_STACK_FRAME("tenblock.CharSprite","getSpeed",0xc0611526,"tenblock.CharSprite.getSpeed","tenblock/CharSprite.hx",102,0x732daec4)
	HX_STACK_THIS(this)
	HX_STACK_LINE(102)
	return this->csSpeed;
}


HX_DEFINE_DYNAMIC_FUNC0(CharSprite_obj,getSpeed,return )

Void CharSprite_obj::setDirMap( Array< int > cdirs){
{
		HX_STACK_FRAME("tenblock.CharSprite","setDirMap",0x793f6cdc,"tenblock.CharSprite.setDirMap","tenblock/CharSprite.hx",106,0x732daec4)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cdirs,"cdirs")
		HX_STACK_LINE(107)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(109)
		{
			HX_STACK_LINE(109)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(109)
			while((true)){
				HX_STACK_LINE(109)
				if ((!(((_g < (int)3))))){
					HX_STACK_LINE(109)
					break;
				}
				HX_STACK_LINE(109)
				int i1 = (_g)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(110)
				this->dirMap[i1] = cdirs->__get(i1);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(CharSprite_obj,setDirMap,(void))


CharSprite_obj::CharSprite_obj()
{
}

void CharSprite_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(CharSprite);
	HX_MARK_MEMBER_NAME(csSheet,"csSheet");
	HX_MARK_MEMBER_NAME(csX,"csX");
	HX_MARK_MEMBER_NAME(csY,"csY");
	HX_MARK_MEMBER_NAME(csWd,"csWd");
	HX_MARK_MEMBER_NAME(csHt,"csHt");
	HX_MARK_MEMBER_NAME(csDir,"csDir");
	HX_MARK_MEMBER_NAME(csSpeed,"csSpeed");
	HX_MARK_MEMBER_NAME(dirMap,"dirMap");
	::openfl::display::DisplayObjectContainer_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void CharSprite_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(csSheet,"csSheet");
	HX_VISIT_MEMBER_NAME(csX,"csX");
	HX_VISIT_MEMBER_NAME(csY,"csY");
	HX_VISIT_MEMBER_NAME(csWd,"csWd");
	HX_VISIT_MEMBER_NAME(csHt,"csHt");
	HX_VISIT_MEMBER_NAME(csDir,"csDir");
	HX_VISIT_MEMBER_NAME(csSpeed,"csSpeed");
	HX_VISIT_MEMBER_NAME(dirMap,"dirMap");
	::openfl::display::DisplayObjectContainer_obj::__Visit(HX_VISIT_ARG);
}

Dynamic CharSprite_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"csX") ) { return csX; }
		if (HX_FIELD_EQ(inName,"csY") ) { return csY; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"csWd") ) { return csWd; }
		if (HX_FIELD_EQ(inName,"csHt") ) { return csHt; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"csDir") ) { return csDir; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"dirMap") ) { return dirMap; }
		if (HX_FIELD_EQ(inName,"setDir") ) { return setDir_dyn(); }
		if (HX_FIELD_EQ(inName,"getDir") ) { return getDir_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"csSheet") ) { return csSheet; }
		if (HX_FIELD_EQ(inName,"csSpeed") ) { return csSpeed; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"setFrame") ) { return setFrame_dyn(); }
		if (HX_FIELD_EQ(inName,"setSpeed") ) { return setSpeed_dyn(); }
		if (HX_FIELD_EQ(inName,"getSpeed") ) { return getSpeed_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setDirMap") ) { return setDirMap_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"getSheetWidth") ) { return getSheetWidth_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"getSpriteWidth") ) { return getSpriteWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"getSheetHeight") ) { return getSheetHeight_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"getSpriteHeight") ) { return getSpriteHeight_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic CharSprite_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"csX") ) { csX=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"csY") ) { csY=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"csWd") ) { csWd=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"csHt") ) { csHt=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"csDir") ) { csDir=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"dirMap") ) { dirMap=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"csSheet") ) { csSheet=inValue.Cast< ::openfl::display::Bitmap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"csSpeed") ) { csSpeed=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void CharSprite_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("csSheet"));
	outFields->push(HX_CSTRING("csX"));
	outFields->push(HX_CSTRING("csY"));
	outFields->push(HX_CSTRING("csWd"));
	outFields->push(HX_CSTRING("csHt"));
	outFields->push(HX_CSTRING("csDir"));
	outFields->push(HX_CSTRING("csSpeed"));
	outFields->push(HX_CSTRING("dirMap"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::openfl::display::Bitmap*/ ,(int)offsetof(CharSprite_obj,csSheet),HX_CSTRING("csSheet")},
	{hx::fsInt,(int)offsetof(CharSprite_obj,csX),HX_CSTRING("csX")},
	{hx::fsInt,(int)offsetof(CharSprite_obj,csY),HX_CSTRING("csY")},
	{hx::fsInt,(int)offsetof(CharSprite_obj,csWd),HX_CSTRING("csWd")},
	{hx::fsInt,(int)offsetof(CharSprite_obj,csHt),HX_CSTRING("csHt")},
	{hx::fsInt,(int)offsetof(CharSprite_obj,csDir),HX_CSTRING("csDir")},
	{hx::fsInt,(int)offsetof(CharSprite_obj,csSpeed),HX_CSTRING("csSpeed")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(CharSprite_obj,dirMap),HX_CSTRING("dirMap")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("csSheet"),
	HX_CSTRING("csX"),
	HX_CSTRING("csY"),
	HX_CSTRING("csWd"),
	HX_CSTRING("csHt"),
	HX_CSTRING("csDir"),
	HX_CSTRING("csSpeed"),
	HX_CSTRING("dirMap"),
	HX_CSTRING("getSheetWidth"),
	HX_CSTRING("getSpriteWidth"),
	HX_CSTRING("getSpriteHeight"),
	HX_CSTRING("getSheetHeight"),
	HX_CSTRING("setFrame"),
	HX_CSTRING("setDir"),
	HX_CSTRING("getDir"),
	HX_CSTRING("setSpeed"),
	HX_CSTRING("getSpeed"),
	HX_CSTRING("setDirMap"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(CharSprite_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(CharSprite_obj::__mClass,"__mClass");
};

#endif

Class CharSprite_obj::__mClass;

void CharSprite_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tenblock.CharSprite"), hx::TCanCast< CharSprite_obj> ,sStaticFields,sMemberFields,
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

void CharSprite_obj::__boot()
{
}

} // end namespace tenblock
