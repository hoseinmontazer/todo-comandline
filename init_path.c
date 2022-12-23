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

#include "init_path.h"






void init_path( char home_user_dir[], char foldername [], char filename[] )
{
    char filepath[500];
    //char *user_file_path;
    char user_file_path[500];
    char ch;
    int i;




    strncat(home_user_dir,&*foldername,200);
    strncat(filepath,&*home_user_dir,200);
    strncat(filepath,&*filename,200);
    //printf("%s\n",filepath);
    printf("if you want initial to-do path please enter your path or empty that and press enter: (default path is ~/.todo/data.json):\n");
    //TO DO
    // add input path from
    i = 0;
    ch = getchar ();
    while(ch!='\n')
    {
        user_file_path[i] = ch;
        i++;
        ch = getchar();
    }
    user_file_path[i] ='\0';
    printf("Entered string is: %s\n", user_file_path);
    if (ch==0x0A)
    {
        printf("ENTER KEY is pressed.\n");
        printf("you choose default path is ~/.todo/data.json.\n");

    }
    printf("aaaaaa\n");


    DIR* dir = opendir(home_user_dir);
    if(!dir){
            if (mkdir(home_user_dir, S_IRWXU | S_IRWXG | S_IRWXO) == -1) {
                printf("Error: %s\n", strerror(errno));
            }
            else
            {
                if(access (filepath, F_OK) == -1)
                {
                    FILE*  file = fopen(filepath ,"w");
                    fprintf(file, "#init data file for todo app command line \n");
                    printf("create data file sucssesfully in %s .\n", filepath);

                }
            }
    }
    else if(access (filepath, F_OK) == -1)
    {
        printf("%s\n",filepath);
        printf("data file is not existed. init data file\n");
        FILE*  file = fopen(filepath ,"w");
        fprintf(file, "#init data file for todo app command line \n");
        printf("create data file sucssesfully in %s .\n", filepath);

    }
    else
    {
       printf("data file is exsited in %s .\n", filepath);
    }



	
	
}