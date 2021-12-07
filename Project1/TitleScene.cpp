#include "define.h"
#include "TitleScene.h"
#include "variable_extern.h"
#include "Sound.h"

HRESULT TitleScene::Init()
{
	
	mStartBtn.pos = { 941, 729 };
	mStartBtn.rc.left =		mStartBtn.pos.x - 74;
	mStartBtn.rc.right =	mStartBtn.pos.x + 74;
	mStartBtn.rc.top =		mStartBtn.pos.y - 22;
	mStartBtn.rc.bottom =	mStartBtn.pos.y + 22;

	mQuitBtn.pos = { 64, 729 };
	mQuitBtn.rc.left = mQuitBtn.pos.x - 53;
	mQuitBtn.rc.right = mQuitBtn.pos.x + 53;
	mQuitBtn.rc.top = mQuitBtn.pos.y - 15;
	mQuitBtn.rc.bottom = mQuitBtn.pos.y + 16;

	return S_OK;
}

void TitleScene::Update()
{
}

void TitleScene::Render(HDC hdc)
{
	Graphics G(hdc);

	G.DrawImage(IMG_MGR->GetImage(eImageTag::Title), 0, 0, WIN_SIZE_X, WIN_SIZE_Y);

	if (PtInRect(&mStartBtn.rc, g_ptMouse))
	{
		if (mEffSwitch == false)
		{
			mEffSwitch = true;
		}
		Image startImg(L"./Image/Title/Start_btn.png");
		G.DrawImage(&startImg, (INT)mStartBtn.rc.left, (INT)mStartBtn.rc.top, 145, 41);
		if (KEY_MGR->IsStayKeyDown(VK_LBUTTON))
		{
			Image startImg(L"./Image/Title/Start_btn_click.png");
			G.DrawImage(&startImg, (INT)mStartBtn.rc.left, (INT)mStartBtn.rc.top, 145, 41);
		}
		if (KEY_MGR->IsOnceKeyUp(VK_LBUTTON))
		{
			SCENE_MGR->ChangeScene(eSceneTag::Town);
		}
	}

	if (PtInRect(&mQuitBtn.rc, g_ptMouse))
	{
		if (mEffSwitch == false)
		{
			mEffSwitch = true;
		}
		Image quitImg(L"./Image/Title/Quit_btn.png");
		G.DrawImage(&quitImg, (INT)mQuitBtn.rc.left, (INT)mQuitBtn.rc.top, 106, 31);
		if (KEY_MGR->IsStayKeyDown(VK_LBUTTON))
		{
			Image quitImg(L"./Image/Title/Quit_btn_click.png");
			G.DrawImage(&quitImg, (INT)mQuitBtn.rc.left, (INT)mQuitBtn.rc.top, 106, 31);
		}
		if (KEY_MGR->IsOnceKeyUp(VK_LBUTTON))
		{
			PostQuitMessage(0);
		}
	}
}

void TitleScene::Release()
{
	
}

TitleScene::TitleScene()
{

}

TitleScene::~TitleScene()
{

}
