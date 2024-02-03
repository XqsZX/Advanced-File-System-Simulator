#include "../include/mockos/BasicDisplayVisitor.h"
#include "../include/mockos/SimpleFileFactory.h"
#include "../include/mockos/SimpleFileSystem.h"
#include "../include/mockos/MetadataDisplayVisitor.h"

int main() {
    SimpleFileFactory fileFactory;
    SimpleFileSystem fileSystem;

    AbstractFile* txtFile = fileFactory.createFile("file.txt");
    AbstractFile* imgFile = fileFactory.createFile("image.img");

    fileSystem.addFile("file.txt", txtFile);
    fileSystem.addFile("image.img", imgFile);

    BasicDisplayVisitor displayVisitor;

    txtFile->accept(&displayVisitor);
    imgFile->accept(&displayVisitor);

    MetadataDisplayVisitor metadataVisitor;

    txtFile->accept(&metadataVisitor); // Displays the metadata of the text file
    imgFile->accept(&metadataVisitor);

    return 0;
}
