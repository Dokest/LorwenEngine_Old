#pragma once

#include "GameObject.h"

#include "Maths/Maths.h"

#include <vector>

namespace Lorwen {

	using namespace Maths;

	struct STransform
	{
		Vec3 Position;
		Vec3 Size;
		Vec3 Rotation;

	private:
		Mat4 m_ModelMatrix;

	public:
		/* TODO */
		inline void UpdateModelMatrix() 
		{

		}

		STransform() {}
		STransform(Vec3 position, Vec3 size, Vec3 rotation, float rotationAngle)
			: Position(position), Size(size), Rotation(rotation)
		{
			m_ModelMatrix = Mat4::Translation(position);
			m_ModelMatrix *= Mat4::Rotation(rotationAngle, rotation);
			m_ModelMatrix *= Mat4::Scale(size);
		}

	};

	class WorldObject : public GameObject
	{
	private:
		std::vector<class Component*> m_pComponents;

	public:
		STransform Transform;


		WorldObject();

	public:
		inline std::vector<class Component*>& GetComponents() { return m_pComponents; }


	protected:
		virtual void OnCreation() {}
		virtual void OnUpdate(float deltaTime) {}
		virtual void OnDestruction() {}

	private:
		inline void _Create() { WorldObject::_Create(); }
 		inline void _Update(float deltaTime) { WorldObject::OnUpdate(deltaTime); }
 		inline void _Destroy() { WorldObject::OnDestruction(); }
		
	};

}