/*
 * Title: hw 4_2.cpp
 * Abstract: This program takes in a list of boxes with apple amounts, and outputs the permutation of boxes that
 *           gives the max number of apples, given that we dont take from two boxes directly next to each other.
 * Author: David Gaeta
 * ID: 4311
 * Date: 09/18/2020
 */
#include <iostream>
#include <string>
#include <math.h>
#include <set>
using namespace std;

int main(){
    int size, temp, ins = 0;
    cin >> size;
    int vals [size];
    while (ins < size){
        cin >> temp;
        vals[ins] = temp;
        ins++;
    }
    string max_string = "";
    int max_num = 0;
    for (int x = 0; x < pow(2,size); x++){
        string bit_string ="";
        bool next_to = false, valid = true;
        int temp_tot = 0;
        for(int y = 0; y < size; y++){
            if (x & (1 << y)){          // index = 1
                if(next_to){            //is next to a 1 already
                    valid = false;
                    break;
                }
                bit_string += to_string(y) + " ";
                temp_tot += vals[y];
                next_to = true;
            }
            else{                       //index == 0
                next_to = false;
            }
        }
        if(valid && (temp_tot > max_num)){
            max_num = temp_tot;
            max_string = bit_string;
        }
    }
    cout << "Boxes:" << max_string << "\nMax Apples:" << max_num;
}