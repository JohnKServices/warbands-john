#include "warband.h"

wb::game_data* warband = nullptr;

bool warband_init()
{
	rgl::check_types();
	wb::check_types();

	const char* cheatmenu = (const char*)(0x008177BC);
	const char* cheat_ui = (const char*)(0x0082274C);
	cheat_ui = "abcdefghhijklmno";
	cheatmenu = "abcde1234"; // override cheatmenu 

	std::ifstream file("C:\\Program Files (x86)\\Mount&Blade Warband\\Modules\\Native\\menus.txt", std::ios::in);
	std::string line;
	while (std::getline(file, line))
	{
		if (line.find("mno_tutorial_cheat  1 31 2 1 1") != std::string::npos)
		{
			return 1;
		}
	}

	warband = (wb::game_data*)(wb::addresses::game_data_ptr);
	return 0;
}

std::string getTime()
{
	return std::to_string(warband->cur_game->hour);
}