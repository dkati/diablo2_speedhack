#include <windows.h>
#include <psapi.h>
#include "printer.h"

int main()
{
    DWORD allProcs[1024], needsCB;

    if (!EnumProcesses(allProcs, sizeof(allProcs), &needsCB))
        return 1;

    printPIDs(allProcs, needsCB);

    return 0;
}
