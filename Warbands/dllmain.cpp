// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include "warband.h"

#pragma comment(lib, "WarbandLib.lib")
#pragma comment(lib, "detours.lib")

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef void(__thiscall* EXEC_CONSOLE_CMD)(DWORD_PTR* a1, DWORD_PTR* a2);
EXEC_CONSOLE_CMD execCommand = (EXEC_CONSOLE_CMD)(0x4DB0B0);

typedef void(__thiscall* UPDATE_TIME_PNT)(void* a1, float a2);
UPDATE_TIME_PNT updateTime = (UPDATE_TIME_PNT)(0x5DCE30);

typedef void(__thiscall* sub_40E810)(void** thisptr);
typedef void(__thiscall* sub_4527C0)(void* thisptr);
extern "C" {
    sub_4527C0 sub_4527C0Func = (sub_4527C0)(0x4527C0);
}

__declspec(naked) void deallocateMemory(void** thisptr)
{
    __asm
    {
        mov     eax, [ecx + 4]
        add     ecx, 10h; Add
        cmp     eax, ecx
        jz      RETURN
        push    eax
        call    free
        pop     ecx
        jmp RETURN
        RETURN: retn
    }
}

extern "C"
{
    void __stdcall printToFile(const char* text)
    {
		ofstream myfile;
		myfile.open("C:\\Users\\veniv\\Downloads\\Reversing\\IDA Pro 7.5 SP3(x86, x64, ARM, ARM64, PPC, PPC64, MIPS)\\text.txt", ios::out);

		if (myfile)
		{
			myfile << text;
		}
		myfile.close();
    }
}

void __fastcall updateTime_H(DWORD_PTR* a1, float a2)
{
    float* timeScale = (float*)((uintptr_t)a1 + 0x16250);
    int* timeScale2 = (int*)((uintptr_t)a1 + 0x14224);
    *timeScale = 1.f / 120;
    *timeScale2 = 2;
    updateTime(a1, a2);
}

__declspec(naked) int execCommand_H(DWORD_PTR* a1, DWORD_PTR* a2)
{
	DWORD_PTR* cursor;
	char* command;
	__asm
	{
		sub esp, 0x120
		push ebp
		push esi
		mov esi, dword ptr ss : [esp + 0x12C]
		mov ebp, ecx
		push esi
		lea ecx, dword ptr ss : [esp + 0x9C]
		mov cursor, esi;
		call deallocateMemory
	}
	command = (char*)cursor + 0x10;
	printToFile(command);
	__asm
	{
		pop edi
		lea ecx, dword ptr ss : [esp + 0x98]
		call sub_4527C0Func
		pop esi
		pop ebp
		add esp, 0x120
		ret 4
	}
}

void OnAttach() {
    if(warband_init()) exit(1);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    static HANDLE hThread;

    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:

        DetourTransactionBegin();
        DetourUpdateThread(GetCurrentThread());
        DetourAttach(&(LPVOID&)updateTime, &updateTime_H);
        DetourAttach(&(LPVOID&)execCommand, &execCommand_H);
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