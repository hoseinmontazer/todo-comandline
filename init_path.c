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
#include <cjson/cJSON.h>
#include "init_path.h"
#include "text_color.h"





// void init_path( char *home_user_dir, char *foldername , char *filename )
void init_path( char *Home_User_Dir , char *Todo_File_Name)
{
    char filepath[500];
    //char *user_file_path;
    char Temp_Home_User_Dir[500];
    char Task_addr[200];
    char user_file_path[500];
    char ch;
    int i;
    struct stat st = {0};
//TO DO
/*
there is two bug and feature
1) sometimes dont right check file path exist but file is existed - 87
2) befor init file path  should check that is avilable or not from  config file
*/

    //printf ("home path is %s\n" , Home_User_Dir );
    //printf ("Todo_File_Name path is %s\n" , Todo_File_Name );
    strcat(Temp_Home_User_Dir,Home_User_Dir);
    strcat(Temp_Home_User_Dir,Todo_File_Name);
	strcat(Task_addr,Temp_Home_User_Dir);
	strcpy(Task_addr,Temp_Home_User_Dir);


    DIR* dir = opendir(Home_User_Dir);

    if(!dir){
            if (mkdir(Home_User_Dir, S_IRWXU | S_IRWXG | S_IRWXO) == -1) {
                printf("Error: %s\n", strerror(errno));
            }
            if(access (Temp_Home_User_Dir, F_OK) == -1)
            {
                FILE*  file = fopen(Temp_Home_User_Dir ,"w");
                fprintf(file, "#init data file for todo app command line \n");
                fclose(file);
                printf("create data file sucssesfully in %s .\n", Temp_Home_User_Dir);
            }
            
    }
    else if(access (Temp_Home_User_Dir, F_OK) == 0)
    {
        text_color("green");
        printf("\e[1mdata file is exsited in %s.\e[m\n", Temp_Home_User_Dir);
        text_color("reset");
		printf("\n");
		text_color("blue");
		printf("1- init     initial path.\n");
		printf("2- list     list all task from list.\n");
		printf("3- add      create a new task in todo list.\n");
		printf("4- edit     change and edit a task.\n");
		printf("5- delete   remove a task from list.\n");
		printf("6- pr       print all or a task from list.\n");
        printf("\n");
		text_color("reset");
    }
    else
    {
        text_color ("red");
        printf("data file is not existed. init data file\n");
        text_color ("reset");
        char *del = &Temp_Home_User_Dir[strlen(Temp_Home_User_Dir)];
		while (del > Temp_Home_User_Dir && *del != '/')
			del--;

		if (*del== '/')
		{
			//printf("deleteee\n");
			*del= '\0';
		}
        if (stat(Temp_Home_User_Dir, &st) == -1) {
			printf("dir not available, create dir\n");
            //printf("dir is: %s %s %s %s.\n", Temp_Home_User_Dir , Home_User_Dir, Todo_File_Name , Task_addr);
			mkdir(Temp_Home_User_Dir, 0700);
		}
        //FILE*  file = fopen("/home/hosein/.todo/data.json" ,"w");
        FILE*  file = fopen(Task_addr ,"w");
        fprintf(file, "#init data file for todo app command line \n");
        fclose(file);
        printf("create data file sucssesfully in %s .\n", Task_addr);

        }




	
	
}