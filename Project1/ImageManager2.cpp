#include "ImageManager2.h"


void ImageManager2::Init()
{
	// 이미지를 추가하는 방법
	AddImage(eImageTag::Title, wstring(L"./Image/Title/Title"));

	AddMultipleImage(eMultipleImageTag::Stand_D, wstring(L"./Image/Character/Lu/Stand_D"), 7);
	AddMultipleImage(eMultipleImageTag::Stand_L, wstring(L"./Image/Character/Lu/Stand_L"), 7);
	AddMultipleImage(eMultipleImageTag::Stand_LD, wstring(L"./Image/Character/Lu/Stand_LD"), 7);
	AddMultipleImage(eMultipleImageTag::Stand_LU, wstring(L"./Image/Character/Lu/Stand_LU"), 7);
	AddMultipleImage(eMultipleImageTag::Stand_U, wstring(L"./Image/Character/Lu/Stand_U"), 7);
	AddMultipleImage(eMultipleImageTag::Stand_R, wstring(L"./Image/Character/Lu/Stand_L"), 7, true);
	AddMultipleImage(eMultipleImageTag::Stand_RD, wstring(L"./Image/Character/Lu/Stand_LD"), 7, true);
	AddMultipleImage(eMultipleImageTag::Stand_RU, wstring(L"./Image/Character/Lu/Stand_LU"), 7, true);


	// 사용법
	/*
	HDC hdc;
	Graphics G(hdc);
	G.DrawImage(GetImage(eImageTag::None), Gdiplus::Rect(0, 0, 100, 100));
	*/
}

void ImageManager2::Release()
{
	for (auto it = mapImages.begin(); it != mapImages.end();)
	{
		delete it->second;
		it = mapImages.erase(it);
	}

	vector<Image*> vSwap;
	for (auto it = mapMultipleImages.begin(); it != mapMultipleImages.end();)
	{
		swap(it->second, vSwap);
		it = mapMultipleImages.erase(it);
	}
	vSwap.clear();
}

void ImageManager2::AddImage(eImageTag tag, wstring path)
{
	wchar_t* pStr = new wchar_t[(int)lstrlenW(path.c_str()) + 8];
	swprintf(pStr, L"%s.png", path.c_str());
	mapImages[tag] = Image::FromFile(pStr);
}

Image* ImageManager2::GetImage(eImageTag tag)
{
	// 구현하기
	return mapImages[tag];
}

// 경로는 "Images/Temp.png"인 경우 "Images/Temp"까지만 넣는다.
void ImageManager2::AddMultipleImage(eMultipleImageTag tag, wstring path, int length, bool flip)
{
	// wchar_t 변수 선언(유니코드를 쓰기 때문) : 이미지의 경로
	// lstrlenW : 문자열의 길이를 구하는 함수
	wchar_t* pStr = new wchar_t[lstrlenW(path.c_str()) + 8];

	for (int i = 0; i < length; ++i)
	{
		swprintf(pStr, L"%s%d.png", path.c_str(), i);
		// pStr : "Images/Temp0.png"
		if (flip == false)
		{
			mapMultipleImages[tag].push_back(Image::FromFile(pStr));
		}
		else
		{
			Image* temp = Image::FromFile(pStr);
			mapMultipleImages[tag].push_back((Image*)temp->RotateFlip(Rotate180FlipY));
		}
	}
}

vector<Image*>& ImageManager2::GetMultipleImage(eMultipleImageTag tag)
{
	return mapMultipleImages[tag];
	// TODO: 여기에 return 문을 삽입합니다.
}
