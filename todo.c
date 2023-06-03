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






// return true if the file specified by the filename exists
bool file_exists(const char *filename)
{
	printf(filename);
    FILE *fp = fopen(filename, "r");
    bool is_exist = false;
    if (fp != NULL)
    {
        is_exist = true;
        fclose(fp); // close the file
    }
	printf("aaaaa");
    return is_exist;
}



int main (int argc, char** argv)
{

	//const char Home_file_name[] = "~/todo/data.json";
	char foldername [200];
	char filename[200];
	char * pathAddr = "/.todo/data.json";
 	char * home_user_dir= getenv("HOME");
	char file_path[200] =  "/home/hosein/.todo/data.json";
	char file_path1[200];
	printf("HOME : %s\n", getenv("HOME"));
	printf("bbbbbbbb %s\n",pathAddr);
	strcat(home_user_dir,pathAddr);
	printf("%s\n",home_user_dir);
	printf("Size home_user_dir is: %d\n", strlen(home_user_dir));

    //int range_home_user_dir= strlen(home_user_dir) + strlen(filename);
    //printf("home_user_dir 1  Size is: %d\n", home_user_dir);
	strcat(file_path1,home_user_dir);
	printf("%s\n",file_path1);
	printf("%s\n",file_path);
	printf("%d\n", strcmp(file_path1, file_path));

	printf("-------------------------------------- \n");
	if (file_exists(file_path))
        printf("File %s exists \n", file_path);
    else
        printf("File %s doesn't exist. \n", file_path);
	//check_path(file_path);
	//checked(home_user_dir,foldername ,filename);
	printf("hiiiiiiiiiiiiiii");
	if( argc == 2 )
	{
    	printf("The argument supplied is %s\n", argv[1]);
		//return 0;
		if (strcmp( argv[1] ,"init") ==0){
			init_path (home_user_dir,foldername ,filename);

		}

	}
	else if (argc > 2)
	{
		printf("Too many arguments supplied.\n");
	}
	else
	{
		list_task (home_user_dir,foldername ,filename);
		//return 0;
	}


	


}
