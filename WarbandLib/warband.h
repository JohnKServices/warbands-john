#pragma once
#include <Windows.h>
#include <fstream>
#include <detours/detours.h>

#include "rgl.h"
#include "wb.h"

extern wb::game_data* warband;

bool warband_init();

void __fastcall updateTime_H(DWORD_PTR* a1, float a2);

std::string getTime();