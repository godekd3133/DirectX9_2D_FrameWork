#include "DXUT.h"
#include "CAnimation.h"

CAnimation::CAnimation(CONSTREF(string) _Key, float _fDelay, bool _bLoop)
	: m_fDelay(_fDelay),m_bLoop(_bLoop), m_bActive(true)
{
	m_Textures = IMAGE.MakeVecTex(_Key);
	m_iMaxFrame = m_Textures.size() - 1;
	m_pTimer = new CTimer(_fDelay, [&]()->void 
		{
			m_iFrame++;	
			if (m_iFrame > m_iMaxFrame)
			{
				m_iFrame = 0;
				if (!m_bLoop) m_bActive = false;
			}
		});
}


CAnimation::CAnimation(CObject * pObject)
	: CComponent(pObject)
{
}

CAnimation::~CAnimation()
{	
	SAFE_DELETE(m_pTimer);
}

void CAnimation::Update()
{
	if (m_bActive)
		m_pTimer->Update(GetNowTimepoint);
}

void CAnimation::Render(CONSTREF(Vector2) _vPos, FLOAT _fDegree, BOOL _bCenterRender, Vector2 * _pRotationCenter, D3DCOLOR _Color)
{
	m_Textures[m_iFrame]->Render(_vPos, _fDegree, _bCenterRender, _pRotationCenter, _Color);
}

void CAnimation::CropRender(CONSTREF(Vector2) _vPos, CONSTREF(RECT) _CropBox, float _fDegree, D3DCOLOR _Color)
{
	m_Textures[m_iFrame]->CropRender(_vPos, _CropBox, _fDegree, _Color);
}

void CAnimation::ScaleRender(CONSTREF(Vector2) _vPos, CONSTREF(Vector2) _vScale, float _fDegree, D3DCOLOR _Color)
{
	m_Textures[m_iFrame]->ScaleRender(_vPos, _vScale, _fDegree, _Color);
}

