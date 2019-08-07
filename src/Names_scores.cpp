/*
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

#include<bits/stdc++.h> 
#include <iostream>

using namespace std;

typedef long long num;

string readName() {
  string result;
 
  while (true) {
    char c = cin.get();
    
    if (!cin || c == ',') break;
    
    if (c == '"') continue;
    
    result += c;
  }

  return result;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  
  set<string> names;
  map<string, int> sorted;
  num sum = 0, pos = 1;
  
  while (true) {
    auto name = readName();
    
    if (name.empty()) break;
    
    names.insert(name);
  }
  
  for (auto name : names) sorted[name] = pos++;
  
  for (auto name : sorted) {
    int value = 0;
    
    for (auto c : name.first) value += c - 'A' + 1;
    
    sum += value * name.second;
  }
  
  cout << sum << "\n";
  return 0;
}
