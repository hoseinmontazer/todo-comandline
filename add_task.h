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
#include "print_task.h"






void add_task( char FULL_Todo_Path[],char Home_User_Dir[], char user_task_name [] )
{
	//char str[BUFFER_SIZE];
	char Task_addr[200];
    char Temp_Home_User_Dir [200];
	char TaskName[200];
	char Description[1000];
	//int TaskIsActive = 1;
	int TaskIsActive = 1;
	struct stat st = {0};



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
	printf("your task path is: %s\n", Temp_Home_User_Dir);
	//printf("\n");
	printf("\033[0m");
	strcat(Task_addr,Temp_Home_User_Dir);
	strcpy(Task_addr,Temp_Home_User_Dir);
	//printf("your task path is: %s %s\n", Task_addr ,Temp_Home_User_Dir);
	





	if(access (Temp_Home_User_Dir, F_OK) == 0)
    {
		printf("data file is exsited in %s .\n", Temp_Home_User_Dir);
		print_task(Home_User_Dir,user_task_name);


    }
	else if(access (Temp_Home_User_Dir, F_OK) == -1)
    {

		char *del = &Temp_Home_User_Dir[strlen(Temp_Home_User_Dir)];
		while (del > Temp_Home_User_Dir && *del != '/')
			del--;

		if (*del== '/')
		{
			//printf("deleteee\n");
			*del= '\0';
		}
		//printf("user_task_name task path is: %s\n", Temp_Home_User_Dir);


		if (stat(Temp_Home_User_Dir, &st) == -1) {
			printf("dir not available, create dir\n");
			mkdir(Temp_Home_User_Dir, 0700);
		}

		printf("\033[0;32m");
		printf("\e[1mEnter your task name:\e[m \n");
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
		printf("\e[1mEnter your task description:\e[m\n");
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
		//printf("Hello %s\n", TaskName);
		//printf("Hello Description %s\n", Description);

        FILE*  file = fopen(Task_addr ,"w");
        fprintf(file, "#init data file for todo task, %s \n",user_task_name);
        fclose(file);
		cJSON *json = cJSON_CreateObject();
		//cJSON_AddStringToObject(json, "taskname", TaskName);
		// cJSON_AddNumberToObject(json, "description", Description);
		// cJSON_AddStringToObject(json, "task_is_active", TaskIsActive);
		cJSON_AddStringToObject(json, "taskname", TaskName);
        cJSON_AddNumberToObject(json, "taskisactive", TaskIsActive);
        cJSON_AddStringToObject(json, "description", Description);
		char *json_str = cJSON_Print(json);
		FILE *fp = fopen(Task_addr, "w");
		// printf("%s\n", json_str);
		fputs(json_str, fp);
		fclose(fp);
		cJSON_free(json_str);
		cJSON_Delete(json);
		printf("init file sucssesfully in %s.\n", Task_addr);
		
		print_task(Task_addr, user_task_name);
    }


}