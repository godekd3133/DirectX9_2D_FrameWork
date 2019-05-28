#include "DXUT.h"
#include "CCollider.h"
#include "CObject.h"

CCollider::CCollider(CObject * _pObj, const Rect& _CollisionBox)
	:CComponent(_pObj) ,m_CollisionBox(_CollisionBox)
{
}

CCollider::~CCollider()
{
}

void CCollider::Update(const Vector2&_vPos)
{ 
	m_CollisionRect =
	{
		(LONG)(_vPos.x + m_CollisionBox.left),
		(LONG)(_vPos.y + m_CollisionBox.top),
		(LONG)(_vPos.x + m_CollisionBox.right),
		(LONG)(_vPos.y + m_CollisionBox.bottom),
	};

	m_CollisionObjects.clear();
}

