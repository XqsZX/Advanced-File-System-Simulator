#ifndef ABSTRACTFILEVISITOR_H
#define ABSTRACTFILEVISITOR_H

class TextFile;
class ImageFile;

class AbstractFileVisitor {
public:
    virtual ~AbstractFileVisitor() = default;
    virtual void visit_TextFile(TextFile* file) = 0;
    virtual void visit_ImageFile(ImageFile* file) = 0;
};

#endif // ABSTRACTFILEVISITOR_H
