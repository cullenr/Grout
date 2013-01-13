#ifndef RENDERCONTROLLER_HPP
#define RENDERCONTROLLER_HPP

#include "Viewport.hpp"
#include <vector>

namespace grout
{
class Sprite;
class RenderController
{
public:
    RenderController();
    void createViewport();
    void enableViewport();
    void disableViewport();
    void begin();
    void finish();
};

class RenderContext
{
protected :
    std::vector<Sprite *> mFrame;
    Viewport &viewport;
    void begin();
    bool addSprite(Sprite *);//Called by the library level RenderVisitor
    void finish();

    RenderContext(Viewport &viewport) : viewport(viewport)
    {
    }
};
};

#endif // RENDERCONTROLLER_HPP


//for each ( RenderContextIter rc )
// rc->begin()
//
//updateSprites()
//=>
//RenderController
