//#include <sys/stat.h>
#include "types.h"
#include "cheats.hpp"
#include "CTRPluginFramework/Graphics/OSD.hpp"

namespace    CTRPluginFramework
{
	using StringVector = std::vector<std::string>;


	//---------------------------------------------------------------
	// 宣言、定義
	//---------------------------------------------------------------
	u8 motion_ekiin;


	//---------------------------------------------------------------
	// プレイヤー変更
	//---------------------------------------------------------------
	struct CHANGE_PLAYER
	{
		const char  *name;
		const u32	id;
	};
	static const std::vector<CHANGE_PLAYER> change_player =
	{
		{ "村長", 0x31F49AA0 },
		{ "サブ1", 0x31F53F20 },
		{ "サブ2", 0x31F5E3A0 },
		{ "サブ3", 0x31F68820 },
	};
	//---------------------------------------------------------------
	void	change_Player(MenuEntry *entry)
	{
		static StringVector items;

		if (items.empty()) for (const CHANGE_PLAYER &i : change_player) items.push_back(i.name);

		Keyboard	keyboard("プレイヤーを選んでください。", items);
		int		 aachoice = keyboard.Open();

		if (aachoice >= 0) Process::Write32(0x00AA914C, change_player[aachoice].id);
	}

	//---------------------------------------------------------------
	// 空気椅子
	//---------------------------------------------------------------
    void	Action1(MenuEntry *entry)
    {
        u32 a;
		if (entry->Hotkeys[0].IsDown())
		{
			if(Process::Read32(0x33099F84, a) && a == -1)//33099F84が-1の時
				Process::Write8(0x33099FE5, 0xAA);//これを実行する
			else//33099F84が-1以外の時
				Process::Write8(0x3309A111, 0xAA);//これを実行する
		}
    }
    //---------------------------------------------------------------
    // 前転
    //---------------------------------------------------------------
    void    Action2(MenuEntry *entry)
    {
        u32 a;
        if (entry->Hotkeys[0].IsDown())
        {
            if(Process::Read32(0x33099F84, a) && a == -1)
			{
                Process::Write8(0x33099FE5, 0x60);
                Process::Write32(0x33099FC0, 0x00000000);
			}
            else
                Process::Write8(0x3309A111, 0x60);
        }
    }
	//---------------------------------------------------------------
	// 尻もち
	//---------------------------------------------------------------
	void	Action3(MenuEntry *entry)
    {
        u32 a;
		if (entry->Hotkeys[0].IsDown())
		{
			if(Process::Read32(0x33099F84, a) && a == -1)
				Process::Write8(0x33099FE5, 0xB3);
			else
				Process::Write8(0x3309A111, 0xB3);
		}
    }
	//---------------------------------------------------------------
	// 黒くなって地面から出る
	//---------------------------------------------------------------
	void	Action4(MenuEntry *entry)
    {
        u32 a;
		if (entry->Hotkeys[0].IsDown())
		{
			if(Process::Read32(0x33099F84, a) && a == -1)
				Process::Write8(0x33099FE5, 0x22);
			else
				Process::Write8(0x3309A111, 0x22);
		}
    }
	//---------------------------------------------------------------
	// アイテムを捕まえた
	//---------------------------------------------------------------
	void	Action5(MenuEntry *entry)
    {
        u32 a;
		if (entry->Hotkeys[0].IsDown())
		{
			if(Process::Read32(0x33099F84, a) && a == -1)
				Process::Write8(0x33099FE5, 0x23);
			else
				Process::Write8(0x3309A111, 0x23);
		}
    }
	//---------------------------------------------------------------
	// クラゲ回避
	//---------------------------------------------------------------
	void	Action6(MenuEntry *entry)
    {
        u32 a;
		if (entry->Hotkeys[0].IsDown())
		{
			if(Process::Read32(0x33099F84, a) && a == -1)
				Process::Write8(0x33099FE5, 0x27);
			else
				Process::Write8(0x3309A111, 0x27);
		}
    }
	//---------------------------------------------------------------
	// リアクション四連発
	//---------------------------------------------------------------
	void	Action7(MenuEntry *entry)
    {
        u32 a;
		if (entry->Hotkeys[0].IsDown())
		{
			if(Process::Read32(0x33099F84, a) && a == -1)
				Process::Write8(0x33099FE5, 0xD6);
			else
				Process::Write8(0x3309A111, 0xD6);
		}
    }
	//---------------------------------------------------------------
	// 赤バラ表示
	//---------------------------------------------------------------
	void	Action8(MenuEntry *entry)
    {
		if (entry->Hotkeys[0].IsDown())
		{
				Process::Write8(0x33099FE5, 0x72);
		}
    }
	//---------------------------------------------------------------
	// 綿毛を吐く
	//---------------------------------------------------------------
	void	Action9(MenuEntry *entry)
    {
        u32 a;
		if (entry->Hotkeys[0].IsDown())
		{
			if(Process::Read32(0x33099F84, a) && a == -1)
				Process::Write8(0x33099FE5, 0x90);
			else
				Process::Write8(0x3309A111, 0x90);
		}
    }
	//---------------------------------------------------------------
	// 頭がピッカーん
	//---------------------------------------------------------------
	void	Action10(MenuEntry *entry)
    {
        u32 a;
		if (entry->Hotkeys[0].IsDown())
		{
			if(Process::Read32(0x33099F84, a) && a == -1)
				Process::Write8(0x33099FE5, 0xC0);
			else
				Process::Write8(0x3309A111, 0xC0);
		}
    }
	//---------------------------------------------------------------
	// かっぺいのボートに立って乗る
	//---------------------------------------------------------------
	void	Action12(MenuEntry *entry)
    {
		{
			Process::Write32(0x33099FE4, 0xBDBCBD00);
		}
	}		
	//---------------------------------------------------------------
	// 気絶
	//---------------------------------------------------------------
	void    Action14(MenuEntry *entry)
{
    u32 kizetu;
    u32 kizetuin;
    if (entry->Hotkeys[0].IsDown())
    {
        if(Process::Read32(0x33099F84, kizetu))
        {
            if(kizetu == -1)
            {
                Process::Write32(0x33099FE4, 0x066B0600);
                Process::Write32(0x33099FB4, 0x00038001);
                Process::Write32(0x33099FB0, 0x00000036);    
            }
        }

        
        if(Process::Read32(0x3309A0A8, kizetuin))
        {
            if(kizetuin == -1)
            {
                Process::Write32(0x3309A110, 0x066B0600);
                Process::Write32(0x3309A0E0, 0x00038001);
                Process::Write32(0x3309A0DC, 0x00000036);
            }    
        }    
    }
}
	//---------------------------------------------------------------
	// アクション停止
	//---------------------------------------------------------------
	void	Action13(MenuEntry *entry)
    {
        u32 a;
		if (entry->Hotkeys[0].IsDown())
		{
			if(Process::Read32(0x33099F84, a) && a == -1)
				Process::Write8(0x33099FE5, 0x06);
			else
				Process::Write8(0x3309A111, 0x06);
		}
    }
	//---------------------------------------------------------------
	// 受け取る
	//---------------------------------------------------------------
	void	Action15(MenuEntry *entry)
    {
        u32 a;
		if (entry->Hotkeys[0].IsDown())
		{
			if(Process::Read32(0x33099F84, a) && a == -1)
				Process::Write32(0x33099FE4, 0x060F7500);
			else
				Process::Write32(0x3309A110, 0x060F7500);
		}
    }
	//---------------------------------------------------------------
	// かっぺいのボートに座って乗る
	//---------------------------------------------------------------
	void	Action16(MenuEntry *entry)
    {
		if (entry->Hotkeys[0].IsDown())
		{
			Process::Write32(0x33099FE4, 0x06BBBC00);
		}
	}
	//---------------------------------------------------------------
	// 泳ぐ
	//---------------------------------------------------------------
    void	Action18(MenuEntry *entry)
    {
        u32 a;
		if (entry->Hotkeys[0].IsDown())
		{
			if(Process::Read32(0x33099F84, a) && a == -1)
				Process::Write32(0x33099FE4, 0x060D1D00);
			else
				Process::Write32(0x3309A110, 0x060D1D00);
		}
    }
	//---------------------------------------------------------------
	// ウィンドウ
	//---------------------------------------------------------------
    void	Action19(MenuEntry *entry)
    {
        u32 a;
		if (entry->Hotkeys[0].IsDown())
		{
			if(Process::Read32(0x33099F84, a) && a == -1)
				Process::Write32(0x33099FE4, 0x1F1F3600);
			else
				Process::Write32(0x3309A110, 0x1F1F3600);
		}
    }	
	//---------------------------------------------------------------
	// 地中深くまで沈む
	//---------------------------------------------------------------
    void	Action20(MenuEntry *entry)
    {
        u32 a;
		if (entry->Hotkeys[0].IsDown())
		{
			if(Process::Read32(0x33099F84, a) && a == -1)
				Process::Write32(0x33099FE4, 0x06061C00);
			else
				Process::Write32(0x3309A110, 0x06061C00);
		}
    }	
	//---------------------------------------------------------------
	// 止まると動きがフリーズ
	//---------------------------------------------------------------
    void	Action22(MenuEntry *entry)
    {
        u32 a;
		{
			if(Process::Read32(0x33099F84, a) && a == -1)
				Process::Write32(0x33099FE4, 0x06060D00);
			else
				Process::Write32(0x3309A110, 0x06060D00);
		}
    }	
	//---------------------------------------------------------------
	// よろける
	//---------------------------------------------------------------
    void	Action23(MenuEntry *entry)
    {
        u32 a;
		if (entry->Hotkeys[0].IsDown())
		{
			if(Process::Read32(0x33099F84, a) && a == -1)
				Process::Write32(0x33099FE4, 0x7C7C7F00);
			else
				Process::Write32(0x3309A110, 0x7C7C7F00);
		}
    }	
	//---------------------------------------------------------------
	// 釣り竿を引き戻す
	//---------------------------------------------------------------
    void	Action24(MenuEntry *entry)
    {
        u32 a;
		if (entry->Hotkeys[0].IsDown())
		{
			if(Process::Read32(0x33099F84, a) && a == -1)
				Process::Write32(0x33099FE4, 0x06B0B200);
			else
				Process::Write32(0x3309A110, 0x06B0B200);
		}
    }	
	//---------------------------------------------------------------
	// 斧を壊す
	//---------------------------------------------------------------
    void	Action25(MenuEntry *entry)
    {
        u32 a;
		if (entry->Hotkeys[0].IsDown())
		{
			if(Process::Read32(0x33099F84, a) && a == -1)
				Process::Write32(0x33099FE4, 0x06555B00);
			else
				Process::Write32(0x3309A110, 0x06555B00);
		}
    }	
	//---------------------------------------------------------------
	// 唾を吐く
	//---------------------------------------------------------------
    void	Action26(MenuEntry *entry)
    {
        u32 a;
		if (entry->Hotkeys[0].IsDown())
		{
			if(Process::Read32(0x33099F84, a) && a == -1)
				Process::Write32(0x33099FE4, 0x0606CF00);
			else
				Process::Write32(0x3309A110, 0x0606CF00);
		}
    }	
	//---------------------------------------------------------------
	// 叩かれる
	//---------------------------------------------------------------
    void	Action27(MenuEntry *entry)
    {
        u32 a;
		if (entry->Hotkeys[0].IsDown())
		{
			if(Process::Read32(0x33099F84, a) && a == -1)
				Process::Write32(0x33099FE4, 0x9C9D9C00);
			else
				Process::Write32(0x3309A110, 0x9C9D9C00);
		}
    }	
	//---------------------------------------------------------------
	// 逆さま
	//---------------------------------------------------------------
	void	Pose1(MenuEntry *entry)
	{
		static bool key_status = false;

		if (entry->Hotkeys[0].IsDown() && key_status == false)
		{
			key_status = true;
			Process::Write32(0x3309A080, 0x00008000);
			Process::Write32(0x3309A1AC, 0x00008000);
			OSD::Notify("Hand stand " << Color::Green << "ON!");
		}
		
		if (entry->Hotkeys[1].IsDown() && key_status == false)
		{
			key_status = true;
			Process::Write32(0x3309A080, 0x00000000);
			Process::Write32(0x3309A1AC, 0x00000000);
			OSD::Notify("Hand stand " << Color::Red << "OFF!");
		}
		if(entry->Hotkeys[0].IsDown() == 0 && entry->Hotkeys[1].IsDown() == 0 ) key_status = false;
	}
	//---------------------------------------------------------------
	// Tポーズ
	//---------------------------------------------------------------
	void	Pose2(MenuEntry *entry)
	{
		static bool key_status = false;

		if (entry->Hotkeys[0].IsDown() && key_status == false)
		{
			key_status = true;
			Process::Write32(0x0073AA30, 0xE1A00000);
			OSD::Notify("T pose " << Color::Green << "ON!");
		}
		
		if (entry->Hotkeys[1].IsDown() && key_status == false)
		{
			key_status = true;
			Process::Write32(0x0073AA30, 0x0A000011);
			OSD::Notify("T pose " << Color::Red << "OFF!");
		}
		if(entry->Hotkeys[0].IsDown() == 0 && entry->Hotkeys[1].IsDown() == 0 ) key_status = false;
	}
	//---------------------------------------------------------------
	// 変な歩き方
	//---------------------------------------------------------------
    void	Pose3(MenuEntry *entry)
    {
        u32 a;
		{
			if(Process::Read32(0x33099F84, a) && a == -1)
				Process::Write32(0x3309A060, 0x0276000C);
			else
				Process::Write32(0x3309A18C, 0x027600BB);
		}
    }
	//---------------------------------------------------------------
	// 顔を初期設定
	//---------------------------------------------------------------
    void	Pose4(MenuEntry *entry)
    {
        u32 a;
		{
			if(Process::Read32(0x33099F84, a) && a == -1)
				Process::Write32(0x33099FE4, 0x0616B900);
			else
				Process::Write32(0x3309A110, 0x7C10B900);
		}
    }
	//---------------------------------------------------------------
	// アイテムを無限に置く
	//---------------------------------------------------------------
	void	Inventory1(MenuEntry *entry)
	{
		static bool key_status = false;

		if (entry->Hotkeys[0].IsDown() && key_status == false)
		{
			key_status = true;
			Process::Write32(0x0019C4D0, 0x00000000);
			Process::Write32(0x0019C42C, 0x00000000);
			OSD::Notify("Infinitely put " << Color::Green << "ON!");
		}
		
		if (entry->Hotkeys[1].IsDown() && key_status == false)
		{
			key_status = true;
			Process::Write32(0x0019C4D0, 0xEB057D0A);
			Process::Write32(0x0019C42C, 0xEB057D33);
			OSD::Notify("Infinitely put " << Color::Red << "OFF!");
		}
		if(entry->Hotkeys[0].IsDown() == 0 && entry->Hotkeys[1].IsDown() == 0 ) key_status = false;
	}
	//---------------------------------------------------------------
	// はや着替え
	//---------------------------------------------------------------
	void	Inventory2(MenuEntry *entry)
	{
		Process::Write32(0x3309A714, 0x00000000);
	}
	//---------------------------------------------------------------
	// 園芸店変更
	//---------------------------------------------------------------
	struct ENGEI_SHOP
	{
		const u8	engei_ID;
		const char  *engei_name;
	};

	static const std::vector<ENGEI_SHOP> engei_shop =
	{
		{ 0x00, "未完成" },
		{ 0x01, "工事中" },
		{ 0x02, "完成" },
		{ 0x03, "ホームセンター" },
		{ 0x04, "デパート" },
	}; 
	void	change_engei(MenuEntry *entry)
	{
		static StringVector engei_No;

		if (engei_No.empty()) for (const ENGEI_SHOP &i : engei_shop) engei_No.push_back(i.engei_name);

		Keyboard	keyboard("どの園芸店の状態に変更しますか。", engei_No);
		int		 choice = keyboard.Open();

		if( choice >= 0 ) Process::Write8( 0x31FB00F4, engei_shop[choice].engei_ID );
	}
	//---------------------------------------------------------------
	// まめつぶ変更
	//---------------------------------------------------------------
	struct MAMETUBU_SHOP
	{
		const u8	mametubu_ID;
		const char  *mametubu_name;
	};

	static const std::vector<MAMETUBU_SHOP> mametubu_shop =
	{
		{ 0x00, "商店" },
		{ 0x01, "コンビニ" },
		{ 0x02, "スーパーマーケット" },
		{ 0x03, "ホームセンター" },
		{ 0x04, "デパート" },
	}; 
	void	change_mametubu(MenuEntry *entry)
	{
		static StringVector mametubu_No;

		if (mametubu_No.empty()) for (const MAMETUBU_SHOP &i : mametubu_shop) mametubu_No.push_back(i.mametubu_name);

		Keyboard	keyboard("どのお店の状態に変更しますか。", mametubu_No);
		int		 choice = keyboard.Open();

		if( choice >= 0 ) Process::Write8( 0x31FABC64, mametubu_shop[choice].mametubu_ID );
	}
	//---------------------------------------------------------------
	//　占いの館
	//---------------------------------------------------------------
	struct URANAI_SHOP
	{
		const u8	uranai_ID;
		const char  *uranai_name;
	};

	static const std::vector<URANAI_SHOP> uranai_shop =
	{
		{ 0x00, "未完成" },
		{ 0x01, "完成" },

	}; 
	void	change_uranai(MenuEntry *entry)
	{
		static StringVector uranai_No;

		if (uranai_No.empty()) for (const URANAI_SHOP &i : uranai_shop) uranai_No.push_back(i.uranai_name);

		Keyboard	keyboard("どの占いの館の状態に変更しますか。", uranai_No);
		int		 choice = keyboard.Open();

		if( choice >= 0 ) Process::Write8( 0x31FB47A4, uranai_shop[choice].uranai_ID );
	}
	//---------------------------------------------------------------
	// 夢見の館変更
	//---------------------------------------------------------------
	struct YUMEMI_SHOP
	{
		const u8	yumemi_ID;
		const char  *yumemi_name;
	};

	static const std::vector<YUMEMI_SHOP> yumemi_shop =
	{
		{ 0x00, "未完成" },
		{ 0x01, "完成" },

	}; 
	void	change_yumemi(MenuEntry *entry)
	{
		static StringVector yumemi_No;

		if (yumemi_No.empty()) for (const YUMEMI_SHOP &i : yumemi_shop) yumemi_No.push_back(i.yumemi_name);

		Keyboard	keyboard("どの夢見の館の状態に変更しますか。", yumemi_No);
		int		 choice = keyboard.Open();

		if( choice >= 0 ) Process::Write8( 0x31FB47A2, yumemi_shop[choice].yumemi_ID );
	}
	//---------------------------------------------------------------
	// CLUB444変更
	//---------------------------------------------------------------
	struct KURABU_SHOP
	{
		const u8	kurabu_ID;
		const char  *kurabu_name;
	};

	static const std::vector<KURABU_SHOP> kurabu_shop =
	{
		{ 0x00, "未完成" },
		{ 0x02, "完成" },
		{ 0x01, "Test" },

	}; 
	void	change_kurabu(MenuEntry *entry)
	{
		static StringVector kurabu_No;

		if (kurabu_No.empty()) for (const KURABU_SHOP &i : kurabu_shop) kurabu_No.push_back(i.kurabu_name);

		Keyboard	keyboard("どのCLUB444の状態に変更しますか。", kurabu_No);
		int		 choice = keyboard.Open();

		if( choice >= 0 ) Process::Write8( 0x31FB4782, kurabu_shop[choice].kurabu_ID );
	}
	//---------------------------------------------------------------
	// 美容院
	//---------------------------------------------------------------
	struct BIYOUIN_SHOP
	{
		const u8	biyouin_ID;
		const char  *biyouin_name;
	};

	static const std::vector<BIYOUIN_SHOP> biyouin_shop =
	{
		{ 0x00, "未完成" },
		{ 0x01, "工事中" },
		{ 0x02, "完成" },

	}; 
	void	change_biyouin(MenuEntry *entry)
	{
		static StringVector biyouin_No;

		if (biyouin_No.empty()) for (const BIYOUIN_SHOP &i : biyouin_shop) biyouin_No.push_back(i.biyouin_name);

		Keyboard	keyboard("どの美容院の状態に変更しますか。", biyouin_No);
		int		 choice = keyboard.Open();

		if( choice >= 0 ) Process::Write8( 0x31FB47B4, biyouin_shop[choice].biyouin_ID );
	}
	//---------------------------------------------------------------
	// 靴屋変更
	//---------------------------------------------------------------
	struct KUTUYA_SHOP
	{
		const u8	kutuya_ID;
		const char  *kutuya_name;
	};

	static const std::vector<KUTUYA_SHOP> kutuya_shop =
	{
		{ 0x00, "未完成" },
		{ 0x01, "工事中" },
		{ 0x02, "完成" },

	}; 
	void	change_kutuya(MenuEntry *entry)
	{
		static StringVector kutuya_No;

		if (kutuya_No.empty()) for (const KUTUYA_SHOP &i : kutuya_shop) kutuya_No.push_back(i.kutuya_name);

		Keyboard	keyboard("どの靴屋の状態に変更しますか。", kutuya_No);
		int		 choice = keyboard.Open();

		if( choice >= 0 ) Process::Write8( 0x31FB022C, kutuya_shop[choice].kutuya_ID );
	}
	//---------------------------------------------------------------
	// 博物館変更
	//---------------------------------------------------------------
	struct HAKUBUTUKAN_SHOP
	{
		const u8	hakubutukan_ID;
		const char  *hakubutukan_name;
	};

	static const std::vector<HAKUBUTUKAN_SHOP> hakubutukan_shop =
	{
		{ 0x00, "F2未完成" },
		{ 0x01, "F2完成" }

	}; 
	void	change_hakubutukan(MenuEntry *entry)
	{
		static StringVector hakubutukan_No;

		if (hakubutukan_No.empty()) 
			for (const HAKUBUTUKAN_SHOP &i : hakubutukan_shop)
				hakubutukan_No.push_back(i.hakubutukan_name);

		Keyboard	keyboard("どの博物館の状態に変更しますか。", hakubutukan_No);
		int		 choice = keyboard.Open();
		if( choice >= 0 ) Process::Write8( 0x31FB46BC, hakubutukan_shop[choice].hakubutukan_ID );
	}
	//---------------------------------------------------------------
	// 拾い方変更
	//---------------------------------------------------------------
	struct aiueo
    {
        const u32 add;
        const u32 add2;
        const u32 hex;
        const u32 hex2;
        const char *name;
    };
    static const std::vector<aiueo> select =
    {
        { 0x005989FC, 0x00596890, 0x0A000044, 0xE3A0001D, "普通に拾う"},
        { 0x005989FC, 0x00596890, 0xEA000030, 0xE3A0001D, "なんでも拾う"},
        { 0x005989FC, 0x00596890, 0xEA000019, 0xE3A0001D, "なんでも引っこ抜く"},
        { 0x005989FC, 0x00596890, 0xEA000020, 0xE3A0001D, "クローバーを拾う"}
    };
    void    Player2(MenuEntry *entry)
    {
        static StringVector no;
        if (no.empty())
            for (const aiueo &i : select) 
                no.push_back(i.name);
            
        Keyboard    keyboard("拾い方を選んでください。", no);
        int         choice = keyboard.Open();
        if( choice >= 0 )
        {
            Process::Write32( select[choice].add, select[choice].hex );
            Process::Write32( select[choice].add2, select[choice].hex2 );
        }
    }
	//---------------------------------------------------------------
	// 速く走る
	//---------------------------------------------------------------
	void    Player1(MenuEntry *entry)
	{
    u32   velocity;
    float Flo;
		if (entry->Hotkeys[0].IsDown())
		{
			Process::Read32(0x33099E7C, velocity);
			Process::ReadFloat(0x33099E7C, Flo);
			if (velocity >= 0x41A79DB3)
			{
				Process::Write32(0x33099E7C, 0x41A79DB3);
			}
			else if (velocity > 0)
			{
				Flo += 2.0;
				Process::WriteFloat(0x33099E7C, Flo);
			}
		}
	}
	//---------------------------------------------------------------
	// 道具機能変更
	//---------------------------------------------------------------
	struct TOOLS_1S
	{
		const u16	Tools_1_ID;
		const char  *Tools_1_name;
	};

	static const std::vector<TOOLS_1S> Tools_1s =
	{
		{ 0x3358, "レンタルスコップ" },
		{ 0x3359, "スコップ" },
		{ 0x335A, "銀のスコップ" },
		{ 0x335B, "金のスコップ" },
		{ 0x3354, "レンタル釣り竿" },
		{ 0x3355, "釣り竿" },
		{ 0x3356, "銀の釣り竿" },
		{ 0x3357, "金の釣り竿" },
		{ 0x3350, "レンタル網" },
		{ 0x3351, "網" },
		{ 0x3352, "銀の網" },
		{ 0x3353, "金の網" },
		{ 0x334C, "レンタル斧" },
		{ 0x334D, "斧" },
		{ 0x334E, "銀の斧" },
		{ 0x334F, "金の斧" },
		{ 0x335C, "レンタルジョウロ" },
		{ 0x335D, "ジョウロ" },
		{ 0x335E, "銀のジョウロ" },
		{ 0x335F, "金のジョウロ" },
		{ 0x3360, "レンタルパチンコ" },
		{ 0x3361, "パチンコ" },
		{ 0x3362, "銀のパチンコ" },
		{ 0x3363, "金のパチンコ" },
		{ 0x3364, "レンタルピコピコハンマー" },
		{ 0x3365, "ピコピコハンマー" },
		{ 0x338C, "コーヒー" },
		{ 0x338F, "恵方巻" },
		{ 0x338E, "豆" },
		{ 0x336A, "クラッカー" },
		{ 0x3399, "緑のスティックライト" },
		{ 0x339B, "黄色いスティックライト" },
		{ 0x339A, "ピンクのスティックライト" },
		{ 0x3398, "青いスティックライト" },
		{ 0x338D, "スパークリングサイダー" },
		{ 0x3379, "青い風船" },
		{ 0x3374, "赤い風船" },
		{ 0x3375, "オレンジの風船" },
		{ 0x3376, "黄色い風船" },
		{ 0x337B, "ピンクの風船" },
		{ 0x3378, "水色の風船" },
		{ 0x3377, "緑の風船" },
		{ 0x337A, "紫の風船" },
		{ 0x3371, "青いウサギ風船" },
		{ 0x336C, "赤いウサギ風船" },
		{ 0x336D, "オレンジウサギ風船" },
		{ 0x336E, "黄色いウサギ風船" },
		{ 0x3373, "ピンクウサギ風船" },
		{ 0x3370, "水色ウサギ風船" },
		{ 0x336F, "緑のウサギ風船" },
		{ 0x3372, "紫ウサギ風船" },
		{ 0x3379, "青いハート風船" },
		{ 0x3381, "赤いハート風船" },
		{ 0x337D, "オレンジハート風船" },
		{ 0x337E, "黄色いハート風船" },
		{ 0x3383, "ピンクのハート風船" },
		{ 0x3380, "水色ハート風船" },
		{ 0x337F, "緑のハート風船" },
		{ 0x3382, "紫ハート風船" },
		{ 0x3389, "青い風車" },
		{ 0x3384, "赤い風車" },
		{ 0x3385, "オレンジの風車" },
		{ 0x3386, "黄色い風車" },
		{ 0x338B, "ピンクの風車" },
		{ 0x3388, "水色の風車" },
		{ 0x3387, "緑の風車" },
		{ 0x338A, "紫の風車" },
		{ 0x336B, "シャボン玉" },
		{ 0x339E, "吹き戻し" },
		{ 0x3391, "チョコソフトクリーム" },
		{ 0x3390, "バニラソフトクリーム" },
		{ 0x3392, "抹茶のソフトクリーム" },
		{ 0x3393, "ミックスソフトクリーム" },
		{ 0x3395, "イチゴアイスクリーム" },
		{ 0x3394, "バニラアイスクリーム" },
		{ 0x3397, "ミントダブルアイス" },
		{ 0x3396, "レモンダブルアイス" },
		
	}; 
	void	Tools_1(MenuEntry *entry)
	{
		static StringVector Tools_1_No;

		if (Tools_1_No.empty()) for (const TOOLS_1S &i : Tools_1s) Tools_1_No.push_back(i.Tools_1_name);

		Keyboard	keyboard("どのツールの機能に変更しますか。", Tools_1_No);
		int		 choice = keyboard.Open();

		if( choice >= 0 ) Process::Write16( 0x33096734, Tools_1s[choice].Tools_1_ID );
	}
	//---------------------------------------------------------------
	// 道具持ち方変更
	//---------------------------------------------------------------
	struct TOOLS_2S
	{
		const u16	Tools_2_ID;
		const char  *Tools_2_name;
	};

	static const std::vector<TOOLS_2S> Tools_2s =
	{
		{ 0x3358, "レンタルスコップ" },
		{ 0x3359, "スコップ" },
		{ 0x335A, "銀のスコップ" },
		{ 0x335B, "金のスコップ" },
		{ 0x3354, "レンタル釣り竿" },
		{ 0x3355, "釣り竿" },
		{ 0x3356, "銀の釣り竿" },
		{ 0x3357, "金の釣り竿" },
		{ 0x3350, "レンタル網" },
		{ 0x3351, "網" },
		{ 0x3352, "銀の網" },
		{ 0x3353, "金の網" },
		{ 0x334C, "レンタル斧" },
		{ 0x334D, "斧" },
		{ 0x334E, "銀の斧" },
		{ 0x334F, "金の斧" },
		{ 0x335C, "レンタルジョウロ" },
		{ 0x335D, "ジョウロ" },
		{ 0x335E, "銀のジョウロ" },
		{ 0x335F, "金のジョウロ" },
		{ 0x3360, "レンタルパチンコ" },
		{ 0x3361, "パチンコ" },
		{ 0x3362, "銀のパチンコ" },
		{ 0x3363, "金のパチンコ" },
		{ 0x3364, "レンタルピコピコハンマー" },
		{ 0x3365, "ピコピコハンマー" },
		{ 0x338C, "コーヒー" },
		{ 0x338F, "恵方巻" },
		{ 0x338E, "豆" },
		{ 0x336A, "クラッカー" },
		{ 0x3399, "緑のスティックライト" },
		{ 0x339B, "黄色いスティックライト" },
		{ 0x339A, "ピンクのスティックライト" },
		{ 0x3398, "青いスティックライト" },
		{ 0x338D, "スパークリングサイダー" },
		{ 0x3379, "青い風船" },
		{ 0x3374, "赤い風船" },
		{ 0x3375, "オレンジの風船" },
		{ 0x3376, "黄色い風船" },
		{ 0x337B, "ピンクの風船" },
		{ 0x3378, "水色の風船" },
		{ 0x3377, "緑の風船" },
		{ 0x337A, "紫の風船" },
		{ 0x3371, "青いウサギ風船" },
		{ 0x336C, "赤いウサギ風船" },
		{ 0x336D, "オレンジウサギ風船" },
		{ 0x336E, "黄色いウサギ風船" },
		{ 0x3373, "ピンクウサギ風船" },
		{ 0x3370, "水色ウサギ風船" },
		{ 0x336F, "緑のウサギ風船" },
		{ 0x3372, "紫ウサギ風船" },
		{ 0x3379, "青いハート風船" },
		{ 0x3381, "赤いハート風船" },
		{ 0x337D, "オレンジハート風船" },
		{ 0x337E, "黄色いハート風船" },
		{ 0x3383, "ピンクのハート風船" },
		{ 0x3380, "水色ハート風船" },
		{ 0x337F, "緑のハート風船" },
		{ 0x3382, "紫ハート風船" },
		{ 0x3389, "青い風車" },
		{ 0x3384, "赤い風車" },
		{ 0x3385, "オレンジの風車" },
		{ 0x3386, "黄色い風車" },
		{ 0x338B, "ピンクの風車" },
		{ 0x3388, "水色の風車" },
		{ 0x3387, "緑の風車" },
		{ 0x338A, "紫の風車" },
		{ 0x336B, "シャボン玉" },
		{ 0x339E, "吹き戻し" },
		{ 0x3391, "チョコソフトクリーム" },
		{ 0x3390, "バニラソフトクリーム" },
		{ 0x3392, "抹茶のソフトクリーム" },
		{ 0x3393, "ミックスソフトクリーム" },
		{ 0x3395, "イチゴアイスクリーム" },
		{ 0x3394, "バニラアイスクリーム" },
		{ 0x3397, "ミントダブルアイス" },
		{ 0x3396, "レモンダブルアイス" },
		
	}; 
	void	Tools_2(MenuEntry *entry)
	{
		static StringVector Tools_2_No;

		if (Tools_2_No.empty()) for (const TOOLS_2S &i : Tools_2s) Tools_2_No.push_back(i.Tools_2_name);

		Keyboard	keyboard("どのツールの持ち方に変更しますか。", Tools_2_No);
		int		 choice = keyboard.Open();

		if( choice >= 0 ) Process::Write16( 0x3309A20C, Tools_2s[choice].Tools_2_ID );
	}
	//---------------------------------------------------------------
	// 花が散らない
	//---------------------------------------------------------------
	void	Hantei1(MenuEntry *entry)
	{
		static bool key_status = false;

		if (entry->Hotkeys[0].IsDown() && key_status == false)
		{
			key_status = true;
			Process::Write32(0x00596890, 0xE3A0001D);
			OSD::Notify("Not scatter flower " << Color::Green << "ON!");
		}
		
		if (entry->Hotkeys[1].IsDown() && key_status == false)
		{
			key_status = true;
			Process::Write32(0x00596890, 0xEBF5990F);
			OSD::Notify("Not scatter flower " << Color::Red << "OFF!");
		}
		if(entry->Hotkeys[0].IsDown() == 0 && entry->Hotkeys[1].IsDown() == 0 ) key_status = false;
	}
	//---------------------------------------------------------------
	// 壁貫通
	//---------------------------------------------------------------
	void	Hantei2(MenuEntry *entry)
	{
		static bool key_status = false;

		if (entry->Hotkeys[0].IsDown() && key_status == false)
		{
			key_status = true;
			Process::Write32(0x0064EEF4, 0xEA000094);
			Process::Write32(0x0064F1E4, 0xEA000065);
			Process::Write32(0x0064EF0C, 0xEA000052);
			Process::Write32(0x0064F070, 0xEA000001);
			Process::Write32(0x0064F0E8, 0xEA000014);
			Process::Write32(0x0064F19C, 0xE1A00000);
			Process::Write32(0x0064F1B4, 0xE1A00000);
			Process::Write32(0x0064F1B8, 0xEA000026);
			OSD::Notify("Walk Anywhere " << Color::Green << "ON!");
		}
		
		if (entry->Hotkeys[1].IsDown() && key_status == false)
		{
			key_status = true;
			Process::Write32(0x0064EEF4, 0x0A000094);
			Process::Write32(0x0064F1E4, 0x0A000065);
			Process::Write32(0x0064EF0C, 0x0A000052);
			Process::Write32(0x0064F070, 0x0A000001);
			Process::Write32(0x0064F0E8, 0xDA000014);
			Process::Write32(0x0064F19C, 0xED841A05);
			Process::Write32(0x0064F1B4, 0xED840A07);
			Process::Write32(0x0064F1B8, 0x0A000026);
			OSD::Notify("Walk Anywhere " << Color::Red << "OFF!");
		}
		if(entry->Hotkeys[0].IsDown() == 0 && entry->Hotkeys[1].IsDown() == 0 ) key_status = false;
	}
	//---------------------------------------------------------------
	// 自宅化
	//---------------------------------------------------------------
	void	Hantei3(MenuEntry *entry)
	{
		static bool key_status = false;

		if (entry->Hotkeys[0].IsDown() && key_status == false)
		{
			key_status = true;
			Process::Write32(0x00951338, 0xA5030000);
			OSD::Notify("Home Zation " << Color::Green << "ON!");
		}
		
		if (entry->Hotkeys[1].IsDown() && key_status == false)
		{
			key_status = true;
			Process::Write32(0x00951338, 0xA5020000);
			OSD::Notify("Home Zation " << Color::Red << "OFF!");
		}
		if(entry->Hotkeys[0].IsDown() == 0 && entry->Hotkeys[1].IsDown() == 0 ) key_status = false;
	}
	//---------------------------------------------------------------
	// 島のお土産変更
	//---------------------------------------------------------------
struct ISLAND_ITEM
    {
        const u32    Island_ID;
        const char  *Island_name;
    };

    static const std::vector<ISLAND_ITEM> Island_Item =
    {
        { 0x3305B814, "お土産左" },
        { 0x3305B818, "お土産中央" },
        { 0x3305B81C, "お土産右" },
        { 0x3305B810, "お土産後ろ" }
    }; 
    void    Change_Island(MenuEntry *entry)
    {
        static StringVector Island_No;

        if (Island_No.empty()) for (const ISLAND_ITEM &i : Island_Item) Island_No.push_back(i.Island_name);

        Keyboard    keyboard("変更する商品を選択", Island_No);
        int         choice = keyboard.Open();

        if( choice >= 0 )
        {
        Keyboard    aiueo("アイテムIDを入力");
        u16 a;
        aiueo.Open(a);
        Process::Write16(Island_Item[choice].Island_ID, a);
    }
    }
	//---------------------------------------------------------------
	// CLUB444ハニワ変更
	//---------------------------------------------------------------
struct CLUB444_ITEM
    {
        const u32    Club444_ID;
        const char  *Club444_name;
    };

    static const std::vector<CLUB444_ITEM> Club444_Item =
    {
        { 0x31FB4792, "ハニワ左" },
        { 0x31FB4796, "ハニワ左中央" },
        { 0x31FB479A, "ハニワ右中央" },
        { 0x31FB479E, "ハニワ右" }
    }; 
    void    Change_Club444(MenuEntry *entry)
    {
        static StringVector Club444_No;

        if (Club444_No.empty()) for (const CLUB444_ITEM &i : Club444_Item) Club444_No.push_back(i.Club444_name);

        Keyboard    keyboard("変更するハニワを選択", Club444_No);
        int         choice = keyboard.Open();

        if( choice >= 0 )
        {
        Keyboard    aiueo("アイテムIDを入力");
        u16 a;
        aiueo.Open(a);
        Process::Write16(Club444_Item[choice].Club444_ID, a);
    }
    }
	//---------------------------------------------------------------
	// 不動産屋
	//---------------------------------------------------------------
struct HOUSING_ITEM
    {
        const u32    Housing_ID;
        const char  *Housing_name;
    };

    static const std::vector<HOUSING_ITEM> Housing_Item =
    {
        { 0x31FB46CE, "石畳" },
        { 0x31FB46D2, "屋根" },
        { 0x31FB46D6, "壁" },
        { 0x31FB46DA, "柵" },
		{ 0x31FB46DE, "ポスト" },
		{ 0x31FB46E2, "ドア左" },
		{ 0x31FB46E6, "ドア右" },
		{ 0x31FB46EA, "建物" },
    }; 
    void    Change_Housing(MenuEntry *entry)
    {
        static StringVector Housing_No;

        if (Housing_No.empty()) for (const HOUSING_ITEM &i : Housing_Item) Housing_No.push_back(i.Housing_name);

        Keyboard    keyboard("変更する商品を選択", Housing_No);
        int         choice = keyboard.Open();

        if( choice >= 0 )
        {
        Keyboard    aiueo("アイテムIDを入力");
        u16 a;
        aiueo.Open(a);
        Process::Write16(Housing_Item[choice].Housing_ID, a);
    }
    }
	//---------------------------------------------------------------
	// デパートF1
	//---------------------------------------------------------------
struct DEPARTMENT_STORE_ITEM
    {
        const u32    DepartmentStore_ID;
        const char  *DepartmentStore_name;
    };

    static const std::vector<DEPARTMENT_STORE_ITEM> DepartmentStore_Item =
    {
        { 0x31FABCAC, "フォーチュンクッキー上" },
        { 0x31FABCB0, "フォーチュンクッキー下" },
        { 0x31FABC70, "ツール上" },
        { 0x31FABC78, "ツール真ん中" },
		{ 0x31FABC7C, "ツール下" },
		{ 0x31FABCA4, "音楽左" },
		{ 0x31FABCA8, "音楽右" },
		{ 0x31FABCA0, "お薬" },
		{ 0x31FABC90, "ラッピング" },
		{ 0x31FABC94, "手紙上" },
		{ 0x31FABC98, "手紙下" },
		{ 0x31FABC9C, "メロディーカード" },
		
		
    }; 
    void    Change_Department_store(MenuEntry *entry)
    {
        static StringVector DepartmentStore_No;

        if (DepartmentStore_No.empty()) for (const DEPARTMENT_STORE_ITEM &i : DepartmentStore_Item) DepartmentStore_No.push_back(i.DepartmentStore_name);

        Keyboard    keyboard("変更する商品を選択", DepartmentStore_No);
        int         choice = keyboard.Open();

        if( choice >= 0 )
        {
        Keyboard    aiueo("アイテムIDを入力");
        u16 a;
        aiueo.Open(a);
        Process::Write16(DepartmentStore_Item[choice].DepartmentStore_ID, a);
    }
    }
	//---------------------------------------------------------------
	// デパートF2
	//---------------------------------------------------------------
struct DEPARTMENT_STORE_F2_ITEM
    {
        const u32    DepartmentStoreF2_ID;
        const char  *DepartmentStoreF2_name;
    };

    static const std::vector<DEPARTMENT_STORE_F2_ITEM> DepartmentStoreF2_Item =
    {
        { 0x31FABCB4, "壁掛け左" },
		{ 0x31FABCB8, "壁掛け右" },
		{ 0x31FABCBC, "家具左上" },
		{ 0x31FABCC4, "家具左下" },
		{ 0x31FABCC8, "家具中央" },
		{ 0x31FABCCC, "家具右下" },
		{ 0x31FABCC0, "家具右上" },
		{ 0x31FABC80, "壁紙上" },
		{ 0x31FABC84, "壁紙下" },
		{ 0x31FABC88, "床上" },
		{ 0x31FABC8C, "床下" },

		
		
    }; 
    void    Change_Department_store_F2(MenuEntry *entry)
    {
        static StringVector DepartmentStoreF2_No;

        if (DepartmentStoreF2_No.empty()) for (const DEPARTMENT_STORE_F2_ITEM &i : DepartmentStoreF2_Item) DepartmentStoreF2_No.push_back(i.DepartmentStoreF2_name);

        Keyboard    keyboard("変更する商品を選択", DepartmentStoreF2_No);
        int         choice = keyboard.Open();

        if( choice >= 0 )
        {
        Keyboard    aiueo("アイテムIDを入力");
        u16 a;
        aiueo.Open(a);
        Process::Write16(DepartmentStoreF2_Item[choice].DepartmentStoreF2_ID, a);
    }
    }
	//---------------------------------------------------------------
	// デパートF3
	//---------------------------------------------------------------
struct DEPARTMENT_STORE_F3_ITEM
    {
        const u32    DepartmentStoreF3_ID;
        const char  *DepartmentStoreF3_name;
    };

    static const std::vector<DEPARTMENT_STORE_F3_ITEM> DepartmentStoreF3_Item =
    {
        { 0x31FB4710, "床" },
		{ 0x31FB470C, "壁紙" },
		{ 0x31FB46F8, "家具左上" },
		{ 0x31FB4700, "家具左下" },
		{ 0x31FB4704, "家具右下" },
		{ 0x31FB46FC, "家具右上" },
		{ 0x31FB4714, "帽子左" },
		{ 0x31FB4718, "帽子右" },
		{ 0x31FB471C, "靴左" },
		{ 0x31FB4720, "靴右" },
		{ 0x31FB4734, "ズボン左" },
		{ 0x31FB4724, "服左中央" },
		{ 0x31FB4728, "服左内側" },
		{ 0x31FB472C, "服右内側" },
		{ 0x31FB4730, "服右中央" },
		{ 0x31FB4738, "ズボン右" },
		{ 0x31FB4708, "壁掛け" },

		
		
    }; 
    void    Change_Department_store_F3(MenuEntry *entry)
    {
        static StringVector DepartmentStoreF3_No;

        if (DepartmentStoreF3_No.empty()) for (const DEPARTMENT_STORE_F3_ITEM &i : DepartmentStoreF3_Item) DepartmentStoreF3_No.push_back(i.DepartmentStoreF3_name);

        Keyboard    keyboard("変更する商品を選択", DepartmentStoreF3_No);
        int         choice = keyboard.Open();

        if( choice >= 0 )
        {
        Keyboard    aiueo("アイテムIDを入力");
        u16 a;
        aiueo.Open(a);
        Process::Write16(DepartmentStoreF3_Item[choice].DepartmentStoreF3_ID, a);
    }
    }
	//---------------------------------------------------------------
	// デパート園芸店
	//---------------------------------------------------------------
struct DEPARTMENT_STORE_ENGEI_ITEM
    {
        const u32    DepartmentStoreEngei_ID;
        const char  *DepartmentStoreEngei_name;
    };

    static const std::vector<DEPARTMENT_STORE_ENGEI_ITEM> DepartmentStoreEngei_Item =
    {
        { 0x31FB00FA, "ツール左" },
		{ 0x31FB00FE, "ツール右" },
		{ 0x31FB011E, "肥料" },
		{ 0x31FB010A, "果物" },
		{ 0x31FB0102, "苗" },
		{ 0x31FB0112, "低木上" },
		{ 0x31FB010E, "低木下" },
		{ 0x31FB011A, "種下" },
		{ 0x31FB0116, "種上" },
		{ 0x31FB00F6, "家具" },
		{ 0x31FABC90, "ラッピング" },
		{ 0x31FABC98, "手紙左" },
		{ 0x31FABC94, "手紙右" },
		{ 0x31FABC9C, "メロディーカード" },
		{ 0x31FABC70, "ツール上" },
        { 0x31FABC78, "ツール真ん中" },
		{ 0x31FABC7C, "ツール下" },

		
		
    }; 
    void    Change_Department_store_Engei(MenuEntry *entry)
    {
        static StringVector DepartmentStoreEngei_No;

        if (DepartmentStoreEngei_No.empty()) for (const DEPARTMENT_STORE_ENGEI_ITEM &i : DepartmentStoreEngei_Item) DepartmentStoreEngei_No.push_back(i.DepartmentStoreEngei_name);

        Keyboard    keyboard("変更する商品を選択", DepartmentStoreEngei_No);
        int         choice = keyboard.Open();

        if( choice >= 0 )
        {
        Keyboard    aiueo("アイテムIDを入力");
        u16 a;
        aiueo.Open(a);
        Process::Write16(DepartmentStoreEngei_Item[choice].DepartmentStoreEngei_ID, a);
    }
    }
	//---------------------------------------------------------------
	// ホームセンター
	//---------------------------------------------------------------
struct HOMECENTER_ITEM
    {
        const u32    HomeCenter_ID;
        const char  *HomeCenter_name;
    };

    static const std::vector<HOMECENTER_ITEM> HomeCenter_Item =
    {
        
		{ 0x31FABCBC, "家具左外側" },
		{ 0x31FABCC0, "家具左内側" },
		{ 0x31FABCB4, "壁掛け" }, 
		{ 0x31FABCC4, "家具右内側" },
		{ 0x31FABCC8, "家具右外側" },
		{ 0x31FABCA4, "音楽左" },
		{ 0x31FABCAC, "フォーチュンクッキー上" },
        { 0x31FABCB0, "フォーチュンクッキー下" },
		{ 0x31FABC80, "壁紙左" },
		{ 0x31FABC84, "壁紙右" },
		{ 0x31FABC88, "床左"},
		{ 0x31FABC8C, "床右" },
		{ 0x31FABCA0, "お薬" },

		
		
    }; 
    void    Change_HomeCenter(MenuEntry *entry)
    {
        static StringVector HomeCenter_No;

        if (HomeCenter_No.empty()) for (const HOMECENTER_ITEM &i : HomeCenter_Item) HomeCenter_No.push_back(i.HomeCenter_name);

        Keyboard    keyboard("変更する商品を選択", HomeCenter_No);
        int         choice = keyboard.Open();

        if( choice >= 0 )
        {
        Keyboard    aiueo("アイテムIDを入力");
        u16 a;
        aiueo.Open(a);
        Process::Write16(HomeCenter_Item[choice].HomeCenter_ID, a);
    }
    }
	//---------------------------------------------------------------
	// ホームセンター園芸店
	//---------------------------------------------------------------
struct HOMECENTER_ENGEI_ITEM
    {
        const u32    HomeCenterEngei_ID;
        const char  *HomeCenterEngei_name;
    };

    static const std::vector<HOMECENTER_ENGEI_ITEM> HomeCenterEngei_Item =
    {
        { 0x31FB00FA, "ツール" },
		{ 0x31FB0102, "苗" },
		{ 0x31FB0112, "低木左" },
		{ 0x31FB010E, "低木右" },
		{ 0x31FB011A, "種左" },
		{ 0x31FB0116, "種右" },
		{ 0x31FB00F6, "家具" },

		
		
    }; 
    void    Change_HomeCenter_Engei(MenuEntry *entry)
    {
        static StringVector HomeCenterEngei_No;

        if (HomeCenterEngei_No.empty()) for (const HOMECENTER_ENGEI_ITEM &i : HomeCenterEngei_Item) HomeCenterEngei_No.push_back(i.HomeCenterEngei_name);

        Keyboard    keyboard("変更する商品を選択", HomeCenterEngei_No);
        int         choice = keyboard.Open();

        if( choice >= 0 )
        {
        Keyboard    aiueo("アイテムIDを入力");
        u16 a;
        aiueo.Open(a);
        Process::Write16(HomeCenterEngei_Item[choice].HomeCenterEngei_ID, a);
    }
    }
	//---------------------------------------------------------------
	// スーパー商品変更
	//---------------------------------------------------------------
struct SUPER_MARKET_ITEM
    {
        const u32    SuperMarket_ID;
        const char  *SuperMarket_name;
    };

    static const std::vector<SUPER_MARKET_ITEM> SuperMarket_Item =
    {
		{ 0x31FABCBC, "家具上" },
		{ 0x31FABCC0, "家具真ん中" },
		{ 0x31FABCC4, "家具下" },
		{ 0x31FABCB4, "壁掛け" },
		{ 0x31FABC80, "壁紙左" },
		{ 0x31FABC84, "壁紙右" },
		{ 0x31FABC88, "床左" },
		{ 0x31FABC8C, "床右" },
        { 0x31FABCAC, "フォーチュンクッキー上" },
        { 0x31FABCB0, "フォーチュンクッキー下" },
        { 0x31FABC70, "ツール左" },
        { 0x31FABC78, "ツール真ん中" },
		{ 0x31FABC7C, "ツール右" },
		{ 0x31FABCA0, "お薬" },
		{ 0x31FABC90, "ラッピング" },
		{ 0x31FABC94, "手紙左" },
		{ 0x31FABC98, "手紙右" },
		{ 0x31FABC9C, "メロディーカード" },
		
		
    }; 
    void    Change_SuperMarket(MenuEntry *entry)
    {
        static StringVector SuperMarket_No;

        if (SuperMarket_No.empty()) for (const SUPER_MARKET_ITEM &i : SuperMarket_Item) SuperMarket_No.push_back(i.SuperMarket_name);

        Keyboard    keyboard("変更する商品を選択", SuperMarket_No);
        int         choice = keyboard.Open();

        if( choice >= 0 )
        {
        Keyboard    aiueo("アイテムIDを入力");
        u16 a;
        aiueo.Open(a);
        Process::Write16(SuperMarket_Item[choice].SuperMarket_ID, a);
    }
    }
	//---------------------------------------------------------------
	// スーパー&コンビニ園芸店
	//---------------------------------------------------------------
struct SUPERMARKETandCONVENIENCESTORE
    {
        const u32    SuperMarketandConvenienceStore_ID;
        const char  *SuperMarketandConvenienceStore_name;
    };

    static const std::vector<SUPERMARKETandCONVENIENCESTORE> SuperMarketandConvenienceStore_Item =
    {
		{ 0x31FB011A, "種左" },
		{ 0x31FB0116, "種右" },
		{ 0x31FB0102, "苗" },
		{ 0x31FB00FA, "ツール" },


		
		
    }; 
    void    Change_SuperMarketandConvenienceStore(MenuEntry *entry)
    {
        static StringVector SuperMarketandConvenienceStore_No;

        if (SuperMarketandConvenienceStore_No.empty()) for (const SUPERMARKETandCONVENIENCESTORE &i : SuperMarketandConvenienceStore_Item) SuperMarketandConvenienceStore_No.push_back(i.SuperMarketandConvenienceStore_name);

        Keyboard    keyboard("変更する商品を選択", SuperMarketandConvenienceStore_No);
        int         choice = keyboard.Open();

        if( choice >= 0 )
        {
        Keyboard    aiueo("アイテムIDを入力");
        u16 a;
        aiueo.Open(a);
        Process::Write16(SuperMarketandConvenienceStore_Item[choice].SuperMarketandConvenienceStore_ID, a);
    }
    }
	//---------------------------------------------------------------
	// コンビニ商品変更
	//---------------------------------------------------------------
struct CONVENIENCESTORE_ITEM
    {
        const u32    ConvenienceStore_ID;
        const char  *ConvenienceStore_name;
    };

    static const std::vector<CONVENIENCESTORE_ITEM> ConvenienceStore_Item =
    {
		{ 0x31FABCBC, "家具上" },
		{ 0x31FABCC0, "家具真ん中" },
		{ 0x31FABCC4, "家具下" },
		{ 0x31FABC80, "壁紙" },
		{ 0x31FABC88, "床" },
		{ 0x31FABC90, "ラッピング" },
		{ 0x31FABC94, "手紙" },
		{ 0x31FABC70, "ツール左" },
        { 0x31FABC78, "ツール右" },
        { 0x31FABCAC, "フォーチュンクッキー上" },
        { 0x31FABCB0, "フォーチュンクッキー下" },
		{ 0x31FABCA0, "お薬" },

		
		
    }; 
    void    Change_ConvenienceStore(MenuEntry *entry)
    {
        static StringVector ConvenienceStore_No;

        if (ConvenienceStore_No.empty()) for (const CONVENIENCESTORE_ITEM &i : ConvenienceStore_Item) ConvenienceStore_No.push_back(i.ConvenienceStore_name);

        Keyboard    keyboard("変更する商品を選択", ConvenienceStore_No);
        int         choice = keyboard.Open();

        if( choice >= 0 )
        {
        Keyboard    aiueo("アイテムIDを入力");
        u16 a;
        aiueo.Open(a);
        Process::Write16(ConvenienceStore_Item[choice].ConvenienceStore_ID, a);
    }
    }
	//---------------------------------------------------------------
	// 商店商品変更
	//---------------------------------------------------------------
struct SYUTEN_ITEM
    {
        const u32    Syuten_ID;
        const char  *Syuten_name;
    };

    static const std::vector<SYUTEN_ITEM> Syuten_Item =
    {
		{ 0x31FABCBC, "家具左" },
		{ 0x31FABCC0, "家具右" },
		{ 0x31FABC90, "ラッピング" },
		{ 0x31FABC94, "手紙" },
		{ 0x31FABC70, "ツール" },
        { 0x31FABCAC, "フォーチュンクッキー上" },
		
		
    }; 
    void    Change_Syuten(MenuEntry *entry)
    {
        static StringVector Syuten_No;

        if (Syuten_No.empty()) for (const SYUTEN_ITEM &i : Syuten_Item) Syuten_No.push_back(i.Syuten_name);

        Keyboard    keyboard("変更する商品を選択", Syuten_No);
        int         choice = keyboard.Open();

        if( choice >= 0 )
        {
        Keyboard    aiueo("アイテムIDを入力");
        u16 a;
        aiueo.Open(a);
        Process::Write16(Syuten_Item[choice].Syuten_ID, a);
    }
    }
	//---------------------------------------------------------------
	// 服屋商品変更
	//---------------------------------------------------------------
struct CLOTH_SHOP_ITEM
    {
        const u32    Cloth_shop_ID;
        const char  *Cloth_shop_name;
    };

    static const std::vector<CLOTH_SHOP_ITEM> Cloth_shop_Item =
    {
		{ 0x31FABCEC, "左内側" },
		{ 0x31FABCF0, "左中央" },
		{ 0x31FABCF4, "中央" },
		{ 0x31FABCF8, "右内側" },
		{ 0x31FABCFC, "右外側" },
		
		
    }; 
    void    Change_Cloth_shop(MenuEntry *entry)
    {
        static StringVector Cloth_shop_No;

        if (Cloth_shop_No.empty()) for (const CLOTH_SHOP_ITEM &i : Cloth_shop_Item) Cloth_shop_No.push_back(i.Cloth_shop_name);

        Keyboard    keyboard("変更する商品を選択", Cloth_shop_No);
        int         choice = keyboard.Open();

        if( choice >= 0 )
        {
        Keyboard    aiueo("アイテムIDを入力");
        u16 a;
        aiueo.Open(a);
        Process::Write16(Cloth_shop_Item[choice].Cloth_shop_ID, a);
    }
    }
	//---------------------------------------------------------------
	// アクセサリー屋商品変更
	//---------------------------------------------------------------
struct ACCESSORY_SHOP_ITEM
    {
        const u32    Accessory_Shop_ID;
        const char  *Accessory_Shop_name;
    };

    static const std::vector<ACCESSORY_SHOP_ITEM> Accessory_Shop_Item =
    {
		{ 0x31FB00B8, "帽子左" },
		{ 0x31FB00BC, "帽子中央" },
		{ 0x31FB00C0, "帽子右" },
		{ 0x31FB00C4, "アクセサリー上" },
		{ 0x31FB00C8, "アクセサリー中央" },
		{ 0x31FB00CC, "アクセサリー下" },
		{ 0x31FB00D0, "傘" },
		
		
    }; 
    void    Change_Accessory_Shop(MenuEntry *entry)
    {
        static StringVector Accessory_Shop_No;

        if (Accessory_Shop_No.empty()) for (const ACCESSORY_SHOP_ITEM &i : Accessory_Shop_Item) Accessory_Shop_No.push_back(i.Accessory_Shop_name);

        Keyboard    keyboard("変更する商品を選択", Accessory_Shop_No);
        int         choice = keyboard.Open();

        if( choice >= 0 )
        {
        Keyboard    aiueo("アイテムIDを入力");
        u16 a;
        aiueo.Open(a);
        Process::Write16(Accessory_Shop_Item[choice].Accessory_Shop_ID, a);
    }
    }
	//---------------------------------------------------------------
	// 靴商品変更
	//---------------------------------------------------------------
struct SHOE_SHOP_ITEM
    {
        const u32    Shoe_Shop_ID;
        const char  *Shoe_Shop_name;
    };

    static const std::vector<SHOE_SHOP_ITEM> Shoe_Shop_Item =
    {
		{ 0x31FB022E, "靴左外側" },
		{ 0x31FB0232, "靴左中央" },
		{ 0x31FB0236, "靴右中央" },
		{ 0x31FB023A, "靴右外側" },
		{ 0x31FB023E, "靴下右" },
		{ 0x31FB0242, "靴下左" },
		
		
    }; 
    void    Change_Shoe_Shop(MenuEntry *entry)
    {
        static StringVector Shoe_Shop_No;

        if (Shoe_Shop_No.empty()) for (const SHOE_SHOP_ITEM &i : Shoe_Shop_Item) Shoe_Shop_No.push_back(i.Shoe_Shop_name);

        Keyboard    keyboard("変更する商品を選択", Shoe_Shop_No);
        int         choice = keyboard.Open();

        if( choice >= 0 )
        {
        Keyboard    aiueo("アイテムIDを入力");
        u16 a;
        aiueo.Open(a);
        Process::Write16(Shoe_Shop_Item[choice].Shoe_Shop_ID, a);
    }
    }
	//---------------------------------------------------------------
	// 交番商品変更
	//---------------------------------------------------------------
struct POLICESTATION_ITEM
    {
        const u32    PoliceStation_ID;
        const char  *PoliceStation_name;
    };

    static const std::vector<POLICESTATION_ITEM> PoliceStation_Item =
    {
		{ 0x31FABBE2, "左上" },
		{ 0x31FABBE6, "左上外側" },
		{ 0x31FABBEA, "左上内側" },
		{ 0x31FABBEE, "右上内側" },
		{ 0x31FABBF2, "右上外側" },
		{ 0x31FABBF6, "右上" },
		{ 0x31FABBFA, "左下" },
		{ 0x31FABBFE, "中央左" },
		{ 0x31FABC02, "中央右" },
		{ 0x31FABC06, "右下" },
		
		
    }; 
    void    Change_PoliceStation(MenuEntry *entry)
    {
        static StringVector PoliceStation_No;

        if (PoliceStation_No.empty()) for (const POLICESTATION_ITEM &i : PoliceStation_Item) PoliceStation_No.push_back(i.PoliceStation_name);

        Keyboard    keyboard("変更する商品を選択", PoliceStation_No);
        int         choice = keyboard.Open();

        if( choice >= 0 )
        {
        Keyboard    aiueo("アイテムIDを入力");
        u16 a;
        aiueo.Open(a);
        Process::Write16(PoliceStation_Item[choice].PoliceStation_ID, a);
    }
    }
	//---------------------------------------------------------------
	// オートキャンプ場商品変更
	//---------------------------------------------------------------
struct CAMP_ITEM
    {
        const u32    Camp_ID;
        const char  *Camp_name;
    };

    static const std::vector<CAMP_ITEM> Camp_Item =
    {
		{ 0x31FB4854, "左" },
		{ 0x31FB4858, "右" },
		
		
    }; 
    void    Change_Camp(MenuEntry *entry)
    {
        static StringVector Camp_No;

        if (Camp_No.empty()) for (const CAMP_ITEM &i : Camp_Item) Camp_No.push_back(i.Camp_name);

        Keyboard    keyboard("変更する商品を選択", Camp_No);
        int         choice = keyboard.Open();

        if( choice >= 0 )
        {
        Keyboard    aiueo("アイテムIDを入力");
        u16 a;
        aiueo.Open(a);
        Process::Write16(Camp_Item[choice].Camp_ID, a);
    }
    }
	//---------------------------------------------------------------
	// 博物館二階商品変更
	//---------------------------------------------------------------
struct HAKUBUTUKAN_ITEM
    {
        const u32    Hakubutukan_ID;
        const char  *Hakubutukan_name;
    };

    static const std::vector<HAKUBUTUKAN_ITEM> Hakubutukan_Item =
    {
		{ 0x31FB46BE, "上" },
		{ 0x31FB46C2, "左" },
		{ 0x31FB46C6, "右" },
		
		
    }; 
    void    Change_Hakubutukan(MenuEntry *entry)
    {
        static StringVector Hakubutukan_No;

        if (Hakubutukan_No.empty()) for (const HAKUBUTUKAN_ITEM &i : Hakubutukan_Item) Hakubutukan_No.push_back(i.Hakubutukan_name);

        Keyboard    keyboard("変更する商品を選択", Hakubutukan_No);
        int         choice = keyboard.Open();

        if( choice >= 0 )
        {
        Keyboard    aiueo("アイテムIDを入力");
        u16 a;
        aiueo.Open(a);
        Process::Write16(Hakubutukan_Item[choice].Hakubutukan_ID, a);
    }
    }
	//---------------------------------------------------------------
	// いなりギャラリー商品変更
	//---------------------------------------------------------------
struct GALLERY_ITEM
    {
        const u32    Gallery_ID;
        const char  *Gallery_name;
    };

    static const std::vector<GALLERY_ITEM> Gallery_Item =
    {
		{ 0x31FB0130, "左上" },
		{ 0x31FB0134, "右上" },
		{ 0x31FB0138, "左下" },
		{ 0x31FB013C, "右下" },
		
		
    }; 
    void    Change_Gallery(MenuEntry *entry)
    {
        static StringVector Gallery_No;

        if (Gallery_No.empty()) for (const GALLERY_ITEM &i : Gallery_Item) Gallery_No.push_back(i.Gallery_name);

        Keyboard    keyboard("変更する商品を選択", Gallery_No);
        int         choice = keyboard.Open();

        if( choice >= 0 )
        {
        Keyboard    aiueo("アイテムIDを入力");
        u16 a;
        aiueo.Open(a);
        Process::Write16(Gallery_Item[choice].Gallery_ID, a);
    }
    }
	//---------------------------------------------------------------
	// リサイクルショップ商品変更
	//---------------------------------------------------------------
struct RECYCLE_SHOP_ITEM
    {
        const u32    Recycle_Shop_ID;
        const char  *Recycle_Shop_name;
    };

    static const std::vector<RECYCLE_SHOP_ITEM> Recycle_Shop_Item =
    {
		{ 0x31FB02CC, "前左" },
		{ 0x31FB02CC, "前右" },
		{ 0x31FB02CC, "真ん中左" },
		{ 0x31FB02CC, "真ん中右" },
		{ 0x31FB02CC, "後ろ左外側" },
		{ 0x31FB02CC, "後ろ左内側" },
		{ 0x31FB02CC, "後ろ右内側" },
		{ 0x31FB02CC, "後ろ右外側" },
		{ 0x31FB024C, "リメイク前P1" },
		{ 0x31FB025C, "リメイク後P1" },
		
		
    }; 
    void    Change_Recycle_Shop(MenuEntry *entry)
    {
        static StringVector Recycle_Shop_No;

        if (Recycle_Shop_No.empty()) for (const RECYCLE_SHOP_ITEM &i : Recycle_Shop_Item) Recycle_Shop_No.push_back(i.Recycle_Shop_name);

        Keyboard    keyboard("変更する商品を選択", Recycle_Shop_No);
        int         choice = keyboard.Open();

        if( choice >= 0 )
        {
        Keyboard    aiueo("アイテムIDを入力");
        u16 a;
        aiueo.Open(a);
        Process::Write16(Recycle_Shop_Item[choice].Recycle_Shop_ID, a);
    }
    }
		//---------------------------------------------------------------
	struct CHANGE_AREA
	{
		const char  *name;
		const u8	id;
	};

	static const std::vector<CHANGE_AREA> change_area =
	{
	  { "村", 0x00 },
	  { "商店街", 0x01 },
	  { "駅", 0x02 },
	  { "P1 家 Main", 0x03 },
	  { "P1 家 UP", 0x04 },
	  { "P1 家 DOWN", 0x05 },
	  { "P1 家 Right", 0x06 },
	  { "P1 家 left", 0x07 },
	  { "P1 家 Back", 0x08 },  
	  { "P2 家 Main", 0x09 },
	  { "P2 家 UP", 0x0A },
	  { "P2 家 DOWN", 0x0B },
	  { "P2 家 Right", 0x0C },
	  { "P2 家 left", 0x0D },
	  { "P2 家 Back", 0x0E },
	  { "P3 家 Main", 0x0F },
	  { "P3 家 UP", 0x10 },
	  { "P3 家 DOWN", 0x11 },
	  { "P3 家 Right", 0x12 },
	  { "P3 家 left", 0x13 },
	  { "P3 家 Back", 0x14 },
	  { "P4 家 Main", 0x15 },
	  { "P4 家 UP", 0x16 },
	  { "P4 家 DOWN", 0x17 },
	  { "P4 家 Right", 0x18 },
	  { "P4 家 left", 0x19 },
	  { "P4 家 Back", 0x1A },
	  { "A1 家", 0x1B },
	  { "A2 家", 0x1C },
	  { "A3 家", 0x1D },
	  { "A4 家", 0x1E },
	  { "A5 家", 0x1F },
	  { "A6 家", 0x20 },
	  { "A7 家", 0x21 },
	  { "A8 家", 0x22 },
	  { "A9 家", 0x23 },
	  { "役場", 0x23 },
	  { "return error", 0x28 },
	  { "Come to the village", 0x2A },
	  { "R-Parkers", 0x2B },
	  { "モダンな交番", 0x30 },
	  { "クラシックな交番", 0x31 },
	  { "カフェ", 0x32 },
	  { "カフェ バイトイベント", 0x33 },
	  { "夢見の館", 0x37 },
	  { "デパート1階", 0x3C },
	  { "デパート2階", 0x3D },
	  { "デパート3階", 0x3E },
	  { "エイブルシスターズ 服屋", 0x3F },
	  { "エイブルシスターズ アクセ屋", 0x40 },
	  { "Shoe Shank 靴屋", 0x40 },
	  { "不動産屋", 0x41 },
	  { "Club444", 0x47 },
	  { "ビューティーサロン スピーディ", 0x48 },
	  { "博物館 中央", 0x49 },
	  { "博物館 魚", 0x4A },
	  { "博物館 虫", 0x4D },
	  { "博物館 化石", 0x50 },
	  { "博物館 絵画", 0x53 },
	  { "博物館 2階", 0x55 },
	  { "博物館 2階 左上", 0x56 },
	  { "博物館 2階 左下", 0x57 },
	  { "博物館 2階 右上", 0x58 },
	  { "博物館 2階 右下", 0x59 },
	  { "郵便局", 0x5A },
	  { "夢見の館", 0x5B },
	  { "証明写真機", 0x5C },
	  { "Train", 0x5D },
	  { "Dream Bed Error", 0x64 },
	  { "島へ行くイベント", 0x65 },
	  { "村へ戻るイベント", 0x66 },
	  { "島 室内", 0x67 },
	  { "島 屋外", 0x68 },
	  { "Go island", 0x65 },
	  { "ハッピーホームアカデミー 中央", 0x8E },
	  { "オートキャンプ場", 0xA0 },
	  { "オートキャンプ場 キャンパーの車の中", 0xA1 },
	  { "しずえがいるエリア", 0x63 },
	  { "タイトル", 0x5E },

	  { "カメラ", 0xa4 },
	  { "住民登録", 0x5d },
	  { "オレンジテント", 0x25 },
	  { "模様替えイベント", 0xa3 },
	  { "釣り結果", 0x2F },
	};
	//---------------------------------------------------------------
	// エリア変更
	//---------------------------------------------------------------
	void	change_Area(MenuEntry *entry)
	{
		static StringVector items;

		if (items.empty()) for(const CHANGE_AREA &i : change_area) items.push_back(i.name);

		Keyboard	keyboard("移動したい場所を選んでください。", items);
		int		 choice = keyboard.Open();

		if (choice >= 0) Process::Write8(0x0095133A, change_area[choice].id);

		u32 loc;
		if(Process::Read32(0x33099F84, loc))
		{
			if (loc == -1)
			{
				Process::Write16(0x33099FB3, 0xC900);
			}
			else {
				Process::Write32(0x3309a0dc, 0x380FF138);
				Process::Write32(0x3309a0df, 0x380FF138);
			}
		}
	}
	//---------------------------------------------------------------
	// 座標移動A+C-pad
	//---------------------------------------------------------------
	    void    coordCType(MenuEntry *entry)
    {
        u32 loc;
        float outz;
        float outx;
        float inz;
        float inx;
        Process::ReadFloat(0x33099E58, outz);
        Process::ReadFloat(0x33099E50, outx);
        Process::ReadFloat(0x33099F84, inz);
        Process::ReadFloat(0x33099F7C, inx);

           
        Process::Read32(0x33099F84, loc);
        if (loc == -1)
        {
            if (Controller::IsKeysDown(A + CPadUp))
            {
                outz = outz - 9.0;
                Process:: WriteFloat(0x33099E58, outz);
            }
            if (Controller::IsKeysDown(A + CPadDown))
            {
                outz = outz + 9.0;
                Process:: WriteFloat(0x33099E58, outz);
            }
            if (Controller::IsKeysDown(A + CPadLeft))
            {
                outx = outx - 9.0;
                Process:: WriteFloat(0x33099E50, outx);
            }
            if (Controller::IsKeysDown(A + CPadRight))
            {
                outx = outx + 9.0;
                Process:: WriteFloat(0x33099E50, outx);
            }
        }
        else 
        {
            if (Controller::IsKeysDown(A + CPadUp))
            {
                inz = inz - 9.0;
                Process:: WriteFloat(0x33099F84, inz);
            }
            if (Controller::IsKeysDown(A + CPadDown))
            {
                inz = inz + 9.0;
                Process:: WriteFloat(0x33099F84, inz);
            }
             if (Controller::IsKeysDown(A + CPadLeft))
             {
                inx = inx - 9.0;
                Process:: WriteFloat(0x33099F7C, inx);
            }
            if (Controller::IsKeysDown(A + CPadRight))
            {
                inx = inx + 9.0;
                Process:: WriteFloat(0x33099F7C, inx);
            }
        }        
    }
	//---------------------------------------------------------------
	// 座標移動A+D-pad
	//---------------------------------------------------------------
	   void    coord(MenuEntry *entry)
    {
        u32 loc;
        float outz;
        float outx;
        float inz;
        float inx;
        Process::ReadFloat(0x33099E58, outz);
        Process::ReadFloat(0x33099E50, outx);
        Process::ReadFloat(0x33099F84, inz);
        Process::ReadFloat(0x33099F7C, inx);

           
        Process::Read32(0x33099F84, loc);
        if (loc == -1)
        {
            if (Controller::IsKeysDown(A + DPadUp))
            {
                outz = outz - 9.0;
                Process:: WriteFloat(0x33099E58, outz);
            }
            if (Controller::IsKeysDown(A + DPadDown))
            {
                outz = outz + 9.0;
                Process:: WriteFloat(0x33099E58, outz);
            }
            if (Controller::IsKeysDown(A + DPadLeft))
            {
                outx = outx - 9.0;
                Process:: WriteFloat(0x33099E50, outx);
            }
            if (Controller::IsKeysDown(A + DPadRight))
            {
                outx = outx + 9.0;
                Process:: WriteFloat(0x33099E50, outx);
            }
        }
        else 
        {
            if (Controller::IsKeysDown(A + DPadUp))
            {
                inz = inz - 9.0;
                Process:: WriteFloat(0x33099F84, inz);
            }
            if (Controller::IsKeysDown(A + DPadDown))
            {
                inz = inz + 9.0;
                Process:: WriteFloat(0x33099F84, inz);
            }
             if (Controller::IsKeysDown(A + DPadLeft))
             {
                inx = inx - 9.0;
                Process:: WriteFloat(0x33099F7C, inx);
            }
            if (Controller::IsKeysDown(A + DPadRight))
            {
                inx = inx + 9.0;
                Process:: WriteFloat(0x33099F7C, inx);
            }
        }        
    }
	//---------------------------------------------------------------
	// 天気変更
	//---------------------------------------------------------------
	struct WEATHER_CHANGE
	{
		const u32	Weather_ID;
		const char  *Weather_name;
	};

	static const std::vector<WEATHER_CHANGE> Weather_Change =
	{
		  
		{ 0xE3A00001, "晴れ" },
		{ 0xE3A00002, "曇り" },
		{ 0xE3A00003, "雨" },
		{ 0xE3A00004, "大雨" },
		{ 0xE3A00005, "雪" },
		{ 0xE3A00006, "大雪" },
	}; 
	void	change_Weather(MenuEntry *entry)
	{
		static StringVector Weather_No;

		if (Weather_No.empty()) for (const WEATHER_CHANGE &i : Weather_Change) Weather_No.push_back(i.Weather_name);

		Keyboard	keyboard("どの天気に変更しますか。", Weather_No);
		int		 choice = keyboard.Open();

		if( choice >= 0 ) Process::Write32( 0x0062E728, Weather_Change[choice].Weather_ID );
	}
	//---------------------------------------------------------------
	// 駅の旗大きさ変更
	//---------------------------------------------------------------
	void	frag_change(MenuEntry *entry)
	{
			float fxx;

			Keyboard keyboard(Utils::Format("旗の大きさを指定してください。デフォルト14.1421(min1.8750max536870912)") );
            int choice = keyboard.Open(fxx);
            if(choice >= 0)
			{ // 入力あり
				if( fxx >= 1.8750 && fxx <= 536870912 ) Process::WriteFloat( 0x001C8CAC, fxx );
			}
	}
	//---------------------------------------------------------------
	// 高額買取品変更
	//---------------------------------------------------------------
	    void    Change_Recycle1(MenuEntry *entry)
    {
            u16 fxx;

            Keyboard keyboard("ItemIDを入力してください。");
            u16 choice = keyboard.Open(fxx);
            if(choice >= 0)
            { // 入力あり
                Process::Write16( 0x31FB02A0, fxx );
            }
    }
	//---------------------------------------------------------------
	// 株価変更
	//---------------------------------------------------------------
//	    void    Change_Recycle2(MenuEntry *entry)
//    {
//            u16 fxx;
//
//            Keyboard keyboard("ItemIDを入力してください。");
//			keyboard.IsHexadecimal( false );
//            u16 choice = keyboard.Open(fxx);
//            if(choice >= 0)
//            { // 入力あり
//                Process::Write16( 0x330DBE30, fxx );
//            }
//    }
	//---------------------------------------------------------------
	// 駅員モーション変更
	//---------------------------------------------------------------
	struct MOTION1S
	{
		const u8	motion_ekiin_map_id;
		const char  *name;
	};

	static const std::vector<CHARS_U8_MAP> motion_ekiin_map =
	{
		{ 0x00, "戻す" },
		{ 0x01, "口を開けて笑う" },
		{ 0x02, "爆笑する" },
		{ 0x03, "お花畑" },
		{ 0x04, "ハート" },
		{ 0x05, "ウキウキ" },
		{ 0x06, "にらむ" },
		{ 0x07, "むか" },
		{ 0x08, "プンプン" },
		{ 0x09, "困る" },
		{ 0x0A, "ため息" },
		{ 0x0B, "考える" },
		{ 0x0C, "がっくり" },
		{ 0x0D, "焦る" },
		{ 0x0E, "泣く" },
		{ 0x10, "びっくり" },
		{ 0x11, "驚く" },
		{ 0x12, "ガーン" },
		{ 0x13, "ヒュー" },
		{ 0x14, "振るえる" },
		{ 0x15, "うなずく" },
		{ 0x16, "ひらめいた" },
		{ 0x17, "はてな" },
		{ 0x18, "失恋" },
		{ 0x19, "あくび" },
		{ 0x1A, "照れる" },
		{ 0x1B, "やれやれ" },
		{ 0x1C, "悪だくみ" },
		{ 0x1D, "拍手" },
		{ 0x1E, "くしゃみ" },
		{ 0x20, "やぁ" },
		{ 0x21, "エッヘン" },
		{ 0x24, "苦笑い" },
		{ 0x26, "ニコッ" },
		{ 0x27, "もじもじ" },
		{ 0x28, "首を振る" },
		{ 0x29, "やらかしたー" },
		{ 0x2A, "くるりんぱ" },
		{ 0x2B, "想像する" },
		{ 0x2C, "シャキーン" },
		{ 0x2E, "スペシャル" },
		{ 0x0F, "没1驚く" },//R-パーカーズで住民が商品を見つけるモーション
		{ 0x1F, "没2叫ぶ" },//村長が村に来た時に住民が「よ・う・こ・そ」と叫ぶときのモーション
		{ 0x22, "没3汗をかく" },//暑い日にそのプレイヤーが初めにやるモーション
		{ 0x23, "没4シャキン" },//有名なキノコのモーションの一種
		{ 0x25, "没5ニコニコ" },//住民が追いかけてくるとき
		{ 0x2D, "没6寝る" },//村が雑草まみれの時にれいじが村にいるときor博物館のフクロウ
		{ 0x2F, "没7倒れる" },//ジョニーが浜辺にいるとき
		{ 0x30, "没8埋まって怒る" },//謎
		{ 0x32, "没9埋まってヒュー" },//謎
		{ 0x33, "没10埋まってびっくり" },//謎
		{ 0x34, "没11埋まってにらむ" },//顔出し看板？
		{ 0x35, "没12埋まっててへぺろ" },//顔出し看板？
		{ 0x36, "没13埋まって激怒" },//リセットさんのモーション？
		{ 0x37, "没14埋まって真剣" },//リセットさんのモーション？
		{ 0x38, "没15けいれい" },//交番の警官がやるモーション
		{ 0x3B, "没16無表情びっくり" },//謎
		{ 0x3E, "没17紫もやもや" },//占いの館のモーション
		{ 0x3F, "没18どれどれ" },//博物館で鑑定するときのモーション
		{ 0x40, "没19お化粧" },//謎
		
		
	}; 
//---------------------------------------------------------------
    void Motion1(MenuEntry *entry)
    {
        static StringVector items;

        if (items.empty()) for (const CHARS_U8_MAP &i : motion_ekiin_map) items.push_back(i.name);

        Keyboard    keyboard("モーションに変更選択", items);
        int         choice = keyboard.Open();

//        if( choice >= 0 ) Process::Write8( 0x330F25A6, motion_ekiin_map[choice].id );
		if( choice >= 0 ) motion_ekiin = motion_ekiin_map[choice].id;
        entry->Disable();
    }
	// ------------------------------------------------------------------
	// 常時実行
	// ------------------------------------------------------------------
	void always_runing(MenuEntry *entry)
	{
		if(motion_ekiin) *(u8 *)0x330F25A6 = motion_ekiin;
	}
	//---------------------------------------------------------------
	// 連続アクション
	//---------------------------------------------------------------
    void	Reaction1(MenuEntry *entry)
    {
        u32 a;
		{
			if(Process::Read32(0x33099F84, a) && a == -1)
				Process::Write32(0x33099FE4, 0x7C7B7C00);
			else
				Process::Write32(0x3309A110, 0x7C7B7C00);
		}
    }
	//---------------------------------------------------------------
	// 村の明るさ変更
	//---------------------------------------------------------------
	void	akarusa_change(MenuEntry *entry)
	{
			float fxx;

			Keyboard keyboard(Utils::Format("村の明るさを指定してください。") );
            int choice = keyboard.Open(fxx);
            if(choice >= 0)
			{ // 入力あり
				Process::WriteFloat( 0x001E6CB4, fxx );
			}
	}
	//---------------------------------------------------------------
	// タイマーチート虫
	//---------------------------------------------------------------
	    void    Taima_musi(MenuEntry *entry)
    {
            u32 fxx;

            Keyboard keyboard("虫の数を指定してください。");
			keyboard.IsHexadecimal( false );
            u32 choice = keyboard.Open(fxx);
            if(choice >= 0)
            { // 入力あり
                Process::Write32( 0x0094A724, fxx );
            }
    }
	//---------------------------------------------------------------
	// タイマーチート魚
	//---------------------------------------------------------------
	    void    Taima_sakana(MenuEntry *entry)
    {
            u32 fxx;

            Keyboard keyboard("魚の数を指定してください。");
			keyboard.IsHexadecimal( false );
            u32 choice = keyboard.Open(fxx);
            if(choice >= 0)
            { // 入力あり
                Process::Write32( 0x0094A72C, fxx );
            }
    }
	//---------------------------------------------------------------
	// タイマーチート海の幸
	//---------------------------------------------------------------
	    void    Taima_uminosati(MenuEntry *entry)
    {
            u32 fxx;

            Keyboard keyboard("海の幸の数を指定してください。");
			keyboard.IsHexadecimal( false );
            u32 choice = keyboard.Open(fxx);
            if(choice >= 0)
            { // 入力あり
                Process::Write32( 0x0094A728, fxx );
            }
    }
	//---------------------------------------------------------------
	// 室外アイテム判定変更
	//---------------------------------------------------------------
	    void    Change_Item(MenuEntry *entry)
    {
            u32 fxx;

            Keyboard keyboard("ItemIDを入力してください。");
            u32 choice = keyboard.Open(fxx);
            if(choice >= 0)
            { // 入力あり
                Process::Write32( 0x009AE248, fxx );
            }
    }
	//---------------------------------------------------------------
	// 性別変更
	//---------------------------------------------------------------
	struct SEIBETU
	{
		const u8	seibetu_ID;
		const char  *seibetu_name;
	};

	static const std::vector<SEIBETU> seibetu =
	{
		{ 0x00, "男" },
		{ 0x01, "女" },
	}; 
	void	change_seibetu(MenuEntry *entry)
	{
		static StringVector seibetu_No;

		if (seibetu_No.empty()) for (const SEIBETU &i : seibetu) seibetu_No.push_back(i.seibetu_name);

		Keyboard	keyboard("なりたい性別を選んでください。", seibetu_No);
		int		 choice = keyboard.Open();

		u32 a;
		 if(Process::Read32(0x00AA914C, a) && a == 0x31F49AA0)
			if( choice >= 0 ) Process::Write8( 0x31F4F05A, seibetu[choice].seibetu_ID );
		 if(Process::Read32(0x00AA914C, a) && a == 0x31F53F20)
			if( choice >= 0 ) Process::Write8( 0x31F594DA, seibetu[choice].seibetu_ID );
		 if(Process::Read32(0x00AA914C, a) && a == 0x31F5E3A0)
			if( choice >= 0 ) Process::Write8( 0x31F6395A, seibetu[choice].seibetu_ID );
		 if(Process::Read32(0x00AA914C, a) && a == 0x31F68820)
			if( choice >= 0 ) Process::Write8( 0x31F6DDDA, seibetu[choice].seibetu_ID );
	}
	//---------------------------------------------------------------
    // 芝生の濃さ変更
    //---------------------------------------------------------------
//    void    Grass(MenuEntry *entry)
//    {
//        u32 fxx;
//
//        for( 0x31FA3300; adrs16 < (u16 *)0x31FS5B7C; adrs16++ )
//        {
//        if*adrs16 = keyboard.Open(fxx);
//        }
//    }
}
