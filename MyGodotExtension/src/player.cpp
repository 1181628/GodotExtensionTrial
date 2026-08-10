#include "player.h"

#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/engine.hpp>

using namespace godot;

Player::Player() {
}

Player::~Player() {
}

void Player::_bind_methods() {
}

void Player::_ready() {
}


void Player::_physics_process(double delta) {
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }

    Input * input = Input::get_singleton();
    Vector2 velocity = get_velocity();

    // gravity
    if (!is_on_floor()) {
        velocity.y += gravity * delta;
    }

    // jump
    if (input->is_action_just_pressed("jump") && is_on_floor()) {
        velocity.y = vertical_acceleration;
    }

    // move left and right
    double moveVector_x = input->get_axis("move_left", "move_right");
    velocity.x += moveVector_x * horizontal_acceleration * delta;
    if (velocity.x < -maxHorizontalSpeed) {
        velocity.x = -maxHorizontalSpeed;
    }
    if (velocity.x > maxHorizontalSpeed) {
        velocity.x = maxHorizontalSpeed;
    }

    if (velocity.x == 0) {
        velocity.x = velocity.x / 2 * delta;
    }

    set_velocity(velocity);
    move_and_slide();
}