#include <stdio.h>

int main(int argv, char *argc[]) {
  // Assumes no string longer than 1024 characters
  char dataStuff[1025] ;
  while (scanf("%s", dataStuff) == 1) {
    printf("%s\n", dataStuff) ;
  }
  return 0 ;
}

// Some would prefer the test
//  scanf("%s", dataStuff) != EOF
