#ifndef _X11_DEFAULT_SCREEN_CONTROLER_H_
#define _X11_DEFAULT_SCREEN_CONTROLER_H_

#include <X11/Xlib.h>

namespace x11
{
    template<class DisplayServer>
    class DefaultScreenControler
    {
        public:
            DefaultScreenControler() : _screen(DefaultScreen(&display_server::getDisplay(DisplayServer::getInstance())))
            {}

            int getScreen() const
            {
                return _screen;
            }

        private:
            int _screen;
    };
    namespace screen
    {
        template<class DisplayServer>
        inline int getScreen(const DefaultScreenControler<DisplayServer>& screen)
        {
            return screen.getScreen();
        }
    }
}

#endif