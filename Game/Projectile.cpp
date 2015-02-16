#include "Projectile.h"
#include <dinput.h>
#include "gamedata.h"

Projectile::Projectile(string _fileName, Vector2 _direction, int _speed, int _damage, int _range, Vector2 _origin, ID3D11Device* _pd3dDevice) :GameObject2D(_fileName, _pd3dDevice)
{
	m_fileName = _fileName;
	m_speed = _speed * 4;
	m_damage = _damage;
	m_range = _range;
	m_pos = _origin;
	m_alive = false;
}

Projectile::~Projectile()
{

}

void Projectile::Spawn(float _life, Vector2 _pos, Vector2 _direction)
{
	m_alive = true;
	m_pos = _pos;
	m_direction = _direction;
	projectileTarget = Vector2(XMVectorAdd(Vector2((m_direction.x * m_range), (m_direction.y * m_range)), m_pos));
	m_lifeLeft = _life;
}

void Projectile::Tick(GameData* GD)
{
	if (m_alive)
	{
		m_lifeLeft -= GD->dt;
		if (m_lifeLeft < 0.0f)
		{
			m_alive = false;
			return;
		}
		XMStoreFloat2(&m_pos, XMLoadFloat2(&m_pos) + m_speed * GD->dt *	XMLoadFloat2(&m_direction));
		GameObject2D::Tick(GD);
	}
	/*if (m_pos.x < projectileTarget.x && m_pos.y < projectileTarget.y)
	{
		m_alive = false;
	}*/
}


bool Projectile::getAliveState()
{
	return m_alive;
}

void Projectile::Draw(DrawData2D* _DD2D)
{
	if (m_alive)
	{
		GameObject2D::Draw(_DD2D);
	}
}
XMFLOAT2 Projectile::getPosition()
{
	return m_pos;
}