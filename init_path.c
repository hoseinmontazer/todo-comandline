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
    
//TO DO 
/* 
there is two bug and feature
1) sometimes dont right check file path exist but file is existed - 87
2) befor init file path  should check that is avilable or not from  config file
*/



    printf("if you want initial to-do path please enter your path or empty that and press enter: (default path is ~/.todo/data.json):\n");
    i = 0;
    ch = getchar ();
    while(ch!='\n')
    {
        user_file_path[i] = ch;
        i++;
        ch = getchar();
    }
    user_file_path[i] ='\0';
    //printf(strlen(user_file_path));
    printf("your chosen pathllll is: %s\n", user_file_path);
    if (ch==0x0A && strlen(user_file_path)<1)
    {
        //printf("your chosen path is in enter: %s\n", user_file_path);
        //printf("ENTER KEY is pressed.\n");
        printf("you choose default path is ~/.todo/data.json.\n");
        strcpy(home_user_dir, home_user_dir);
        printf("first of  first directory %s\n",home_user_dir);


    }
    else
    {
        
        printf("your chosen path is: %s\n", user_file_path);
        strcpy(home_user_dir, user_file_path);
        printf("secound of  first directory %s\n",home_user_dir);

    }
    strncat(filepath,&*home_user_dir,200);
    strncat(filepath,&*filename,200);
    printf("thirth of  first directory %s\n",home_user_dir);
    printf("final  first filepath %s\n",filepath);
    
    DIR* dir = opendir(home_user_dir);
    
    //FILE *file;
    if(!dir){
            if (mkdir(home_user_dir, S_IRWXU | S_IRWXG | S_IRWXO) == -1) {
                printf("Error: %s\n", strerror(errno));
            }
            if(access (filepath, F_OK) == -1)
            {
                FILE*  file = fopen(filepath ,"w");
                fprintf(file, "#init data file for todo app command line \n");
                fclose(file);
                printf("create data file sucssesfully in %s .\n", filepath);
            }
            
    }
    else if(access (filepath, F_OK) == 0)
    {
        printf("data file is exsited in %s .\n", filepath);
    }
    else
    {

        printf("thirth path %s\n",filepath);
        printf("data file is not existed. init data file\n");
        FILE*  file = fopen(filepath ,"w");
        fprintf(file, "#init data file for todo app command line \n");
        fclose(file);
        printf("create data file sucssesfully in %s .\n", filepath);
       

    }



	
	
}