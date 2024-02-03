#ifndef DISPLAYCOMMAND_H
#define DISPLAYCOMMAND_H

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFile.h"
#include "MetadataDisplayVisitor.h"
#include <string>

class DisplayCommand : public AbstractCommand {
    AbstractFileSystem* fileSystem;

public:
    DisplayCommand(AbstractFileSystem* fs);
    int execute(std::string args) override;
    void displayInfo() override;
};

#endif // DISPLAYCOMMAND_H
