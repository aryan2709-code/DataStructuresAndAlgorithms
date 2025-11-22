#include<iostream>
#include<stack>
using namespace std;

bool isOperand(char c)
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') )
        return true;
        
        return false;
    }
    string postToPre(string post_exp) {
        string str = post_exp;
        stack<string> st;
        int n = str.size();
        int i = 0;
        while(i < n)
        {
            char c = str[i];
            if(isOperand(c))
            {
                string temp = "";
                temp += c;
                st.push(temp);
            }
            else
            {
                string top1 = st.top(); st.pop();
                string top2 = st.top(); st.pop();
                string newStr = c + top2 + top1;
                st.push(newStr);
            }
            i++;
        }
        return st.top();
    }

    int main()
    {
        cout << postToPre("ABC/-AK/L-*")<<endl;
        cout << postToPre("ab+")<<endl;
    }