#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>
#include <string>
#include <iostream>
#include "printer.h"

int main()
{
    DWORD allProcs[1024], needsCB, countProcs;
    unsigned int i;

    if (!EnumProcesses(allProcs, sizeof(allProcs), &needsCB))
        return 1;

    countProcs = needsCB / sizeof(DWORD);

    printPIDs(allProcs,countProcs);

    return 0;
}
