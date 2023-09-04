#ifndef WIN32_WINDOW_HPP
#define WIN32_WINDOW_HPP

#include <enginx/platform_detection.h>

#ifdef EX_PLATFORM_WINDOWS

#include <enginx/core/window/window.hpp>

#include <Windows.h>
#include <memory>

namespace enginx
{
    class Win32Window : public ExWindow
    {
        public:
            Win32Window(u32 width, u32 height, const std::string& title);
            virtual ~Win32Window();
        
        public:
            void OnUpdate() override;

            void Initialize() override;
            
            void Show() const override;
            void Clear() const override;
            void Close() override;
            
            void SetTitle(const std::string& title) const override;
            void SetIcon(const char* iconFilePath) const override;

            void PumpEvents() override;      // * Non blocking
            void WaitForEvents() override;   // * Blocking

            void MakeContextCurrent() const override;
            void Present() const override;

            void Toggle_FullScreenMode() override;
            void Toggle_BorderlessMode() override;

            bool shouldClose() const override;

            u32 GetWidth() const override;
            u32 GetHeight() const override;
            void GetLocation(int& x, int& y) const override;
        
        private:
            const u32 m_width;
            const u32 m_height;
            std::string m_defaultWindowName;
            bool m_shouldClose = false;

            bool borderless = false;
            bool fullscreen = false;
        
        private:
            HWND m_windowHandle;
            // HICON m_Icon;

            MSG m_message_queue; // * Event Queue
    
        private:
            void _register_window_class();
            void _create_window();

    };

}

#endif // EX_PLATFORM_WINDOWS

#endif // ! end of WIN32_WINDOW_HPP