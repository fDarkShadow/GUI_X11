#ifndef _X11_GRAPHIC_CONTEXT_H_
#define _X11_GRAPHIC_CONTEXT_H_

#include <X11/Xlib.h>

#include <utility>

namespace x11
{
    template<class DisplayServer>
    class GraphicContext
    {
        public:
            template<class WindowControler>
            GraphicContext(
                const WindowControler& windowControler,
                unsigned long backGroundColor,
                unsigned long foreGroundColor
            )
            {
                _gc = XCreateGC(&display_server::getDisplay(DisplayServer::getInstance()), window_controler::getWindow(windowControler), 0,0);        
                XSetBackground(&display_server::getDisplay(DisplayServer::getInstance()),_gc,backGroundColor);
                XSetForeground(&display_server::getDisplay(DisplayServer::getInstance()),_gc,foreGroundColor);
            }
            virtual ~GraphicContext()
            {
                XFreeGC(&display_server::getDisplay(DisplayServer::getInstance()), _gc);
            }

            GC getGC() const
            {
                return _gc;
            }

        private:
            GC _gc;
    };
}

#endif