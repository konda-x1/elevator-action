#include "EnemyBullet.hpp"
#include "Bullet.hpp"
#include "Level.hpp"
#include "CollisionHelper.hpp"
#include "Enemy.hpp"

EnemyBullet::EnemyBullet(Enemy *enemy, float vx, float vy) : Bullet(enemy->level, enemy->gun_fx(), enemy->gun_fy(), vx, vy), enemy(enemy)
{
	this->r = 1.0f;
	this->g = 0.65f;
	this->b = 0.0f;
}


EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::process(float delta)
{
	float dx = this->dx(delta);
	float dy = this->dy(delta);
	if (CollisionHelper::collides_with_solid(&this->hitbox, dx, dy, this->level->hitboxes)) {
		this->level->despawn_bullet(this);
	}
	else {
		this->fx += this->dx(delta);
		this->fy += this->dy(delta);
	}
}
