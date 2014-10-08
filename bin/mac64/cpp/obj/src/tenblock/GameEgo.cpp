#include <hxcpp.h>

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
#ifndef INCLUDED_tenblock_GameEgo
#include <tenblock/GameEgo.h>
#endif
#ifndef INCLUDED_tenblock_GameSprite
#include <tenblock/GameSprite.h>
#endif
namespace tenblock{

Void GameEgo_obj::__construct(::openfl::display::Bitmap csheet,::String cname,::String ctype,int cx,int cy,int cwd,int cht)
{
HX_STACK_FRAME("tenblock.GameEgo","new",0xb630b82f,"tenblock.GameEgo.new","tenblock/GameEgo.hx",20,0xa4200d62)
HX_STACK_THIS(this)
HX_STACK_ARG(csheet,"csheet")
HX_STACK_ARG(cname,"cname")
HX_STACK_ARG(ctype,"ctype")
HX_STACK_ARG(cx,"cx")
HX_STACK_ARG(cy,"cy")
HX_STACK_ARG(cwd,"cwd")
HX_STACK_ARG(cht,"cht")
{
	HX_STACK_LINE(21)
	super::__construct(csheet,cname,ctype,cx,cy,cwd,cht);
	HX_STACK_LINE(22)
	this->egMax = (int)3;
	HX_STACK_LINE(23)
	this->egSpeed = (int)0;
}
;
	return null();
}

//GameEgo_obj::~GameEgo_obj() { }

Dynamic GameEgo_obj::__CreateEmpty() { return  new GameEgo_obj; }
hx::ObjectPtr< GameEgo_obj > GameEgo_obj::__new(::openfl::display::Bitmap csheet,::String cname,::String ctype,int cx,int cy,int cwd,int cht)
{  hx::ObjectPtr< GameEgo_obj > result = new GameEgo_obj();
	result->__construct(csheet,cname,ctype,cx,cy,cwd,cht);
	return result;}

Dynamic GameEgo_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< GameEgo_obj > result = new GameEgo_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5],inArgs[6]);
	return result;}

Void GameEgo_obj::setStrike( ::tenblock::GameSprite cstrike){
{
		HX_STACK_FRAME("tenblock.GameEgo","setStrike",0x71b6c883,"tenblock.GameEgo.setStrike","tenblock/GameEgo.hx",28,0xa4200d62)
		HX_STACK_THIS(this)
		HX_STACK_ARG(cstrike,"cstrike")
		HX_STACK_LINE(28)
		this->egStrike = cstrike;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameEgo_obj,setStrike,(void))

Void GameEgo_obj::sendCode( int ccode){
{
		HX_STACK_FRAME("tenblock.GameEgo","sendCode",0x96701866,"tenblock.GameEgo.sendCode","tenblock/GameEgo.hx",35,0xa4200d62)
		HX_STACK_THIS(this)
		HX_STACK_ARG(ccode,"ccode")
		HX_STACK_LINE(35)
		if (((ccode == (int)39))){
			struct _Function_2_1{
				inline static bool Block( hx::ObjectPtr< ::tenblock::GameEgo_obj > __this){
					HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","tenblock/GameEgo.hx",37,0xa4200d62)
					{
						HX_STACK_LINE(37)
						int _g = __this->getDir();		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(37)
						return (_g == (int)0);
					}
					return null();
				}
			};
			HX_STACK_LINE(37)
			if (((  (((this->egSpeed == this->egMax))) ? bool(_Function_2_1::Block(this)) : bool(false) ))){
				HX_STACK_LINE(38)
				this->egSpeed = (int)0;
			}
			else{
				HX_STACK_LINE(40)
				this->egSpeed = this->egMax;
			}
			HX_STACK_LINE(42)
			this->setDir((int)0);
		}
		else{
			HX_STACK_LINE(44)
			if (((ccode == (int)40))){
				struct _Function_3_1{
					inline static bool Block( hx::ObjectPtr< ::tenblock::GameEgo_obj > __this){
						HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","tenblock/GameEgo.hx",46,0xa4200d62)
						{
							HX_STACK_LINE(46)
							int _g1 = __this->getDir();		HX_STACK_VAR(_g1,"_g1");
							HX_STACK_LINE(46)
							return (_g1 == (int)1);
						}
						return null();
					}
				};
				HX_STACK_LINE(46)
				if (((  (((this->egSpeed == this->egMax))) ? bool(_Function_3_1::Block(this)) : bool(false) ))){
					HX_STACK_LINE(47)
					this->egSpeed = (int)0;
				}
				else{
					HX_STACK_LINE(49)
					this->egSpeed = this->egMax;
				}
				HX_STACK_LINE(51)
				this->setDir((int)1);
			}
			else{
				HX_STACK_LINE(53)
				if (((ccode == (int)37))){
					struct _Function_4_1{
						inline static bool Block( hx::ObjectPtr< ::tenblock::GameEgo_obj > __this){
							HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","tenblock/GameEgo.hx",55,0xa4200d62)
							{
								HX_STACK_LINE(55)
								int _g2 = __this->getDir();		HX_STACK_VAR(_g2,"_g2");
								HX_STACK_LINE(55)
								return (_g2 == (int)2);
							}
							return null();
						}
					};
					HX_STACK_LINE(55)
					if (((  (((this->egSpeed == this->egMax))) ? bool(_Function_4_1::Block(this)) : bool(false) ))){
						HX_STACK_LINE(56)
						this->egSpeed = (int)0;
					}
					else{
						HX_STACK_LINE(58)
						this->egSpeed = this->egMax;
					}
					HX_STACK_LINE(60)
					this->setDir((int)2);
				}
				else{
					HX_STACK_LINE(62)
					if (((ccode == (int)38))){
						struct _Function_5_1{
							inline static bool Block( hx::ObjectPtr< ::tenblock::GameEgo_obj > __this){
								HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","tenblock/GameEgo.hx",64,0xa4200d62)
								{
									HX_STACK_LINE(64)
									int _g3 = __this->getDir();		HX_STACK_VAR(_g3,"_g3");
									HX_STACK_LINE(64)
									return (_g3 == (int)3);
								}
								return null();
							}
						};
						HX_STACK_LINE(64)
						if (((  (((this->egSpeed == this->egMax))) ? bool(_Function_5_1::Block(this)) : bool(false) ))){
							HX_STACK_LINE(65)
							this->egSpeed = (int)0;
						}
						else{
							HX_STACK_LINE(67)
							this->egSpeed = this->egMax;
						}
						HX_STACK_LINE(69)
						this->setDir((int)3);
					}
					else{
						HX_STACK_LINE(71)
						if (((bool((ccode == (int)13)) || bool((ccode == (int)32))))){
							HX_STACK_LINE(73)
							int _g4 = this->getX();		HX_STACK_VAR(_g4,"_g4");
							HX_STACK_LINE(73)
							if (((_g4 != (int)-100))){
								HX_STACK_LINE(75)
								this->egSpeed = (int)0;
								HX_STACK_LINE(76)
								int _g5 = this->getDir();		HX_STACK_VAR(_g5,"_g5");
								HX_STACK_LINE(76)
								this->egStrike->setDir(_g5);
								HX_STACK_LINE(78)
								int _g6 = this->egStrike->getDir();		HX_STACK_VAR(_g6,"_g6");
								HX_STACK_LINE(78)
								if (((_g6 == (int)0))){
									HX_STACK_LINE(79)
									int _g7 = this->getX();		HX_STACK_VAR(_g7,"_g7");
									HX_STACK_LINE(79)
									int _g8 = (_g7 + (int)8);		HX_STACK_VAR(_g8,"_g8");
									HX_STACK_LINE(79)
									int _g9 = this->getY();		HX_STACK_VAR(_g9,"_g9");
									HX_STACK_LINE(79)
									int _g10 = (_g9 - (int)20);		HX_STACK_VAR(_g10,"_g10");
									HX_STACK_LINE(79)
									this->egStrike->drawAt(_g8,_g10);
								}
								else{
									HX_STACK_LINE(80)
									int _g11 = this->egStrike->getDir();		HX_STACK_VAR(_g11,"_g11");
									HX_STACK_LINE(80)
									if (((_g11 == (int)1))){
										HX_STACK_LINE(81)
										int _g12 = this->getX();		HX_STACK_VAR(_g12,"_g12");
										HX_STACK_LINE(81)
										int _g13 = (_g12 - (int)7);		HX_STACK_VAR(_g13,"_g13");
										HX_STACK_LINE(81)
										int _g14 = this->getY();		HX_STACK_VAR(_g14,"_g14");
										HX_STACK_LINE(81)
										this->egStrike->drawAt(_g13,_g14);
									}
									else{
										HX_STACK_LINE(82)
										int _g15 = this->egStrike->getDir();		HX_STACK_VAR(_g15,"_g15");
										HX_STACK_LINE(82)
										if (((_g15 == (int)2))){
											HX_STACK_LINE(83)
											int _g16 = this->getX();		HX_STACK_VAR(_g16,"_g16");
											HX_STACK_LINE(83)
											int _g17 = (_g16 - (int)22);		HX_STACK_VAR(_g17,"_g17");
											HX_STACK_LINE(83)
											int _g18 = this->getY();		HX_STACK_VAR(_g18,"_g18");
											HX_STACK_LINE(83)
											int _g19 = (_g18 - (int)20);		HX_STACK_VAR(_g19,"_g19");
											HX_STACK_LINE(83)
											this->egStrike->drawAt(_g17,_g19);
										}
										else{
											HX_STACK_LINE(84)
											int _g20 = this->egStrike->getDir();		HX_STACK_VAR(_g20,"_g20");
											HX_STACK_LINE(84)
											if (((_g20 == (int)3))){
												HX_STACK_LINE(85)
												int _g21 = this->getX();		HX_STACK_VAR(_g21,"_g21");
												HX_STACK_LINE(85)
												int _g22 = (_g21 - (int)10);		HX_STACK_VAR(_g22,"_g22");
												HX_STACK_LINE(85)
												int _g23 = this->getY();		HX_STACK_VAR(_g23,"_g23");
												HX_STACK_LINE(85)
												int _g24 = (_g23 - (int)24);		HX_STACK_VAR(_g24,"_g24");
												HX_STACK_LINE(85)
												this->egStrike->drawAt(_g22,_g24);
											}
										}
									}
								}
								HX_STACK_LINE(89)
								this->set_visible(false);
							}
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(GameEgo_obj,sendCode,(void))

Void GameEgo_obj::stopCode( ){
{
		HX_STACK_FRAME("tenblock.GameEgo","stopCode",0x555c6020,"tenblock.GameEgo.stopCode","tenblock/GameEgo.hx",96,0xa4200d62)
		HX_STACK_THIS(this)
		HX_STACK_LINE(97)
		this->doStop();
		HX_STACK_LINE(99)
		bool _g = this->get_visible();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(99)
		if (((_g == false))){
			HX_STACK_LINE(101)
			this->set_visible(true);
			HX_STACK_LINE(102)
			this->egStrike->set_x((int)-100);
			HX_STACK_LINE(103)
			this->egStrike->set_y((int)-100);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameEgo_obj,stopCode,(void))

Void GameEgo_obj::egoMove( ){
{
		HX_STACK_FRAME("tenblock.GameEgo","egoMove",0x473cf2cd,"tenblock.GameEgo.egoMove","tenblock/GameEgo.hx",137,0xa4200d62)
		HX_STACK_THIS(this)
		HX_STACK_LINE(138)
		::String ccode1;		HX_STACK_VAR(ccode1,"ccode1");
		HX_STACK_LINE(139)
		::String ccode2;		HX_STACK_VAR(ccode2,"ccode2");
		HX_STACK_LINE(141)
		int _g = this->getDir();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(141)
		::String _g1 = this->getMoveCode1(_g,true);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(141)
		ccode1 = _g1;
		HX_STACK_LINE(142)
		int _g2 = this->getDir();		HX_STACK_VAR(_g2,"_g2");
		HX_STACK_LINE(142)
		::String _g3 = this->getMoveCode2(_g2,true);		HX_STACK_VAR(_g3,"_g3");
		HX_STACK_LINE(142)
		ccode2 = _g3;
		HX_STACK_LINE(144)
		if (((  ((this->isGood(ccode1))) ? bool(this->isGood(ccode2)) : bool(false) ))){
			HX_STACK_LINE(146)
			int _g4 = this->getDir();		HX_STACK_VAR(_g4,"_g4");
			HX_STACK_LINE(146)
			if (((  (((_g4 == (int)0))) ? bool((this->egSpeed > (int)0)) : bool(false) ))){
				HX_STACK_LINE(148)
				this->doNextFrame();
				HX_STACK_LINE(149)
				Float _g5 = this->get_x();		HX_STACK_VAR(_g5,"_g5");
				HX_STACK_LINE(149)
				Float _g6 = this->getCanvas()->get_x();		HX_STACK_VAR(_g6,"_g6");
				HX_STACK_LINE(149)
				Float _g7 = (_g5 - _g6);		HX_STACK_VAR(_g7,"_g7");
				HX_STACK_LINE(149)
				if (((_g7 >= 633.))){
					HX_STACK_LINE(149)
					::openfl::display::Sprite _g8 = this->getCanvas();		HX_STACK_VAR(_g8,"_g8");
					HX_STACK_LINE(149)
					Float _g81 = _g8->get_x();		HX_STACK_VAR(_g81,"_g81");
					HX_STACK_LINE(149)
					Float _g9 = (_g81 - this->egSpeed);		HX_STACK_VAR(_g9,"_g9");
					HX_STACK_LINE(149)
					_g8->set_x(_g9);
				}
				HX_STACK_LINE(150)
				{
					HX_STACK_LINE(150)
					::tenblock::GameEgo _g8 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g8,"_g8");
					HX_STACK_LINE(150)
					Float _g10 = _g8->get_x();		HX_STACK_VAR(_g10,"_g10");
					HX_STACK_LINE(150)
					Float _g11 = (_g10 + this->egSpeed);		HX_STACK_VAR(_g11,"_g11");
					HX_STACK_LINE(150)
					_g8->set_x(_g11);
				}
			}
			else{
				HX_STACK_LINE(152)
				int _g12 = this->getDir();		HX_STACK_VAR(_g12,"_g12");
				HX_STACK_LINE(152)
				if (((  (((_g12 == (int)1))) ? bool((this->egSpeed > (int)0)) : bool(false) ))){
					HX_STACK_LINE(154)
					this->doNextFrame();
					HX_STACK_LINE(155)
					Float _g13 = this->get_y();		HX_STACK_VAR(_g13,"_g13");
					HX_STACK_LINE(155)
					Float _g14 = this->getCanvas()->get_y();		HX_STACK_VAR(_g14,"_g14");
					HX_STACK_LINE(155)
					Float _g15 = (_g13 - _g14);		HX_STACK_VAR(_g15,"_g15");
					HX_STACK_LINE(155)
					if (((_g15 >= 334.))){
						HX_STACK_LINE(155)
						::openfl::display::Sprite _g5 = this->getCanvas();		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(155)
						Float _g16 = _g5->get_y();		HX_STACK_VAR(_g16,"_g16");
						HX_STACK_LINE(155)
						Float _g17 = (_g16 - this->egSpeed);		HX_STACK_VAR(_g17,"_g17");
						HX_STACK_LINE(155)
						_g5->set_y(_g17);
					}
					HX_STACK_LINE(156)
					{
						HX_STACK_LINE(156)
						::tenblock::GameEgo _g5 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g5,"_g5");
						HX_STACK_LINE(156)
						Float _g18 = _g5->get_y();		HX_STACK_VAR(_g18,"_g18");
						HX_STACK_LINE(156)
						Float _g19 = (_g18 + this->egSpeed);		HX_STACK_VAR(_g19,"_g19");
						HX_STACK_LINE(156)
						_g5->set_y(_g19);
					}
				}
				else{
					HX_STACK_LINE(158)
					int _g20 = this->getDir();		HX_STACK_VAR(_g20,"_g20");
					HX_STACK_LINE(158)
					if (((  (((_g20 == (int)2))) ? bool((this->egSpeed > (int)0)) : bool(false) ))){
						HX_STACK_LINE(160)
						this->doNextFrame();
						HX_STACK_LINE(161)
						Float _g21 = this->getCanvas()->get_x();		HX_STACK_VAR(_g21,"_g21");
						HX_STACK_LINE(161)
						if (((_g21 < -(this->egSpeed)))){
							HX_STACK_LINE(161)
							::openfl::display::Sprite _g5 = this->getCanvas();		HX_STACK_VAR(_g5,"_g5");
							HX_STACK_LINE(161)
							Float _g22 = _g5->get_x();		HX_STACK_VAR(_g22,"_g22");
							HX_STACK_LINE(161)
							Float _g23 = (_g22 + this->egSpeed);		HX_STACK_VAR(_g23,"_g23");
							HX_STACK_LINE(161)
							_g5->set_x(_g23);
						}
						HX_STACK_LINE(162)
						{
							HX_STACK_LINE(162)
							::tenblock::GameEgo _g5 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g5,"_g5");
							HX_STACK_LINE(162)
							Float _g24 = _g5->get_x();		HX_STACK_VAR(_g24,"_g24");
							HX_STACK_LINE(162)
							Float _g25 = (_g24 - this->egSpeed);		HX_STACK_VAR(_g25,"_g25");
							HX_STACK_LINE(162)
							_g5->set_x(_g25);
						}
					}
					else{
						HX_STACK_LINE(164)
						int _g26 = this->getDir();		HX_STACK_VAR(_g26,"_g26");
						HX_STACK_LINE(164)
						if (((  (((_g26 == (int)3))) ? bool((this->egSpeed > (int)0)) : bool(false) ))){
							HX_STACK_LINE(166)
							this->doNextFrame();
							HX_STACK_LINE(167)
							Float _g27 = this->getCanvas()->get_y();		HX_STACK_VAR(_g27,"_g27");
							HX_STACK_LINE(167)
							if (((_g27 < -(this->egSpeed)))){
								HX_STACK_LINE(167)
								::openfl::display::Sprite _g5 = this->getCanvas();		HX_STACK_VAR(_g5,"_g5");
								HX_STACK_LINE(167)
								Float _g28 = _g5->get_y();		HX_STACK_VAR(_g28,"_g28");
								HX_STACK_LINE(167)
								Float _g29 = (_g28 + this->egSpeed);		HX_STACK_VAR(_g29,"_g29");
								HX_STACK_LINE(167)
								_g5->set_y(_g29);
							}
							HX_STACK_LINE(168)
							{
								HX_STACK_LINE(168)
								::tenblock::GameEgo _g5 = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g5,"_g5");
								HX_STACK_LINE(168)
								Float _g30 = _g5->get_y();		HX_STACK_VAR(_g30,"_g30");
								HX_STACK_LINE(168)
								Float _g31 = (_g30 - this->egSpeed);		HX_STACK_VAR(_g31,"_g31");
								HX_STACK_LINE(168)
								_g5->set_y(_g31);
							}
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(GameEgo_obj,egoMove,(void))


GameEgo_obj::GameEgo_obj()
{
}

void GameEgo_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(GameEgo);
	HX_MARK_MEMBER_NAME(egSpeed,"egSpeed");
	HX_MARK_MEMBER_NAME(egMax,"egMax");
	HX_MARK_MEMBER_NAME(egStrike,"egStrike");
	::tenblock::GameSprite_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void GameEgo_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(egSpeed,"egSpeed");
	HX_VISIT_MEMBER_NAME(egMax,"egMax");
	HX_VISIT_MEMBER_NAME(egStrike,"egStrike");
	::tenblock::GameSprite_obj::__Visit(HX_VISIT_ARG);
}

Dynamic GameEgo_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"egMax") ) { return egMax; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"egSpeed") ) { return egSpeed; }
		if (HX_FIELD_EQ(inName,"egoMove") ) { return egoMove_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"egStrike") ) { return egStrike; }
		if (HX_FIELD_EQ(inName,"sendCode") ) { return sendCode_dyn(); }
		if (HX_FIELD_EQ(inName,"stopCode") ) { return stopCode_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"setStrike") ) { return setStrike_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic GameEgo_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"egMax") ) { egMax=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"egSpeed") ) { egSpeed=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"egStrike") ) { egStrike=inValue.Cast< ::tenblock::GameSprite >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void GameEgo_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("egSpeed"));
	outFields->push(HX_CSTRING("egMax"));
	outFields->push(HX_CSTRING("egStrike"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(GameEgo_obj,egSpeed),HX_CSTRING("egSpeed")},
	{hx::fsInt,(int)offsetof(GameEgo_obj,egMax),HX_CSTRING("egMax")},
	{hx::fsObject /*::tenblock::GameSprite*/ ,(int)offsetof(GameEgo_obj,egStrike),HX_CSTRING("egStrike")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("egSpeed"),
	HX_CSTRING("egMax"),
	HX_CSTRING("egStrike"),
	HX_CSTRING("setStrike"),
	HX_CSTRING("sendCode"),
	HX_CSTRING("stopCode"),
	HX_CSTRING("egoMove"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(GameEgo_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(GameEgo_obj::__mClass,"__mClass");
};

#endif

Class GameEgo_obj::__mClass;

void GameEgo_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("tenblock.GameEgo"), hx::TCanCast< GameEgo_obj> ,sStaticFields,sMemberFields,
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

void GameEgo_obj::__boot()
{
}

} // end namespace tenblock
