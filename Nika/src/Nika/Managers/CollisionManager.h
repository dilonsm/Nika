#pragma once

namespace Nika
{
	class CollisionManager
	{
	public:
		static CollisionManager& getInstance();

		void addCollider(const BoundingBox box);
		bool checkCollision(const BoundingBox& box);

	private:
		 CollisionManager() = default;
		~CollisionManager() = default;

		std::vector<BoundingBox> m_Colliders;
	};
}

