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

	char * Todo_File_Name = "/.todo/data.json";
	char * Todo_Path = "/.todo/data.json";
 	char * Home_User_Dir= getenv("HOME");

	printf("Home path is %s\n",Home_User_Dir);
	printf("Todo_File_name path is %s\n",Todo_File_Name);

	strcat(Temp_Home_User_Dir,Home_User_Dir);
	strcat(Temp_Home_User_Dir,Todo_File_Name);


	strcat(FULL_Todo_Path,Home_User_Dir);
	strcat(FULL_Todo_Path,Todo_File_Name);


	printf("hamed %s\n",Temp_Home_User_Dir);

	printf("-------------------------------------- \n");
	if (file_exists(Temp_Home_User_Dir))
        printf("File %s exists \n", Temp_Home_User_Dir);
    else
        printf("File %s doesn't exist. \n", Temp_Home_User_Dir);

	printf("hiiiiiiiiiiiiiii new world \n");
	if( argc == 2 )
	{
    	printf("The argument supplied is %s\n", argv[1]);

		if (strcmp( argv[1] ,"init") ==0){
			printf("path issssssssssss %s \n",Temp_Home_User_Dir);
			printf("path issssssssssss %s \n",Home_User_Dir );
			printf("path issssssssssss %s \n",Todo_File_Name );
			init_path (Home_User_Dir ,Todo_File_Name);


		}

	}
	else if (argc > 2)
	{
		printf("Too many arguments supplied.\n");
	}
	else
	{
		list_task (Home_User_Dir,Todo_Path ,Todo_File_Name);

	}


	


}
