#pragma once

#include "GameObject.h"

#include "Maths/Maths.h"

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
	public:
		STransform Transform;

		WorldObject();

	public:



	private:
		virtual inline void Create() { OnCreation(); }
		virtual inline void Update(float deltaTime) { OnUpdate(deltaTime); }
		virtual inline void Destroy() { OnDestruction(); }
		
	};

}