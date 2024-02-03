#ifndef COPYCOMMAND_H
#define COPYCOMMAND_H

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>

class CopyCommand : public AbstractCommand {
    AbstractFileSystem* fileSystem;

public:
    CopyCommand(AbstractFileSystem* fs);
    int execute(std::string args) override;
    void displayInfo() override;
};

#endif // COPYCOMMAND_H
