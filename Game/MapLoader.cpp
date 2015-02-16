#include "MapLoader.h"
#include <fstream>


MapLoader::MapLoader(string _fileName, ID3D11Device* _pd3dDevice) 
{
	m_pTextureRV = nullptr;
	LoadMap();
	m_fileName = _fileName;
	m_rotation = 0.0f;
	m_pos = Vector2(64.0f, 64.0f);
	for (int i = 0; i < LevelData.size(); i++)
	{
		if (LevelData[i] == 'X')
		{
			//SpriteData.push_back(new Sprite("128x128", _pd3dDevice, m_pos));
			m_pos.x += 128.0f;
		}
		else if (LevelData[i] == 'Y')
		{
			//SpriteData.push_back(new Sprite("testSprite", _pd3dDevice, m_pos));
			m_pos.x += 128.0f;
		}
		else if (LevelData[i] == 'I')
		{
			m_pos.x = 64.0f;
			m_pos.y += 128.0f;
		}
	}
}

MapLoader::~MapLoader()
{

}

void MapLoader::Tick(GameData* GD)
{
	/*
	for (vector<Sprite *>::iterator it = SpriteData.begin(); it != SpriteData.end(); it++)
	{
		(*it)->Tick(GD);//Updates All the Sprites
	}
	*/
}

void MapLoader::LoadMap()
{
	ifstream levelFile;
	levelFile.open("HELLO");
	getline(levelFile, LevelData);
	levelFile.close();
}

void MapLoader::Draw(DrawData2D* _DD2D)
{
	for (vector<Sprite *>::iterator it = SpriteData.begin(); it != SpriteData.end(); it++)
	{
		(*it)->Draw(_DD2D);//Calls Draw Function from SpriteDraw
	}
}