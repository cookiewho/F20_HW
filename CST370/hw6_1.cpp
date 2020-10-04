/*
 * Title: hw 6_1.cpp
 * Abstract: This program takes in graph information, a starting location, and a number of hops allowed.
 *           The program then performs a bfs and outputs all locations from the starting location within
 *           the hops allowed, in alphabetical order.
 * Author: David Gaeta
 * ID: 4311
 * Date: 10/01/2020
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <sstream>
using namespace std;

int main(){
    vector<vector<int>> graph;
    map <int, string> idx_city;
    map <string, int> city_idx;
    map <string, int> answer;
    queue<int> q;
    int vertecies, edges, hops, hops_taken = 0;
    cin >> vertecies;
    string city;
    for(int x = 0; x < vertecies; x++){ //take in city names and assign inx to dictionary
        cin >> city;
        idx_city[x] = city;
        city_idx[city] = x;
    }
    //DEBUGGING FOR LOOP
    // for(auto const y: city_idx){
    //     cout << y.first << " " << y.second << endl;
    // }
    //END OF DEBUGGING FOR LOOP
    graph.resize(vertecies);
    vector<int> visited(graph.size(), 0);
    cin >> edges;
    string from, to;
    for(int z = 0; z < edges; z++){
        cin >> from >> to;
        graph[city_idx[from]].push_back(city_idx[to]);
    }
    int curr;
    cin >> from;
    curr = city_idx[from];
    cin >> hops;
    cout << endl;
    // DEBBUGING TO MAKE SURE THAT IT IS GOOD TO GO
    // cout<< "MATRIX CHECK : " << endl;
    // for (int i = 0; i < graph.size(); i++) 
    // {
    //     cout << i;
    //     for (int j = 0; j < graph[i].size(); j++) 
    //     {
    //         cout << " -> " << graph[i][j];
    //     }
    //     cout << endl;
    // }
    //END OF DEBUGGING
    q.push(curr);
    visited[curr]=1;
    if(hops > 0){answer[idx_city[curr]] = 0;}// add starting local to ans dict
    while((!q.empty()) ){
        // cout << "wow";
        curr = q.front();
        q.pop();
        
        // cout << "Visiting: " << curr << endl;
        for(int x = 0; x < graph[curr].size(); x++){
            int neighbor = graph[curr][x];
            // cout << "Neighbor to " << curr << ": " << neighbor << endl;
            if(visited[neighbor] == 0){
                visited[neighbor]=1;
                q.push(neighbor);
                hops_taken = answer[idx_city[curr]] + 1;
                if(hops_taken <= hops){
                    answer[idx_city[neighbor]] = hops_taken;
                }
            }
        }
        // cout <<"Hopes taken: "<< hops_taken<< endl;
    }
    // cout << "OUR ANSWER DICT" << endl;
    for(auto const y: answer){
        cout<<y.first<<":"<<y.second<<endl;
    }

}