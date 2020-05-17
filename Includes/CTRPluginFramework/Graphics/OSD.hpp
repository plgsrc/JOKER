#ifndef CTRPLUGINFRAMEWORK_OSD_HPP
#define CTRPLUGINFRAMEWORK_OSD_HPP

#include "CTRPluginFramework/Graphics/Color.hpp"
#include "ctrulib/services/gspgpu.h"
#include <string>

namespace CTRPluginFramework
{
    using GSPFormat = GSPGPU_FramebufferFormats;

    class Screen
    {
    public:
        bool      IsTop;
        bool      Is3DEnabled;
        u32       LeftFramebuffer;
        u32       RightFramebuffer;
        u32       Stride;
        u32       BytesPerPixel;
        GSPFormat Format;

        /**
         * \brief Get a pointer to the screen's framebuffer
         * \param posX The position on the screen to point to
         * \param posY The position on the screen to point to
         * \param useRightFb If the function must return a pointer to the right framebuffer
         * \return A pointer to the screen's framebuffer at the desired position
         */
		/**
         * \brief スクリーンのフレームバッファにポインタを得る 
         * するために示す映画界の\param posXポジション
         * するために示す映画界の\param posYポジション
         * もしポインタの右のフレームバッファへの機能による返却\param useRightFb
         * 要求されたポジションのスクリーンのフレームバッファへの\return Aポインタ
         */
        u8 *    GetFramebuffer(u32 posX, u32 posY, bool useRightFb = false) const;

        /**
         * \brief Draw a string using Linux's font
         * \param str The string to draw
         * \param posX The position on screen to draw the string to
         * \param posY The position on screen to draw the string to
         * \param foreground The color of the characters
         * \param background The color of the background
         * \return posY + 10 (line feed)
         */
		/**
         * Linuxのフォントを使っている\brief引きストリング
         * 引く\param strストリング
         * するためにストリングを引くスクリーンの\param posXポジション
         * するためにストリングを引くスクリーンの\param posYポジション
         * 文字の\paramフォアグラウンド色
         * 背景の\param背景色
         * \return posY +10（改行）
         */
        u32 Draw(const std::string &str, u32 posX, u32 posY, const Color &foreground = Color::Blank, const Color &background = Color::Black) const;

        /**
         * \brief Draw a string using system font (support utf8 strings with special chars & unicode)
         * \param str The string to draw
         * \param posX The position on screen to draw the string to
         * \param posY The position on screen to draw the string to
         * \param foreground The color of the characters
         * \return posY + 16 (line feed)
         */
		/**
         * システムフォントを使っている\brief引きストリング（サポートutf8によりユニコードは特別な雑用&によってストリングにされる）
         * 引く\param strストリング
         * するためにストリングを引くスクリーンの\param posXポジション
         * するためにストリングを引くスクリーンの\param posYポジション
         * 文字の\paramフォアグラウンド色
         * \return posY +16（改行）
         */
        u32     DrawSysfont(const std::string &str, u32 posX, u32 posY, const Color &foreground = Color::Blank) const;

        /**
         * \brief Draw a rectangle
         * \param posX The position on screen to draw the rectangle
         * \param posY The position on screen to draw the rectangle
         * \param width The width of the rectangle
         * \param height The height of the rectangle
         * \param color The color of the rectangle
         * \param filled If the rectangle is filled or if the function should only draw the border
         */
		/**
         * \brief引き長方形
         * 長方形を引くスクリーンの\param posXポジション
         * 長方形を引くスクリーンの\param posYポジション
         * 長方形の\param幅幅
         * 長方形の\param高さ高さ
         * 長方形の\param色色
         * もし長方形が満たされるか、または、機能が境界を引くだけならば、\paramは満ちた
         */
        void    DrawRect(u32 posX, u32 posY, u32 width, u32 height, const Color &color, bool filled = true) const;
        /**
         * \brief Change the color of a pixel at the desired X, Y position
         * \param posX The X position of the pixel to change
         * \param posY The Y position of the pixel to change
         * \param color The new color of the pixel
         */
        void    DrawPixel(u32 posX, u32 posY, const Color &color) const;

        /**
         * \brief Get the current color of a pixel at X, Y position
         * \param posX The X position of the pixel to read
         * \param posY The Y position of the pixel to read
         * \param pixel The output color of the pixel
         * \param fromRightFb If the pixel must be read from the right framebuffer
         */
		/**
         * X、Yポジションのピクセルの\brief獲得現在の色
         * 読むピクセルの\param posX Xポジション
         * 読むピクセルの\param posY Yポジション
         * ピクセルの\paramピクセルアウトプット色
         * もし右のフレームバッファからのピクセルの読み\param fromRightFb
         */
        void    ReadPixel(u32 posX, u32 posY, Color &pixel, bool fromRightFb = false) const;

    private:
        friend class OSDImpl;
        Screen() {};
    };

    using OSDCallback = bool(*)(const Screen &);
    class OSD
    {
    public:

      /**
         * 一番上のスクリーン、通知期間は、 オンの\brief送信通知書 5 seconds\nである
         * 最大50の通知書が列に並べられうる
         * 通知の\param strテキスト
         * テキストの\paramフォアグラウンド色（デフォルト：空白）
         * 背景の\param背景色（デフォルト：黒）
         * \return 0 ならば 成功、もし通知の不追加-1 
         */

        static int      Notify(std::string str, Color foreground = Color(255, 255, 255), Color background = Color());

        /*
         * \brief追加 個々のゲームのフレームで呼ばれるOSDシステムへのコールバック 
         * 追加する\param cbコールバック
         */
        static void     Run(OSDCallback cb);

		/*
         * OSDシステムからの\brief除去コールバック
         * 取り除く\param cbコールバック
         */
        static void     Stop(OSDCallback cb);

        /* Those are to be used only when the process is paused */
        static const Screen&    GetTopScreen(void);
        static const Screen&    GetBottomScreen(void);
        static void             SwapBuffers(void);

        static void     Lock(void);
        static bool     TryLock(void); //false success, true failure
        static void     Unlock(void);
    };
}

#endif
