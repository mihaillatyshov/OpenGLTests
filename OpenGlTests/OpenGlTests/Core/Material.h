#pragma once

#include "Texture.h"
#include <glm.hpp>
#include <memory>

struct MaterialInfo
{
	int DiffuseTextureSlot = -1;
};

struct Material
{
public:
	Material() = default;
	//Material(Texture* texture, const glm::vec4& color = glm::vec4(1.0f)) : Diffuse(texture), DiffuseColor(color) { }
	Material(std::shared_ptr<Texture> texture, const glm::vec4& color = glm::vec4(1.0f)) : Diffuse(texture), DiffuseColor(color) { }
	inline std::shared_ptr<Material> GetStandartMaterial() const { return s_StandartMaterial; }
	void SetStandertMaterial(std::shared_ptr<Material> material);
	bool HasTextures() const;
public:
	std::shared_ptr<Texture> Diffuse = nullptr;
	glm::vec4 DiffuseColor = glm::vec4(1.0f);
public:
	static inline std::shared_ptr<Material> s_StandartMaterial;
};