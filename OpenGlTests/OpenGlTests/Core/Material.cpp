#include "Material.h"



void Material::SetStandertMaterial(std::shared_ptr<Material> material)
{
	s_StandartMaterial = material;
}

bool Material::HasTextures() const
{
	//Texture* t1 = nullptr;
	//Texture* t2 = nullptr;
	//Texture* t3 = nullptr;
	//
	//return t1 || t2 || t3;

	//(bool)Diffuse

	if (Diffuse /* || Specular || Normal */)
		return true;

	return false;

	//return (bool)Diffuse /* || Specular || Normal */;
}
