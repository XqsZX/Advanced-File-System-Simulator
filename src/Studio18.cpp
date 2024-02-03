#include "../include/mockos/SimpleFileSystem.h"
#include "../include/mockos/SimpleFileFactory.h"
#include "../include/mockos/TextFile.h"
#include "../include/mockos/ImageFile.h"
#include <iostream>

int main() {
    // Initialize file system and file factory
    AbstractFileSystem* fs = new SimpleFileSystem();
    AbstractFileFactory* ff = new SimpleFileFactory();

    // Create a text file
    AbstractFile* file1 = ff->createFile("test.txt");
    if (file1) {
        fs->addFile("test.txt", file1);
    }

    // Create an image file
    AbstractFile* file2 = ff->createFile("image.img");
    if (file2) {
        fs->addFile("image.img", file2);
    }

    // Open, write to, and read from the text file
    AbstractFile* openedFile1 = fs->openFile("test.txt");
    if (openedFile1) {
        std::vector<char> content = { 'H', 'e', 'l', 'l', 'o' };
        openedFile1->write(content);
        openedFile1->read();
        fs->closeFile(openedFile1);
    }

    // Attempt to open and read the image file
    AbstractFile* openedFile2 = fs->openFile("image.img");
    if (openedFile2) {
        openedFile2->read();
        fs->closeFile(openedFile2);
    }

    // Clean up
    delete fs;
    delete ff;

    return 0;
}
