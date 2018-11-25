#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int dir_print(char *) ;
int largestFile = 0;
char fileName[8192] = "";

// If there is an argument, pass it on to dir_print; otherwise, exit
int main(int argc, char *argv[]) {
  if (argc > 1) {
    return dir_print(argv[1]) ;
  } else {
    fprintf(stderr, "Usage: %s file-name\n", argv[0]) ;
    return 235 ;
  }
}

int dir_print(char *base_path){
    char curPath[8192];
    struct dirent *dp;
    DIR *dir = opendir(base_path);

    if (!dir){
        return 0;
    }

    while((dp = readdir(dir)) != NULL){

        struct stat fileStat;

        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0){
            //printf("%s\n", dp->d_name);

            if (!stat(curPath, &fileStat)) {
                if (S_ISREG(fileStat.st_mode)){
                    if (fileStat.st_size > largestFile){
                        largestFile = fileStat.st_size;
                        strcpy(fileName, curPath);
                    }
                }
            }
            // Construct new path from our base path
            strcpy(curPath, base_path);
            strcat(curPath, "/");
            strcat(curPath, dp->d_name);

            dir_print(curPath);
        }

    }
    printf("%s:   ", fileName);
    printf("File size:    %d bytes\n", largestFile);
    closedir(dir);
    return 0;
}

