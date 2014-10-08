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
#ifndef INCLUDED_tenblock_Scenario
#include <tenblock/Scenario.h>
#endif
#ifndef INCLUDED_tenblock_SpritePack
#include <tenblock/SpritePack.h>
#endif
namespace tenblock{

Void Scenario_obj::__construct(::String cfile)
{
HX_STACK_FRAME("tenblock.Scenario","new",0x1ae09a80,"tenblock.Scenario.new","tenblock/Scenario.hx",37,0x96d1a28f)
HX_STACK_THIS(this)
HX_STACK_ARG(cfile,"cfile")
{
	HX_STACK_LINE(38)
	Array< ::String > _g = Array_obj< ::String >::__new();		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(38)
	this->scNames = _g;
	HX_STACK_LINE(39)
	Array< ::String > _g1 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g1,"_g1");
	HX_STACK_LINE(39)
	this->scSides = _g1;
	HX_STACK_LINE(40)
	Array< int > _g2 = Array_obj< int >::__new();		HX_STACK_VAR(_g2,"_g2");
	HX_STACK_LINE(40)
	this->scStartX = _g2;
	HX_STACK_LINE(41)
	Array< int > _g3 = Array_obj< int >::__new();		HX_STACK_VAR(_g3,"_g3");
	HX_STACK_LINE(41)
	this->scStartY = _g3;
	HX_STACK_LINE(42)
	Array< int > _g4 = Array_obj< int >::__new();		HX_STACK_VAR(_g4,"_g4");
	HX_STACK_LINE(42)
	this->scX = _g4;
	HX_STACK_LINE(43)
	Array< int > _g5 = Array_obj< int >::__new();		HX_STACK_VAR(_g5,"_g5");
	HX_STACK_LINE(43)
	this->scY = _g5;
	HX_STACK_LINE(44)
	Array< ::Dynamic > _g6 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g6,"_g6");
	HX_STACK_LINE(44)
	this->scCounters = _g6;
	HX_STACK_LINE(46)
	Array< int > _g7 = Array_obj< int >::__new();		HX_STACK_VAR(_g7,"_g7");
	HX_STACK_LINE(46)
	this->scX = _g7;
	HX_STACK_LINE(47)
	Array< int > _g8 = Array_obj< int >::__new();		HX_STACK_VAR(_g8,"_g8");
	HX_STACK_LINE(47)
	this->scY = _g8;
	HX_STACK_LINE(49)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(50)
	::String cxml = ::openfl::Assets_obj::getText(cfile);		HX_STACK_VAR(cxml,"cxml");
	HX_STACK_LINE(51)
	::Xml xml = ::Xml_obj::parse(cxml);		HX_STACK_VAR(xml,"xml");
	HX_STACK_LINE(52)
	::Xml _g9 = xml->firstElement();		HX_STACK_VAR(_g9,"_g9");
	HX_STACK_LINE(52)
	::haxe::xml::Fast fast = ::haxe::xml::Fast_obj::__new(_g9);		HX_STACK_VAR(fast,"fast");
	HX_STACK_LINE(54)
	i = (int)0;
	HX_STACK_LINE(56)
	::String _g10 = fast->node->resolve(HX_CSTRING("name"))->get_innerData();		HX_STACK_VAR(_g10,"_g10");
	HX_STACK_LINE(56)
	this->scName = _g10;
	HX_STACK_LINE(57)
	::haxe::xml::Fast counters = fast->node->resolve(HX_CSTRING("counters"));		HX_STACK_VAR(counters,"counters");
	HX_STACK_LINE(59)
	for(::cpp::FastIterator_obj< ::haxe::xml::Fast > *__it = ::cpp::CreateFastIterator< ::haxe::xml::Fast >(counters->nodes->resolve(HX_CSTRING("counter"))->iterator());  __it->hasNext(); ){
		::haxe::xml::Fast q = __it->next();
		{
			HX_STACK_LINE(61)
			this->scNames[i] = q->node->resolve(HX_CSTRING("name"))->get_innerData();
			HX_STACK_LINE(62)
			this->scSides[i] = q->node->resolve(HX_CSTRING("side"))->get_innerData();
			HX_STACK_LINE(63)
			::String _g11 = q->node->resolve(HX_CSTRING("startx"))->get_innerData();		HX_STACK_VAR(_g11,"_g11");
			HX_STACK_LINE(63)
			this->scStartX[i] = ::Std_obj::parseInt(_g11);
			HX_STACK_LINE(64)
			::String _g12 = q->node->resolve(HX_CSTRING("starty"))->get_innerData();		HX_STACK_VAR(_g12,"_g12");
			HX_STACK_LINE(64)
			this->scStartY[i] = ::Std_obj::parseInt(_g12);
			HX_STACK_LINE(66)
			this->scX[i] = this->scStartX->__get(i);
			HX_STACK_LINE(67)
			this->scY[i] = this->scStartY->__get(i);
			HX_STACK_LINE(69)
			(i)++;
		}
;
	}
	HX_STACK_LINE(72)
	this->scCount = i;
}
;
	return null();
}

//Scenario_obj::~Scenario_obj() { }

Dynamic Scenario_obj::__CreateEmpty() { return  new Scenario_obj; }
hx::ObjectPtr< Scenario_obj > Scenario_obj::__new(::String cfile)
{  hx::ObjectPtr< Scenario_obj > result = new Scenario_obj();
	result->__construct(cfile);
	return result;}

Dynamic Scenario_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Scenario_obj > result = new Scenario_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Scenario_obj::doDraw( ){
{
		HX_STACK_FRAME("tenblock.Scenario","doDraw",0xb1a81b0f,"tenblock.Scenario.doDraw","tenblock/Scenario.hx",76,0x96d1a28f)
		HX_STACK_THIS(this)
		HX_STACK_LINE(77)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(79)
		i = (int)0;
		HX_STACK_LINE(81)
		while((true)){
			HX_STACK_LINE(81)
			if ((!(((i < this->scCount))))){
				HX_STACK_LINE(81)
				break;
			}
			HX_STACK_LINE(83)
			int _g = this->scPack->getNum(this->scNames->__get(i));		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(83)
			::tenblock::GameSprite _g1 = this->scPack->makeSprite(_g);		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(83)
			this->scCounters->push(_g1);
			HX_STACK_LINE(85)
			this->scCounters->__get(i).StaticCast< ::tenblock::GameSprite >()->setMap(this->scMap);
			HX_STACK_LINE(86)
			this->scCounters->__get(i).StaticCast< ::tenblock::GameSprite >()->setCanvas(this->scCanvas);
			HX_STACK_LINE(87)
			this->scCounters->__get(i).StaticCast< ::tenblock::GameSprite >()->setTileWidth((int)45);
			HX_STACK_LINE(89)
			this->scCounters->__get(i).StaticCast< ::tenblock::GameSprite >()->drawAt((int)-150,(int)-150);
			HX_STACK_LINE(90)
			this->scCounters->__get(i).StaticCast< ::tenblock::GameSprite >()->dropOnSq(this->scStartX->__get(i),this->scStartY->__get(i));
			HX_STACK_LINE(91)
			this->scX[i] = this->scStartX->__get(i);
			HX_STACK_LINE(92)
			this->scY[i] = this->scStartY->__get(i);
			HX_STACK_LINE(94)
			(i)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Scenario_obj,doDraw,(void))

Void Scenario_obj::setCMP( ::openfl::display::Sprite ccanvas,::tenblock::GameMap cmap,::tenblock::SpritePack cpack){
{
		HX_STACK_FRAME("tenblock.Scenario","setCMP",0x0e9739e4,"tenblock.Scenario.setCMP","tenblock/Scenario.hx",99,0x96d1a28f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(ccanvas,"ccanvas")
		HX_STACK_ARG(cmap,"cmap")
		HX_STACK_ARG(cpack,"cpack")
		HX_STACK_LINE(100)
		this->scCanvas = ccanvas;
		HX_STACK_LINE(101)
		this->scMap = cmap;
		HX_STACK_LINE(102)
		this->scPack = cpack;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Scenario_obj,setCMP,(void))

int Scenario_obj::getCount( int cx,int cy,::String cside){
	HX_STACK_FRAME("tenblock.Scenario","getCount",0xb67cd639,"tenblock.Scenario.getCount","tenblock/Scenario.hx",106,0x96d1a28f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(cx,"cx")
	HX_STACK_ARG(cy,"cy")
	HX_STACK_ARG(cside,"cside")
	HX_STACK_LINE(107)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(108)
	int ccount;		HX_STACK_VAR(ccount,"ccount");
	HX_STACK_LINE(110)
	i = (int)0;
	HX_STACK_LINE(111)
	ccount = (int)0;
	HX_STACK_LINE(113)
	while((true)){
		HX_STACK_LINE(113)
		if ((!(((i < this->scCount))))){
			HX_STACK_LINE(113)
			break;
		}
		HX_STACK_LINE(115)
		if (((bool((bool((this->scX->__get(i) == cx)) && bool((this->scY->__get(i) == cy)))) && bool((this->scSides->__get(i) == cside))))){
			HX_STACK_LINE(116)
			(ccount)++;
		}
		HX_STACK_LINE(118)
		(i)++;
	}
	HX_STACK_LINE(121)
	return ccount;
}


HX_DEFINE_DYNAMIC_FUNC3(Scenario_obj,getCount,return )

Void Scenario_obj::findPath( int cfromx,int cfromy,int ctox,int ctoy,int cinit,Array< int > cresults){
{
		HX_STACK_FRAME("tenblock.Scenario","findPath",0xa928745e,"tenblock.Scenario.findPath","tenblock/Scenario.hx",125,0x96d1a28f)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cfromx,"cfromx")
		HX_STACK_ARG(cfromy,"cfromy")
		HX_STACK_ARG(ctox,"ctox")
		HX_STACK_ARG(ctoy,"ctoy")
		HX_STACK_ARG(cinit,"cinit")
		HX_STACK_ARG(cresults,"cresults")
		HX_STACK_LINE(127)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(128)
		int j;		HX_STACK_VAR(j,"j");
		HX_STACK_LINE(129)
		int k;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(130)
		int l;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(131)
		int cweight;		HX_STACK_VAR(cweight,"cweight");
		HX_STACK_LINE(133)
		int x1;		HX_STACK_VAR(x1,"x1");
		HX_STACK_LINE(134)
		int y1;		HX_STACK_VAR(y1,"y1");
		HX_STACK_LINE(136)
		int ccount;		HX_STACK_VAR(ccount,"ccount");
		HX_STACK_LINE(137)
		int cmax;		HX_STACK_VAR(cmax,"cmax");
		HX_STACK_LINE(139)
		Array< int > _g = Array_obj< int >::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(139)
		this->csrX = _g;
		HX_STACK_LINE(140)
		Array< int > _g1 = Array_obj< int >::__new();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(140)
		this->csrY = _g1;
		HX_STACK_LINE(141)
		Array< int > _g2 = Array_obj< int >::__new();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(141)
		this->csrFlag = _g2;
		HX_STACK_LINE(142)
		Array< int > _g3 = Array_obj< int >::__new();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(142)
		this->csrWeight = _g3;
		HX_STACK_LINE(143)
		Array< int > _g4 = Array_obj< int >::__new();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(143)
		this->csrAnc = _g4;
		HX_STACK_LINE(145)
		this->csrX[(int)0] = cfromx;
		HX_STACK_LINE(146)
		this->csrY[(int)0] = cfromy;
		HX_STACK_LINE(147)
		this->csrFlag[(int)0] = (int)1;
		HX_STACK_LINE(148)
		this->csrWeight[(int)0] = cinit;
		HX_STACK_LINE(149)
		this->csrAnc[(int)0] = (int)-1;
		HX_STACK_LINE(151)
		cresults[(int)0] = (int)-1;
		HX_STACK_LINE(152)
		cresults[(int)1] = (int)-1;
		HX_STACK_LINE(153)
		cresults[(int)2] = (int)9999;
		HX_STACK_LINE(155)
		x1 = (int)0;
		HX_STACK_LINE(156)
		y1 = (int)0;
		HX_STACK_LINE(157)
		l = (int)0;
		HX_STACK_LINE(159)
		while((true)){
			HX_STACK_LINE(161)
			ccount = (int)0;
			HX_STACK_LINE(162)
			cmax = this->csrX->length;
			HX_STACK_LINE(164)
			k = (int)0;
			HX_STACK_LINE(165)
			while((true)){
				HX_STACK_LINE(165)
				if ((!(((k < cmax))))){
					HX_STACK_LINE(165)
					break;
				}
				HX_STACK_LINE(167)
				if (((this->csrFlag->__get(k) == (int)0))){
					HX_STACK_LINE(167)
					this->csrFlag[k] = (int)1;
				}
				HX_STACK_LINE(168)
				(k)++;
			}
			HX_STACK_LINE(171)
			k = (int)0;
			HX_STACK_LINE(173)
			while((true)){
				HX_STACK_LINE(173)
				if ((!(((k < cmax))))){
					HX_STACK_LINE(173)
					break;
				}
				HX_STACK_LINE(175)
				cweight = (int)9999;
				HX_STACK_LINE(176)
				j = (int)0;
				HX_STACK_LINE(177)
				i = k;
				HX_STACK_LINE(178)
				(k)++;
				HX_STACK_LINE(180)
				if (((bool((bool((this->csrX->__get(i) == ctox)) && bool((this->csrY->__get(i) == ctoy)))) && bool((this->csrWeight->__get(i) <= cresults->__get((int)2)))))){
					HX_STACK_LINE(182)
					cresults[(int)0] = this->csrX->__get(this->csrAnc->__get(i));
					HX_STACK_LINE(183)
					cresults[(int)1] = this->csrY->__get(this->csrAnc->__get(i));
					HX_STACK_LINE(184)
					cresults[(int)2] = this->csrWeight->__get(i);
				}
				else{
					HX_STACK_LINE(186)
					if (((this->csrFlag->__get(i) == (int)1))){
						HX_STACK_LINE(188)
						this->csrFlag[i] = (int)-1;
						HX_STACK_LINE(189)
						j = (int)0;
						HX_STACK_LINE(191)
						while((true)){
							HX_STACK_LINE(191)
							if ((!(((j < (int)6))))){
								HX_STACK_LINE(191)
								break;
							}
							HX_STACK_LINE(193)
							if (((bool((j == (int)0)) || bool((j == (int)4))))){
								HX_STACK_LINE(195)
								if (((hx::Mod(this->csrY->__get(i),(int)2) == (int)0))){
									HX_STACK_LINE(196)
									x1 = this->csrX->__get(i);
								}
								else{
									HX_STACK_LINE(198)
									x1 = (this->csrX->__get(i) - (int)1);
								}
							}
							else{
								HX_STACK_LINE(200)
								if (((j == (int)2))){
									HX_STACK_LINE(201)
									x1 = (this->csrX->__get(i) - (int)1);
								}
								else{
									HX_STACK_LINE(202)
									if (((j == (int)3))){
										HX_STACK_LINE(203)
										x1 = (this->csrX->__get(i) + (int)1);
									}
									else{
										HX_STACK_LINE(204)
										if (((bool((j == (int)1)) || bool((j == (int)5))))){
											HX_STACK_LINE(206)
											if (((hx::Mod(this->csrY->__get(i),(int)2) == (int)0))){
												HX_STACK_LINE(207)
												x1 = (this->csrX->__get(i) + (int)1);
											}
											else{
												HX_STACK_LINE(209)
												x1 = this->csrX->__get(i);
											}
										}
									}
								}
							}
							HX_STACK_LINE(212)
							if (((bool((j == (int)0)) || bool((j == (int)1))))){
								HX_STACK_LINE(213)
								y1 = (this->csrY->__get(i) - (int)1);
							}
							else{
								HX_STACK_LINE(214)
								if (((bool((j == (int)2)) || bool((j == (int)3))))){
									HX_STACK_LINE(215)
									y1 = this->csrY->__get(i);
								}
								else{
									HX_STACK_LINE(217)
									y1 = (this->csrY->__get(i) + (int)1);
								}
							}
							HX_STACK_LINE(219)
							if (((  ((this->scMap->isValid(x1,y1,HX_CSTRING("test")))) ? bool((this->csrWeight->__get(i) < (int)4)) : bool(false) ))){
								HX_STACK_LINE(222)
								int _g5 = this->getNode(x1,y1,(this->csrWeight->__get(i) + (int)1));		HX_STACK_VAR(_g5,"_g5");
								HX_STACK_LINE(222)
								l = _g5;
								HX_STACK_LINE(223)
								if (((l != (int)-1))){
									HX_STACK_LINE(225)
									this->csrX[l] = x1;
									HX_STACK_LINE(226)
									this->csrY[l] = y1;
									HX_STACK_LINE(227)
									this->csrFlag[l] = (int)0;
									HX_STACK_LINE(228)
									this->csrWeight[l] = (this->csrWeight->__get(i) + (int)1);
									HX_STACK_LINE(229)
									this->csrAnc[l] = i;
									HX_STACK_LINE(230)
									ccount = (int)1;
								}
							}
							HX_STACK_LINE(234)
							(j)++;
						}
					}
				}
			}
			HX_STACK_LINE(159)
			if ((!(((ccount > (int)0))))){
				HX_STACK_LINE(159)
				break;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(Scenario_obj,findPath,(void))

int Scenario_obj::getNode( int cx,int cy,int cweight){
	HX_STACK_FRAME("tenblock.Scenario","getNode",0xca1913d8,"tenblock.Scenario.getNode","tenblock/Scenario.hx",243,0x96d1a28f)
	HX_STACK_THIS(this)
	HX_STACK_ARG(cx,"cx")
	HX_STACK_ARG(cy,"cy")
	HX_STACK_ARG(cweight,"cweight")
	HX_STACK_LINE(244)
	int i;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(246)
	i = (int)0;
	HX_STACK_LINE(248)
	while((true)){
		HX_STACK_LINE(248)
		if ((!(((i < this->csrX->length))))){
			HX_STACK_LINE(248)
			break;
		}
		HX_STACK_LINE(250)
		if (((bool((bool((this->csrX->__get(i) == cx)) && bool((this->csrY->__get(i) == cy)))) && bool((this->csrWeight->__get(i) > cweight))))){
			HX_STACK_LINE(251)
			return i;
		}
		HX_STACK_LINE(252)
		if (((bool((bool((this->csrX->__get(i) == cx)) && bool((this->csrY->__get(i) == cy)))) && bool((this->csrWeight->__get(i) < cweight))))){
			HX_STACK_LINE(253)
			return (int)-1;
		}
		HX_STACK_LINE(255)
		(i)++;
	}
	HX_STACK_LINE(258)
	i = (int)0;
	HX_STACK_LINE(260)
	while((true)){
		HX_STACK_LINE(260)
		if ((!(((i < this->scCounters->length))))){
			HX_STACK_LINE(260)
			break;
		}
		HX_STACK_LINE(262)
		if (((bool((this->scX->__get(i) == cx)) && bool((this->scY->__get(i) == cy))))){
			HX_STACK_LINE(263)
			return (int)-1;
		}
		HX_STACK_LINE(265)
		(i)++;
	}
	HX_STACK_LINE(268)
	return this->csrX->length;
}


HX_DEFINE_DYNAMIC_FUNC3(Scenario_obj,getNode,return )


Scenario_obj::Scenario_obj()
{
}

void Scenario_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Scenario);
	HX_MARK_MEMBER_NAME(scName,"scName");
	HX_MARK_MEMBER_NAME(scNames,"scNames");
	HX_MARK_MEMBER_NAME(scSides,"scSides");
	HX_MARK_MEMBER_NAME(scStartX,"scStartX");
	HX_MARK_MEMBER_NAME(scStartY,"scStartY");
	HX_MARK_MEMBER_NAME(scCounters,"scCounters");
	HX_MARK_MEMBER_NAME(csrX,"csrX");
	HX_MARK_MEMBER_NAME(csrY,"csrY");
	HX_MARK_MEMBER_NAME(csrFlag,"csrFlag");
	HX_MARK_MEMBER_NAME(csrWeight,"csrWeight");
	HX_MARK_MEMBER_NAME(csrAnc,"csrAnc");
	HX_MARK_MEMBER_NAME(scX,"scX");
	HX_MARK_MEMBER_NAME(scY,"scY");
	HX_MARK_MEMBER_NAME(scPack,"scPack");
	HX_MARK_MEMBER_NAME(scMap,"scMap");
	HX_MARK_MEMBER_NAME(scCanvas,"scCanvas");
	HX_MARK_MEMBER_NAME(scCount,"scCount");
	HX_MARK_END_CLASS();
}

void Scenario_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(scName,"scName");
	HX_VISIT_MEMBER_NAME(scNames,"scNames");
	HX_VISIT_MEMBER_NAME(scSides,"scSides");
	HX_VISIT_MEMBER_NAME(scStartX,"scStartX");
	HX_VISIT_MEMBER_NAME(scStartY,"scStartY");
	HX_VISIT_MEMBER_NAME(scCounters,"scCounters");
	HX_VISIT_MEMBER_NAME(csrX,"csrX");
	HX_VISIT_MEMBER_NAME(csrY,"csrY");
	HX_VISIT_MEMBER_NAME(csrFlag,"csrFlag");
	HX_VISIT_MEMBER_NAME(csrWeight,"csrWeight");
	HX_VISIT_MEMBER_NAME(csrAnc,"csrAnc");
	HX_VISIT_MEMBER_NAME(scX,"scX");
	HX_VISIT_MEMBER_NAME(scY,"scY");
	HX_VISIT_MEMBER_NAME(scPack,"scPack");
	HX_VISIT_MEMBER_NAME(scMap,"scMap");
	HX_VISIT_MEMBER_NAME(scCanvas,"scCanvas");
	HX_VISIT_MEMBER_NAME(scCount,"scCount");
}

Dynamic Scenario_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"scX") ) { return scX; }
		if (HX_FIELD_EQ(inName,"scY") ) { return scY; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"csrX") ) { return csrX; }
		if (HX_FIELD_EQ(inName,"csrY") ) { return csrY; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"scMap") ) { return scMap; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"scName") ) { return scName; }
		if (HX_FIELD_EQ(inName,"csrAnc") ) { return csrAnc; }
		if (HX_FIELD_EQ(inName,"scPack") ) { return scPack; }
		if (HX_FIELD_EQ(inName,"doDraw") ) { return doDraw_dyn(); }
		if (HX_FIELD_EQ(inName,"setCMP") ) { return setCMP_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"scNames") ) { return scNames; }
		if (HX_FIELD_EQ(inName,"scSides") ) { return scSides; }
		if (HX_FIELD_EQ(inName,"csrFlag") ) { return csrFlag; }
		if (HX_FIELD_EQ(inName,"scCount") ) { return scCount; }
		if (HX_FIELD_EQ(inName,"getNode") ) { return getNode_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"scStartX") ) { return scStartX; }
		if (HX_FIELD_EQ(inName,"scStartY") ) { return scStartY; }
		if (HX_FIELD_EQ(inName,"scCanvas") ) { return scCanvas; }
		if (HX_FIELD_EQ(inName,"getCount") ) { return getCount_dyn(); }
		if (HX_FIELD_EQ(inName,"findPath") ) { return findPath_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"csrWeight") ) { return csrWeight; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"scCounters") ) { return scCounters; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Scenario_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"scX") ) { scX=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scY") ) { scY=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"csrX") ) { csrX=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"csrY") ) { csrY=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"scMap") ) { scMap=inValue.Cast< ::tenblock::GameMap >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"scName") ) { scName=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"csrAnc") ) { csrAnc=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scPack") ) { scPack=inValue.Cast< ::tenblock::SpritePack >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"scNames") ) { scNames=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scSides") ) { scSides=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"csrFlag") ) { csrFlag=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scCount") ) { scCount=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"scStartX") ) { scStartX=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scStartY") ) { scStartY=inValue.Cast< Array< int > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scCanvas") ) { scCanvas=inValue.Cast< ::openfl::display::Sprite >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"csrWeight") ) { csrWeight=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"scCounters") ) { scCounters=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Scenario_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("scName"));
	outFields->push(HX_CSTRING("scNames"));
	outFields->push(HX_CSTRING("scSides"));
	outFields->push(HX_CSTRING("scStartX"));
	outFields->push(HX_CSTRING("scStartY"));
	outFields->push(HX_CSTRING("scCounters"));
	outFields->push(HX_CSTRING("csrX"));
	outFields->push(HX_CSTRING("csrY"));
	outFields->push(HX_CSTRING("csrFlag"));
	outFields->push(HX_CSTRING("csrWeight"));
	outFields->push(HX_CSTRING("csrAnc"));
	outFields->push(HX_CSTRING("scX"));
	outFields->push(HX_CSTRING("scY"));
	outFields->push(HX_CSTRING("scPack"));
	outFields->push(HX_CSTRING("scMap"));
	outFields->push(HX_CSTRING("scCanvas"));
	outFields->push(HX_CSTRING("scCount"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsString,(int)offsetof(Scenario_obj,scName),HX_CSTRING("scName")},
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(Scenario_obj,scNames),HX_CSTRING("scNames")},
	{hx::fsObject /*Array< ::String >*/ ,(int)offsetof(Scenario_obj,scSides),HX_CSTRING("scSides")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(Scenario_obj,scStartX),HX_CSTRING("scStartX")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(Scenario_obj,scStartY),HX_CSTRING("scStartY")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Scenario_obj,scCounters),HX_CSTRING("scCounters")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(Scenario_obj,csrX),HX_CSTRING("csrX")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(Scenario_obj,csrY),HX_CSTRING("csrY")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(Scenario_obj,csrFlag),HX_CSTRING("csrFlag")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(Scenario_obj,csrWeight),HX_CSTRING("csrWeight")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(Scenario_obj,csrAnc),HX_CSTRING("csrAnc")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(Scenario_obj,scX),HX_CSTRING("scX")},
	{hx::fsObject /*Array< int >*/ ,(int)offsetof(Scenario_obj,scY),HX_CSTRING("scY")},
	{hx::fsObject /*::tenblock::SpritePack*/ ,(int)offsetof(Scenario_obj,scPack),HX_CSTRING("scPack")},
	{hx::fsObject /*::tenblock::GameMap*/ ,(int)offsetof(Scenario_obj,scMap),HX_CSTRING("scMap")},
	{hx::fsObject /*::openfl::display::Sprite*/ ,(int)offsetof(Scenario_obj,scCanvas),HX_CSTRING("scCanvas")},
	{hx::fsInt,(int)offsetof(Scenario_obj,scCount),HX_CSTRING("scCount")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("scName"),
	HX_CSTRING("scNames"),
	HX_CSTRING("scSides"),
	HX_CSTRING("scStartX"),
	HX_CSTRING("scStartY"),
	HX_CSTRING("scCounters"),
	HX_CSTRING("csrX"),
	HX_CSTRING("csrY"),
	HX_CSTRING("csrFlag"),
	HX_CSTRING("csrWeight"),
	HX_CSTRING("csrAnc"),
	HX_CSTRING("scX"),
	HX_CSTRING("scY"),
	HX_CSTRING("scPack"),
	HX_CSTRING("scMap"),
	HX_CSTRING("scCanvas"),
	HX_CSTRING("scCount"),
	HX_CSTRING("doDraw"),
	HX_CSTRING("setCMP"),
	HX_CSTRING("getCount"),
	HX_CSTRING("findPath"),
	HX_CSTRING("getNode"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Scenario_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Scenario_obj::__mClass,"__mClass");
};

#endif

Class Scenario_obj::__mClass;

void Scenario_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tenblock.Scenario"), hx::TCanCast< Scenario_obj> ,sStaticFields,sMemberFields,
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

void Scenario_obj::__boot()
{
}

} // end namespace tenblock
