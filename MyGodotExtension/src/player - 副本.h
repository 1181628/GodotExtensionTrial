// Fixed structure: prevents this header file from being included more than once
#ifndef PLAYER_H
#define PLAYER_H

// Fixed structure: includes the Godot C++ parent class that you want to inherit from
#include <godot_cpp/classes/character_body2d.hpp>

// Fixed structure: indicates that the following code belongs to the godot namespace
namespace godot {

// Fixed structure: creates a new class and inherits the features of its parent class
class Player : public CharacterBody2D {
	GDCLASS(Player, CharacterBody2D)

// Fixed structure: indicates that the following variables and functions
// can only be accessed directly from inside this class
private:
    // ==============================
    // Write yourself: variables that the game needs to store
	// For example:
	// double gravity = 580.0;
	// double move_speed = 200.0;
	// double jump_speed = 300.0;
	// int health = 100;
	// ==============================

// Fixed structure: indicates that the following functions
// can be accessed from outside the class
protected:
	static void _bind_methods();

// Fixed structure: indicates that the following functions
// can be accessed from outside the class
public:
    // Fixed structure: constructor and destructor
	Player();
	~Player();

    // Keep when needed: declares a function that runs once
	// when the node has finished being created
	void _ready() override;
    // Usually needed for character movement:
	// declares a function that runs during every physics frame
	void _process(double delta) override;
    // ==============================
	// Write yourself: declarations of other functions you create
	// For example:
	// void take_damage(int damage);
	// void jump();
	// void attack();
	// ==============================
};

}

#endif