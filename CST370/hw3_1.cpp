/*
 * Title: hw3_1.cpp
 * Abstract: This program takes in a list of paired event hours
 and outputs the max number of overlaping event times.
 * Author: David Gaeta
 * ID: 4311
 * Date: 09/10/2020
 */
#include <iostream>
#include <map>
using namespace std;

int main(){
    int size, start, end, max = 0, x=0;
    map<int, int> count_hrs;
    cin >> size;
    while(x<size){
        cin >> start >> end;
        for(int y=start; y<end;y++){
            if(count_hrs.count(y) < 1){
                count_hrs[y] = 1;
                if(count_hrs[y] > max){
                    max = count_hrs[y];
                }
            }
            else{
                count_hrs[y] += 1;
                if(count_hrs[y] > max){
                    max = count_hrs[y];
                }
            }
        }
        x++;
    }
    cout << "Max events: " << max << endl;
    return max;
 }