#include "GameObject.h"

#include <algorithm>

#include "../Debug/ConsoleLog.h"
#include "Renderables/Transformation.h"


namespace LM
{

	void GameObject::Add(std::shared_ptr<GameObject> object)
	{
		m_GameObjects.push_back(object);
		object->m_Prev = this;
	}

	void GameObject::Add(std::shared_ptr<Renderable> renderable)
	{
		m_Renderables.push_back(renderable);
	}

	void GameObject::Remove()
	{
		if (!m_Prev)
		{
			LOGW("GameObject has no root node!");
			return;
		}
		auto ptr = std::find_if(m_Prev->m_GameObjects.begin(), m_Prev->m_GameObjects.end(), [&](std::shared_ptr<GameObject> go) {
			return go.get() == this;
			});
		if (ptr != m_Prev->m_GameObjects.end())
			m_Prev->m_GameObjects.erase(ptr);
	}

	void GameObject::Remove(std::shared_ptr<Renderable> renderable)
	{
		auto ptr = std::find(m_Renderables.begin(), m_Renderables.end(), renderable);

		if (ptr != m_Renderables.end())
			m_Renderables.erase(ptr);
	}

	void GameObject::Remove(Renderable* renderable)
	{
		auto ptr = std::find_if(m_Renderables.begin(), m_Renderables.end(), [&](std::shared_ptr<Renderable> r) {
			return r.get() == renderable;
			});
		if (ptr != m_Renderables.end())
			m_Renderables.erase(ptr);
	}

}