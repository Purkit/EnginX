#ifndef CONNECTION_HPP
#define CONNECTION_HPP


#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>

namespace X11_Internal
{

    class XConnection
    {
        public:
            static Display* connection;

            static void Connect();
            static void Disconnect();             

    };

}

#endif // CONNECTION_HPP