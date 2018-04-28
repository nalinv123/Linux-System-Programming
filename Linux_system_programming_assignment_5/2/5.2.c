//
//  5.c
//  
//
//  Created by Nalin on 28/04/18.
//

#include "header.h"

int main()
{
    int pid = 0;
    int priority = 0;
    int iRet = 0;
    
    pid = getpid();
    priority = getpriority(PRIO_PROCESS, pid);
    
    printf("Process Priority before change : %d\n", priority);
    
    iRet = setpriority(PRIO_PROCESS, pid, -10);
    
    priority = getpriority(PRIO_PROCESS, pid);
    
    printf("Process Priority after change : %d\n", priority);
    
    return 0;
}
