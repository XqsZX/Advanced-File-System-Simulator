#ifndef RENAMEPARSINGSTRATEGY_H
#define RENAMEPARSINGSTRATEGY_H

#include "AbstractParsingStrategy.h"
#include <vector>
#include <string>

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
    std::vector<std::string> parse(std::string input) override;
};

#endif // RENAMEPARSINGSTRATEGY_H
