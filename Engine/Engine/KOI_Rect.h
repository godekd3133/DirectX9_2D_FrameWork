#pragma once
class KOI_Rect
{
public:
	FLOAT Left;
	FLOAT Top;
	FLOAT Right;
	FLOAT Bottom;
public:
	KOI_Rect();
	KOI_Rect(FLOAT _fLeft, FLOAT _fTop, FLOAT _fRight, FLOAT _fBottom);
	KOI_Rect(const Vector2& _vPos, FLOAT _fWidth, FLOAT _fHeight);
	KOI_Rect(RECT _reRect);
	operator RECT()
	{
		return
		{
			(LONG)Left,
			(LONG)Top,
			(LONG)Right,
			(LONG)Bottom
		};
	}
	~KOI_Rect();
};

