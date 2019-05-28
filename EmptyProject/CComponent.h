#pragma once
class CObject;
class CComponent 
{
public:
	CComponent(CObject * _pObj);
	virtual ~CComponent();

public:
	virtual void Init() PURE;
	virtual void Update() PURE;
	virtual void Render() PURE;
	virtual void Release() PURE;
	bool isActive() { return true; }
protected:
	CObject * m_pObject;
};

