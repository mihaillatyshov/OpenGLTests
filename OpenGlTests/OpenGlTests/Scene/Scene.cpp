#include "Scene.h"

#include <imgui.h>
#include "../Debug/ConsoleLog.h"

namespace LM
{

	void Scene::ImGuiGameObject(void* ptr_id, std::shared_ptr<GameObject> go, int id)
	{
		ImGui::PushID(ptr_id);

		ImGui::AlignTextToFramePadding();
		bool isTN = ImGui::TreeNode(ptr_id, "GameObjects %4d %X", id, ptr_id);

		ImGui::SameLine();
		if (ImGui::Button("Add GO"))
		{
			go->Add(std::make_shared<GameObject>());
		}

		ImGui::SameLine();
		if (ImGui::Button("Del GO"))
		{
			go->Remove();
		}

		ImGui::SameLine();
		if(ImGui::Button("Add R"))
		{
			go->Add(std::make_shared<Renderable>());
		}

		if (isTN)
		{
			for (int i = 0; i < go->m_GameObjects.size(); i++)
			{
				ImGuiGameObject((void*)go->m_GameObjects[i].get(), go->m_GameObjects[i], i);
			}

			ImGui::TreePop();
		}

		//ImGui::SameLine();
		for (int i = 0; i < go->m_Renderables.size(); i++)
		{
			ImGui::PushID(i);
			ImGui::AlignTextToFramePadding();
			ImGui::BulletText("Renderable %4d", i);
			ImGui::SameLine();
			if (ImGui::Button("Del"))
			{
				go->Remove(go->m_Renderables[i]);
			}
			ImGui::PopID();
		}

		ImGui::PopID();
	}

	void Scene::ImGuiRender()
	{
		if (ImGui::Begin("SceneLayer"))
		{
			if (ImGui::CollapsingHeader("Scene"))
			{
				ImGui::AlignTextToFramePadding();
				bool isTN = ImGui::TreeNode("GameObjects##Scene");

				ImGui::SameLine();
				if (ImGui::Button("Add GO##Scene"))
				{
					Add(std::make_shared<GameObject>());
				}

				ImGui::SameLine();
				if (ImGui::Button("Del GO"))
				{
					Remove();
				}

				ImGui::SameLine();
				if (ImGui::Button("Add R##Scene"))
				{
					Add(std::make_shared<Renderable>());
				}

				if (isTN)
				{
					for (int i = 0; i < m_GameObjects.size(); i++)
					{
						ImGuiGameObject((void*)m_GameObjects[i].get(), m_GameObjects[i], i);
					}

					ImGui::TreePop();
				}

				for (int i = 0; i < m_Renderables.size(); i++)
				{
					ImGui::PushID(i);
					ImGui::AlignTextToFramePadding();
					ImGui::Text("Renderable %4d", i);
					ImGui::SameLine();
					if (ImGui::Button("Del"))
					{
						Remove(m_Renderables[i]);
					}
					ImGui::PopID();
				}

			}
		}

		ImGui::End();
	}

}