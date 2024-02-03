#include "../../include//mockos/ImageFile.h"
#include <iostream>

ImageFile::ImageFile(const std::string& fileName) : name(fileName), size(0) {}

//void ImageFile::read() {
//    for (int y = 0; y < size; ++y) {
//        for (int x = 0; x < size; ++x) {
//            std::cout << content[y * size + x];
//        }
//        std::cout << std::endl;
//    }
//}

std::vector<char> ImageFile::read() const {
    return content;
}

int ImageFile::write(const std::vector<char>& data) {
    // Last char is the size
    char newSize = data.back() - '0';
    if (newSize * newSize != data.size() - 1) {
        content.clear();
        size = 0;
        return 1;
    }

    // Validate the pixels
    for (size_t i = 0; i < data.size() - 1; ++i) {
        if (data[i] != 'X' && data[i] != ' ') {
            content.clear();
            size = 0;
            return 1;
        }
    }

    // Set size and copy content
    size = newSize;
    content.assign(data.begin(), data.end() - 1);
    return 0;
}

int ImageFile::append(const std::vector<char>& data) {
    return 2; 
}

unsigned int ImageFile::getSize() const {
    return content.size();
}

std::string ImageFile::getName() const {
    return name;
}

void ImageFile::accept(AbstractFileVisitor* visitor) {
    visitor->visit_ImageFile(this);
}

AbstractFile* ImageFile::clone(std::string newFileName) {
    ImageFile* copy = new ImageFile(newFileName);
    copy->content = this->content;
    return copy;
}