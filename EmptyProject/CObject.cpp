#include "DXUT.h"
#include "CObject.h"


CObject::CObject()
{
}


CObject::~CObject()
{
	for (auto iter : m_Components)
	{
		SAFE_DELETE(iter);
	}
	m_Components.clear();
}


void CObject::Init(ObjectTag _Tag)
{
	Translation = this->AddComponent<CTransform>();
	m_Tag = _Tag;
}

void CObject::Update()
{

}


void CObject::Release()
{
}


