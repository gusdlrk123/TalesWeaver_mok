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
    mPlayerPos = pos;               // ���� ������
    mImgTag = Img;                  // ���� �̹��� �±�
    mImgMaxFrame =                  // ���� �̹����� MaxFrame
        IMG_MGR->GetMultipleImage(mImgTag).size();
    mImgCurrFrame = 0;
    mFrameRotateTime = frameTime;   // ���� �̹����� ������ ��ȸ �ð�
    mPlayerWidth =                  // ���� �̹����� �ʺ�
        IMG_MGR->GetMultipleImage(mImgTag)[mImgCurrFrame]->GetWidth();
    mPlayerHeight =                 // ���� �̹����� ����
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
        else { mImgCurrFrame = 0; }// ���� �̹����� ������

        mPlayerWidth =                  // ���� �̹����� �ʺ�
            IMG_MGR->GetMultipleImage(mImgTag)[mImgCurrFrame]->GetWidth();
        mPlayerHeight =                 // ���� �̹����� ����
            IMG_MGR->GetMultipleImage(mImgTag)[mImgCurrFrame]->GetHeight();
        // ���� �̹����� ��� ����(�簢��)
        SetRect(&mPlayerRc, mPlayerPos.x - mPlayerWidth / 2,
            mPlayerPos.y - mPlayerHeight / 2,
            mPlayerPos.x + mPlayerWidth / 2,
            mPlayerPos.y + mPlayerHeight / 2);

        mCurrTime = 0.f;
    }
}



