#ifndef BASICDISPLAYVISITOR_H
#define BASICDISPLAYVISITOR_H

#include "AbstractFileVisitor.h"
#include "TextFile.h"
#include "ImageFile.h"

class BasicDisplayVisitor : public AbstractFileVisitor {
public:
    void visit_TextFile(TextFile* file) override;
    void visit_ImageFile(ImageFile* file) override;
};

#endif // BASICDISPLAYVISITOR_H
