#pragma once
#include "CCollider.h"
#include "CComponent.h"
#include "CRenderer.h"
#include "CTransform.h"

enum ObjectTag : int
{
	Untagged = 0,

};


class CObject
{
public:
	CObject();
	virtual ~CObject();
public:
	virtual void Init();
	virtual void Update();
	virtual void Release();

protected:
	list<CComponent *>m_Components;
	ObjectTag m_Tag;
protected:
	BOOL m_bDestroy = FALSE; // �ش� ������Ʈ�� �ı�ȣ��Ǿ�����
public:
	ObjectTag GetObjectKind() { return m_Tag; }
	virtual void OnCollisionEnter() PURE;
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
	void AddComponent()
	{
		//������Ʈ�� ��ӹ��� �ʾҴٸ� ����
		if (FALSE == std::is_base_of<CComponent, T>::value)
			return;

		//�̹� �������ִ� ������Ʈ�� �� �߰��Ϸ��� ����
		if (nullptr != this->GetComponent<T>())
			return;

		//new T ������ �Ķ���Ͱ� ���� ������ ���� �ڵ忡�� ����ó���� ���Ʊ⋚���Դϴ�.
		T * pComponent = new T(this);

		pComponent->Init();

		m_Components.push_back(pComponent);
	}
};
#define tf GetComponent<CTransform>()


