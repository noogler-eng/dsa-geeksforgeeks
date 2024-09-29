// reverse words
// string is given in which words are seprated by dot, we have to reverse them
#include<iostream>
#include<stack>
#include <string.h>
using namespace std;

// input: i.like.this.program.very.much
// output: much.very.program.this.like.i
// using recursion

// this is recursive approach
string split(string &s){
    string temp = "";
    
    int i=0;
    while(i < s.length() && s[i]!='.'){
        temp += s[i];
        i++;
    }

    if(i < s.length()){
        s.erase(0, i+1);
    }else{
        s = "";
    }
    return temp;
}

void revserString(string &s){
    
    // if string length == 0
    if(s.length() == 0) return;

    string temp = split(s);
    revserString(s);
    if(s.length() == 0) {
        s+=temp;
    }else{
        s+='.'+temp;
    }
}


// best approach
// reverse words only by stack
// time compelxity is o(n)
// space complexity is o(n)
string reverse(string s){
    stack<string> st;
    string new_str = "";

    // pushing words to stack
    string word = "";
    for(int i=0; i<s.length(); i++){
        if(s[i] == '.'){
            st.push(word);
            word = "";
            continue;
        }
        word+=s[i];
    }
    st.push(word);

    // removing words from stack
    int size = st.size();
    for(int i=0; i<size-1;i++){
        new_str += st.top() + '.';
        st.pop();
    }
    new_str += st.top();
    st.pop();

    return new_str;

}

int main(){ 
    string s = "i.like.this.program.very.much";
    cout<<reverse(s)<<endl;
    cout<<" -- -- "<<endl;
    revserString(s);
    cout<<s<<endl;

    return 0;
}   