// lemonade change
#include<iostream>
#include<vector>
using namespace std;
// returning true if every coustmer is satified
bool lemonadeChange(vector<int> coustmersGiven){
    //cost of single lemonde is $5
    int noOf5 = 0;
    int noOf10 = 0;
    int noOf20 = 0;

    int i=0;
    while(i < coustmersGiven.size()){
        if(coustmersGiven[i] == 5){
            noOf5++;
        }else if(coustmersGiven[i] == 10){
            if(noOf5 >= 1) {
                noOf5--;
                noOf10++;
            }else{
                return false;
            }
        }else{
            // first we will give rs 10 coin then afterward rs 5 for better handling
            // here greedyness is saving the money of 5 coin
            if(noOf5 >= 1 && noOf10 >=1){
                noOf20++;
                noOf5--;
                noOf10--;
            }else if(noOf5 >=3){
                noOf20++;
                noOf5-=3;
            }else{
                return false;
            }
        }
        i++;
    }
    return true;
}

int main(){
    vector<int> coustmersGiven = {5, 5, 5, 10, 20};
    int ans = lemonadeChange(coustmersGiven);
    cout<<ans<<endl;
    return 0;
}