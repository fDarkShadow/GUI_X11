#ifndef _X11_DRAWER_POINT_HPP_
#define _X11_DRAWER_POINT_HPP_

#include <X11/Xlib.h>

namespace x11
{
    namespace drawer
    {
        template<class DisplayServer, class DrawableControler, class GraphicContext>
        inline void drawPoint(
            const DrawableControler& drawableControler,
            const GraphicContext& graphicContext,
            std::pair<int, int> xyPosition,
            const unsigned long color
        )
        {
            XSetForeground(
                &x11::display_server::getDisplay(DisplayServer::getInstance()),
                x11::graphic_context::getContext(graphicContext),
                color
            );
            XDrawPoint(
                &x11::display_server::getDisplay(DisplayServer::getInstance()),
                x11::window_controler::getWindow(drawableControler),
                x11::graphic_context::getContext(graphicContext),
                xyPosition.first,
                xyPosition.second
            );
        }
    }
}

#endif