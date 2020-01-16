#include "unit01.h"
#include "file_utils.h"

namespace {
// Fixed file name.    
const char kFileName[] = "Unit01.txt";
}   // namespace

namespace unit01 {
    
void RunAssignmentOfUnit01() {
    std::string str;
    // Get input from the keyboard.
    // TODO: Handle the case of all contents are white spaces.
    std::cout << "Enter string to write: " << std::endl;
    std::getline(std::cin >> std::ws, str);

    // Write the contents into Unit01.txt
    if (!file_utils::Append(kFileName, str)) {
        std::cout << "File to write file";
        return;
    }
        
    // Read the contents of the file
    std::cout << std::endl << "Contents of file: " << std::endl;
    std::string contents_of_file;
    if (!file_utils::ReadContents(kFileName, &contents_of_file)) {
        std::cout << "Failed to read file.";
        return;
    } else {
        std::cout << contents_of_file << std::endl;
    }
}
    
}   // namespace unit01