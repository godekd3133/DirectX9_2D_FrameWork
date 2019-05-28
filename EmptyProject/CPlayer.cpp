#include "DXUT.h"
#include "CPlayer.h"

CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
	 
}

void CPlayer::Init()
{
	//m_Animations[PLAYER_STATUS::Run] = new CAnimation("RUN", 0.05f, true);
	//m_Animations[PLAYER_STATUS::Slide] = new CAnimation("RUN", 0.05f, true);
	//m_Animations[PLAYER_STATUS::Jump] = new CAnimation("RUN", 0.05f, true);
	//m_Animations[PLAYER_STATUS::DoubleJump] = new CAnimation("RUN", 0.05f, true);
	AddComponent<CRenderer>();
}

void CPlayer::Update()
{
	// DEBUG_LOG("player update");
	//GetComponent<CCollider>()->Update(m_vPosition);
	//_Animations[m_Status]->Update();
	
//	if (INPUT.KeyPress(VK_LEFT)) m_vPosition.x -= 400 * TIME.DeltaTime;
//	if (INPUT.KeyPress(VK_RIGHT)) m_vPosition.x += 400 * TIME.DeltaTime;
}

void CPlayer::Render()
{
	//m_pAnimation[m_Status]->Render(m_vPosition);
}

void CPlayer::Release()
{
	//SAFE_DELETE(m_pAnimation);
}
