#ifndef _X11_DISPLAY_SINGLETON_H_
#define _X11_DISPLAY_SINGLETON_H_

namespace x11
{
    template<class Display>
    class Singleton
    {
        public:
            static Display& getInstance()
            {
                static Display instance;
                return instance;
            }
        private:
            Singleton() {}

        public:
            Singleton(Singleton const&) = delete;
            void operator=(Singleton const&) = delete;
    };
}

#endif