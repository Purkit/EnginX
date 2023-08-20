#ifndef DEFINES_H
#define DEFINES_H

#include <cstdint>

// ** PLATFORM  DETECTION  **

// Windows Platform :
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
    #define EX_PLATFORM_WINDOWS 1
    #ifndef _WIN64
        #error "64-bit is required on Windows!"
    #endif
// Linux Platform :
#elif defined(__linux__) || defined(__gnu_linux__)
    #define EX_PLATFORM_LINUX 1
    #if defined(__ANDROID__)
        #define EX_PLATFORM_ANDROID 1
    #endif
// Unix Platform :
#elif defined(__unix__)
    // Catch anything not caught by the above.
    #define EX_PLATFORM_UNIX 1
// Posix :
#elif defined(_POSIX_VERSION)
    #define EX_PLATFORM_POSIX 1
// Apple Platforms :
#elif __APPLE__
    #define EX_PLATFORM_APPLE 1
    #include <TargetConditionals.h>
    
    #if TARGET_IPHONE_SIMULATOR
        // iOS Simulator
        #define EX_PLATFORM_IOS 1
        #define EX_PLATFORM_IOS_SIMULATOR 1
    #elif TARGET_OS_IPHONE
        // iOS device
        #define EX_PLATFORM_IOS 1
    #elif TARGET_OS_MAC
        // Other kinds of Mac OS
    #else
        #error "Unknown Apple platform"
    #endif
#else
    #error "Unknown platform!"
#endif


// ** Unsigned Integer Types:
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

// ** Signed Integer Types:
typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

// ** Floating Point Types:
typedef float f32;
typedef double f64;

#define EXAPI __attribute__((visibility("default")))


#endif // DEFINES_H