#include "../../include/mockos/BasicDisplayVisitor.h"
#include <iostream>

void BasicDisplayVisitor::visit_TextFile(TextFile* file) {
    std::vector<char> content = file->read();
    for (char c : content) {
        std::cout << c;
    }
    std::cout << std::endl;
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile* file) {
    std::vector<char> content = file->read();
    int dimensions = static_cast<int>(sqrt(content.size()));
    for (int i = 0; i < dimensions; ++i) {
        for (int j = 0; j < dimensions; ++j) {
            std::cout << content[i * dimensions + j];
        }
        std::cout << std::endl;
    }
}
