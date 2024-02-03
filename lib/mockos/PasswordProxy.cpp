#include "../../include/mockos/PasswordProxy.h"
#include <iostream>

PasswordProxy::PasswordProxy(AbstractFile* file, const std::string& pwd)
    : realFile(file), password(pwd) {}

PasswordProxy::~PasswordProxy() {
    delete realFile;
}

std::string PasswordProxy::passwordPrompt() const {
    std::string input;
    std::cout << "Enter password: ";
    std::cin >> input;
    return input;
}

bool PasswordProxy::checkPassword(const std::string& input) const {
    return input == password;
}

std::vector<char> PasswordProxy::read() const {
    if (checkPassword(passwordPrompt())) {
        return realFile->read();
    }
    return std::vector<char>();
}

int PasswordProxy::write(const std::vector<char>& v) {
    if (checkPassword(passwordPrompt())) {
        return realFile->write(v);
    }
    return -1;
}

int PasswordProxy::append(const std::vector<char>& v) {
    if (checkPassword(passwordPrompt())) {
        return realFile->append(v);
    }
    return -1;
}

unsigned int PasswordProxy::getSize() const {
    return realFile->getSize();
}

std::string PasswordProxy::getName() const {
    return realFile->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* visitor) {
    if (checkPassword(passwordPrompt())) {
        realFile->accept(visitor);
    }
}

AbstractFile* PasswordProxy::clone(std::string newFileName) {
    AbstractFile* fileCopy = realFile->clone(newFileName);
    return new PasswordProxy(fileCopy, password);
}