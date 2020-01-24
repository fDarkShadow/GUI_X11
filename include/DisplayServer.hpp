#ifndef _X11_DISPLAY_SERVER_H_
#define _X11_DISPLAY_SERVER_H_

#include <X11/Xlib.h>

namespace x11
{
    class DisplayServer
    {
        public:
            DisplayServer()
            {
                _display = XOpenDisplay((char *)0);
                _screen = DefaultScreen(_display);
            }
            virtual ~DisplayServer()
            {
                XCloseDisplay(_display);
            }

            Display& getDisplay() const
            {
                return *_display;
            }
            int getScreen() const
            {
                return _screen;
            }

        private:
            Display* _display;
            int _screen;
    };
    namespace display_server
    {
        inline Display& getDisplay(const DisplayServer& display)
        {
            return display.getDisplay();
        }
        inline int getScreen(const DisplayServer& display)
        {
            return display.getScreen();
        }
        inline unsigned long getWhitePixel(const DisplayServer& display)
        {
            return WhitePixel(&display.getDisplay(), display.getScreen());
        }
        inline unsigned long getBlackPixel(const DisplayServer& display)
        {
            return BlackPixel(&display.getDisplay(), display.getScreen());
        }
    }
}

#endif