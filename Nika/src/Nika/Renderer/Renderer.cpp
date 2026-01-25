#include "nkpch.h"
#include "Renderer.h"

namespace Nika
{
	Renderer::Renderer(CameraManager& cam, GUI& gui)
		:m_CamManager(cam), m_Gui(gui)
	{
	}

	// --- RENDERING AND DRAWING ---
	void Renderer::drawScene(Player& player)
	{
		Vector3 playerPos = player.getPosition();

		Vector3 cubeOffset = { 0.0f, 0.5f, 0.0f }; // --- cube is 1,1,1 big and origin is in the middle ---
		DrawCube((playerPos + cubeOffset), 1.0f, 1.0f, 1.0f, RED);

		DrawPlane(Vector3{ 0.0f, 0.0f, 0.0f }, Vector2{ 10.0f, 10.0f }, LIGHTGRAY);
		DrawCube(Vector3{ 0.0f, 0.5f, 0.0f }, 1.0f, 1.0f, 1.0f, RED);
	}

	// --- UPDATE ---
	void Renderer::renderUpdate(Player& player)
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		// --- choose a camera by removing comments ---

			BeginMode3D(m_CamManager.getPlayerCamera());

			// BeginMode3D(m_CamManager.getWorldCamera());
			// m_CamManager.updateWorldCamera();

			drawScene(player);

			EndMode3D();

		// --- 2D stuff regarding GUI needs to be drawn after this comment ---
		DrawFPS(10, 10);

		m_Gui.drawReticle();

		EndDrawing();
	}
}

