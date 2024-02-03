#ifndef TOUCHCOMMAND_H
#define TOUCHCOMMAND_H

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "PasswordProxy.h"

#include <iostream>
#include <sstream>

class TouchCommand : public AbstractCommand {
    AbstractFileSystem* fileSystem;
    AbstractFileFactory* fileFactory;

public:
    TouchCommand(AbstractFileSystem* fs, AbstractFileFactory* ff);
    void displayInfo() override;
    int execute(std::string filename) override;
};

#endif // TOUCHCOMMAND_H
