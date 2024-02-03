#include "../include/mockos/TextFile.h"
#include "../include/mockos/AbstractFile.h"
#include <iostream>
#include <vector>

int main() {
    // Create an instance of TextFile
    TextFile myTextFile("example.txt");

    // Create a base class alias (pointer) to the TextFile instance
    AbstractFile* filePtr = &myTextFile;

    // Data to be written to the file
    std::vector<char> dataToWrite = { 'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!' };

    // Writing data to the file using the base class alias
    int writeResult = filePtr->write(dataToWrite);
    if (writeResult == 0) {
        std::cout << "Write operation successful." << std::endl;
    }
    else {
        std::cout << "Write operation failed with error code: " << writeResult << std::endl;
    }

    // Reading data from the file using the base class alias
    std::cout << "Reading from the file: " << std::endl;
    filePtr->read();

    // Other tests can be performed in a similar manner using filePtr

    return 0;
}
