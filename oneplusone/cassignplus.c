#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int day, month, year;
} Dates;

int compare(const void *aptr, const void *bptr){
    int a = ((Dates *)aptr)->year, b = ((Dates *)bptr)->year;
    return (a > b) - (a < b);
}

int main(int argv, char *argc[]) {
  // Assumes no string longer than 1024 characters
  Dates arr[235];
  int month, day, year ;
  int i = 0;

  while (scanf("%d/%d/%d", &month, &day, &year) == 3) {
    arr[i].month = month;
    arr[i].day = day;
    arr[i].year = year;

    //REMOVE- test print to make sure std input is working
    printf("Before sorting: \n");
    printf("%02d/%02d/%04d\n", arr[i].month, arr[i].day, arr[i].year) ;
    i++;
  }

  printf("\n");

  qsort(arr, i+1, sizeof(Dates), compare);

  for (int j = 0; j < i; j++){
      printf("%02d/%02d/%04d\n", arr[j].month, arr[j].day, arr[j].year);
  }
  return 0 ;
}


