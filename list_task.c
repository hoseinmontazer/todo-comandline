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



void list_task( char FULL_Todo_Path[],char Home_User_Dir[], char Todo_File_Name [] )
{
    char Temp_Home_User_Dir [200];
    strcat(Temp_Home_User_Dir,getenv("HOME"));
    strcat(Temp_Home_User_Dir,"/.todo");
    //printf(Temp_Home_User_Dir,"\n");
    DIR *d;
    struct dirent *dir;
    d = opendir(Temp_Home_User_Dir);
    tree_list_path(FULL_Todo_Path,getenv("HOME"),Todo_File_Name);
}