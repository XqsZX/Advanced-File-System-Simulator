#ifndef MACROCOMMAND_H
#define MACROCOMMAND_H

#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"
#include <vector>

class MacroCommand : public AbstractCommand {
    std::vector<AbstractCommand*> commands;
    AbstractParsingStrategy* parseStrategy;
    AbstractFileSystem* fileSystem;

public:
    MacroCommand();
    MacroCommand(AbstractFileSystem* fs);
    void setParseStrategy(AbstractParsingStrategy*);
    void addCommand(AbstractCommand*);
    int execute(std::string args) override;
    void displayInfo() override;
};

#endif // MACROCOMMAND_H
