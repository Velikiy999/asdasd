#include <stdio.h>
#include "Game.h"
#include <locale>


long long *n, *m;


int main(void)

{
	setlocale(LC_CTYPE, "ukr");

	Game *game = new Game();
	game->Play();

	return 0;
}