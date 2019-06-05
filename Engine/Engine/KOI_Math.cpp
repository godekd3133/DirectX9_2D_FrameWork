#include "KOI_Math.h"
using namespace Math;
bool Math::CheckCollision(const Rect & _reRect, const Vector2 & _vPos)
{
	return (_reRect.Left < _vPos.x &&
		_reRect.Top < _vPos.y &&
		_reRect.Right > _vPos.x &&
		_reRect.Bottom > _vPos.y);
}

bool Math::CheckCollision(const Vector2 & _vPos, const Rect & _reRect)
{
	CheckCollision(_reRect, _vPos);
}
bool Math::CheckCollision(const Rect & _reRect01, const Rect & _reRect02)
{
	return (_reRect01.Left < _reRect02.Right &&
		_reRect01.Top <  _reRect02.Bottom &&
		_reRect01.Right > _reRect02.Left &&
		_reRect01.Bottom > _reRect02.Bottom);
}

bool Math::OBBCheckCollision(const Rect & _reRect01, float _fRot01, const Rect & _reRect02, float _fRot02)
{
	Vector2 dist = GetDistanceVector(_reRect01, _reRect02);
	Vector2 vec[4] = { GetHeightVector(_reRect01,_fRot01), GetHeightVector(_reRect02,_fRot02), GetWidthVector(_reRect01,_fRot01), GetWidthVector(_reRect02,_fRot02) };
	Vector2 unit;
	for (int i = 0; i < 4; i++) {
		double sum = 0;
		unit = GetUnitVector(vec[i]);
		for (int j = 0; j < 4; j++) {
			sum += fabsf(D3DXVec2Dot(&vec[j], &unit));
		}
		if (fabsf(D3DXVec2Dot(&dist,&unit)) > sum) {
			return false;
		}
	}
	return true;
}

double Math::DegToRad(double deg)
{
	return deg / 180 * 3.141592;
}

double Math::RadToDeg(double rad)
{
	return rad * 180 / 3.141592;
}

Vector2 Math::GetDistanceVector(Rect a, Rect b)
{
	Vector2 ret;
	ret.x = (a.Left + (a.Right - a.Left) / 2) - (b.Left + (b.Right - b.Left) / 2);
	ret.y = (a.Top + (a.Bottom - a.Top) / 2) - (b.Top + (b.Bottom - b.Top) / 2);
	return ret;
}

Vector2 Math::GetHeightVector(Rect a, float _fRot)
{
	Vector2 ret;
	ret.x = (a.Bottom - a.Top) * cos(DegToRad(_fRot)) / 2;
	ret.y = (a.Bottom - a.Top) * sin(DegToRad(_fRot)) / 2;
	return ret;
}

Vector2 Math::GetWidthVector(Rect a, float _fRot)
{
	Vector2 ret;
	ret.x = (a.Right - a.Left) * cos(DegToRad(_fRot)) / 2;
	ret.y = (a.Right - a.Left) * sin(DegToRad(_fRot)) / 2;
	return ret;
}

Vector2 Math::GetUnitVector(Vector2 a)
{
	Vector2 ret;
	double size;
	size = sqrtf(pow(a.x, 2) + pow(a.y, 2));
	ret.x = a.x / size;
	ret.y = a.y / size;
	return ret;
}

Math::Rect::Rect()
{
}

Math::Rect::Rect(FLOAT _fLeft, FLOAT _fTop, FLOAT _fRight, FLOAT _fBottom)
	: Left(_fLeft), Top(_fTop), Right(_fRight), Bottom(_fBottom)
{
}

Math::Rect::Rect(Vector2  _vPos, FLOAT _fWidth, FLOAT _fHeight)
	: Left(_vPos.x), Top(_vPos.y), Right(_vPos.x + _fWidth), Bottom(_vPos.y + _fHeight)
{

}

Math::Rect::Rect(RECT _reRect)
	: Rect((FLOAT)_reRect.left,
	(FLOAT)_reRect.top,
		(FLOAT)_reRect.right,
		(FLOAT)_reRect.bottom)
{
}

Math::Rect::~Rect()
{
}


