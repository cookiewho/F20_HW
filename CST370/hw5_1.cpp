/*
 * Title: hw 5_2.cpp
 * Abstract: This program takes in a size and list of that saize, and outputs the partitioned form of that list,
 *           where we define partitioned as seperating the negative numbers from the positive numbers.
 * Author: David Gaeta
 * ID: 4311
 * Date: 09/24/2020
 */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    int size, temp, ind = 0;
    bool neg = false;
    string inp;
    cin >> size;
    int nums1[size];
    int nums2[size];
    cin >> std::ws;
    getline(cin, inp);
    istringstream input(inp);
    
    for(int z = 0; z < size; z++){//Take in list
        input>>temp;
        nums1[z] = (temp);
        nums2[z] = (temp);
    }
    cout << endl << endl << endl; 
    int x = 0, y = size-1; // method 1
    while(x < y){
        if(nums1[x] >= 0){// check x is greater than or equal 0
            if(nums1[y]<0){// check y is less than 0
                temp = nums1[y];
                nums1[y] = nums1[x];
                nums1[x] = temp;
                x++;
            }
            else{y--;}
        }
        else{
            x++;
        }
    }
    
    for(int z = 0; z < size; z++){ // output method 1
        cout << nums1[z] << " ";
    }
    cout << endl;
    for(int x = 0; x < size; x++){ //method 2
        if(nums2[x] >0){
            int y = x;
            while(y < size){
                if(nums2[y] < 0){
                    temp = nums2[y];
                    nums2[y] = nums2[x];
                    nums2[x] = temp;
                    break;
                }
                y++;
            }
            if(y == size){
                break;
            }
        }
    }
    for(int z = 0; z < size; z++){ // output method 2
        cout << nums2[z] << " ";
    }
    cout << endl;
    
}
 /*
 BAD CODE THAT IS UGLY AND AWFUL< BUT AM LEAVING IN FOR MY OWN RECORDS
    x = 0, y = 0;
    while(j < size-1){
        while(nums2[i] < 0){
            i++;
        }while(nums2[i] >= 0 && y < size-1){
            y++;
        }
        if (nums2[x] > 0 && nums2[y] > 0){
            break;
        }
        temp = nums2[y];
        nums2[y] = nums2[x];
        nums2[x] = temp;
    }
    
    int i = 0, j = 1;
    while(j < size && (nums2 [i] >= 0 && nums2[j] >= 0)){ // check if both positive???
        while(nums2[i] < 0){// NOT positive
            i++;
        }
        while(nums2[j] >= 0){
            j++;
        }
        //SWAPPING!
        temp = nums2[j];
        nums2[j] = nums2[i];
        nums2[i] = temp;
    }
    */
      /*
    int j = 0;
    for(int x = 0; x < size; x++){
        if(nums2[x] < 0){
            if(nums2[j] < 0){
                cout <<" " << 0 << " "  << nums2[j] <<  endl;
                while(nums2[j] < 0){
                    cout <<" " << j << " "  << nums2[j] <<  endl;
                    j++;
                }
            }
            if(nums2[j] >= 0){
                cout <<"SWAPING" << nums2[x] << " "  << nums2[j] <<  endl;
                temp = nums2[j];
                nums2[j] = nums2[x];
                nums2[x] = temp;
                cout <<"SWAPED" << nums2[x] << " "  << nums2[j] <<  endl << endl;
            }
        }
    }
    */