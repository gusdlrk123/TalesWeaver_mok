#pragma once
#include "header.h"
#include "define.h"

class Animation2
{
private:
	POINT mPlayerPos;			// �÷��̾��� �߽���
	eMultipleImageTag mImgTag;	// �÷��̾� �̹��� �±�
	Image* mPlayerImg;			// �÷��̾� �̹���
	RECT mPlayerRc;				// �÷��̾� �̹��� RECT

	int mPlayerWidth;			// �÷��̾� �̹����� �ʺ�
	int mPlayerHeight;			// �÷��̾� �̹����� ����
	int mImgMaxFrame;			// �̹����� �ִ� ������
	int mImgCurrFrame;			// �̹����� ���� ������

	int mState;					// �̹����� ����
	float mFrameRotateTime;		// ������ ��ȸ �ð�
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

