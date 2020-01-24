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
            GraphicContext(DisplayServer& display, const WindowControler& windowContoler) : _display(display)
            {
                _gc = XCreateGC(&display_server::getDisplay(_display), window_controler::getWindow(windowContoler), 0,0);        
                XSetBackground(&display_server::getDisplay(_display),_gc,display_server::getWhitePixel(_display));
                XSetForeground(&display_server::getDisplay(_display),_gc,display_server::getBlackPixel(_display));
            }
            virtual ~GraphicContext()
            {
                XFreeGC(&display_server::getDisplay(_display), _gc);
            }

        private:
            DisplayServer& _display;
            GC _gc;
    };
}

#endif