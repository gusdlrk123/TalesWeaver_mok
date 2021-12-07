#include "ImageManager2.h"

void ImageManager2::Init()
{
	// �̹����� �߰��ϴ� ���
	AddImage(eImageTag::None, wstring(L"���"));
	AddMultipleImage(eMultipleImageTag::StandDown, wstring(L"./Image/Character/Lu/StandStand_D"), 7);

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
}

void ImageManager2::AddImage(eImageTag tag, wstring path)
{
	// �����ϱ�
}

Image* ImageManager2::GetImage(eImageTag tag)
{
	// �����ϱ�
	return nullptr;
}

// ��δ� "Images/Temp.png"�� ��� "Images/Temp"������ �ִ´�.
void ImageManager2::AddMultipleImage(eMultipleImageTag tag, wstring path, int length)
{
	// wchar_t ���� ����(�����ڵ带 ���� ����) : �̹����� ���
	// lstrlenW : ���ڿ��� ���̸� ���ϴ� �Լ�
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
	// TODO: ���⿡ return ���� �����մϴ�.
}
