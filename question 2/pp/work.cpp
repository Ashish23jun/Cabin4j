#include <iostream>
#include <fstream>
#include <bits/stdc++.h>


using  namespace std;

bool solve( string s ) {
   for( int i = 0; i < s.length(); i++ ) {
      if( !isdigit(s[i])) {
         return false;
      }
   }
   return true;
}

int convert(string s)
{
    // Initialize a variable
    int num = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
        num = num * 10 + (int(s[i]) - 48);
 
    // Print the answer
    return num;
}

void final(vector<string> ans){
    stack<int> st;
    int n = ans.size();
    for(int i=0;i<n;i++){
        // cout<<convert(ans[i])<<"\n";
        if(ans[i]=="") continue;
        if(solve(ans[i])==true){
            st.push(convert(ans[i]));
        }
        else if(ans[i]=="+"){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(a+b);
        }
        else if(ans[i]=="-"){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b-a);
        }
        else if(ans[i]=="*"){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(a*b);
        }
        else if(ans[i]=="/"){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b/a);
        }
    }
    // cout<<st.top();
    string app;
    ifstream in("str.txt");
    getline(in,app);
    string stri = to_string(st.top());
    stri = app+stri;
    ofstream out("str.txt");
    out<<stri<<"\n";
    cout<<st.top();

}

int priority (string alpha){
    if(alpha == "+" || alpha =="-")
        return 1;
 
    if(alpha == "*" || alpha =="/")
        return 2;
 
    if(alpha == "^")
        return 3;
    if(alpha == "(") return 0;
 
    return 0;
}

void print(vector<string>& inf){
    int n = inf.size();
    for (int i = 0; i < n; i++)
    {
        cout<<convert(inf[i])<<" ";
    }
    
}

void iftopos(vector<string> pos){
    int n = pos.size();
    vector<string> inf;
    stack<string> st;
    for(int i=0;i<n;i++){
        if(pos[i]=="+" || pos[i]=="-" || pos[i]=="*" || pos[i]=="/" || pos[i]=="^"){
            while (!st.empty() && priority(pos[i]) <= priority(st.top())){
                string temp = st.top();
                inf.push_back(temp);
                st.pop();
            }
            st.push(pos[i]);
        }
        else if(pos[i]=="("){
            st.push(pos[i]);
        }
        else if(pos[i]==")"){
            while(st.top()!="("){
                string temp = st.top();
                inf.push_back(temp);
                st.pop();
            }
            st.pop();
        }
        else{
            inf.push_back(pos[i]);
        }
    }
    final(inf);
    // print(inf);
}

void stto(string s,vector<string>& inf){
    int n = s.length();
    inf.push_back("(");
    for(int i=0;i<n;i++){
        if(s[i]=='=') break;
        string k = "";
        while(i<n){
            if(s[i]>=48 && s[i]<=57){
                k+=s[i];
            } 
            else{
                break;;
            }
            i++;
        }
        inf.push_back(k);
        k="";
        string l = "";
        l+=s[i];
        inf.push_back(l);
        
    }
    inf.push_back(")");
    // print(inf);
    iftopos(inf);
}


int main(){
    string s;
    ifstream in("str.txt");
    getline(in,s);
    cout<<s;
    vector<string> inf;
    stto(s,inf);

}