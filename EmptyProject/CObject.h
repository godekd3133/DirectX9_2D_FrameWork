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
	BOOL m_bDestroy = FALSE; // 해당 오브젝트가 파괴호출되었는지
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
			//추상클래스의 컨테이너이기때문에
			//dynamic_cast를 통해 자식클래스로 중복된 컴포넌트를 처리합니다.
			if (typeid(dynamic_cast<T*>(iter)) == typeid(T*))
				return dynamic_cast<T*>(iter);
		}
		return nullptr;
	}
	
	template <typename T>
	T* AddComponent()
	{
		//컴포넌트를 상속받지 않았다면 리턴
		if (FALSE == std::is_base_of<CComponent, T>::value)
			return nullptr;

		//이미 가지고있는 컴포넌트를 또 추가하려면 리턴
		if (nullptr != this->GetComponent<T>())
			return this->GetComponent<T>();
		
		T * pComponent = new T(this);

		pComponent->Init();

		m_Components.push_back(pComponent);

		return pComponent;
	}
};


