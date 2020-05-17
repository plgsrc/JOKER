#ifndef CHEATS_H
#define CHEATS_H

#include "CTRPluginFramework.hpp"
//#include "Helpers.hpp"
//#include "Unicode.h"

namespace CTRPluginFramework
{
	void	change_Player(MenuEntry *entry);
	void	Action1(MenuEntry *entry);
	void	Action2(MenuEntry *entry);
	void	Action3(MenuEntry *entry);
	void	Action4(MenuEntry *entry);
	void	Action5(MenuEntry *entry);
	void	Action6(MenuEntry *entry);
	void	Action7(MenuEntry *entry);
	void	Action8(MenuEntry *entry);
	void	Action9(MenuEntry *entry);
	void	Action10(MenuEntry *entry);
	void	Action11(MenuEntry *entry);
	void	Action12(MenuEntry *entry);
	void	Action13(MenuEntry *entry);
	void    Action14(MenuEntry *entry);
	void	Action15(MenuEntry *entry);
	void	Action16(MenuEntry *entry);
	void	Action18(MenuEntry *entry);
	void	Action19(MenuEntry *entry);
	void	Action20(MenuEntry *entry);
	void	Action22(MenuEntry *entry);
	void	Action23(MenuEntry *entry);
	void	Action24(MenuEntry *entry);
	void	Action25(MenuEntry *entry);
	void	Action26(MenuEntry *entry);
	void	Action27(MenuEntry *entry);
	void	Player1(MenuEntry *entry);
	void	Player2(MenuEntry *entry);
	void	Inventory1(MenuEntry *entry);
	void	Inventory2(MenuEntry *entry);
	void    Pose1(MenuEntry *entry);
	void    Pose2(MenuEntry *entry);
	void	Pose3(MenuEntry *entry);
	void	Pose4(MenuEntry *entry);
	void    Tools_1(MenuEntry *entry);
	void    Tools_2(MenuEntry *entry);
	void	change_engei(MenuEntry *entry);
	void	change_mametubu(MenuEntry *entry);
	void	change_uranai(MenuEntry *entry);
	void	change_yumemi(MenuEntry *entry);
	void	change_kurabu(MenuEntry *entry);
	void	change_biyouin(MenuEntry *entry);
	void	change_kutuya(MenuEntry *entry);
	void	change_hakubutukan(MenuEntry *entry);
	void	Hantei1(MenuEntry *entry);
	void	Hantei2(MenuEntry *entry);
	void	Hantei3(MenuEntry *entry);
	void    Change_Island(MenuEntry *entry);
	void    Change_Club444(MenuEntry *entry);
	void    Change_Housing(MenuEntry *entry);
	void    Change_Department_store(MenuEntry *entry);
	void    Change_Department_store_F2(MenuEntry *entry);
	void    Change_Department_store_F3(MenuEntry *entry);
	void    Change_Department_store_Engei(MenuEntry *entry);
	void    Change_HomeCenter(MenuEntry *entry);
	void    Change_HomeCenter_Engei(MenuEntry *entry);
	void    Change_SuperMarket(MenuEntry *entry);
	void    Change_ConvenienceStore(MenuEntry *entry);
	void    Change_SuperMarketandConvenienceStore(MenuEntry *entry);
	void    Change_Syuten(MenuEntry *entry);
	void    Change_Cloth_shop(MenuEntry *entry);
	void    Change_Accessory_Shop(MenuEntry *entry);
	void    Change_Shoe_Shop(MenuEntry *entry);
	void    Change_Hakubutukan(MenuEntry *entry);
	void    Change_Gallery(MenuEntry *entry);
	void    Change_PoliceStation(MenuEntry *entry);
	void    Change_Camp(MenuEntry *entry);
	void    Change_Recycle_Shop(MenuEntry *entry);
	void	change_Area(MenuEntry *entry);
	void    coordCType(MenuEntry *entry);
	void	coord(MenuEntry *entry);
	void	change_Weather(MenuEntry *entry);
	void	frag_change(MenuEntry *entry);
	void    Change_Recycle1(MenuEntry *entry);
//	void	Change_Recycle2(MenuEntry *entry);
	void    okikae(MenuEntry *entry);
	void    Change_Item(MenuEntry *entry);
	void	Motion1(MenuEntry *entry);
	void	always_runing( MenuEntry *entry );
	void	Reaction1(MenuEntry *entry);
	void	akarusa_change(MenuEntry *entry);
	void    Taima_musi(MenuEntry *entry);
	void    Taima_sakana(MenuEntry *entry);
	void    Taima_uminosati(MenuEntry *entry);
	void	change_seibetu(MenuEntry *entry);

// -------------------------------------------------------------------
struct CHARS_MAP
{
	const char  *name;
};
// -------------------------------------------------------------------
struct CHARS_U8_MAP
{
	const u8	id;
	const char  *name;
};
// -------------------------------------------------------------------
struct CHARS_U16_MAP
{
	const u16	id;
	const char  *name;
};
// -------------------------------------------------------------------
struct CHARS_U32_MAP
{
	const u32	id;
	const char  *name;
};
// -------------------------------------------------------------------
struct CHARS_INT_MAP
{
	const int	id;
	const char  *name;
};
// -------------------------------------------------------------------
struct CHARS_MAP_INT
{
	const char  *name;
	const int	id;
};
// -------------------------------------------------------------------
struct CHARS_MAP_U8
{
	const char  *name;
	const u8	id;
};
// -------------------------------------------------------------------
struct CHARS_MAP_U16
{
	const char  *name;
	const u16	id;
};
// -------------------------------------------------------------------
struct CHARS_MAP_U32
{
	const char  *name;
	const u32	id;
};




}
#endif

