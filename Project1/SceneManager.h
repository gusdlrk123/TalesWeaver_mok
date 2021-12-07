#pragma once
#include "header.h"
#include "define.h"
#include "Singleton.h"

using namespace std;

enum class eSceneTag
{
	Title,
	Town,
};

class GameEntity;
class SceneManager : public Singleton<SceneManager>
{
private:
	map<eSceneTag, GameEntity*>	mapScenes;
	map<eSceneTag, GameEntity*>	mapLoadingScenes;

public:
	static GameEntity* currScene;		// ���� ��� ���� ��
	static GameEntity* readyScene;		// �غ� ���� ��
	static GameEntity* loadingScene;	// �ε� ��

	void Init(eSceneTag tag, GameEntity* scene);
	void Release();
	void Update();
	void Render(HDC hdc);

	void AddLoadingScene(eSceneTag tag, GameEntity* scene);

	HRESULT ChangeScene(eSceneTag tag);
	HRESULT ChangeScene(eSceneTag tag, eSceneTag loadingSceneName);
};

