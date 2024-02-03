# Studio 18
1. Xin Zhao(xin.zhao1@wustl.edu), Yifan Chen(chenyifan@wustl.edu)

2. While the factory method pattern provides an elegant solution to creating objects, 
   the direct dependency on concrete classes can be problematic. 
   It requires updates to each file system class when new file types are added, which is not ideal. 
   Introducing a separate factory class that handles object creation would be a more robust and extensible solution.

3. Advantages: Separation of Concerns, Encapsulation of Object Creation, Consistency Among Products, Extensibility
   Disadvantages: Difficult Refactoring, Complexity.

   A new concrete file factory class is warranted when there is a need to create a different family of file types or when the object creation logic significantly differs from existing factories.

   If a new file type is introduced, the concrete factory classes need to be modified to handle the creation of the new file type. This could mean adding a new method or modifying an existing method to account for the new type.

   If two file system implementations manage the same types of files, the same concrete factory can be used to create files for both. This is because the factory is concerned with object creation, not object management.

   A concrete factory implementation could be designed to be flexible and capable of creating different types of files based on input parameters.

4. Test Code:
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

Output: 
Hello

5. The SimpleFileSystem class no longer has a dependency on concrete file types. 
   It now depends solely on the AbstractFile interface.