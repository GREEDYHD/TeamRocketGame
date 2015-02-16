#include "Player.h"
#include <dinput.h>
#include "gamedata.h"

Player::Player(string _fileName, ID3D11Device* _pd3dDevice) :GameObject2D(_fileName, _pd3dDevice)
{
	m_pos = Vector2(896.0f, 476.0f);
	shootDirection = Vector2(0 , -1);
	m_scale = m_scale *0.5;
	for (int i = 0; i < 100; i++)
	{
		playerProjectiles.push_back(new Projectile("white", shootDirection, 100, 10, 100, Vector2(100.0f,100.0f), _pd3dDevice));
	}
}

Player::~Player()
{

}

void Player::Draw(DrawData2D* _DD2D)
{
	for (vector<Projectile*>::iterator it = playerProjectiles.begin(); it != playerProjectiles.end(); it++)
	{
		(*it)->Draw(_DD2D);
	}
	GameObject2D::Draw(_DD2D);
}
void Player::Tick(GameData* GD)
{
	float speed = GD->dt * 500.0f;
	if (GD->keyboard[DIK_A] & 0x80)
	{
		m_pos.x -= speed;
		Direction = 'N';
		shootDirection = Vector2(-1, 0);
	}
	if (GD->keyboard[DIK_D] & 0x80)
	{
		m_pos.x += speed;
		Direction = 'S';
		shootDirection = Vector2(1, 0);
	}
	if (GD->keyboard[DIK_W] & 0x80)
	{
		m_pos.y -= speed;
		Direction = 'E';
		shootDirection = Vector2(0, -1);
	}
	if (GD->keyboard[DIK_S] & 0x80)
	{
		m_pos.y += speed;
		Direction = 'W';
		shootDirection = Vector2(0, 1);
	}
	if (GD->keyboard[DIK_SPACE] & 0x80)
	{
		for (int i = 0; i < 100; i++)
		{
			if (!playerProjectiles[i]->getAliveState())
			{
				playerProjectiles[i]->Spawn(1.0f, m_pos, shootDirection);
				break;
			}
		}
	}
	for (vector<Projectile*>::iterator it = playerProjectiles.begin(); it != playerProjectiles.end(); it++)
	{
		(*it)->Tick(GD);
	}
}