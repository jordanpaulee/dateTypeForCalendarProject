#include <iostream>
#include <string>
#include <iomanip>

#include "dateType.h"

using namespace std;

//useful arrays and variable

int longMonth[7] = {1,3,5,7,8,10,12};
int shortMonth[4] = {4,6,9,11};
int february = 2;


//default constructor
dateType::dateType(int month, int day, int year){
  dateType::setDate(month, day, year);
};

//public functions
  //setters
void dateType::setDate(int month , int day, int year){
  
  if (year < 1900){
    dYear = 1900;
    // assuming there was a typo in header file.  
  }
  else{
    dYear=year;
  }
  
  if(month < 1 || month > 12){
    dMonth=1;
  }
  else{
    dMonth=month;
  }

  if (month == 2){
    if(isLeapYear()){
      if (day < 1 || day > 29){
        dDay=1;
      }
      else{
        dDay=day;
      }
    }
    else{
      if(day < 1 || day > 28){
        dDay=1;
      }
      else{
        dDay=day;
      }
    }
  }
  else{};
  
  for (int i=0; i < 7; i++){
    if (month == longMonth[i] && month != 2){
      if (day < 1 || day > 31){
        dDay=1;
        break;
      }
      else{
        dDay=day;
        break;
      }
    }
    else{}
  };

  for (int i=0; i < 4 ; i++){
    if(month == shortMonth[i] && month != 2){
      if (day < 1 || day > 30){
        dDay=1;
        break;
      }
      else{
        dDay=day;
        break;
      }
    }
    else{}
  };
};

void dateType::setMonth(int month){
  if (month < 1 || month > 12){
    dMonth=1;
  }
  else{
    dMonth=month;
  }
};

void dateType::setDay(int day){
  if (dMonth == 2){
    if(isLeapYear()){
      if (day < 1 || day > 29){
        dDay=1;
      }
      else{
        dDay=day;
      }
    }
    else{
      if(day < 1 || day > 28){
        dDay=1;
      }
      else{
        dDay=day;
      }
    }
  }
  else{
    for (int i=0; i < 6; i++){
      if (dMonth == longMonth[i] && dMonth != 2){
        if (day < 1 || day > 31){
          dDay=1;
          break;
        }
        else{
          dDay=day;
          break;
        }
      }
    }

    for (int i=0; i < 5; i++){
      if(dMonth == shortMonth[i] && dMonth != 2){
        if (day < 1 || day > 30){
          dDay=1;
          break;
        }
        else{
          dDay=day;
          break;
        }
      }
    }
  }
};

void dateType::setYear(int year){
  if (year < 1900){
    dYear = 1900;
    // assuming there was a typo in header file in the setDate preconditions.  
  }
  else{
    dYear=year;
  }
  //catches leap year edge case on 2/29 so day updates with year update.
  if(!isLeapYear() && dMonth == 2 && dDay == 29){
    dDay = 1;
  }
  else{
  }
};
  //functions
void dateType::print() const{
  cout << setfill('0') << setw(2);
  cout << dMonth << "-" << dDay << "-" << setw(4) << dYear << endl; 
}

int dateType::numberOfDaysPassed(){
  int daysMonthNoLeap[12] = {31,59,90,120,151,181,212,243,273,304,334};
  int daysMonthLeap[12] = {31,60,91,121,152,182,213,244,274,305,335};
  
  if(isLeapYear())
    if(dMonth>1){
      int daysPassed = daysMonthLeap[dMonth-2] + dDay;
      return daysPassed;
    }
    else{
      return dDay;
    }
  else{
    if(dMonth>1){
      int daysPassed = daysMonthNoLeap[dMonth-2] + dDay;
      return daysPassed;
    }
    else{
      return dDay;
    }
  }
};

int dateType::numberOfDaysLeft(){
  if(isLeapYear()){
    int daysLeft = 366 - dateType::numberOfDaysPassed();
    return daysLeft;
  }
  else{
    int daysLeft = 365 - dateType::numberOfDaysPassed();
    return daysLeft;
  }
};

void dateType::incrementDate(int nDays){
  int daysMonthNoLeap[12] = {31,59,90,120,151,181,212,243,273,304,334};
  int daysMonthLeap[12] = {31,60,91,121,152,182,213,244,274,305,335};

  int dayCount = dateType::numberOfDaysPassed() + nDays;


  if(isLeapYear()){
      while (dayCount > 366){
      if(!isLeapYear()){
        dayCount = dayCount-365;
        dYear++;
        }
      else{
        dayCount = dayCount-366;
        dYear++;
        }
      }
    if(dayCount <= 31) {
      dMonth=1;
      dDay=dayCount;
    }
    else if(dayCount > 335){
      dMonth=12;
      dDay=366-dayCount;
    }
    else{
      for(int i=0; i < 11; i++){
        if(dayCount > daysMonthLeap[i] && dayCount < daysMonthLeap[i+1]){
          dMonth=i+2;
          dDay=dayCount-daysMonthLeap[i];
        }
      }
    }
  }
  else{
    while (dayCount > 365){
      if(!isLeapYear()){
        dayCount = dayCount-365;
        dYear++;
        }
      else{
        dayCount = dayCount-366;
        dYear++;
        }
    }
    if(dayCount <= 31) {
      dMonth=1;
      dDay=dayCount;
    }
    else if(dayCount > 334){
      dMonth=12;
      dDay=365-dayCount;
    }
    else{
      for(int i=0; i < 11; i++){
        if(dayCount > daysMonthNoLeap[i] && dayCount < daysMonthNoLeap[i+1]){
          dMonth=i+2;
          dDay=dayCount-daysMonthNoLeap[i];
          break;
        }
      }
    }
  }

};

//getters

int dateType::getMonth() const{
  return dMonth;
};

int dateType::getDay() const{
  return dDay;
};

int dateType::getYear() const{
  return dYear;
};

int dateType::getDaysInMonth(){

  if(dMonth >=1 && dMonth <= 12){
    if (dMonth == 2){
      if(isLeapYear()){
        return 29;
      }
      else{
        return 28;
      }
    }
    else{
    };
    
    for (int i=0; i < 7; i++){
      if (dMonth == longMonth[i] && dMonth != 2){
        return 31;
        break;
      }
      else{
      }
    };

    for (int i=0; i < 4 ; i++){
      if(dMonth == shortMonth[i] && dMonth != 2){
        return 30;
        break;
      }
      else{
      }
    };
  }
  else{
  }
};
//warning INVALID as ALL cases are covered by arrays global arrays... frustrating.

bool dateType::isLeapYear(){
  if(dYear%4 == 0){
    if(dYear%100 == 0){
      if(dYear%400 == 0){
        return true;
      }
      else{
        return false;
      }
    }
    else{
      return true;
    }
  }
  else{
    return false;
  }
}