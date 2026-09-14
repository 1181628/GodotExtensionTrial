// game_camera.h
#ifndef GAMECAMERA_H
#define GAMECAMERA_H

#include <godot_cpp/classes/camera2d.hpp>

namespace godot {

class GameCamera : public Camera2D {
    GDCLASS(GameCamera, Camera2D)

private:
	double strength = 0.0;
    double recoverySpeed = 20.0;

protected:
    static void _bind_methods();

public:
    GameCamera();
    ~GameCamera();

    void _ready() override;
    void _process(double delta) override;

    void camera_shake_small();
    void camera_shake_big();
};

}

#endif