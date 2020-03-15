#include <windows.h>
#include <iostream>
#include <psapi.h>
#include "printer.h"

void printProcsAndPIDs(DWORD* procs, DWORD needsCB) {

    DWORD countProcs = needsCB / sizeof(DWORD);
    TCHAR procName[MAX_PATH] = L"<Hidden name>";

    // proc handle
    HANDLE hProc;

    for (unsigned int i = 0; i < countProcs; i++)
    {
        if (procs[i] != 0) {
            // Grab proc handle
            hProc = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, procs[i]);
            if (hProc != NULL) {

                HMODULE hModule;
                DWORD bytesNeeded;

                // Retrieves a handle for each module in the specified process.
                if (EnumProcessModules(hProc, &hModule, sizeof(hModule), &bytesNeeded))
                    GetModuleBaseName(hProc, hModule, procName, sizeof(procName) / sizeof(TCHAR)); // get proc name

                std::wcout << "Process : " << procName << " ( " << procs[i] << " )" << std::endl;

                // Release the proc handle 
                CloseHandle(hProc);
            }
        }

    }
}