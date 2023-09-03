#include <enginx/core/file_handler/file_handler.hpp>
#include <enginx/utility/assert/asserts.hpp>
#include <enginx/utility/logger/logger.hpp>

#include <unistd.h>
#include <sys/stat.h>

namespace enginx
{
    bool FileUtils::DoesFileExists(const char* file_path)
    {
        if (access(file_path, F_OK) != -1)
            return true;
        else
            return false;
    }

    u64 FileUtils::GetFileSize(const char* file_path)
    {   
        if ( DoesFileExists(file_path) != true)
            return -1; // ! RETURN -1 IF FILE DOES NOT EXISTS
        
        struct stat file_info;
        stat(file_path, &file_info);

        return (u64)file_info.st_size;
    }

    bool FileUtils::Create(File file_struct_object, long flags_mask)
    {
        const char* mode_str;
        if (flags_mask == (long)FILE_ACCESS_FLAGS::WRITE_ONLY)
            mode_str = "w";
        if (flags_mask == (long)FILE_ACCESS_FLAGS::WRITE_ONLY | (long)FILE_HANDELING_FLAGS::NO_OVERWRITE_IF_ALREADY_EXISTS)
            mode_str = "wx";
        if ( (flags_mask == (long)FILE_ACCESS_FLAGS::READ_AND_WRITE) || (flags_mask == (long)FILE_ACCESS_FLAGS::READ_AND_WRITE | (long)FILE_HANDELING_FLAGS::NEW_EMPTY_FILE) || (flags_mask == (long)FILE_ACCESS_FLAGS::READ_AND_WRITE | (long)FILE_HANDELING_FLAGS::OVERWRITE_IF_ALREADY_EXISTS))
            mode_str = "w+";
        if ( (flags_mask == (long)FILE_ACCESS_FLAGS::READ_AND_WRITE | (long)FILE_HANDELING_FLAGS::NO_OVERWRITE) )
            mode_str = "w+x";
        

        file_struct_object.handle = fopen(file_struct_object.file_path, mode_str);
        if ( !file_struct_object.handle )
        {
            file_struct_object.handle = nullptr;
            return false;
        }

        return true;        
    }

    bool FileUtils::Open(File file_struct_object, long flags_mask)
    {
        const char* mode_str;

        int isBinaryModeEnabled = (flags_mask & (1 << 5)) != 0;
        int isNoOverwriteModeEnabled = (flags_mask & (1 << 7)) != 0;

        using enum FILE_ACCESS_FLAGS;
        if ( (flags_mask == (long)READ_ONLY) )
            mode_str = isBinaryModeEnabled ? "rb" : "r";
        if (flags_mask == (long)WRITE_ONLY)
            mode_str = (isNoOverwriteModeEnabled ? (isBinaryModeEnabled ? "wbx" : "wx") : (isBinaryModeEnabled ? "wb" : "w"));
        if ( flags_mask == (long)READ_AND_WRITE )
            mode_str = "r+";
        if ( flags_mask == (long)APPEND_ONLY )
            mode_str = "a";
        if ( flags_mask == (long)READ_AND_APPEND )
            mode_str = "a+";
        
        file_struct_object.handle = fopen(file_struct_object.file_path, mode_str);
        if ( !file_struct_object.handle )
        {
            file_struct_object.handle = nullptr;
            return false;
        }

        return true;
    }

    bool FileUtils::Close(File file_struct_object)
    {
        if ( file_struct_object.handle == nullptr )
        {
            // The given file is already closed
            // or never been opened at all.
            return false;
        }

        fclose(file_struct_object.handle);
        file_struct_object.handle = nullptr;
        return true;
    }

    bool FileUtils::Delete(File file_struct_object)
    {
        if ( remove(file_struct_object.file_path) == 0 )
        {
            return true;
        }
        else
            return false;
    }

    bool FileUtils::Delete(const char* file_path)
    {
        if (remove(file_path) == 0)
            return true;
        else
            return false;
    }

    bool FileUtils::Write(File file_struct_object, const char& msg)
    {
        if (file_struct_object.handle == nullptr)
            return false;
        
        fprintf(file_struct_object.handle, &msg);
    }

    bool FileUtils::Read(File file_struct_object, char **output_content)
    {
        /*
            ----How to use ?----
                char *file_content = NULL;
                if ( FileUtils::Read(file_obj, &file_content) )
                {
                    printf("File content:\n%s\n", file_content);
                    free(file_content); // Free allocated memory
                }
                else
                {
                    printf("Failed to read file content.\n");
                }
        */


        // Determine the file size
        fseek(file_struct_object.handle, 0, SEEK_END);
        long file_size = ftell(file_struct_object.handle);
        fseek(file_struct_object.handle, 0, SEEK_SET);

        // Allocate memory to hold the file content
        *output_content = (char *)malloc(file_size + 1); // +1 for the null terminator

        if (*output_content == NULL)
        {
            FATAL("FAILED TO ALLOCATE MEMORY.");
            return false;
        }

        // Read the entire content of the file
        fread(*output_content, 1, file_size, file_struct_object.handle);
        (*output_content)[file_size] = '\0'; // Null-terminate the string

        return true;
    }

}