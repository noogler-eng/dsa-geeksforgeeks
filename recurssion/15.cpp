// generate all valid balance parentesis
#include<iostream>
using namespace std;
// input: n = 2
// output: ()(), .... all valid parenthisis



// by binary tree help we find that if nOpen == nClose then do not use close bracket it is hamfull
void balanceParenthesis(int nOpen, int nClose, string res){

    if( nOpen == 0 && nClose == 0){
        cout<<res<<endl;
        return;
    }

    // it will work only when nOpen!=nClose
    // we can only use close bracket when we already some open bracket
    if(nOpen < nClose){
        string res_1 = res + ')';
        balanceParenthesis(nOpen, nClose - 1, res_1);
    }

    // using open here, it will always work
    if(nOpen > 0){
        string res_1 = res + '(';
        balanceParenthesis(nOpen - 1, nClose, res_1);
    }

}

int main(){
    int n = 3;
    // we are taking care of open and close brackets differently
    balanceParenthesis(n, n, "");
    return 0;
}