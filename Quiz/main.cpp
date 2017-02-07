#include <memory>
#include "game.h"

using namespace std;
using namespace quiz;

int main() {

	unique_ptr<Game> game(new Game());
	game->start();

}