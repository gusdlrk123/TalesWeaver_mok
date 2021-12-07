#pragma once
#include "GameEntity.h"
#include "header.h"

class Sound;
class TitleScene : public GameEntity
{
private:
	struct tagBtnInfo
	{
		RECT rc;
		POINT pos;
	};
private:
	tagBtnInfo mStartBtn;
	tagBtnInfo mQuitBtn;
	Sound* mSound;
	bool mEffSwitch = false;

public:
	virtual HRESULT Init();
	virtual void Update();
	virtual void Render(HDC hdc);
	virtual void Release();

	TitleScene();
	virtual ~TitleScene();


};

