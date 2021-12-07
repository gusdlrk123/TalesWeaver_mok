#include "Animation2.h"

HRESULT Animation2::Init()
{
    mImgCurrFrame = 0;
    mCurrTime = 0;

    return S_OK;
}

void Animation2::Update()
{
}

void Animation2::Render(HDC hdc)
{
    Graphics G(hdc);
    Rectangle(hdc, mPlayerRc.left,
        mPlayerRc.top,
        mPlayerRc.right,
        mPlayerRc.bottom);
    G.DrawImage(IMG_MGR->GetMultipleImage(mImgTag)[mImgCurrFrame],
        (int)mPlayerRc.left,
        (int)mPlayerRc.top,
        (int)mPlayerWidth,
        (int)mPlayerHeight);
}

void Animation2::Release()
{
}

void Animation2::SetAnimationValue(POINT pos, eMultipleImageTag Img,
    float frameTime)
{
    mPlayerPos = pos;               // 현재 포지션
    mImgTag = Img;                  // 현재 이미지 태그
    mImgMaxFrame =                  // 현재 이미지의 MaxFrame
        IMG_MGR->GetMultipleImage(mImgTag).size();
    mImgCurrFrame = 0;
    mFrameRotateTime = frameTime;   // 현재 이미지의 프레임 순회 시간
    mPlayerWidth =                  // 현재 이미지의 너비
        IMG_MGR->GetMultipleImage(mImgTag)[mImgCurrFrame]->GetWidth();
    mPlayerHeight =                 // 현재 이미지의 높이
        IMG_MGR->GetMultipleImage(mImgTag)[mImgCurrFrame]->GetHeight();
    SetRect(&mPlayerRc, mPlayerPos.x - mPlayerWidth / 2,
        mPlayerPos.y - mPlayerHeight / 2,
        mPlayerPos.x + mPlayerWidth / 2,
        mPlayerPos.y + mPlayerHeight / 2);
}

void Animation2::PlayAnimation()
{
    mCurrTime += TIMER_MGR->GetDeltaTime();

    if (mCurrTime >= mFrameRotateTime / mImgMaxFrame)
    {
        if (mImgCurrFrame < mImgMaxFrame - 1) { ++mImgCurrFrame; }
        else { mImgCurrFrame = 0; }// 현재 이미지의 프레임

        mPlayerWidth =                  // 현재 이미지의 너비
            IMG_MGR->GetMultipleImage(mImgTag)[mImgCurrFrame]->GetWidth();
        mPlayerHeight =                 // 현재 이미지의 높이
            IMG_MGR->GetMultipleImage(mImgTag)[mImgCurrFrame]->GetHeight();
        // 현재 이미지의 출력 범위(사각형)
        SetRect(&mPlayerRc, mPlayerPos.x - mPlayerWidth / 2,
            mPlayerPos.y - mPlayerHeight / 2,
            mPlayerPos.x + mPlayerWidth / 2,
            mPlayerPos.y + mPlayerHeight / 2);

        mCurrTime = 0.f;
    }
}



