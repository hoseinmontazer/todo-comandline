#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdbool.h>
//#include "print_color.h"
#include <cjson/cJSON.h>







void print_task(char Home_User_Dir[], char user_task_name [] )
{
	//char str[BUFFER_SIZE];
    char Temp_Home_User_Dir [200];
	char TaskName[200];
	char Description[1000];
	//int TaskIsActive = 1;
	int TaskIsActive = 1;


    //printf("FULL_Todo_Path path is zzzzzzzzzz %s\n", Home_User_Dir);

    if (user_task_name  == NULL)
    {
        printf("FULL_Todo_Path path is zzzzzzzzzz %s\n", user_task_name);
    }
    else{
        //printf("FULL_Todo_Path path is zzzzzzzzzz %s\n", FULL_Todo_Path);
        strcat(Temp_Home_User_Dir,getenv("HOME"));
        //printf(Temp_Home_User_Dir,"\n");
        strcpy(Temp_Home_User_Dir, getenv("HOME"));
        //printf("default path is zzzzzzzzzz %s\n", Temp_Home_User_Dir);
        strcat(Temp_Home_User_Dir,"/.todo/");
        //printf(Temp_Home_User_Dir,"\n");
        //printf("default path is ssss %s\n", Temp_Home_User_Dir);
        strcat(Temp_Home_User_Dir,user_task_name);
        strcat(Temp_Home_User_Dir,".json");
        //printf("\033[1;31m");
        printf("yourrr task path is: %s\n", Temp_Home_User_Dir);
        //printf("\n");
        printf("\033[0m");

        FILE *fp = fopen(Temp_Home_User_Dir, "r");
        // read the file contents into a string 
        char buffer[1024]; 
        int len = fread(buffer, 1, sizeof(buffer), fp); 
        fclose(fp); 

        // parse the JSON data 
        cJSON *json = cJSON_Parse(buffer); 
        if (json == NULL) { 
            const char *error_ptr = cJSON_GetErrorPtr(); 
            if (error_ptr != NULL) { 
                printf("Error: %s\n", error_ptr); 
            } 
            cJSON_Delete(json); 
        } 
        // access the JSON data 
        cJSON *taskname = cJSON_GetObjectItemCaseSensitive(json, "taskname");
        cJSON *taskisactive = cJSON_GetObjectItemCaseSensitive(json, "taskisactive");
        cJSON *description = cJSON_GetObjectItemCaseSensitive(json, "description");
        if (cJSON_IsString(taskname) && (taskname->valuestring != NULL)) { 
            printf("\e[1mTask Name: %s\e[m\n", taskname->valuestring);
            printf("\e[1mDescription: %s\e[m\n", description->valuestring);
        } 
    
        // delete the JSON object 
        cJSON_Delete(json); 
    }

}