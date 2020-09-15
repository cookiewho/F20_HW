/*
 * Title: hw1_1.cpp
 * Abstract: This program outputs the most common numbers, in a set of two random lists, in ascending order.
 * Author: David Gaeta
 * ID: 4311
 * Date: 08/24/2020
 */
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
  int temp, size1, size2, max = 1;
  cin >> size1;
  map<int, int> standings;
  int x = 0;
  for(x; x < size1; x++){
    cin >> temp;
    if (standings.count(temp) < 1){
      standings[temp] = 1;
    }
    else{
      standings[temp]+=1;
      if (standings[temp] > max){
        max = standings[temp];
      }
    }
  }
  cin >> size2;
  size2 += x;
  for(x; x < size2; x++){
    cin >> temp;
    if (standings.count(temp) < 1){
      standings[temp] = 1;
    }
    else{
      standings[temp]+=1;
      if (standings[temp] > max){
        max = standings[temp];
      }
    }
  }
  cout << "Answer:";
  bool found = false;
  for(auto const y: standings){
    if (y.second > 1){
      cout << y.first << " ";
      found = true;
    }
  }

  if (found == false)
  {
    cout << "NONE";
  }
  cout << endl;
  return 0;
}