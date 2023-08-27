#ifndef EX_ASSERTS_HPP
#define EX_ASSERTS_HPP

#include <stdio.h>

#define exASSERTION_ENABLED

#ifdef exASSERTION_ENABLED

#define debugBreak() __builtin_trap()

namespace assert
{
    void report_assertion_failure(const char* expression, const char* message, const char* fromFile, int atLine);
}


#define PROCED_IF_TRUE(expr)                                         \
    {                                                                \
        if (expr) {                                                  \
        } else {                                                     \
            assert::report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                            \
        }                                                            \
    }


#define exASSERT_MSG(expr, message)                                       \
    {                                                                     \
        if (expr) {                                                       \
        } else {                                                          \
            assert::report_assertion_failure(#expr, message, __FILE__, __LINE__); \
            debugBreak();                                                 \
        }                                                                 \
    }

#define STOP_IF_TRUE(expr, message)                                         \
    {                                                                       \
        if (expr) {                                                         \
            assert::report_assertion_failure(#expr, message, __FILE__, __LINE__);   \
            debugBreak();                                                   \
        }                                                                   \
    }

#ifdef _DEBUG
    #define exASSERT_DEBUG(expr)                                         \
        {                                                                \
            if (expr) {                                                  \
            } else {                                                     \
                assert::report_assertion_failure(#expr, "", __FILE__, __LINE__); \
                debugBreak();                                            \
            }                                                            \
        }
#else
    #define exASSERT_DEBUG(expr)  
#endif  // ! end of _DEBUG

#else // if exASSERTION_ENABLED is not defined

#define exASSERT(expr)               // Does nothing at all
#define exASSERT_MSG(expr, message)  // Does nothing at all
#define exASSERT_DEBUG(expr)         // Does nothing at all

#endif // ! end of exASSERTION_ENABLED

#endif // ! end of EX_ASSERTS_HPP