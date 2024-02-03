#include "../include/mockos/TextFile.h"
#include "../include/mockos/PasswordProxy.h"
#include "../include/mockos/BasicDisplayVisitor.h"
#include <iostream>
#include <vector>

int main() {
    // Dynamically allocate a TextFile
    AbstractFile* myFile = new TextFile("example.txt");

    // Create a PasswordProxy for the file
    std::string password = "secret";
    AbstractFile* proxy = new PasswordProxy(myFile, password);

    // Create a BasicDisplayVisitor for testing display functionality
    BasicDisplayVisitor displayVisitor;

    // Test 1: Attempt to read the file through the proxy (without correct password)
    std::vector<char> content = proxy->read();
    if (content.empty()) {
        std::cout << "Read test (without password) passed: Access denied" << std::endl;
    }

    // Test 2: Attempt to write to the file through the proxy (with correct password)
    std::cout << "Enter password for writing: ";
    int writeResult = proxy->write({ 'H', 'e', 'l', 'l', 'o' });
    if (writeResult == 0) {
        std::cout << "Write test (with password) passed: Write successful" << std::endl;
    }

    // Test 3: Display the file through the proxy (with correct password)
    proxy->accept(&displayVisitor);

    // Clean up
    delete proxy;

    return 0;
}
