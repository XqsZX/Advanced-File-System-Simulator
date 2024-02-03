#include "../../include/mockos/TextFile.h"
#include <iostream>

TextFile::TextFile(const std::string& fileName) : name(fileName) {}

//void TextFile::read() {
//    for (char c : content) {
//        std::cout << c;
//    }
//    std::cout << std::endl;
//}

std::vector<char> TextFile::read() const {
    return content;
}

int TextFile::write(const std::vector<char>& data) {
    content = data;
    return 0; // Indicating successful write
}

int TextFile::append(const std::vector<char>& data) {
    content.insert(content.end(), data.begin(), data.end());
    return 0; // Indicating successful append
}

unsigned int TextFile::getSize() const {
    return content.size();
}

std::string TextFile::getName() const {
    return name;
}

void TextFile::accept(AbstractFileVisitor* visitor) {
    visitor->visit_TextFile(this);
}

AbstractFile* TextFile::clone(std::string newFileName) {
    TextFile* copy = new TextFile(newFileName);
    copy->content = this->content;
    return copy;
}