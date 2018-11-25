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

void dir_print(char *base_path){
    char curPath[8196];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    if (!dir){
        return;
    }

    while((dp = readdir(dir)) != NULL){

        struct stat fileStat;

        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0){
            if (S_
        }
    }
}