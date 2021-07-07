#pragma once

#include "Renderable.h"
#include "Transformation.h"


class Sprite : public Renderable
{
public:
	Sprite(glm::vec2 position, glm::vec2 size, std::shared_ptr<Material> material = Material::s_StandartMaterial);
	virtual void Submit(Renderer* renderer) override;

	void ImGuiDraw();
protected:
	glm::vec2 m_Translation;
	float     m_Rotation;
	glm::vec2 m_Scaling;
	float m_Depth;
	std::shared_ptr<LM::Transformation> m_Transformation;
};