#include "nkpch.h"
#include "Renderer.h"

namespace Nika
{
	Renderer::Renderer(CameraManager& cam, GUI& gui)
		:m_CamManager(cam), m_Gui(gui)
	{
	}

	// --- RENDERING AND DRAWING ---
	void Renderer::drawScene()
	{
		DrawPlane(Vector3{ 0.0f, 0.0f, 0.0f }, Vector2{ 10.0f, 10.0f }, LIGHTGRAY);
		DrawCube(Vector3{ 0.0f, 0.5f, 0.0f }, 1.0f, 1.0f, 1.0f, RED);
		DrawCubeWires(Vector3{ 0.0f, 0.5f, 0.0f }, 1.0f, 1.0f, 1.0f, MAROON);
	}

	// --- UPDATE ---
	void Renderer::renderUpdate()
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		BeginMode3D(m_CamManager.getPlayerCamera());
		// BeginMode3D(m_CamManager.getWorldCamera());

		// --- choose a camera by removing comments. ---
		// --- camera update ---
		m_CamManager.updatePlayerCamera(); 
		// m_CamManager.updateWorldCamera();

		drawScene();

		EndMode3D();

		// ! --- 2D stuff regarding GUI needs to be drawn after 3D Mode --- !
		DrawFPS(10, 10);

		m_Gui.drawReticle();

		EndDrawing();
	}
}

