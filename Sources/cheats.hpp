#ifndef CHEATS_H
#define CHEATS_H

#include "CTRPluginFramework.hpp"
// #include "Helpers.hpp"
// #include "Unicode.h"

namespace	CTRPluginFramework
{
	void change_Player( MenuEntry *entry );
// アクション系
	void Action1( MenuEntry *entry );
	void Action2( MenuEntry *entry );
	void Action3( MenuEntry *entry );
	void Action4( MenuEntry *entry );
	void Action5( MenuEntry *entry );
	void Action6( MenuEntry *entry );
	void Action7( MenuEntry *entry );
	void Action8( MenuEntry *entry );
	void Action9( MenuEntry *entry );
	void Action10( MenuEntry *entry );
//	void Action11( MenuEntry *entry );
	void Action12( MenuEntry *entry );
	void Action13( MenuEntry *entry );
	void Action14( MenuEntry *entry );
	void Action15( MenuEntry *entry );
	void Action16( MenuEntry *entry );
//	void Action17( MenuEntry *entry );
	void Action18( MenuEntry *entry );
	void Action19( MenuEntry *entry );
	void Action20( MenuEntry *entry );
//	void Action21( MenuEntry *entry );
	void Action22( MenuEntry *entry );
	void Action23( MenuEntry *entry );
	void Action24( MenuEntry *entry );
	void Action25( MenuEntry *entry );
	void Action26( MenuEntry *entry );
	void Action27( MenuEntry *entry );
// ---------------------------------------
	void Player1( MenuEntry *entry );
	void Player2( MenuEntry *entry );
	void Inventory1( MenuEntry *entry );
	void Inventory2( MenuEntry *entry );
	void Pose1( MenuEntry *entry );
	void Pose2( MenuEntry *entry );
	void Pose3( MenuEntry *entry );
	void Pose4( MenuEntry *entry );
	void Tools_1( MenuEntry *entry );
	void Tools_2( MenuEntry *entry );
//	商店街発展状況変更
	void change_engei( MenuEntry *entry );
	void change_mametubu( MenuEntry *entry );
	void change_uranai( MenuEntry *entry );
	void change_yumemi( MenuEntry *entry );
	void change_kurabu( MenuEntry *entry );
	void change_biyouin( MenuEntry *entry );
	void change_kutuya( MenuEntry *entry );
	void change_hakubutukan( MenuEntry *entry );
// ---------------------------------------
	void Hantei1( MenuEntry *entry );
	void Hantei2( MenuEntry *entry );
	void Hantei3( MenuEntry *entry );
//	商品変更系
	void Change_Island( MenuEntry *entry );
	void Change_Club444( MenuEntry *entry );
	void Change_Housing( MenuEntry *entry );
	void Change_Department_store( MenuEntry *entry );
	void Change_Department_store_F2( MenuEntry *entry );
	void Change_Department_store_F3( MenuEntry *entry );
	void Change_Department_store_Engei( MenuEntry *entry );
	void Change_HomeCenter( MenuEntry *entry );
	void Change_HomeCenter_Engei( MenuEntry *entry );
	void Change_SuperMarket( MenuEntry *entry );
	void Change_ConvenienceStore( MenuEntry *entry );
	void Change_SuperMarketandConvenienceStore( MenuEntry *entry );
	void Change_Syuten( MenuEntry *entry );
	void Change_Cloth_shop( MenuEntry *entry );
	void Change_Accessory_Shop( MenuEntry *entry );
	void Change_Shoe_Shop( MenuEntry *entry );
	void Change_Hakubutukan( MenuEntry *entry );
	void Change_Gallery( MenuEntry *entry );
	void Change_PoliceStation( MenuEntry *entry );
	void Change_Camp( MenuEntry *entry );
	void Change_Recycle_Shop( MenuEntry *entry );
// ---------------------------------------
	void change_Area( MenuEntry *entry );
	void coordCType( MenuEntry *entry );
	void coord( MenuEntry *entry );
	void change_Weather( MenuEntry *entry );
	void frag_change( MenuEntry *entry );
	void Change_Recycle1( MenuEntry *entry );
//	void Change_Recycle2( MenuEntry *entry );
	void okikae( MenuEntry *entry );
	void Change_Item( MenuEntry *entry );
	void Change_Item_Frag( MenuEntry *entry );
	void Change_Item_kotei( MenuEntry *entry );
//	モーション変更系
	void Motion1( MenuEntry *entry );
	void Motion2( MenuEntry *entry );
	void Motion3( MenuEntry *entry );
	void Motion4( MenuEntry *entry );
	void Motion5( MenuEntry *entry );
	void Motion6( MenuEntry *entry );
	void Motion7( MenuEntry *entry );
// ---------------------------------------
	void always_runing( MenuEntry *entry );
	void Pou( MenuEntry *entry );
	void Reaction1( MenuEntry *entry );
	void akarusa_change( MenuEntry *entry );
	void Taima_musi( MenuEntry *entry );
	void Taima_sakana( MenuEntry *entry );
	void Taima_uminosati( MenuEntry *entry );
	void change_seibetu( MenuEntry *entry );
	void change_badge( MenuEntry *entry );
	void change_gamespeed( MenuEntry *entry );
	void sibahu( MenuEntry *entry );
//	無人島系
	void mujintou_hosuuP1( MenuEntry *entry );
	void mujintou_hosuuP2( MenuEntry *entry );
	void mujintou_hosuuP3( MenuEntry *entry );
	void hosuukotei( MenuEntry *entry );
	void mujinntou_stage_open( MenuEntry *entry );
	void Walkscore_kotei( MenuEntry *entry );
	void mujintou_WalkScore( MenuEntry *entry );
	void mujintou_Item1( MenuEntry *entry );
	void mujintou_Item2( MenuEntry *entry );
	void mujintou_Item3( MenuEntry *entry );
	void mujintou_Item4( MenuEntry *entry );
	void mujintou_Item5( MenuEntry *entry );
	void mujintou_Item6( MenuEntry *entry );
	void mujintou_Item7( MenuEntry *entry );
	void mujintou_hoof1( MenuEntry *entry );
	void mujintou_hoof2( MenuEntry *entry );
	void mujintou_hoof3( MenuEntry *entry );
	void mujintou_hoof4( MenuEntry *entry );
	void mujintou_Tool1( MenuEntry *entry );
	void mujintou_Tool2( MenuEntry *entry );
	void mujintou_Tool3( MenuEntry *entry );
	void mujintou_Tool4( MenuEntry *entry );
	void mujintou_STool1( MenuEntry *entry );
	void mujintou_STool2( MenuEntry *entry );
	void mujintou_STool3( MenuEntry *entry );
	void mujintou_STool4( MenuEntry *entry );
	void mujintou_GTool1( MenuEntry *entry );
	void mujintou_GTool2( MenuEntry *entry );
	void mujintou_GTool3( MenuEntry *entry );
	void mujintou_GTool4( MenuEntry *entry );
	void mujintou_hizuke1( MenuEntry *entry );
	void mujintou_hizuke2( MenuEntry *entry );
	void mujintou_syokuryou1( MenuEntry *entry );
	void mujintou_syokuryou2( MenuEntry *entry );
	void mujintou_syokuryou3( MenuEntry *entry );
	void mujintou_Otosiana( MenuEntry *entry );
	void mujintou_TokugiP1( MenuEntry *entry );
	void mujintou_TokugiP2( MenuEntry *entry );
	void mujintou_TokugiP3( MenuEntry *entry );
	void mujintou_FoodP1( MenuEntry *entry );
	void mujintou_FoodP2( MenuEntry *entry );
	void mujintou_FoodP3( MenuEntry *entry );
// ---------------------------------------
	
// -------------------------------------------------------------------
	struct	CHARS_MAP
	{
		const char	*name;
	};
// -------------------------------------------------------------------
	struct	CHARS_U8_MAP
	{
		const u8	id;
		const char	*name;
	};
// -------------------------------------------------------------------
	struct	CHARS_U16_MAP
	{
		const u16	id;
		const char	*name;
	};
// -------------------------------------------------------------------
	struct	CHARS_U32_MAP
	{
		const u32	id;
		const char	*name;
	};
// -------------------------------------------------------------------
	struct	CHARS_INT_MAP
	{
		const int	id;
		const char	*name;
	};
// -------------------------------------------------------------------
	struct	CHARS_MAP_INT
	{
		const char	*name;
		const int	id;
	};
// -------------------------------------------------------------------
	struct	CHARS_MAP_U8
	{
		const char	*name;
		const u8	id;
	};
// -------------------------------------------------------------------
	struct	CHARS_MAP_U16
	{
		const char	*name;
		const u16	id;
	};
// -------------------------------------------------------------------
	struct	CHARS_MAP_U32
	{
		const char	*name;
		const u32	id;
	};

}
#endif
