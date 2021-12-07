#pragma once
#include "Singleton.h"
#include "header.h"
#include "define.h"

using namespace std;
using namespace Gdiplus;

// �ϳ��� �̹����� �ҷ��ö� ���� �±�
enum class eImageTag
{
	None,
	Title,
	Town,
};

// �������� �̹����� �ҷ��ö� ���� �±�
enum class eMultipleImageTag
{
	None,
	Stand_D,
	Stand_L,
	Stand_LD,
	Stand_LU,
	Stand_U,
	Stand_R,
	Stand_RD,
	Stand_RU,
};

class ImageManager2 : public Singleton<ImageManager2>
{
private:
	unordered_map<eImageTag, Image*>	mapImages;
	unordered_map<eMultipleImageTag, vector<Image*>>	mapMultipleImages;

public:
	void Init();
	void Release();

	void AddImage(eImageTag tag, wstring path);
	Image* GetImage(eImageTag tag);

	void AddMultipleImage(eMultipleImageTag tag, wstring path, int length, bool flip = false);
	vector<Image*>& GetMultipleImage(eMultipleImageTag tag);
};

