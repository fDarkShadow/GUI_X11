#ifndef _X11_EVENTS_HPP_
#define _X11_EVENTS_HPP_

#include <X11/X.h>
#include <X11/Xlib.h>

namespace x11
{
    template<class DisplayServer>
    class Event
    {
        public:
            XEvent& getEvent()
            {
                return event;
            }

            KeySym& getKey()
            {
                return key;
            }

        private:
            XEvent event;
            KeySym key;
    };

    namespace event
    {
        enum class Type
        {
            NONE,
            KEY_PRESSED,
            KEY_RELEASED,
            BUTTON_PRESSED,
            BUTTON_RELEASED,
            EXPOSED
        };
        
        template<class DisplayServer>
        inline void checkEvent(Event<DisplayServer>& e)
        {
            XNextEvent(&display_server::getDisplay(DisplayServer::getInstance()), &e.getEvent());
        }

        template<class DisplayServer>
        inline Type getEventType(Event<DisplayServer>& e)
        {
            switch(e.getEvent().type)
            {
                case ButtonPress : return Type::BUTTON_PRESSED;
                case ButtonRelease : return Type::BUTTON_RELEASED;
                case KeyPress : return Type::KEY_PRESSED;
                case KeyRelease : return Type::KEY_RELEASED;
                case Expose : return Type::EXPOSED;
                default : return Type::NONE;
            };
        }

        template<class DisplayServer>
        inline int getXPosition(Event<DisplayServer>& e)
        {
            return e.getEvent().xbutton.x;
        }
        template<class DisplayServer>
        inline int getYPosition(Event<DisplayServer>& e)
        {
            return e.getEvent().xbutton.y;
        }

        template<class DisplayServer>
        inline char getChar(Event<DisplayServer>& e)
        {
            char c;
            if(XLookupString(&e.getEvent().xkey,&c,1,&e.getKey(),nullptr) == 1)
            {
                return c;
            }
            return '\0';
        }
    }
}

#endif