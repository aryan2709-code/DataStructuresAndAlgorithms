#include<iostream>
#include<stack>
using namespace std;

bool isOperand(char c)
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') )
        return true;
        
        return false;
    }
    string postToInfix(string exp) {
        int i = 0;
        int n = exp.size();
        stack<string> st;
        
        while(i < n)
        {
            char c = exp[i];
            if(isOperand(c))
            {
                string temp = "";
                temp.push_back(c);
                st.push(temp);
            }
            else //It's an operator
            {
             string top1 = st.top(); st.pop();
             string top2 = st.top(); st.pop();
             string newStr = '(' + top2 + c + top1 + ')';
             st.push(newStr);
            }
            i++;
        }
        return st.top();
    }

    int main()
    {
        cout << postToInfix("abc*+d-")<<endl;
        cout << postToInfix("xyz-w+*v/")<<endl;
        return 0;
    }