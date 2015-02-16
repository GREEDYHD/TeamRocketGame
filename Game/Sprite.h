#ifndef _Sprite_H_
#define _Sprite_H_
#include "GameObject2D.h"
#include "GameData.h"

class Sprite : public GameObject2D
{
public:
	Sprite(string _fileName, ID3D11Device* _pd3dDevice, Vector2 _pos);
	~Sprite();

	void Tick(GameData* GD);
	void Draw(DrawData2D* _DD2D);

protected:

	string m_fileName;
	
};

#endif