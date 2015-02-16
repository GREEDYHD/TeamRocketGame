#include "Sprite.h"

Sprite::Sprite(string _fileName, ID3D11Device* _pd3dDevice, Vector2 _pos) :GameObject2D(_fileName, _pd3dDevice)
{
	m_pos = _pos;
	m_fileName = _fileName;
}

Sprite::~Sprite()
{

}

void Sprite::Tick(GameData* GD)
{
	//Tick(GD);
}

void Sprite::Draw(DrawData2D* _DD2D)
{
	GameObject2D::Draw(_DD2D);
}