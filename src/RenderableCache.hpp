#ifndef RENDERABLECACHE_HPP
#define RENDERABLECACHE_HPP

#include <queue>
#include <vector>

namespace grout
{
class IRenderable;
class RenderableCache
{
private:
    std::queue<std::vector<IRenderable *> > mQueue;
public:
    RenderableCache();

    void clear();
    void pushLayer();
    void popLayer();
    void addRenderable(IRenderable *);
};
};

#endif // RENDERABLECACHE_HPP
