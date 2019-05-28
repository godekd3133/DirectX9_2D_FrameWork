#include "stdafx.h"
#include "KOI_Rect.h"

KOI_Rect::KOI_Rect()
{
}

KOI_Rect::KOI_Rect(FLOAT _fLeft, FLOAT _fTop, FLOAT _fRight, FLOAT _fBottom)
	: Left(_fLeft) , Top(_fTop), Right(_fRight), Bottom(_fBottom)
{
}

KOI_Rect::KOI_Rect(const Vector2 & _vPos, FLOAT _fWidth, FLOAT _fHeight)
	: Left(_vPos.x), Top(_vPos.y), Right(_vPos.x + _fWidth), Bottom(_vPos.y + _fHeight)
{
	
}

KOI_Rect::KOI_Rect(RECT _reRect)
	: Rect((FLOAT)_reRect.left,
		(FLOAT)_reRect.top,
		(FLOAT)_reRect.right,
		(FLOAT)_reRect.bottom)
{
}

KOI_Rect::~KOI_Rect()
{
}

