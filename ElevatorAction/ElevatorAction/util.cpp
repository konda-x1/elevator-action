#include <cstdlib>

int randint(int min_val, int max_val)
{
	return rand() % (max_val - min_val + 1) + min_val;
}
