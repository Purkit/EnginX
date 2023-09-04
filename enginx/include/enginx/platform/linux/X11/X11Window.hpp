#ifndef X11_WINDOW_HPP
#define X11_WINDOW_HPP

#include <enginx/core/window/window.hpp>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/keysymdef.h>


namespace enginx
{

    class X11Window : public ExWindow
    {
        public:
            X11Window(u32 width, u32 height, const std::string& title);
            virtual ~X11Window();
        
        public:
            void OnUpdate() override;

            void Initialize() override;
            
            void Show() const override;
            void Clear() const override;
            void SetTitle(const std::string& title) const override;
            void Close() override;

            void PumpEvents() override;      // * Non blocking
            void WaitForEvents() override;   // * Blocking

            void MakeContextCurrent() const override;
            void Present() const override;

            void Toggle_FullScreenMode() override;
            void Toggle_BorderlessMode() override;

            bool shouldClose() const override;

            u32 GetWidth() const override;
            u32 GetHeight() const override;
            void GetLocation(int& xpos, int& ypos) const override;
        
        private:
            u32 m_width;
            u32 m_height;
            std::string m_defaultWindowName;
            bool m_shouldClose = false;

            bool borderless = false;
            bool fullscreen = false;
        
        private:
            Window m_window;
            XEvent m_event_q;
            KeySym keysym = 0;
        
        private:
            void CreateWindow();   
            void postWindowCreation();

            void handle_event();
        
        private:
            Atom atomWMDeleteWindow;
            Atom motifWMHints;
            Atom wmState;
            Atom wmStateFullScreen;        
    };


}

#endif // ! end of X11_WINDOW_HPP