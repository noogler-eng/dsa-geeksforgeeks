// Report spam message
// time complexity o(n), space complexity o(n)
// if two or more banned words appeard in array of messages then return true

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string, int> m;

        // filling the hashmap and moving forward
        for(int i=0; i<message.size(); i++){
            m[message[i]]++;
        }

        // finding the map
        int n = m.size();

        if( message.size() < 2) return false;

        // removing the element and erasing from map
        for(int i=0; i<bannedWords.size(); i++){
            if(m.find(bannedWords[i]) != m.end()){
                if(m[bannedWords[i]] >= 2){
                    return true;
                }else{
                    m.erase(bannedWords[i]);
                }
            }
        }

        // if the size if map is decrease by 2 or more then returning true
        if(m.size() <= n-2){
            return true;
        }

        return false;
    }
};