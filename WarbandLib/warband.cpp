#include "warband.h"

wb::game_data* warband = nullptr;

void warband_init()
{
	rgl::check_types();
	wb::check_types();

	const char* cheatmenu = (const char*)(0x008177BC);
	cheatmenu = "abcde1234"; // override cheatmenu 

	warband = (wb::game_data*)(wb::addresses::game_data_ptr);
}

std::string getTime()
{
	return std::to_string(warband->cur_game->hour);
}