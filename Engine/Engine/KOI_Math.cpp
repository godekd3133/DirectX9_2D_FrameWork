#include "KOI_Math.h"

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
