#pragma once

class BaseLevel
{
public:
	static BaseLevel* CurrentLevel;

protected:
	class WPlayerController* PlayerController = nullptr;

	class LGameMode* GameMode;

public:
	virtual ~BaseLevel() {}

	virtual void Load() = 0;

	virtual void Init() = 0;

	virtual void End() = 0; 

	virtual void PrepareLevel() = 0;

	virtual void Submit(class LRenderableComponent* renComp) = 0;

	virtual void SubmitNextFrame(LRenderableComponent* renComp) {}
};
