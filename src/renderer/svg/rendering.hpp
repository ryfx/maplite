#ifndef __SVG_RENDERING_H__
#define __SVG_RENDERING_H__

#include <string>
#include <cairo.h>
#include <memory>

namespace svg {

class Document ;

// This is the entry point to SVG rendering

// provides a binding between the loaded SVG DOM and the associated file

class DocumentInstance
{
public:

    // load from file

     bool load(std::istream &strm) ;

    // render to target context centered on (x,y) scaled to (size) and with given dpi

    void renderToTarget(cairo_t *target, float x, float y, float sw, float sh, float dpi) ;

private:

    std::shared_ptr<Document> root_ ;

    std::string file_name_ ;

private:

    void render(cairo_t *cr, float w, float h, float dpi);
};

}


#endif
