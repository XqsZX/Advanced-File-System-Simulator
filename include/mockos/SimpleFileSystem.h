#ifndef SIMPLEFILESYSTEM_H
#define SIMPLEFILESYSTEM_H

#include "AbstractFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <map>
#include <set>
#include <string>

class SimpleFileSystem : public AbstractFileSystem {
private:
    std::map<std::string, AbstractFile*> files;
    std::set<AbstractFile*> openFiles;

public:
    int addFile(const std::string& filename, AbstractFile* file) override;
    // int createFile(const std::string& filename) override;
    int deleteFile(const std::string& filename) override;
    AbstractFile* openFile(const std::string& filename) override;
    int closeFile(AbstractFile* file) override;
    std::set<std::string> getFileNames() override;
};

#endif // SIMPLEFILESYSTEM_H
