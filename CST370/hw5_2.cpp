/*
 * Title: hw 5_2.cpp
 * Abstract: This program takes in a number of verticies and edges and takes in the starting Vertex.
 *           It then tries to find the cheapest cycle it can take from start to start, with the
 *           constraint that it has to visit every vertex.
 * Author: David Gaeta
 * ID: 4311
 * Date: 09/24/2020
 */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    
    int verticies, edges, x, y, cost, start, z = 0;
    cin >> verticies >> edges;
    int matrix[verticies][verticies] = {0};
    while(z < edges){
        cin >> x >> y >> cost;
        if(x < verticies && y < verticies && x != y){
            matrix[x][y] = cost;
        }
        z++;
    }
    cin >> start;
    for(int x=0 ; x<verticies ; x++){
        cout << x;
        for(int y=0 ; y<verticies ; y++){
            if (matrix[x][y] != 0){
                cout << "--" << matrix[x][y] << "->" << y ;
            }
        }
        cout << endl;
    }
    //ALL ABOVE IS INPUT
    
    //ALGORITHM MAGIC HERE
}