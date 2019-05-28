#include "DXUT.h"
#include "CMainGame.h"
#include "CLoadingScene.h"
#include "CMainScene.h"

CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
}

void CMainGame::Init()
{
	TIME.AddTimer("HELLO", new CTimer(60.f, [&]()->void
		{
			//MEMORYSTATUSEX memInfo;
			//memInfo.dwLength = sizeof(MEMORYSTATUSEX);
			//GlobalMemoryStatusEx(&memInfo);
			//DWORDLONG totalVirtualMem = memInfo.ullTotalPageFile;

			//�� ���μ����� ���� �ִ� Virtual Memory :
			PROCESS_MEMORY_COUNTERS pmc;
			GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
			//SIZE_T virtualMemUsedByMe = pmc.PrivateUsage;

			//��ü Physical Memory(RAM) 
			//	DWORDLONG totalPhysMem = memInfo.ullTotalPhys;
			//���� ���� �ִ� Physical Memory 
			//	DWORDLONG physMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;
			//�� ���μ����� ���� �ִ� Physical Memory
			SIZE_T physMemUsedByMe = pmc.WorkingSetSize;

			FLOAT Byte = physMemUsedByMe / 1024.f / 1024.f;
			DEBUG_LOG("���� ������� �޸� : %.1f MB", Byte);
		}
	));


	//SOUND.AddSound("1", "./Sound/Flak.wav");
	//SOUND.AddSound("2", "./Sound/aim.wav");
	//SOUND.AddSound("3", "./Sound/489.mp3");
	//SOUND.Play("1", FALSE);
	//SOUND.Play("2", FALSE);
	//SOUND.Play("3", FALSE);
	SCENE.AddScene("S_LOADING", new CLoadingScene());
	SCENE.AddScene("S_MAIN", new CMainScene());

	SCENE.ChangeScene("S_LOADING");
}
void CMainGame::Update()
{
	TIME.Update();

	INPUT.Update();

	OBJECT.Update();

	CAMERA.Update();

	SCENE.Update();
}

void CMainGame::Render()
{
	CAMERA.SetTransform();

	IMAGE.Begin(FALSE);

	SCENE.Render();

	OBJECT.Render();

	IMAGE.End();
}

void CMainGame::Release()
{
	CInputManager::ReleaseInstance();
	CImageManager::ReleaseInstance();
	CObjectManager::ReleaseInstance();
	CSceneManager::ReleaseInstance();
	CTimeManager::ReleaseInstance();
	CDataManager::ReleaseInstance();
	CSoundManager::ReleaseInstance();
	CCameraManager::ReleaseInstance();
}

void CMainGame::OnResetDevice()
{
	IMAGE.OnResetDevice();
}

void CMainGame::OnLostDevice()
{
	IMAGE.OnLostDevice();
}
