#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <enginx/defines.h>

#include <string>
#include <memory>
#include <functional>


namespace enginx
{

    // ** EnginX Window Interface
    class EXAPI ExWindow
    {
        public:
            virtual ~ExWindow() = default;

            virtual void OnUpdate() = 0;

            virtual void Initialize() = 0;            
            virtual void Show() const = 0;
            virtual void Clear() const = 0;
            virtual void Close() = 0;

            virtual void SetTitle(const std::string& title) const = 0;
            virtual void SetIcon(const char* iconFilePath) const = 0;

            virtual void PumpEvents() = 0;      // * Non blocking
            virtual void WaitForEvents() = 0;   // * Blocking

            virtual void MakeContextCurrent() const = 0;
            virtual void Present() const = 0;

            virtual void Toggle_FullScreenMode() = 0;
            virtual void Toggle_BorderlessMode() = 0;

            virtual bool shouldClose() const = 0;

            virtual u32 GetWidth() const = 0;
            virtual u32 GetHeight() const = 0;
            virtual void GetLocation(int& x, int& y) const = 0;

            static std::unique_ptr<ExWindow> Create(u32 w, u32 h, const std::string& title);
    };

}

#endif // ! WINDOW_HPP