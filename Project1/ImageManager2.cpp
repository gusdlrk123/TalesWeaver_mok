#include "ImageManager2.h"

void ImageManager2::Init()
{
	// 이미지를 추가하는 방법
	AddImage(eImageTag::None, wstring(L"경로"));
	AddMultipleImage(eMultipleImageTag::StandDown, wstring(L"./Image/Character/Lu/StandStand_D"), 7);

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
}

void ImageManager2::AddImage(eImageTag tag, wstring path)
{
	// 구현하기
}

Image* ImageManager2::GetImage(eImageTag tag)
{
	// 구현하기
	return nullptr;
}

// 경로는 "Images/Temp.png"인 경우 "Images/Temp"까지만 넣는다.
void ImageManager2::AddMultipleImage(eMultipleImageTag tag, wstring path, int length)
{
	// wchar_t 변수 선언(유니코드를 쓰기 때문) : 이미지의 경로
	// lstrlenW : 문자열의 길이를 구하는 함수
	wchar_t* pStr = new wchar_t[lstrlenW(path.c_str()) + 8];

	for (int i = 0; i < length; ++i)
	{
		swprintf(pStr, L"%s%d.png", path.c_str(), i);
		// pStr : "Images/Temp0.png"
		mapMultipleImages[tag].push_back(Image::FromFile(pStr));
	}
}

vector<Image*>& ImageManager2::GetMultipleImage(eMultipleImageTag tag)
{
	return mapMultipleImages[tag];
	// TODO: 여기에 return 문을 삽입합니다.
}
