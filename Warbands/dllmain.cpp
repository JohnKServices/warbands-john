// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include "warband.h"

#pragma comment(lib, "WarbandLib.lib")

#include <iostream>
#include <fstream>

using namespace std;


void OnAttach() {
    ofstream myfile;
    myfile.open("test.txt");
    myfile << warband->basic_game.game_download_url;
    myfile.close();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    static HANDLE hThread;

    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)OnAttach, NULL, NULL, NULL);
            break;
        case DLL_PROCESS_DETACH:
            if (hThread) {
                TerminateThread(hThread, 0);
            }
            break;
    }
    return TRUE;
}
