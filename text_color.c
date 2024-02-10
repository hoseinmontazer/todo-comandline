#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <dirent.h>
#include <errno.h>
#include "tree_list_path.h"
#include "list_task.h"



void text_color( char color [] )
{
    // char Temp_Home_User_Dir [200];
    // printf ("lllllll\n"  );
    // strcat(Temp_Home_User_Dir,getenv("HOME"));
    // strcat(Temp_Home_User_Dir,"/.todo");
    //printf(Temp_Home_User_Dir,"\n");
    // DIR *d;
    // struct dirent *dir;
    // d = opendir(Temp_Home_User_Dir);
    // tree_list_path(FULL_Todo_Path,getenv("HOME"),Todo_File_Name);


    if (strcmp( color ,"red") ==0)
    {
        printf("\033[1;31m");
    }
    else if (strcmp( color ,"blue") ==0)
    {
        printf("\033[0;34m");
    }
    else if (strcmp( color ,"blueb") ==0)
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