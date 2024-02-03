#ifndef TOUCHCATPARSINGSTRATEGY_H
#define TOUCHCATPARSINGSTRATEGY_H

#include "AbstractParsingStrategy.h"
#include <vector>
#include <string>

class TouchCatParsingStrategy : public AbstractParsingStrategy {
public:
    std::vector<std::string> parse(std::string input) override;
};

#endif // TOUCHCATPARSINGSTRATEGY_H
