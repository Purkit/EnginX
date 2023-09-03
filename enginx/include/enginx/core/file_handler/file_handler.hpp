#ifndef FILE_HANDLER_HPP
#define FILE_HANDLER_HPP

#include <enginx/defines.h>

#include <stdlib.h>
#include <string>


// TODO : For now I'm going with a generic
// TODO : universal implementation of file
// TODO : handleing methods. Later implement
// TODO : the platform specific file handleing
// TODO : methods for getting optimized result.


namespace enginx
{
    enum class FILE_ACCESS_FLAGS : long
    {
        READ_ONLY       = 00000001,
        WRITE_ONLY      = 00000010,
        READ_AND_WRITE  = 00000100,
        APPEND_ONLY     = 00001000,
        READ_AND_APPEND = 00010000,
        BINARY_MODE     = 00100000
    };

    enum class FILE_HANDELING_FLAGS : long
    {
        NEW_EMPTY_FILE = 01000000,
        NO_OVERWRITE = 10000000,
        NO_OVERWRITE_IF_ALREADY_EXISTS = 10000000,
        OVERWRITE_IF_ALREADY_EXISTS = 01000000
    };

    struct File
    {
        const char* file_path;
        FILE* handle;
    };

    class EXAPI FileUtils
    {
        public:
            static bool Create(File file_struct_object, long flags_mask);
            static bool Open(File file_struct_object, long flags_mask);
            static bool Close(File file_struct_object);
            static bool Delete(File file_struct_object);
            static bool Delete(const char* file_path);
            static bool Write(File file_struct_object, const char& msg);
            static bool Read(File file_struct_object, char **output_content);
        
        public:
            static bool DoesFileExists(const char* file_path);
            static u64 GetFileSize(const char* file_path);

    };



}

#endif // ! FILE_HANDLER_HPP