#include "ImageManager2.h"


void ImageManager2::Init()
{
	// �̹����� �߰��ϴ� ���
	AddImage(eImageTag::Title, wstring(L"./Image/Title/Title"));

	AddMultipleImage(eMultipleImageTag::Stand_D, wstring(L"./Image/Character/Lu/Stand_D"), 7);
	AddMultipleImage(eMultipleImageTag::Stand_L, wstring(L"./Image/Character/Lu/Stand_L"), 7);
	AddMultipleImage(eMultipleImageTag::Stand_LD, wstring(L"./Image/Character/Lu/Stand_LD"), 7);
	AddMultipleImage(eMultipleImageTag::Stand_LU, wstring(L"./Image/Character/Lu/Stand_LU"), 7);
	AddMultipleImage(eMultipleImageTag::Stand_U, wstring(L"./Image/Character/Lu/Stand_U"), 7);
	AddMultipleImage(eMultipleImageTag::Stand_R, wstring(L"./Image/Character/Lu/Stand_L"), 7, true);
	AddMultipleImage(eMultipleImageTag::Stand_RD, wstring(L"./Image/Character/Lu/Stand_LD"), 7, true);
	AddMultipleImage(eMultipleImageTag::Stand_RU, wstring(L"./Image/Character/Lu/Stand_LU"), 7, true);


	// ����
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
	// �����ϱ�
	return mapImages[tag];
}

// ��δ� "Images/Temp.png"�� ��� "Images/Temp"������ �ִ´�.
void ImageManager2::AddMultipleImage(eMultipleImageTag tag, wstring path, int length, bool flip)
{
	// wchar_t ���� ����(�����ڵ带 ���� ����) : �̹����� ���
	// lstrlenW : ���ڿ��� ���̸� ���ϴ� �Լ�
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
	// TODO: ���⿡ return ���� �����մϴ�.
}
