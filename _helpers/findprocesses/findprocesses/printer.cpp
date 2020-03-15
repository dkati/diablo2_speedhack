#include <windows.h>
#include <iostream>
#include "printer.h"

void printPIDs(DWORD* procs, DWORD needsCB) {

    DWORD countProcs = needsCB / sizeof(DWORD);
    for (unsigned int i = 0; i < countProcs; i++)
    {
        if (procs[i] != 0)
            std::wcout << "PID: " << procs[i] << std::endl;

    }
}