#pragma once
#include "stdafx.h"
namespace Math
{
	static float PI = 3.141592f;

	using Vector2 = KOI_DEF_TYPEDEFINE_VECTOR2D;
	using Vector3 = KOI_DEF_TYPEDEFINE_VECTOR3D;
	using Vector4 = KOI_DEF_TYPEDEFINE_VECTOR4D;
	using Matrix = KOI_DEF_TYPEDEFINE_MAXTRIX4;


	class Rect
	{
	public:
		FLOAT Left;
		FLOAT Top;
		FLOAT Right;
		FLOAT Bottom;
	public:
		Rect();
		Rect(FLOAT _fLeft, FLOAT _fTop, FLOAT _fRight, FLOAT _fBottom);
		Rect(Vector2 _vPos, FLOAT _fWidth, FLOAT _fHeight);
		Rect(RECT _reRect);
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
		~Rect();
	};

	//사각형안에 벡터가 속해있는지 확인해주는 함수
	bool CheckCollision(const Rect& _reRect, const Vector2& _vPos);
	
	//사각형안에 벡터가 속해있는지 확인해주는 함수
	bool CheckCollision(const Vector2& _vPos, const Rect& _reRect);


	bool CheckCollision(const Rect& _reRect01, const Rect& _reRect02);

	bool OBBCheckCollision(const Rect& _reRect01, float _fRot01, const Rect& _reRect02, float _fRot02);


	//deg -> rad
	__inline double DegToRad(double deg);

	//deg -> rad 
	__inline double RadToDeg(double rad);

	//distance vector
	Vector2 GetDistanceVector(Rect a, Rect b);

	//height vector
	Vector2 GetHeightVector(Rect a, float _fRot);	 

	//width vector
	Vector2 GetWidthVector(Rect a, float _fRot);

	//unit vector
	Vector2 GetUnitVector(Vector2 a);
}
