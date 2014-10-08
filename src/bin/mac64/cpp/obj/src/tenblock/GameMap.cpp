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
#ifndef INCLUDED_tenblock_GameMap
#include <tenblock/GameMap.h>
#endif
namespace tenblock{

Void GameMap_obj::__construct(::String cfile)
{
HX_STACK_FRAME("tenblock.GameMap","new",0x301ed87e,"tenblock.GameMap.new","tenblock/GameMap.hx",37,0x633cabf3)
HX_STACK_THIS(this)
HX_STACK_ARG(cfile,"cfile")
{
	HX_STACK_LINE(38)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(39)
	::String cxml = ::openfl::Assets_obj::getText(cfile);		HX_STACK_VAR(cxml,"cxml");
	HX_STACK_LINE(40)
	::Xml xml = ::Xml_obj::parse(cxml);		HX_STACK_VAR(xml,"xml");
	HX_STACK_LINE(41)
	::Xml _g = xml->firstElement();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(41)
	::haxe::xml::Fast fast = ::haxe::xml::Fast_obj::__new(_g);		HX_STACK_VAR(fast,"fast");
	HX_STACK_LINE(43)
	::haxe::xml::Fast rows = fast->node->resolve(HX_CSTRING("rows"));		HX_STACK_VAR(rows,"rows");
	HX_STACK_LINE(45)
	Array< ::String > _g1 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(45)
	this->gmRows = _g1;
	HX_STACK_LINE(47)
	Array< ::String > _g2 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(47)
	this->gmCodes = _g2;
	HX_STACK_LINE(48)
	Array< ::String > _g3 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(48)
	this->gmNames = _g3;
	HX_STACK_LINE(49)
	Array< ::String > _g4 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(49)
	this->gmTypes = _g4;
	HX_STACK_LINE(50)
	Array< ::String > _g5 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(50)
	this->gmBlocks = _g5;
	HX_STACK_LINE(51)
	Array< ::String > _g6 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(51)
	this->gmFiles = _g6;
	HX_STACK_LINE(52)
	Array< int > _g7 = Array_obj< int >::__new();		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(52)
	this->gmWidths = _g7;
	HX_STACK_LINE(53)
	Array< int > _g8 = Array_obj< int >::__new();		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(53)
	this->gmHeights = _g8;
	HX_STACK_LINE(55)
	this->anchorX = (int)10;
	HX_STACK_LINE(56)
	this->anchorY = (int)-50;
	HX_STACK_LINE(58)
	i = (int)0;
	HX_STACK_LINE(60)
	for(::cpp::FastIterator_obj< ::haxe::xml::Fast > *__it = ::cpp::CreateFastIterator< ::haxe::xml::Fast >(rows->nodes->resolve(HX_CSTRING("row"))->iterator());  __it->hasNext(); ){
		::haxe::xml::Fast p = __it->next();
		{
			HX_STACK_LINE(61)
			this->gmRows[i] = p->get_innerData();
			HX_STACK_LINE(62)
			(i)++;
		}
;
	}
	HX_STACK_LINE(65)
	this->gmHeight = i;
	HX_STACK_LINE(66)
	this->gmWidth = this->gmRows->__get((i - (int)1)).length;
	HX_STACK_LINE(68)
	::haxe::xml::Fast tiles = fast->node->resolve(HX_CSTRING("tiles"));		HX_STACK_VAR(tiles,"tiles");
	HX_STACK_LINE(69)
	::String _g9 = fast->node->resolve(HX_CSTRING("tilewidth"))->get_innerData();		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(69)
	Dynamic _g10 = ::Std_obj::parseInt(_g9);		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(69)
	this->tileWidth = _g10;
	HX_STACK_LINE(70)
	::String _g11 = fast->node->resolve(HX_CSTRING("tileheight"))->get_innerData();		HX_STACK_VAR(_g11,"_g11");
	HX_STACK_LINE(70)
	Dynamic _g12 = ::Std_obj::parseInt(_g11);		HX_STACK_VAR(_g12,"_g12");
	HX_STACK_LINE(70)
	this->tileHeight = _g12;
	HX_STACK_LINE(72)
	i = (int)0;
	HX_STACK_LINE(74)
	for(::cpp::FastIterator_obj< ::haxe::xml::Fast > *__it = ::cpp::CreateFastIterator< ::haxe::xml::Fast >(tiles->nodes->resolve(HX_CSTRING("tile"))->iterator());  __it->hasNext(); ){
		::haxe::xml::Fast q = __it->next();
		{
			HX_STACK_LINE(76)
			this->gmCodes[i] = q->node->resolve(HX_CSTRING("code"))->get_innerData();
			HX_STACK_LINE(77)
			this->gmNames[i] = q->node->resolve(HX_CSTRING("name"))->get_innerData();
			HX_STACK_LINE(78)
			this->gmTypes[i] = q->node->resolve(HX_CSTRING("type"))->get_innerData();
			HX_STACK_LINE(79)
			this->gmBlocks[i] = q->node->resolve(HX_CSTRING("block"))->get_innerData();
			HX_STACK_LINE(80)
			this->gmFiles[i] = q->node->resolve(HX_CSTRING("file"))->get_innerData();
			HX_STACK_LINE(82)
			(i)++;
		}
;
	}
}
;
	return null();
}

//GameMap_obj::~GameMap_obj() { }

Dynamic GameMap_obj::__CreateEmpty() { return  new GameMap_obj; }
hx::ObjectPtr< GameMap_obj > GameMap_obj::__new(::String cfile)
{  hx::ObjectPtr< GameMap_obj > result = new GameMap_obj();
	result->__construct(cfile);
	return result;}

Dynamic GameMap_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GameMap_obj > result = new GameMap_obj();
	result->__construct(inArgs[0]);
	return result;}

int GameMap_obj::getTileWidth( ){
	HX_STACK_FRAME("tenblock.GameMap","getTileWidth",0x4062b4a4,"tenblock.GameMap.getTileWidth","tenblock/GameMap.hx",88,0x633cabf3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(88)
	return this->tileWidth;
}


HX_DEFINE_DYNAMIC_FUNC0(GameMap_obj,getTileWidth,return )

int GameMap_obj::getWidth( ){
	HX_STACK_FRAME("tenblock.GameMap","getWidth",0xb42690b2,"tenblock.GameMap.getWidth","tenblock/GameMap.hx",93,0x633cabf3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(93)
	return this->gmWidth;
}


HX_DEFINE_DYNAMIC_FUNC0(GameMap_obj,getWidth,return )

int GameMap_obj::getHeight( ){
	HX_STACK_FRAME("tenblock.GameMap","getHeight",0xa3e783bb,"tenblock.GameMap.getHeight","tenblock/GameMap.hx",98,0x633cabf3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(98)
	return this->gmHeight;
}


HX_DEFINE_DYNAMIC_FUNC0(GameMap_obj,getHeight,return )

Void GameMap_obj::setAnchorX( int cax){
{
		HX_STACK_FRAME("tenblock.GameMap","setAnchorX",0xcc906863,"tenblock.GameMap.setAnchorX","tenblock/GameMap.hx",103,0x633cabf3)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cax,"cax")
		HX_STACK_LINE(103)
		this->anchorX = cax;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameMap_obj,setAnchorX,(void))

Void GameMap_obj::setAnchorY( int cay){
{
		HX_STACK_FRAME("tenblock.GameMap","setAnchorY",0xcc906864,"tenblock.GameMap.setAnchorY","tenblock/GameMap.hx",108,0x633cabf3)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cay,"cay")
		HX_STACK_LINE(108)
		this->anchorY = cay;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameMap_obj,setAnchorY,(void))

Void GameMap_obj::setCanvas( ::openfl::display::Sprite ccanvas){
{
		HX_STACK_FRAME("tenblock.GameMap","setCanvas",0x3d2ebcb8,"tenblock.GameMap.setCanvas","tenblock/GameMap.hx",113,0x633cabf3)
		HX_STACK_THIS(this)
		HX_STACK_ARG(ccanvas,"ccanvas")
		HX_STACK_LINE(113)
		this->gmCanvas = ccanvas;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameMap_obj,setCanvas,(void))

::openfl::display::Sprite GameMap_obj::getCanvas( ){
	HX_STACK_FRAME("tenblock.GameMap","getCanvas",0x59ddd0ac,"tenblock.GameMap.getCanvas","tenblock/GameMap.hx",118,0x633cabf3)
	HX_STACK_THIS(this)
	HX_STACK_LINE(118)
	return this->gmCanvas;
}


HX_DEFINE_DYNAMIC_FUNC0(GameMap_obj,getCanvas,return )

int GameMap_obj::getMidSqX( int csqx){
	HX_STACK_FRAME("tenblock.GameMap","getMidSqX",0xeded6d26,"tenblock.GameMap.getMidSqX","tenblock/GameMap.hx",123,0x633cabf3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(csqx,"csqx")
	HX_STACK_LINE(123)
	return ::Std_obj::_int(((this->anchorX + (csqx * this->tileWidth)) + (Float(this->tileWidth) / Float((int)2))));
}


HX_DEFINE_DYNAMIC_FUNC1(GameMap_obj,getMidSqX,return )

int GameMap_obj::getMidSqY( int csqy){
	HX_STACK_FRAME("tenblock.GameMap","getMidSqY",0xeded6d27,"tenblock.GameMap.getMidSqY","tenblock/GameMap.hx",128,0x633cabf3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(csqy,"csqy")
	HX_STACK_LINE(128)
	return ::Std_obj::_int(((this->anchorY + ((csqy * this->tileWidth) * 0.85)) + (Float(this->tileHeight) / Float((int)2))));
}


HX_DEFINE_DYNAMIC_FUNC1(GameMap_obj,getMidSqY,return )

int GameMap_obj::getSqX( int cx){
	HX_STACK_FRAME("tenblock.GameMap","getSqX",0x81c53da6,"tenblock.GameMap.getSqX","tenblock/GameMap.hx",133,0x633cabf3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(cx,"cx")
	HX_STACK_LINE(133)
	return ::Std_obj::_int((Float(cx) / Float(this->tileWidth)));
}


HX_DEFINE_DYNAMIC_FUNC1(GameMap_obj,getSqX,return )

int GameMap_obj::getSqY( int cy){
	HX_STACK_FRAME("tenblock.GameMap","getSqY",0x81c53da7,"tenblock.GameMap.getSqY","tenblock/GameMap.hx",138,0x633cabf3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(cy,"cy")
	HX_STACK_LINE(138)
	return ::Std_obj::_int((Float(cy) / Float(this->tileWidth)));
}


HX_DEFINE_DYNAMIC_FUNC1(GameMap_obj,getSqY,return )

::String GameMap_obj::getCode( int cx,int cy){
	HX_STACK_FRAME("tenblock.GameMap","getCode",0x003bd001,"tenblock.GameMap.getCode","tenblock/GameMap.hx",143,0x633cabf3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(cx,"cx")
	HX_STACK_ARG(cy,"cy")
	HX_STACK_LINE(143)
	return this->gmRows->__get(cy).substr(cx,(int)1);
}


HX_DEFINE_DYNAMIC_FUNC2(GameMap_obj,getCode,return )

::String GameMap_obj::getType( ::String ccode){
	HX_STACK_FRAME("tenblock.GameMap","getType",0x0b80118e,"tenblock.GameMap.getType","tenblock/GameMap.hx",147,0x633cabf3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(ccode,"ccode")
	HX_STACK_LINE(148)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(150)
	i = (int)0;
	HX_STACK_LINE(151)
	while((true)){
		HX_STACK_LINE(151)
		if ((!(((i < this->gmCodes->length))))){
			HX_STACK_LINE(151)
			break;
		}
		HX_STACK_LINE(153)
		if (((ccode == this->gmCodes->__get(i)))){
			HX_STACK_LINE(153)
			return this->gmTypes->__get(i);
		}
		HX_STACK_LINE(154)
		(i)++;
	}
	HX_STACK_LINE(157)
	return HX_CSTRING("");
}


HX_DEFINE_DYNAMIC_FUNC1(GameMap_obj,getType,return )

::String GameMap_obj::getBlock( ::String ccode){
	HX_STACK_FRAME("tenblock.GameMap","getBlock",0x9ec04ff9,"tenblock.GameMap.getBlock","tenblock/GameMap.hx",161,0x633cabf3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(ccode,"ccode")
	HX_STACK_LINE(162)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(164)
	i = (int)0;
	HX_STACK_LINE(165)
	while((true)){
		HX_STACK_LINE(165)
		if ((!(((i < this->gmCodes->length))))){
			HX_STACK_LINE(165)
			break;
		}
		HX_STACK_LINE(167)
		if (((ccode == this->gmCodes->__get(i)))){
			HX_STACK_LINE(167)
			return this->gmBlocks->__get(i);
		}
		HX_STACK_LINE(168)
		(i)++;
	}
	HX_STACK_LINE(171)
	return HX_CSTRING("");
}


HX_DEFINE_DYNAMIC_FUNC1(GameMap_obj,getBlock,return )

bool GameMap_obj::isValid( int cx,int cy,::String ctype){
	HX_STACK_FRAME("tenblock.GameMap","isValid",0xba3287d0,"tenblock.GameMap.isValid","tenblock/GameMap.hx",176,0x633cabf3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(cx,"cx")
	HX_STACK_ARG(cy,"cy")
	HX_STACK_ARG(ctype,"ctype")
	HX_STACK_LINE(176)
	if (((bool((cx < (int)0)) || bool((cy < (int)0))))){
		HX_STACK_LINE(177)
		return false;
	}
	else{
		HX_STACK_LINE(178)
		if (((bool((cx >= this->gmWidth)) || bool((cy >= this->gmHeight))))){
			HX_STACK_LINE(179)
			return false;
		}
		else{
			HX_STACK_LINE(180)
			::String _g = this->getCode(cx,cy);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(180)
			::String _g1 = this->getBlock(_g);		HX_STACK_VAR(_g1,"_g1");
			struct _Function_3_1{
				inline static bool Block( hx::ObjectPtr< ::tenblock::GameMap_obj > __this,int &cx,int &cy){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","tenblock/GameMap.hx",180,0x633cabf3)
					{
						HX_STACK_LINE(180)
						::String _g2 = __this->getCode(cx,cy);		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(180)
						::String _g3 = __this->getBlock(_g2);		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(180)
						return (_g3 == HX_CSTRING("all"));
					}
					return null();
				}
			};
			HX_STACK_LINE(180)
			if (((  ((!(((_g1 == ctype))))) ? bool(_Function_3_1::Block(this,cx,cy)) : bool(true) ))){
				HX_STACK_LINE(181)
				return false;
			}
			else{
				HX_STACK_LINE(183)
				return true;
			}
		}
	}
	HX_STACK_LINE(176)
	return false;
}


HX_DEFINE_DYNAMIC_FUNC3(GameMap_obj,isValid,return )

int GameMap_obj::getCoord( ::String ccoord,int cx,int cy){
	HX_STACK_FRAME("tenblock.GameMap","getCoord",0x34229561,"tenblock.GameMap.getCoord","tenblock/GameMap.hx",187,0x633cabf3)
	HX_STACK_THIS(this)
	HX_STACK_ARG(ccoord,"ccoord")
	HX_STACK_ARG(cx,"cx")
	HX_STACK_ARG(cy,"cy")
	HX_STACK_LINE(188)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(189)
	int j;		HX_STACK_VAR(j,"j");
	HX_STACK_LINE(190)
	int finalx;		HX_STACK_VAR(finalx,"finalx");
	HX_STACK_LINE(191)
	int finaly;		HX_STACK_VAR(finaly,"finaly");
	HX_STACK_LINE(193)
	int cxstart;		HX_STACK_VAR(cxstart,"cxstart");
	HX_STACK_LINE(194)
	int cystart;		HX_STACK_VAR(cystart,"cystart");
	HX_STACK_LINE(195)
	int ytemp;		HX_STACK_VAR(ytemp,"ytemp");
	HX_STACK_LINE(197)
	i = (int)0;
	HX_STACK_LINE(198)
	j = (int)0;
	HX_STACK_LINE(199)
	finalx = (int)0;
	HX_STACK_LINE(200)
	finaly = (int)0;
	HX_STACK_LINE(201)
	cxstart = (int)0;
	HX_STACK_LINE(202)
	cystart = (int)0;
	HX_STACK_LINE(204)
	while((true)){
		HX_STACK_LINE(204)
		if ((!(((i < this->gmRows->length))))){
			HX_STACK_LINE(204)
			break;
		}
		HX_STACK_LINE(206)
		j = (int)0;
		HX_STACK_LINE(208)
		while((true)){
			HX_STACK_LINE(208)
			if ((!(((j < this->gmRows->__get((int)0).length))))){
				HX_STACK_LINE(208)
				break;
			}
			HX_STACK_LINE(210)
			cxstart = ((j * this->tileWidth) + this->anchorX);
			HX_STACK_LINE(211)
			if (((hx::Mod(i,(int)2) != (int)0))){
				HX_STACK_LINE(211)
				int _g = ::Std_obj::_int((Float(this->tileWidth) / Float((int)2)));		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(211)
				int _g1 = (cxstart - _g);		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(211)
				cxstart = _g1;
			}
			HX_STACK_LINE(213)
			cystart = ((i * (int)53) + this->anchorY);
			HX_STACK_LINE(215)
			if (((bool((bool((bool((cx >= cxstart)) && bool((cx < (cxstart + this->tileWidth))))) && bool((cy >= cystart)))) && bool((cy < (cystart + this->tileHeight)))))){
				HX_STACK_LINE(217)
				if ((((cy - cystart) < (int)21))){
					HX_STACK_LINE(219)
					if ((((cx - cxstart) <= (int)32))){
						HX_STACK_LINE(221)
						int _g2 = ::Std_obj::_int(((Float(((cx - cxstart))) / Float((int)32)) * (int)21));		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(221)
						ytemp = _g2;
						HX_STACK_LINE(223)
						if ((((cy - cystart) >= ((int)21 - ytemp)))){
							HX_STACK_LINE(225)
							finalx = j;
							HX_STACK_LINE(226)
							finaly = i;
						}
					}
					else{
						HX_STACK_LINE(231)
						int _g3 = ::Std_obj::_int(((Float((((cx - cxstart) - (int)32))) / Float((int)32)) * (int)21));		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(231)
						ytemp = _g3;
						HX_STACK_LINE(233)
						if ((((cy - cystart) >= ytemp))){
							HX_STACK_LINE(235)
							finalx = j;
							HX_STACK_LINE(236)
							finaly = i;
						}
					}
				}
				else{
					HX_STACK_LINE(240)
					if ((((cy - cystart) >= (int)53))){
						HX_STACK_LINE(242)
						if ((((cx - cxstart) <= (int)32))){
							HX_STACK_LINE(244)
							int _g4 = ::Std_obj::_int(((Float(((cx - cxstart))) / Float((int)32)) * (int)21));		HX_STACK_VAR(_g4,"_g4");
							HX_STACK_LINE(244)
							ytemp = _g4;
							HX_STACK_LINE(246)
							if (((((cy - cystart) - (int)53) <= ytemp))){
								HX_STACK_LINE(248)
								finalx = j;
								HX_STACK_LINE(249)
								finaly = i;
							}
						}
						else{
							HX_STACK_LINE(254)
							int _g5 = ::Std_obj::_int(((Float((((cx - cxstart) - (int)32))) / Float((int)32)) * (int)21));		HX_STACK_VAR(_g5,"_g5");
							HX_STACK_LINE(254)
							ytemp = _g5;
							HX_STACK_LINE(256)
							if (((((cy - cystart) - (int)53) <= ((int)21 - ytemp)))){
								HX_STACK_LINE(258)
								finalx = j;
								HX_STACK_LINE(259)
								finaly = i;
							}
						}
					}
					else{
						HX_STACK_LINE(265)
						finalx = j;
						HX_STACK_LINE(266)
						finaly = i;
					}
				}
			}
			HX_STACK_LINE(270)
			(j)++;
		}
		HX_STACK_LINE(273)
		(i)++;
	}
	HX_STACK_LINE(276)
	if (((ccoord == HX_CSTRING("x")))){
		HX_STACK_LINE(276)
		return finalx;
	}
	else{
		HX_STACK_LINE(277)
		return finaly;
	}
	HX_STACK_LINE(276)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC3(GameMap_obj,getCoord,return )

Void GameMap_obj::drawMap( ){
{
		HX_STACK_FRAME("tenblock.GameMap","drawMap",0xe7c76016,"tenblock.GameMap.drawMap","tenblock/GameMap.hx",281,0x633cabf3)
		HX_STACK_THIS(this)
		HX_STACK_LINE(282)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(283)
		int j;		HX_STACK_VAR(j,"j");
		HX_STACK_LINE(284)
		int k;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(285)
		int ccode;		HX_STACK_VAR(ccode,"ccode");
		HX_STACK_LINE(287)
		i = (int)0;
		HX_STACK_LINE(288)
		while((true)){
			HX_STACK_LINE(288)
			if ((!(((i < this->gmRows->length))))){
				HX_STACK_LINE(288)
				break;
			}
			HX_STACK_LINE(290)
			j = (int)0;
			HX_STACK_LINE(292)
			while((true)){
				HX_STACK_LINE(292)
				if ((!(((j < this->gmRows->__get((int)0).length))))){
					HX_STACK_LINE(292)
					break;
				}
				HX_STACK_LINE(294)
				k = (int)0;
				HX_STACK_LINE(295)
				ccode = (int)-1;
				HX_STACK_LINE(297)
				while((true)){
					HX_STACK_LINE(297)
					if ((!(((k < this->gmCodes->length))))){
						HX_STACK_LINE(297)
						break;
					}
					HX_STACK_LINE(299)
					::String _g = this->gmRows->__get(i).charAt(j);		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(299)
					if (((_g == this->gmCodes->__get(k)))){
						HX_STACK_LINE(301)
						ccode = k;
						HX_STACK_LINE(302)
						k = this->gmCodes->length;
					}
					HX_STACK_LINE(305)
					(k)++;
				}
				HX_STACK_LINE(308)
				if (((ccode != (int)-1))){
					HX_STACK_LINE(310)
					::openfl::display::BitmapData _g1 = ::openfl::Assets_obj::getBitmapData(this->gmFiles->__get(ccode),null());		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(310)
					::openfl::display::Bitmap mapBitmap = ::openfl::display::Bitmap_obj::__new(_g1,null(),null());		HX_STACK_VAR(mapBitmap,"mapBitmap");
					HX_STACK_LINE(311)
					mapBitmap->set_smoothing(true);
					HX_STACK_LINE(312)
					this->gmCanvas->addChild(mapBitmap);
					HX_STACK_LINE(314)
					if (((hx::Mod(i,(int)2) == (int)0))){
						HX_STACK_LINE(316)
						mapBitmap->set_x(((j * this->tileWidth) + this->anchorX));
						HX_STACK_LINE(317)
						mapBitmap->set_y((((i * this->tileWidth) * 0.85) + this->anchorY));
					}
					else{
						HX_STACK_LINE(321)
						int _g2 = ::Std_obj::_int((Float(this->tileWidth) / Float((int)2)));		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(321)
						int _g3 = ((j * this->tileWidth) - _g2);		HX_STACK_VAR(_g3,"_g3");
						HX_STACK_LINE(321)
						int _g4 = (_g3 + this->anchorX);		HX_STACK_VAR(_g4,"_g4");
						HX_STACK_LINE(321)
						mapBitmap->set_x(_g4);
						HX_STACK_LINE(322)
						mapBitmap->set_y((((i * this->tileWidth) * 0.85) + this->anchorY));
					}
				}
				HX_STACK_LINE(327)
				(j)++;
			}
			HX_STACK_LINE(330)
			(i)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameMap_obj,drawMap,(void))


GameMap_obj::GameMap_obj()
{
}

void GameMap_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GameMap);
	HX_MARK_MEMBER_NAME(gmRows,"gmRows");
	HX_MARK_MEMBER_NAME(gmCodes,"gmCodes");
	HX_MARK_MEMBER_NAME(gmNames,"gmNames");
	HX_MARK_MEMBER_NAME(gmTypes,"gmTypes");
	HX_MARK_MEMBER_NAME(gmBlocks,"gmBlocks");
	HX_MARK_MEMBER_NAME(gmFiles,"gmFiles");
	HX_MARK_MEMBER_NAME(gmWidths,"gmWidths");
	HX_MARK_MEMBER_NAME(gmHeights,"gmHeights");
	HX_MARK_MEMBER_NAME(tileWidth,"tileWidth");
	HX_MARK_MEMBER_NAME(tileHeight,"tileHeight");
	HX_MARK_MEMBER_NAME(anchorX,"anchorX");
	HX_MARK_MEMBER_NAME(anchorY,"anchorY");
	HX_MARK_MEMBER_NAME(gmWidth,"gmWidth");
	HX_MARK_MEMBER_NAME(gmHeight,"gmHeight");
	HX_MARK_MEMBER_NAME(gmCanvas,"gmCanvas");
	HX_MARK_END_CLASS();
}

void GameMap_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(gmRows,"gmRows");
	HX_VISIT_MEMBER_NAME(gmCodes,"gmCodes");
	HX_VISIT_MEMBER_NAME(gmNames,"gmNames");
	HX_VISIT_MEMBER_NAME(gmTypes,"gmTypes");
	HX_VISIT_MEMBER_NAME(gmBlocks,"gmBlocks");
	HX_VISIT_MEMBER_NAME(gmFiles,"gmFiles");
	HX_VISIT_MEMBER_NAME(gmWidths,"gmWidths");
	HX_VISIT_MEMBER_NAME(gmHeights,"gmHeights");
	HX_VISIT_MEMBER_NAME(tileWidth,"tileWidth");
	HX_VISIT_MEMBER_NAME(tileHeight,"tileHeight");
	HX_VISIT_MEMBER_NAME(anchorX,"anchorX");
	HX_VISIT_MEMBER_NAME(anchorY,"anchorY");
	HX_VISIT_MEMBER_NAME(gmWidth,"gmWidth");
	HX_VISIT_MEMBER_NAME(gmHeight,"gmHeight");
	HX_VISIT_MEMBER_NAME(gmCanvas,"gmCanvas");
}

Dynamic GameMap_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"gmRows") ) { return gmRows; }
		if (HX_FIELD_EQ(inName,"getSqX") ) { return getSqX_dyn(); }
		if (HX_FIELD_EQ(inName,"getSqY") ) { return getSqY_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"gmCodes") ) { return gmCodes; }
		if (HX_FIELD_EQ(inName,"gmNames") ) { return gmNames; }
		if (HX_FIELD_EQ(inName,"gmTypes") ) { return gmTypes; }
		if (HX_FIELD_EQ(inName,"gmFiles") ) { return gmFiles; }
		if (HX_FIELD_EQ(inName,"anchorX") ) { return anchorX; }
		if (HX_FIELD_EQ(inName,"anchorY") ) { return anchorY; }
		if (HX_FIELD_EQ(inName,"gmWidth") ) { return gmWidth; }
		if (HX_FIELD_EQ(inName,"getCode") ) { return getCode_dyn(); }
		if (HX_FIELD_EQ(inName,"getType") ) { return getType_dyn(); }
		if (HX_FIELD_EQ(inName,"isValid") ) { return isValid_dyn(); }
		if (HX_FIELD_EQ(inName,"drawMap") ) { return drawMap_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"gmBlocks") ) { return gmBlocks; }
		if (HX_FIELD_EQ(inName,"gmWidths") ) { return gmWidths; }
		if (HX_FIELD_EQ(inName,"gmHeight") ) { return gmHeight; }
		if (HX_FIELD_EQ(inName,"gmCanvas") ) { return gmCanvas; }
		if (HX_FIELD_EQ(inName,"getWidth") ) { return getWidth_dyn(); }
		if (HX_FIELD_EQ(inName,"getBlock") ) { return getBlock_dyn(); }
		if (HX_FIELD_EQ(inName,"getCoord") ) { return getCoord_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"gmHeights") ) { return gmHeights; }
		if (HX_FIELD_EQ(inName,"tileWidth") ) { return tileWidth; }
		if (HX_FIELD_EQ(inName,"getHeight") ) { return getHeight_dyn(); }
		if (HX_FIELD_EQ(inName,"setCanvas") ) { return setCanvas_dyn(); }
		if (HX_FIELD_EQ(inName,"getCanvas") ) { return getCanvas_dyn(); }
		if (HX_FIELD_EQ(inName,"getMidSqX") ) { return getMidSqX_dyn(); }
		if (HX_FIELD_EQ(inName,"getMidSqY") ) { return getMidSqY_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"tileHeight") ) { return tileHeight; }
		if (HX_FIELD_EQ(inName,"setAnchorX") ) { return setAnchorX_dyn(); }
		if (HX_FIELD_EQ(inName,"setAnchorY") ) { return setAnchorY_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"getTileWidth") ) { return getTileWidth_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GameMap_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"gmRows") ) { gmRows=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"gmCodes") ) { gmCodes=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gmNames") ) { gmNames=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gmTypes") ) { gmTypes=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gmFiles") ) { gmFiles=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"anchorX") ) { anchorX=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"anchorY") ) { anchorY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gmWidth") ) { gmWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"gmBlocks") ) { gmBlocks=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gmWidths") ) { gmWidths=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gmHeight") ) { gmHeight=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gmCanvas") ) { gmCanvas=inValue.Cast< ::openfl::display::Sprite >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"gmHeights") ) { gmHeights=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tileWidth") ) { tileWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"tileHeight") ) { tileHeight=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GameMap_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("gmRows"));
	outFields->push(HX_CSTRING("gmCodes"));
	outFields->push(HX_CSTRING("gmNames"));
	outFields->push(HX_CSTRING("gmTypes"));
	outFields->push(HX_CSTRING("gmBlocks"));
	outFields->push(HX_CSTRING("gmFiles"));
	outFields->push(HX_CSTRING("gmWidths"));
	outFields->push(HX_CSTRING("gmHeights"));
	outFields->push(HX_CSTRING("tileWidth"));
	outFields->push(HX_CSTRING("tileHeight"));
	outFields->push(HX_CSTRING("anchorX"));
	outFields->push(HX_CSTRING("anchorY"));
	outFields->push(HX_CSTRING("gmWidth"));
	outFields->push(HX_CSTRING("gmHeight"));
	outFields->push(HX_CSTRING("gmCanvas"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(GameMap_obj,gmRows),HX_CSTRING("gmRows")},
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(GameMap_obj,gmCodes),HX_CSTRING("gmCodes")},
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(GameMap_obj,gmNames),HX_CSTRING("gmNames")},
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(GameMap_obj,gmTypes),HX_CSTRING("gmTypes")},
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(GameMap_obj,gmBlocks),HX_CSTRING("gmBlocks")},
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(GameMap_obj,gmFiles),HX_CSTRING("gmFiles")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(GameMap_obj,gmWidths),HX_CSTRING("gmWidths")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(GameMap_obj,gmHeights),HX_CSTRING("gmHeights")},
	{hx::fsInt,(int)offsetof(GameMap_obj,tileWidth),HX_CSTRING("tileWidth")},
	{hx::fsInt,(int)offsetof(GameMap_obj,tileHeight),HX_CSTRING("tileHeight")},
	{hx::fsInt,(int)offsetof(GameMap_obj,anchorX),HX_CSTRING("anchorX")},
	{hx::fsInt,(int)offsetof(GameMap_obj,anchorY),HX_CSTRING("anchorY")},
	{hx::fsInt,(int)offsetof(GameMap_obj,gmWidth),HX_CSTRING("gmWidth")},
	{hx::fsInt,(int)offsetof(GameMap_obj,gmHeight),HX_CSTRING("gmHeight")},
	{hx::fsObject /*::openfl::display::Sprite*/ ,(int)offsetof(GameMap_obj,gmCanvas),HX_CSTRING("gmCanvas")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("gmRows"),
	HX_CSTRING("gmCodes"),
	HX_CSTRING("gmNames"),
	HX_CSTRING("gmTypes"),
	HX_CSTRING("gmBlocks"),
	HX_CSTRING("gmFiles"),
	HX_CSTRING("gmWidths"),
	HX_CSTRING("gmHeights"),
	HX_CSTRING("tileWidth"),
	HX_CSTRING("tileHeight"),
	HX_CSTRING("anchorX"),
	HX_CSTRING("anchorY"),
	HX_CSTRING("gmWidth"),
	HX_CSTRING("gmHeight"),
	HX_CSTRING("gmCanvas"),
	HX_CSTRING("getTileWidth"),
	HX_CSTRING("getWidth"),
	HX_CSTRING("getHeight"),
	HX_CSTRING("setAnchorX"),
	HX_CSTRING("setAnchorY"),
	HX_CSTRING("setCanvas"),
	HX_CSTRING("getCanvas"),
	HX_CSTRING("getMidSqX"),
	HX_CSTRING("getMidSqY"),
	HX_CSTRING("getSqX"),
	HX_CSTRING("getSqY"),
	HX_CSTRING("getCode"),
	HX_CSTRING("getType"),
	HX_CSTRING("getBlock"),
	HX_CSTRING("isValid"),
	HX_CSTRING("getCoord"),
	HX_CSTRING("drawMap"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GameMap_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GameMap_obj::__mClass,"__mClass");
};

#endif

Class GameMap_obj::__mClass;

void GameMap_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tenblock.GameMap"), hx::TCanCast< GameMap_obj> ,sStaticFields,sMemberFields,
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

void GameMap_obj::__boot()
{
}

} // end namespace tenblock
