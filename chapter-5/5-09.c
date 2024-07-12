#include <stdio.h>

int day_of_year(int, int, int);
void month_day(int, int, int *, int *);
int check_leap(int);

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main() {
    int m, d;
    month_day(1988, 366+365, &m, &d);
    printf("Month: %d, Day: %d\n", m, d);
    printf("Day of Year: %d\n", day_of_year(1989, 12, 31));
    return 0;
}

/* day_of_year:  set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int leap;
    char *p;

    leap = check_leap(year);
    p = daytab[leap];

    if (month > 12 || month < 1) {
        return -1;
    }
    if (day > p[month] || day < 1) {
        return -1;
    }
    while (--month) {
        day += *++p;
    }
    return day;
}

/* month_day:  set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int leap;
    char *p;
    
    if (year < 1) {
        *pmonth = -1;
        *pday = -1;
        return;
    }

    leap = check_leap(year);
    p = daytab[leap];

    // rewritten to account for number of days exceeding one year
    while (yearday > *++p){
        if (p > daytab[leap] + 12) {
            leap = check_leap(++year);
            p = daytab[leap] + 1;
        }
        yearday -= *p;
    }

    *pmonth =  p - *(daytab + leap);
    *pday = yearday;
}

int check_leap(int year) {
    return year%4 == 0 && year%100 != 0 || year%400 == 0;
}
