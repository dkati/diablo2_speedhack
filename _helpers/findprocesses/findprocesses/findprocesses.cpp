#include <windows.h>
#include <psapi.h>
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
