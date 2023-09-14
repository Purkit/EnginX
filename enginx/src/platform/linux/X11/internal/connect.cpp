#include <enginx/platform/linux/X11/internal/connect.hpp>
#include <enginx/utility/assert/asserts.hpp>
#include <enginx/utility/logger/logger.hpp>

namespace X11_Internal
{
    Display* XConnection::connection = nullptr;

    void XConnection::Connect()
    {
        VERBOSE("Connecting to X Server...");
        connection = XOpenDisplay(nullptr);
        STOP_IF_TRUE(connection == nullptr, "Failed to connect to X Server.");    
    }

    void XConnection::Disconnect()
    {
        if (connection != nullptr)
            XCloseDisplay(connection);
        VERBOSE("Disconnected to X Server.");
    }

}