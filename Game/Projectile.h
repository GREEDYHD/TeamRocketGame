#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_
#include "GameObject2D.h"

class Projectile : public GameObject2D
{
public:
	Projectile(string _fileName, Vector2 _direction, int _speed, int _damage, int _range, Vector2 _origin, ID3D11Device* _pd3dDevice);
	~Projectile();

	void Tick(GameData* GD);

	void Spawn(float _life, Vector2 _pos, Vector2 _direction);
	bool getAliveState();
	void Draw(DrawData2D* _DD2D);
	XMFLOAT2 getPosition();
	
protected:
	bool m_alive;
	string m_fileName;
	Vector2 m_direction;
	int m_speed;
	int m_damage;
	int m_range;
	Vector2 m_originP;
	float m_lifeLeft;
	
	Vector2 projectileTarget;

};

#endif