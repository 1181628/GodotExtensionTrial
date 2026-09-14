#include "gameCamera.h"

#include <godot_cpp/core/math.hpp>
#include <godot_cpp/variant/vector2.hpp>

#include <cstdlib>

using namespace godot;

GameCamera::GameCamera() {
}

GameCamera::~GameCamera() {
}

void GameCamera::_bind_methods() {
}

void GameCamera::_ready() {
}

void GameCamera::_process(double delta) {
    // Creates a random position between -strength and strength
    double randomX = -strength + (static_cast<double>(rand()) / RAND_MAX) * strength * 2;
    double randomY = -strength + (static_cast<double>(rand()) / RAND_MAX) * strength * 2;
    // Moves the camera by the generated random offset
    set_offset(Vector2(randomX, randomY));
    // Gradually reduces the shake strength until it reaches zero
    strength = Math::move_toward(strength, 0.0, recoverySpeed * delta);
}

// Sets the shake strength to a small amount
void GameCamera::camera_shake_small() {
    strength = 1.0;
    recoverySpeed = 20.0;
}

// Sets the shake strength to a larger amount
void GameCamera::camera_shake_big() {
    strength = 3.0;
    recoverySpeed = 20.0;
}

// Sets the shake strength to a very larger amount
void GameCamera::camera_shake_verybig() {
    strength = 5.0;
    recoverySpeed = 20.0;
}