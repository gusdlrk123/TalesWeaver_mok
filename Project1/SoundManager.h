#pragma once
#include <vector>
using namespace std;

// 1. ������� �����Ѵ�.
/* 2. BGM�� ��ĥ �� ������
Init�� ���� ���ο� BGM�� �־��ְ�,
find�� ���� BGM�� �˻�,
play�� ���� BGM�� ��������ָ�,
release�� ���� �������� ��� BGM����
3. 
*/

class SoundManager
{
private:
	enum eSoundFileNameBGM
	{
		Title_BGM,
	};
	enum eSoundFileNameEff
	{
		BtnOver_Eff,
	};

	vector<pair<eSoundFileNameBGM, int>> mBGM;

public:
	void Init();
};

