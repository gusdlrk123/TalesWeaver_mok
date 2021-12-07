#pragma once
#include "header.h"
#include "define.h"

class Animation2
{
private:
	POINT mPlayerPos;			// 플레이어의 중심점
	eMultipleImageTag mImgTag;	// 플레이어 이미지 태그
	Image* mPlayerImg;			// 플레이어 이미지
	RECT mPlayerRc;				// 플레이어 이미지 RECT

	int mPlayerWidth;			// 플레이어 이미지의 너비
	int mPlayerHeight;			// 플레이어 이미지의 높이
	int mImgMaxFrame;			// 이미지의 최대 프레임
	int mImgCurrFrame;			// 이미지의 현재 프레임

	int mState;					// 이미지의 상태
	float mFrameRotateTime;		// 프레임 순회 시간
	float mCurrTime;

public:
	HRESULT Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void SetAnimationValue(POINT pos, eMultipleImageTag Img,
		float frameTime = 1);
	void PlayAnimation();

};

