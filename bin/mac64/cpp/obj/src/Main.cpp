#include <hxcpp.h>

#ifndef INCLUDED_Main
#include <Main.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_openfl_Assets
#include <openfl/Assets.h>
#endif
#ifndef INCLUDED_openfl_Lib
#include <openfl/Lib.h>
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
#ifndef INCLUDED_openfl_display_MovieClip
#include <openfl/display/MovieClip.h>
#endif
#ifndef INCLUDED_openfl_display_PixelSnapping
#include <openfl/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_openfl_display_Sprite
#include <openfl/display/Sprite.h>
#endif
#ifndef INCLUDED_openfl_display_Stage
#include <openfl/display/Stage.h>
#endif
#ifndef INCLUDED_openfl_display_StageAlign
#include <openfl/display/StageAlign.h>
#endif
#ifndef INCLUDED_openfl_display_StageDisplayState
#include <openfl/display/StageDisplayState.h>
#endif
#ifndef INCLUDED_openfl_display_StageScaleMode
#include <openfl/display/StageScaleMode.h>
#endif
#ifndef INCLUDED_openfl_events_Event
#include <openfl/events/Event.h>
#endif
#ifndef INCLUDED_openfl_events_EventDispatcher
#include <openfl/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_IEventDispatcher
#include <openfl/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_events_KeyboardEvent
#include <openfl/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_openfl_events_MouseEvent
#include <openfl/events/MouseEvent.h>
#endif
#ifndef INCLUDED_openfl_net_URLLoader
#include <openfl/net/URLLoader.h>
#endif
#ifndef INCLUDED_openfl_net_URLRequest
#include <openfl/net/URLRequest.h>
#endif
#ifndef INCLUDED_openfl_system_Capabilities
#include <openfl/system/Capabilities.h>
#endif
#ifndef INCLUDED_tenblock_CharSprite
#include <tenblock/CharSprite.h>
#endif
#ifndef INCLUDED_tenblock_GameEgo
#include <tenblock/GameEgo.h>
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

Void Main_obj::__construct()
{
HX_STACK_FRAME("Main","new",0x6616a5cb,"Main.new","Main.hx",135,0x087e5c05)
HX_STACK_THIS(this)
{
	HX_STACK_LINE(136)
	super::__construct();
	HX_STACK_LINE(137)
	this->addEventListener(::openfl::events::Event_obj::ADDED_TO_STAGE,this->added_dyn(),null(),null(),null());
}
;
	return null();
}

//Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hx::ObjectPtr< Main_obj > Main_obj::__new()
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Void Main_obj::resize( Dynamic e){
{
		HX_STACK_FRAME("Main","resize",0x39257969,"Main.resize","Main.hx",50,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(e,"e")
		HX_STACK_LINE(50)
		if ((!(this->inited))){
			HX_STACK_LINE(50)
			this->init();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,resize,(void))

Void Main_obj::init( ){
{
		HX_STACK_FRAME("Main","init",0xea732345,"Main.init","Main.hx",55,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(56)
		int dirs_0 = (int)2;		HX_STACK_VAR(dirs_0,"dirs_0");
		HX_STACK_LINE(56)
		int dirs_1 = (int)0;		HX_STACK_VAR(dirs_1,"dirs_1");
		HX_STACK_LINE(56)
		int dirs_2 = (int)1;		HX_STACK_VAR(dirs_2,"dirs_2");
		HX_STACK_LINE(56)
		int dirs_3 = (int)3;		HX_STACK_VAR(dirs_3,"dirs_3");
		HX_STACK_LINE(57)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(59)
		this->egoWidth = (int)65;
		HX_STACK_LINE(60)
		this->egoHeight = (int)75;
		HX_STACK_LINE(62)
		if ((this->inited)){
			HX_STACK_LINE(62)
			return null();
		}
		HX_STACK_LINE(63)
		this->inited = true;
		HX_STACK_LINE(65)
		this->get_stage()->set_scaleMode(::openfl::display::StageScaleMode_obj::NO_SCALE);
		HX_STACK_LINE(66)
		Float _g = ::openfl::system::Capabilities_obj::get_screenResolutionX();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(66)
		if (((_g == (int)13660))){
			HX_STACK_LINE(67)
			this->get_stage()->set_displayState(::openfl::display::StageDisplayState_obj::FULL_SCREEN);
		}
		else{
			HX_STACK_LINE(69)
			this->get_stage()->set_displayState(::openfl::display::StageDisplayState_obj::NORMAL);
		}
		HX_STACK_LINE(72)
		::tenblock::GameMap gameMap = ::tenblock::GameMap_obj::__new(HX_CSTRING("xml/gamemap.xml"));		HX_STACK_VAR(gameMap,"gameMap");
		HX_STACK_LINE(73)
		gameMap->setAnchorX((int)10);
		HX_STACK_LINE(74)
		gameMap->setAnchorY((int)0);
		HX_STACK_LINE(75)
		gameMap->setCanvas(hx::ObjectPtr<OBJ_>(this));
		HX_STACK_LINE(76)
		gameMap->drawMap();
		HX_STACK_LINE(78)
		::tenblock::SpritePack _g1 = ::tenblock::SpritePack_obj::__new(HX_CSTRING("xml/gamesprites.xml"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(78)
		this->sprPack = _g1;
		HX_STACK_LINE(79)
		::tenblock::Scenario _g2 = ::tenblock::Scenario_obj::__new(HX_CSTRING("xml/scenario1.xml"));		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(79)
		this->gameSc = _g2;
		HX_STACK_LINE(80)
		this->gameSc->setCMP(hx::ObjectPtr<OBJ_>(this),gameMap,this->sprPack);
		HX_STACK_LINE(81)
		this->gameSc->doDraw();
		HX_STACK_LINE(83)
		::openfl::display::Sprite _g3 = ::openfl::display::Sprite_obj::__new();		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(83)
		this->MainPl = _g3;
		HX_STACK_LINE(84)
		Array< ::Dynamic > _g4 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(84)
		this->gameImages = _g4;
		HX_STACK_LINE(85)
		Array< ::Dynamic > _g5 = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(85)
		this->gameMoves = _g5;
		HX_STACK_LINE(87)
		i = (int)0;
		HX_STACK_LINE(89)
		while((true)){
			HX_STACK_LINE(89)
			if ((!(((i < (int)100))))){
				HX_STACK_LINE(89)
				break;
			}
			HX_STACK_LINE(91)
			::openfl::display::BitmapData _g6 = ::openfl::Assets_obj::getBitmapData(HX_CSTRING("img/move.png"),null());		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(91)
			::openfl::display::Bitmap _g7 = ::openfl::display::Bitmap_obj::__new(_g6,null(),null());		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(91)
			this->gameMoves[i] = ::tenblock::GameSprite_obj::__new(_g7,HX_CSTRING("move1"),HX_CSTRING("move"),(int)3,(int)4,(int)65,(int)75);
			HX_STACK_LINE(92)
			this->gameMoves->__get(i).StaticCast< ::tenblock::GameSprite >()->setCanvas(hx::ObjectPtr<OBJ_>(this));
			HX_STACK_LINE(93)
			this->gameMoves->__get(i).StaticCast< ::tenblock::GameSprite >()->setMap(gameMap);
			HX_STACK_LINE(94)
			this->gameMoves->__get(i).StaticCast< ::tenblock::GameSprite >()->drawAt((int)-150,(int)-150);
			HX_STACK_LINE(96)
			(i)++;
		}
		HX_STACK_LINE(99)
		::openfl::display::BitmapData _g8 = ::openfl::Assets_obj::getBitmapData(HX_CSTRING("img/highlight.png"),null());		HX_STACK_VAR(_g8,"_g8");
		HX_STACK_LINE(99)
		::openfl::display::Bitmap _g9 = ::openfl::display::Bitmap_obj::__new(_g8,null(),null());		HX_STACK_VAR(_g9,"_g9");
		HX_STACK_LINE(99)
		::tenblock::GameEgo _g10 = ::tenblock::GameEgo_obj::__new(_g9,HX_CSTRING("ego1"),HX_CSTRING("ego"),(int)3,(int)4,(int)65,(int)75);		HX_STACK_VAR(_g10,"_g10");
		HX_STACK_LINE(99)
		this->gameEgo = _g10;
		HX_STACK_LINE(100)
		::openfl::display::BitmapData _g11 = ::openfl::Assets_obj::getBitmapData(HX_CSTRING("img/select.png"),null());		HX_STACK_VAR(_g11,"_g11");
		HX_STACK_LINE(100)
		::openfl::display::Bitmap _g12 = ::openfl::display::Bitmap_obj::__new(_g11,null(),null());		HX_STACK_VAR(_g12,"_g12");
		HX_STACK_LINE(100)
		::tenblock::GameSprite _g13 = ::tenblock::GameSprite_obj::__new(_g12,HX_CSTRING("estrike1"),HX_CSTRING("estrike"),(int)3,(int)4,(int)65,(int)75);		HX_STACK_VAR(_g13,"_g13");
		HX_STACK_LINE(100)
		this->gameEgoStrike = _g13;
		HX_STACK_LINE(105)
		this->gameEgo->setMap(gameMap);
		HX_STACK_LINE(107)
		this->gameEgo->setCanvas(hx::ObjectPtr<OBJ_>(this));
		HX_STACK_LINE(108)
		this->gameEgo->drawAt((int)350,(int)250);
		HX_STACK_LINE(116)
		this->gameEgoStrike->setCanvas(hx::ObjectPtr<OBJ_>(this));
		HX_STACK_LINE(117)
		this->gameEgoStrike->setMap(gameMap);
		HX_STACK_LINE(118)
		this->gameEgoStrike->drawAt((int)-100,(int)-100);
		HX_STACK_LINE(120)
		this->MainFr = (int)0;
		HX_STACK_LINE(122)
		this->gameTime = (int)0;
		HX_STACK_LINE(123)
		this->animTime = (int)1;
		HX_STACK_LINE(127)
		this->get_stage()->addEventListener(::openfl::events::MouseEvent_obj::MOUSE_MOVE,this->onMouseMove_dyn(),null(),null(),null());
		HX_STACK_LINE(128)
		this->get_stage()->addEventListener(::openfl::events::MouseEvent_obj::MOUSE_DOWN,this->onMouseDown_dyn(),null(),null(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,init,(void))

Void Main_obj::added( Dynamic e){
{
		HX_STACK_FRAME("Main","added",0x98771aeb,"Main.added","Main.hx",141,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(e,"e")
		HX_STACK_LINE(142)
		this->removeEventListener(::openfl::events::Event_obj::ADDED_TO_STAGE,this->added_dyn(),null());
		HX_STACK_LINE(143)
		this->get_stage()->addEventListener(::openfl::events::Event_obj::RESIZE,this->resize_dyn(),null(),null(),null());
		HX_STACK_LINE(147)
		this->init();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,added,(void))

Void Main_obj::doSpriteOrder( Array< ::Dynamic > csprs){
{
		HX_STACK_FRAME("Main","doSpriteOrder",0xe99de1a9,"Main.doSpriteOrder","Main.hx",160,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(csprs,"csprs")
		HX_STACK_LINE(161)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(162)
		int j;		HX_STACK_VAR(j,"j");
		HX_STACK_LINE(163)
		int k;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(164)
		int l;		HX_STACK_VAR(l,"l");
		HX_STACK_LINE(165)
		int cln;		HX_STACK_VAR(cln,"cln");
		HX_STACK_LINE(166)
		Array< int > cmark = Array_obj< int >::__new();		HX_STACK_VAR(cmark,"cmark");
		HX_STACK_LINE(168)
		i = (int)0;
		HX_STACK_LINE(169)
		while((true)){
			HX_STACK_LINE(169)
			if ((!(((i < csprs->length))))){
				HX_STACK_LINE(169)
				break;
			}
			HX_STACK_LINE(171)
			cmark[i] = (int)0;
			HX_STACK_LINE(172)
			(i)++;
		}
		HX_STACK_LINE(175)
		i = (int)1;
		HX_STACK_LINE(176)
		j = (int)0;
		HX_STACK_LINE(177)
		k = (int)-1;
		HX_STACK_LINE(178)
		l = (int)0;
		HX_STACK_LINE(180)
		while((true)){
			HX_STACK_LINE(180)
			if ((!(((l != (int)-1))))){
				HX_STACK_LINE(180)
				break;
			}
			HX_STACK_LINE(182)
			j = (int)0;
			HX_STACK_LINE(183)
			l = (int)-1;
			HX_STACK_LINE(185)
			while((true)){
				HX_STACK_LINE(185)
				if ((!(((j < csprs->length))))){
					HX_STACK_LINE(185)
					break;
				}
				HX_STACK_LINE(187)
				int _g = csprs->__get(j).StaticCast< ::tenblock::GameSprite >()->getFeetY();		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(187)
				if (((  (((_g > k))) ? bool((cmark->__get(j) == (int)0)) : bool(false) ))){
					HX_STACK_LINE(189)
					l = j;
					HX_STACK_LINE(190)
					int _g1 = csprs->__get(j).StaticCast< ::tenblock::GameSprite >()->getFeetY();		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(190)
					k = _g1;
				}
				HX_STACK_LINE(193)
				(j)++;
			}
			HX_STACK_LINE(196)
			if (((l != (int)-1))){
				HX_STACK_LINE(198)
				cmark[l] = (int)1;
				HX_STACK_LINE(199)
				int _g2 = this->get_numChildren();		HX_STACK_VAR(_g2,"_g2");
				HX_STACK_LINE(199)
				int _g3 = (_g2 - i);		HX_STACK_VAR(_g3,"_g3");
				HX_STACK_LINE(199)
				this->setChildIndex(csprs->__get(l).StaticCast< ::tenblock::GameSprite >(),_g3);
				HX_STACK_LINE(200)
				(i)++;
				HX_STACK_LINE(201)
				k = (int)-1;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,doSpriteOrder,(void))

Void Main_obj::this_onEnterFrame( ::openfl::events::Event event){
{
		HX_STACK_FRAME("Main","this_onEnterFrame",0x64786a60,"Main.this_onEnterFrame","Main.hx",209,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(209)
		if (((this->gameTime >= this->animTime))){
			HX_STACK_LINE(211)
			if (((this->animTime < this->gameTime))){
				HX_STACK_LINE(211)
				this->animTime = this->gameTime;
			}
			HX_STACK_LINE(213)
			(this->MainFr)++;
			HX_STACK_LINE(214)
			if (((this->MainFr > (int)3))){
				HX_STACK_LINE(214)
				this->MainFr = (int)0;
			}
			HX_STACK_LINE(218)
			if (((this->MainFr < (int)3))){
				HX_STACK_LINE(219)
				this->gameImages->__get((int)0).StaticCast< ::tenblock::GameSprite >()->set_x(-((((int)60 * this->MainFr))));
			}
			else{
				HX_STACK_LINE(221)
				this->gameImages->__get((int)0).StaticCast< ::tenblock::GameSprite >()->set_x(-((((int)60 * (((int)4 - this->MainFr))))));
			}
			HX_STACK_LINE(224)
			(this->animTime)++;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,this_onEnterFrame,(void))

Void Main_obj::stage_onKeyDown( ::openfl::events::KeyboardEvent event){
{
		HX_STACK_FRAME("Main","stage_onKeyDown",0xfd7eec2c,"Main.stage_onKeyDown","Main.hx",231,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(231)
		this->gameEgo->sendCode(event->keyCode);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,stage_onKeyDown,(void))

Void Main_obj::stage_onKeyUp( ::openfl::events::KeyboardEvent event){
{
		HX_STACK_FRAME("Main","stage_onKeyUp",0x131bf3a5,"Main.stage_onKeyUp","Main.hx",236,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(event,"event")
		HX_STACK_LINE(236)
		this->gameEgo->stopCode();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,stage_onKeyUp,(void))

Void Main_obj::_loadXML( ){
{
		HX_STACK_FRAME("Main","_loadXML",0x89a6cb87,"Main._loadXML","Main.hx",240,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_LINE(241)
		::haxe::Log_obj::trace(HX_CSTRING("Main._loadXML"),hx::SourceInfo(HX_CSTRING("Main.hx"),241,HX_CSTRING("Main"),HX_CSTRING("_loadXML")));
		HX_STACK_LINE(242)
		::openfl::net::URLLoader _g = ::openfl::net::URLLoader_obj::__new(null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(242)
		this->_xmlLoader = _g;
		HX_STACK_LINE(243)
		this->_xmlLoader->addEventListener(::openfl::events::Event_obj::COMPLETE,this->_onXMLLoaded_dyn(),null(),null(),null());
		HX_STACK_LINE(244)
		::openfl::net::URLRequest _g1 = ::openfl::net::URLRequest_obj::__new(HX_CSTRING("assets/xml/sample.xml"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(244)
		this->_xmlLoader->load(_g1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Main_obj,_loadXML,(void))

Void Main_obj::_onXMLLoaded( ::openfl::events::Event e){
{
		HX_STACK_FRAME("Main","_onXMLLoaded",0xa9dfbf53,"Main._onXMLLoaded","Main.hx",249,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(e,"e")
		HX_STACK_LINE(249)
		::haxe::Log_obj::trace(e->get_target()->__Field(HX_CSTRING("data"),true),hx::SourceInfo(HX_CSTRING("Main.hx"),249,HX_CSTRING("Main"),HX_CSTRING("_onXMLLoaded")));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,_onXMLLoaded,(void))

Void Main_obj::onMouseMove( ::openfl::events::MouseEvent e){
{
		HX_STACK_FRAME("Main","onMouseMove",0x15ff3722,"Main.onMouseMove","Main.hx",253,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(e,"e")
		HX_STACK_LINE(254)
		int cx;		HX_STACK_VAR(cx,"cx");
		HX_STACK_LINE(255)
		int cy;		HX_STACK_VAR(cy,"cy");
		HX_STACK_LINE(257)
		int _g = ::Std_obj::_int(e->stageX);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(257)
		int _g1 = ::Std_obj::_int(e->stageY);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(257)
		int _g2 = this->gameEgo->getMap()->getCoord(HX_CSTRING("x"),_g,_g1);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(257)
		cx = _g2;
		HX_STACK_LINE(258)
		int _g3 = ::Std_obj::_int(e->stageX);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(258)
		int _g4 = ::Std_obj::_int(e->stageY);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(258)
		int _g5 = this->gameEgo->getMap()->getCoord(HX_CSTRING("y"),_g3,_g4);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(258)
		cy = _g5;
		HX_STACK_LINE(260)
		if (((hx::Mod(cy,(int)2) == (int)0))){
			HX_STACK_LINE(261)
			int _g6 = ::Std_obj::_int((cy * 54.5));		HX_STACK_VAR(_g6,"_g6");
			HX_STACK_LINE(261)
			int _g7 = _g6;		HX_STACK_VAR(_g7,"_g7");
			HX_STACK_LINE(261)
			this->gameEgo->moveTo(((cx * (int)64) + (int)10),_g7);
		}
		else{
			HX_STACK_LINE(263)
			int _g8 = ::Std_obj::_int((cy * 54.5));		HX_STACK_VAR(_g8,"_g8");
			HX_STACK_LINE(263)
			int _g9 = _g8;		HX_STACK_VAR(_g9,"_g9");
			HX_STACK_LINE(263)
			this->gameEgo->moveTo((((cx * (int)64) + (int)10) - (int)32),_g9);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onMouseMove,(void))

Void Main_obj::onMouseDown( ::openfl::events::MouseEvent e){
{
		HX_STACK_FRAME("Main","onMouseDown",0x100c4c73,"Main.onMouseDown","Main.hx",267,0x087e5c05)
		HX_STACK_THIS(this)
		HX_STACK_ARG(e,"e")
		HX_STACK_LINE(268)
		Array< int > cresults;		HX_STACK_VAR(cresults,"cresults");
		HX_STACK_LINE(269)
		int i;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(270)
		int j;		HX_STACK_VAR(j,"j");
		HX_STACK_LINE(271)
		int k;		HX_STACK_VAR(k,"k");
		HX_STACK_LINE(273)
		int cx;		HX_STACK_VAR(cx,"cx");
		HX_STACK_LINE(274)
		int cy;		HX_STACK_VAR(cy,"cy");
		HX_STACK_LINE(276)
		Array< int > _g = Array_obj< int >::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(276)
		cresults = _g;
		HX_STACK_LINE(277)
		cresults[(int)0] = (int)-1;
		HX_STACK_LINE(278)
		cresults[(int)1] = (int)-1;
		HX_STACK_LINE(279)
		cresults[(int)2] = (int)9999;
		HX_STACK_LINE(281)
		int _g1 = ::Std_obj::_int(e->stageX);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(281)
		int _g2 = ::Std_obj::_int(e->stageY);		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(281)
		int _g3 = this->gameEgo->getMap()->getCoord(HX_CSTRING("x"),_g1,_g2);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(281)
		cx = _g3;
		HX_STACK_LINE(282)
		int _g4 = ::Std_obj::_int(e->stageX);		HX_STACK_VAR(_g4,"_g4");
		HX_STACK_LINE(282)
		int _g5 = ::Std_obj::_int(e->stageY);		HX_STACK_VAR(_g5,"_g5");
		HX_STACK_LINE(282)
		int _g6 = this->gameEgo->getMap()->getCoord(HX_CSTRING("y"),_g4,_g5);		HX_STACK_VAR(_g6,"_g6");
		HX_STACK_LINE(282)
		cy = _g6;
		HX_STACK_LINE(284)
		i = (int)0;
		HX_STACK_LINE(286)
		while((true)){
			HX_STACK_LINE(286)
			if ((!(((i < (int)100))))){
				HX_STACK_LINE(286)
				break;
			}
			HX_STACK_LINE(288)
			this->gameMoves->__get(i).StaticCast< ::tenblock::GameSprite >()->dropOnSq((int)-5,(int)-5);
			HX_STACK_LINE(289)
			(i)++;
		}
		HX_STACK_LINE(292)
		i = (cy - (int)3);
		HX_STACK_LINE(293)
		k = (int)0;
		HX_STACK_LINE(295)
		int _g7 = this->gameSc->getCount(cx,cy,HX_CSTRING("a"));		HX_STACK_VAR(_g7,"_g7");
		HX_STACK_LINE(295)
		if (((_g7 > (int)0))){
			HX_STACK_LINE(297)
			while((true)){
				HX_STACK_LINE(297)
				if ((!(((i < (cy + (int)3)))))){
					HX_STACK_LINE(297)
					break;
				}
				HX_STACK_LINE(299)
				j = (cx - (int)3);
				HX_STACK_LINE(300)
				while((true)){
					HX_STACK_LINE(300)
					if ((!(((j < (cx + (int)3)))))){
						HX_STACK_LINE(300)
						break;
					}
					HX_STACK_LINE(302)
					if (((bool((i == cy)) && bool((j == cx))))){
						HX_STACK_LINE(304)
						this->gameEgoStrike->dropOnSq(j,i);
						HX_STACK_LINE(305)
						(j)++;
					}
					else{
						HX_STACK_LINE(309)
						cresults[(int)0] = (int)-1;
						HX_STACK_LINE(310)
						cresults[(int)1] = (int)-1;
						HX_STACK_LINE(311)
						cresults[(int)2] = (int)9999;
						HX_STACK_LINE(313)
						this->gameSc->findPath(cx,cy,j,i,(int)0,cresults);
						HX_STACK_LINE(315)
						if (((cresults->__get((int)2) < (int)3))){
							HX_STACK_LINE(317)
							this->gameMoves->__get(k).StaticCast< ::tenblock::GameSprite >()->dropOnSq(j,i);
							HX_STACK_LINE(318)
							(k)++;
						}
						HX_STACK_LINE(321)
						(j)++;
					}
				}
				HX_STACK_LINE(324)
				(i)++;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Main_obj,onMouseDown,(void))

Void Main_obj::main( ){
{
		HX_STACK_FRAME("Main","main",0xed0e206e,"Main.main","Main.hx",152,0x087e5c05)
		HX_STACK_LINE(154)
		::openfl::Lib_obj::get_current()->get_stage()->set_align(::openfl::display::StageAlign_obj::TOP_LEFT);
		HX_STACK_LINE(155)
		::openfl::Lib_obj::get_current()->get_stage()->set_scaleMode(::openfl::display::StageScaleMode_obj::NO_SCALE);
		HX_STACK_LINE(156)
		::Main _g = ::Main_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(156)
		::openfl::Lib_obj::get_current()->addChild(_g);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Main_obj,main,(void))


Main_obj::Main_obj()
{
}

void Main_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Main);
	HX_MARK_MEMBER_NAME(inited,"inited");
	HX_MARK_MEMBER_NAME(gameImages,"gameImages");
	HX_MARK_MEMBER_NAME(gameMoves,"gameMoves");
	HX_MARK_MEMBER_NAME(MainPl,"MainPl");
	HX_MARK_MEMBER_NAME(MainFr,"MainFr");
	HX_MARK_MEMBER_NAME(gameTime,"gameTime");
	HX_MARK_MEMBER_NAME(animTime,"animTime");
	HX_MARK_MEMBER_NAME(doAnim,"doAnim");
	HX_MARK_MEMBER_NAME(gameEgo,"gameEgo");
	HX_MARK_MEMBER_NAME(gameEgoStrike,"gameEgoStrike");
	HX_MARK_MEMBER_NAME(gameMap,"gameMap");
	HX_MARK_MEMBER_NAME(sprPack,"sprPack");
	HX_MARK_MEMBER_NAME(gameSc,"gameSc");
	HX_MARK_MEMBER_NAME(egoWidth,"egoWidth");
	HX_MARK_MEMBER_NAME(egoHeight,"egoHeight");
	HX_MARK_MEMBER_NAME(_xmlLoader,"_xmlLoader");
	::openfl::display::DisplayObjectContainer_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Main_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(inited,"inited");
	HX_VISIT_MEMBER_NAME(gameImages,"gameImages");
	HX_VISIT_MEMBER_NAME(gameMoves,"gameMoves");
	HX_VISIT_MEMBER_NAME(MainPl,"MainPl");
	HX_VISIT_MEMBER_NAME(MainFr,"MainFr");
	HX_VISIT_MEMBER_NAME(gameTime,"gameTime");
	HX_VISIT_MEMBER_NAME(animTime,"animTime");
	HX_VISIT_MEMBER_NAME(doAnim,"doAnim");
	HX_VISIT_MEMBER_NAME(gameEgo,"gameEgo");
	HX_VISIT_MEMBER_NAME(gameEgoStrike,"gameEgoStrike");
	HX_VISIT_MEMBER_NAME(gameMap,"gameMap");
	HX_VISIT_MEMBER_NAME(sprPack,"sprPack");
	HX_VISIT_MEMBER_NAME(gameSc,"gameSc");
	HX_VISIT_MEMBER_NAME(egoWidth,"egoWidth");
	HX_VISIT_MEMBER_NAME(egoHeight,"egoHeight");
	HX_VISIT_MEMBER_NAME(_xmlLoader,"_xmlLoader");
	::openfl::display::DisplayObjectContainer_obj::__Visit(HX_VISIT_ARG);
}

Dynamic Main_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"added") ) { return added_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"inited") ) { return inited; }
		if (HX_FIELD_EQ(inName,"MainPl") ) { return MainPl; }
		if (HX_FIELD_EQ(inName,"MainFr") ) { return MainFr; }
		if (HX_FIELD_EQ(inName,"doAnim") ) { return doAnim; }
		if (HX_FIELD_EQ(inName,"gameSc") ) { return gameSc; }
		if (HX_FIELD_EQ(inName,"resize") ) { return resize_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"gameEgo") ) { return gameEgo; }
		if (HX_FIELD_EQ(inName,"gameMap") ) { return gameMap; }
		if (HX_FIELD_EQ(inName,"sprPack") ) { return sprPack; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"gameTime") ) { return gameTime; }
		if (HX_FIELD_EQ(inName,"animTime") ) { return animTime; }
		if (HX_FIELD_EQ(inName,"egoWidth") ) { return egoWidth; }
		if (HX_FIELD_EQ(inName,"_loadXML") ) { return _loadXML_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"gameMoves") ) { return gameMoves; }
		if (HX_FIELD_EQ(inName,"egoHeight") ) { return egoHeight; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"gameImages") ) { return gameImages; }
		if (HX_FIELD_EQ(inName,"_xmlLoader") ) { return _xmlLoader; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"onMouseMove") ) { return onMouseMove_dyn(); }
		if (HX_FIELD_EQ(inName,"onMouseDown") ) { return onMouseDown_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"_onXMLLoaded") ) { return _onXMLLoaded_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"gameEgoStrike") ) { return gameEgoStrike; }
		if (HX_FIELD_EQ(inName,"doSpriteOrder") ) { return doSpriteOrder_dyn(); }
		if (HX_FIELD_EQ(inName,"stage_onKeyUp") ) { return stage_onKeyUp_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"stage_onKeyDown") ) { return stage_onKeyDown_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"this_onEnterFrame") ) { return this_onEnterFrame_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Main_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"inited") ) { inited=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MainPl") ) { MainPl=inValue.Cast< ::openfl::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MainFr") ) { MainFr=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"doAnim") ) { doAnim=inValue.Cast< ::haxe::Timer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gameSc") ) { gameSc=inValue.Cast< ::tenblock::Scenario >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"gameEgo") ) { gameEgo=inValue.Cast< ::tenblock::GameEgo >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gameMap") ) { gameMap=inValue.Cast< ::tenblock::GameMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sprPack") ) { sprPack=inValue.Cast< ::tenblock::SpritePack >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"gameTime") ) { gameTime=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"animTime") ) { animTime=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"egoWidth") ) { egoWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"gameMoves") ) { gameMoves=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"egoHeight") ) { egoHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"gameImages") ) { gameImages=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_xmlLoader") ) { _xmlLoader=inValue.Cast< ::openfl::net::URLLoader >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"gameEgoStrike") ) { gameEgoStrike=inValue.Cast< ::tenblock::GameSprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Main_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("inited"));
	outFields->push(HX_CSTRING("gameImages"));
	outFields->push(HX_CSTRING("gameMoves"));
	outFields->push(HX_CSTRING("MainPl"));
	outFields->push(HX_CSTRING("MainFr"));
	outFields->push(HX_CSTRING("gameTime"));
	outFields->push(HX_CSTRING("animTime"));
	outFields->push(HX_CSTRING("doAnim"));
	outFields->push(HX_CSTRING("gameEgo"));
	outFields->push(HX_CSTRING("gameEgoStrike"));
	outFields->push(HX_CSTRING("gameMap"));
	outFields->push(HX_CSTRING("sprPack"));
	outFields->push(HX_CSTRING("gameSc"));
	outFields->push(HX_CSTRING("egoWidth"));
	outFields->push(HX_CSTRING("egoHeight"));
	outFields->push(HX_CSTRING("_xmlLoader"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("main"),
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsBool,(int)offsetof(Main_obj,inited),HX_CSTRING("inited")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Main_obj,gameImages),HX_CSTRING("gameImages")},
	{hx::fsObject /*Array< ::Dynamic >*/ ,(int)offsetof(Main_obj,gameMoves),HX_CSTRING("gameMoves")},
	{hx::fsObject /*::openfl::display::Sprite*/ ,(int)offsetof(Main_obj,MainPl),HX_CSTRING("MainPl")},
	{hx::fsInt,(int)offsetof(Main_obj,MainFr),HX_CSTRING("MainFr")},
	{hx::fsInt,(int)offsetof(Main_obj,gameTime),HX_CSTRING("gameTime")},
	{hx::fsInt,(int)offsetof(Main_obj,animTime),HX_CSTRING("animTime")},
	{hx::fsObject /*::haxe::Timer*/ ,(int)offsetof(Main_obj,doAnim),HX_CSTRING("doAnim")},
	{hx::fsObject /*::tenblock::GameEgo*/ ,(int)offsetof(Main_obj,gameEgo),HX_CSTRING("gameEgo")},
	{hx::fsObject /*::tenblock::GameSprite*/ ,(int)offsetof(Main_obj,gameEgoStrike),HX_CSTRING("gameEgoStrike")},
	{hx::fsObject /*::tenblock::GameMap*/ ,(int)offsetof(Main_obj,gameMap),HX_CSTRING("gameMap")},
	{hx::fsObject /*::tenblock::SpritePack*/ ,(int)offsetof(Main_obj,sprPack),HX_CSTRING("sprPack")},
	{hx::fsObject /*::tenblock::Scenario*/ ,(int)offsetof(Main_obj,gameSc),HX_CSTRING("gameSc")},
	{hx::fsInt,(int)offsetof(Main_obj,egoWidth),HX_CSTRING("egoWidth")},
	{hx::fsInt,(int)offsetof(Main_obj,egoHeight),HX_CSTRING("egoHeight")},
	{hx::fsObject /*::openfl::net::URLLoader*/ ,(int)offsetof(Main_obj,_xmlLoader),HX_CSTRING("_xmlLoader")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("inited"),
	HX_CSTRING("gameImages"),
	HX_CSTRING("gameMoves"),
	HX_CSTRING("MainPl"),
	HX_CSTRING("MainFr"),
	HX_CSTRING("gameTime"),
	HX_CSTRING("animTime"),
	HX_CSTRING("doAnim"),
	HX_CSTRING("gameEgo"),
	HX_CSTRING("gameEgoStrike"),
	HX_CSTRING("gameMap"),
	HX_CSTRING("sprPack"),
	HX_CSTRING("gameSc"),
	HX_CSTRING("egoWidth"),
	HX_CSTRING("egoHeight"),
	HX_CSTRING("_xmlLoader"),
	HX_CSTRING("resize"),
	HX_CSTRING("init"),
	HX_CSTRING("added"),
	HX_CSTRING("doSpriteOrder"),
	HX_CSTRING("this_onEnterFrame"),
	HX_CSTRING("stage_onKeyDown"),
	HX_CSTRING("stage_onKeyUp"),
	HX_CSTRING("_loadXML"),
	HX_CSTRING("_onXMLLoaded"),
	HX_CSTRING("onMouseMove"),
	HX_CSTRING("onMouseDown"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Main_obj::__mClass,"__mClass");
};

#endif

Class Main_obj::__mClass;

void Main_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Main"), hx::TCanCast< Main_obj> ,sStaticFields,sMemberFields,
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

void Main_obj::__boot()
{
}

