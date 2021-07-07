#pragma once

#include "Layer.h"
#include "../Scene/Scene.h"

#include <memory>

namespace LM
{

	class SceneLayer : public Layer
	{
	public:
		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;

		virtual void OnImGuiRender() override;
	protected:
		std::shared_ptr<Scene> m_Scene;
	};

}