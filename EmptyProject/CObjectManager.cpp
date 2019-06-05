#include "DXUT.h"
#include "CObjectManager.h"


CObjectManager::CObjectManager()
{
}


CObjectManager::~CObjectManager()
{
	for (auto& iter : m_Objects)
	{
		iter->Release();
		SAFE_DELETE(iter);
	} 
	m_Objects.clear();
}



void CObjectManager::Update()
{
	 
	for (auto& iter = m_Objects.begin(); iter != m_Objects.end();)
	{
		CObject * pObj = (CObject*)(LP(iter));

		pObj->CObject::Update();

		pObj->Update();
		
		for (auto& iter : pObj->GetComponents())
		{
			iter->Update();
		}

		// 오브젝트가 파괴되었다면
		if (TRUE == LP(iter)->isDestroyed())
		{
			LP(iter)->Release();
			SAFE_DELETE(LP(iter));
			iter = m_Objects.erase(iter);
		}
		else iter++;
	}
}

void CObjectManager::Render()
{
	// 오브젝트를 받아와서 출력순에 따라 정렬할 리스트로 복사한다.
	list<CObject *> Renderlist;
	for (auto& iter : m_Objects)
	{
		//1. 렌더러 컴포넌트를 사용하고
		//2. 렌더러 컴포넌트의 기능이 켜져있다면
		//3. 렌더링 리스트에 추가한다.
		if (nullptr != iter->GetComponent<CRenderer>() &&
			TRUE == iter->GetComponent<CRenderer>()->isActive())
		{
			Renderlist.push_back(iter);
		}
	}

	// 렌더링 리스트를 깊이에따라 오름차순으로 정렬
	//Renderlist.sort([&](CObject *  pPrev, CObject *  pNext)->bool { return pPrev->GetDepth() > pNext->GetDepth(); });

	for (auto& iter : Renderlist)
	{
		
	}
	
}
