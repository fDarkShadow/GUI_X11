#ifndef _X11_PIXEL_COLOR_H_
#define _X11_PIXEL_COLOR_H_

namespace x11
{
    namespace pixel_color
    {
        inline unsigned long getColor(unsigned char red, unsigned char green, unsigned char blue)
        {
            unsigned long color = 0;
            color |= (red << 16 & 0xff0000);
            color |= (green << 8 & 0xff00);
            color |= (blue & 0xff);
            return color;
        }
    }
}

#endif