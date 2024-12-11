#include <stdio.h>

/*Calcultes the number day in the year of the specified
date.*/
numberDayOfYear(year, month, day, dtbl)
int year, month, day, *dtbl[]; {
    int e, leap;

    leap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);

    for (e = 1; e < month; e++) day += dtbl[leap][e];
    return day;
}

/*Calculates the date of the nth day of the year.*/
dateOfNumberDay(year, dayNumber, monthPtr, dayPtr, dtbl)
int year, dayNumber, *monthPtr, *dayPtr, *dtbl[]; {
    int m,leap;
    leap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    
    for (m = 1; dayNumber > dtbl[leap][m]; m++)
        dayNumber -= dtbl[leap][m];

    *monthPtr = m;
    *dayPtr = dayNumber;
}

main() {
    int row1[13];
    row1[0] = 0;
    row1[1] = 31;
    row1[2] = 28;
    row1[3] = 31;
    row1[4] = 30;
    row1[5] = 31;
    row1[6] = 30;
    row1[7] = 31;
    row1[8] = 31;
    row1[9] = 30;
    row1[10] = 31;
    row1[11] = 30;
    row1[12] = 31;

    int row2[13];
    row2[0] = 0;
    row2[1] = 31;
    row2[2] = 29;
    row2[3] = 31;
    row2[4] = 30;
    row2[5] = 31;
    row2[6] = 30;
    row2[7] = 31;
    row2[8] = 31;
    row2[9] = 30;
    row2[10] = 31;
    row2[11] = 30;
    row2[12] = 31;

    int* dayTable[2];
    dayTable[0] = &row1;
    dayTable[1] = &row2;

    int e, j;

    printf("%s", "\n");

    printf("%d", numberDayOfYear(2024, 6, 18, dayTable));
    printf("%s", "\n");

    int m,d;

    dateOfNumberDay(2024, 84, &m, &d, dayTable);

    printf("Day 84 is day %d of month %d.", d, m);
}