#include "cheats.hpp"
#include "3DS.h"

namespace	CTRPluginFramework
{
	// This function is called on the plugin starts, before main
	void PatchProcess( FwkSettings &settings ) { }

	#define MAJOR_VERSION		2
	#define MINOR_VERSION		0
	#define REVISION_VERSION	0
	#define STRINGIFY( x )		#x
	#define TOSTRING( x )		STRINGIFY( x )
	#define STRING_VERSION		"[" TOSTRING( MAJOR_VERSION ) "." TOSTRING( MINOR_VERSION ) "." TOSTRING( REVISION_VERSION ) "]"

	std::string green = "" << Color::Green << "";
	std::string orange = "" << Color::Orange << "";
	std::string red = "" << Color::Red << "";
	std::string blue = "" << Color::Blue << "";
	std::string cyan = "" << Color::Cyan << "";
	std::string turquoise = "" << Color::Turquoise << "";
	std::string dogerblue = "" << Color::DodgerBlue << "";
	std::string acnl = "" << Color::Green << "とびだせどうぶつの森";
	std::string sakuseisya = "" << Color::Cyan << "プラグイン作成者";

	const	std::string about = "Plugin作成者\n"
	"JOKERPlugin作成グループ\n"
	"Specal thanks\n"
	"升ﾁﾄ\n"
	"Kenjiy\n"
	"いろは\n"
	"協力ありがとうございます。";

	static MenuEntry *EntryWithHotkey( MenuEntry *entry, const Hotkey &hotkey )
	{
		if( entry != nullptr )
		{
			entry->Hotkeys += hotkey;
			entry->SetArg( new std::string(entry->Name()) );
			entry->Name() += " " + hotkey.ToString();
			entry->Hotkeys.OnHotkeyChangeCallback([](MenuEntry *entry, int index)
			{
					std::string *name = reinterpret_cast < std::string * > (entry->GetArg());
					entry->Name() = *name + " " + entry->Hotkeys[0].ToString();
			} );
		}
		return( entry );
	}
	// --------------------------------------------------------------
	static MenuEntry *EntryWithHotkey( MenuEntry *entry, const std::vector< Hotkey > &hotkeys )
	{
		if( entry != nullptr )
		{
			for( const Hotkey &hotkey: hotkeys ) entry->Hotkeys += hotkey;
		}
		return( entry );
	}
	// --------------------------------------------------------------
	static MenuEntry *EnableEntry( MenuEntry *entry )
	{
		if( entry != nullptr ) entry->Enable();
		return( entry );
	}
	// ---------------------------------------------------------------
	// チート
	// ---------------------------------------------------------------
	static void CreateMenu( PluginMenu &menu )
	{
		menu += new MenuEntry( "常時実行", always_runing );
		menu += new MenuEntry( "ONにしとくといいやつ", Pou );

		menu += new MenuFolder( "" << Color::Red << "動作系", "" << Color::SkyBlue << "動作系フォルダ",
		{
				EntryWithHotkey(new MenuEntry("" << Color::Red << "空気椅子", Action1, "" << Color::SkyBlue << "キーを押すと、椅子に座る。"),
				Hotkey(Key::B, "空気椅子")),
				EntryWithHotkey(new MenuEntry("" << Color::Red << "椅子から降りれない", Action23, "" << Color::SkyBlue << "キーを押すと椅子に降りれないときの動作をします。"),
				Hotkey(Key::B, "椅子から降りれない")),
				EntryWithHotkey(new MenuEntry("" << Color::Red << "気絶", Action14, "" << Color::SkyBlue << "キーを押すと気絶する。\n連続気絶可能"),
				Hotkey(Key::B, "気絶")),
				EntryWithHotkey(new MenuEntry("" << Color::Red << "頭がピッカーん", Action10, "" << Color::SkyBlue << "キーを押すと頭がピカピカになる。"),
				Hotkey(Key::B, "頭がピッカーん")),
				EntryWithHotkey(new MenuEntry("" << Color::Red << "どこでも泳ぐ", Action18, "" << Color::SkyBlue << "キーを長押しすると泳げます。"),
				Hotkey(Key::B, "どこでも泳ぐ")),
				EntryWithHotkey(new MenuEntry("" << Color::Red << "どこでも潜る", Action20, "" << Color::SkyBlue << "キーを押すとどこでも潜れます"),
				Hotkey(Key::B, "どこでも潜る")),
				EntryWithHotkey(new MenuEntry("" << Color::Red << "黒くなって地面から出る", Action4, "" << Color::SkyBlue << "キーを押すと潜って(実際には潜らず黒くなる)地面から出てくる。"),
				Hotkey(Key::B, "黒くなって地面から出る")),
				EntryWithHotkey(new MenuEntry("" << Color::Red << "アイテムを捕まえた", Action5, "" << Color::SkyBlue << "アイテムを拾うときにキーを押すと海の幸を捕まえる動作。"),
				Hotkey(Key::B, "アイテムを捕まえた")),
				EntryWithHotkey(new MenuEntry("" << Color::Red << "クラゲ回避", Action6, "" << Color::SkyBlue << "クラゲに当たった時にキーを押すとクラゲに当たり終わる。"),
				Hotkey(Key::B, "クラゲ回避")),
				EntryWithHotkey(new MenuEntry("" << Color::Red << "右回転+釣り糸を引く", Action24, "" << Color::SkyBlue << "キーを押すと右回転しAを押すと釣り糸を引き戻します。"),
				Hotkey(Key::B, "右回転+釣り糸を引く")),
				EntryWithHotkey(new MenuEntry("" << Color::Red << "前転", Action2, "" << Color::SkyBlue << "キーを押すと前転する。"),
				Hotkey(Key::B, "前転")),
				EntryWithHotkey(new MenuEntry("" << Color::Red << "尻もち", Action3, "" << Color::SkyBlue << "キーを押すと尻もちをつく。"),
				Hotkey(Key::B, "尻もち")),
				EntryWithHotkey(new MenuEntry("" << Color::Red << "綿毛を吐く", Action9, "" << Color::SkyBlue << "キーを押すと綿毛を吐き出す。"),
				Hotkey(Key::B, "綿毛を吐く")),
				EntryWithHotkey(new MenuEntry("" << Color::Red << "唾を吐く", Action26, "" << Color::SkyBlue << "キーを押すと唾を吐きます"),
				Hotkey(Key::B, "唾を吐く")),
				EntryWithHotkey(new MenuEntry("" << Color::Red << "何かを受け取る", Action15, "" << Color::SkyBlue << "キーを押すと何かをもらうアクションをする"),
				Hotkey(Key::B, "何かを受け取る")),
				EntryWithHotkey(new MenuEntry("" << Color::Red << "持ち物を開く", Action19, "" << Color::SkyBlue << "キーを押すと持ち物を開く動作をする。"),
				Hotkey(Key::B, "持ち物を開く")),
				EntryWithHotkey(new MenuEntry("" << Color::Red << "持っているツールを消す", Action25, "" << Color::SkyBlue << "キーを押すと持っているツールを斧が壊れるエフェクトで消します。"),
				Hotkey(Key::B, "持っているツールを消す")),
				EntryWithHotkey(new MenuEntry("" << Color::Red << "叩かれる", Action27, "" << Color::SkyBlue << "キーを押すとピコピコハンマーでたたかれます。"),
				Hotkey(Key::B, "叩かれる")),
				EntryWithHotkey(new MenuEntry("" << Color::Red << "赤バラ表示", Action8, "" << Color::SkyBlue << "キーを押すと赤バラが出てくる。\n" "" << Color::Red << "室外限定"),
				Hotkey(Key::B, "赤バラ表示")),
				EntryWithHotkey(new MenuEntry("" << Color::Red << "かっぺいのボートに立って乗る", Action12, "" << Color::SkyBlue << "キーを押すと船に乗る位置に立つ。"),
				Hotkey(Key::B, "かっぺいのボートに立って乗る")),
				EntryWithHotkey(new MenuEntry("" << Color::Red << "かっぺいのボートに座って乗る", Action16, "" << Color::SkyBlue << "キーを押すと船に乗る。"),
				Hotkey(Key::B, "かっぺいのボートに座って乗る")),
				EntryWithHotkey(new MenuEntry("" << Color::Red << "アクション後に停止", Action22, "" << Color::SkyBlue << "オンにするとアクション後に動作が停止します。"),
				Hotkey(Key::B, "アクション後に停止")),
		} );

		menu += new MenuFolder( "" << Color::Green << "見た目変更", "" << Color::SkyBlue << "見た目変更系フォルダ",
		{
				EntryWithHotkey(new MenuEntry("" << Color::Green << "逆さま", Pose1, "" << Color::SkyBlue << "キーを押すと自分が逆さになる。"), 
					{ Hotkey(Key::L | DPadUp, "逆さま"),
					Hotkey(Key::L | DPadDown, "通常") }),
				EntryWithHotkey(new MenuEntry("" << Color::Green << "Tポーズ", Pose2, "" << Color::SkyBlue << "キーを押すとみんながTポーズをする。"), 
					{ Hotkey(Key::L | DPadUp, "Tポーズ"),
					Hotkey(Key::L | DPadDown, "通常") }),
				new MenuEntry("" << Color::Green << "ひらひら歩き", Pose3, "" << Color::SkyBlue << "オンにするとひらひら歩きをする。"),
				new MenuEntry("" << Color::Green << "顔を初期設定にする", Pose4, "" << Color::SkyBlue << "オンにすると顔が初期設定(目が黒くなり坊主に)なる。\nオフにしてリロードすると元に戻る。"),
				new MenuEntry("" << Color::Green << "駅の旗大きさ変更", nullptr, frag_change, "" << Color::SkyBlue << "駅の旗の大きさを変更できる。"),
		} );

		menu += new MenuFolder( "" << Color::Blue << "判定変更", "" << Color::SkyBlue << "判定変更系のチートです。",
		{
				EntryWithHotkey(new MenuEntry("" << Color::Blue << "花の判定変更", Hantei1, "" << Color::SkyBlue << "キーを押すと、花の判定が変わる。"),
					{ Hotkey(Key::R | DPadUp, "花が散らない"), 
					Hotkey(Key::R | DPadDown, "花が散る") }),
				EntryWithHotkey(new MenuEntry("" << Color::Blue << "見えない壁判定変更", Hantei2, "" << Color::SkyBlue << "キーを押すと、見えない壁の判定が変わる。"),
					{ Hotkey(Key::L | DPadUp, "壁貫通"), 
					Hotkey(Key::L | DPadDown, "壁貫通不可") }),
				EntryWithHotkey(new MenuEntry("" << Color::Blue << "室内判定変更", Hantei3, "" << Color::SkyBlue << "キーを押すと、室内が家の判定になる。"),
					{ Hotkey(Key::Y | DPadUp, "家"), 
					Hotkey(Key::Y | DPadDown, "建物") }),
				new MenuEntry("" << Color::Blue << "プレイヤー判定変更", nullptr, change_Player),
		} );

		menu += new MenuFolder( "" << Color::Yellow << "モーション", "" << Color::SkyBlue << "モーション系フォルダ",
		{
				new MenuEntry("" << Color::Yellow << "連続リアクション", Reaction1, "" << Color::SkyBlue << "オンにすると連続リアクションが出来ます。"),
				EntryWithHotkey(new MenuEntry("" << Color::Yellow << "リアクション四連発", Action7, "" << Color::SkyBlue << "キーを押すと有名なキノコを食べた後に起こるリアクションを繰り返す。"),
				Hotkey(Key::B, "リアクション四連発")),
				new MenuEntry("" << Color::Yellow << "駅員モーション変更", nullptr, Motion1),
				new MenuEntry("" << Color::Yellow << "かっぺいモーション変更", nullptr, Motion2),
				new MenuEntry("" << Color::Yellow << "しずえ(室内)モーション変更", nullptr, Motion3),
				new MenuEntry("" << Color::Yellow << "しずえ(室外)モーション変更", nullptr, Motion4),
				new MenuEntry("" << Color::Yellow << "リサモーション変更", nullptr, Motion5),
				new MenuEntry("" << Color::Yellow << "ケイトモーション変更", nullptr, Motion6),
				new MenuEntry("" << Color::Yellow << "タヌキチモーション変更", nullptr, Motion7),
		} );

		menu += new MenuFolder( "" << Color::Orange << "移動", "" << Color::SkyBlue << "移動系フォルダ",
		{
				new MenuEntry("" << Color::Orange << "エリア変更", nullptr, change_Area),
				new MenuEntry("" << Color::Orange << "座標移動 十時キー", coord, "" << Color::SkyBlue << "A+D-padを押すと座標移動する。"),
				new MenuEntry("" << Color::Orange << "座標移動 スライドパッド", coordCType, "" << Color::SkyBlue << "A+C-padを押すと座標移動する。"),
		} );

		menu += new MenuFolder( "" << Color::Magenta << "画面", "" << Color::SkyBlue << "画面系フォルダ",
		{
				new MenuEntry("" << Color::Magenta << "村の明るさ変更", nullptr, akarusa_change, "" << Color::SkyBlue << "指定した村の明るさに変更します。"),
				new MenuEntry("" << Color::SkyBlue << "ゲームスピード上昇", change_gamespeed, "" << Color::SkyBlue << "オンにするとゲームスピードが上昇する。"),
		} );

		menu += new MenuFolder( "" << Color::SkyBlue << "室外", "" << Color::SkyBlue << "室外系フォルダ",
		{
				new MenuEntry("" << Color::SkyBlue << "天気変更", nullptr, change_Weather, "" << Color::SkyBlue << "天気を変更できる"),
				new MenuEntry("" << Color::SkyBlue << "拾い方変更", nullptr, Player2, "" << Color::SkyBlue << "拾い方を変更できる"),
				new MenuEntry("" << Color::SkyBlue << "道具機能変更", nullptr, Tools_1, "" << Color::SkyBlue << "道具の機能を変更できる。網、釣り竿、スコップ以外を持っているとクラッシュする危険性がある"),
				new MenuEntry("" << Color::SkyBlue << "道具持ち方変更", nullptr, Tools_2, "" << Color::SkyBlue << "道具の持ち方を変更できる。"),
				new MenuEntry("" << Color::SkyBlue << "はや着替え", Inventory2, "" << Color::SkyBlue << "オンにすると着替えが早くなる。"),
				EntryWithHotkey(new MenuEntry("" << Color::SkyBlue << "速く走る", Player1, "" << Color::SkyBlue << "キーを押すと速く走れる"), Hotkey(Key::B, "速く走る")),
				EntryWithHotkey(new MenuEntry("" << Color::SkyBlue << "アイテムを無限に置く", Inventory1, "" << Color::SkyBlue << "キーを押すとアイテムを無限に置けるようになる。"),
			{
				Hotkey(Key::R | DPadRight, "アイテムを無限に置く"),
					Hotkey(Key::R | DPadLeft, "アイテムを普通に置く") }),
				new MenuEntry("" << Color::SkyBlue << "室外アイテム変更", nullptr, Change_Item, "" << Color::SkyBlue << "何かをしたアイテムを変更する"),
				new MenuEntry("" << Color::SkyBlue << "室外アイテム変更(Frag)", nullptr, Change_Item_Frag, "" << Color::SkyBlue << "何かをしたアイテムを変化する(Frag指定用)"),
				new MenuEntry("" << Color::SkyBlue << "室外アイテム変更固定", Change_Item_kotei),
		} );
		MenuFolder	*omise = new MenuFolder( "" << Color::LimeGreen << "お店" );
//		{
		*omise += new MenuFolder( "" << Color::Red << "商店街発展状況変更", "" << Color::SkyBlue << "商店街のお店の発展状況を変更できます。",
		{
				new MenuEntry("" << Color::Red << "占いの館状態変更", nullptr, change_uranai),
				new MenuEntry("" << Color::Red << "夢見の館状態変更", nullptr, change_yumemi),
				new MenuEntry("" << Color::Red << "CLUB444状態変更", nullptr, change_kurabu),
				new MenuEntry("" << Color::Red << "まめつぶ状態変更", nullptr, change_mametubu),
				new MenuEntry("" << Color::Red << "園芸店状態変更", nullptr, change_engei),
				new MenuEntry("" << Color::Red << "美容院状態変更", nullptr, change_biyouin),
				new MenuEntry("" << Color::Red << "靴屋状態変更", nullptr, change_kutuya),
				new MenuEntry("" << Color::Red << "博物館状態変更", nullptr, change_hakubutukan),
		} );

		*omise += new MenuFolder( "" << Color::Green << "商品変更", "" << Color::SkyBlue << "商品変更系チートです。",
		{
				new MenuEntry("" << Color::Green << "CLUB444ハニワ変更", nullptr, Change_Club444),
				new MenuEntry("" << Color::Green << "たぬきハウジングリフォーム変更", nullptr, Change_Housing),
				new MenuEntry("" << Color::Green << "デパートF1商品変更", nullptr, Change_Department_store),
				new MenuEntry("" << Color::Green << "デパートF2商品変更", nullptr, Change_Department_store_F2),
				new MenuEntry("" << Color::Green << "デパートF3商品変更", nullptr, Change_Department_store_F3),
				new MenuEntry("" << Color::Green << "ホームセンター商品変更", nullptr, Change_HomeCenter),
				new MenuEntry("" << Color::Green << "スーパーマーケット商品変更", nullptr, Change_SuperMarket),
				new MenuEntry("" << Color::Green << "まめつぶ商店商品変更", nullptr, Change_Syuten),
				new MenuEntry("" << Color::Green << "デパート園芸店商品変更", nullptr, Change_Department_store_Engei),
				new MenuEntry("" << Color::Green << "ホームセンター園芸店商品変更", nullptr, Change_HomeCenter_Engei),
				new MenuEntry("" << Color::Green << "コンビニ商品変更", nullptr, Change_ConvenienceStore),
				new MenuEntry("" << Color::Green << "スーパーマーケット&コンビニ園芸店商品変更", nullptr, Change_SuperMarketandConvenienceStore),
				new MenuEntry("" << Color::Green << "服屋商品変更", nullptr, Change_Cloth_shop),
				new MenuEntry("" << Color::Green << "アクセサリー店商品変更", nullptr, Change_Accessory_Shop),
				new MenuEntry("" << Color::Green << "靴屋商品変更", nullptr, Change_Shoe_Shop),
				new MenuEntry("" << Color::Green << "博物館二階商品変更", nullptr, Change_Hakubutukan),
				new MenuEntry("" << Color::Green << "島お土産変更", nullptr, Change_Island, "" << Color::Red << "オン島での使用は絶対にしないでください。"),
				new MenuEntry("" << Color::Green << "オートキャンプ場商品変更", nullptr, Change_Camp),
				new MenuEntry("" << Color::Green << "いなりギャラリー美術品変更", nullptr, Change_Gallery),
				new MenuEntry("" << Color::Green << "交番落とし物変更", nullptr, Change_PoliceStation),
				new MenuEntry("" << Color::Green << "リサイクルショップ出品物変更", nullptr, Change_Recycle_Shop),
		} );

		*omise += new MenuFolder( "" << Color::Blue << "その他", "" << Color::SkyBlue << "お店系のチート",
		{
				new MenuEntry("" << Color::Blue << "高額買取品変更", nullptr, Change_Recycle1),
//				new MenuEntry("" << Color::Blue << "株価変更β", nullptr, Change_Recycle2),
		} );
//	}
		menu += omise;

		menu += new MenuFolder( "" << Color::DodgerBlue << "タイマー", "" << Color::SkyBlue << "タイマー系フォルダ",
		{
				new MenuEntry("" << Color::DodgerBlue << "タイマー虫変更", nullptr, Taima_musi, "" << Color::SkyBlue << "指定した数値に変更します。"),
				new MenuEntry("" << Color::DodgerBlue << "タイマー魚変更", nullptr, Taima_sakana, "" << Color::SkyBlue << "指定した数値に変更します。"),
				new MenuEntry("" << Color::DodgerBlue << "タイマー海の幸変更", nullptr, Taima_uminosati, "" << Color::SkyBlue << "指定した数値に変更します。"),
		} );

		menu += new MenuFolder( "" << Color::ForestGreen << "プレイヤー情報", "" << Color::SkyBlue << "プレイヤー情報系フォルダ",
		{
				new MenuEntry("" << Color::ForestGreen << "性別変更", nullptr, change_seibetu),
				new MenuEntry("" << Color::ForestGreen << "バッジ変更", nullptr, change_badge),
		} );
		
		
		menu += new MenuFolder( "" << Color::ForestGreen << "村情報", "" << Color::SkyBlue << "村情報系フォルダ",
		{
			new MenuEntry("" << Color::Yellow << "芝生の濃さ変更", nullptr, sibahu, "" << Color::SkyBlue << "リロードで反映"),
		} );
		
		menu += new MenuFolder( "" << Color::ForestGreen << "無人島", "" << Color::SkyBlue << "無人島系フォルダ",
		{
				new MenuEntry("" << Color::Yellow << "歩数変更P1", nullptr, mujintou_hosuuP1),
				new MenuEntry("" << Color::Yellow << "歩数変更P2", nullptr, mujintou_hosuuP2),
				new MenuEntry("" << Color::Yellow << "歩数変更P3", nullptr, mujintou_hosuuP3),
				new MenuEntry("" << Color::Yellow << "歩数固定", hosuukotei),
				new MenuEntry("" << Color::Yellow << "歩いた時のスコア変更", nullptr, mujintou_WalkScore),
				new MenuEntry("" << Color::Yellow << "歩いた時のスコア固定", Walkscore_kotei),
				new MenuEntry("" << Color::Yellow << "ステージ開放率変更", nullptr, mujinntou_stage_open),
				new MenuEntry("" << Color::Yellow << "棒所持数変更", nullptr, mujintou_Item1),
				new MenuEntry("" << Color::Yellow << "糸所持数変更", nullptr, mujintou_Item2),
				new MenuEntry("" << Color::Yellow << "布きれ所持数変更", nullptr, mujintou_Item3),
				new MenuEntry("" << Color::Yellow << "石ころ所持数変更", nullptr, mujintou_Item4),
				new MenuEntry("" << Color::Yellow << "ぎんこうせき所持数変更", nullptr, mujintou_Item5),
				new MenuEntry("" << Color::Yellow << "きんこうせき所持数変更", nullptr, mujintou_Item6),
				new MenuEntry("" << Color::Yellow << "おくすり所持数変更", nullptr, mujintou_Item7),
				new MenuEntry("" << Color::Yellow << "丸太の入手数変更", nullptr, mujintou_hoof1),
				new MenuEntry("" << Color::Yellow << "船の旗の入手数変更", nullptr, mujintou_hoof2),
				new MenuEntry("" << Color::Yellow << "丸太の残りの数変更", nullptr, mujintou_hoof3),
				new MenuEntry("" << Color::Yellow << "船の旗の残りの数変更", nullptr, mujintou_hoof4),
				new MenuEntry("" << Color::Yellow << "釣り竿所持変更", nullptr, mujintou_Tool1),
				new MenuEntry("" << Color::Yellow << "パチンコ所持変更", nullptr, mujintou_Tool2),
				new MenuEntry("" << Color::Yellow << "網所持変更", nullptr, mujintou_Tool3),
				new MenuEntry("" << Color::Yellow << "スコップ所持変更", nullptr, mujintou_Tool4),
				new MenuEntry("" << Color::Yellow << "銀の釣り竿所持変更", nullptr, mujintou_STool1),
				new MenuEntry("" << Color::Yellow << "銀のパチンコ所持変更", nullptr, mujintou_STool2),
				new MenuEntry("" << Color::Yellow << "銀の網所持変更", nullptr, mujintou_STool3),
				new MenuEntry("" << Color::Yellow << "銀のスコップ所持変更", nullptr, mujintou_STool4),
				new MenuEntry("" << Color::Yellow << "金の釣り竿所持変更", nullptr, mujintou_GTool1),
				new MenuEntry("" << Color::Yellow << "金のパチンコ所持変更", nullptr, mujintou_GTool2),
				new MenuEntry("" << Color::Yellow << "金の網所持変更", nullptr, mujintou_GTool3),
				new MenuEntry("" << Color::Yellow << "金のスコップ所持変更", nullptr, mujintou_GTool4),
				new MenuEntry("" << Color::Yellow << "残り日数変更", nullptr, mujintou_hizuke1),
				new MenuEntry("" << Color::Yellow << "経過日数変更", nullptr, mujintou_hizuke2),
				new MenuEntry("" << Color::Yellow << "食料落下数変更", nullptr, mujintou_syokuryou1),
				new MenuEntry("" << Color::Yellow << "リンゴゲージ変更", nullptr, mujintou_syokuryou2),
				new MenuEntry("" << Color::Yellow << "食料所持数変更", nullptr, mujintou_syokuryou3),
				new MenuEntry("" << Color::Yellow << "落とし穴無効化", nullptr, mujintou_Otosiana),
				new MenuEntry("" << Color::Yellow << "特技変更", nullptr, mujintou_TokugiP1),
				new MenuEntry("" << Color::Yellow << "特技変更", nullptr, mujintou_TokugiP2),
				new MenuEntry("" << Color::Yellow << "特技変更", nullptr, mujintou_TokugiP3),
				new MenuEntry("" << Color::Yellow << "好きな食べ物変更", nullptr, mujintou_FoodP1),
				new MenuEntry("" << Color::Yellow << "好きな食べ物変更", nullptr, mujintou_FoodP2),
				new MenuEntry("" << Color::Yellow << "好きな食べ物変更", nullptr, mujintou_FoodP3),
		} );

//		menu += new MenuFolder( "" << Color::Yellow << "Test", "" << Color::SkyBlue << "Test Folder",
//		{
//				
//		} );
	}
	// -----------------------------------------------------------------------------
	int main( void )
	{
		if(!File::Exists("Pass.bin"))
    {
    static    u16    Pass = 0;
    Keyboard    keyboard("パスワードを入力");
    if(keyboard.Open(Pass)) 
    {
    Pass;
    }

    if (Pass == 0x0515) 
    {
    File::Create("Pass.bin");
    OSD::Notify(Color::Orange<<"Pass is My birthday. Presents please.");
    }
    else 
    {
    OSD::Notify(Color::Orange<<"Pass is 45451919.You`re fuck");
    abort();
    }
    }
		PluginMenu	*menu = new PluginMenu( "" << Color::Red << "J" "" << Color::Green << "O" "" << Color::Blue << "K" "" << Color::Yellow << "E" "" << Color::Magenta << "R", 1, 1, 0, about );
		menu->SynchronizeWithFrame( true );
		CreateMenu( *menu );
		menu->Run();
		return( 0 );
	}
}
