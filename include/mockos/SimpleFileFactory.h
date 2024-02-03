#ifndef SIMPLEFILEFACTORY_H
#define SIMPLEFILEFACTORY_H

#include "AbstractFileFactory.h"

class SimpleFileFactory : public AbstractFileFactory {
public:
    AbstractFile* createFile(const std::string& filename) override;
};

#endif // SIMPLEFILEFACTORY_H
