#include "DXUT.h"
#include "CTexture.h"


CTexture::CTexture()
{
}


CTexture::~CTexture()
{
	SAFE_RELEASE(m_pTexture);
}

void CTexture::Render(const Vector2 & _vPos, const Vector2 & _vScale, FLOAT _fDegree, BOOL _bCenterRender, const Vector2 & _vRotationCenter, Rect _reRect, Color _Color)
{
	IMAGE.Render(this, _vPos, _vScale, _fDegree, _bCenterRender, _vRotationCenter, _reRect, _Color);
}


