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
// printf("if you want initial to-do path please enter your path or empty that and press enter: (default path is ~/.todo/todo.json):\n");
//     i = 0;
//     ch = getchar ();
//     while(ch!='\n')
//     {
//         user_file_path[i] = ch;
//         i++;
//         ch = getchar();
//     }
//     user_file_path[i] ='\0';
//     //printf(strlen(user_file_path));
//     printf("your chosen path is: %s\n", user_file_path);
//     if (ch==0x0A && strlen(user_file_path)<1)
//     {
//         //printf("your chosen path is in enter: %s\n", user_file_path);
//         //printf("ENTER KEY is pressed.\n");
        
//         // printf("you choose default path is ~/.todo/data.json.\n");
//         // strcat(Home_User_Dir, Todo_Path);
//         // strcat(FULL_Todo_Path, Home_User_Dir);
//         // strcat(FULL_Todo_Path, Todo_File_Name);
//         // printf("first of  first directory %s\n",Home_User_Dir);
//         // printf("first of  first directory %s\n",Todo_Path);
//         // printf("full path is directory %s\n",FULL_Todo_Path);
//         // printf("first of  first directory %s\n",Home_User_Dir);


//     }
//     else
//     {
        
//         printf("your chosen path is: %s\n", user_file_path);
//         printf("secound of  first directory %s\n",Home_User_Dir);

//     }
//     // strncat(filepath,&*home_user_dir,200);
//     // strncat(filepath,&*Home_User_Dir,200);
//     // printf("thirth of  first directory %s\n",Home_User_Dir);
//     // printf("final  first filepath %s\n",filepath);
    
//     DIR* dir = opendir(Home_User_Dir);
    
//     //FILE *file;
//     if(!dir){
//             if (mkdir(Home_User_Dir, S_IRWXU | S_IRWXG | S_IRWXO) == -1) {
//                 printf("Error: %s\n", strerror(errno));
//             }
//             if(access (Temp_Home_User_Dir, F_OK) == -1)
//             {
//                 FILE*  file = fopen(Temp_Home_User_Dir ,"w");
//                 fprintf(file, "#init data file for todo app command line \n");
//                 fclose(file);
//                 printf("create data file sucssesfully in %s .\n", Temp_Home_User_Dir);
//             }
            
//     }
//     else if(access (Temp_Home_User_Dir, F_OK) == 0)
//     {
//         printf("data file is exsited in %s .\n", Temp_Home_User_Dir);
//     }
//     else
//     {
//         strcat(Temp_Home_User_Dir,Home_User_Dir);
// 	    strcat(Temp_Home_User_Dir,Todo_File_Name);

//         printf("thirth path %s\n",Temp_Home_User_Dir);
//         printf("data file is not existed. init data file\n");
//         //FILE*  file = fopen("/home/hosein/.todo/data.json" ,"w");
//         FILE*  file = fopen(Temp_Home_User_Dir ,"w");
//         fprintf(file, "#init data file for todo app command line \n");
//         fclose(file);
//         printf("create data file sucssesfully in %s .\n", Temp_Home_User_Dir);
       

//     }




	
	
}