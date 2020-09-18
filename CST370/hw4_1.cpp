/*
 * Title: hw 4_1.cpp
 * Abstract: This program takes in a set of elements, and outputs all possible permutations of it;
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
    int size, count, x = 0;
    string input, word = "";
    cin >> size;
    if(size == 0){
        cout << "0:EMPTY";
        return 0;
    }
    string sets[size];
    set<std::string> checker={};
    cin >> std::ws;
    getline(cin, input);
    cout << endl;
    for(int y = 0; y < input.length() ; y++){
        if (input[y] != ' '){
            word += input[y];
            
        }
        else{
            if(checker.find(word) == checker.end()){
                checker.insert(word);// check if already in set
                sets[x] = word;
                x++;
                word = "";
            }
        }
    }
    if(checker.find(word) == checker.end()){
        checker.insert(word);
        sets[x] = word;
    }
    size = checker.size();
    for(int z = 0; z < pow(2,size); z++){
        string chars="";
        string bitNum = "";
        bool on = false;
        for(int a = 0; a < size ; a++){
            int max =  z << (size-a);
            if (z & (1<<a)){
                bitNum = "1" + bitNum;
                chars = sets[(size-a) -1]+ " " + chars;
                on = true;
            }
            else{
                bitNum = "0" + bitNum;
            }
        }
        if (on){
            cout << bitNum << ":" << chars;
        }
        else{
            cout << bitNum << ":EMPTY";
        }
        cout << endl;
    }
    return 0;
}