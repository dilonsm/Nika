#include "nkpch.h"
#include "CollisionManager.h"

namespace Nika
{
	CollisionManager& CollisionManager::getInstance()
	{
		static CollisionManager instance;
		return instance;
	}
	
	void CollisionManager::addCollider(BoundingBox bbox)
	{
		// add collider to vector
		m_Colliders.push_back(bbox);
	}

	bool CollisionManager::checkCollision(const BoundingBox& box)
	{
		for (const BoundingBox& collider : m_Colliders)
		{
			if (CheckCollisionBoxes(box, collider))
			{
				return true; // Collision detected
			}
		}

		return false; // No collision detected
	}
}

