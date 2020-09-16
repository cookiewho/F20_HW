/*
 * Title: hw 2_1.cpp
 * Abstract: This program takes takes in two strings and checks if one is an anagram of the other.
 * Author: David Gaeta
 * ID: 4311
 * Date: 09/03/2020
 */
#include <iostream>
#include <map>
#include <string>
#include <sstream>
using namespace std;
int main(){
    string str;
    map<char,int[2]> characters;
    getline(cin, str);
    bool fStr = false;
    for (int x = 0; x < str.length(); x++){
        if (str[x] == ' '){
            fStr = true;
        }
        else if(fStr == true){
            if (characters.find(str[x])!=characters.end()){
                characters[str[x]][1] -= 1;
            }
            else{
                cout << "NO ANAGRAM"<< endl;
                return 0;
            }
        }
        else{
            if (sizeof(characters[str[x]]) < 1){
                characters[str[x]][0] = 1;
                characters[str[x]][1] = 1;
            }
            else{
                characters[str[x]][0] += 1;
                characters[str[x]][1] += 1;
            }
        }
    }
    std::ostringstream ans;
    for(auto const y: characters){
        if(y.second[1] != 0){
            cout <<"NO ANAGRAM"<< endl;
            return 0;
        }
        ans << y.first << ":" << y.second[0]<< endl;
    }
    cout << "ANAGRAM"<< endl << ans.str() << endl;
    return 0;
    
}