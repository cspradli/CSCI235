//Modified by Caleb Spradlin
//SO FAR WORKS BUT DOES NOT GO INTO SUBDIRECTORIES
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

// Print all the files and (sub)directories of the path_name
int dir_print(char *path_name) {
  struct stat dirStat ;
  char bigFileNameBuffer[8192] ;
  // "Open" the directory
  DIR *dirPntr  = opendir(path_name) ;
  if (dirPntr != NULL) {
    struct dirent *entryPntr ;
    // Read the next directory entry into entryPntr
    while ((entryPntr = readdir(dirPntr)) != NULL) {

      // Get the stats for the entryPntr
      // print name and type for entryPntr if the entry is a file or directory
      sprintf(bigFileNameBuffer, "%s/%s", path_name, entryPntr->d_name) ;
      struct stat fileStat ;
      
      if (!stat(bigFileNameBuffer, &fileStat)) {
      //Prints file size if there is a file in the directory
	  if (S_ISREG(fileStat.st_mode)) {
        if (fileStat.st_size > largestFile){
            largestFile = fileStat.st_size;
            strcpy(fileName, bigFileNameBuffer);
        }
        
        //printf("%s:  ", bigFileNameBuffer) ;
        //printf("File size:    %ld bytes\n", (long) fileStat.st_size);
	    }
      }
    }
    printf("%s:   ", fileName);
    printf("File size:    %d bytes\n", largestFile);
    return 0 ;
  } else {
    // This is unexpected...
    fprintf(stderr, "Unable to open directory %s: %s\n",
	    path_name, strerror(errno)) ;
    return 235 ;
  }
}
