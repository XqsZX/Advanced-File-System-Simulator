#ifndef METADATADISPLAYVISITOR_H
#define METADATADISPLAYVISITOR_H

#include "AbstractFileVisitor.h"

class TextFile;
class ImageFile;

class MetadataDisplayVisitor : public AbstractFileVisitor {
public:
    void visit_TextFile(TextFile* file) override;
    void visit_ImageFile(ImageFile* file) override;
};

#endif // METADATADISPLAYVISITOR_H
