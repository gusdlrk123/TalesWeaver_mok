#pragma once
#include "Singleton.h"
#include "header.h"
#include "define.h"

using namespace std;
using namespace Gdiplus;

// 하나의 이미지만 불러올때 쓰는 태그
enum class eImageTag
{
	None,
};

// 여러개의 이미지를 불러올때 쓰는 태그
enum class eMultipleImageTag
{
	None,
	StandDown,
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

	void AddMultipleImage(eMultipleImageTag tag, wstring path, int length);
	vector<Image*>& GetMultipleImage(eMultipleImageTag tag);
};

