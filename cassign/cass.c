#include <stdio.h>
//#include <string.h>

int main(int argv, char const **argc){
    //char buff[100];
    int month;
    int day;
    int year;
    while(scanf("%d/%d/%d", &month, &day, &year) == 3){
        printf("%d %d %d\n", month, day, year);
    }
}
