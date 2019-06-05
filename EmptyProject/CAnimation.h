//#pragma once
//#include "CComponent.h"
//class CAnimation : public CComponent
//{
//public:
//	CAnimation(CObject * pObject);
//	~CAnimation();
//private:
//	vector<CTexture*> m_Textures;
//	CTimer * m_pTimer = nullptr;
//
//	// 재생 딜레이
//	float m_fDelay;
//
//	// 반복 여부 FALSE 일경우 한번만 돌고 0프레임으로 가고 재생 정지
//	bool m_bLoop;
//	
//	// 애니메이션 재생중인지 
//	bool m_bActive;
//
//	// 인덱스 기준 현재 프레임
//	int m_iFrame = 0;
//
//	// 인덱스 기준 최대 프레임
//	int m_iMaxFrame;
//public:
//	void Update();
//public:
//	void Render(
//		CONSTREF(Vector2)	_vPos,
//		FLOAT				_fDegree = 0.f,
//		BOOL				_bCenterRender = TRUE,
//		Vector2 *			_pRotationCenter = nullptr,
//		D3DCOLOR			_Color = COLOR_BASIC);
//
//	void CropRender(
//		CONSTREF(Vector2)	_vPos,
//		CONSTREF(RECT)		_CropBox,
//		float				_fDegree = 0.f,
//		D3DCOLOR			_Color = COLOR_BASIC);
//
//	void ScaleRender(
//		CONSTREF(Vector2)	_vPos,
//		CONSTREF(Vector2)	_vScale = { 1.f,1.f },
//		float				_fDegree = 0.f,
//		D3DCOLOR			_Color = COLOR_BASIC);
//};
//
