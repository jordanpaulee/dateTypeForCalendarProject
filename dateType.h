#ifndef dateType_H
#define dateType_H

/* dateType stores and manipulates a calendar date. 
   It provides the following services: 
   Set a date.
   Set individual components of a date (month, day, or year).
   Print the date in the form mm-dd-yyyy
   Return the number of days passed, 
      number of days left, and number of days in the month.
   Determines if year is a leap year.
*/

class dateType
{ 
public:
    // Setters
    void setDate(int, int, int);
    /* Preconditions: month must be between 1 and 12 (otherwise set to 1), 
          day must be between 1 and the last day for that month 
          (otherwise set to 1), 
          year must be greater than or equal to 1990 (otherwise set to 1900)
      Post condition: Month, day, and year are setDate
    */
    void setMonth(int);
    // Precondition: Month must be between 1 and 12
    // Post condition - Month is reset (set to 1 if input is invalid)
    void setDay(int);
    // Precondition: Day must be between 1 and last day of month
    // Post condition: Day is reset (set to 1 if input is invalid)
    void setYear(int);
	  // Precondition: Year must be >= 1900
    // Post condition: Year is set to 1900 if input is invalid
    void print() const;
    // Displays date in form mm-dd-yyyy 
    int numberOfDaysPassed();	
    // Returns the number of days passed since beginning of the year
    int numberOfDaysLeft();
    // Returns the number of days left in the year
    void incrementDate(int nDays);
    // Changes the date by adding the input to the current date

    //Getters
    int getMonth() const;
    int getDay() const;
    int getYear() const;

    int getDaysInMonth();
    // Returns the number of days in the month
    bool isLeapYear();
    // Returns true if year is a leap year, otherwise returns false
    dateType(int = 1, int = 1, int = 1900);
    // Constructor

private:
    int dMonth;
    int dDay;
    int dYear;
};

#endif