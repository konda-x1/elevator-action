#pragma once
#include "Level.hpp"
#include "EnemyHitbox.hpp"
#include "UserInput.hpp"

class Level;
class EnemyHitbox;
class Elevator;
class Door;
class Enemy : public Usable
{
	void elapse_fire(float delta);
public:
	float fx, fy; // Coordinates of the lower left point of the enemy
	float width = 0.2f, height = 0.5f;
	float velx = 0.0f, vely = 0.0f;
	float movement_speed = 1.0f;
	float fire_elapsed = 0.0f;
	float fire_cooldown = 1.5f;
	bool firing = false;
	enum Orientation {
		LEFT = -1,
		RIGHT = 1
	} orientation = RIGHT;
	Level *level = nullptr;
	EnemyHitbox *hitbox = nullptr;

	Enemy();
	Enemy(Level *level, float fx, float fy, Orientation orientation = Orientation::RIGHT);
	~Enemy();

	float dfx(float delta);
	float dfy(float delta);
	float gun_fx();
	float gun_fy();
	void fire();
	void die();
	void check_usable() override;
	void process(float delta);
	void render_gun();
	void render(float delta);
};

