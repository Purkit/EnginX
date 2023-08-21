#include <stdio.h>

namespace assert
{
    void report_assertion_failure(const char* expression, const char* message, const char* fromFile, int atLine)
    {
        printf("[ASSERT FAILED]: Expression: %s <%s>, from file: %s at line %d\n", expression, message, fromFile, atLine);
    }
}