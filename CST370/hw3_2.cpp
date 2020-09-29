/*
 * Title: hw3_2.cpp
 * Abstract: This program takes in an x and y dimension and makes
 a matrix out of it. It then fills the matrix with the following x,y
 pairs, and outputs the values of the matrix (representing the edges) in ascending order.
 * Author: David Gaeta
 * ID: 4311
 * Date: 09/10/2020
 */
#include <iostream>
using namespace std;

int main(){
    int x_max, y_max, x, y, z=0;
    cin >> x_max >>  y_max;
    int matrix[x_max][x_max] = {0};
    while(z < y_max){
        cin >> x >> y;
        if (x < x_max && y < y_max && x != y){
            matrix[x][y] = 1;   
        }
        z++;
    }
    for(int x=0 ; x<x_max ; x++){
        cout << x;
        for(int y=0 ; y<x_max ; y++){
            if (matrix[x][y] == 1){
                cout << "->" << y;
            }
        }
        cout << endl;
    }
 }