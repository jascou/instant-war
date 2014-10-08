#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_openfl_display_Bitmap
#include <openfl/display/Bitmap.h>
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
#ifndef INCLUDED_tenblock_GameMap
#include <tenblock/GameMap.h>
#endif
#ifndef INCLUDED_tenblock_GameSprite
#include <tenblock/GameSprite.h>
#endif
namespace tenblock{

Void GameSprite_obj::__construct(::openfl::display::Bitmap csheet,::String cname,::String ctype,int cx,int cy,int cwd,int cht)
{
HX_STACK_FRAME("tenblock.GameSprite","new",0x6bf3aa87,"tenblock.GameSprite.new","tenblock/GameSprite.hx",35,0x04989628)
HX_STACK_THIS(this)
HX_STACK_ARG(csheet,"csheet")
HX_STACK_ARG(cname,"cname")
HX_STACK_ARG(ctype,"ctype")
HX_STACK_ARG(cx,"cx")
HX_STACK_ARG(cy,"cy")
HX_STACK_ARG(cwd,"cwd")
HX_STACK_ARG(cht,"cht")
{
	HX_STACK_LINE(36)
	super::__construct(csheet,cx,cy,cwd,cht);
	HX_STACK_LINE(38)
	this->gsName = cname;
	HX_STACK_LINE(39)
	this->gsType = ctype;
	HX_STACK_LINE(41)
	this->gsFrame = (int)0;
	HX_STACK_LINE(42)
	this->runFlag = (int)0;
	HX_STACK_LINE(43)
	this->gsIncr = (int)1;
	HX_STACK_LINE(45)
	this->gsMoveSqX = (int)-1;
	HX_STACK_LINE(46)
	this->gsMoveSqY = (int)-1;
	HX_STACK_LINE(47)
	this->gsFlag = (int)0;
	HX_STACK_LINE(48)
	Array< int > _g = Array_obj< int >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(48)
	this->gsSeq = _g;
}
;
	return null();
}

//GameSprite_obj::~GameSprite_obj() { }

Dynamic GameSprite_obj::__CreateEmpty() { return  new GameSprite_obj; }
hx::ObjectPtr< GameSprite_obj > GameSprite_obj::__new(::openfl::display::Bitmap csheet,::String cname,::String ctype,int cx,int cy,int cwd,int cht)
{  hx::ObjectPtr< GameSprite_obj > result = new GameSprite_obj();
	result->__construct(csheet,cname,ctype,cx,cy,cwd,cht);
	return result;}

Dynamic GameSprite_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GameSprite_obj > result = new GameSprite_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6]);
	return result;}

Void GameSprite_obj::setCanvas( ::openfl::display::Sprite ccanvas){
{
		HX_STACK_FRAME("tenblock.GameSprite","setCanvas",0x21ae3b81,"tenblock.GameSprite.setCanvas","tenblock/GameSprite.hx",53,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_ARG(ccanvas,"ccanvas")
		HX_STACK_LINE(53)
		this->gsCanvas = ccanvas;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameSprite_obj,setCanvas,(void))

::openfl::display::Sprite GameSprite_obj::getCanvas( ){
	HX_STACK_FRAME("tenblock.GameSprite","getCanvas",0x3e5d4f75,"tenblock.GameSprite.getCanvas","tenblock/GameSprite.hx",58,0x04989628)
	HX_STACK_THIS(this)
	HX_STACK_LINE(58)
	return this->gsCanvas;
}


HX_DEFINE_DYNAMIC_FUNC0(GameSprite_obj,getCanvas,return )

Void GameSprite_obj::setMap( ::tenblock::GameMap cmap){
{
		HX_STACK_FRAME("tenblock.GameSprite","setMap",0x03765053,"tenblock.GameSprite.setMap","tenblock/GameSprite.hx",63,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cmap,"cmap")
		HX_STACK_LINE(63)
		this->gsMap = cmap;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameSprite_obj,setMap,(void))

::tenblock::GameMap GameSprite_obj::getMap( ){
	HX_STACK_FRAME("tenblock.GameSprite","getMap",0x372dfbdf,"tenblock.GameSprite.getMap","tenblock/GameSprite.hx",68,0x04989628)
	HX_STACK_THIS(this)
	HX_STACK_LINE(68)
	return this->gsMap;
}


HX_DEFINE_DYNAMIC_FUNC0(GameSprite_obj,getMap,return )

Void GameSprite_obj::setInterval( Float cincr){
{
		HX_STACK_FRAME("tenblock.GameSprite","setInterval",0xb1ae1c2e,"tenblock.GameSprite.setInterval","tenblock/GameSprite.hx",73,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cincr,"cincr")
		HX_STACK_LINE(73)
		this->gsIncr = cincr;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameSprite_obj,setInterval,(void))

Void GameSprite_obj::setGoodCodes( ::String cgood){
{
		HX_STACK_FRAME("tenblock.GameSprite","setGoodCodes",0x0f3ffd20,"tenblock.GameSprite.setGoodCodes","tenblock/GameSprite.hx",78,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cgood,"cgood")
		HX_STACK_LINE(78)
		this->gsGoodCodes = cgood;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameSprite_obj,setGoodCodes,(void))

Void GameSprite_obj::drawAt( int cx,int cy){
{
		HX_STACK_FRAME("tenblock.GameSprite","drawAt",0x73e22650,"tenblock.GameSprite.drawAt","tenblock/GameSprite.hx",82,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cx,"cx")
		HX_STACK_ARG(cy,"cy")
		HX_STACK_LINE(83)
		this->gsCanvas->addChild(hx::ObjectPtr<OBJ_>(this));
		HX_STACK_LINE(84)
		this->set_x(cx);
		HX_STACK_LINE(85)
		this->set_y(cy);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(GameSprite_obj,drawAt,(void))

Void GameSprite_obj::moveTo( int cx,int cy){
{
		HX_STACK_FRAME("tenblock.GameSprite","moveTo",0x60b88b25,"tenblock.GameSprite.moveTo","tenblock/GameSprite.hx",89,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cx,"cx")
		HX_STACK_ARG(cy,"cy")
		HX_STACK_LINE(90)
		this->set_x(cx);
		HX_STACK_LINE(91)
		this->set_y(cy);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(GameSprite_obj,moveTo,(void))

Void GameSprite_obj::setMid( int cmidx,int cmidy){
{
		HX_STACK_FRAME("tenblock.GameSprite","setMid",0x0376573f,"tenblock.GameSprite.setMid","tenblock/GameSprite.hx",95,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cmidx,"cmidx")
		HX_STACK_ARG(cmidy,"cmidy")
		HX_STACK_LINE(96)
		int _g = ::Std_obj::_int((cmidx - (Float(this->csWd) / Float((int)2))));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(96)
		this->set_x(_g);
		HX_STACK_LINE(97)
		int _g1 = ::Std_obj::_int((cmidy - (Float(this->csHt) / Float((int)2))));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(97)
		this->set_y(_g1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(GameSprite_obj,setMid,(void))

int GameSprite_obj::getX( ){
	HX_STACK_FRAME("tenblock.GameSprite","getX",0x04a10afb,"tenblock.GameSprite.getX","tenblock/GameSprite.hx",101,0x04989628)
	HX_STACK_THIS(this)
	HX_STACK_LINE(102)
	Float _g = this->get_x();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(102)
	return ::Std_obj::_int(_g);
}


HX_DEFINE_DYNAMIC_FUNC0(GameSprite_obj,getX,return )

int GameSprite_obj::getY( ){
	HX_STACK_FRAME("tenblock.GameSprite","getY",0x04a10afc,"tenblock.GameSprite.getY","tenblock/GameSprite.hx",106,0x04989628)
	HX_STACK_THIS(this)
	HX_STACK_LINE(107)
	Float _g = this->get_y();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(107)
	return ::Std_obj::_int(_g);
}


HX_DEFINE_DYNAMIC_FUNC0(GameSprite_obj,getY,return )

int GameSprite_obj::getMidX( ){
	HX_STACK_FRAME("tenblock.GameSprite","getMidX",0x11146f2d,"tenblock.GameSprite.getMidX","tenblock/GameSprite.hx",111,0x04989628)
	HX_STACK_THIS(this)
	HX_STACK_LINE(112)
	Float _g = this->get_x();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(112)
	int _g1 = ::Std_obj::_int((Float(this->csWd) / Float((int)2)));		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(112)
	Float _g2 = (_g + _g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(112)
	return ::Std_obj::_int(_g2);
}


HX_DEFINE_DYNAMIC_FUNC0(GameSprite_obj,getMidX,return )

int GameSprite_obj::getMidY( ){
	HX_STACK_FRAME("tenblock.GameSprite","getMidY",0x11146f2e,"tenblock.GameSprite.getMidY","tenblock/GameSprite.hx",116,0x04989628)
	HX_STACK_THIS(this)
	HX_STACK_LINE(117)
	Float _g = this->get_y();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(117)
	Float _g1 = (_g + (Float(this->csHt) / Float((int)2)));		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(117)
	return ::Std_obj::_int(_g1);
}


HX_DEFINE_DYNAMIC_FUNC0(GameSprite_obj,getMidY,return )

Void GameSprite_obj::setTileWidth( int cwidth){
{
		HX_STACK_FRAME("tenblock.GameSprite","setTileWidth",0xd7fafcef,"tenblock.GameSprite.setTileWidth","tenblock/GameSprite.hx",122,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cwidth,"cwidth")
		HX_STACK_LINE(122)
		this->gsTileWidth = cwidth;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameSprite_obj,setTileWidth,(void))

int GameSprite_obj::getXSq( ){
	HX_STACK_FRAME("tenblock.GameSprite","getXSq",0x37364879,"tenblock.GameSprite.getXSq","tenblock/GameSprite.hx",126,0x04989628)
	HX_STACK_THIS(this)
	HX_STACK_LINE(127)
	Float _g = this->get_x();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(127)
	Float _g1 = (Float(_g) / Float(this->gsTileWidth));		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(127)
	return ::Std_obj::_int(_g1);
}


HX_DEFINE_DYNAMIC_FUNC0(GameSprite_obj,getXSq,return )

int GameSprite_obj::getYSq( ){
	HX_STACK_FRAME("tenblock.GameSprite","getYSq",0x37370aba,"tenblock.GameSprite.getYSq","tenblock/GameSprite.hx",131,0x04989628)
	HX_STACK_THIS(this)
	HX_STACK_LINE(132)
	Float _g = this->get_y();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(132)
	Float _g1 = (Float(_g) / Float(this->gsTileWidth));		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(132)
	return ::Std_obj::_int(_g1);
}


HX_DEFINE_DYNAMIC_FUNC0(GameSprite_obj,getYSq,return )

int GameSprite_obj::getFeetY( ){
	HX_STACK_FRAME("tenblock.GameSprite","getFeetY",0xd65ac92e,"tenblock.GameSprite.getFeetY","tenblock/GameSprite.hx",136,0x04989628)
	HX_STACK_THIS(this)
	HX_STACK_LINE(137)
	Float _g = this->get_y();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(137)
	Float _g1 = (_g + this->csHt);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(137)
	return ::Std_obj::_int(_g1);
}


HX_DEFINE_DYNAMIC_FUNC0(GameSprite_obj,getFeetY,return )

Void GameSprite_obj::setMidX( int cmidx){
{
		HX_STACK_FRAME("tenblock.GameSprite","setMidX",0x04160039,"tenblock.GameSprite.setMidX","tenblock/GameSprite.hx",141,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cmidx,"cmidx")
		HX_STACK_LINE(142)
		int _g = ::Std_obj::_int((cmidx - (Float(this->csWd) / Float((int)2))));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(142)
		this->set_x(_g);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameSprite_obj,setMidX,(void))

Void GameSprite_obj::setMidY( int cmidy){
{
		HX_STACK_FRAME("tenblock.GameSprite","setMidY",0x0416003a,"tenblock.GameSprite.setMidY","tenblock/GameSprite.hx",146,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cmidy,"cmidy")
		HX_STACK_LINE(147)
		int _g = ::Std_obj::_int((cmidy - (Float(this->csHt) / Float((int)2))));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(147)
		this->set_y(_g);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameSprite_obj,setMidY,(void))

Void GameSprite_obj::setFeetY( int cmidy){
{
		HX_STACK_FRAME("tenblock.GameSprite","setFeetY",0x84b822a2,"tenblock.GameSprite.setFeetY","tenblock/GameSprite.hx",151,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cmidy,"cmidy")
		HX_STACK_LINE(152)
		int _g = ::Std_obj::_int((cmidy - this->csHt));		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(152)
		this->set_y(_g);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameSprite_obj,setFeetY,(void))

Void GameSprite_obj::dropOnSq( int csqx,int csqy){
{
		HX_STACK_FRAME("tenblock.GameSprite","dropOnSq",0x67e20fe5,"tenblock.GameSprite.dropOnSq","tenblock/GameSprite.hx",156,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_ARG(csqx,"csqx")
		HX_STACK_ARG(csqy,"csqy")
		HX_STACK_LINE(157)
		int _g = this->gsMap->getMidSqX(csqx);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(157)
		int cx = (_g - ((int)32 * (hx::Mod(csqy,(int)2))));		HX_STACK_VAR(cx,"cx");
		HX_STACK_LINE(158)
		int cy = this->gsMap->getMidSqY(csqy);		HX_STACK_VAR(cy,"cy");
		HX_STACK_LINE(160)
		this->setMid(cx,cy);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(GameSprite_obj,dropOnSq,(void))

Void GameSprite_obj::setTarget( int ctx,int cty){
{
		HX_STACK_FRAME("tenblock.GameSprite","setTarget",0xf058d9fa,"tenblock.GameSprite.setTarget","tenblock/GameSprite.hx",164,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_ARG(ctx,"ctx")
		HX_STACK_ARG(cty,"cty")
		HX_STACK_LINE(165)
		this->gsTargetX = ctx;
		HX_STACK_LINE(166)
		this->gsTargetY = cty;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(GameSprite_obj,setTarget,(void))

int GameSprite_obj::getTargetX( ){
	HX_STACK_FRAME("tenblock.GameSprite","getTargetX",0x59e842aa,"tenblock.GameSprite.getTargetX","tenblock/GameSprite.hx",171,0x04989628)
	HX_STACK_THIS(this)
	HX_STACK_LINE(171)
	return this->gsTargetX;
}


HX_DEFINE_DYNAMIC_FUNC0(GameSprite_obj,getTargetX,return )

int GameSprite_obj::getTargetY( ){
	HX_STACK_FRAME("tenblock.GameSprite","getTargetY",0x59e842ab,"tenblock.GameSprite.getTargetY","tenblock/GameSprite.hx",176,0x04989628)
	HX_STACK_THIS(this)
	HX_STACK_LINE(176)
	return this->gsTargetY;
}


HX_DEFINE_DYNAMIC_FUNC0(GameSprite_obj,getTargetY,return )

::String GameSprite_obj::getName( ){
	HX_STACK_FRAME("tenblock.GameSprite","getName",0x11b79ba8,"tenblock.GameSprite.getName","tenblock/GameSprite.hx",181,0x04989628)
	HX_STACK_THIS(this)
	HX_STACK_LINE(181)
	return this->gsName;
}


HX_DEFINE_DYNAMIC_FUNC0(GameSprite_obj,getName,return )

::String GameSprite_obj::getType( ){
	HX_STACK_FRAME("tenblock.GameSprite","getType",0x15c11c17,"tenblock.GameSprite.getType","tenblock/GameSprite.hx",186,0x04989628)
	HX_STACK_THIS(this)
	HX_STACK_LINE(186)
	return this->gsType;
}


HX_DEFINE_DYNAMIC_FUNC0(GameSprite_obj,getType,return )

int GameSprite_obj::getDistance( int cx1,int cy1,int cx2,int cy2){
	HX_STACK_FRAME("tenblock.GameSprite","getDistance",0xeabe2f12,"tenblock.GameSprite.getDistance","tenblock/GameSprite.hx",190,0x04989628)
	HX_STACK_THIS(this)
	HX_STACK_ARG(cx1,"cx1")
	HX_STACK_ARG(cy1,"cy1")
	HX_STACK_ARG(cx2,"cx2")
	HX_STACK_ARG(cy2,"cy2")
	HX_STACK_LINE(191)
	Float _g = ::Math_obj::pow((cx2 - cx1),(int)2);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(191)
	Float _g1 = ::Math_obj::pow((cy2 - cy1),(int)2);		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(191)
	Float _g2 = (_g + _g1);		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(191)
	Float _g3 = ::Math_obj::sqrt(_g2);		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(191)
	return ::Std_obj::_int(_g3);
}


HX_DEFINE_DYNAMIC_FUNC4(GameSprite_obj,getDistance,return )

int GameSprite_obj::getDistFrom( ::tenblock::GameSprite cSpr){
	HX_STACK_FRAME("tenblock.GameSprite","getDistFrom",0xd8e87fcd,"tenblock.GameSprite.getDistFrom","tenblock/GameSprite.hx",195,0x04989628)
	HX_STACK_THIS(this)
	HX_STACK_ARG(cSpr,"cSpr")
	HX_STACK_LINE(196)
	int _g = this->getMidX();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(196)
	int _g1 = this->getMidY();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(196)
	int _g2 = cSpr->getMidX();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(196)
	int _g3 = cSpr->getMidY();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(196)
	return this->getDistance(_g,_g1,_g2,_g3);
}


HX_DEFINE_DYNAMIC_FUNC1(GameSprite_obj,getDistFrom,return )

Void GameSprite_obj::doSequence( Array< ::String > cSeq){
{
		HX_STACK_FRAME("tenblock.GameSprite","doSequence",0xd880fda5,"tenblock.GameSprite.doSequence","tenblock/GameSprite.hx",200,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cSeq,"cSeq")
		HX_STACK_LINE(201)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(203)
		{
			HX_STACK_LINE(203)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(203)
			int _g = cSeq->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(203)
			while((true)){
				HX_STACK_LINE(203)
				if ((!(((_g1 < _g))))){
					HX_STACK_LINE(203)
					break;
				}
				HX_STACK_LINE(203)
				int i1 = (_g1)++;		HX_STACK_VAR(i1,"i1");
				HX_STACK_LINE(204)
				this->gsSeq[i1] = ::Std_obj::parseInt(cSeq->__get(i1));
			}
		}
		HX_STACK_LINE(206)
		int _g = this->getXSq();		HX_STACK_VAR(_g,"_g");
		struct _Function_1_1{
			inline static bool Block( hx::ObjectPtr< ::tenblock::GameSprite_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","tenblock/GameSprite.hx",206,0x04989628)
				{
					HX_STACK_LINE(206)
					int _g1 = __this->getYSq();		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(206)
					return (_g1 == __this->gsSeq->__get((__this->gsFlag + (int)1)));
				}
				return null();
			}
		};
		HX_STACK_LINE(206)
		if (((  (((_g == this->gsSeq->__get(this->gsFlag)))) ? bool(_Function_1_1::Block(this)) : bool(false) ))){
			HX_STACK_LINE(208)
			this->gsFlag = (this->gsFlag + (int)2);
			HX_STACK_LINE(209)
			if (((this->gsFlag >= this->gsSeq->length))){
				HX_STACK_LINE(210)
				this->gsFlag = (int)0;
			}
		}
		HX_STACK_LINE(213)
		int _g2 = ::Std_obj::_int((Float(this->gsTileWidth) / Float((int)2)));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(213)
		int _g3 = ((this->gsSeq->__get(this->gsFlag) * this->gsTileWidth) + _g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(213)
		int _g4 = ::Std_obj::_int((Float(this->gsTileWidth) / Float((int)2)));		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(213)
		int _g5 = ((this->gsSeq->__get((this->gsFlag + (int)1)) * this->gsTileWidth) + _g4);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(213)
		this->setTarget(_g3,_g5);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameSprite_obj,doSequence,(void))

Void GameSprite_obj::doMovement( ){
{
		HX_STACK_FRAME("tenblock.GameSprite","doMovement",0xefcb6493,"tenblock.GameSprite.doMovement","tenblock/GameSprite.hx",218,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_LINE(218)
		if (((this->gsType == HX_CSTRING("spider")))){
			HX_STACK_LINE(220)
			this->doMoveTarget(true);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameSprite_obj,doMovement,(void))

Void GameSprite_obj::doMoveTarget( bool reverse){
{
		HX_STACK_FRAME("tenblock.GameSprite","doMoveTarget",0xbaf0eda6,"tenblock.GameSprite.doMoveTarget","tenblock/GameSprite.hx",225,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_ARG(reverse,"reverse")
		HX_STACK_LINE(226)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(227)
		int j;		HX_STACK_VAR(j,"j");
		HX_STACK_LINE(229)
		int tx;		HX_STACK_VAR(tx,"tx");
		HX_STACK_LINE(230)
		int ty;		HX_STACK_VAR(ty,"ty");
		HX_STACK_LINE(231)
		int cx;		HX_STACK_VAR(cx,"cx");
		HX_STACK_LINE(232)
		int cy;		HX_STACK_VAR(cy,"cy");
		HX_STACK_LINE(233)
		int cmidy;		HX_STACK_VAR(cmidy,"cmidy");
		HX_STACK_LINE(234)
		int mx;		HX_STACK_VAR(mx,"mx");
		HX_STACK_LINE(235)
		int my;		HX_STACK_VAR(my,"my");
		HX_STACK_LINE(236)
		int cdir;		HX_STACK_VAR(cdir,"cdir");
		HX_STACK_LINE(238)
		int idir;		HX_STACK_VAR(idir,"idir");
		HX_STACK_LINE(239)
		int imult;		HX_STACK_VAR(imult,"imult");
		HX_STACK_LINE(243)
		tx = this->gsTargetX;
		HX_STACK_LINE(244)
		ty = this->gsTargetY;
		HX_STACK_LINE(246)
		int _g = this->getMidX();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(246)
		cx = _g;
		HX_STACK_LINE(247)
		int _g1 = this->getFeetY();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(247)
		cy = _g1;
		HX_STACK_LINE(248)
		int _g2 = this->getMidY();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(248)
		cmidy = _g2;
		HX_STACK_LINE(249)
		int _g3 = this->getDir();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(249)
		cdir = _g3;
		HX_STACK_LINE(251)
		int _g4 = this->gsMap->getSqX(cx);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(251)
		mx = _g4;
		HX_STACK_LINE(252)
		int _g5 = this->gsMap->getSqY(cy);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(252)
		my = _g5;
		HX_STACK_LINE(255)
		if (((bool((bool((mx == this->gsMoveSqX)) && bool((my == this->gsMoveSqY)))) && bool((cdir != (int)0))))){
			HX_STACK_LINE(256)
			return null();
		}
		else{
			HX_STACK_LINE(257)
			int _g6 = this->gsMap->getMidSqX(mx);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(257)
			int _g7 = this->gsMap->getMidSqY(my);		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(257)
			int _g8 = this->getDistance(cx,cy,_g6,_g7);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(257)
			if (((_g8 > (int)10))){
				HX_STACK_LINE(258)
				return null();
			}
			else{
				HX_STACK_LINE(261)
				this->gsMoveSqX = mx;
				HX_STACK_LINE(262)
				this->gsMoveSqY = my;
				HX_STACK_LINE(264)
				idir = (int)0;
				HX_STACK_LINE(265)
				imult = (int)1000000;
				HX_STACK_LINE(266)
				i = (int)0;
				HX_STACK_LINE(267)
				j = (int)1000000;
				HX_STACK_LINE(269)
				while((true)){
					HX_STACK_LINE(269)
					if ((!(((i < (int)4))))){
						HX_STACK_LINE(269)
						break;
					}
					struct _Function_4_1{
						inline static bool Block( hx::ObjectPtr< ::tenblock::GameSprite_obj > __this,int &my,int &mx){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","tenblock/GameSprite.hx",271,0x04989628)
							{
								HX_STACK_LINE(271)
								::String _g9 = __this->gsMap->getCode((mx + (int)1),my);		HX_STACK_VAR(_g9,"_g9");
								HX_STACK_LINE(271)
								return __this->isGood(_g9);
							}
							return null();
						}
					};
					HX_STACK_LINE(271)
					if (((  (((bool((i == (int)0)) && bool(((bool((cdir != (int)2)) || bool((reverse == true)))))))) ? bool(_Function_4_1::Block(this,my,mx)) : bool(false) ))){
						HX_STACK_LINE(272)
						int _g10 = this->getDistance((cx + (int)20),cy,tx,ty);		HX_STACK_VAR(_g10,"_g10");
						HX_STACK_LINE(272)
						j = _g10;
					}
					else{
						struct _Function_5_1{
							inline static bool Block( hx::ObjectPtr< ::tenblock::GameSprite_obj > __this,int &my,int &mx){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","tenblock/GameSprite.hx",273,0x04989628)
								{
									HX_STACK_LINE(273)
									::String _g11 = __this->gsMap->getCode(mx,(my + (int)1));		HX_STACK_VAR(_g11,"_g11");
									HX_STACK_LINE(273)
									return __this->isGood(_g11);
								}
								return null();
							}
						};
						HX_STACK_LINE(273)
						if (((  (((bool((i == (int)1)) && bool(((bool((cdir != (int)3)) || bool((reverse == true)))))))) ? bool(_Function_5_1::Block(this,my,mx)) : bool(false) ))){
							HX_STACK_LINE(274)
							int _g12 = this->getDistance(cx,(cy + (int)20),tx,ty);		HX_STACK_VAR(_g12,"_g12");
							HX_STACK_LINE(274)
							j = _g12;
						}
						else{
							struct _Function_6_1{
								inline static bool Block( hx::ObjectPtr< ::tenblock::GameSprite_obj > __this,int &my,int &mx){
									HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","tenblock/GameSprite.hx",275,0x04989628)
									{
										HX_STACK_LINE(275)
										::String _g13 = __this->gsMap->getCode((mx - (int)1),my);		HX_STACK_VAR(_g13,"_g13");
										HX_STACK_LINE(275)
										return __this->isGood(_g13);
									}
									return null();
								}
							};
							HX_STACK_LINE(275)
							if (((  (((bool((i == (int)2)) && bool(((bool((cdir != (int)0)) || bool((reverse == true)))))))) ? bool(_Function_6_1::Block(this,my,mx)) : bool(false) ))){
								HX_STACK_LINE(276)
								int _g14 = this->getDistance((cx - (int)20),cy,tx,ty);		HX_STACK_VAR(_g14,"_g14");
								HX_STACK_LINE(276)
								j = _g14;
							}
							else{
								struct _Function_7_1{
									inline static bool Block( hx::ObjectPtr< ::tenblock::GameSprite_obj > __this,int &my,int &mx){
										HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","tenblock/GameSprite.hx",277,0x04989628)
										{
											HX_STACK_LINE(277)
											::String _g15 = __this->gsMap->getCode(mx,(my - (int)1));		HX_STACK_VAR(_g15,"_g15");
											HX_STACK_LINE(277)
											return __this->isGood(_g15);
										}
										return null();
									}
								};
								HX_STACK_LINE(277)
								if (((  (((bool((i == (int)3)) && bool(((bool((cdir != (int)1)) || bool((reverse == true)))))))) ? bool(_Function_7_1::Block(this,my,mx)) : bool(false) ))){
									HX_STACK_LINE(278)
									int _g16 = this->getDistance(cx,(cy - (int)20),tx,ty);		HX_STACK_VAR(_g16,"_g16");
									HX_STACK_LINE(278)
									j = _g16;
								}
							}
						}
					}
					HX_STACK_LINE(280)
					if (((j < imult))){
						HX_STACK_LINE(281)
						idir = i;
						HX_STACK_LINE(282)
						imult = j;
					}
					HX_STACK_LINE(285)
					(i)++;
				}
			}
		}
		HX_STACK_LINE(290)
		this->setDir(idir);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameSprite_obj,doMoveTarget,(void))

Void GameSprite_obj::correctSq( ){
{
		HX_STACK_FRAME("tenblock.GameSprite","correctSq",0xec7e910f,"tenblock.GameSprite.correctSq","tenblock/GameSprite.hx",294,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_LINE(295)
		int cx;		HX_STACK_VAR(cx,"cx");
		HX_STACK_LINE(296)
		int cy;		HX_STACK_VAR(cy,"cy");
		HX_STACK_LINE(297)
		int mx;		HX_STACK_VAR(mx,"mx");
		HX_STACK_LINE(298)
		int my;		HX_STACK_VAR(my,"my");
		HX_STACK_LINE(300)
		int _g = this->getMidX();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(300)
		cx = _g;
		HX_STACK_LINE(301)
		int _g1 = this->getFeetY();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(301)
		cy = _g1;
		HX_STACK_LINE(302)
		int _g2 = this->gsMap->getSqX(cx);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(302)
		mx = _g2;
		HX_STACK_LINE(303)
		int _g3 = this->gsMap->getSqY(cy);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(303)
		my = _g3;
		HX_STACK_LINE(305)
		int _g4 = this->gsMap->getMidSqX(mx);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(305)
		this->setMidX(_g4);
		HX_STACK_LINE(306)
		int _g5 = this->gsMap->getMidSqY(my);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(306)
		this->setFeetY(_g5);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameSprite_obj,correctSq,(void))

Void GameSprite_obj::doAnimate( int cinterval){
{
		HX_STACK_FRAME("tenblock.GameSprite","doAnimate",0x848ef3bd,"tenblock.GameSprite.doAnimate","tenblock/GameSprite.hx",311,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cinterval,"cinterval")
		HX_STACK_LINE(311)
		if (((this->runFlag == (int)0))){
			HX_STACK_LINE(312)
			::haxe::Timer _g = ::haxe::Timer_obj::__new(cinterval);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(312)
			this->doAnim = _g;
			HX_STACK_LINE(313)
			this->doAnim->run = this->doFrames_dyn();
			HX_STACK_LINE(314)
			this->runFlag = (int)1;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameSprite_obj,doAnimate,(void))

Void GameSprite_obj::doNextFrame( ){
{
		HX_STACK_FRAME("tenblock.GameSprite","doNextFrame",0x5f982a56,"tenblock.GameSprite.doNextFrame","tenblock/GameSprite.hx",320,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_LINE(320)
		this->doFrames();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameSprite_obj,doNextFrame,(void))

Void GameSprite_obj::doNextMove( ){
{
		HX_STACK_FRAME("tenblock.GameSprite","doNextMove",0xe3c16908,"tenblock.GameSprite.doNextMove","tenblock/GameSprite.hx",324,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_LINE(325)
		int _g = this->getDir();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(325)
		if (((_g == (int)0))){
			HX_STACK_LINE(327)
			::tenblock::GameSprite _g1 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(327)
			Float _g11 = _g1->get_x();		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(327)
			int _g2 = this->getSpeed();		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(327)
			Float _g3 = (_g11 + _g2);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(327)
			_g1->set_x(_g3);
		}
		else{
			HX_STACK_LINE(329)
			int _g4 = this->getDir();		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(329)
			if (((_g4 == (int)1))){
				HX_STACK_LINE(331)
				::tenblock::GameSprite _g1 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(331)
				Float _g5 = _g1->get_y();		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(331)
				int _g6 = this->getSpeed();		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(331)
				Float _g7 = (_g5 + _g6);		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(331)
				_g1->set_y(_g7);
			}
			else{
				HX_STACK_LINE(333)
				int _g8 = this->getDir();		HX_STACK_VAR(_g8,"_g8");
				HX_STACK_LINE(333)
				if (((_g8 == (int)2))){
					HX_STACK_LINE(335)
					::tenblock::GameSprite _g1 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(335)
					Float _g9 = _g1->get_x();		HX_STACK_VAR(_g9,"_g9");
					HX_STACK_LINE(335)
					int _g10 = this->getSpeed();		HX_STACK_VAR(_g10,"_g10");
					HX_STACK_LINE(335)
					Float _g11 = (_g9 - _g10);		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(335)
					_g1->set_x(_g11);
				}
				else{
					HX_STACK_LINE(337)
					int _g12 = this->getDir();		HX_STACK_VAR(_g12,"_g12");
					HX_STACK_LINE(337)
					if (((_g12 == (int)3))){
						HX_STACK_LINE(339)
						::tenblock::GameSprite _g1 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(339)
						Float _g13 = _g1->get_y();		HX_STACK_VAR(_g13,"_g13");
						HX_STACK_LINE(339)
						int _g14 = this->getSpeed();		HX_STACK_VAR(_g14,"_g14");
						HX_STACK_LINE(339)
						Float _g15 = (_g13 - _g14);		HX_STACK_VAR(_g15,"_g15");
						HX_STACK_LINE(339)
						_g1->set_y(_g15);
					}
				}
			}
		}
		HX_STACK_LINE(342)
		this->doNextFrame();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameSprite_obj,doNextMove,(void))

Void GameSprite_obj::doCheckMove( ){
{
		HX_STACK_FRAME("tenblock.GameSprite","doCheckMove",0x4e104415,"tenblock.GameSprite.doCheckMove","tenblock/GameSprite.hx",346,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_LINE(347)
		::String ccode1;		HX_STACK_VAR(ccode1,"ccode1");
		HX_STACK_LINE(348)
		::String ccode2;		HX_STACK_VAR(ccode2,"ccode2");
		HX_STACK_LINE(350)
		int _g = this->getDir();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(350)
		::String _g1 = this->getMoveCode1(_g,true);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(350)
		ccode1 = _g1;
		HX_STACK_LINE(351)
		int _g2 = this->getDir();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(351)
		::String _g3 = this->getMoveCode2(_g2,true);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(351)
		ccode2 = _g3;
		HX_STACK_LINE(353)
		if (((  ((this->isGood(ccode1))) ? bool(this->isGood(ccode2)) : bool(false) ))){
			HX_STACK_LINE(355)
			this->doNextMove();
		}
		else{
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameSprite_obj,doCheckMove,(void))

bool GameSprite_obj::isGood( ::String ccode){
	HX_STACK_FRAME("tenblock.GameSprite","isGood",0xf5dc1280,"tenblock.GameSprite.isGood","tenblock/GameSprite.hx",364,0x04989628)
	HX_STACK_THIS(this)
	HX_STACK_ARG(ccode,"ccode")
	HX_STACK_LINE(365)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(367)
	::String _g = this->gsMap->getType(ccode);		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(367)
	int _g1 = this->gsGoodCodes.indexOf(_g,null());		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(367)
	if (((_g1 != (int)-1))){
		HX_STACK_LINE(368)
		return true;
	}
	else{
		HX_STACK_LINE(370)
		return false;
	}
	HX_STACK_LINE(372)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC1(GameSprite_obj,isGood,return )

::String GameSprite_obj::getMoveCode1( int cdir,bool inSq){
	HX_STACK_FRAME("tenblock.GameSprite","getMoveCode1",0x7560eb16,"tenblock.GameSprite.getMoveCode1","tenblock/GameSprite.hx",376,0x04989628)
	HX_STACK_THIS(this)
	HX_STACK_ARG(cdir,"cdir")
	HX_STACK_ARG(inSq,"inSq")
	HX_STACK_LINE(377)
	int _g = this->getMidX();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(377)
	int _g1 = ::Std_obj::_int((Float(this->csWd) / Float((int)2)));		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(377)
	int cx = (_g - _g1);		HX_STACK_VAR(cx,"cx");
	HX_STACK_LINE(378)
	int cy = this->getFeetY();		HX_STACK_VAR(cy,"cy");
	HX_STACK_LINE(379)
	int spd = this->getSpeed();		HX_STACK_VAR(spd,"spd");
	HX_STACK_LINE(381)
	int mx = this->gsMap->getSqX(cx);		HX_STACK_VAR(mx,"mx");
	HX_STACK_LINE(382)
	int my = this->gsMap->getSqY(cy);		HX_STACK_VAR(my,"my");
	HX_STACK_LINE(383)
	int midx = this->gsMap->getMidSqX(mx);		HX_STACK_VAR(midx,"midx");
	HX_STACK_LINE(384)
	int midy = this->gsMap->getMidSqY(my);		HX_STACK_VAR(midy,"midy");
	HX_STACK_LINE(386)
	::String ccode = HX_CSTRING("");		HX_STACK_VAR(ccode,"ccode");
	HX_STACK_LINE(388)
	if (((cdir == (int)0))){
		HX_STACK_LINE(390)
		if (((bool((((cx + spd) + (Float(this->csWd) / Float((int)2))) > (midx + (int)32))) || bool((inSq == false))))){
			HX_STACK_LINE(391)
			::String _g2 = this->gsMap->getCode((mx + (int)1),my);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(391)
			ccode = _g2;
		}
		else{
			HX_STACK_LINE(393)
			::String _g3 = this->gsMap->getCode(mx,my);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(393)
			ccode = _g3;
		}
	}
	else{
		HX_STACK_LINE(395)
		if (((cdir == (int)1))){
			HX_STACK_LINE(397)
			int _g4 = this->gsMap->getTileWidth();		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(397)
			Float _g5 = (Float(_g4) / Float((int)2));		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(397)
			Float _g6 = (midy + _g5);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(397)
			int _g7 = this->gsMap->getTileWidth();		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(397)
			Float _g8 = (_g7 * 0.1);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(397)
			Float _g9 = (_g6 - _g8);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(397)
			if (((  ((!((((cy + spd) > _g9))))) ? bool((inSq == false)) : bool(true) ))){
				HX_STACK_LINE(398)
				::String _g10 = this->gsMap->getCode(mx,(my + (int)1));		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(398)
				ccode = _g10;
			}
			else{
				HX_STACK_LINE(400)
				::String _g11 = this->gsMap->getCode(mx,my);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(400)
				ccode = _g11;
			}
		}
		else{
			HX_STACK_LINE(402)
			if (((cdir == (int)2))){
				HX_STACK_LINE(404)
				if (((bool(((cx - spd) < midx)) || bool((inSq == false))))){
					HX_STACK_LINE(405)
					::String _g12 = this->gsMap->getCode((mx - (int)1),my);		HX_STACK_VAR(_g12,"_g12");
					HX_STACK_LINE(405)
					ccode = _g12;
				}
				else{
					HX_STACK_LINE(407)
					::String _g13 = this->gsMap->getCode(mx,my);		HX_STACK_VAR(_g13,"_g13");
					HX_STACK_LINE(407)
					ccode = _g13;
				}
			}
			else{
				HX_STACK_LINE(409)
				if (((cdir == (int)3))){
					HX_STACK_LINE(411)
					int _g14 = this->gsMap->getTileWidth();		HX_STACK_VAR(_g14,"_g14");
					HX_STACK_LINE(411)
					Float _g15 = (Float(_g14) / Float((int)2));		HX_STACK_VAR(_g15,"_g15");
					HX_STACK_LINE(411)
					Float _g16 = (midy - _g15);		HX_STACK_VAR(_g16,"_g16");
					HX_STACK_LINE(411)
					int _g17 = this->gsMap->getTileWidth();		HX_STACK_VAR(_g17,"_g17");
					HX_STACK_LINE(411)
					Float _g18 = (_g17 * 0.25);		HX_STACK_VAR(_g18,"_g18");
					HX_STACK_LINE(411)
					Float _g19 = (_g16 + _g18);		HX_STACK_VAR(_g19,"_g19");
					HX_STACK_LINE(411)
					if (((  ((!((((cy - spd) < _g19))))) ? bool((inSq == false)) : bool(true) ))){
						HX_STACK_LINE(412)
						::String _g20 = this->gsMap->getCode(mx,(my - (int)1));		HX_STACK_VAR(_g20,"_g20");
						HX_STACK_LINE(412)
						ccode = _g20;
					}
					else{
						HX_STACK_LINE(414)
						::String _g21 = this->gsMap->getCode(mx,my);		HX_STACK_VAR(_g21,"_g21");
						HX_STACK_LINE(414)
						ccode = _g21;
					}
				}
			}
		}
	}
	HX_STACK_LINE(417)
	return ccode;
}


HX_DEFINE_DYNAMIC_FUNC2(GameSprite_obj,getMoveCode1,return )

::String GameSprite_obj::getMoveCode2( int cdir,bool inSq){
	HX_STACK_FRAME("tenblock.GameSprite","getMoveCode2",0x7560eb17,"tenblock.GameSprite.getMoveCode2","tenblock/GameSprite.hx",421,0x04989628)
	HX_STACK_THIS(this)
	HX_STACK_ARG(cdir,"cdir")
	HX_STACK_ARG(inSq,"inSq")
	HX_STACK_LINE(422)
	int _g = this->getMidX();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(422)
	int _g1 = ::Std_obj::_int((Float(this->csWd) / Float((int)2)));		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(422)
	int cx = (_g + _g1);		HX_STACK_VAR(cx,"cx");
	HX_STACK_LINE(423)
	int cy = this->getFeetY();		HX_STACK_VAR(cy,"cy");
	HX_STACK_LINE(424)
	int spd = this->getSpeed();		HX_STACK_VAR(spd,"spd");
	HX_STACK_LINE(426)
	int mx = this->gsMap->getSqX(cx);		HX_STACK_VAR(mx,"mx");
	HX_STACK_LINE(427)
	int my = this->gsMap->getSqY(cy);		HX_STACK_VAR(my,"my");
	HX_STACK_LINE(428)
	int midx = this->gsMap->getMidSqX(mx);		HX_STACK_VAR(midx,"midx");
	HX_STACK_LINE(429)
	int midy = this->gsMap->getMidSqY(my);		HX_STACK_VAR(midy,"midy");
	HX_STACK_LINE(431)
	::String ccode = HX_CSTRING("");		HX_STACK_VAR(ccode,"ccode");
	HX_STACK_LINE(433)
	if (((cdir == (int)0))){
		HX_STACK_LINE(435)
		if (((bool((((cx + spd) + (Float(this->csWd) / Float((int)2))) > (midx + (int)32))) || bool((inSq == false))))){
			HX_STACK_LINE(436)
			::String _g2 = this->gsMap->getCode((mx + (int)1),my);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(436)
			ccode = _g2;
		}
		else{
			HX_STACK_LINE(438)
			::String _g3 = this->gsMap->getCode(mx,my);		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(438)
			ccode = _g3;
		}
	}
	else{
		HX_STACK_LINE(440)
		if (((cdir == (int)1))){
			HX_STACK_LINE(442)
			int _g4 = this->gsMap->getTileWidth();		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(442)
			Float _g5 = (Float(_g4) / Float((int)2));		HX_STACK_VAR(_g5,"_g5");
			HX_STACK_LINE(442)
			Float _g6 = (midy + _g5);		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(442)
			int _g7 = this->gsMap->getTileWidth();		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(442)
			Float _g8 = (_g7 * 0.1);		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(442)
			Float _g9 = (_g6 - _g8);		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(442)
			if (((  ((!((((cy + spd) > _g9))))) ? bool((inSq == false)) : bool(true) ))){
				HX_STACK_LINE(443)
				::String _g10 = this->gsMap->getCode(mx,(my + (int)1));		HX_STACK_VAR(_g10,"_g10");
				HX_STACK_LINE(443)
				ccode = _g10;
			}
			else{
				HX_STACK_LINE(445)
				::String _g11 = this->gsMap->getCode(mx,my);		HX_STACK_VAR(_g11,"_g11");
				HX_STACK_LINE(445)
				ccode = _g11;
			}
		}
		else{
			HX_STACK_LINE(447)
			if (((cdir == (int)2))){
				HX_STACK_LINE(449)
				if (((bool(((cx - spd) < midx)) || bool((inSq == false))))){
					HX_STACK_LINE(450)
					::String _g12 = this->gsMap->getCode((mx - (int)1),my);		HX_STACK_VAR(_g12,"_g12");
					HX_STACK_LINE(450)
					ccode = _g12;
				}
				else{
					HX_STACK_LINE(452)
					::String _g13 = this->gsMap->getCode(mx,my);		HX_STACK_VAR(_g13,"_g13");
					HX_STACK_LINE(452)
					ccode = _g13;
				}
			}
			else{
				HX_STACK_LINE(454)
				if (((cdir == (int)3))){
					HX_STACK_LINE(456)
					int _g14 = this->gsMap->getTileWidth();		HX_STACK_VAR(_g14,"_g14");
					HX_STACK_LINE(456)
					Float _g15 = (Float(_g14) / Float((int)2));		HX_STACK_VAR(_g15,"_g15");
					HX_STACK_LINE(456)
					Float _g16 = (midy - _g15);		HX_STACK_VAR(_g16,"_g16");
					HX_STACK_LINE(456)
					int _g17 = this->gsMap->getTileWidth();		HX_STACK_VAR(_g17,"_g17");
					HX_STACK_LINE(456)
					Float _g18 = (_g17 * 0.25);		HX_STACK_VAR(_g18,"_g18");
					HX_STACK_LINE(456)
					Float _g19 = (_g16 + _g18);		HX_STACK_VAR(_g19,"_g19");
					HX_STACK_LINE(456)
					if (((  ((!((((cy - spd) < _g19))))) ? bool((inSq == false)) : bool(true) ))){
						HX_STACK_LINE(457)
						::String _g20 = this->gsMap->getCode(mx,(my - (int)1));		HX_STACK_VAR(_g20,"_g20");
						HX_STACK_LINE(457)
						ccode = _g20;
					}
					else{
						HX_STACK_LINE(459)
						::String _g21 = this->gsMap->getCode(mx,my);		HX_STACK_VAR(_g21,"_g21");
						HX_STACK_LINE(459)
						ccode = _g21;
					}
				}
			}
		}
	}
	HX_STACK_LINE(462)
	return ccode;
}


HX_DEFINE_DYNAMIC_FUNC2(GameSprite_obj,getMoveCode2,return )

Void GameSprite_obj::doStop( ){
{
		HX_STACK_FRAME("tenblock.GameSprite","doStop",0xb06b4d66,"tenblock.GameSprite.doStop","tenblock/GameSprite.hx",466,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_LINE(467)
		if (((this->runFlag == (int)1))){
			HX_STACK_LINE(467)
			this->doAnim->stop();
		}
		HX_STACK_LINE(468)
		this->runFlag = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameSprite_obj,doStop,(void))

Void GameSprite_obj::doStand( int cframe){
{
		HX_STACK_FRAME("tenblock.GameSprite","doStand",0xad6dcaf2,"tenblock.GameSprite.doStand","tenblock/GameSprite.hx",472,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cframe,"cframe")
		HX_STACK_LINE(473)
		if (((this->runFlag == (int)1))){
			HX_STACK_LINE(473)
			this->doAnim->stop();
		}
		HX_STACK_LINE(474)
		this->runFlag = (int)0;
		HX_STACK_LINE(475)
		this->setFrame(cframe);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameSprite_obj,doStand,(void))

Void GameSprite_obj::doFrames( ){
{
		HX_STACK_FRAME("tenblock.GameSprite","doFrames",0xb9322e0a,"tenblock.GameSprite.doFrames","tenblock/GameSprite.hx",479,0x04989628)
		HX_STACK_THIS(this)
		HX_STACK_LINE(480)
		this->gsFrame = (this->gsFrame + this->gsIncr);
		HX_STACK_LINE(481)
		int _g = this->getSheetWidth();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(481)
		int _g1 = (_g + (int)1);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(481)
		if (((this->gsFrame >= _g1))){
			HX_STACK_LINE(481)
			this->gsFrame = (int)0;
		}
		HX_STACK_LINE(482)
		int _g2 = ::Std_obj::_int(this->gsFrame);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(482)
		this->setFrame(_g2);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameSprite_obj,doFrames,(void))


GameSprite_obj::GameSprite_obj()
{
}

void GameSprite_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GameSprite);
	HX_MARK_MEMBER_NAME(gsName,"gsName");
	HX_MARK_MEMBER_NAME(gsType,"gsType");
	HX_MARK_MEMBER_NAME(gsCanvas,"gsCanvas");
	HX_MARK_MEMBER_NAME(doAnim,"doAnim");
	HX_MARK_MEMBER_NAME(gsFrame,"gsFrame");
	HX_MARK_MEMBER_NAME(runFlag,"runFlag");
	HX_MARK_MEMBER_NAME(gsIncr,"gsIncr");
	HX_MARK_MEMBER_NAME(gsTargetX,"gsTargetX");
	HX_MARK_MEMBER_NAME(gsTargetY,"gsTargetY");
	HX_MARK_MEMBER_NAME(gsMoveSqX,"gsMoveSqX");
	HX_MARK_MEMBER_NAME(gsMoveSqY,"gsMoveSqY");
	HX_MARK_MEMBER_NAME(gsMap,"gsMap");
	HX_MARK_MEMBER_NAME(gsGoodCodes,"gsGoodCodes");
	HX_MARK_MEMBER_NAME(gsSeq,"gsSeq");
	HX_MARK_MEMBER_NAME(gsFlag,"gsFlag");
	HX_MARK_MEMBER_NAME(gsTileWidth,"gsTileWidth");
	::tenblock::CharSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void GameSprite_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(gsName,"gsName");
	HX_VISIT_MEMBER_NAME(gsType,"gsType");
	HX_VISIT_MEMBER_NAME(gsCanvas,"gsCanvas");
	HX_VISIT_MEMBER_NAME(doAnim,"doAnim");
	HX_VISIT_MEMBER_NAME(gsFrame,"gsFrame");
	HX_VISIT_MEMBER_NAME(runFlag,"runFlag");
	HX_VISIT_MEMBER_NAME(gsIncr,"gsIncr");
	HX_VISIT_MEMBER_NAME(gsTargetX,"gsTargetX");
	HX_VISIT_MEMBER_NAME(gsTargetY,"gsTargetY");
	HX_VISIT_MEMBER_NAME(gsMoveSqX,"gsMoveSqX");
	HX_VISIT_MEMBER_NAME(gsMoveSqY,"gsMoveSqY");
	HX_VISIT_MEMBER_NAME(gsMap,"gsMap");
	HX_VISIT_MEMBER_NAME(gsGoodCodes,"gsGoodCodes");
	HX_VISIT_MEMBER_NAME(gsSeq,"gsSeq");
	HX_VISIT_MEMBER_NAME(gsFlag,"gsFlag");
	HX_VISIT_MEMBER_NAME(gsTileWidth,"gsTileWidth");
	::tenblock::CharSprite_obj::__Visit(HX_VISIT_ARG);
}

Dynamic GameSprite_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"getX") ) { return getX_dyn(); }
		if (HX_FIELD_EQ(inName,"getY") ) { return getY_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"gsMap") ) { return gsMap; }
		if (HX_FIELD_EQ(inName,"gsSeq") ) { return gsSeq; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"gsName") ) { return gsName; }
		if (HX_FIELD_EQ(inName,"gsType") ) { return gsType; }
		if (HX_FIELD_EQ(inName,"doAnim") ) { return doAnim; }
		if (HX_FIELD_EQ(inName,"gsIncr") ) { return gsIncr; }
		if (HX_FIELD_EQ(inName,"gsFlag") ) { return gsFlag; }
		if (HX_FIELD_EQ(inName,"setMap") ) { return setMap_dyn(); }
		if (HX_FIELD_EQ(inName,"getMap") ) { return getMap_dyn(); }
		if (HX_FIELD_EQ(inName,"drawAt") ) { return drawAt_dyn(); }
		if (HX_FIELD_EQ(inName,"moveTo") ) { return moveTo_dyn(); }
		if (HX_FIELD_EQ(inName,"setMid") ) { return setMid_dyn(); }
		if (HX_FIELD_EQ(inName,"getXSq") ) { return getXSq_dyn(); }
		if (HX_FIELD_EQ(inName,"getYSq") ) { return getYSq_dyn(); }
		if (HX_FIELD_EQ(inName,"isGood") ) { return isGood_dyn(); }
		if (HX_FIELD_EQ(inName,"doStop") ) { return doStop_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"gsFrame") ) { return gsFrame; }
		if (HX_FIELD_EQ(inName,"runFlag") ) { return runFlag; }
		if (HX_FIELD_EQ(inName,"getMidX") ) { return getMidX_dyn(); }
		if (HX_FIELD_EQ(inName,"getMidY") ) { return getMidY_dyn(); }
		if (HX_FIELD_EQ(inName,"setMidX") ) { return setMidX_dyn(); }
		if (HX_FIELD_EQ(inName,"setMidY") ) { return setMidY_dyn(); }
		if (HX_FIELD_EQ(inName,"getName") ) { return getName_dyn(); }
		if (HX_FIELD_EQ(inName,"getType") ) { return getType_dyn(); }
		if (HX_FIELD_EQ(inName,"doStand") ) { return doStand_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"gsCanvas") ) { return gsCanvas; }
		if (HX_FIELD_EQ(inName,"getFeetY") ) { return getFeetY_dyn(); }
		if (HX_FIELD_EQ(inName,"setFeetY") ) { return setFeetY_dyn(); }
		if (HX_FIELD_EQ(inName,"dropOnSq") ) { return dropOnSq_dyn(); }
		if (HX_FIELD_EQ(inName,"doFrames") ) { return doFrames_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"gsTargetX") ) { return gsTargetX; }
		if (HX_FIELD_EQ(inName,"gsTargetY") ) { return gsTargetY; }
		if (HX_FIELD_EQ(inName,"gsMoveSqX") ) { return gsMoveSqX; }
		if (HX_FIELD_EQ(inName,"gsMoveSqY") ) { return gsMoveSqY; }
		if (HX_FIELD_EQ(inName,"setCanvas") ) { return setCanvas_dyn(); }
		if (HX_FIELD_EQ(inName,"getCanvas") ) { return getCanvas_dyn(); }
		if (HX_FIELD_EQ(inName,"setTarget") ) { return setTarget_dyn(); }
		if (HX_FIELD_EQ(inName,"correctSq") ) { return correctSq_dyn(); }
		if (HX_FIELD_EQ(inName,"doAnimate") ) { return doAnimate_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"getTargetX") ) { return getTargetX_dyn(); }
		if (HX_FIELD_EQ(inName,"getTargetY") ) { return getTargetY_dyn(); }
		if (HX_FIELD_EQ(inName,"doSequence") ) { return doSequence_dyn(); }
		if (HX_FIELD_EQ(inName,"doMovement") ) { return doMovement_dyn(); }
		if (HX_FIELD_EQ(inName,"doNextMove") ) { return doNextMove_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"gsGoodCodes") ) { return gsGoodCodes; }
		if (HX_FIELD_EQ(inName,"gsTileWidth") ) { return gsTileWidth; }
		if (HX_FIELD_EQ(inName,"setInterval") ) { return setInterval_dyn(); }
		if (HX_FIELD_EQ(inName,"getDistance") ) { return getDistance_dyn(); }
		if (HX_FIELD_EQ(inName,"getDistFrom") ) { return getDistFrom_dyn(); }
		if (HX_FIELD_EQ(inName,"doNextFrame") ) { return doNextFrame_dyn(); }
		if (HX_FIELD_EQ(inName,"doCheckMove") ) { return doCheckMove_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"setGoodCodes") ) { return setGoodCodes_dyn(); }
		if (HX_FIELD_EQ(inName,"setTileWidth") ) { return setTileWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"doMoveTarget") ) { return doMoveTarget_dyn(); }
		if (HX_FIELD_EQ(inName,"getMoveCode1") ) { return getMoveCode1_dyn(); }
		if (HX_FIELD_EQ(inName,"getMoveCode2") ) { return getMoveCode2_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GameSprite_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"gsMap") ) { gsMap=inValue.Cast< ::tenblock::GameMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gsSeq") ) { gsSeq=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"gsName") ) { gsName=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gsType") ) { gsType=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"doAnim") ) { doAnim=inValue.Cast< ::haxe::Timer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gsIncr") ) { gsIncr=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gsFlag") ) { gsFlag=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"gsFrame") ) { gsFrame=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"runFlag") ) { runFlag=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"gsCanvas") ) { gsCanvas=inValue.Cast< ::openfl::display::Sprite >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"gsTargetX") ) { gsTargetX=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gsTargetY") ) { gsTargetY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gsMoveSqX") ) { gsMoveSqX=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gsMoveSqY") ) { gsMoveSqY=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"gsGoodCodes") ) { gsGoodCodes=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gsTileWidth") ) { gsTileWidth=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GameSprite_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("gsName"));
	outFields->push(HX_CSTRING("gsType"));
	outFields->push(HX_CSTRING("gsCanvas"));
	outFields->push(HX_CSTRING("doAnim"));
	outFields->push(HX_CSTRING("gsFrame"));
	outFields->push(HX_CSTRING("runFlag"));
	outFields->push(HX_CSTRING("gsIncr"));
	outFields->push(HX_CSTRING("gsTargetX"));
	outFields->push(HX_CSTRING("gsTargetY"));
	outFields->push(HX_CSTRING("gsMoveSqX"));
	outFields->push(HX_CSTRING("gsMoveSqY"));
	outFields->push(HX_CSTRING("gsMap"));
	outFields->push(HX_CSTRING("gsGoodCodes"));
	outFields->push(HX_CSTRING("gsSeq"));
	outFields->push(HX_CSTRING("gsFlag"));
	outFields->push(HX_CSTRING("gsTileWidth"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(GameSprite_obj,gsName),HX_CSTRING("gsName")},
	{hx::fsString,(int)offsetof(GameSprite_obj,gsType),HX_CSTRING("gsType")},
	{hx::fsObject /*::openfl::display::Sprite*/ ,(int)offsetof(GameSprite_obj,gsCanvas),HX_CSTRING("gsCanvas")},
	{hx::fsObject /*::haxe::Timer*/ ,(int)offsetof(GameSprite_obj,doAnim),HX_CSTRING("doAnim")},
	{hx::fsFloat,(int)offsetof(GameSprite_obj,gsFrame),HX_CSTRING("gsFrame")},
	{hx::fsInt,(int)offsetof(GameSprite_obj,runFlag),HX_CSTRING("runFlag")},
	{hx::fsFloat,(int)offsetof(GameSprite_obj,gsIncr),HX_CSTRING("gsIncr")},
	{hx::fsInt,(int)offsetof(GameSprite_obj,gsTargetX),HX_CSTRING("gsTargetX")},
	{hx::fsInt,(int)offsetof(GameSprite_obj,gsTargetY),HX_CSTRING("gsTargetY")},
	{hx::fsInt,(int)offsetof(GameSprite_obj,gsMoveSqX),HX_CSTRING("gsMoveSqX")},
	{hx::fsInt,(int)offsetof(GameSprite_obj,gsMoveSqY),HX_CSTRING("gsMoveSqY")},
	{hx::fsObject /*::tenblock::GameMap*/ ,(int)offsetof(GameSprite_obj,gsMap),HX_CSTRING("gsMap")},
	{hx::fsString,(int)offsetof(GameSprite_obj,gsGoodCodes),HX_CSTRING("gsGoodCodes")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(GameSprite_obj,gsSeq),HX_CSTRING("gsSeq")},
	{hx::fsInt,(int)offsetof(GameSprite_obj,gsFlag),HX_CSTRING("gsFlag")},
	{hx::fsInt,(int)offsetof(GameSprite_obj,gsTileWidth),HX_CSTRING("gsTileWidth")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("gsName"),
	HX_CSTRING("gsType"),
	HX_CSTRING("gsCanvas"),
	HX_CSTRING("doAnim"),
	HX_CSTRING("gsFrame"),
	HX_CSTRING("runFlag"),
	HX_CSTRING("gsIncr"),
	HX_CSTRING("gsTargetX"),
	HX_CSTRING("gsTargetY"),
	HX_CSTRING("gsMoveSqX"),
	HX_CSTRING("gsMoveSqY"),
	HX_CSTRING("gsMap"),
	HX_CSTRING("gsGoodCodes"),
	HX_CSTRING("gsSeq"),
	HX_CSTRING("gsFlag"),
	HX_CSTRING("gsTileWidth"),
	HX_CSTRING("setCanvas"),
	HX_CSTRING("getCanvas"),
	HX_CSTRING("setMap"),
	HX_CSTRING("getMap"),
	HX_CSTRING("setInterval"),
	HX_CSTRING("setGoodCodes"),
	HX_CSTRING("drawAt"),
	HX_CSTRING("moveTo"),
	HX_CSTRING("setMid"),
	HX_CSTRING("getX"),
	HX_CSTRING("getY"),
	HX_CSTRING("getMidX"),
	HX_CSTRING("getMidY"),
	HX_CSTRING("setTileWidth"),
	HX_CSTRING("getXSq"),
	HX_CSTRING("getYSq"),
	HX_CSTRING("getFeetY"),
	HX_CSTRING("setMidX"),
	HX_CSTRING("setMidY"),
	HX_CSTRING("setFeetY"),
	HX_CSTRING("dropOnSq"),
	HX_CSTRING("setTarget"),
	HX_CSTRING("getTargetX"),
	HX_CSTRING("getTargetY"),
	HX_CSTRING("getName"),
	HX_CSTRING("getType"),
	HX_CSTRING("getDistance"),
	HX_CSTRING("getDistFrom"),
	HX_CSTRING("doSequence"),
	HX_CSTRING("doMovement"),
	HX_CSTRING("doMoveTarget"),
	HX_CSTRING("correctSq"),
	HX_CSTRING("doAnimate"),
	HX_CSTRING("doNextFrame"),
	HX_CSTRING("doNextMove"),
	HX_CSTRING("doCheckMove"),
	HX_CSTRING("isGood"),
	HX_CSTRING("getMoveCode1"),
	HX_CSTRING("getMoveCode2"),
	HX_CSTRING("doStop"),
	HX_CSTRING("doStand"),
	HX_CSTRING("doFrames"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GameSprite_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GameSprite_obj::__mClass,"__mClass");
};

#endif

Class GameSprite_obj::__mClass;

void GameSprite_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tenblock.GameSprite"), hx::TCanCast< GameSprite_obj> ,sStaticFields,sMemberFields,
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

void GameSprite_obj::__boot()
{
}

} // end namespace tenblock
