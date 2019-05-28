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
	BOOL m_bDestroy = FALSE; // 해당 오브젝트가 파괴호출되었는지
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
			//추상클래스의 컨테이너이기때문에
			//dynamic_cast를 통해 자식클래스로 중복된 컴포넌트를 처리합니다.
			if (typeid(dynamic_cast<T*>(iter)) == typeid(T*))
				return dynamic_cast<T*>(iter);
		}
		return nullptr;
	}
	
	template <typename T>
	void AddComponent()
	{
		//컴포넌트를 상속받지 않았다면 리턴
		if (FALSE == std::is_base_of<CComponent, T>::value)
			return;

		//이미 가지고있는 컴포넌트를 또 추가하려면 리턴
		if (nullptr != this->GetComponent<T>())
			return;

		//new T 구문에 파라미터가 들어가는 이유는 위의 코드에서 예외처리를 마쳤기떄문입니다.
		T * pComponent = new T(this);

		pComponent->Init();

		m_Components.push_back(pComponent);
	}
};
#define tf GetComponent<CTransform>()


