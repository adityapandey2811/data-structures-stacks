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
