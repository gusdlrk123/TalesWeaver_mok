#pragma once
#include "header.h"
#include "define.h"
#include "variable_extern.h"
#include "GameEntity.h"

class TownScene : public GameEntity
{
private:

public:
	virtual HRESULT Init();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

	virtual ~TownScene() {}
};

