Objective:     Write a program that takes a date entered by the user and determines 
which day of the week the day falls on. It must account for incorrectly entered dates 
including leap years.
*/
#include <stdio.h> 
#include <stdbool.h>
struct date      /*definition of the date structure as a global 
        variable since the main function and other 
        functions will use it*/
{ 
 int month;
 int day;
 int year; 
};

/*Function to take date as an argument and return a numeric value*/
long int calc_date_number (struct date d)
{
 long int N;
 int f, g, a, b, c;
 
 if (d.month <=2) {
  f = (d.year - 1);
  g = (d.month + 13);
 }
 else {
  f = d.year; 
  g = (d.month + 1);
 }
 
 N = (((1461 * f) / 4) + ((153 * g) / 5) + (d.day));
 
 return N;
 
}/*end function*/

/*Function to take numeric date and return a number 0-6*/
int calc_day_number (long int numericdate)
{ 
  long int numericdate; 
  int w;
  long int calc_date_number (struct date d);
 
 w = (numericdate - 621049)%7;
 
 return w;
}/*end function*/

/*Function to determine if it's a leap year*/
bool isLeapYear (struct date d)
{
 bool leapYearFlag;
 
 if ( (d.year % 4 == 0 && d.year % 100 != 0)  || d.year % 400 == 0)
  leapYearFlag = true;
 
 else 
  leapYearFlag = false;
 
 return leapYearFlag;
}/* end function */


/*Begin main program*/
int main (void)
{  
 /*declaration of variables*/
 
 long int calc_date_number (struct date entry);  /*function to calculate N*/
 int calc_day_number (long int numericdate);  /*function to calculate day number*/ 
 bool isLeapYear (struct date d);    /*function to test if it is a leap year*/
 struct date entry;
 int w;
 long int numericdate;
 const int daysPerMonth[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
 char *days[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
 
 
printf("Welcome to the Date to Day of the Week Program.\n\n");
printf("The program will give the day of the week for any date from 1/1/1990\n\n");
 
do      /*begin trap loop to take proper date 
      and store it as a structure called "entry"*/
  {
   printf ("Enter day (mm/dd/yyyy): ");
   scanf("%d/%d/%d", &entry.month, &entry.day, &entry.year);
   fflush(stdin);
 
   if (entry.month < 1)    /*month must be greater than 1*/
     printf("Invalid month.  Please re-enter date.\n\n"); 
  
   else
   if (entry.month > 12)  /*month must be less than 12*/
     printf("Invalid month.  Please re-enter date.\n\n");
   
   else 
   if (entry.day < 1)   /*day must be greater than 1*/
     printf("Invalid day.  Please re-enter date.\n\n");
     
   else 
   if  (entry.day > 31)  /*day must be less than 31*/
     printf("Invalid day.  Please re-enter date.\n\n");
     
   else
   if (entry.year < 1990)  /*year must be greater than 1900*/
     printf("Invalid year. Please re-enter date. Year must be greater than 1900.\n\n");
     
   else       /*day cannot be more than the maximum days of the month*/
   if (entry.day > daysPerMonth[entry.month - 1])
     printf("Invalid date.  Please re-enter with appropriate day.\n\n");
   
   else      /*day cannot be more than 28 on a non-leap year*/
   if ( ! isLeapYear (entry) && entry.month == 2 && entry.day > 28)
     printf("Invalid date. %i is not a leap year.\n\n", entry.year);
     
  }while (entry.month < 1 || entry.month > 12 || entry.day < 1 || entry.day > 31 || entry.year < 1990
    || entry.day > daysPerMonth[entry.month - 1] || (! isLeapYear (entry) && entry.month == 2 && entry.day > 28));
    /* end do-while*/
 
  
 numericdate = calc_date_number (entry);  /*call calc_date_number function*/
 w = calc_day_number (numericdate);   /*call calc_day_number function*/
 
 printf("%i/%i/%i falls on a %s.\n", entry.month, entry.day, entry.year, days[w-1]);
 
 printf("Thank you for using the Date to Day-of-Week Program\n"); 
return 0;
  
}/*end main*/
