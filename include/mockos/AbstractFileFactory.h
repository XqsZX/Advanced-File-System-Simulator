#ifndef ABSTRACTFILEFACTORY_H
#define ABSTRACTFILEFACTORY_H

#include "AbstractFile.h"
#include <string>

class AbstractFileFactory {
public:
    virtual ~AbstractFileFactory() {}
    virtual AbstractFile* createFile(const std::string& filename) = 0;
};

#endif // ABSTRACTFILEFACTORY_H
