//读取 player.h
#include "player.h"

#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

Player::Player() {
	// 相当于 GDScript 中创建变量时设置：
	// var gravity = 580
	gravity = 580.0;
}

Player::~Player() {
}

void Player::_bind_methods() {
}

void Player::_ready() {
	// 相当于 GDScript 中的 pass
}

void Player::_process(double delta) {
	// 目前没有使用 delta，防止编译器产生警告
	(void)delta;

	// 取得 CharacterBody2D 自带的 velocity
	Vector2 velocity = get_velocity();

	// 相当于 GDScript：velocity.y = 10
	velocity.y = 10.0;

	// 将修改后的 velocity 放回 CharacterBody2D
	set_velocity(velocity);

	// 相当于 GDScript：move_and_slide()
	move_and_slide();
}