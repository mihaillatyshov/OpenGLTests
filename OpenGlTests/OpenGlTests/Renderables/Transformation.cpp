#include "Transformation.h"

namespace LM
{

	TransformTreeNode::TransformTreeNode(const glm::mat4 &transform, uint32_t id, std::shared_ptr<TransformTreeNode> prev)
		: LocalTransform(transform), Id(id), Prev(prev)
	{
		Transform = Prev->Transform * LocalTransform;
	}

	TransformTreeNode::~TransformTreeNode()
	{
	}

	void TransformTreeNode::SetLocalTransform(const glm::mat4& transform)
	{
		LocalTransform = transform;
	}

	void TransformTreeNode::Recalculate()
	{
		Transform = Prev->Transform * LocalTransform;

		for (auto& node : Next)
		{
			node->Recalculate();
		}
	}



	TransformTree::TransformTree()
	{
		//s_Instance = this;

		First = std::make_shared<TransformTreeNode>(glm::mat4(1.0f), 0, nullptr);
	}

	TransformTree::~TransformTree()
	{
		//s_Instance = nullptr;
	}

	bool TransformTree::Find(std::shared_ptr<TransformTreeNode> check, uint32_t id, std::shared_ptr<TransformTreeNode>& place)
	{
		if (check->Id == id)
		{
			place = check;
			return true;
		}

		for (auto& node : check->Next)
		{
			if (Find(node, id, place))
			{
				return true;
			}
		}

		return false;
	}

	void TransformTree::Push(const glm::mat4& transform, uint32_t place, uint32_t id)
	{
		std::shared_ptr<TransformTreeNode> Node;

		Find(First, place, Node);

		Node->Next.push_back(std::make_shared<TransformTreeNode>(transform, id, nullptr));

		//if (place == First->Id)
		//{
		//	First->Next.push_back(std::make_shared<TransformTreeNode>(transform, id));
		//}
		//
		//for 
	}

	void TransformTree::Pop(uint32_t id)
	{
		std::shared_ptr<TransformTreeNode> Node;

		Find(First, id, Node);

		uint32_t fid;
		for (fid = 0; fid < Node->Prev->Next.size(); fid++)
		{
			if (Node->Prev->Next[fid]->Id == id)
				break;
		}
		
		Node->Prev->Next.erase(Node->Prev->Next.begin() + fid);
	}

	void TransformTree::Change(const glm::mat4& transform, uint32_t id)
	{
		std::shared_ptr<TransformTreeNode> Node;

		Find(First, id, Node);

		Node->SetLocalTransform(transform);
		Node->Recalculate();
	}
}