#pragma once
#include <vector>
using namespace std;

// 1. 사운드들을 관리한다.
/* 2. BGM은 겹칠 수 없으며
Init을 통해 새로운 BGM을 넣어주고,
find를 통해 BGM을 검색,
play를 통해 BGM을 실행시켜주며,
release를 통해 마지막에 모든 BGM삭제
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

