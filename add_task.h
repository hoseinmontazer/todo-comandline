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




void red () {
	printf("\033[1;31m");
}

void yellow () {
	printf("\033[1;33m");
}

void green () {
	printf("\033[0;32m");
}
void blue () {
	printf("\033[0;34m");
}

void reset () {
	printf("\033[0m");
}
int main (int argc, char** argv)
{

	char Temp_Home_User_Dir [200];
	char TEMP_Todo_Path [200];
	char Temp_Todo_File_Name [200];
    char FULL_Todo_Path [200];


}