#include "nkpch.h"
#include "Player.h"

namespace Nika
{
	void Player::initPlayer(Vector3 pos, CameraManager& camMan)
	{
		m_PlayerData.Position = pos;
		m_PlayerData.Yaw   = 0.0f;
		m_PlayerData.Pitch = 0.0f;

		m_CamManager = &camMan;
	}

	void Player::updatePlayer(float dt)
	{
		updateRotation();
		updateMovement(dt);
		updateCamera();
	}

	void Player::updateRotation()
	{
		Vector2 mouseDelta = GetMouseDelta();
		const float sensitivity = 0.003f;

		m_PlayerData.Yaw   -= mouseDelta.x * sensitivity;
		m_PlayerData.Pitch -= mouseDelta.y * sensitivity;

		// pitch clamp to avoid flipping the camera
		m_PlayerData.Pitch = Clamp(m_PlayerData.Pitch, -1.5f, 1.5f);
	}

	void Player::updateMovement(float dt)
	{
		Vector2 input = { 0.0f, 0.0f };

		if (IsKeyDown(KEY_W)) input.y += 1.0f;
		if (IsKeyDown(KEY_A)) input.x += 1.0f;
		if (IsKeyDown(KEY_S)) input.y -= 1.0f;
		if (IsKeyDown(KEY_D)) input.x -= 1.0f;

		// checking for input
		float length = sqrtf(input.x * input.x + input.y * input.y);
		if (length <= 0.0f) return;

		// normalizing input
		input.x /= length;
		input.y /= length;

		Vector3 forward = {
			sinf(m_PlayerData.Yaw),
			0.0f,
			cosf(m_PlayerData.Yaw)
		};
		Vector3 right = {
			cosf(m_PlayerData.Yaw),
			0.0f,
			-sinf(m_PlayerData.Yaw)
		};

		Vector3 moveDir = {
			right.x * input.x + forward.x * input.y,
			0.0f,
			right.z * input.x + forward.z * input.y
		};

		m_PlayerData.Position.x += moveDir.x * m_PlayerData.Speed * dt;
		m_PlayerData.Position.z += moveDir.z * m_PlayerData.Speed * dt;
	}

	void Player::updateCamera()
	{
		Camera3D& cam = m_CamManager->getPlayerCamera();

		// “head” offset (height of eyes above character origin)
		const Vector3 headOffset = { 0.0f, 1.8f, 0.0f };

		cam.position = Vector3Add(m_PlayerData.Position, headOffset);

		// compute forward vector from yaw + pitch
		Vector3 forward = {
			cosf(m_PlayerData.Pitch) * sinf(m_PlayerData.Yaw),
			sinf(m_PlayerData.Pitch),
			cosf(m_PlayerData.Pitch) * cosf(m_PlayerData.Yaw)
		};

		cam.target = Vector3Add(cam.position, forward);
		cam.up = { 0.0f, 1.0f, 0.0f };
	}
}

