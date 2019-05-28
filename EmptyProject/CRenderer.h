#pragma once
#include "CComponent.h"
class CRenderer 
	: public CComponent
{
public:
	CRenderer(CObject * _pObj);
	~CRenderer();
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
public:
	CTexture * m_pTexture = nullptr;
	Color m_Color;
	Rect m_rRect;
	bool m_bCenterRender;

private:
	void SetTexture(CTexture * _pTexture);


};

 