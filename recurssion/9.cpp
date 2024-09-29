// tower of hanoi 
#include<iostream>
using namespace std;

// n disk are given with 3 stack, we have to move all the disk from stack_1 to stack_3
// we have to find the total no of moves
// constraint: order of disk must be smae anywhere like smaller comes upper then bigger one

// n is given as no of disk on stack_1 
// input n = 3

// source, destination, helper - 3 stacks


// solve(n , s->d, h)
void noOfWays(int n, int s, int d, int h, int &count){
    // when there is only one plate, move from source to destination
    if(n == 1) {
        cout<<"moving plate n from "<< s <<" to "<<d<<endl;
        count++;
        return;
    }

    // moving n-1 plates from source to destination
    // take out biggest plate and move to destination
    // solve(n-1 , s->h, d)

    // count++ measuring no of steps
    count++;
    noOfWays(n-1, s, h, d, count);
    cout<<"moving plate n from "<< s <<" to "<<d<<endl;

    // solve(n-1, h->d, s)
    noOfWays(n-1, h, d, s, count);
}

int main(){
    // this is no of disk
    int n = 3;
    int count = 0;
    noOfWays(n, 1, 2, 0, count);
    cout<<count<<endl;
    return 0;
}








