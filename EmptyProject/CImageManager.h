#pragma once
#include "singleton.h"
class CImageManager :
	public singleton< CImageManager>
{
public:
	CImageManager();
	~CImageManager();
private:
	LPD3DXSPRITE m_pSprite = NULL;
	map<string, CTexture*> m_mapTexture;
public:
	void Begin(bool isInterface);
	void End();
	void ReBegin(bool isInterface);
	void OnLostDevice();
	void OnResetDevice();
public:
	CTexture * AddTexture(CONSTREF(string)_Key, CONSTREF(string) _Path);
	CTexture * FindTexture(CONSTREF(string)_Key);
	vector<CTexture*> MakeVecTex(CONSTREF(string)_Key);
public:
	void Render(
		CTexture * _pTexture,
		const Vector2& _vPos,
		const Vector2& _vScale,
		FLOAT _fDegree,
		BOOL _bCenterRender,
		const Vector2& _vRotationCenter,
		Rect _reRect,
		Color _Color);


};

#define IMAGE (*CImageManager::GetInstance())

