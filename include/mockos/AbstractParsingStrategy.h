#ifndef ABSTRACTPARSINGSTRATEGY_H
#define ABSTRACTPARSINGSTRATEGY_H

#include <vector>
#include <string>

class AbstractParsingStrategy {
public:
    virtual ~AbstractParsingStrategy() = default;
    virtual std::vector<std::string> parse(std::string) = 0;
};

#endif // ABSTRACTPARSINGSTRATEGY_H
