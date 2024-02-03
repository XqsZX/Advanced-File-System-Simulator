#ifndef ABSTRACTFILE_H
#define ABSTRACTFILE_H

#include "AbstractFileVisitor.h"
#include <string>
#include <vector>

class AbstractFile {
public:
    virtual std::vector<char> read() const = 0;
    virtual int write(const std::vector<char>& data) = 0;
    virtual int append(const std::vector<char>& data) = 0;
    virtual unsigned int getSize() const = 0;
    virtual std::string getName() const = 0;
    virtual void accept(AbstractFileVisitor* visitor) = 0;
    virtual AbstractFile* clone(std::string newFileName) = 0;

    virtual ~AbstractFile() {}
};

#endif // ABSTRACTFILE_H
