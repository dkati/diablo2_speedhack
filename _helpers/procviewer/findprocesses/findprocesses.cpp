#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>
#include <string>
#include <iostream>

int main()
{
    // Get the list of process identifiers.

    DWORD allProcs[1024], needsCB, countProcs;
    unsigned int i;

    if (!EnumProcesses(allProcs, sizeof(allProcs), &needsCB))
        return 1;

    countProcs = needsCB / sizeof(DWORD);

    for (i = 0; i < countProcs; i++)
    {
        if (allProcs[i] != 0)
            _tprintf(TEXT("PID: %u\n"), allProcs[i]);
    }

    return 0;
}
