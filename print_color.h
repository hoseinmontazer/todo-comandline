#include <stdio.h>
#include <stdio.h>
// #include <string.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <unistd.h>
// #include <string.h>
// #include <stdlib.h>
// #include <dirent.h>
// #include <stdbool.h>




void  print_color( char color []) {
    if (strcmp( color ,"red") ==0)
    {
        printf("\033[1;31m");
    }
    else if (strcmp( color ,"blue") ==0)
    {
        printf("\033[0;34m");
    }
    else if (strcmp( color ,"yellow") ==0)
    {
        printf("\033[1;33m");
    }
    else if (strcmp( color ,"green") ==0)
    {
        printf("\033[0;32m");
    }
    else if (strcmp( color ,"reset") ==0)
    {
        printf("\033[0m");
    }
    else
    {
        printf("\033[0;37m");
    }

    
}