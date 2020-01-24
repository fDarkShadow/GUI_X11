#include "DisplayServer.hpp"
#include "WindowControler.hpp"
#include "GraphicContext.hpp"

#include <functional>

#include <iostream>
#include <chrono>
#include <thread>



int main () {
    // XEvent event;		/* the XEvent declaration !!! */
    // KeySym key;		/* a dealie-bob to handle KeyPress Events */	
    // char text[255];		/* a char buffer for KeyPress Events */

    // init_x();

    // /* look for events forever... */
    // while(1) {		
    // 	/* get the next event and stuff it into our event variable.
    // 	   Note:  only events we set the mask for are detected!
    // 	*/
    // 	XNextEvent(dis, &event);
    
    // 	if (event.type==Expose && event.xexpose.count==0) {
    // 	/* the window was exposed redraw it! */
    // 		redraw();
    // 	}
    // 	if (event.type==KeyPress&&
    // 	    XLookupString(&event.xkey,text,255,&key,0)==1) {
    // 	/* use the XLookupString routine to convert the invent
    // 	   KeyPress data into regular text.  Weird but necessary...
    // 	*/
    // 		if (text[0]=='q') {
    // 			close_x();
    // 		}
    // 		printf("You pressed the %c key!\n",text[0]);
    // 	}
    // 	if (event.type==ButtonPress) {
    // 	/* tell where the mouse Button was Pressed */
    // 		int x=event.xbutton.x,
    // 		    y=event.xbutton.y;

    // 		strcpy(text,"X is FUN!");
    // 		XSetForeground(dis,gc,rand()%event.xbutton.x%255);
    // 		XDrawString(dis,win,gc,x,y, text, strlen(text));
    // 	}
    // }

    x11::DisplayServer display{};
    x11::WindowControler<x11::DisplayServer> window(display);
    x11::GraphicContext<x11::DisplayServer> gc(display, window);
    XEvent event;
    KeySym key;
    char text[255];
    while(true)
    {
        XNextEvent(&display.getDisplay(), &event);
        if (event.type==KeyPress && XLookupString(&event.xkey,text,255,&key,0)==1)
        {
            if (text[0]=='q') {
                return 1;
            }
        }
    }
    return 0;
}