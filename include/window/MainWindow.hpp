#ifndef _X11_MAIN_WINDOW_H_
#define _X11_MAIN_WINDOW_H_

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include <utility>

namespace x11
{
    template<class DisplayServer>
    class MainWindow
    {
        public:
            MainWindow(
                std::string name,
                int xPositionPixels,
                int yPositionPixels,
                unsigned int widthPixels,
                unsigned int heightPixels,
                unsigned int borderWidthPixels,
                unsigned long borderColor,
                unsigned long backGroundColor
            ) :
                _window(XCreateSimpleWindow(
                    &display_server::getDisplay(DisplayServer::getInstance()),
                    DefaultRootWindow(&display_server::getDisplay(DisplayServer::getInstance())),
                    xPositionPixels,
                    yPositionPixels,
                    widthPixels,
                    heightPixels,
                    borderWidthPixels,
                    borderColor,
                    backGroundColor
                ))
            {
                XSetStandardProperties(&display_server::getDisplay(DisplayServer::getInstance()),_window,name.c_str(),name.c_str(),None,nullptr,0,nullptr);
                XSelectInput(&display_server::getDisplay(DisplayServer::getInstance()), _window, ExposureMask|ButtonPressMask|KeyPressMask);
                XClearWindow(&display_server::getDisplay(DisplayServer::getInstance()), _window);
                XMapWindow(&display_server::getDisplay(DisplayServer::getInstance()), _window);
            }
            virtual ~MainWindow()
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
        inline Window getWindow(const MainWindow<DisplayServer>& controler)
        {
            return controler.getWindow();
        }
        template<class DisplayServer>
        inline void show(const MainWindow<DisplayServer>& controler)
        {
            XMapWindow(&display_server::getDisplay(DisplayServer::getInstance()), controler.getWindow());
        }
        template<class DisplayServer>
        inline void clear(const MainWindow<DisplayServer>& controler)
        {
            XClearWindow(&display_server::getDisplay(DisplayServer::getInstance()), controler.getWindow());
        }
    }
}

#endif