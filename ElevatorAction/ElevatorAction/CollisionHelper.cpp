#include <assert.h>
#include "CollisionHelper.hpp"
#include "Hitbox.hpp"
#include "util.hpp"


CollisionHelper::CollisionHelper()
{
}


CollisionHelper::~CollisionHelper()
{
}

bool CollisionHelper::will_collide(AbstractHitbox * moving_hitbox, float dx, float dy, AbstractHitbox * standing_hitbox)
{
	Hitbox moved_hitbox = Hitbox(moving_hitbox->x1() + dx, moving_hitbox->y1() + dy, moving_hitbox->x2() + dx, moving_hitbox->y2() + dy, moving_hitbox->solid);
	return moved_hitbox.intersects(standing_hitbox);
}

AbstractHitbox * CollisionHelper::collides_with_solid(AbstractHitbox * moving_hitbox, float dx, float dy, std::vector<AbstractHitbox*> hitboxes)
{
	for (AbstractHitbox *h : hitboxes) {
		if (!h->solid || moving_hitbox == h) {
			continue;
		}
		if (will_collide(moving_hitbox, dx, dy, h)) {
			return h;
		}
	}
	return nullptr;
}

std::pair<float, float> CollisionHelper::move_nointersect(AbstractHitbox * moving_hitbox, float dx, float dy, AbstractHitbox * standing_hitbox)
{
	if (standing_hitbox == nullptr || !will_collide(moving_hitbox, dy, dy, standing_hitbox)) {
		return std::make_pair(dx, dy);
	}
	else if (moving_hitbox->intersects(standing_hitbox)) {
		throw std::exception("Hitboxes already intersect");
	}

	// This fllowing code only works properly if the hitboxes do not already intersect and a collission is guaranteed
	assert(!moving_hitbox->intersects(standing_hitbox));
	assert(will_collide(moving_hitbox, dy, dy, standing_hitbox));
	
	float collision_hd, collision_vd; // Horizontal and vertical distance from collision
	if (dx == 0)
		collision_hd = -1.0f; // Infinite
	else
		collision_hd = (dx > 0 ? standing_hitbox->left() - moving_hitbox->right() : moving_hitbox->left() - standing_hitbox->right());

	if (dy == 0)
		collision_vd = -1.0f; // Infinite
	else
		collision_vd = (dy > 0 ? standing_hitbox->bottom() - moving_hitbox->top() : moving_hitbox->bottom() - standing_hitbox->top());

	// At most one collission distance (horizontal or vertical) may be infinite
	assert(collision_hd >= 0.0f || collision_vd >= 0.0f);
	float scale;
	if (collision_hd < 0.0f || collision_vd < collision_hd) { // Vertical foremost collision
		assert(collision_vd <= dy); // Sanity check for vertical collission
		scale = collision_vd / dy;
	}
	else if (collision_vd < 0.0f || collision_hd <= collision_vd) { // Horizontal foremost or both vertical and horizontal collision (<=)
		assert(collision_hd <= dx); // Sanity check for horizontal collission
		scale = collision_hd / dx;
	}

	assert(0.0f <= scale && scale <= 1.0f); // Sanity check for scale
	return std::make_pair(scale * dx, scale * dy);
}

std::pair<float, float> CollisionHelper::move_and_collide(AbstractHitbox * moving_hitbox, float dx, float dy, std::vector<AbstractHitbox*> standing_hitboxes, bool solid_only)
{
	auto current_xy = std::make_pair(dx, dy);
	if (solid_only && !moving_hitbox->solid) {
		return current_xy;
	}
	auto *min_xy = &current_xy;
	for (AbstractHitbox *h : standing_hitboxes) {
		if (solid_only && !h->solid) {
			continue;
		}
		auto new_xy = CollisionHelper::move_nointersect(moving_hitbox, dx, dy, h);
		if (v2len(new_xy) < v2len(*min_xy)) {
			min_xy = &new_xy;
		}
	}
	return *min_xy;
}
