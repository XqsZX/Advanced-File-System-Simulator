#ifndef REMOVECOMMAND_H
#define REMOVECOMMAND_H

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class RemoveCommand : public AbstractCommand {
    AbstractFileSystem* fileSystem;

public:
    RemoveCommand(AbstractFileSystem* fs);
    int execute(std::string filename) override;
    void displayInfo() override;
};

#endif // REMOVECOMMAND_H
