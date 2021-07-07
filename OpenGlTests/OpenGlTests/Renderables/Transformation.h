#pragma once

#include <vector>
#include <memory>
#include <glm.hpp>

namespace LM
{

	class TransformTreeNode;
	class TransformTree;

	class Transformation
	{
	public:
		Transformation(const glm::mat4& transformation = glm::mat4(1.0f))
		{
			SetTransformation(transformation);
		}

		inline void SetTransformation(const glm::mat4& transformation)
		{
			m_Transformation = transformation;
			m_IsChanged = true;
		}

		inline void SetIsChanged(bool isChanged = false) { m_IsChanged = isChanged; }

		inline const glm::mat4& GetTransformation() { return m_Transformation; }

		inline bool GetIsChanged() { return m_IsChanged; }

	protected:
		glm::mat4 m_Transformation;
		bool m_IsChanged;
		//TransformTreeNode* m_TransformNode; // TEST THIS!!!
	};


	//////////////////////////////////////////////////////////////////////////////
	////////// TransformTreeNode /////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
	struct TransformTreeNode
	{
		TransformTreeNode(const glm::mat4& transform, uint32_t id, std::shared_ptr<TransformTreeNode> prev);
		~TransformTreeNode();

		void SetLocalTransform(const glm::mat4& transform);
		void Recalculate();
	public:
		uint32_t Id;

		std::vector<std::shared_ptr<TransformTreeNode>> Next;
		std::shared_ptr<TransformTreeNode> Prev;

		glm::mat4 Transform;		// Calculated transform
	protected:
		glm::mat4 LocalTransform;	// Local transform
	};


	//////////////////////////////////////////////////////////////////////////////
	////////// TransformTree /////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
	struct TransformTree
	{
	public:
		TransformTree();
		~TransformTree();

		bool Find(std::shared_ptr<TransformTreeNode> check, uint32_t id, std::shared_ptr<TransformTreeNode> &place);

		void Push(const glm::mat4& transform, uint32_t place, uint32_t id);
		void Pop(uint32_t id);

		void Change(const glm::mat4& transform, uint32_t id);


	public:
		std::shared_ptr<TransformTreeNode> First;

		//uint32_t Count = 0;

		//static inline TransformTree* s_Instance;
	};

}