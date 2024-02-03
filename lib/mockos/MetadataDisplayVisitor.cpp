#include "../../include/mockos/MetadataDisplayVisitor.h"
#include "../../include/mockos/TextFile.h"
#include "../../include/mockos/ImageFile.h"
#include <iostream>

void MetadataDisplayVisitor::visit_TextFile(TextFile* file) {
    std::cout << file->getName() << " ";
    std::cout << "text" << " ";
    std::cout << file->getSize() << std::endl;
}

void MetadataDisplayVisitor::visit_ImageFile(ImageFile* file) {
    std::cout << file->getName() << " ";
    std::cout << "image" << " ";
    std::cout << file->getSize() << std::endl;
}
