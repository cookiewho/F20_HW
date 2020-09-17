/*
 * Title: hw 2_2.cpp
 * Abstract: This program takes takes in two time 
 * Author: David Gaeta
 * ID: 4311
 * Date: 09/03/2020
 */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(){
    string s1, s2, temp1 = "", temp2 = "";
    cin >> s1;
    cin >> s2;
    int temp3, temp4, count = 0;
    int ans [3];
    for(int x = 0; x < s1.length(); x++){
        if(s1[x] == ':'){
            temp3 = stoi(temp1);
            temp4 = stoi(temp2);
            if (count == 0){
                if (temp4 <temp3){
                    temp4+=24;
                }   
                ans[count] = temp4-temp3;
                count+=1;
            }
            else{
                if (temp4 < temp3){
                    temp4+=60;
                    ans[count-1] -= 1;
                }   
                ans[count] = temp4-temp3;
                count+=1;
                    
            }
            temp1 = "";
            temp2 = "";
            
        }else{
            temp1 += s1[x];
            temp2 += s2[x];
        }
    }
    temp3 = stoi(temp1);
    temp4 = stoi(temp2);
    if (temp4 < temp3){
            temp4+=60;
            ans[count-1] -= 1;
            }   
            ans[count] = temp4-temp3;
    std::ostringstream result;
    for(int y = 0; y < 3; y++){
        if (ans[y] < 10){
            result << "0";
        }
        if(y != 2){
            result << ans[y] << ":";
        }
        else{
            result << ans[y];
        }
    }
    cout << result.str() << endl;
}