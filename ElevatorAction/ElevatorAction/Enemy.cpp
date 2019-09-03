#include <iostream>
#include "glut/glut.h"
#include "Game.hpp"
#include "Enemy.hpp"
#include "util.hpp"
#include "CollisionHelper.hpp"
#include "Door.hpp"
#include "EnemyBullet.hpp"

Enemy::Enemy()
{
	this->hitbox = new EnemyHitbox(this);
}

Enemy::Enemy(Level *level, float fx, float fy, Orientation orientation): level(level), fx(fx), fy(fy), orientation(orientation)
{
	Enemy();
}


Enemy::~Enemy()
{
}

float Enemy::dfx(float delta)
{
	return this->velx * delta;
}

float Enemy::dfy(float delta)
{
	return this->vely * delta;
}

float Enemy::gun_fx()
{
	return (this->hitbox->left() + this->hitbox->right()) / 2.0f + (float)this->orientation * this->width;
}

float Enemy::gun_fy()
{
	return this->fy + this->height * 0.75f;
}

void Enemy::fire()
{
	if (!this->firing) {
		std::cout << "Enemy Firing" << std::endl;
		this->level->spawn_bullet(new EnemyBullet(this, (float)this->orientation * 2.0f));
		this->firing = true;
	}
}

void Enemy::die()
{
	this->level->despawn_enemy(this);
}

void Enemy::check_usable()
{
	if (this->level == nullptr)
		throw std::exception("Level is null");
}


void Enemy::elapse_fire(float delta)
{
	if (this->firing) {
		this->fire_elapsed += delta;
		if (this->fire_elapsed > this->fire_cooldown) {
			this->fire_elapsed = 0.0f;
			this->firing = false;
		}
	}
}

void Enemy::process(float delta)
{
	
}

void Enemy::render_gun()
{
	float middle_h = this->gun_fy();
	float x1 = (this->hitbox->left() + this->hitbox->right()) / 2.0f + (float)this->orientation * this->width / 2.0f;
	float y1 = middle_h + 0.04f * this->height;
	float x2 = this->gun_fx();
	float y2 = middle_h - 0.04f * this->height;
	//std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << std::endl;
	//std::cout << this->orientation << std::endl;
	glColor3f(0.55f, 0.27f, 0.075f); // Brown
	glRectf(x1, y1, x2, y2);
}

void Enemy::render(float delta)
{
	this->check_usable();

	this->hitbox->render(delta, 0.0f, 0.8f, 0.0f);
	this->render_gun();
}
