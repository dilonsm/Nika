#include "nkpch.h"
#include "Renderer.h"

namespace Nika
{
	Renderer::Renderer(CameraManager& cam, GUI& gui, Player& player)
		:m_CamManager(cam), m_Gui(gui), m_Player(player)
	{
		m_Player.initPlayer(m_Player.getPosition(), m_CamManager);
	}

	// --- RENDERING AND DRAWING ---
	void Renderer::drawScene()
	{
		DrawPlane(Vector3{ 0.0f, 0.0f, 0.0f }, Vector2{ 10.0f, 10.0f }, LIGHTGRAY);
		DrawCube(Vector3{ 0.0f, 0.5f, 0.0f }, 1.0f, 1.0f, 1.0f, RED);
	}

	// --- UPDATE ---
	void Renderer::renderUpdate(float dt)
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

			if (m_CamManager.isPlayerMode())
			{
				BeginMode3D(m_CamManager.getPlayerCamera());
				
				drawPlayer();
				m_Player.updatePlayer(dt);
			}
			else
			{
				BeginMode3D(m_CamManager.getWorldCamera());
				m_CamManager.updateWorldCamera();
			}

			drawScene();

			EndMode3D();

		// --- 2D stuff regarding GUI needs to be drawn after this comment ---
		DrawFPS(10, 10);

		m_Gui.drawReticle();

		EndDrawing();
	}

	void Renderer::drawPlayer()
	{
		Vector3 playerPos = m_Player.getPosition();

		Vector3 cubeOffset = { 0.0f, 0.5f, 0.0f }; // --- cube is 1,1,1 and the origin is in the middle ---
		DrawCube((playerPos + cubeOffset), 1.0f, 1.0f, 1.0f, RED);
	}
}

