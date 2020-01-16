#include "file_utils.h"

#include <fstream>

namespace file_utils {
    
bool Append(const std::string& file_name,
            const std::string& contents) {
    if (file_name.empty() || contents.empty())
        return false;
    
    // Open fie stream for writting.
    std::fstream fs(file_name, std::ios::out | std::ios::app);
    if (!fs.good())
        return false;
    
    // Append a new line after contents.
    fs << contents << std::endl;
    
    return true;
}

bool ReadContents(const std::string& file_name,
                  std::string* buffer) {
    if (file_name.empty() || !buffer)
        return false;
    
    // Open fie stream for writting.
    std::fstream fs(file_name, std::ios::in);
    if (!fs.good())
        return false;
        
    buffer->clear();
    char ch_to_read;
    while (!fs.eof()) {
        fs.get(ch_to_read);
        *buffer += ch_to_read;
    }
        
    return true;
}

}   // namespace file_utils