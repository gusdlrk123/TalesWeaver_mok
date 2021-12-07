#pragma once
#include "GameObject.h"

class Animation2;

class Character : public GameObject
{
protected:
	RECT mRc;
	int mWidth;
	int mHeight;
	Animation2* mAnimation;

public:
	virtual HRESULT Init();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

	Character() = default;
	virtual ~Character() {};
};

