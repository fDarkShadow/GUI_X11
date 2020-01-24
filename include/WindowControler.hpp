#ifndef _X11_WINDOW_CONTROLER_H_
#define _X11_WINDOW_CONTROLER_H_

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <utility>

namespace x11
{
    template<class DisplayServer>
    class WindowControler
    {
        public:
            WindowControler(DisplayServer& display) : _display(display)
            {
                _window = XCreateSimpleWindow(&display_server::getDisplay(_display),DefaultRootWindow(&display_server::getDisplay(_display)),0,0,	
                    300, 300, 5,display_server::getBlackPixel(_display), display_server::getWhitePixel(_display));
                XSetStandardProperties(&display_server::getDisplay(_display),_window,"Howdy","Hi",None,nullptr,0,nullptr);
                XSelectInput(&display_server::getDisplay(_display), _window, ExposureMask|ButtonPressMask|KeyPressMask);
                XClearWindow(&display_server::getDisplay(_display), _window);
                XMapRaised(&display_server::getDisplay(_display), _window);
            }
            virtual ~WindowControler()
            {
                XDestroyWindow(&display_server::getDisplay(_display),_window);
            }

            Window getWindow() const
            {
                return _window;
            }

        private:
            DisplayServer& _display;
            Window _window;
    };

    namespace window_controler
    {
        template<class DisplayServer>
        Window getWindow(const WindowControler<DisplayServer>& controler)
        {
            return controler.getWindow();
        }
    }
}

#endif