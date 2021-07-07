#include "Sprite.h"

#include "Renderers/Renderer.h"
#include <gtx/transform.hpp>
#include <imgui.h>

Sprite::Sprite(glm::vec2 position, glm::vec2 size, std::shared_ptr<Material> material)
{
	//m_Transformation = glm::vec3(position, 0.0f);
	m_Transformation = std::make_shared<LM::Transformation>();

	m_Depth = 0.0f;
	m_Translation = position;
	m_Rotation = 0.0f;
	m_Scaling = glm::vec2(1.0f);

	m_Material = material;

	m_Positions = { glm::vec3(-size.x / 2.0f, -size.y / 2.0f, 0.0f),
					glm::vec3( size.x / 2.0f, -size.y / 2.0f, 0.0f),
					glm::vec3( size.x / 2.0f,  size.y / 2.0f, 0.0f),
					glm::vec3(-size.x / 2.0f,  size.y / 2.0f, 0.0f) };

	m_UVs = { glm::vec2(0.0f, 0.0f), 
			  glm::vec2(1.0f, 0.0f), 
			  glm::vec2(1.0f, 1.0f), 
			  glm::vec2(0.0f, 1.0f) };

	m_Normals = { glm::vec3(0.0f, 0.0f, 1.0f), 
				  glm::vec3(0.0f, 0.0f, 1.0f), 
				  glm::vec3(0.0f, 0.0f, 1.0f), 
				  glm::vec3(0.0f, 0.0f, 1.0f) };

	m_Tangents = { glm::vec3(), glm::vec3(), glm::vec3(), glm::vec3() };

	m_Indices = { 0, 1, 2 , 0, 2, 3 };
}


void Sprite::Submit(Renderer* renderer)
{
	glm::mat4 PosTransform = glm::translate(glm::vec3(m_Translation, m_Depth));
	glm::mat4 RotTransform = glm::rotate(glm::radians(m_Rotation), glm::vec3(0.0f, 0.0f, -1.0f));
	glm::mat4 SclTransform = glm::scale(glm::vec3(m_Scaling, 0.0f));

	glm::mat4 Result = PosTransform * RotTransform * SclTransform;

	m_Transformation->SetTransformation(Result);

	renderer->PushTransform(m_Transformation);
	Renderable::Submit(renderer);
	renderer->PopTransform();
}


void Sprite::ImGuiDraw()
{
	bool isChanged = false;
	ImGui::PushID(this);
	if (ImGui::DragFloat2("Position", &m_Translation.x, 0.01f)) isChanged = true;
	if (ImGui::DragFloat("Rotation", &m_Rotation, 0.1f)) isChanged = true;
	if (ImGui::DragFloat2("Scaling", &m_Scaling.x, 0.01f)) isChanged = true;
	if (ImGui::DragFloat("Depth", &m_Depth, 0.01f)) isChanged = true;
	ImGui::PopID();


	if (isChanged)
	{
		glm::mat4 PosTransform = glm::translate(glm::vec3(m_Translation, m_Depth));
		glm::mat4 RotTransform = glm::rotate(glm::radians(m_Rotation), glm::vec3(0.0f, 0.0f, -1.0f));
		glm::mat4 SclTransform = glm::scale(glm::vec3(m_Scaling, 0.0f));

		glm::mat4 Result = PosTransform * RotTransform * SclTransform;

		m_Transformation->SetTransformation(Result);
	}
}
