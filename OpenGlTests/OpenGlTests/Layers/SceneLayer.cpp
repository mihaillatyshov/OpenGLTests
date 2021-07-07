#include "SceneLayer.h"

namespace LM
{

	void SceneLayer::OnAttach()
	{
		m_Scene = std::make_shared<Scene>(glm::mat4(1.0f), nullptr);
	}

	void SceneLayer::OnDetach()
	{

	}

	void SceneLayer::OnUpdate()
	{

	}

	void SceneLayer::OnImGuiRender()
	{
		m_Scene->ImGuiRender();
	}

}