#include "DXUT.h"

INT GetRandomNum(INT _Min, INT _Max)
{
	//�õ� ����
	random_device RndDevice;
	mt19937_64 rnd(RndDevice());

	//���� ����
	uniform_int_distribution<int> range(_Min, _Max);

	//�� ����
	return range(rnd);
}

FLOAT GetRandomNum(FLOAT _Min, FLOAT _Max)
{
	INT min = (INT)(_Min * 1000);
	INT max = (INT)(_Max * 1000);
	//�õ� ����
	random_device RndDevice;
	mt19937_64 rnd(RndDevice());

	//���� ����
	uniform_int_distribution<int> range(min, max);

	//�� ����
	return (FLOAT)(range(rnd) / 1000.f);
}

