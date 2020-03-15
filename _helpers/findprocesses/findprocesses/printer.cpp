#include <windows.h>
#include <iostream>
#include "printer.h"

void printPIDs(DWORD* procs, DWORD procCount) {
    for (unsigned int i = 0; i < procCount; i++)
    {
        if (procs[i] != 0)
            std::wcout << "PID: " << procs[i] << std::endl;

    }
}