#ifndef _X11_CHILD_WINDOW_H_
#define _X11_CHILD_WINDOW_H_

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <utility>

namespace x11
{
    template<class DisplayServer>
    class ChildWindow
    {
        public:
            template<class ParentWindow>
            ChildWindow(
                const ParentWindow& parent,
                const int xPositionPixels,
                const int yPositionPixels,
                const unsigned int widthPixels,
                const unsigned int heightPixels,
                const unsigned int borderWidthPixels,
                const unsigned long borderColor,
                const unsigned long backGroundColor
            ) :
                _window(XCreateSimpleWindow(
                    &display_server::getDisplay(DisplayServer::getInstance()),
                    window_controler::getWindow(parent),
                    xPositionPixels,
                    yPositionPixels,
                    widthPixels,
                    heightPixels,
                    borderWidthPixels,
                    borderColor,
                    backGroundColor
                ))
            {
                //XSelectInput(&display_server::getDisplay(DisplayServer::getInstance()), _window, ExposureMask|ButtonPressMask|KeyPressMask);
                XClearWindow(&display_server::getDisplay(DisplayServer::getInstance()), _window);
                XMapWindow(&display_server::getDisplay(DisplayServer::getInstance()), _window);
            }
            virtual ~ChildWindow()
            {
                XDestroyWindow(&display_server::getDisplay(DisplayServer::getInstance()),_window);
            }

            Window getWindow() const
            {
                return _window;
            }

        private:
            Window _window;
    };

    namespace window_controler
    {
        template<class DisplayServer>
        inline Window getWindow(const ChildWindow<DisplayServer>& controler)
        {
            return controler.getWindow();
        }
        template<class DisplayServer>
        inline void show(const ChildWindow<DisplayServer>& controler)
        {
            XMapWindow(&display_server::getDisplay(DisplayServer::getInstance()), controler.getWindow());
        }
        template<class DisplayServer>
        inline void clear(const ChildWindow<DisplayServer>& controler)
        {
            XClearWindow(&display_server::getDisplay(DisplayServer::getInstance()), controler.getWindow());
        }
    }
}

#endif