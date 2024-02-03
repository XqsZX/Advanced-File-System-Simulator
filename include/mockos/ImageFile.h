#ifndef IMAGEFILE_H
#define IMAGEFILE_H

#include "AbstractFile.h"
#include <string>
#include <vector>

class ImageFile : public AbstractFile {
private:
    std::string name;
    std::vector<char> content;
    char size;

public:
    ImageFile(const std::string& fileName);

    std::vector<char> read() const override;
    // virtual void read() override;
    virtual int write(const std::vector<char>& data) override;
    virtual int append(const std::vector<char>& data) override;
    virtual unsigned int getSize() const override;
    virtual std::string getName() const override;
    void accept(AbstractFileVisitor* visitor) override;
    AbstractFile* clone(std::string newFileName) override;
};

#endif // IMAGEFILE_H
