/*
 * Title: hw1_1.cpp
 * Abstract: This program calculates the minimum distance of any two numbers in a given set.
 * Author: David Gaeta
 * ID: 4311
 * Date: 08/24/2020
 */
#include <iostream>
using namespace std;

int main()
{
  int size, temp, minN1, minN2, min_dist = INT8_MAX;
  cin >> size;
  int arr[size];
  for(int x = 0; x < size; x++){
    cin >> temp;
    arr[x] = temp;
    for(int y = x-1; y >=0; y--)
    {
      if (abs(temp - arr[y]) < min_dist){
        min_dist = abs(temp-arr[y]);
        if (temp < arr[y]){
          minN1 = temp;
          minN2 = arr[y];
        }
        else{
          minN1 = arr[y];
          minN2 = temp;
        }
      }
    }
  }
  cout << "Min distance: "<< min_dist << endl << "Two numbers for min distance: " << minN1 << " and " << minN2 << endl; 
}