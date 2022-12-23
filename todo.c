#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include "init_path.h"







int check_path(const char *Home_file_name)
{

	//FILE* rfile ;
	//FILE* wfile ;
	//rfile = fopen("~/todo/data.json","r");
	//wfile = fopen("~/todo/data.json","w");

	if (NULL == Home_file_name)
	{
		//printf("file can not opened \n");
		//fprintf(wfile, "this is a test %d\n",wfile);
		//printf("please init a repo with \" todo init \" command.\n");
		return 0 ;
	}
	else
	{
	return 1 ;
	}

}





void list_task(const char  *Home_file_name )
{
	printf("tttttttttest list list_task ");
	//int number;
	//while (fscanf(rfile, "%d", & number) == 1  )
	//{
//		printf ("We just read file %d\n", number);
//	}
}



int main (int argc, char** argv)
{

	//const char Home_file_name[] = "~/todo/data.json";
	char filename[] ="/data.json";
	char foldername[] = "/.todo" ;
 	char * home_user_dir = getenv("HOME");
	//char home_dir = strcat(home_user_dir , foldername);
	char Home_file_name [] = "tttt";

	//printf ("This program was called with \"%s\".\n",argv[0]);
	if( argc == 2 )
	{
    		//printf("The argument supplied is %s\n", argv[1]);
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
    	printf("The argument supplied is %s\n", argv[1]);
		printf("One argument expected.\n");
		list_task(Home_file_name);
		//return 0;
	}


	


}
