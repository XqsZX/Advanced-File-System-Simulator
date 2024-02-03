#ifndef CATCOMMAND_H
#define CATCOMMAND_H

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include <string>

class CatCommand : public AbstractCommand {
    AbstractFileSystem* fileSystem;

public:
    CatCommand(AbstractFileSystem* fs);
    int execute(std::string args) override;
    void displayInfo() override;
};

#endif // CATCOMMAND_H
