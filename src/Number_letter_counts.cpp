/*
If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
*/

#include<bits/stdc++.h> 
#include <iostream>

using namespace std;

typedef long long num;

int proper[20] = {
  0, strlen("one"),
  strlen("two"),
  strlen("three"),
  strlen("four"),
  strlen("five"),
  strlen("six"),
  strlen("seven"),
  strlen("eight"),
  strlen("nine"),
  strlen("ten"),
  strlen("eleven"),
  strlen("twelve"),
  strlen("thirteen"),
  strlen("fourteen"),
  strlen("fifteen"),
  strlen("sixteen"),
  strlen("seventeen"),
  strlen("eighteen"),
  strlen("nineteen")
};

int tenth[8] = {
  strlen("twenty"),
  strlen("thirty"),
  strlen("forty"),
  strlen("fifty"),
  strlen("sixty"),
  strlen("seventy"),
  strlen("eighty"),
  strlen("ninety")
};

int noAdditionInName(int n) {
  if (n < 20) {
    return proper[n];
  } else {
    return tenth[n / 10 - 2 | 0] + proper[n % 10];
  }
}

int numberLength(int n) {
  if (n < 100) return noAdditionInName(n);

  int res = 0;
  int h = (int) floor(n / 100) % 10;
  int t = (int) floor(n / 1000);
  int s = n % 100;

  if (n > 999) res += noAdditionInName(t) + strlen("thousand");
    
  if (h != 0) res += proper[h] + strlen("hundred");
  
  if (s != 0) res += strlen("and") + noAdditionInName(s);
  
  return res;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int l = 0;
  
  for (int i = 1; i <= 1000; i++) {
    l += numberLength(i);
  }
  
  cout << l << "\n";
  return 0;
}
