#include "DXUT.h"
#include "CMainScene.h"
#include "CPlayer.h"

CMainScene::CMainScene()
{
}


CMainScene::~CMainScene()
{
}

void CMainScene::Init()
{
	OBJECT.AddObject<CPlayer>()->Init();
}

void CMainScene::Update()
{
}

void CMainScene::Render()
{

}

void CMainScene::Release()
{
}
