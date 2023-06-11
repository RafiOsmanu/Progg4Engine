#pragma once
#include <glm/glm.hpp>
#include <vector>
#include <memory>
#include "BaseComponent.h"
#include "Texture2D.h"
#include "ResourceManager.h"


namespace dae
{
	struct Cube
	{
		glm::vec2 position;  // The position of the cube in world space
		float size;          // The size of the cube
		glm::vec3 color;     // The color of the cube
		std::shared_ptr<Texture2D> texture;
	};

	class MapCreator : public BaseComponent
	{
		std::weak_ptr<GameObject> m_pOwner;
	public:
		
		explicit MapCreator(std::shared_ptr<GameObject> pOwner, int numRows);
		~MapCreator() = default;
		MapCreator(const MapCreator&) = delete;
		MapCreator(MapCreator&&) = delete;
		MapCreator& operator= (const MapCreator&) = delete;
		MapCreator& operator= (const MapCreator&&) = delete;

		//Fuctions

		void Update() override;
		void Render() override;

		void CreateMap();

	protected:
		std::weak_ptr<GameObject> GetOwner() const { return m_pOwner; }

	private:
		//DataMembers
		int m_NumRows;
		std::vector<Cube> m_Cubes;

	};
}

