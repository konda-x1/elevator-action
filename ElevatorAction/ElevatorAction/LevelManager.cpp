#include <exception>
#include "LevelManager.hpp"


Level * LevelManager::current()
{
	if (this->levels.size() > 0)
		return this->levels.at(this->current_index);
	return nullptr;
}

LevelManager::LevelManager()
{
}


LevelManager::~LevelManager()
{
}

void LevelManager::add(Level *level)
{
	this->levels.push_back(level);
	level->manager = this;
}

bool LevelManager::go2next()
{
	if (!this->is_game_over()) {
		if ((unsigned)this->current_index < this->levels.size() - 1) {
			Level *current = this->levels.at(current_index);
			Level *next = this->levels.at(current_index + 1);
			current->transition_to(next);
			++this->current_index;
			
			return true;
		}
		this->game_over = true;
	}
	return false;
}

bool LevelManager::is_game_over() const
{
	return this->game_over;
}

void LevelManager::process(float delta)
{
	Level *current = this->current();
	if(current != nullptr)
		current->process(delta);
}

void LevelManager::render(float delta)
{
	Level *current = this->current();
	if (current != nullptr)
		current->render(delta);
}
