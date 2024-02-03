#ifndef PASSWORDPROXY_H
#define PASSWORDPROXY_H

#include "AbstractFile.h"
#include <string>

class PasswordProxy : public AbstractFile {
private:
    AbstractFile* realFile;
    std::string password;

protected:
    std::string passwordPrompt() const;
    bool checkPassword(const std::string& input) const;

public:
    PasswordProxy(AbstractFile* file, const std::string& password);
    ~PasswordProxy();

    // Inherited from AbstractFile
    std::vector<char> read() const override;
    int write(const std::vector<char>& v) override;
    int append(const std::vector<char>& v) override;
    unsigned int getSize() const override;
    std::string getName() const override;
    void accept(AbstractFileVisitor* visitor) override;
    AbstractFile* clone(std::string newFileName) override;
};

#endif // PASSWORDPROXY_H
