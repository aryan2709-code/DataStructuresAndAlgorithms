#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
    void reverseStr(string& s)
    {
        int n = s.size();
        for(int i=0; i<n/2; i++)
        {
            swap(s[i],s[n-i-1]);
        }
        for(int i=0; i<n; i++)
        {
            if(s[i] == '(') s[i] = ')';
            else if(s[i] == ')') s[i] = '(';
        }
    }
     int priority(char c)
    {
        if(c == '^')
        return 3;
        else if(c == '*' || c == '/')
        return 2;
        else if(c == '+' || c == '-')
        return 1;
        
        return -1;
    }
    bool isOperand(char c)
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') )
        return true;
        
        return false;
    }
    
    string infixToPrefix(string &s) {
        reverseStr(s); //Reverse the given infix
        int n = s.size();
        stack<char> st;
        string ans = "";
        int i = 0;
        
        // Infix to postfix using controlled conversion
        while(i < n)
        {
            char c = s[i];
            if(isOperand(c))
            {
                ans.push_back(c);
            }
            else if(c == '(')
            st.push(c);
            else if(c == ')')
            {
                while(!st.empty() && st.top() != '(')
                {
                    ans.push_back(st.top());
                    st.pop();
                }
                st.pop(); //Pop the opening bracket too
            }
            else //it's an operator
            {
                if(c == '^')
                {
                    while(!st.empty() && priority(st.top()) >= priority(c))
                    {
                        ans.push_back(st.top());
                        st.pop();
                    }
                    
                    st.push(c);
                }
                else
                {
                   while(!st.empty() && priority(st.top()) > priority(c))
                   {
                       ans.push_back(st.top());
                       st.pop();
                   }
                    
                   st.push(c); 
                }
            }
            i++;
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        // Reverse the answer before returning
        reverse(ans.begin(),ans.end());
        return ans;
    }

    int main()
    {
        string infix1 = "A+B*C-D";
        string infix2 = "(A-B)/(C+D)";
        cout << infixToPrefix(infix1) << endl;
        cout << infixToPrefix(infix2) << endl;
        return 0;
    }
