#include <enginx/core/window/window.hpp>

#include <enginx/defines.h>
#include <enginx/platform_detection.h>

#include <memory>

namespace enginx
{
    std::unique_ptr<ExWindow> ExWindow::Create(u32 w, u32 h, const std::string& title)
    {
        #ifdef EX_PLATFORM_LINUX
            #if defined(EX_USE_XORG)
                return std::make_unique<X11Window>(w, h, title);
            #elif defined(EX_USE_WAYLAND)
                return std::make_unique<WaylandWindow>(w, h, title);
            #endif
        #endif

        #ifdef EX_PLATFORM_WINDOWS
            return std::make_unique<Win32Window>(w, h, title);
        #endif

        #ifdef EX_PLATFORM_APPLE
            return std::make_unique<CocoaWindow>(w, h, title);
        #endif
    }
            
}