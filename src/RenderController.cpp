#include "RenderController.hpp"
#include "IRenderable.hpp"
#include "Transform.hpp"
#include "Texture.hpp"
#include "Rectangle.hpp"
#include "Shader.hpp"
#include <algorithm>

using namespace grout;

RenderController::RenderController()
{
}

void RenderController::addRenderable(IRenderable *renderable)
{
    mRenderables.push_back(renderable);
}

void RenderController::render()
{
    //std::sort(mRenderables.begin(), mRenderables.end());

    for(IRenderable *renderable : mRenderables)
    {
        Transform * transform = renderable->getTransform();
        Texture * texture = renderable->getTexture();
        math::Rectangle * rectangle = renderable->getRectangle();
        Shader * shader = renderable->getShader();

        glBindTexture(GL_TEXTURE_2D, texture->textureId);

        int x = transform->position.x;
        int y = transform->position.y;
        int width = rectangle->width;
        int height = rectangle->width;
        float textureX = rectangle->x / texture->width;
        float textureY = rectangle->y / texture->height;
        float textureWidth = rectangle->width / texture->width;
        float textureHeight = rectangle->height / rectangle->height;

        glBegin(GL_QUADS);
            glTexCoord2f(textureX, textureY)            ; glVertex3f(x, y, 0);
            glTexCoord2f(textureWidth, textureY)        ; glVertex3f(x + width, y, 0);
            glTexCoord2f(textureWidth, textureHeight)   ; glVertex3f(x + width, y + height, 0);
            glTexCoord2f(textureX, textureHeight)       ; glVertex3f(x, y + height, 0);
        glEnd();


//        glBegin(GL_QUADS);
//            glTexCoord2f(0, 0); glVertex3f(x, y, 0);
//            glTexCoord2f(1, 0); glVertex3f(x + width, y, 0);
//            glTexCoord2f(1, 1); glVertex3f(x + width, y + height, 0);
//            glTexCoord2f(0, 1); glVertex3f(x, y + height, 0);
//        glEnd();

    }

    mRenderables.clear();
}

