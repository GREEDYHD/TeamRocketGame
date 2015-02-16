#ifndef _Map_Loader_H_
#define _Map_Loader_H_
#include "GameObject2D.h"
#include "DrawData2D.h"
#include "Sprite.h"
#include <vector>
//#include <list>
struct GameData;
class Sprite;

class MapLoader :public GameObject2D
{
public:
	MapLoader(string _fileName, ID3D11Device* _pd3dDevice);
	~MapLoader();

	void Tick(GameData* GD);
	void LoadMap();
	void Draw(DrawData2D* _DD2D);

protected:

	string m_fileName;
	string LevelData;

	float m_rotation;
	//vector<MapLoader *> MapData;
	vector<Sprite *> SpriteData;
	//DrawData2D* m_DD2D;
};

#endif