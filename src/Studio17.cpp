#include "../include/mockos/ImageFile.h"
#include <iostream>
#include <vector>

int main() {
    // Test 1: Create an ImageFile instance
    ImageFile myImage("myImage.img");
    std::cout << "Created ImageFile with name: " << myImage.getName() << std::endl;

    // Test 2: Write valid data to the ImageFile
    std::vector<char> validData = { 'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3' };
    int writeResult = myImage.write(validData);
    if (writeResult == 0) {
        std::cout << "Valid write operation successful." << std::endl;
    }
    else {
        std::cout << "Valid write operation failed with error code: " << writeResult << std::endl;
    }

    // Test 3: Read from the ImageFile
    std::cout << "Reading from the image file:" << std::endl;
    myImage.read();

    // Test 4: Attempt to append data (should fail)
    std::vector<char> appendData = { 'X', 'X', 'X' };
    int appendResult = myImage.append(appendData);
    if (appendResult != 0) {
        std::cout << "Append operation failed as expected with error code: " << appendResult << std::endl;
    }
    else {
        std::cout << "Append operation unexpectedly succeeded." << std::endl;
    }

    // Test 5: Write invalid data to the ImageFile
    std::vector<char> invalidData = { 'X', 'Y', 'Z', '2' };
    int invalidWriteResult = myImage.write(invalidData);
    if (invalidWriteResult != 0) {
        std::cout << "Invalid write operation failed as expected with error code: " << invalidWriteResult << std::endl;
    }
    else {
        std::cout << "Invalid write operation unexpectedly succeeded." << std::endl;
    }

    return 0;
}
