#include "AnimationSequence.hpp"
#include "IVisitor.hpp"
#include <utility>

using namespace grout;

AnimationSequence::AnimationSequence()
{
}

AnimationSequence::~AnimationSequence()
{
}

void AnimationSequence::accept(IVisitor *visitor)
{
    visitor->visit(this);
}

void AnimationSequence::setAnimation(std::string key, Animation animation)
{
    mAnimationMap[key] = animation;//TODO investigate emplace
}

bool AnimationSequence::play(std::string key) // TODO : check if this key exists
{    
    mActiveAnimation = key;

    return true;
}

const Animation AnimationSequence::getActiveAnimation() const
{
    return mAnimationMap.at(mActiveAnimation);//C++11
}
