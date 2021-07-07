#pragma once

#include <unordered_map>
#include <GL/glew.h>
#include <glm.hpp>
#include <TestBoneAnim/math_3d.h>
#include "Material.h"

class Shader
{
protected:
	GLint GetUniformLocation(const std::string &name) const;
	GLuint Load();
	static std::string LoadShaderFile(const std::string& filepath);
public:
	Shader(const char *vertPath, const char *fragPath, bool initArray = true);
	~Shader();

	void Enable() const;
	void Disable() const;


	void SetUniform1f(const std::string &name, float value);
	void SetUniform1fv(const std::string &name, float* value, int count);
	void SetUniform1i(const std::string &name, int value);
	void SetUniform1iv(const std::string &name, int* value, int count);
	void SetUniform2f(const std::string &name, const glm::vec2 &vector);
	void SetUniform3f(const std::string &name, const glm::vec3 &vector);
	void SetUniform4f(const std::string &name, const glm::vec4 &vector);
	void SetUniformMat4(const std::string &name, const glm::mat4& matrix);
	void SetUniformMat4(const std::string &name, const Matrix4f& matrix);
	void SetMaterial(const GLuint id, const Material *material, const MaterialInfo *material_info);
protected:
	GLuint m_ShaderID;
	const char *m_VertPath;
	const char *m_FragPath;
	mutable std::unordered_map<std::string, GLint> m_UniformLocationCache;
};