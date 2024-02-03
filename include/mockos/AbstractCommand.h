#ifndef ABSTRACTCOMMAND_H
#define ABSTRACTCOMMAND_H

#include <string>

class AbstractCommand {
public:
    virtual ~AbstractCommand() = default;
    virtual int execute(std::string) = 0;
    virtual void displayInfo() = 0;
};

#endif // ABSTRACTCOMMAND_H
