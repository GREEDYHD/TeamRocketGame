#ifndef _GAME_OBJECT_2D_H_
#define _GAME_OBJECT_2D_H_
#include <d3d11_1.h>
#include "SimpleMath.h"
#include <string>
#include "gamedata.h"

using namespace DirectX;
using namespace SimpleMath;
using namespace std;

struct DrawData2D;

class GameObject2D
{
public:
	GameObject2D(){};
	GameObject2D(string _fileName, ID3D11Device* _GD);
	virtual ~GameObject2D();

	virtual void Tick(GameData* GD);
	virtual void Draw(DrawData2D* DD);

	void SetPos(Vector2 _pos){ m_pos = _pos; }
	void SetRot(float _rot){ m_rotation = _rot; }
	void SetColour(Color _colour){ m_colour = _colour; }
	void SetScale(Vector2 _scale){ m_scale = _scale; }
	void SetScale(float _scale){ m_scale = _scale * Vector2::One; }
	void SetOrigin(Vector2 _origin){ m_origin = _origin; }

protected:
	Vector2 m_pos;
	Vector2 p_pos;
	float m_rotation;
	Vector2 m_scale;
	Color m_colour;
	Vector2 m_origin;

	ID3D11ShaderResourceView* m_pTextureRV;

};


#endif