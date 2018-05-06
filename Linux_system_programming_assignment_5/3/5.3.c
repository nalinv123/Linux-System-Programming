//
//  5.c
//  
//
//  Created by Nalin on 28/04/18.
//

#include "header.h"

int main()
{
    int iRet = 0;
    
    iRet = sched_yield();
    
    if (iRet == 0) {
        printf("Processor yiedld successfully\n");
    }
    else
    {
        printf("Processor yiedld not successfull\n");
    }
    
    return 0;
}
