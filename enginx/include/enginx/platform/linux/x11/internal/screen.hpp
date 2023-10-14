#ifndef X11_SCREEN_INTERNAL_HPP
#define X11_SCREEN_INTERNAL_HPP

#include <X11/Xlib.h>

namespace X11_Internal
{

    class X11Screen
    {
        public:
            static Screen* defaultScreen;
            static int defaultScreen_ID;
    
        public:
            static void GetDefaultScreen();
            static void Release();

        public:
            int GetWidth();
            int GetHeight();

    };

}

#endif // X11_SCREEN_INTERNAL_HPP
