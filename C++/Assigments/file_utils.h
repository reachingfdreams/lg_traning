#ifndef ASSIGNMENT_FILE_UTILS_H_
#define ASSIGNMENT_FILE_UTILS_H_

#include <iostream>
#include <string>

namespace file_utils {
    
bool Append(const std::string& file_name,
            const std::string& contents);
bool ReadContents(const std::string& file_name,
                  std::string* buffer);
                      
}   // namespace file_utils

#endif  // ASSIGNMENT_FILE_UTILS_H_