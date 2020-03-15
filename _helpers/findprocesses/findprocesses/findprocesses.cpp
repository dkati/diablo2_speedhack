#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <psapi.h>
#include <string>
#include <iostream>

int main()
{
    DWORD allProcs[1024], needsCB, countProcs;
    unsigned int i;

    if (!EnumProcesses(allProcs, sizeof(allProcs), &needsCB))
        return 1;

    countProcs = needsCB / sizeof(DWORD);

    for (i = 0; i < countProcs; i++)
    {
        if (allProcs[i] != 0) 
            std::wcout << "PID: " << allProcs[i] << std::endl;
       
    }

    return 0;
}
