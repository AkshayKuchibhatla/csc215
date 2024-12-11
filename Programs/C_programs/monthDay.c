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

promptDayFromDate(m,d,y) 
int* m,d,y; {
    printf("Enter month number below.\n");
    printf(">");
    scanf("%d", m);
    printf("\nEnter day number below.\n");
    printf(">");
    scanf("%d", d);
    printf("\nEnter year number below.\n");
    printf(">");
    scanf("%d", y);
}

promptDateFromDay(n, y)
int* n, y; {
    printf("Enter day number of the year below.\n");
    printf(">");
    scanf("%d", y);
    printf("\nEnter day number of the year below.\n");
    printf(">");
    scanf("%d", n);
}

getMonthName(n, mns) 
int n;
char *mns[]; {
    return ((n < 1 || n > 12) ? mns[0] : mns[n]);
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

    char *monthNames[13];
    monthNames[0] = "Illegal month";
    monthNames[1] = "January";
    monthNames[2] = "February";
    monthNames[3] = "March";
    monthNames[4] = "April";
    monthNames[5] = "May";
    monthNames[6] = "June";
    monthNames[7] = "July";
    monthNames[8] = "August";
    monthNames[9] = "September";
    monthNames[10] = "October";
    monthNames[11] = "November";
    monthNames[12] = "December";
    
    int option, month, day, year, dayNumber;

    while (1) {
        printf("\n*** MAIN MENU ***\n");
        printf("Choose one of the following options.\n\n");
        printf("0: Get day number from date.\n");
        printf("1: Get date from day number.\n\n");

        while (option != 48 && option != 49) {
            printf(">");
            option = getchar();
            printf("\n");
        }

        printf("\n");
        if (option == 48) {
            promptDayFromDate(&month, &day, &year);
            printf(
                "\nThe day number is %d.\n", 
                numberDayOfYear(year, month, day, dayTable)
            );
        } else {
            promptDateFromDay(&dayNumber, &year);
            dateOfNumberDay(year, dayNumber, &month, &day, dayTable);
            printf("\nThe date is %s %d, %d.\n", getMonthName);
        }
    }
}