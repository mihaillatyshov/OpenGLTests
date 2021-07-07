#if 1
#include <vector>

#include "Core/Window.h"
#include "Layers/ImGuiLayer.h"
#include "Layers/TestBoneAnimLayer.h"
#include "Layers/TrianglesLayer.h"
#include "Layers/RealBatchRendererLayer.h"
#include "Layers/Collision2DLayer.h"
#include <iostream>
#include "Core/Timer.h"
#include "Debug/Instrumentor.h"

#include "Core/Application.h"

std::ostream& operator<<(std::ostream& ostr, const glm::vec4 &vec)
{
	ostr << "{ " << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << " }";
	return ostr;
}




int main()
{
	PROFILE_BEGIN_SESSION("Runtime", "Profile-Runtime.json");
#if 1
	

	Application* app = new Application();

	app->Run();

	delete app;



#else

	class TestOBJ
	{
	public:
		TestOBJ(uint32_t tid, uint32_t vc)
			: TransformId(tid), VerticesCount(vc)
		{

		}
		uint32_t TransformId;
		uint32_t VerticesCount;
	};

	std::vector<std::shared_ptr<TestOBJ>> TestObjects;
	{
		PROFILE_SCOPE("Create Objects");
		for (int i = 0; i < 10'000; i++)
		{
			TestObjects.emplace_back(std::make_shared<TestOBJ>(i, 4 * 6));
		}
	}

	std::vector<int> TransformId;
	for (int c = 0; c < 100; c++)
	{
		PROFILE_SCOPE("Iteration");
		{
			TransformId.clear();
			TransformId.reserve(1'000'000);
			PROFILE_SCOPE("Add Transformations ids");
			for (int i = 0; i < TestObjects.size(); i++)
			{
				for (int j = 0; i < TestObjects[i]->VerticesCount; i++)
				{
					TransformId.push_back(TestObjects[i]->TransformId);
				}
			}
		}
	}

	system("pause");

#endif

	PROFILE_END_SESSION();
	return 0;
}

#else

#include <TestMultiDraw.h>

#endif