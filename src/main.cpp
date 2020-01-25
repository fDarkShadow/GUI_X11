#include "display/LocalDisplayServer.hpp"
#include "display/Singleton.hpp"
#include "screen/DefaultScreenControler.hpp"
#include "window/MainWindow.hpp"
#include "Events.hpp"
#include "GraphicContext.hpp"
#include "pixelColor.hpp"
#include "drawer/point.hpp"

#include <functional>

#include <iostream>
#include <chrono>
#include <thread>



int main () {
    using Display = x11::Singleton<x11::LocalDisplayServer>;
    using Screen = x11::DefaultScreenControler<Display>;
    Screen screen;
    x11::MainWindow<Display> window(
        "Window",
        0,
        0,
        300,
        300,
        10,
        x11::pixel_color::getColor(0,255,0),
        x11::pixel_color::getColor(255,0,0)
    );
    x11::Event<Display> event;
    x11::GraphicContext<Display> gc(window, x11::pixel_color::getColor(0,0,0), x11::pixel_color::getColor(0,0,0));

    while(true)
    {
        x11::event::checkEvent(event);
        if (x11::event::getEventType(event) == x11::event::Type::KEY_PRESSED)
        {
            auto c = x11::event::getChar(event);
            if(c == 'q')
            {
                return 1;
            }
            if(c == '\r')
            {
                x11::window_controler::clear(window);
            }
        }

        if (x11::event::getEventType(event) == x11::event::Type::BUTTON_PRESSED)
        {
            /* std::string t("Waouh");
            XSetForeground(
                &x11::display_server::getDisplay(Display::getInstance()),
                gc.getGC(),
                x11::pixel_color::getColor(0,255,0)
            );
            XDrawString(
                &x11::display_server::getDisplay(Display::getInstance()),
                window.getWindow(),
                gc.getGC(),
                x11::event::getXPosition(event),
                x11::event::getYPosition(event),
                t.c_str(),
                t.size()
            ); */
            x11::drawer::drawPoint<Display>(window, gc, std::make_pair(x11::event::getXPosition(event), x11::event::getYPosition(event)), x11::pixel_color::getColor(0,255,0));
        }
    }
    return 0;
}