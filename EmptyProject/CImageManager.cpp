#include "DXUT.h"
#include "CImageManager.h"


CImageManager::CImageManager()
{
	D3DXCreateSprite(g_Device, &m_pSprite);
}


CImageManager::~CImageManager()
{
	for (auto& iter : m_mapTexture)
	{
		SAFE_DELETE(iter.second);
	}
	m_mapTexture.clear();
	SAFE_RELEASE(m_pSprite);

}

void CImageManager::Begin(bool isInterface)
{
	if (TRUE == isInterface)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
	}
	else m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
}

void CImageManager::End()
{
	m_pSprite->End();
}

void CImageManager::ReBegin(bool isInterface)
{
	m_pSprite->End();
	if (TRUE == isInterface)
	{
		m_pSprite->Begin(D3DXSPRITE_ALPHABLEND);
	}
	else m_pSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_OBJECTSPACE);
}

void CImageManager::OnLostDevice()
{
	m_pSprite->OnLostDevice();
}

void CImageManager::OnResetDevice()
{
	m_pSprite->OnResetDevice();
}

CTexture * CImageManager::AddTexture(CONSTREF(string) _Key, CONSTREF(string) _Path)
{
	auto find = m_mapTexture.find(_Key);
	
	if (find == m_mapTexture.end())
	{
		CTexture * pTexture = new CTexture;
		
		if (S_OK == D3DXCreateTextureFromFileExA(
			g_Device,
			_Path.c_str(),
			D3DX_DEFAULT_NONPOW2,
			D3DX_DEFAULT_NONPOW2,
			0,
			0,
			D3DFMT_UNKNOWN,
			D3DPOOL_MANAGED,
			D3DX_DEFAULT,
			D3DX_DEFAULT,
			0,
			&pTexture->m_Info,
			NULL,
			&pTexture->m_pTexture))
		{
			m_mapTexture[_Key] = pTexture;
			return pTexture;
		}
		DEBUG_LOG("FAILED LOAD TEXTURE %s",_Path.c_str());
		return nullptr;
	}
	
	return find->second;
}

CTexture * CImageManager::FindTexture(CONSTREF(string) _Key)
{
	auto find = m_mapTexture.find(_Key);
	
	if (find != m_mapTexture.end())
	{
		return find->second;
	}
	return nullptr;
}

vector<CTexture*> CImageManager::MakeVecTex(CONSTREF(string) _Key)
{
	vector<CTexture*> vecTexture;
	
	for(int i = 1; ; i++)
	{
		char Key[100];
		sprintf(Key, "%s (%d)", _Key.c_str(),i);

		auto Find = FindTexture(Key);
		if (Find == nullptr)
			break;
		
		vecTexture.push_back(Find);
	}

	if (vecTexture.empty() == true)
	{
		DEBUG_LOG("VECTEXTURE IS EMPTY : %s", _Key.c_str());
	}
	
	return vecTexture;	
}

void CImageManager::Render(
	CTexture * _pTexture,
	const Vector2& _vPos,
	const Vector2& _vScale,
	FLOAT _fDegree,
	BOOL _bCenterRender,
	const Vector2& _vRotationCenter,
	Rect _reRect,
	Color _Color)
{
	Vector3 vCenter = Vector3(_pTexture->m_Info.Width / 2.f, _pTexture->m_Info.Height / 2.f, 0.f);

	Matrix matWorld, matScale, matRotation, matTransformation;

	D3DXMatrixScaling(&matScale, _vScale.x, _vScale.y, 0.f);

	D3DXMatrixRotationAxis(&matRotation,&Vector3( _vRotationCenter.x,_vRotationCenter.y,0.f), D3DXToRadian(_fDegree));

	D3DXMatrixTranslation(&matTransformation, _vPos.x, _vPos.y, 0.f);

	matWorld = matScale * matRotation * matTransformation;

	m_pSprite->SetTransform(&matWorld);

	m_pSprite->Draw(_pTexture->m_pTexture, &(RECT)_reRect, _bCenterRender == TRUE ? &vCenter : nullptr, nullptr, _Color);

}


