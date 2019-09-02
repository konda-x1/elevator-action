#pragma once
#include <vector>
#include <set>
#include <utility>
#include "Usable.hpp"
#include "LevelObject.hpp"
#include "SingleFloorLevelObject.hpp"
#include "PlayerSpawnPoint.hpp"
#include "Elevator.hpp"
#include "Player.hpp"

class PlayerSpawnPoint;
class LevelManager;
class Level : public Usable
{
	std::vector<LevelObject *> objects = std::vector<LevelObject *>();
	std::vector<PlayerSpawnPoint *> spawns = std::vector<PlayerSpawnPoint *>();
	std::set<std::pair<int, int>> occupied = std::set<std::pair<int, int>>();
	std::set<std::pair<int, int>> elevator_occupied = std::set<std::pair<int, int>>();
	std::set<std::pair<int, int>> platform_occupied = std::set<std::pair<int, int>>();
	Player *player;
	bool built = false;

	int remaining_free();
	void generate_missing();
	void generate_missing_spawnpoint();
	void generate_roof();
	void generate_missing_doors();
	void generate_missing_platforms();
	void insert_document_doors();
	Player *spawn(Player *player = nullptr);
	void add_exit();
	void add_hitboxes();
public:
	LevelManager *manager = nullptr;
	std::vector<AbstractHitbox *> hitboxes = std::vector<AbstractHitbox *>();
	int width;
	int height;
	int document_doors;
	int document_doors_opened = 0;

	Level(int width, int height, int document_doors, Player *player = nullptr);
	~Level();

	int size();
	void add_elevator(Elevator *e);
	void add_platform(int x, int y);
	void add_spawnpoint(int x, int y);
	void add_xy(SingleFloorLevelObject *sflo);
	void set_player(Player *player = nullptr);
	void move_player(float dx, float dy);
	void check_usable() override;
	void transition_to(Level *level);
	void process(float delta);
	void render(float delta);
	void build();
};

