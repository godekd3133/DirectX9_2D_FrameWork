#pragma once
#include "CComponent.h"

class CObject;
class CCollider : public CComponent
{
public:
	CCollider(CObject * _pObj,const Rect& _CollisionBox);
	~CCollider();
private:
	RECT m_CollisionRect;
	RECT m_CollisionBox;
	list <CObject *> m_CollisionObjects;
public:
	void Update(const Vector2& _vPos);
	RECT GetCollisionBox() { return m_CollisionBox; }
	RECT GetCollisionRect() { return m_CollisionRect; }
	list<CObject *>& GetCollisionObjects() {return m_CollisionObjects;}
};

