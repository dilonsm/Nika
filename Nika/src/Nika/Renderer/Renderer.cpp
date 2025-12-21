#include "nkpch.h"
#include "Renderer.h"

namespace Nika
{
	// --- BEGINNING ---
	void Renderer::beginScene(Camera& camera)
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);

		BeginMode3D(camera.getRaylibCamera());
	}

	// --- DRAWING ---
	void Renderer::drawScene()
	{
		DrawPlane(Vector3{ 0.0f, 0.0f, 0.0f }, Vector2{ 10.0f, 10.0f }, LIGHTGRAY);
		DrawCube(Vector3{ 0.0f, 0.5f, 0.0f }, 1.0f, 1.0f, 1.0f, RED);
		DrawCubeWires(Vector3{ 0.0f, 0.5f, 0.0f }, 1.0f, 1.0f, 1.0f, MAROON);
	}

	// --- ENDING ---
	void Renderer::endScene()
	{
		EndMode3D();
		EndDrawing();
	}
	
	// --- UPDATE ---
	void Renderer::renderUpdate(Camera& camera)
	{
		beginScene(camera);
		drawScene();
		endScene();
	}
}

