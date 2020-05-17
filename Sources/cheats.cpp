// #include <sys/stat.h>
#include "types.h"
#include "cheats.hpp"
#include "CTRPluginFramework/Graphics/OSD.hpp"

namespace	CTRPluginFramework
{
	using	StringVector = std::vector < std::string >;
	
	StringVector items( 200 ); // エリア確保は大体でいい、足りないときは自動で拡張する
	
	// ---------------------------------------------------------------
	// 宣言、定義
	// ---------------------------------------------------------------
	u8	motion_ekiin;						// 駅員モーション変更
	u8	motion_kappei;						// かっぺいモーション変更
	u8	motion_sizue_indoor;				// しずえ(室内)モーション変更
	u8	motion_sizue_outdoor;				// しずえ(室外)モーション変更
	u8	motion_risa;						// リサモーション変更
	u8	motion_keito;						// ケイトモーション変更
	u8	motion_tanukiti;					// タヌキチモーション変更
	u16 outdoor_Frag;						// 室外アイテム判定変更　Freg
	u16 outdoor_item;						// 室外アイテム判定変更
	u32 change_pickup;						// 拾い方変更
	u32 hosuuP1;							// 無人島P1歩数変更
	u32 hosuuP2;							// 無人島P2歩数変更
	u32 hosuuP3;							// 無人島P3歩数変更
	u32 change_WalkScore;					// 無人島歩いた時のスコア変更
	int *g_location = (int *)0x33099F84;	// -1:室外, !=-1:室内
	int *room_ID = (int *)0x0095133A;		// room_deta指定

	// ---------------------------------------------------------------
	// アクション変更8byte
	// ---------------------------------------------------------------
	void set_action_8( u8 act_8 )
	{
		if( *g_location == -1 )
			Process::Write8( 0x33099FE5, act_8 ); // 室外
		else
			Process::Write8( 0x3309A111, act_8 ); // 室内
	}
	
	// ---------------------------------------------------------------
	// アクション変更32byte
	// ---------------------------------------------------------------
	void set_action_32( u32 act_32 )
	{
		if( *g_location == -1 )
			Process::Write32( 0x33099FE4, act_32 ); // 室外
		else
			Process::Write32( 0x3309A110, act_32 ); // 室内
	}
	
	// ---------------------------------------------------------------
	// アクション変更8byte 室内使用禁止
	// ---------------------------------------------------------------
	void set_action_8_not_indoor( u8 act_8_not_in )
	{
		if( *g_location == -1 )
			Process::Write8( 0x33099FE5, act_8_not_in );	// 室外
		else
			( MessageBox("室内では実行できません") )();		// 室内
	}
	
	// ---------------------------------------------------------------
	// アクション変更32byte 室内使用禁止
	// ---------------------------------------------------------------
	void set_action_32_not_indoor( u32 act_32_not_in )
	{
		if( *g_location == -1 )
			Process::Write32( 0x33099FE4, act_32_not_in );	// 室外
		else
			( MessageBox("室内では実行できません") )();		// 室内
	}
	
	// ---------------------------------------------------------------
	// 前転の時の汗の状態
	// ---------------------------------------------------------------
	void sweat( u32 sweat )
	{
		if( *g_location == -1 )
			Process::Write32( 0x33099FC0, sweat ); // 室外
		else
			Process::Write32( 0x3309A0EC, sweat ); // 室内
	}
	
	// ------------------------------------------------------------------
	// 常時実行
	// ------------------------------------------------------------------
	void always_runing( MenuEntry *entry )
	{
		u32	a;
		
		if( motion_ekiin ) *(u8 *)0x330F25A6 = motion_ekiin;		// 駅員モーション変更常時実行
		if( motion_kappei ) *(u8 *)0x330D8F56 = motion_kappei;		// かっぺいモーション変更常時実行
		if( motion_sizue_indoor ) *(u8 *)0x330DA252 = motion_sizue_indoor;		// しずえ(室内)モーション変更常時実行
		if( motion_sizue_outdoor ) *(u8 *)0x330DB64E = motion_sizue_outdoor;		// しずえ（室外）モーション変更常時実行
		if( motion_risa ) *(u8 *)0x330D8EFA = motion_risa;		// リサモーション変更常時実行
		if( motion_keito ) *(u8 *)0x330CE99A = motion_keito;		// ケイトモーション変更常時実行
		if( motion_tanukiti ) *(u8 *)0x330D90DA = motion_tanukiti;		// タヌキチモーション変更常時実行
		if( change_pickup ) *(u32 *)0x005989FC = change_pickup; // 拾い方変更常時実行
	}
	
	// ------------------------------------------------------------------
	// ONだとといいやつ
	// ------------------------------------------------------------------
	void Pou( MenuEntry *entry )
	{
		u32	a;
		Process::Write32( 0x00AD05C0, 0x00000000 );				// @
		Process::Write32( 0x00AD0250, 0x01000000 );				// 改行
		Process::Write32( 0x32E15624, 0x00000036 );				// 文字制限解除(通常)
		Process::Write32( 0x32E15740, 0x45800000 );				// 文字制限解除(ベスチャ)
	}
	
	// ---------------------------------------------------------------
	// 空気椅子
	// ---------------------------------------------------------------
	void Action1( MenuEntry *entry )
	{
		if( entry->Hotkeys[0].IsDown() )
		{
			set_action_8( 0xAA ); // 	アクショ実行
		}
	}
	
	// ---------------------------------------------------------------
	// 前転
	// ---------------------------------------------------------------
	void Action2( MenuEntry *entry )
	{
		if( entry->Hotkeys[0].IsDown() )
		{
			set_action_8( 0x60 );	//    アクショ実行
			sweat( 0x00000000 );	//	汗かかない
		}
	}
	
	// ---------------------------------------------------------------
	// 尻もち
	// ---------------------------------------------------------------
	void Action3( MenuEntry *entry )
	{
		if( entry->Hotkeys[0].IsDown() )
		{
			set_action_8( 0xB3 ); // 	アクショ実行
		}
	}
	
	// ---------------------------------------------------------------
	// 黒くなって地面から出る
	// ---------------------------------------------------------------
	void Action4( MenuEntry *entry )
	{
		if( entry->Hotkeys[0].IsDown() )
		{
			set_action_8( 0x22 ); // アクショ実行
		}
	}
	
	// ---------------------------------------------------------------
	// アイテムを捕まえた
	// ---------------------------------------------------------------
	void Action5( MenuEntry *entry )
	{
		if( entry->Hotkeys[0].IsDown() )
		{
			set_action_8( 0x23 ); // アクショ実行
		}
	}
	
	// ---------------------------------------------------------------
	// クラゲ回避
	// ---------------------------------------------------------------
	void Action6( MenuEntry *entry )
	{
		if( entry->Hotkeys[0].IsDown() )
		{
			set_action_8( 0x27 ); // アクショ実行
		}
	}
	
	// ---------------------------------------------------------------
	// リアクション四連発
	// ---------------------------------------------------------------
	void Action7( MenuEntry *entry )
	{
		if( entry->Hotkeys[0].IsDown() )
		{
			set_action_8( 0xD6 ); // アクショ実行
		}
	}
	
	// ---------------------------------------------------------------
	// 赤バラ表示
	// ---------------------------------------------------------------
	void Action8( MenuEntry *entry )
	{
		if( entry->Hotkeys[0].IsDown() )
		{
			set_action_8_not_indoor( 0x72 ); // アクショ実行
		}
	}
	
	// ---------------------------------------------------------------
	// 綿毛を吐く
	// ---------------------------------------------------------------
	void Action9( MenuEntry *entry )
	{
		if( entry->Hotkeys[0].IsDown() )
		{
			set_action_8( 0x90 ); // アクショ実行
		}
	}
	
	// ---------------------------------------------------------------
	// 頭がピッカーん
	// ---------------------------------------------------------------
	void Action10( MenuEntry *entry )
	{
		if( entry->Hotkeys[0].IsDown() )
		{
			set_action_8( 0xC0 ); // アクショ実行
		}
	}
	
	// ---------------------------------------------------------------
	// かっぺいのボートに立って乗る
	// ---------------------------------------------------------------
	void Action12( MenuEntry *entry )
	{
		if( entry->Hotkeys[0].IsDown() )
		{
			set_action_32_not_indoor( 0xBDBCBD00 ); // 	アクショ実行
		}
	}
	
	// ---------------------------------------------------------------
	// 気絶
	// ---------------------------------------------------------------
	void Action14( MenuEntry *entry )
	{
		if( entry->Hotkeys[0].IsDown() )
		{
			if( *g_location == -1 )
			{
				Process::Write32( 0x33099FE4, 0x066B0600 );
				Process::Write32( 0x33099FB4, 0x00038001 );
				Process::Write32( 0x33099FB0, 0x00000036 );
			}
			if( *g_location != -1 )
			{
				Process::Write32( 0x3309A110, 0x066B0600 );
				Process::Write32( 0x3309A0E0, 0x00038001 );
				Process::Write32( 0x3309A0DC, 0x00000036 );
			}
		}
	}
	
	// ---------------------------------------------------------------
	// 受け取る
	// ---------------------------------------------------------------
	void Action15( MenuEntry *entry )
	{
		u32 a;
		if( entry->Hotkeys[0].IsDown() )
		{
			set_action_32( 0x060F7500 ); // 	アクショ実行
		}
	}
	
	// ---------------------------------------------------------------
	// かっぺいのボートに座って乗る
	// ---------------------------------------------------------------
	void Action16( MenuEntry *entry )
	{
		u32 a;
		if( entry->Hotkeys[0].IsDown() )
		{
			set_action_32_not_indoor( 0x06BBBC00 ); // 	アクショ実行
		}
	}
	
	// ---------------------------------------------------------------
	// 泳ぐ
	// ---------------------------------------------------------------
	void Action18( MenuEntry *entry )
	{
		u32 a;
		if( entry->Hotkeys[0].IsDown() )
		{
			set_action_32_not_indoor( 0x060D1D00 ); // 	アクショ実行
		}
	}
	
	// ---------------------------------------------------------------
	// ウィンドウ
	// ---------------------------------------------------------------
	void Action19( MenuEntry *entry )
	{
		u32 a;
		if( entry->Hotkeys[0].IsDown() )
		{
			set_action_32_not_indoor( 0x1F1F3600 ); // 	アクショ実行
		}
	}
	
	// ---------------------------------------------------------------
	// 地中深くまで沈む
	// ---------------------------------------------------------------
	void Action20( MenuEntry *entry )
	{
		u32 a;
		if( entry->Hotkeys[0].IsDown() )
		{
			set_action_32_not_indoor( 0x06061C00 ); // 	アクショ実行
		}
	}
	
	// ---------------------------------------------------------------
	// 止まると動きがフリーズ
	// ---------------------------------------------------------------
	void Action22( MenuEntry *entry )
	{
		u32 a;
		if( entry->Hotkeys[0].IsDown() )
		{
			set_action_32_not_indoor( 0x06060D00 ); // 	アクショ実行
		}
	}
	
	// ----------------------------------------------------------------
	// よろける
	// ---------------------------------------------------------------
	void Action23( MenuEntry *entry )
	{
		u32 a;
		if( entry->Hotkeys[0].IsDown() )
		{
			set_action_32_not_indoor( 0x7C7C7F00 ); // 	アクショ実行
		}
	}
	
	// ---------------------------------------------------------------
	// 釣り竿を引き戻す
	// ---------------------------------------------------------------
	void Action24( MenuEntry *entry )
	{
		u32 a;
		if( entry->Hotkeys[0].IsDown() )
		{
			set_action_32_not_indoor( 0x06B0B200 ); // 	アクショ実行
		}
	}
	
	// ---------------------------------------------------------------
	// 斧を壊す
	// ---------------------------------------------------------------
	void Action25( MenuEntry *entry )
	{
		u32 a;
		if( entry->Hotkeys[0].IsDown() )
		{
			set_action_32_not_indoor( 0x06555B00 ); // 	アクショ実行
		}
	}
	
	// ---------------------------------------------------------------
	// 唾を吐く
	// ---------------------------------------------------------------
	void Action26( MenuEntry *entry )
	{
		u32 a;
		if( entry->Hotkeys[0].IsDown() )
		{
			set_action_32_not_indoor( 0x0606CF00 ); // 	アクショ実行
		}
	}
	
	// ---------------------------------------------------------------
	// 叩かれる
	// ---------------------------------------------------------------
	void Action27( MenuEntry *entry )
	{
		u32 a;
		if( entry->Hotkeys[0].IsDown() )
		{
			set_action_32_not_indoor( 0x9C9D9C00 ); // 	アクショ実行
		}
	}
	
	// ---------------------------------------------------------------
	// プレイヤー変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_MAP_U32 > change_player =
	{
		{ "村長", 0x31F49AA0 },
		{ "サブ1", 0x31F53F20 },
		{ "サブ2", 0x31F5E3A0 },
		{ "サブ3", 0x31F68820 },
	};
	// ---------------------------------------------------------------
	void change_Player( MenuEntry *entry )
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_MAP_U32 &i: change_player )
			items.push_back( i.name );

		Keyboard keyboard( "指定したプレイヤーに変化。", items );
		int aachoice = keyboard.Open();

		if( aachoice >= 0 ) Process::Write32( 0x00AA914C, change_player[aachoice].id );
	}
	
	// ---------------------------------------------------------------
	// 逆さま
	// ---------------------------------------------------------------
	void Pose1( MenuEntry *entry )
	{
		static bool key_status = false;

		if( entry->Hotkeys[0].IsDown() && key_status == false )
		{
			key_status = true;
			Process::Write32( 0x3309A080, 0x00008000 );
			Process::Write32( 0x3309A1AC, 0x00008000 );
			OSD::Notify( "Hand stand " << Color::Green << "ON!" );
		}

		if( entry->Hotkeys[1].IsDown() && key_status == false )
		{
			key_status = true;
			Process::Write32( 0x3309A080, 0x00000000 );
			Process::Write32( 0x3309A1AC, 0x00000000 );
			OSD::Notify( "Hand stand " << Color::Red << "OFF!" );
		}
		if( entry->Hotkeys[0].IsDown() == 0 && entry->Hotkeys[1].IsDown() == 0 ) key_status = false;
	}
	
	// ---------------------------------------------------------------
	// Tポーズ
	// ---------------------------------------------------------------
	void Pose2( MenuEntry *entry )
	{
		static bool key_status = false;

		if( entry->Hotkeys[0].IsDown() && key_status == false )
		{
			key_status = true;
			Process::Write32( 0x0073AA30, 0xE1A00000 );
			OSD::Notify( "T pose " << Color::Green << "ON!" );
		}

		if( entry->Hotkeys[1].IsDown() && key_status == false )
		{
			key_status = true;
			Process::Write32( 0x0073AA30, 0x0A000011 );
			OSD::Notify( "T pose " << Color::Red << "OFF!" );
		}
		if( entry->Hotkeys[0].IsDown() == 0 && entry->Hotkeys[1].IsDown() == 0 ) key_status = false;
	}
	
	// ---------------------------------------------------------------
	// 変な歩き方
	// ---------------------------------------------------------------
	void Pose3( MenuEntry *entry )
	{
		set_action_32_not_indoor( 0x027600BB ); // 	アクショ実行
	}
	
	// ---------------------------------------------------------------
	// 顔を初期設定
	// ---------------------------------------------------------------
	void Pose4( MenuEntry *entry )
	{
		set_action_32_not_indoor( 0x0616B900 ); // 	アクショ実行
	}
	
	// ---------------------------------------------------------------
	// アイテムを無限に置く
	// ---------------------------------------------------------------
	void Inventory1( MenuEntry *entry )
	{
		static bool key_status = false;

		if( entry->Hotkeys[0].IsDown() && key_status == false )
		{
			key_status = true;
			Process::Write32( 0x0019C4D0, 0x00000000 );
			Process::Write32( 0x0019C42C, 0x00000000 );
			OSD::Notify( "Infinitely put " << Color::Green << "ON!" );
		}

		if( entry->Hotkeys[1].IsDown() && key_status == false )
		{
			key_status = true;
			Process::Write32( 0x0019C4D0, 0xEB057D0A );
			Process::Write32( 0x0019C42C, 0xEB057D33 );
			OSD::Notify( "Infinitely put " << Color::Red << "OFF!" );
		}
		if( entry->Hotkeys[0].IsDown() == 0 && entry->Hotkeys[1].IsDown() == 0 ) key_status = false;
	}
	
	// ---------------------------------------------------------------
	// はや着替え
	// ---------------------------------------------------------------
	void Inventory2( MenuEntry *entry )
	{
		Process::Write32( 0x3309A714, 0x00000000 );
	}
	
	// ---------------------------------------------------------------
	// 園芸店変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U8_MAP > engei_shop =
	{
		{ 0x00, "未完成"		 },
		{ 0x01, "工事中"		 },
		{ 0x02, "完成"			 },
		{ 0x03, "ホームセンター" },
		{ 0x04, "デパート"		 },
	};
	void change_engei( MenuEntry *entry )
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: engei_shop )
			items.push_back( i.name );
		Keyboard keyboard( "指定した園芸店に変化。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x31FB00F4, engei_shop[choice].id );
	}
	
	// ---------------------------------------------------------------
	// まめつぶ変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U8_MAP > mametubu_shop =
	{
		{ 0x00, "商店"				 },
		{ 0x01, "コンビニ"			 },
		{ 0x02, "スーパーマーケット" },
		{ 0x03, "ホームセンター"	 },
		{ 0x04, "デパート"			 },
	};
	void change_mametubu( MenuEntry *entry )
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: mametubu_shop )
			items.push_back( i.name );
		Keyboard keyboard( "指定したまめつぶショップに変化。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x31FABC64, mametubu_shop[choice].id );
	}
	
	// ---------------------------------------------------------------
	// 　占いの館
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U8_MAP > uranai_shop =
	{
		{ 0x00, "未完成" },
		{ 0x01, "完成"	 },
	};
	void change_uranai( MenuEntry *entry )
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: uranai_shop )
			items.push_back( i.name );
		Keyboard keyboard( "指定した占いの館に変化。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x31FB47A4, uranai_shop[choice].id );
	}
	
	// ---------------------------------------------------------------
	// 夢見の館変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U8_MAP > yumemi_shop =
	{
		{ 0x00, "未完成" },
		{ 0x01, "完成"	 },
	};
	void change_yumemi( MenuEntry *entry )
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: yumemi_shop )
			items.push_back( i.name );
		Keyboard keyboard( "指定した夢見の館に変化。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x31FB47A2, yumemi_shop[choice].id );
	}
	
	// ---------------------------------------------------------------
	// CLUB444変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U8_MAP > kurabu_shop =
	{
		{ 0x00, "未完成" },
		{ 0x02, "完成"	 },
	};
	void change_kurabu( MenuEntry *entry )
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: kurabu_shop )
			items.push_back( i.name );
		Keyboard keyboard( "指定したCLUB444に変化。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x31FB4782, kurabu_shop[choice].id );
	}
	
	// ---------------------------------------------------------------
	// 美容院
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U8_MAP > biyouin_shop =
	{
		{ 0x00, "未完成" },
		{ 0x01, "工事中" },
		{ 0x02, "完成"	 },
	};
	void change_biyouin( MenuEntry *entry )
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: biyouin_shop )
			items.push_back( i.name );

		Keyboard keyboard( "指定した美容院に変化。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x31FB47B4, biyouin_shop[choice].id );
	}
	
	// ---------------------------------------------------------------
	// 靴屋変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U8_MAP > kutuya_shop =
	{
		{ 0x00, "未完成" },
		{ 0x01, "工事中" },
		{ 0x02, "完成"	 },
	};
	void change_kutuya( MenuEntry *entry )
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: kutuya_shop )
			items.push_back( i.name );
		Keyboard keyboard( "指定した靴屋に変化。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x31FB022C, kutuya_shop[choice].id );
	}
	
	// ---------------------------------------------------------------
	// 博物館変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U8_MAP > hakubutukan_shop =
	{
		{ 0x00, "F2未完成" },
		{ 0x01, "F2完成"   }
	};
	void change_hakubutukan( MenuEntry *entry )
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: hakubutukan_shop )
			items.push_back( i.name );
		Keyboard keyboard( "指定した博物館に変化。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x31FB46BC, hakubutukan_shop[choice].id );
	}
	
	// ---------------------------------------------------------------
	// 拾い方変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > Hirou =
	{
		{ 0x0A000044, "通常動作"		   },
		{ 0xEA000030, "なんでも拾う"	   },
		{ 0xEA000019, "なんでも引っこ抜く" },
		{ 0xEA000020, "なんでもクローバー" }
	};
	void Player2( MenuEntry *entry )
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: Hirou )
			items.push_back( i.name );
		Keyboard keyboard( "指定した拾い方に変化。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) change_pickup = Hirou[choice].id;
	}
	
	// ---------------------------------------------------------------
	// 速く走る
	// ---------------------------------------------------------------
	void Player1( MenuEntry *entry )
	{
		u32		velocity;
		float	*Flo; // <-- pointerに変更

		Flo = (float *)0x33099E7C; // <--- 追加
		if( entry->Hotkeys[0].IsDown() )
		{
//			Process::Read32( 0x33099E7C, velocity );  <-- 不要
//			Process::ReadFloat( 0x33099E7C, Flo ); // <-- 削除
			if( *Flo > 20.0 ) // <-- if( velocity >= 0x41A79DB3 )
			{
				*Flo = 20.0;  // <-- Process::Write32( 0x33099E7C, 0x41A79DB3 );
			}
			else if( *Flo > 0 ) // <-- else if( *Flovelocity > 0 )
			{
				*Flo += 2.0;
//				Process::WriteFloat( 0x33099E7C, Flo ); <-- 削除
			}
		}
	}
	
	// ---------------------------------------------------------------
	// ツール系
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U16_MAP > Tool =
	{
		{ 0x3358, "レンタルスコップ"		 },
		{ 0x3359, "スコップ"				 },
		{ 0x335A, "銀のスコップ"			 },
		{ 0x335B, "金のスコップ"			 },
		{ 0x3354, "レンタル釣り竿"			 },
		{ 0x3355, "釣り竿"					 },
		{ 0x3356, "銀の釣り竿"				 },
		{ 0x3357, "金の釣り竿"				 },
		{ 0x3350, "レンタル網"				 },
		{ 0x3351, "網"						 },
		{ 0x3352, "銀の網"					 },
		{ 0x3353, "金の網"					 },
		{ 0x334C, "レンタル斧"				 },
		{ 0x334D, "斧"						 },
		{ 0x334E, "銀の斧"					 },
		{ 0x334F, "金の斧"					 },
		{ 0x335C, "レンタルジョウロ"		 },
		{ 0x335D, "ジョウロ"				 },
		{ 0x335E, "銀のジョウロ"			 },
		{ 0x335F, "金のジョウロ"			 },
		{ 0x3360, "レンタルパチンコ"		 },
		{ 0x3361, "パチンコ"				 },
		{ 0x3362, "銀のパチンコ"			 },
		{ 0x3363, "金のパチンコ"			 },
		{ 0x3364, "レンタルピコピコハンマー" },
		{ 0x3365, "ピコピコハンマー"		 },
		{ 0x338C, "コーヒー"				 },
		{ 0x338F, "恵方巻"					 },
		{ 0x338E, "豆"						 },
		{ 0x336A, "クラッカー"				 },
		{ 0x3399, "緑のスティックライト"	 },
		{ 0x339B, "黄色いスティックライト"	 },
		{ 0x339A, "ピンクのスティックライト" },
		{ 0x3398, "青いスティックライト"	 },
		{ 0x338D, "スパークリングサイダー"	 },
		{ 0x3379, "青い風船"				 },
		{ 0x3374, "赤い風船"				 },
		{ 0x3375, "オレンジの風船"			 },
		{ 0x3376, "黄色い風船"				 },
		{ 0x337B, "ピンクの風船"			 },
		{ 0x3378, "水色の風船"				 },
		{ 0x3377, "緑の風船"				 },
		{ 0x337A, "紫の風船"				 },
		{ 0x3371, "青いウサギ風船"			 },
		{ 0x336C, "赤いウサギ風船"			 },
		{ 0x336D, "オレンジウサギ風船"		 },
		{ 0x336E, "黄色いウサギ風船"		 },
		{ 0x3373, "ピンクウサギ風船"		 },
		{ 0x3370, "水色ウサギ風船"			 },
		{ 0x336F, "緑のウサギ風船"			 },
		{ 0x3372, "紫ウサギ風船"			 },
		{ 0x3379, "青いハート風船"			 },
		{ 0x3381, "赤いハート風船"			 },
		{ 0x337D, "オレンジハート風船"		 },
		{ 0x337E, "黄色いハート風船"		 },
		{ 0x3383, "ピンクのハート風船"		 },
		{ 0x3380, "水色ハート風船"			 },
		{ 0x337F, "緑のハート風船"			 },
		{ 0x3382, "紫ハート風船"			 },
		{ 0x3389, "青い風車"				 },
		{ 0x3384, "赤い風車"				 },
		{ 0x3385, "オレンジの風車"			 },
		{ 0x3386, "黄色い風車"				 },
		{ 0x338B, "ピンクの風車"			 },
		{ 0x3388, "水色の風車"				 },
		{ 0x3387, "緑の風車"				 },
		{ 0x338A, "紫の風車"				 },
		{ 0x336B, "シャボン玉"				 },
		{ 0x339E, "吹き戻し"				 },
		{ 0x3391, "チョコソフトクリーム"	 },
		{ 0x3390, "バニラソフトクリーム"	 },
		{ 0x3392, "抹茶のソフトクリーム"	 },
		{ 0x3393, "ミックスソフトクリーム"	 },
		{ 0x3395, "イチゴアイスクリーム"	 },
		{ 0x3394, "バニラアイスクリーム"	 },
		{ 0x3397, "ミントダブルアイス"		 },
		{ 0x3396, "レモンダブルアイス"		 },
	};
	void Tools_1( MenuEntry *entry )//道具機能変更
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U16_MAP &i: Tool )
			items.push_back( i.name );
		Keyboard keyboard( "指定したツールの機能に変化。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write16( 0x33096734, Tool[choice].id );
	}
	
	void Tools_2( MenuEntry *entry )//道具持ち方変更
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U16_MAP &i: Tool )
			items.push_back( i.name );
		Keyboard keyboard( "指定したツールの持ち方に変化。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write16( 0x3309A20C, Tool[choice].id );
	}
	
	// ---------------------------------------------------------------
	// 花が散らない
	// ---------------------------------------------------------------
	void Hantei1( MenuEntry *entry )
	{
		static bool key_status = false;

		if( entry->Hotkeys[0].IsDown() && key_status == false )
		{
			key_status = true;
			Process::Write32( 0x00596890, 0xE3A0001D );
			OSD::Notify( "Not scatter flower " << Color::Green << "ON!" );
		}

		if( entry->Hotkeys[1].IsDown() && key_status == false )
		{
			key_status = true;
			Process::Write32( 0x00596890, 0xEBF5990F );
			OSD::Notify( "Not scatter flower " << Color::Red << "OFF!" );
		}
		if( entry->Hotkeys[0].IsDown() == 0 && entry->Hotkeys[1].IsDown() == 0 ) key_status = false;
	}
	
	// ---------------------------------------------------------------
	// 壁貫通
	// ---------------------------------------------------------------
	void Hantei2( MenuEntry *entry )
	{
		static bool key_status = false;

		if( entry->Hotkeys[0].IsDown() && key_status == false )
		{
			key_status = true;
			Process::Write32( 0x0064EEF4, 0xEA000094 );
			Process::Write32( 0x0064F1E4, 0xEA000065 );
			Process::Write32( 0x0064EF0C, 0xEA000052 );
			Process::Write32( 0x0064F070, 0xEA000001 );
			Process::Write32( 0x0064F0E8, 0xEA000014 );
			Process::Write32( 0x0064F19C, 0xE1A00000 );
			Process::Write32( 0x0064F1B4, 0xE1A00000 );
			Process::Write32( 0x0064F1B8, 0xEA000026 );
			OSD::Notify( "Walk Anywhere " << Color::Green << "ON!" );
		}

		if( entry->Hotkeys[1].IsDown() && key_status == false )
		{
			key_status = true;
			Process::Write32( 0x0064EEF4, 0x0A000094 );
			Process::Write32( 0x0064F1E4, 0x0A000065 );
			Process::Write32( 0x0064EF0C, 0x0A000052 );
			Process::Write32( 0x0064F070, 0x0A000001 );
			Process::Write32( 0x0064F0E8, 0xDA000014 );
			Process::Write32( 0x0064F19C, 0xED841A05 );
			Process::Write32( 0x0064F1B4, 0xED840A07 );
			Process::Write32( 0x0064F1B8, 0x0A000026 );
			OSD::Notify( "Walk Anywhere " << Color::Red << "OFF!" );
		}
		if( entry->Hotkeys[0].IsDown() == 0 && entry->Hotkeys[1].IsDown() == 0 ) key_status = false;
	}
	
	// ---------------------------------------------------------------
	// 自宅化
	// ---------------------------------------------------------------
	void Hantei3( MenuEntry *entry )
	{
		static bool key_status = false;

		if( entry->Hotkeys[0].IsDown() && key_status == false )
		{
			key_status = true;
			Process::Write32( 0x00951338, 0xA5030000 );
			OSD::Notify( "Home Zation " << Color::Green << "ON!" );
		}

		if( entry->Hotkeys[1].IsDown() && key_status == false )
		{
			key_status = true;
			Process::Write32( 0x00951338, 0xA5020000 );
			OSD::Notify( "Home Zation " << Color::Red << "OFF!" );
		}
		if( entry->Hotkeys[0].IsDown() == 0 && entry->Hotkeys[1].IsDown() == 0 ) key_status = false;
	}
	
	// ---------------------------------------------------------------
	// 島のお土産変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > Island_Item =
	{
		{ 0x3305B814, "お土産左"   },
		{ 0x3305B818, "お土産中央" },
		{ 0x3305B81C, "お土産右"   },
		{ 0x3305B810, "お土産後ろ" }
	};
	void Change_Island( MenuEntry *entry )
	{
		u16 a; // <-- ここに移動

		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: Island_Item )
			items.push_back( i.name );
		Keyboard keyboard( "お土産変更先を指定してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 )
		{
			Keyboard aiueo( "指定したアイテムに変化。" );
			if( aiueo.Open( a ) >= 0 ) // <--- aiueo.Open( a );
				Process::Write16( Island_Item[choice].id, a );
		}
	}
	
	// ---------------------------------------------------------------
	// CLUB444ハニワ変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > Club444_Item =
	{
		{ 0x31FB4792, "ハニワ左"	 },
		{ 0x31FB4796, "ハニワ左中央" },
		{ 0x31FB479A, "ハニワ右中央" },
		{ 0x31FB479E, "ハニワ右"	 }
	};
	void Change_Club444( MenuEntry *entry )
	{
		u16 a; // <-- ここに移動

		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: Club444_Item )
			items.push_back( i.name );
		Keyboard keyboard( "ハニワ変更先を指定してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 )
		{
			Keyboard aiueo( "指定したアイテムに変化。" );
			if( aiueo.Open( a ) >= 0 ) // <-- aiueo.Open( a );
				Process::Write16( Club444_Item[choice].id, a );
		}
	}
	
	// ---------------------------------------------------------------
	// 不動産屋
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > Housing_Item =
	{
		{ 0x31FB46CE, "石畳"   },
		{ 0x31FB46D2, "屋根"   },
		{ 0x31FB46D6, "壁"	   },
		{ 0x31FB46DA, "柵"	   },
		{ 0x31FB46DE, "ポスト" },
		{ 0x31FB46E2, "ドア左" },
		{ 0x31FB46E6, "ドア右" },
		{ 0x31FB46EA, "建物"   },
	};
	void Change_Housing( MenuEntry *entry )
	{
		u16 a;

		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: Housing_Item )
			items.push_back( i.name );
		Keyboard keyboard( "エクステリア変更先を指定してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 )
		{
			Keyboard aiueo( "指定したアイテムに変化。" );
			if( aiueo.Open( a ) >= 0 ) Process::Write16( Housing_Item[choice].id, a );
		}
	}
	
	// ---------------------------------------------------------------
	// デパートF1
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > DepartmentStore_Item =
	{
		{ 0x31FABCAC, "フォーチュンクッキー上" },
		{ 0x31FABCB0, "フォーチュンクッキー下" },
		{ 0x31FABC70, "ツール上"			   },
		{ 0x31FABC78, "ツール真ん中"		   },
		{ 0x31FABC7C, "ツール下"			   },
		{ 0x31FABCA4, "音楽左"				   },
		{ 0x31FABCA8, "音楽右"				   },
		{ 0x31FABCA0, "お薬"				   },
		{ 0x31FABC90, "ラッピング"			   },
		{ 0x31FABC94, "手紙上"				   },
		{ 0x31FABC98, "手紙下"				   },
		{ 0x31FABC9C, "メロディーカード"	   },
	};
	void Change_Department_store( MenuEntry *entry )
	{
		u16 a;

		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: DepartmentStore_Item )
			items.push_back( i.name );
		Keyboard keyboard( "商品変更先を指定してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 )
		{
			Keyboard aiueo( "指定したアイテムに変化。" );
			if( aiueo.Open( a ) >= 0 ) Process::Write16( DepartmentStore_Item[choice].id, a );
		}
	}
	
	// ---------------------------------------------------------------
	// デパートF2
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > DepartmentStoreF2_Item =
	{
		{ 0x31FABCB4, "壁掛け左" },
		{ 0x31FABCB8, "壁掛け右" },
		{ 0x31FABCBC, "家具左上" },
		{ 0x31FABCC4, "家具左下" },
		{ 0x31FABCC8, "家具中央" },
		{ 0x31FABCCC, "家具右下" },
		{ 0x31FABCC0, "家具右上" },
		{ 0x31FABC80, "壁紙上"	 },
		{ 0x31FABC84, "壁紙下"	 },
		{ 0x31FABC88, "床上"	 },
		{ 0x31FABC8C, "床下"	 },
	};
	void Change_Department_store_F2( MenuEntry *entry )
	{
		u16 a;

		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: DepartmentStoreF2_Item )
			items.push_back( i.name );
		Keyboard keyboard( "商品変更先を指定してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 )
		{
			Keyboard aiueo( "指定したアイテムに変化。" );
			if( aiueo.Open( a ) >= 0 ) Process::Write16( DepartmentStoreF2_Item[choice].id, a );
		}
	}
	
	// ---------------------------------------------------------------
	// デパートF3
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > DepartmentStoreF3_Item =
	{
		{ 0x31FB4710, "床"		 },
		{ 0x31FB470C, "壁紙"	 },
		{ 0x31FB46F8, "家具左上" },
		{ 0x31FB4700, "家具左下" },
		{ 0x31FB4704, "家具右下" },
		{ 0x31FB46FC, "家具右上" },
		{ 0x31FB4714, "帽子左"	 },
		{ 0x31FB4718, "帽子右"	 },
		{ 0x31FB471C, "靴左"	 },
		{ 0x31FB4720, "靴右"	 },
		{ 0x31FB4734, "ズボン左" },
		{ 0x31FB4724, "服左中央" },
		{ 0x31FB4728, "服左内側" },
		{ 0x31FB472C, "服右内側" },
		{ 0x31FB4730, "服右中央" },
		{ 0x31FB4738, "ズボン右" },
		{ 0x31FB4708, "壁掛け"	 },
	};
	void Change_Department_store_F3( MenuEntry *entry )
	{
		u16 a;

		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: DepartmentStoreF3_Item )
			items.push_back( i.name );
		Keyboard keyboard( "商品変更先を指定してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 )
		{
			Keyboard aiueo( "指定したアイテムに変化。" );
			if( aiueo.Open( a ) >= 0 ) Process::Write16( DepartmentStoreF3_Item[choice].id, a );
		}
	}
	
	// ---------------------------------------------------------------
	// デパート園芸店
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > DepartmentStoreEngei_Item =
	{
		{ 0x31FB00FA, "ツール左"		 },
		{ 0x31FB00FE, "ツール右"		 },
		{ 0x31FB011E, "肥料"			 },
		{ 0x31FB010A, "果物"			 },
		{ 0x31FB0102, "苗"				 },
		{ 0x31FB0112, "低木上"			 },
		{ 0x31FB010E, "低木下"			 },
		{ 0x31FB011A, "種下"			 },
		{ 0x31FB0116, "種上"			 },
		{ 0x31FB00F6, "家具"			 },
		{ 0x31FABC90, "ラッピング"		 },
		{ 0x31FABC98, "手紙左"			 },
		{ 0x31FABC94, "手紙右"			 },
		{ 0x31FABC9C, "メロディーカード" },
		{ 0x31FABC70, "ツール上"		 },
		{ 0x31FABC78, "ツール真ん中"	 },
		{ 0x31FABC7C, "ツール下"		 },
	};
	void Change_Department_store_Engei( MenuEntry *entry )
	{
		u16 a;

		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: DepartmentStoreEngei_Item )
			items.push_back( i.name );
		Keyboard keyboard( "商品変更先を指定してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 )
		{
			Keyboard aiueo( "指定したアイテムに変化。" );
			if( aiueo.Open( a ) >= 0 ) Process::Write16( DepartmentStoreEngei_Item[choice].id, a );
		}
	}
	
	// ---------------------------------------------------------------
	// ホームセンター
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > HomeCenter_Item =
	{
		{ 0x31FABCBC, "家具左外側"			   },
		{ 0x31FABCC0, "家具左内側"			   },
		{ 0x31FABCB4, "壁掛け"				   },
		{ 0x31FABCC4, "家具右内側"			   },
		{ 0x31FABCC8, "家具右外側"			   },
		{ 0x31FABCA4, "音楽左"				   },
		{ 0x31FABCAC, "フォーチュンクッキー上" },
		{ 0x31FABCB0, "フォーチュンクッキー下" },
		{ 0x31FABC80, "壁紙左"				   },
		{ 0x31FABC84, "壁紙右"				   },
		{ 0x31FABC88, "床左"				   },
		{ 0x31FABC8C, "床右"				   },
		{ 0x31FABCA0, "お薬"				   },
	};
	void Change_HomeCenter( MenuEntry *entry )
	{
		u16 a;

		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: HomeCenter_Item )
			items.push_back( i.name );
		Keyboard keyboard( "商品変更先を指定してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 )
		{
			Keyboard aiueo( "指定したアイテムに変化。" );
			if( aiueo.Open( a ) >= 0 ) Process::Write16( HomeCenter_Item[choice].id, a );
		}
	}
	
	// ---------------------------------------------------------------
	// ホームセンター園芸店
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > HomeCenterEngei_Item =
	{
		{ 0x31FB00FA, "ツール" },
		{ 0x31FB0102, "苗"	   },
		{ 0x31FB0112, "低木左" },
		{ 0x31FB010E, "低木右" },
		{ 0x31FB011A, "種左"   },
		{ 0x31FB0116, "種右"   },
		{ 0x31FB00F6, "家具"   },
	};
	void Change_HomeCenter_Engei( MenuEntry *entry )
	{
		u16 a;

		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: HomeCenterEngei_Item )
			items.push_back( i.name );
		Keyboard keyboard( "商品変更先を指定してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 )
		{
			Keyboard aiueo( "指定したアイテムに変化。" );
			if( aiueo.Open( a ) >= 0 ) Process::Write16( HomeCenterEngei_Item[choice].id, a );
		}
	}
	
	// ---------------------------------------------------------------
	// スーパー商品変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > SuperMarket_Item =
	{
		{ 0x31FABCBC, "家具上"				   },
		{ 0x31FABCC0, "家具真ん中"			   },
		{ 0x31FABCC4, "家具下"				   },
		{ 0x31FABCB4, "壁掛け"				   },
		{ 0x31FABC80, "壁紙左"				   },
		{ 0x31FABC84, "壁紙右"				   },
		{ 0x31FABC88, "床左"				   },
		{ 0x31FABC8C, "床右"				   },
		{ 0x31FABCAC, "フォーチュンクッキー上" },
		{ 0x31FABCB0, "フォーチュンクッキー下" },
		{ 0x31FABC70, "ツール左"			   },
		{ 0x31FABC78, "ツール真ん中"		   },
		{ 0x31FABC7C, "ツール右"			   },
		{ 0x31FABCA0, "お薬"				   },
		{ 0x31FABC90, "ラッピング"			   },
		{ 0x31FABC94, "手紙左"				   },
		{ 0x31FABC98, "手紙右"				   },
		{ 0x31FABC9C, "メロディーカード"	   },
	};
	void Change_SuperMarket( MenuEntry *entry )
	{
		u16 a;

		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: SuperMarket_Item )
			items.push_back( i.name );
		Keyboard keyboard( "商品変更先を指定してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 )
		{
			Keyboard aiueo( "指定したアイテムに変化。" );
			if( aiueo.Open( a ) >= 0 ) Process::Write16( SuperMarket_Item[choice].id, a );
		}
	}
	
	// ---------------------------------------------------------------
	// スーパー&コンビニ園芸店
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > SuperMarketandConvenienceStore_Item =
	{
		{ 0x31FB011A, "種左"   },
		{ 0x31FB0116, "種右"   },
		{ 0x31FB0102, "苗"	   },
		{ 0x31FB00FA, "ツール" },
	};
	void Change_SuperMarketandConvenienceStore( MenuEntry *entry )
	{
		u16 a;

		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: SuperMarketandConvenienceStore_Item )
			items.push_back( i.name );
		Keyboard keyboard( "商品変更先を指定してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 )
		{
			Keyboard aiueo( "指定したアイテムに変化。" );
			if( aiueo.Open( a ) >= 0 ) Process::Write16( SuperMarketandConvenienceStore_Item[choice].id, a );
		}
	}
	
	// ---------------------------------------------------------------
	// コンビニ商品変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > ConvenienceStore_Item =
	{
		{ 0x31FABCBC, "家具上"				   },
		{ 0x31FABCC0, "家具真ん中"			   },
		{ 0x31FABCC4, "家具下"				   },
		{ 0x31FABC80, "壁紙"				   },
		{ 0x31FABC88, "床"					   },
		{ 0x31FABC90, "ラッピング"			   },
		{ 0x31FABC94, "手紙"				   },
		{ 0x31FABC70, "ツール左"			   },
		{ 0x31FABC78, "ツール右"			   },
		{ 0x31FABCAC, "フォーチュンクッキー上" },
		{ 0x31FABCB0, "フォーチュンクッキー下" },
		{ 0x31FABCA0, "お薬"				   },
	};
	void Change_ConvenienceStore( MenuEntry *entry )
	{
		u16 a;

		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: ConvenienceStore_Item )
			items.push_back( i.name );
		Keyboard keyboard( "商品変更先を指定してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 )
		{
			Keyboard aiueo( "指定したアイテムに変化。" );
			if( aiueo.Open( a ) >= 0 ) Process::Write16( ConvenienceStore_Item[choice].id, a );
		}
	}
	
	// ---------------------------------------------------------------
	// 商店商品変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > Syuten_Item =
	{
		{ 0x31FABCBC, "家具左"				   },
		{ 0x31FABCC0, "家具右"				   },
		{ 0x31FABC90, "ラッピング"			   },
		{ 0x31FABC94, "手紙"				   },
		{ 0x31FABC70, "ツール"				   },
		{ 0x31FABCAC, "フォーチュンクッキー上" },
	};
	void Change_Syuten( MenuEntry *entry )
	{
		u16 a;

		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: Syuten_Item )
			items.push_back( i.name );
		Keyboard keyboard( "商品変更先を指定してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 )
		{
			Keyboard aiueo( "指定したアイテムに変化。" );
			if( aiueo.Open( a ) >= 0 ) Process::Write16( Syuten_Item[choice].id, a );
		}
	}
	
	// ---------------------------------------------------------------
	// 服屋商品変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > Cloth_shop_Item =
	{
		{ 0x31FABCEC, "左内側" },
		{ 0x31FABCF0, "左中央" },
		{ 0x31FABCF4, "中央"   },
		{ 0x31FABCF8, "右内側" },
		{ 0x31FABCFC, "右外側" },
	};
	void Change_Cloth_shop( MenuEntry *entry )
	{
		u16 a;

		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: Cloth_shop_Item )
			items.push_back( i.name );
		Keyboard keyboard( "商品変更先を指定してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 )
		{
			Keyboard aiueo( "指定したアイテムに変化。" );
			if( aiueo.Open( a ) >= 0 ) Process::Write16( Cloth_shop_Item[choice].id, a );
		}
	}
	
	// ---------------------------------------------------------------
	// アクセサリー屋商品変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > Accessory_Shop_Item =
	{
		{ 0x31FB00B8, "帽子左"			 },
		{ 0x31FB00BC, "帽子中央"		 },
		{ 0x31FB00C0, "帽子右"			 },
		{ 0x31FB00C4, "アクセサリー上"	 },
		{ 0x31FB00C8, "アクセサリー中央" },
		{ 0x31FB00CC, "アクセサリー下"	 },
		{ 0x31FB00D0, "傘"				 },
	};
	void Change_Accessory_Shop( MenuEntry *entry )
	{
		u16 a;

		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: Accessory_Shop_Item )
			items.push_back( i.name );
		Keyboard keyboard( "商品変更先を指定してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 )
		{
			Keyboard aiueo( "指定したアイテムに変化。" );
			if( aiueo.Open( a ) >= 0 ) Process::Write16( Accessory_Shop_Item[choice].id, a );
		}
	}
//zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz
	// ---------------------------------------------------------------
	// 靴商品変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > Shoe_Shop_Item =
	{
		{ 0x31FB022E, "靴左外側" },
		{ 0x31FB0232, "靴左中央" },
		{ 0x31FB0236, "靴右中央" },
		{ 0x31FB023A, "靴右外側" },
		{ 0x31FB023E, "靴下右"	 },
		{ 0x31FB0242, "靴下左"	 },
	};
	void Change_Shoe_Shop( MenuEntry *entry )
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: Shoe_Shop_Item )
			items.push_back( i.name );
		Keyboard keyboard( "商品変更先を指定してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 )
		{
			Keyboard aiueo( "指定したアイテムに変化。" );
			u16 a;
			aiueo.Open( a );
			Process::Write16( Shoe_Shop_Item[choice].id, a );
		}
	}
	
	// ---------------------------------------------------------------
	// 交番商品変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > PoliceStation_Item =
	{
		{ 0x31FABBE2, "左上"	 },
		{ 0x31FABBE6, "左上外側" },
		{ 0x31FABBEA, "左上内側" },
		{ 0x31FABBEE, "右上内側" },
		{ 0x31FABBF2, "右上外側" },
		{ 0x31FABBF6, "右上"	 },
		{ 0x31FABBFA, "左下"	 },
		{ 0x31FABBFE, "中央左"	 },
		{ 0x31FABC02, "中央右"	 },
		{ 0x31FABC06, "右下"	 },
	};
	void Change_PoliceStation( MenuEntry *entry )
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: PoliceStation_Item )
			items.push_back( i.name );
		Keyboard keyboard( "落とし物変更先を指定してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 )
		{
			Keyboard aiueo( "指定したアイテムに変化。" );
			u16 a;
			aiueo.Open( a );
			Process::Write16( PoliceStation_Item[choice].id, a );
		}
	}
	
	// ---------------------------------------------------------------
	// オートキャンプ場商品変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > Camp_Item =
	{
		{ 0x31FB4854, "左" },
		{ 0x31FB4858, "右" },
	};
	void Change_Camp( MenuEntry *entry )
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: Camp_Item )
			items.push_back( i.name );
		Keyboard keyboard( "商品変更先を指定してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 )
		{
			Keyboard aiueo( "指定したアイテムに変化。" );
			u16 a;
			aiueo.Open( a );
			Process::Write16( Camp_Item[choice].id, a );
		}
	}
	
	// ---------------------------------------------------------------
	// 博物館二階商品変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > Hakubutukan_Item =
	{
		{ 0x31FB46BE, "上" },
		{ 0x31FB46C2, "左" },
		{ 0x31FB46C6, "右" },
	};
	void Change_Hakubutukan( MenuEntry *entry )
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: Hakubutukan_Item )
			items.push_back( i.name );
		Keyboard keyboard( "記念販売品変更先を指定してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 )
		{
			Keyboard aiueo( "指定したアイテムに変化。" );
			u16 a;
			aiueo.Open( a );
			Process::Write16( Hakubutukan_Item[choice].id, a );
		}
	}
	
	// ---------------------------------------------------------------
	// いなりギャラリー商品変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > Gallery_Item =
	{
		{ 0x31FB0130, "左上" },
		{ 0x31FB0134, "右上" },
		{ 0x31FB0138, "左下" },
		{ 0x31FB013C, "右下" },
	};
	void Change_Gallery( MenuEntry *entry )
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: Gallery_Item )
			items.push_back( i.name );
		Keyboard keyboard( "美術品変更先を指定してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 )
		{
			Keyboard aiueo( "指定したアイテムに変化。" );
			u16 a;
			aiueo.Open( a );
			Process::Write16( Gallery_Item[choice].id, a );
		}
	}
	
	// ---------------------------------------------------------------
	// リサイクルショップ商品変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > Recycle_Shop_Item =
	{
		{ 0x31FB02CC, "前左"		 },
		{ 0x31FB02D0, "前右"		 },
		{ 0x31FB02C4, "真ん中左"	 },
		{ 0x31FB02C8, "真ん中右"	 },
		{ 0x31FB02B4, "後ろ左外側"	 },
		{ 0x31FB02B8, "後ろ左内側"	 },
		{ 0x31FB02BC, "後ろ右内側"	 },
		{ 0x31FB02C0, "後ろ右外側"	 },
		{ 0x31FB024C, "リメイク前P1" },
		{ 0x31FB025C, "リメイク後P1" },
	};
	void Change_Recycle_Shop( MenuEntry *entry )
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: Recycle_Shop_Item )
			items.push_back( i.name );
		Keyboard keyboard( "出品物変更先を指定してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 )
		{
			Keyboard aiueo( "指定したアイテムに変化。" );
			u16 a;
			aiueo.Open( a );
			Process::Write16( Recycle_Shop_Item[choice].id, a );
		}
	}
	
	// ---------------------------------------------------------------
	struct	CHANGE_AREA
	{
		const char	*name;
		const u8	id;
	};
	static const	std::vector< CHANGE_AREA > change_area =
	{
		{ "村",									 0x00 },
		{ "商店街",								 0x01 },
		{ "駅",									 0x02 },
		{ "P1 家 Main",							 0x03 },
		{ "P1 家 UP",							 0x04 },
		{ "P1 家 DOWN",							 0x05 },
		{ "P1 家 Right",						 0x06 },
		{ "P1 家 left",							 0x07 },
		{ "P1 家 Back",							 0x08 },
		{ "P2 家 Main",							 0x09 },
		{ "P2 家 UP",							 0x0A },
		{ "P2 家 DOWN",							 0x0B },
		{ "P2 家 Right",						 0x0C },
		{ "P2 家 left",							 0x0D },
		{ "P2 家 Back",							 0x0E },
		{ "P3 家 Main",							 0x0F },
		{ "P3 家 UP",							 0x10 },
		{ "P3 家 DOWN",							 0x11 },
		{ "P3 家 Right",						 0x12 },
		{ "P3 家 left",							 0x13 },
		{ "P3 家 Back",							 0x14 },
		{ "P4 家 Main",							 0x15 },
		{ "P4 家 UP",							 0x16 },
		{ "P4 家 DOWN",							 0x17 },
		{ "P4 家 Right",						 0x18 },
		{ "P4 家 left",							 0x19 },
		{ "P4 家 Back",							 0x1A },
		{ "A1 家",								 0x1B },
		{ "A2 家",								 0x1C },
		{ "A3 家",								 0x1D },
		{ "A4 家",								 0x1E },
		{ "A5 家",								 0x1F },
		{ "A6 家",								 0x20 },
		{ "A7 家",								 0x21 },
		{ "A8 家",								 0x22 },
		{ "A9 家",								 0x23 },
		{ "役場",								 0x23 },
		{ "return error",						 0x28 },
		{ "Come to the village",				 0x2A },
		{ "R-Parkers",							 0x2B },
		{ "モダンな交番",						 0x30 },
		{ "クラシックな交番",					 0x31 },
		{ "カフェ",								 0x32 },
		{ "カフェ バイトイベント",				 0x33 },
		{ "夢見の館",							 0x37 },
		{ "デパート1階",						 0x3C },
		{ "デパート2階",						 0x3D },
		{ "デパート3階",						 0x3E },
		{ "エイブルシスターズ 服屋",			 0x3F },
		{ "エイブルシスターズ アクセ屋",		 0x40 },
		{ "Shoe Shank 靴屋",					 0x40 },
		{ "不動産屋",							 0x41 },
		{ "Club444",							 0x47 },
		{ "ビューティーサロン スピーディ",		 0x48 },
		{ "博物館 中央",						 0x49 },
		{ "博物館 魚",							 0x4A },
		{ "博物館 虫",							 0x4D },
		{ "博物館 化石",						 0x50 },
		{ "博物館 絵画",						 0x53 },
		{ "博物館 2階",							 0x55 },
		{ "博物館 2階 左上",					 0x56 },
		{ "博物館 2階 左下",					 0x57 },
		{ "博物館 2階 右上",					 0x58 },
		{ "博物館 2階 右下",					 0x59 },
		{ "郵便局",								 0x5A },
		{ "夢見の館",							 0x5B },
		{ "証明写真機",							 0x5C },
		{ "Train",								 0x5D },
		{ "Dream Bed Error",					 0x64 },
		{ "島へ行くイベント",					 0x65 },
		{ "村へ戻るイベント",					 0x66 },
		{ "島 室内",							 0x67 },
		{ "島 屋外",							 0x68 },
		{ "Go island",							 0x65 },
		{ "ハッピーホームアカデミー 中央",		 0x8E },
		{ "オートキャンプ場",					 0xA0 },
		{ "オートキャンプ場 キャンパーの車の中", 0xA1 },
		{ "しずえがいるエリア",					 0x63 },
		{ "タイトル",							 0x5E },
		{ "カメラ",								 0xa4 },
		{ "住民登録",							 0x5d },
		{ "オレンジテント",						 0x25 },
		{ "模様替えイベント",					 0xa3 },
		{ "釣り結果",							 0x2F },
	};
	// ---------------------------------------------------------------
	// エリア変更
	// ---------------------------------------------------------------
	void change_Area( MenuEntry *entry )
	{
		static StringVector items;

		if( items.empty() )
		for( const CHANGE_AREA &i: change_area )
			items.push_back( i.name );
		Keyboard keyboard( "指定した場所に移動。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x0095133A, change_area[choice].id );
		int loc;
		loc = *g_location;
		if( loc == -1 )
		{
			Process::Write16( 0x33099FB3, 0xC900 );
		}
		else {
			Process::Write32( 0x3309a0dc, 0x380FF138 );
			Process::Write32( 0x3309a0df, 0x380FF138 );
		}
	}
	
	// ---------------------------------------------------------------
	// 座標移動A+C-pad
	// ---------------------------------------------------------------
	void coordCType( MenuEntry *entry )
	{
		int		loc;
		float	outz;
		float	outx;
		float	inz;
		float	inx;
		Process::ReadFloat( 0x33099E58, outz );
		Process::ReadFloat( 0x33099E50, outx );
		Process::ReadFloat( 0x33099F84, inz );
		Process::ReadFloat( 0x33099F7C, inx );

		loc = *g_location;
		if( loc == -1 )
		{
			if( Controller::IsKeysDown(A + CPadUp) )
			{
				outz = outz - 9.0;
				Process::WriteFloat( 0x33099E58, outz );
			}
			if( Controller::IsKeysDown(A + CPadDown) )
			{
				outz = outz + 9.0;
				Process::WriteFloat( 0x33099E58, outz );
			}
			if( Controller::IsKeysDown(A + CPadLeft) )
			{
				outx = outx - 9.0;
				Process::WriteFloat( 0x33099E50, outx );
			}
			if( Controller::IsKeysDown(A + CPadRight) )
			{
				outx = outx + 9.0;
				Process::WriteFloat( 0x33099E50, outx );
			}
		}
		else {
			if( Controller::IsKeysDown(A + CPadUp) )
			{
				inz = inz - 9.0;
				Process::WriteFloat( 0x33099F84, inz );
			}
			if( Controller::IsKeysDown(A + CPadDown) )
			{
				inz = inz + 9.0;
				Process::WriteFloat( 0x33099F84, inz );
			}
			if( Controller::IsKeysDown(A + CPadLeft) )
			{
				inx = inx - 9.0;
				Process::WriteFloat( 0x33099F7C, inx );
			}
			if( Controller::IsKeysDown(A + CPadRight) )
			{
				inx = inx + 9.0;
				Process::WriteFloat( 0x33099F7C, inx );
			}
		}
	}
	
	// ---------------------------------------------------------------
	// 座標移動A+D-pad
	// ---------------------------------------------------------------
	void coord( MenuEntry *entry )
	{
		int		loc;
		float	outz;
		float	outx;
		float	inz;
		float	inx;
		Process::ReadFloat( 0x33099E58, outz );
		Process::ReadFloat( 0x33099E50, outx );
		Process::ReadFloat( 0x33099F84, inz );
		Process::ReadFloat( 0x33099F7C, inx );

		loc = *g_location;
		if( loc == -1 )
		{
			if( Controller::IsKeysDown(A + DPadUp) )
			{
				outz = outz - 9.0;
				Process::WriteFloat( 0x33099E58, outz );
			}
			if( Controller::IsKeysDown(A + DPadDown) )
			{
				outz = outz + 9.0;
				Process::WriteFloat( 0x33099E58, outz );
			}
			if( Controller::IsKeysDown(A + DPadLeft) )
			{
				outx = outx - 9.0;
				Process::WriteFloat( 0x33099E50, outx );
			}
			if( Controller::IsKeysDown(A + DPadRight) )
			{
				outx = outx + 9.0;
				Process::WriteFloat( 0x33099E50, outx );
			}
		}
		else {
			if( Controller::IsKeysDown(A + DPadUp) )
			{
				inz = inz - 9.0;
				Process::WriteFloat( 0x33099F84, inz );
			}
			if( Controller::IsKeysDown(A + DPadDown) )
			{
				inz = inz + 9.0;
				Process::WriteFloat( 0x33099F84, inz );
			}
			if( Controller::IsKeysDown(A + DPadLeft) )
			{
				inx = inx - 9.0;
				Process::WriteFloat( 0x33099F7C, inx );
			}
			if( Controller::IsKeysDown(A + DPadRight) )
			{
				inx = inx + 9.0;
				Process::WriteFloat( 0x33099F7C, inx );
			}
		}
	}
	
	// ---------------------------------------------------------------
	// 天気変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > Weather_Change =
	{
		{ 0xE1A00004, "通常" },
		{ 0xE3A00001, "晴れ" },
		{ 0xE3A00002, "曇り" },
		{ 0xE3A00003, "雨"	 },
		{ 0xE3A00004, "大雨" },
		{ 0xE3A00005, "雪"	 },
		{ 0xE3A00006, "大雪" },
	};
	void change_Weather( MenuEntry *entry )
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: Weather_Change )
			items.push_back( i.name );
		Keyboard keyboard( "指定した天気に変化。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write32( 0x0062E728, Weather_Change[choice].id );
	}
	
	// ---------------------------------------------------------------
	// 駅の旗大きさ変更
	// ---------------------------------------------------------------
	void frag_change( MenuEntry *entry )
	{
		float	fxx;

		Keyboard keyboard( Utils::Format("指定した旗のサイズに変化。/nデフォルト14.1421/nmin1.8750/nmax536870912") );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			if( fxx >= 1.8750 && fxx <= 536870912 ) Process::WriteFloat( 0x001C8CAC, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	// 高額買取品変更
	// ---------------------------------------------------------------
	void Change_Recycle1( MenuEntry *entry )
	{
		u16 fxx;

		Keyboard keyboard( "指定したアイテムに変化。" );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			Process::Write16( 0x31FB02A0, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	// 株価変更
	// ---------------------------------------------------------------
//	void Change_Recycle2( MenuEntry *entry )
//	{
//		u16 fxx;
//
//		Keyboard keyboard( "ItemIDを入力してください。" );
//		keyboard.IsHexadecimal( false );
//		u16 choice = keyboard.Open( fxx );
//		if( choice >= 0 )
//		{ // 入力あり
//			Process::Write16( 0x330DBE30, fxx );
//		}
//	}

	// ---------------------------------------------------------------
	// モーション変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U8_MAP > motion =
	{
		{ 0x00, "戻す"				   },
		{ 0x01, "口を開けて笑う"	   },
		{ 0x02, "爆笑する"			   },
		{ 0x03, "お花畑"			   },
		{ 0x04, "ハート"			   },
		{ 0x05, "ウキウキ"			   },
		{ 0x06, "にらむ"			   },
		{ 0x07, "むか"				   },
		{ 0x08, "プンプン"			   },
		{ 0x09, "困る"				   },
		{ 0x0A, "ため息"			   },
		{ 0x0B, "考える"			   },
		{ 0x0C, "がっくり"			   },
		{ 0x0D, "焦る"				   },
		{ 0x0E, "泣く"				   },
		{ 0x10, "びっくり"			   },
		{ 0x11, "驚く"				   },
		{ 0x12, "ガーン"			   },
		{ 0x13, "ヒュー"			   },
		{ 0x14, "振るえる"			   },
		{ 0x15, "うなずく"			   },
		{ 0x16, "ひらめいた"		   },
		{ 0x17, "はてな"			   },
		{ 0x18, "失恋"				   },
		{ 0x19, "あくび"			   },
		{ 0x1A, "照れる"			   },
		{ 0x1B, "やれやれ"			   },
		{ 0x1C, "悪だくみ"			   },
		{ 0x1D, "拍手"				   },
		{ 0x1E, "くしゃみ"			   },
		{ 0x20, "やぁ"				   },
		{ 0x21, "エッヘン"			   },
		{ 0x24, "苦笑い"			   },
		{ 0x26, "ニコッ"			   },
		{ 0x27, "もじもじ"			   },
		{ 0x28, "首を振る"			   },
		{ 0x29, "やらかしたー"		   },
		{ 0x2A, "くるりんぱ"		   },
		{ 0x2B, "想像する"			   },
		{ 0x2C, "シャキーン"		   },
		{ 0x2E, "スペシャル"		   },
		{ 0x0F, "没1驚く"			   }, // 色々使われてる
		{ 0x1F, "没2叫ぶ"			   }, // 村長が村に来た時に住民が「よ・う・こ・そ」と叫ぶときのモーション
		{ 0x22, "没3汗をかく"		   }, // 暑い日にそのプレイヤーが初めにやるモーション
		{ 0x23, "没4シャキン"		   }, // 色々使われてる
		{ 0x25, "没5ニコニコ"		   }, // 住民が追いかけてくるとき
		{ 0x2D, "没6寝る"			   }, // 村が雑草まみれの時にれいじが村にいるときor博物館のフクロウ
		{ 0x2F, "没7倒れる"			   }, // ジョニーが浜辺にいるとき
		{ 0x30, "没8埋まって怒る"	   }, // 謎
		{ 0x32, "没9埋まってヒュー"    }, // 謎
		{ 0x33, "没10埋まってびっくり" }, // 謎
		{ 0x34, "没11埋まってにらむ"   }, // 顔出し看板？
		{ 0x35, "没12埋まっててへぺろ" }, // 顔出し看板？
		{ 0x36, "没13埋まって激怒"	   }, // リセットさんのモーション？
		{ 0x37, "没14埋まって真剣"	   }, // リセットさんのモーション？
		{ 0x38, "没15けいれい"		   }, // 交番の警官がやるモーション
		{ 0x3B, "没16無表情びっくり"   }, // 謎
		{ 0x3E, "没17紫もやもや"	   }, // 占いの館のモーション
		{ 0x3F, "没18どれどれ"		   }, // 博物館で鑑定するときのモーション
		{ 0x40, "没19お化粧"		   }, // 謎
	};
	void Motion1( MenuEntry *entry )//駅員
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: motion )
			items.push_back( i.name );
		Keyboard keyboard( "指定したモーションに変化", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) motion_ekiin = motion[choice].id;
	}
	
	void Motion2( MenuEntry *entry )//かっぺい
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: motion )
			items.push_back( i.name );
		Keyboard keyboard( "指定したモーションに変化。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) motion_kappei = motion[choice].id;
	}
	
	void Motion3( MenuEntry *entry )//しずえ(室内)
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: motion )
			items.push_back( i.name );
		Keyboard keyboard( "指定したモーションに変化。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) motion_sizue_indoor = motion[choice].id;
	}
	
	void Motion4( MenuEntry *entry )//しずえ(室外)
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: motion )
			items.push_back( i.name );
		Keyboard keyboard( "指定したモーションに変化。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) motion_sizue_outdoor = motion[choice].id;
	}
	
	void Motion5( MenuEntry *entry )//リサ
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: motion )
			items.push_back( i.name );
		Keyboard keyboard( "指定したモーションに変化。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) motion_risa = motion[choice].id;
	}
	
	void Motion6( MenuEntry *entry )//ケイト
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: motion )
			items.push_back( i.name );
		Keyboard keyboard( "指定したモーションに変化。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) motion_keito = motion[choice].id;
	}
	
	void Motion7( MenuEntry *entry )//タヌキチ
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: motion )
			items.push_back( i.name );
		Keyboard keyboard( "指定したモーションに変化。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) motion_tanukiti = motion[choice].id;
	}
	
//	//---------------------------------------------------------------
//	// 	モーション
//	//---------------------------------------------------------------
//		{ 0x00000000, "カイゾー" },
//		{ 0x00000000, "" },

	// ---------------------------------------------------------------
	// 連続アクション
	// ---------------------------------------------------------------
	void Reaction1( MenuEntry *entry )
	{
		u32 a;
		{
			set_action_32_not_indoor( 0x7C7B7C00 ); // 	アクショ実行
		}
	}
	
	// ---------------------------------------------------------------
	// 村の明るさ変更
	// ---------------------------------------------------------------
	void akarusa_change( MenuEntry *entry )
	{
		float	fxx;

		Keyboard keyboard( Utils::Format("指定した明るさに変化。") );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			Process::WriteFloat( 0x001E6CB4, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	// タイマーチート虫
	// ---------------------------------------------------------------
	void Taima_musi( MenuEntry *entry )
	{
		u32 fxx;

		Keyboard keyboard( "指定した虫の数に変化。" );
		keyboard.IsHexadecimal( false );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			Process::Write32( 0x0094A724, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	// タイマーチート魚
	// ---------------------------------------------------------------
	void Taima_sakana( MenuEntry *entry )
	{
		u32 fxx;

		Keyboard keyboard( "指定した魚の数に変化。" );
		keyboard.IsHexadecimal( false );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			Process::Write32( 0x0094A72C, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	// タイマーチート海の幸
	// ---------------------------------------------------------------
	void Taima_uminosati( MenuEntry *entry )
	{
		u32 fxx;

		Keyboard keyboard( "指定した海の幸の数に変化。" );
		keyboard.IsHexadecimal( false );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			Process::Write32( 0x0094A728, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	// 室外アイテム判定変更　Freg
	// ---------------------------------------------------------------
	void Change_Item_Frag( MenuEntry *entry )
	{
		u16 fxx;

		Keyboard keyboard( "指定したFragに変化。" );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			Process::Write16( 0x009AE248, fxx );
			Process::Write16( outdoor_Frag, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	// 室外アイテム判定変更　
	// ---------------------------------------------------------------
	void Change_Item( MenuEntry *entry )
	{
		u16 fxx;

		Keyboard keyboard( "指定したアイテムに変化。" );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			Process::Write16( 0x009AE24B, fxx );
			Process::Write16( outdoor_item, fxx );
		}
	}
	
	// ------------------------------------------------------------------
	// 室外アイテム固定
	// ------------------------------------------------------------------
	void Change_Item_kotei( MenuEntry *entry )
	{
		if( outdoor_Frag ) *(u16 *)0x009AE248 = outdoor_Frag;
		if( outdoor_item ) *(u16 *)0x009AE24B = outdoor_item;
	}
	
	// ---------------------------------------------------------------
	// 性別変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U8_MAP > seibetu =
	{
		{ 0x00, "男" },
		{ 0x01, "女" },
	};
	void change_seibetu( MenuEntry *entry )
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: seibetu )
			items.push_back( i.name );
		Keyboard keyboard( "指定した性別に変化。", items );
		int choice = keyboard.Open();
		u32 a;
		if( Process::Read32(0x00AA914C, a) && a == 0x31F49AA0 )
			if( choice >= 0 ) Process::Write8( 0x31F4F05A, seibetu[choice].id );
		if( Process::Read32(0x00AA914C, a) && a == 0x31F53F20 )
			if( choice >= 0 ) Process::Write8( 0x31F594DA, seibetu[choice].id );
		if( Process::Read32(0x00AA914C, a) && a == 0x31F5E3A0 )
			if( choice >= 0 ) Process::Write8( 0x31F6395A, seibetu[choice].id );
		if( Process::Read32(0x00AA914C, a) && a == 0x31F68820 )
			if( choice >= 0 ) Process::Write8( 0x31F6DDDA, seibetu[choice].id );
	}
	
	//----------------------------------------------------------------
	// 1.1
	// ---------------------------------------------------------------
	
	// ---------------------------------------------------------------
	// バッジ変更
	// ---------------------------------------------------------------
	struct	aiueo
	{
		const u32	hex;
		const u32	hex2;
		const u32	hex3;
		const u32	hex4;
		const u32	hex5;
		const u32	hex6;
		const char	*name;
	};
	static const	std::vector< aiueo > badge =
	{
		{ 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, "なし" },
		{ 0x01010101, 0x01010101, 0x01010101, 0x01010101, 0x01010101, 0x01010101, "銅"	 },
		{ 0x02020202, 0x02020202, 0x02020202, 0x02020202, 0x02020202, 0x02020202, "銀"	 },
		{ 0x03030303, 0x03030303, 0x03030303, 0x03030303, 0x03030303, 0x03030303, "金"	 },
	};
	void change_badge( MenuEntry *entry )
	{
		static StringVector no;
		u32					a;
		no.clear();
		for( const aiueo &i: badge ) no.push_back( i.name );
		Keyboard keyboard( "指定したバッジに変化。", no );
		int choice = keyboard.Open();
		if( choice >= 0 )
		{
			if( Process::Read32(0x00AA914C, a) && a == 0x31F49AA0 )
			{ // P1
				Process::Write32( 0x31F4F13C, badge[choice].hex );
				Process::Write32( 0x31F4F140, badge[choice].hex2 );
				Process::Write32( 0x31F4F144, badge[choice].hex3 );
				Process::Write32( 0x31F4F148, badge[choice].hex4 );
				Process::Write32( 0x31F4F14C, badge[choice].hex5 );
				Process::Write32( 0x31F4F150, badge[choice].hex6 );
			}
			else if( Process::Read32(0x00AA914C, a) && a == 0x31F53F20 )
			{ // P2
				Process::Write32( 0x31F595BC, badge[choice].hex );
				Process::Write32( 0x31F595C0, badge[choice].hex2 );
				Process::Write32( 0x31F595C4, badge[choice].hex3 );
				Process::Write32( 0x31F595C8, badge[choice].hex4 );
				Process::Write32( 0x31F595CC, badge[choice].hex5 );
				Process::Write32( 0x31F595D0, badge[choice].hex6 );
			}
			else if( Process::Read32(0x00AA914C, a) && a == 0x31F5E3A0 )
			{ // P3
				Process::Write32( 0x31F63A3C, badge[choice].hex );
				Process::Write32( 0x31F63A40, badge[choice].hex2 );
				Process::Write32( 0x31F63A44, badge[choice].hex3 );
				Process::Write32( 0x31F63A48, badge[choice].hex4 );
				Process::Write32( 0x31F63A4C, badge[choice].hex5 );
				Process::Write32( 0x31F63A50, badge[choice].hex6 );
			}
			else if( Process::Read32(0x00AA914C, a) && a == 0x31F68820 )
			{ // P4
				Process::Write32( 0x31F6DEBC, badge[choice].hex );
				Process::Write32( 0x31F6DEC0, badge[choice].hex2 );
				Process::Write32( 0x31F6DEC4, badge[choice].hex3 );
				Process::Write32( 0x31F6DEC8, badge[choice].hex4 );
				Process::Write32( 0x31F6DECC, badge[choice].hex5 );
				Process::Write32( 0x31F6DED0, badge[choice].hex6 );
			}
		}
	}
	
	// ---------------------------------------------------------------
	// 無人島歩数変更P1
	// ---------------------------------------------------------------
	void mujintou_hosuuP1( MenuEntry *entry )
	{
		u32 fxx;

		Keyboard keyboard( "指定した歩数に変化。" );
		keyboard.IsHexadecimal( false );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			hosuuP1 = fxx;
			Process::Write32( 0x330C5324, fxx );
			Process::Write32( hosuuP1, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	// 無人島歩数変更P2
	// ---------------------------------------------------------------
	void mujintou_hosuuP2( MenuEntry *entry )
	{
		u32 fxx;

		Keyboard keyboard( "指定した歩数に変化。" );
		keyboard.IsHexadecimal( false );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			hosuuP2 = fxx;
			Process::Write32( 0x330C577C, fxx );
			Process::Write32( hosuuP2, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	// 無人島歩数変更P3
	// ---------------------------------------------------------------
	void mujintou_hosuuP3( MenuEntry *entry )
	{
		u32 fxx;

		Keyboard keyboard( "歩数を指定してください。" );
		keyboard.IsHexadecimal( false );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			hosuuP3 = fxx;
			Process::Write32( 0x330C5BD4, fxx );
			Process::Write32( hosuuP3, fxx );
		}
	}
	
	// ------------------------------------------------------------------
	// 歩数固定
	// ------------------------------------------------------------------
	void hosuukotei( MenuEntry *entry )
	{
		if( hosuuP1 ) *(u32 *)0x330C5324 = hosuuP1;
		if( hosuuP2 ) *(u32 *)0x330C577C = hosuuP2;
		if( hosuuP3 ) *(u32 *)0x330C5BD4 = hosuuP3;
	}
	
	// ---------------------------------------------------------------
	// ステージ開放
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > mujinntou_stage =
	{
		{ 0x00000000, "無開放"		  },
		{ 0x00000002, "初級1まで解放" },
		{ 0x00000022, "初級2まで解放" },
		{ 0x00000222, "初級3まで解放" },
		{ 0x00000262, "初級4まで解放" },
		{ 0x00000362, "初級5まで解放" },
		{ 0x00000372, "初級6まで解放" },
		{ 0x000003FA, "初級8まで解放" },
		{ 0x000003FB, "初級9まで解放" },
		{ 0x000003FF, "初級全開放"	  },
		{ 0xFFFFFFFF, "全開放"		  },
	};
	void mujinntou_stage_open( MenuEntry *entry )
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: mujinntou_stage )
			items.push_back( i.name );
		Keyboard keyboard( "ステージ開放率を指定してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write32( 0x330B110C, mujinntou_stage[choice].id );
	}
	
	// ---------------------------------------------------------------
	// 無人島歩く時のスコア変更
	// ---------------------------------------------------------------
	void mujintou_WalkScore( MenuEntry *entry )
	{
		u32 fxx;

		Keyboard keyboard( "スコアを指定してください。" );
		keyboard.IsHexadecimal( false );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			change_WalkScore = fxx;
			Process::Write32( 0x330BB078, fxx );
			Process::Write32( change_WalkScore, fxx );
		}
	}
	
	// ------------------------------------------------------------------
	// 無人島歩く時のスコア固定
	// ------------------------------------------------------------------
	void Walkscore_kotei( MenuEntry *entry )
	{
		if( change_WalkScore ) *(u16 *)0x330BB078 = change_WalkScore; // 無人島歩いた時のスコア変更
	}
	
	// ---------------------------------------------------------------
	// 無人島棒所持数変更
	// ---------------------------------------------------------------
	void mujintou_Item1( MenuEntry *entry )
	{
		u8 fxx;

		Keyboard keyboard( "所持数を指定してください" );
		keyboard.IsHexadecimal( false );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			Process::Write8( 0x330BE3C8, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	// 無人島糸所持数変更
	// ---------------------------------------------------------------
	void mujintou_Item2( MenuEntry *entry )
	{
		u8 fxx;

		Keyboard keyboard( "所持数を指定してください" );
		keyboard.IsHexadecimal( false );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			Process::Write8( 0x330BE3CC, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	// 無人島布きれ所持数変更
	// ---------------------------------------------------------------
	void mujintou_Item3( MenuEntry *entry )
	{
		u8 fxx;

		Keyboard keyboard( "所持数を指定してください" );
		keyboard.IsHexadecimal( false );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			Process::Write8( 0x330BE3D0, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	// 無人島石ころ所持数変更
	// ---------------------------------------------------------------
	void mujintou_Item4( MenuEntry *entry )
	{
		u8 fxx;

		Keyboard keyboard( "所持数を指定してください" );
		keyboard.IsHexadecimal( false );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			Process::Write8( 0x330BE3D8, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	// 無人島ぎんこうせき所持数変更
	// ---------------------------------------------------------------
	void mujintou_Item5( MenuEntry *entry )
	{
		u8 fxx;

		Keyboard keyboard( "所持数を指定してください" );
		keyboard.IsHexadecimal( false );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			Process::Write8( 0x330BE3DC, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	// 無人島きんこうせき所持数変更
	// ---------------------------------------------------------------
	void mujintou_Item6( MenuEntry *entry )
	{
		u8 fxx;

		Keyboard keyboard( "所持数を指定してください" );
		keyboard.IsHexadecimal( false );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			Process::Write8( 0x330BE3E0, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	// 無人島おくすり所持数変更
	// ---------------------------------------------------------------
	void mujintou_Item7( MenuEntry *entry )
	{
		u8 fxx;

		Keyboard keyboard( "所持数を指定してください" );
		keyboard.IsHexadecimal( false );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			Process::Write8( 0x330BE3D4, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	// 丸太入手数変更
	// ---------------------------------------------------------------
	void mujintou_hoof1( MenuEntry *entry )
	{
		u32 fxx;

		Keyboard keyboard( "入手数を指定してください" );
		keyboard.IsHexadecimal( false );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			Process::Write32( 0x330BE3E4, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	// 船の旗入手数変更
	// ---------------------------------------------------------------
	void mujintou_hoof2( MenuEntry *entry )
	{
		u32 fxx;

		Keyboard keyboard( "入手数を指定してください" );
		keyboard.IsHexadecimal( false );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			Process::Write32( 0x330BE3E8, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	// 丸太残りの数変更
	// ---------------------------------------------------------------
	void mujintou_hoof3( MenuEntry *entry )
	{
		u32 fxx;

		Keyboard keyboard( "残りの数を指定してください" );
		keyboard.IsHexadecimal( false );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			Process::Write32( 0x330E0FF0, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	// 船の旗残りの数変更
	// ---------------------------------------------------------------
	void mujintou_hoof4( MenuEntry *entry )
	{
		u32 fxx;

		Keyboard keyboard( "残りの数を指定してください" );
		keyboard.IsHexadecimal( false );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			Process::Write32( 0x330E0FF8, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	//  無人島ツール
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U8_MAP > Mujiontou_Tools =
	{
		{ 0x01, "入手" },
		{ 0x00, "未入手" },
	};
	void mujintou_Tool1( MenuEntry *entry )//釣り竿
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: Mujiontou_Tools )
			items.push_back( i.name );
		Keyboard keyboard( "このアイテムを入手しますか？", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x330BC2DC, Mujiontou_Tools[choice].id );
	}
	
	void mujintou_Tool2( MenuEntry *entry )//パチンコ
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: Mujiontou_Tools )
			items.push_back( i.name );
		Keyboard keyboard( "このアイテムを入手しますか？", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x330BC2E0, Mujiontou_Tools[choice].id );
	}
	
	void mujintou_Tool3( MenuEntry *entry )//網
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: Mujiontou_Tools )
			items.push_back( i.name );
		Keyboard keyboard( "このアイテムを入手しますか？", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x330BC2E4, Mujiontou_Tools[choice].id );
	}
	
	void mujintou_Tool4( MenuEntry *entry )//スコップ
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: Mujiontou_Tools )
			items.push_back( i.name );
		Keyboard keyboard( "このアイテムを入手しますか？", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x330BC2E8, Mujiontou_Tools[choice].id );
	}
	
	void mujintou_STool1( MenuEntry *entry )//銀の釣り竿
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: Mujiontou_Tools )
			items.push_back( i.name );
		Keyboard keyboard( "このアイテムを入手しますか？", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x330BC2EC, Mujiontou_Tools[choice].id );
	}
	
	void mujintou_STool2( MenuEntry *entry )//銀のパチンコ
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: Mujiontou_Tools )
			items.push_back( i.name );
		Keyboard keyboard( "このアイテムを入手しますか？", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x330BC2F0, Mujiontou_Tools[choice].id );
	}
	
	void mujintou_STool3( MenuEntry *entry )//銀の網
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: Mujiontou_Tools )
			items.push_back( i.name );
		Keyboard keyboard( "このアイテムを入手しますか？", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x330BC2F4, Mujiontou_Tools[choice].id );
	}
	
	void mujintou_STool4( MenuEntry *entry )//銀のスコップ
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: Mujiontou_Tools )
			items.push_back( i.name );
		Keyboard keyboard( "このアイテムを入手しますか？", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x330BC2F8, Mujiontou_Tools[choice].id );
	}
	
	void mujintou_GTool1( MenuEntry *entry )//金の釣り竿
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: Mujiontou_Tools )
			items.push_back( i.name );
		Keyboard keyboard( "このアイテムを入手しますか？", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x330BC2FC, Mujiontou_Tools[choice].id );
	}
	
	void mujintou_GTool2( MenuEntry *entry )//金のパチンコ
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: Mujiontou_Tools )
			items.push_back( i.name );
		Keyboard keyboard( "このアイテムを入手しますか？", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x330BC300, Mujiontou_Tools[choice].id );
	}
	
	void mujintou_GTool3( MenuEntry *entry )//金の網
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: Mujiontou_Tools )
			items.push_back( i.name );
		Keyboard keyboard( "このアイテムを入手しますか？", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x330BC304, Mujiontou_Tools[choice].id );
	}
	
	void mujintou_GTool4( MenuEntry *entry )//金のスコップ
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: Mujiontou_Tools )
			items.push_back( i.name );
		Keyboard keyboard( "このアイテムを入手しますか？", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x330BC308, Mujiontou_Tools[choice].id );
	}
	
	// ---------------------------------------------------------------
	// 残り日数変更
	// ---------------------------------------------------------------
	void mujintou_hizuke1( MenuEntry *entry )
	{
		u32 fxx;

		Keyboard keyboard( "残り日数を指定してください。" );
		keyboard.IsHexadecimal( false );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			Process::Write32( 0x330B1798, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	// 経過日数変更
	// ---------------------------------------------------------------
	void mujintou_hizuke2( MenuEntry *entry )
	{
		u32 fxx;

		Keyboard keyboard( "経過日数を指定してください。" );
		keyboard.IsHexadecimal( false );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			Process::Write32( 0x330B1794, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	// 食料落下数変更
	// ---------------------------------------------------------------
	void mujintou_syokuryou1( MenuEntry *entry )
	{
		u32 fxx;

		Keyboard keyboard( "食料落下数を指定してください。" );
		keyboard.IsHexadecimal( false );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			Process::Write32( 0x330F9080, fxx );
		}
	}

	// ---------------------------------------------------------------
	// リンゴゲージ変更
	// ---------------------------------------------------------------
	void mujintou_syokuryou2( MenuEntry *entry )
	{
		u32 fxx;

		Keyboard keyboard( "リンゴゲージを指定してください。" );
		keyboard.IsHexadecimal( false );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			Process::Write32( 0x330E0FDC, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	// 食料所持数変更
	// ---------------------------------------------------------------
	void mujintou_syokuryou3( MenuEntry *entry )
	{
		u32 fxx;

		Keyboard keyboard( "食料所持数を指定してください。" );
		keyboard.IsHexadecimal( false );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
			Process::Write32( 0x330E0FD8, fxx );
		}
	}
	
	// ---------------------------------------------------------------
	// 落とし穴無効化
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U8_MAP > Mujiontou_otosiana =
	{
		{ 0x01, "無効化" },
		{ 0x00, "有効化" },
	};
	void mujintou_Otosiana( MenuEntry *entry )//釣り竿
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U8_MAP &i: Mujiontou_otosiana )
			items.push_back( i.name );
		Keyboard keyboard( "落とし穴から抜け出しますか？", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x330F9078, Mujiontou_otosiana[choice].id );
	}
	
	// ---------------------------------------------------------------
	// 住民特技変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > Mujiontou_tokugi =
	{
		{ 0x00, "ランナー" },
		{ 0x01, "探偵" },
		{ 0x02, "ハニーモンター" },
		{ 0x04, "釣り名人" },
		{ 0x08, "料理人" },
		{ 0x10, "食いしん坊" },
		{ 0x20, "気まぐれ" },
		{ 0x40, "寝だめ" },
		{ 0x80, "怪力" },
		{ 0x100, "水泳" },
		{ 0x200, "ハンター" },
		{ 0x400, "飛行" },
		{ 0x800, "トンネル" },
		{ 0x1000, "忍び足" },
		{ 0x2000, "応急処置" },
		{ 0x4000, "衝突猛進" },
		{ 0x8000, "器用" },
		{ 0x10000, "一匹狼" },
	
	};
	void mujintou_TokugiP1( MenuEntry *entry )//P
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: Mujiontou_tokugi )
			items.push_back( i.name );
		Keyboard keyboard( "特技を選択してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write32( 0x330C5240, Mujiontou_tokugi[choice].id );
	}
	void mujintou_TokugiP2( MenuEntry *entry )//P2
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: Mujiontou_tokugi )
			items.push_back( i.name );
		Keyboard keyboard( "特技を選択してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write32( 0x330C5698, Mujiontou_tokugi[choice].id );
	}
	void mujintou_TokugiP3( MenuEntry *entry )//P3
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: Mujiontou_tokugi )
			items.push_back( i.name );
		Keyboard keyboard( "特技を選択してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write32( 0x330C5AF0, Mujiontou_tokugi[choice].id );
	}
	
	// ---------------------------------------------------------------
	// 住民好きな食べ物変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > Mujiontou_Food =
	{
		{ 0xE0300, "桃" },
		{ 0x20B00, "ヤシの実" },
		{ 0x10600, "レモン" },
		{ 0x40500, "ドリアン" },
		{ 0x30000, "リンゴ" },
		{ 0x80100, "オレンジ" },
		{ 0x50200, "梨" },
		{ 0x100A00, "バナナ" },
		{ 0x90700, "ライチ" },
		{ 0xA0900, "柿" },
		{ 0xC0800, "マンゴー" },
		{ 0xF0000, "好きな食べ物ない" },
	
	};
	void mujintou_FoodP1( MenuEntry *entry )//P1
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: Mujiontou_Food )
			items.push_back( i.name );
		Keyboard keyboard( "好きな食べ物を選択してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write32( 0x330C5244, Mujiontou_Food[choice].id );
	}
	void mujintou_FoodP2( MenuEntry *entry )//P2
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: Mujiontou_Food )
			items.push_back( i.name );
		Keyboard keyboard( "好きな食べ物を選択してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write32( 0x330C569C, Mujiontou_Food[choice].id );
	}
	void mujintou_FoodP3( MenuEntry *entry )//P3
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: Mujiontou_Food )
			items.push_back( i.name );
		Keyboard keyboard( "好きな食べ物を選択してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write32( 0x330C5AF4, Mujiontou_Food[choice].id );
	}
	
	// ---------------------------------------------------------------
	//  ゲームスピード上昇
	// ---------------------------------------------------------------
	void change_gamespeed( MenuEntry *entry )
	{
		Process::Write32( 0x32939920, 0x00006000 );
	}
	
	// ---------------------------------------------------------------
	// 芝生の濃さ変更
	// ---------------------------------------------------------------
	void sibahu( MenuEntry *entry )
	{
		u8 fxx;
		u8 *a;

		Keyboard keyboard( "指定した濃さに変更。" );
		int choice = keyboard.Open( fxx );
		if( choice >= 0 )
		{ // 入力あり
//			if( a >= 0x31FA3300 && a <= 0x31FA5AFC ) Process::Write32( a, fxx );
			for( a = (u8 *)0x31FA3300; a <= (u8 *)0x31FA5AFF; a++ ) *a = fxx;
		}
	}
// -------------------------------------------------------------------
// 村/商店街の座標からmemory位置を計算
// -------------------------------------------------------------------
	u32 get_pos1( u32 x, u32 y )
	{
		u32 reg0;
		u32 reg1;

		reg0 = x % 0x10;
		x /= 0x10;
		reg1 = y % 0x10;
		y /= 0x10;
		reg0 *= 0x4;	// *4
		reg1 *= 0x40;	// *16*4
		x *= 0x400;		// *16*4
		y *= 0x1400;	// *80*4
		return( reg0 + reg1 + x + y );
	}
// ---------------------------------------------------------
struct ITEM_MAP {
	u16			code;
	const char	*name1; // 表示用
	const char	*name2; // 検索用
};
	//1.2
	// ---------------------------------------------------------------
	// 歩いたところに物を置く
	// ---------------------------------------------------------------
	void walk_put_item( MenuEntry *entry )
	{
		u32 *g_town_items = (u32 *)0x31F9CED8;
		u32	*g_my_inv = (u32 *)0x31F50670;
		float *g_outdoor_pos_x = (float *)0x33099E50;
		float *g_outdoor_pos_y = (float *)0x33099E58;
		float *g_indoor_pos_x = (float *)0x33099F7C;
		float *g_indoor_pos_y = (float *)0x33099F84;
		u8	*g_room0 = (u8 *)0x319C265C;

		float		*tmp_pos_x, *tmp_pos_y;
		int			x, y;
		u32			offset;

		if( *g_location == -1 )
		{ // 室外
			tmp_pos_x = g_outdoor_pos_x;
			tmp_pos_y = g_outdoor_pos_y;
		}
		else { // 室内
			tmp_pos_x = g_indoor_pos_x;
			tmp_pos_y = g_indoor_pos_y;
		}
		x = (int)( *tmp_pos_x / 0x20 );
		y = (int)( *tmp_pos_y / 0x20 );

		if( *g_room0 == 0x00 )
		{ // 外,地上
			if( x >= 16 && x < 96 && y >= 16 && y < 90 )
			{
				x -= 0x10;					// offset
				y -= 0x10;					// offset
				offset = get_pos1( x, y );	// 村
				g_town_items[offset / sizeof( u32 )] = *g_my_inv;
			}
		}
	}
	
	// ---------------------------------------------------------------
	// 広場の木サイズ変更
	// ---------------------------------------------------------------
	static const	std::vector< CHARS_U32_MAP > Tree size =
	{
		{ 0x00, "植えたて" },
		{ 0x01, "一段階目" },
		{ 0x02, "二段階目" },
		{ 0x03, "三段階目" },
		{ 0x04, "四段階目" },
		{ 0x05, "五段階目" },
		{ 0x06, "六段階目" },
		{ 0x07, "最終段階" },
	};
	void Tree_size_change( MenuEntry *entry )
	{
		items.clear();
		if( items.empty() )
		for( const CHARS_U32_MAP &i: Tree_size )
			items.push_back( i.name );
		Keyboard keyboard( "木のサイズを選択してください。", items );
		int choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x31F95886, Tree_size[choice].id );
	}
}
