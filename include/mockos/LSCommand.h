#ifndef LSCOMMAND_H
#define LSCOMMAND_H

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "MetadataDisplayVisitor.h"

class LSCommand : public AbstractCommand {
    AbstractFileSystem* fileSystem;

public:
    LSCommand(AbstractFileSystem* fs);
    int execute(std::string args) override;
    void displayInfo() override;
};

#endif // LSCOMMAND_H
