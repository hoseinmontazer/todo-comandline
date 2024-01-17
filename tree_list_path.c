#include "tree_list_path.h"


#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>



#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>


// void red () {
// 	printf("\033[1;31m");
// }

// void yellow () {
// 	printf("\033[1;33m");
// }

// void green () {
// 	printf("\033[0;32m");
// }
// void blue () {
// 	printf("\033[0;34m");
// }

// void reset () {
// 	printf("\033[0m");
// }



void listdir(const char *name, int indent)
{
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(name)))
        return;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char path[1024];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            snprintf(path, sizeof(path), "%s/%s", name, entry->d_name);
            printf("%*s\e[1;34m[ %s ]\033[0m\n", indent, "", entry->d_name);
            listdir(path, indent + 1);
        } else {
            printf("%*s|- %s\n", indent, "", entry->d_name);
        }
    }
    closedir(dir);
}

void  tree_list_path(char FULL_Todo_Path[],char Home_User_Dir[], char Todo_File_Name []) {
    char Temp_Home_User_Dir [200];


    strcat(Temp_Home_User_Dir,Home_User_Dir);
    strcat(Temp_Home_User_Dir,"/.todo");
    printf(Temp_Home_User_Dir,"\n");
    listdir(Temp_Home_User_Dir, 2);
    
}

