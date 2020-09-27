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
#include <algorithm>
#include <climits>
using namespace std;

void display(int a[][0], int n) 
{ 
	for (int i = 0; i < n; i++) 
	{ 
		cout << a[i] << " "; 
	} 
	cout << endl; 
} 

int main(){
    
    int verticies, edges, x, y, cost, start, z = 0;
    cin >> verticies >> edges;
    int v_size = verticies-1;
    int matrix[verticies][verticies] = {};
    int vertexs[v_size];
    while(z < edges){
        cin >> x >> y >> cost;
        matrix[x][y] = cost;
        z++;
    }
    cin >> start;
    int count = 0;
    for(int z = 0; z <v_size; z++){
        if(count == start){count++;}
            {
            vertexs[z] = count;
            count++;
        }
    }
    int min_count=INT_MAX;
    string min_path = "";
    //ALGORITHM MAGIC HERE
    do{
        string s_temp = std::to_string(start) + "->";
        int count_temp = 0;
        int prev = start;
        for(int x=0 ; x<v_size; x++){  //one permutation
            int val = matrix[prev][vertexs[x]];
            if(val == 0){
                count_temp = 0;
                break;
            }
            else{
                count_temp += val;
                prev = vertexs[x];
                s_temp +=  std::to_string(vertexs[x]) + "->";
            }
        }
        int val = matrix[prev][start];//messy check to see if we can go back to start
        if(val == 0){
            count_temp = 0;
        }
        else{
            if(count_temp != 0){
                count_temp += val;
                s_temp += std::to_string(start);
                if(count_temp < min_count){
                    min_count = count_temp;
                    min_path = s_temp;
                }
            }
        }
    }while(next_permutation(vertexs, vertexs+v_size));//gets all permutations
    if (min_count == INT_MAX || min_count == 0){
        min_path = "";
        min_count = -1;
    }
    cout<< "Path:"<<min_path << endl << "Cost:" << min_count << endl;
    
}