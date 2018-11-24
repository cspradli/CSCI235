//Modified by Caleb Spradlin
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int dir_print(char *) ;

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
      printf("%s:  ", bigFileNameBuffer) ;
      if (!stat(bigFileNameBuffer, &fileStat)) {
	if (S_ISDIR(fileStat.st_mode)) {
	  puts("Directory") ;
	} else if (S_ISREG(fileStat.st_mode)) {
	  puts("File") ;
    printf("File size:    %ld bytes\n", (long) fileStat.st_size);
	} else {
	  puts("who cares?") ;
	}
      } else {
	// This is unexpected
	fprintf(stderr, "Unable to access %s\n", bigFileNameBuffer) ;
      }
    }
    return 0 ;
  } else {
    // This is unexpected...
    fprintf(stderr, "Unable to open directory %s: %s\n",
	    path_name, strerror(errno)) ;
    return 235 ;
  }
}
