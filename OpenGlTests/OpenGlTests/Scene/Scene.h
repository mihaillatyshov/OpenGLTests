#pragma once


#include "GameObject.h"
#include "../Debug/ConsoleLog.h"

namespace LM
{
	class Scene : public GameObject
	{
	public:
		Scene(const glm::mat4& transform, Renderer* renderer) 
		{
			m_Prev = nullptr; 
		}

		//void Remove() override
		//{
		//	LOGW("you can't delete Scene Object!");
		//}

		//void Remove(std::shared_ptr<Renderable> renderable) override
		//{
		//	LOGW("you can't delete Scene Object!");
		//}

		void ImGuiGameObject(void* ptr_id, std::shared_ptr<GameObject> go, int id);
		void ImGuiRender();
	protected:
	};

}