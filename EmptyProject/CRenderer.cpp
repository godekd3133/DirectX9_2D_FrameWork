#include "DXUT.h"
#include "CRenderer.h"


CRenderer::CRenderer(CObject * _pObj)
	:CComponent(_pObj)
{
}


CRenderer::~CRenderer()
{
}

void CRenderer::Init()
{
	this->m_Color = D3DCOLOR_ARGB(255, 255, 255, 255);
	this->m_rRect = { 0,0,0,0 };
	this->m_bCenterRender = true;
	this->m_pTexture = nullptr;
}

void CRenderer::Update()
{

}

void CRenderer::Render()
{
	if (NULL == m_pTexture)
	{
		DEBUG_LOG("Object Name");
	}

	m_pTexture->Render(
		this->m_pObject->Translation->m_vPosition,
		this->m_pObject->Translation->m_vScale,
		this->m_pObject->Translation->m_fRotation,
		this->m_bCenterRender,
		this->m_pObject->Translation->m_vRotationCenter,
		this->m_rRect,
		this->m_Color);
}

void CRenderer::Release()
{
}

void CRenderer::SetTexture(CTexture * _pTexture)
{
	if (_pTexture == nullptr)
	{
		DEBUG_LOG("SetTextureFunc Error");
		return;
	}
	this->m_pTexture = _pTexture;

	m_rRect = Rect(0.f,0.f,_pTexture->m_Info.Width, _pTexture->m_Info.Height);

}
