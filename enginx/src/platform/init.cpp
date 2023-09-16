#include <enginx/platform/init.hpp>
#include <enginx/platform_detection.h>

#if defined(EX_PLATFORM_LINUX)
#include <enginx/platform/linux/X11/internal/connect.hpp>
#include <enginx/platform/linux/X11/internal/screen.hpp>
#endif

namespace enginx
{
    void Platform::StartUp()
    {
        #if defined(EX_PLATFORM_WINDOWS)
            // * Windows stuff
        #elif defined(EX_PLATFORM_LINUX)
            X11_Internal::XConnection::Connect();
            X11_Internal::X11Screen::GetDefaultScreen();
        #elif defined(EX_PLATFORM_ANDROID)
            // * Android stuff
        #elif defined(EX_PLATFORM_APPLE)
            // * Apple stuff
        #endif
    }

    void Platform::Shutdown()
    {
        #if defined(EX_PLATFORM_WINDOWS)
            // * Windows stuff
        #elif defined(EX_PLATFORM_LINUX)
            X11_Internal::XConnection::Disconnect();
        #elif defined(EX_PLATFORM_ANDROID)
            // * Android stuff
        #elif defined(EX_PLATFORM_APPLE)
            // * Apple stuff
        #endif

    }
}