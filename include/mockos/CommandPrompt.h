#ifndef COMMANDPROMPT_H
#define COMMANDPROMPT_H

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <map>
#include <string>
#include <sstream>

class CommandPrompt {
private:
    std::map<std::string, AbstractCommand*> commands;
    AbstractFileSystem* fileSystem;
    AbstractFileFactory* fileFactory;

protected:
    void listCommands() const;
    std::string prompt() const;

public:
    CommandPrompt();
    void setFileSystem(AbstractFileSystem*);
    void setFileFactory(AbstractFileFactory*);
    int addCommand(const std::string&, AbstractCommand*);
    int run();
};

#endif // COMMANDPROMPT_H

