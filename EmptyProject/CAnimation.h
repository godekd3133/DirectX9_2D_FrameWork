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
//	// ��� ������
//	float m_fDelay;
//
//	// �ݺ� ���� FALSE �ϰ�� �ѹ��� ���� 0���������� ���� ��� ����
//	bool m_bLoop;
//	
//	// �ִϸ��̼� ��������� 
//	bool m_bActive;
//
//	// �ε��� ���� ���� ������
//	int m_iFrame = 0;
//
//	// �ε��� ���� �ִ� ������
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
