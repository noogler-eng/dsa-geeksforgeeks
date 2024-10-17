// check wheather the given parenthis is balanced or not
#include<iostream>
#include<stack>
using namespace std;
bool isBalanced(string s){

    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '[' || s[i] == '(' || s[i] == '{'){
            // if there is open bracket then pushing to the stack
            st.push(s[i]);
        }else{
            // if bracket is closing 
            if((s[i] == ']' && st.top() == '[') || (s[i] == ')' && st.top() == '(') || (s[i] == '}' && st.top() == '{')){
                st.pop();
            }else{
                return false;
            }
        }
    }

    if(st.empty()) return true;
    return false;

}
int main(){
    string s = "()[{}()]";
    bool ans = isBalanced(s);
    cout<<ans<<endl;
    return 0;
}