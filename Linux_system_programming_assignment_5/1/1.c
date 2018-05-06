//
//  1.c
//  
//
//  Created by Nalin on 28/04/18.
//

#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

int main()
{
    int pid = 0, priority = 0;
    
    pid = getpid();
    
    priority = getpriority(PRIO_PROCESS, pid);
    
    printf("Process Priority : %d\n", priority);
    
    return 0;
}
