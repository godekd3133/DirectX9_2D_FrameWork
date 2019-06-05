#pragma once
#include "CComponent.h"
#include "CRenderer.h"
#include "CTransform.h"

enum ObjectTag : int
{
	Untagged = 0,

};


class CObject abstract
{
public:
	CObject();
	virtual ~CObject();
public:
	
	virtual void Init(ObjectTag _Tag= Untagged);
	virtual void Update();
	virtual void Release();
protected:
	list<CComponent *>m_Components;
	ObjectTag m_Tag;
protected:
	BOOL m_bDestroy = FALSE; // �ش� ������Ʈ�� �ı�ȣ��Ǿ�����
public:
	CTransform * Translation;

	ObjectTag GetObjectKind() { return m_Tag; }
	
	list<CComponent *>& GetComponents() { return m_Components; }
	BOOL isDestroyed() { return m_bDestroy; }
	void Destroy() { m_bDestroy = TRUE; }

	template <typename T>
	T*  GetComponent()
	{
		for (auto iter : m_Components)
		{
			//�߻�Ŭ������ �����̳��̱⶧����
			//dynamic_cast�� ���� �ڽ�Ŭ������ �ߺ��� ������Ʈ�� ó���մϴ�.
			if (typeid(dynamic_cast<T*>(iter)) == typeid(T*))
				return dynamic_cast<T*>(iter);
		}
		return nullptr;
	}
	
	template <typename T>
	T* AddComponent()
	{
		//������Ʈ�� ��ӹ��� �ʾҴٸ� ����
		if (FALSE == std::is_base_of<CComponent, T>::value)
			return nullptr;

		//�̹� �������ִ� ������Ʈ�� �� �߰��Ϸ��� ����
		if (nullptr != this->GetComponent<T>())
			return this->GetComponent<T>();
		
		T * pComponent = new T(this);

		pComponent->Init();

		m_Components.push_back(pComponent);

		return pComponent;
	}
};


