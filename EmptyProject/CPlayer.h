#pragma once
#include "CObject.h"

enum class PLAYER_STATUS
{
	Run = 0,
	Jump,
	DoubleJump,
	Slide,
};
class CPlayer :
	public CObject
{

public:
	CPlayer();
	~CPlayer();

public:
	virtual void Init();
	virtual void Update();
	virtual void Render();
	virtual void Release();

private:
	map<PLAYER_STATUS,CAnimation *> m_Animations; 
	PLAYER_STATUS m_Status;
};

