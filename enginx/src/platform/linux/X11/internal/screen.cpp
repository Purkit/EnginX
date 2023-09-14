#include <enginx/platform/linux/X11/internal/screen.hpp>
#include <enginx/platform/linux/X11/internal/connect.hpp>

namespace X11_Internal
{
    Screen* X11Screen::defaultScreen = NULL;
    int X11Screen::defaultScreen_ID = {};

    void X11Screen::GetDefaultScreen()
    {
        defaultScreen = DefaultScreenOfDisplay(XConnection::connection);
        defaultScreen_ID = DefaultScreen(XConnection::connection);
    }

    void X11Screen::Release()
    {

    }

    int X11Screen::GetWidth()
    {
        return defaultScreen->width;
    }

    int X11Screen::GetHeight()
    {
        return defaultScreen->height;
    }


}