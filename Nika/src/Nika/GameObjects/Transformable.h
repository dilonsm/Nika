#pragma once

#include <raylib.h>
#include <raymath.h>

namespace Nika
{
    class Transformable
    {
    public:
        Transformable() = default;
        virtual ~Transformable() = default;

        // getter
        const Vector3& getPosition() const   { return m_Position; }
        float getYaw()   const               { return m_Yaw;      }
        float getPitch() const               { return m_Pitch;    }

        // setter
        void setPosition(const Vector3& pos) { m_Position = pos; }
        void setYaw(float yaw)               { m_Yaw   = yaw;    }
        void setPitch(float pitch)           { m_Pitch = pitch;  }

    protected:
        Vector3 m_Position { 0.0f, 0.0f, 0.0f };
        float   m_Yaw   = 0.0f;
        float   m_Pitch = 0.0f;
    };
}

