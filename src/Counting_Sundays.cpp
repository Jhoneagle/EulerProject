/*
You are given the following information, but you may prefer to do some research for yourself.

- 1 Jan 1900 was a Monday.
- Thirty days has September, April, June and November.
- All the rest have thirty-one, Saving February alone, Which has twenty-eight, rain or shine.
- And on leap years, twenty-nine.
- A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
*/

#include<bits/stdc++.h> 
#include <iostream>

using namespace std;

typedef long long num;

// based on Zeller's congruence
// January = 1, February = 2, ..., December = 12
// returns 0 => Saturday, 1 => Sunday, 2 => Monday, ... 6 => Friday
int getWeekday(num year, int month, int day) {
  // January and February are counted as month 13 and 14 of the previous year
  if (month <= 2) {
    month += 12;
    year--;
  }
  
  return (day + 13 * (month + 1) / 5 + year + (year / 4) - (year / 100) + (year / 400)) % 7;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  num yearFrom, yearTo;
  int sum = 0, monthFrom, monthTo, dayFrom, dayTo;
  
  cin >> yearFrom >> monthFrom >> dayFrom;
  cin >> yearTo >> monthTo >> dayTo;
  
  num currentYear = yearFrom;
  int currentMonth = monthFrom;
  
  if (dayFrom > 1) {
    currentMonth++;
    
    if (currentMonth > 12) {
      currentMonth -= 12;
      currentYear++;
    }
  }
  
  while (currentMonth < monthTo || currentYear < yearTo) {
    if (getWeekday(currentYear, currentMonth, 1) == 1) sum++;
    
    currentMonth++;
    
    if (currentMonth > 12) {
      currentMonth -= 12;
      currentYear++;
    }
  }
  
  if (getWeekday(currentYear, currentMonth, 1) == 1) sum++;
  
  cout << sum << "\n";
  return 0;
}
