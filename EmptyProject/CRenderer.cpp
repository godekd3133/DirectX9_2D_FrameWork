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
	m_pTexture->Render(
		m_pObject->tf->m_vPosition,
		m_pObject->tf->m_vScale,
		m_pObject->tf->m_fRotation,
		this->m_bCenterRender,
		m_pObject->tf->m_vRotationCenter,
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

	m_rRect = { 0.f,0.f,_pTexture->m_Info.Width, _pTexture->m_Info.Height };

}
