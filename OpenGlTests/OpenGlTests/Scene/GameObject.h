#pragma once

#include <vector>

#include "Renderables/Renderable.h"

namespace LM
{

	class GameObject
	{
	public:
		virtual void Add(std::shared_ptr<GameObject> object);

		virtual void Add(std::shared_ptr<Renderable> renderable);

		virtual void Remove();

		virtual void Remove(std::shared_ptr<Renderable> renderable);
		virtual void Remove(Renderable* renderable);

		//virtual void ChangeRoot();
	public:
		std::vector<std::shared_ptr<GameObject>> m_GameObjects;
		std::vector<std::shared_ptr<Renderable>> m_Renderables;

		GameObject* m_Prev;

		glm::mat4 m_Transformation;
		//Transformation m_Transformation;
	};

}