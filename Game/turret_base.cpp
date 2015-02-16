#include "Turret_base.h"
#include <dinput.h>
#include "gamedata.h"
//I suppose we shoudl really call this the main palyer character

Turret_Base::Turret_Base(string _fileName, ID3D11Device* _pd3dDevice, MyEffectFactory* _EF) :CMOGO(_fileName, _pd3dDevice, _EF)
{
	m_pos.y = 10.0f;
	m_scale = 2.0f * Vector3::One;

	m_fudge = Matrix::CreateRotationZ(0.5f * XM_PI);
}

Turret_Base::~Turret_Base()
{

}

void Turret_Base::Tick(GameData* _GD)
{
	CMOGO::Tick(_GD);
}