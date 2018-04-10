#include "AnimationPlayer.h"
#include "ResourceManager.h"

AnimationPlayer::AnimationPlayer(AnimationResource& animation, bool isLooped) :
	_animation(animation),
	_isLooped(isLooped),
	_animationTime(animation.getAnimationTime()),
	_activeFrameId(0)
{

}

void AnimationPlayer::Start()
{
	_animationTime = _animation.getAnimationTime();
	_isStoped = false;
}

void AnimationPlayer::Start(sf::Time animationTime)
{
	_animationTime = animationTime;
	_isStoped = false;
}

void AnimationPlayer::Pause()
{
	_isStoped = true;
}

void AnimationPlayer::Reset()
{
	_activeFrameId = 0;
	_isStoped = true;
}

void AnimationPlayer::Update()
{

}

void AnimationPlayer::draw(sf::RenderTarget & target, sf::RenderStates states)
{
	//target.draw();
}

AnimationResource& AnimationPlayer::GetAnimation() const
{
	return _animation;
}

void AnimationPlayer::SetAnimation(AnimationResource animation)
{
	_animation = animation;
	_animationTime = animation.getAnimationTime();
	_frameTime = _animationTime.asSe
}

void AnimationPlayer::SetLooped(bool isLooped)
{
	_isLooped = isLooped;
}

AnimationPlayer::~AnimationPlayer()
{
}