#ifndef _Player_H_
#define _Player_H_
#include "GameObject2D.h"
#include "Projectile.h"
#include <vector>

class Projectile;

class Player : public GameObject2D
{
public:
	Player(string _fileName, ID3D11Device* _pd3dDevice);
	~Player();

	void Draw(DrawData2D* _DD2D);
	void Tick(GameData* GD);

protected:
	char Direction;
	int projectileSpeed;
	int projectileDamage;
	int projecteleRange;
	int projectileOrigin;

	Vector2 shootDirection;
	vector<Projectile*> playerProjectiles;
};

#endif