#pragma once

// --- defines for conflicts between raylib and windows header files ---
#define WIN32_LEAN_AND_MEAN
#define NOGDI
#define NOUSER
#define NOMINMAX

// --- standard includes ---
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>
#include <iostream>
#include <sstream>

#include <array>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// --- core includes ---
#include "Nika/Core/Base.h"
#include "Nika/Core/Log.h"

