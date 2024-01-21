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
#include "init_path.h"
#include "list_task.h"
#include "check_path.h"
#define BUFFER_SIZE 15






void add_task( char FULL_Todo_Path[],char Home_User_Dir[], char user_task_name [] )
{
	//char str[BUFFER_SIZE];
    char Temp_Home_User_Dir [200];
	char TaskName[200];
	char Description[1000];
	//int TaskIsActive = 1;
	int TaskIsActive = 1;



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
	printf("\033[1;31m");
	printf("you task path is: %s\n", Temp_Home_User_Dir);
	printf("==========================================================\n");
	printf("\n");
	printf("\033[0m");
	printf("\033[0;32m");
	printf("Enter your task name: \n");
	printf("\033[0m");
	//fgets(TaskName, sizeof(TaskName), stdin);
	if (fgets(TaskName, sizeof(TaskName), stdin) == NULL)
	{
		printf("Fail to read the input stream");
    }
	else
	{
		TaskName [ strcspn (TaskName, "\n")] = 0;
	}
	
	printf("\033[0;32m");
	printf("Enter your task description: \n");
	printf("\033[0m");
	//fgets(Description, sizeof(Description), stdin);
	if (fgets(Description, sizeof(Description), stdin) == NULL)
	{
		printf("Fail to read the input stream");
    }
	else
	{
		Description [ strcspn (Description, "\n")] = 0;
	}
	printf("Hello %s\n", TaskName);
	printf("Hello Description %s\n", Description);
	if(access (Temp_Home_User_Dir, F_OK) == -1)
    {
        FILE*  file = fopen(Temp_Home_User_Dir ,"w");
        fprintf(file, "#init data file for todo task, %s \n",user_task_name);
        fclose(file);
        printf("create data file sucssesfully in %s .\n", Temp_Home_User_Dir);
		cJSON *json = cJSON_CreateObject();
		//cJSON_AddStringToObject(json, "taskname", TaskName);
		// cJSON_AddNumberToObject(json, "description", Description);
		// cJSON_AddStringToObject(json, "task_is_active", TaskIsActive);
		cJSON_AddStringToObject(json, "name", TaskName);
        cJSON_AddNumberToObject(json, "age", TaskIsActive);
        cJSON_AddStringToObject(json, "email", Description);
		char *json_str = cJSON_Print(json);
		FILE *fp = fopen(Temp_Home_User_Dir, "w");
		printf("%s\n", json_str);
		fputs(json_str, fp);
		fclose(fp);
		cJSON_free(json_str);
		cJSON_Delete(json);
    }
	else if(access (Temp_Home_User_Dir, F_OK) == 0)
    {
        printf("data file is exsited in %s .\n", Temp_Home_User_Dir);
        // cJSON *json = cJSON_CreateObject();
        // cJSON_AddStringToObject(json, "name", "John Doe");
        // cJSON_AddNumberToObject(json, "age", 30);
        // cJSON_AddStringToObject(json, "email", "john.doe@example.com");
        // char *json_str = cJSON_Print(json);
        // FILE *fp = fopen(Temp_Home_User_Dir, "w");
        // printf("%s\n", json_str);
        // fputs(json_str, fp);
        // fclose(fp);
        // cJSON_free(json_str);
        // cJSON_Delete(json);
        // printf("%s\n");
    }
	// cJSON *json = cJSON_CreateObject();
    // cJSON_AddStringToObject(json, "taskname", TaskName);
    // cJSON_AddNumberToObject(json, "description", Description);
    // cJSON_AddStringToObject(json, "task_is_active", TaskIsActive);
    // char *json_str = cJSON_Print(json);
    // FILE *fp = fopen(Temp_Home_User_Dir, "w");
    // printf("%s\n", json_str);
    // fputs(json_str, fp);
    // fclose(fp);
    // cJSON_free(json_str);
    // cJSON_Delete(json);


    //printf("hello add task \n");

}