#include <enginx/utility/logger/logger.hpp>

namespace enginx
{
    std::mutex Logger::logger_mutex;
    LogLevel Logger::current_log_level = LOG_LEVEL_VERBOSE;

    void Logger::setPrirority(LogLevel log_level)
    {
        Logger::current_log_level = log_level;
    }

    void Logger::log_to_console(LogLevel level, const char *fromFile, const char *fromFunction, int atLine, const char *msg, ...)
    {
        std::scoped_lock<std::mutex> lock(logger_mutex);
        if (Logger::current_log_level >= level)
        {
            const char *log_level_tag[] = {"\e[1m\x1B[31m[FATAL]: \e[0m", "\e[1m\x1B[31m[CRITICAL]: \e[0m", "\e[1m\x1B[36m[WARN]: \e[0m", "\e[1m\x1B[33m[DEBUG]: \e[0m", "\e[1m[TRACE]: \e[0m", "\e[1m[INFO]: \e[0m", "\e[1m\x1B[32m[VERBOSE]: \e[0m"};

            char out_msg[1000] = {};

            va_list arg_ptr;
            va_start(arg_ptr, msg);
            vsnprintf(out_msg, 500, msg, arg_ptr);
            va_end(arg_ptr);

            printf("%s", log_level_tag[level]);
            printf("<from %s, function %s, at line %d>", fromFile, fromFunction, atLine);
            printf(" %s", out_msg);
            printf("\n");
        }
    }

    void Logger::log_to_file()
    {
        // TODO : Implement the file handler submodules
    }

}