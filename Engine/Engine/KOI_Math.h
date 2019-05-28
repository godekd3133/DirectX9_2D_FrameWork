#pragma once
#include "stdafx.h"
#include "KOI_Rect.h"
namespace Math
{
	static float PI = 3.141592f;

	using Vector2 = KOI_DEF_TYPEDEFINE_VECTOR2D;
	using Vector3 = KOI_DEF_TYPEDEFINE_VECTOR3D;
	using Vector4 = KOI_DEF_TYPEDEFINE_VECTOR4D;
	using Matrix = KOI_DEF_TYPEDEFINE_MAXTRIX4;
	using Rect = KOI_Rect; 

	//사각형안에 벡터가 속해있는지 확인해주는 함수
	bool CheckCollision(const Rect& _reRect, const Vector2& _vPos);
	bool CheckCollision(const Vector2& _vPos, const Rect& _reRect);


	bool CheckCollision(const Rect& _reRect01, const Rect& _reRect02);

	bool OBBCheckCollision(const Rect& _reRect01, float _fRot01, const Rect& _reRect02, float _fRot02);




	double DegToRad(double deg) { //deg -> rad 
		return deg / 180 * 3.141592;
	}
	double RadToDeg(double rad) { //deg -> rad 
		return rad * 180 / 3.141592;
	}

	Vector2 GetDistanceVector(Rect a, Rect b) { //distance vector
		Vector2 ret;
		ret.x = (a.Left + (a.Right - a.Left) / 2) - (b.Left + (b.Right - b.Left) / 2);
		ret.y = (a.Top + (a.Bottom - a.Top) / 2) - (b.Top + (b.Bottom - b.Top) / 2);
		return ret;
	}

	Vector2 GetHeightVector(Rect a, float _fRot) { //height vector
		Vector2 ret;
		ret.x = (a.Bottom - a.Top) * cos(DegToRad(_fRot)) / 2;
		ret.y = (a.Bottom - a.Top) * sin(DegToRad(_fRot)) / 2;
		return ret;
	}

	Vector2 GetWidthVector(Rect a,float _fRot) { //width vector
		Vector2 ret;
		ret.x = (a.Right - a.Left) * cos(DegToRad(_fRot)) / 2;
		ret.y = (a.Right - a.Left) * sin(DegToRad(_fRot)) / 2;
		return ret;
	}

	Vector2 GetUnitVector(Vector2 a) { //unit vector
		Vector2 ret;
		double size;
		size = sqrtf(pow(a.x, 2) + pow(a.y, 2));
		ret.x = a.x / size;
		ret.y = a.y / size;
		return ret;
	}
}