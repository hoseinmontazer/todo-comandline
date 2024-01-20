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






// void init_path( char *home_user_dir, char *foldername , char *filename )
void init_path( char *Home_User_Dir , char *Todo_File_Name)
{
    char filepath[500];
    //char *user_file_path;
    char Temp_Home_User_Dir[500];

    char user_file_path[500];
    char ch;
    int i;
    
//TO DO
/*
there is two bug and feature
1) sometimes dont right check file path exist but file is existed - 87
2) befor init file path  should check that is avilable or not from  config file
*/


printf ("home path is %s\n" , Home_User_Dir );
printf ("Todo_File_Name path is %s\n" , Todo_File_Name );
strcat(Temp_Home_User_Dir,Home_User_Dir);
strcat(Temp_Home_User_Dir,Todo_File_Name);

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
        printf("data file is exsited in %s .\n", Temp_Home_User_Dir);
        cJSON *json = cJSON_CreateObject();
        cJSON_AddStringToObject(json, "name", "John Doe");
        cJSON_AddNumberToObject(json, "age", 30);
        cJSON_AddStringToObject(json, "email", "john.doe@example.com");
        char *json_str = cJSON_Print(json);
        FILE *fp = fopen(Temp_Home_User_Dir, "w");
        printf("%s\n", json_str);
        fputs(json_str, fp);
        fclose(fp);
        cJSON_free(json_str);
        cJSON_Delete(json);
        // printf("%s\n");
    }
    else
    {
        // strcat(Temp_Home_User_Dir,Home_User_Dir);
	    // strcat(Temp_Home_User_Dir,Todo_File_Name);

        printf("thirth path %s\n",Temp_Home_User_Dir);
        printf("data file is not existed. init data file\n");
        //FILE*  file = fopen("/home/hosein/.todo/data.json" ,"w");
        FILE*  file = fopen(Temp_Home_User_Dir ,"w");
        fprintf(file, "#init data file for todo app command line \n");
        fclose(file);
        printf("create data file sucssesfully in %s .\n", Temp_Home_User_Dir);

        }




	
	
}