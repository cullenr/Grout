#ifndef ANIMATIONSEQUENCE_HPP
#define ANIMATIONSEQUENCE_HPP

#include "Animation.hpp"
#include <string>
#include <map>

namespace grout
{
class IVisitor;
class AnimationSequence
{
    std::map<std::string, Animation> mAnimationMap;
    std::string mActiveAnimation;
public :
    AnimationSequence();
    ~AnimationSequence();

    void setAnimation(std::string key, Animation animation);
    bool play(std::string key);
    const Animation getActiveAnimation() const;

    void accept(IVisitor *);
};
};


inline std::ostream& operator<<(std::ostream &strm, const grout::AnimationSequence &a)
{
    return strm << "AnimationSequence" << std::endl;
}

#endif // ANIMATIONSEQUENCE_HPP
