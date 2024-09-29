#include<iostream>
using namespace std;

// minimum no of deletion and insertion in str_1 to make it same as of str_2
int minimumDeletion(string &str_1, string &str_2){
    int maxCommon = 0;
    
    // count no of common series wise
    for(int i=0; str_1.length(); i++){
        int common = 0;
        for(int j=0; j<str_2.length(); j++){
            if(str_1[i] == str_2[j]){
                common++;
                i++;
            }
        }
        maxCommon = max(maxCommon, common);
    }

    int numberOfChanges = str_1.length() + str_2.length() - (2 * maxCommon); 
    return numberOfChanges;
}

int main(){
    string str_1 = "heap";
    string str_2 = "pea";
    int minimumDelet = minimumDeletion(str_1, str_2);
    cout<<minimumDelet<<endl;
    return 0;
}

