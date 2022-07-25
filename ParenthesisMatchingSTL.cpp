bool isValid(string s) {
    stack<char> st;
    int i = 0;
    if(s[i] == ')' || s[i] == ']' || s[i] == '}')
        return false;
    while(s[i] != '\0'){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        }
        if(s[i] == ')'){
            if(!st.empty() && st.top() == '(')
                st.pop();
            else
                return false;
        }
        if(s[i] == ']'){
            if(!st.empty() && st.top() == '[')
                st.pop();
            else
                return false;
        }
        if(s[i] == '}'){
            if(!st.empty() && st.top() == '{')
                st.pop();
            else
                return false;
        }
        i++;
    }
    if(st.empty())
        return true;
    return false;
}




//Updated Solution Nothing much change

#include <bits/stdc++.h>
using namespace std;
bool parenthesisMatching(vector<char> &v)
{
    stack<char> s;
    vector<char>::iterator it = v.begin();
    while (it != v.end())
    {
        if (*it == '(')
        {
            s.push(*it);
            it++;
            continue;
        }
        else if (*it == ')')
        {
            if (s.empty() || s.top() != '(')
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
        if (*it == '[')
        {
            s.push(*it);
            it++;
            continue;
        }
        else if (*it == ']')
        {
            if (s.empty() || s.top() != '[')
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
        if (*it == '{')
        {
            s.push(*it);
            it++;
            continue;
        }
        else if (*it == '}')
        {
            if (s.empty() || s.top() != '{')
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
        it++;
    }
    if (s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    vector<char> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        v.push_back(c);
    }
    bool res = parenthesisMatching(v);
    if (res)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
