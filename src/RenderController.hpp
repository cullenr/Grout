#ifndef RENDERCONTROLLER_HPP
#define RENDERCONTROLLER_HPP

#include "Viewport.hpp"
#include <vector>
#include <list>

namespace grout
{
class IRenderable;

class RenderController
{
    std::vector<Viewport> mViewports;
    std::list<IRenderable *> mRenderables;
public:
    RenderController();
    void addRenderable(IRenderable *);
    void render();
};
};

#endif // RENDERCONTROLLER_HPP

