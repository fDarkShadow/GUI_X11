#ifndef _X11_DISPLAY_SERVER_H_
#define _X11_DISPLAY_SERVER_H_

#include <X11/Xlib.h>
#include <string>

namespace x11
{
    class LocalDisplayServer
    {
        public:
            LocalDisplayServer()
            {
                std::string displayName = ":0.0";
                _display = XOpenDisplay(displayName.c_str());
                if(_display == nullptr)
                {
                    throw; //TODO : correct exception
                }
            }
            virtual ~LocalDisplayServer()
            {
                XCloseDisplay(_display);
            }

            Display& getDisplay()
            {
                return *_display;
            }

        private:
            Display* _display;
    };
    namespace display_server
    {
        inline Display& getDisplay(LocalDisplayServer& display)
        {
            return display.getDisplay();
        }
    }
}

#endif