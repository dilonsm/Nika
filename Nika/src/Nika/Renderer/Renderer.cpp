#include "nkpch.h"
#include "Renderer.h"

namespace Nika
{
	// --- RENDERING AND DRAWING ---
	void Renderer::drawScene()
	{
		DrawPlane(Vector3{ 0.0f, 0.0f, 0.0f }, Vector2{ 10.0f, 10.0f }, LIGHTGRAY);
		DrawCube(Vector3{ 0.0f, 0.5f, 0.0f }, 1.0f, 1.0f, 1.0f, RED);
		DrawCubeWires(Vector3{ 0.0f, 0.5f, 0.0f }, 1.0f, 1.0f, 1.0f, MAROON);
	}

	// --- UPDATE ---
	void Renderer::renderUpdate(Camera& camera)
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		BeginMode3D(camera.getRaylibCamera());

		drawScene();

		EndMode3D();

		// ! --- 2D stuff regarding GUI needs to be drawn after 3D Mode --- !
		DrawFPS(10, 10);

		m_Gui.drawReticle();

		EndDrawing();
	}
}

