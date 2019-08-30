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
class Level : public Usable
{
	std::vector<LevelObject *> objects = std::vector<LevelObject *>();
	std::vector<class PlayerSpawnPoint *> spawns = std::vector<class PlayerSpawnPoint *>();
	std::set<std::pair<int, int>> occupied = std::set<std::pair<int, int>>();
	std::set<std::pair<int, int>> elevator_occupied = std::set<std::pair<int, int>>();
	std::set<std::pair<int, int>> platform_occupied = std::set<std::pair<int, int>>();
	class Player *player;
	bool built = false;

	int remaining_free();
	void generate_missing();
	void generate_missing_spawnpoint();
	void generate_roof();
	void generate_missing_doors();
	void generate_missing_platforms();
	void insert_document_doors();
	class Player *spawn(class Player *player);
public:
	class LevelManager *manager = nullptr;
	int width;
	int height;
	int document_doors;

	Level(int width, int height, int document_doors, Player *player = nullptr);
	~Level();

	int size();
	void add_elevator(Elevator *e);
	void add_platform(int x, int y);
	void add_spawnpoint(int x, int y);
	void add_xy(SingleFloorLevelObject *sflo);
	void set_player(Player *player);
	void check_usable() override;
	void process(float delta);
	void render(float delta);
	void build();
};

