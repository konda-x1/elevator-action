#include "PlayerBullet.hpp"
#include "Bullet.hpp"
#include "Level.hpp"
#include "CollisionHelper.hpp"

PlayerBullet::PlayerBullet(Level *level, float vx, float vy) : Bullet(level, level->player->gun_fx(), level->player->gun_fy(), vx, vy)
{
	this->r = 1.0f;
	this->g = 0.65f;
	this->b = 0.0f;
}


PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::process(float delta)
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