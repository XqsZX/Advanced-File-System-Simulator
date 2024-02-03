#ifndef TEXTFILE_H
#define TEXTFILE_H

#include "../../include/mockos/AbstractFile.h"
#include <string>
#include <vector>

class TextFile : public AbstractFile {
private:
    std::vector<char> content;  // Holds the file's contents
    std::string name;           // Holds the name of the file

public:
    TextFile(const std::string& fileName);

    std::vector<char> read() const override;
    // virtual void read() override;
    virtual int write(const std::vector<char>& data) override;
    virtual int append(const std::vector<char>& data) override;
    virtual unsigned int getSize() const override;
    virtual std::string getName() const override;
    void accept(AbstractFileVisitor* visitor) override;
    AbstractFile* clone(std::string newFileName) override;
};

#endif // TEXTFILE_H
