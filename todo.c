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
#include "init_path.h"
#include "list_task.h"
#include "check_path.h"
#include "add_task.h"
#include "print_color.h"




// return true if the file specified by the filename exists
bool file_exists(const char *filename)
{
	//printf(filename);
    FILE *fp = fopen(filename, "r");
    bool is_exist = false;
    if (fp != NULL)
    {
        is_exist = true;
        fclose(fp); // close the file
    }
	// printf("aaaaa");
    return is_exist;
}



int main (int argc, char** argv)
{

	char Temp_Home_User_Dir [200];
	char TEMP_Todo_Path [200];
	char Temp_Todo_File_Name [200];
    char FULL_Todo_Path [200];

	char Todo_File_Name[] = "/.todo/data.json";
	char Todo_Path[] = "/.todo/data.json";
 	// char * Home_User_Dir = getenv("HOME");

	// printf("Home path is %s\n",Home_User_Dir);
	// printf("Todo_File_name path is %s\n",Todo_File_Name);

	// strcat(Temp_Home_User_Dir,Home_User_Dir);
	strcat(Temp_Home_User_Dir,getenv("HOME"));
	strcat(Temp_Home_User_Dir,Todo_File_Name);


	//strcat(FULL_Todo_Path,Home_User_Dir);
	strcat(FULL_Todo_Path,getenv("HOME"));
	strcat(FULL_Todo_Path,Todo_File_Name);


	printf("\n");
	print_color("yellow");
	printf("=============================================== \n");
	printf("=                   TODO LIST                 = \n");
	printf("=============================================== \n");
	print_color("reset");
	if (file_exists(Temp_Home_User_Dir))
	{
        // printf("File path exist \n", Temp_Home_User_Dir);

		if( argc == 2 )
		{
			printf("your argument is: %s\n", argv[1]);
			if (strcmp( argv[1] ,"init") ==0){
				printf("\n");
				print_color("blue");
				printf("  init list add edit delete\n");
				printf("=============================\n");
				printf("\n");
				print_color("reset");
				init_path (getenv("HOME") ,Todo_File_Name);


			}
			else if (strcmp( argv[1] ,"list") ==0){
				printf("\n");
				print_color("blue");
				printf("  init list add edit delete\n");
				printf("=============================\n");
				printf("\n");
				print_color("reset");
				list_task (FULL_Todo_Path,getenv("HOME") ,Todo_File_Name);

			}
			else if (strcmp( argv[1] ,"help") ==0)
			{
				printf("\n");
				print_color("blue");
				printf("1- init     initial path.\n");
				printf("2- list     list all task from list.\n");
				printf("3- add      create a new task in todo list.\n");
				printf("4- edit     change and edit a task.\n");
				printf("5- delete   remove a task from list.\n");
				print_color("reset");
			}

		}
		else if (argc > 2)
		{
			//printf("your argument is: argv[1] %s\n", argv[1]);
			//printf("your argument is: argv[2] %s\n", argv[2]);
			//printf("Too many arguments supplied.\n");
			if (strcmp( argv[1] ,"add") ==0){
				printf("\n");
				print_color("blue");
				printf("  init list add edit delete\n");
				printf("=============================\n");
				printf("\n");
				print_color("reset");
				add_task (FULL_Todo_Path,getenv("HOME") ,argv[2]);

			}

		}
		else
		{
			printf("\n");
			print_color("blue");
			printf("  init list add edit delete\n");
			printf("=============================\n");
			printf("\n");
			print_color("reset");
			// list_task (FULL_Todo_Path,Home_User_Dir ,Todo_File_Name);
			list_task (FULL_Todo_Path,getenv("HOME") ,Todo_File_Name);

		}
	}
    else
	{
		printf("\n");
		print_color("red");
        printf("File %s doesn't exist. \n", Temp_Home_User_Dir);
		print_color("reset");

		if( argc == 2 )
		{
			printf("The argument supplied is %s\n", argv[1]);

			if (strcmp( argv[1] ,"init") ==0){

				// init_path (Home_User_Dir ,Todo_File_Name);
				init_path (getenv("HOME") ,Todo_File_Name);


			}

		}
		else if (argc > 2)
		{
			printf("Too many arguments supplied.\n");
		}
		else
		{
			// printf("\n");
			// blue();
			// printf("init add edit delete\n", Temp_Home_User_Dir);
			// reset();
			//list_task (FULL_Todo_Path,Home_User_Dir,Todo_File_Name);
			list_task (FULL_Todo_Path,getenv("HOME"),Todo_File_Name);

		}

	}



}
