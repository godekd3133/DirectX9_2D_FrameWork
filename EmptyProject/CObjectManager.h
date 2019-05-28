#pragma once
#include "singleton.h"



class CObjectManager :
	public singleton<CObjectManager>
{
public:
	CObjectManager();
	~CObjectManager();
private:
	list<CObject *> m_Objects;
public:
	void AddObject(CObject * _pObject);
public:
	void Update();
	void Render();
};

#define OBJECT (*CObjectManager::GetInstance())