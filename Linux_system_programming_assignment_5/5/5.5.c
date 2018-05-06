#include "header.h"

int main(int argc, char *argv)
{
    char *name = NULL;
    char *home = NULL;
    
    name = getenv("USERNAME");
    printf("Username : %s\n", name);
    
    home = getenv("HOME");
    printf("Home directory : %s\n", home);
    
    return 0;
}
