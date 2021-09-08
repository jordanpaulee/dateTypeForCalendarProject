#include <iostream>
#include <string>

#include "dateType.h"

using namespace std;

int main() 
{
  dateType date1;
  dateType date2(12,31,2000);

  cout << "Default constructor: ";
  date1.print();
  cout << "Constructor with parameters: ";
  date2.print();


  cout << "Number of days passed: " << date2.numberOfDaysPassed() << endl;
  cout << "Number of days left: " << date2.numberOfDaysLeft() << endl;
  cout << "Number of days in month: " << date2.getDaysInMonth() << endl;

  date2.incrementDate(15);
/*
  cout << birthDay.numberOfDaysPassed() << endl;
  cout << birthDay.numberOfDaysLeft() << endl;
*/
  cout << "After 15 days the date will be: ";
  date2.print();
    
  date2.setYear(2004);
  cout << "After setting the year to 2004: " << date2.getYear() << endl;
  date2.print();
  date2.setMonth(2);
  cout << "After setting month to 2: " << date2.getMonth() << endl;
  date2.print();
  date2.setDay(29);
  cout << "After setting the day to 29: " << date2.getDay() << endl;
  date2.print();
  date2.setYear(2021);
  cout << "Resetting year to 2021: " << date2.getYear() << endl;
  cout << "Date is now set to: ";
  date2.print();
  date2.setMonth(0);
  cout << "Resetting month to 0: " << date2.getMonth() << endl;

}