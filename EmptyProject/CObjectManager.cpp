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

		// ������Ʈ�� �ı��Ǿ��ٸ�
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
	// ������Ʈ�� �޾ƿͼ� ��¼��� ���� ������ ����Ʈ�� �����Ѵ�.
	list<CObject *> Renderlist;
	for (auto& iter : m_Objects)
	{
		//1. ������ ������Ʈ�� ����ϰ�
		//2. ������ ������Ʈ�� ����� �����ִٸ�
		//3. ������ ����Ʈ�� �߰��Ѵ�.
		if (nullptr != iter->GetComponent<CRenderer>() &&
			TRUE == iter->GetComponent<CRenderer>()->isActive())
		{
			Renderlist.push_back(iter);
		}
	}

	// ������ ����Ʈ�� ���̿����� ������������ ����
	//Renderlist.sort([&](CObject *  pPrev, CObject *  pNext)->bool { return pPrev->GetDepth() > pNext->GetDepth(); });

	for (auto& iter : Renderlist)
	{
		
	}
	
}
