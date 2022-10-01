// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include "warband.h"

#pragma comment(lib, "WarbandLib.lib")
#pragma comment(lib, "detours.lib")

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef void(__thiscall* UPDATE_TIME_PNT)(void* a1, float a2);
UPDATE_TIME_PNT updateTime = (UPDATE_TIME_PNT)(0x5DCE30);

void __fastcall updateTime_H(DWORD_PTR* a1, float a2)
{
    float* timeScale = (float*)((uintptr_t)a1 + 0x16250);
    int* timeScale2 = (int*)((uintptr_t)a1 + 0x14224);
    *timeScale = 1.f / 120;
    *timeScale2 = 2;
    updateTime(a1, a2);
}

void OnAttach() {
    warband_init();
    ofstream myfile;
    myfile.open("C:\\Users\\veniv\\Downloads\\Reversing\\IDA Pro 7.5 SP3(x86, x64, ARM, ARM64, PPC, PPC64, MIPS)\\txt.txt", ios::out);
    
    if (myfile)
    {
        myfile << getName();
    }
    myfile.close();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    static HANDLE hThread;

    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:

            DetourTransactionBegin();
            DetourUpdateThread(GetCurrentThread());
            DetourAttach(&(LPVOID&)updateTime, &updateTime_H);
            DetourTransactionCommit();
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
