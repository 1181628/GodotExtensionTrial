#ifndef PLAYER_H
#define PLAYER_H

#include <godot_cpp/classes/character_body2d.hpp>

namespace godot {

class Player : public CharacterBody2D {
	GDCLASS(Player, CharacterBody2D)

private:
	double gravity = 580.0;

protected:
    //static：函数属于整个类，不属于某一个 Player 对象
    //void：函数不会返回结果
    //_bind_methods：Godot 规定使用的方法名称
	static void _bind_methods();

//表示下面的函数可以从类外部访问
public:
    //当一个 Player 对象被创建时，构造函数会执行
	Player();
    //当 Player 对象被销毁时执行
	~Player();

    //_ready()：节点准备完成时由 Godot 调用
    //override：表示我们正在重写父类已有的虚函数
	void _ready() override;
    //从上一个物理帧到当前物理帧经过了多少秒
	void _process(double delta) override;
};

}

#endif