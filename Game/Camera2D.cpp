////base camera class
//#include "Camera2D.h"
//
//Camera2D::Camera2D(float _fieldOfView, float _aspectRatio, float _nearPlaneDistance, float _farPlaneDistance, Vector2 _target)
//{
//	m_fieldOfView = _fieldOfView;
//	m_aspectRatio = _aspectRatio;
//	m_nearPlaneDistance = _nearPlaneDistance;
//	m_farPlaneDistance = _farPlaneDistance;
//	m_target = _target;
//}
//
//Camera2D::~Camera2D()
//{
//
//}
//
//void Camera2D::Tick(GameData* _GD)
//{
//	m_projMat = Matrix::CreatePerspectiveFieldOfView(m_fieldOfView, m_aspectRatio, m_nearPlaneDistance, m_farPlaneDistance);
//	//m_viewMat = Matrix::CreateLookAt(m_pos, m_target);
//
//	GameObject2D::Tick(_GD);
//}
//
//void Camera2D::Draw(DrawData2D* _DD2D)
//{
//	//standard camera doesn't draw ANYTHING
//}