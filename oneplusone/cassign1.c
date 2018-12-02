#include <stdio.h>

int main(int argv, char *argc[]) {
  // Assumes no string longer than 1024 characters
  int month, day, year ;
  while (scanf("%d/%d/%d", &month, &day, &year) == 4) {
    printf("%02d/%02d/%04d\n", month, day, year) ;
  }
  return 0 ;
}

// Some would prefer the test
//  scanf("%s", dataStuff) != EOF
