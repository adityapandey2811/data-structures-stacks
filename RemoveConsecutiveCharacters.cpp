string removeConsecutiveCharacter(string s)
{
    int i = 0;
    stack<char> st;
    if(st.empty()){
        st.push(s[i]);
        i++;
    }
    while(s[i]!='\0'){
        if(s[i] != st.top()){
            st.push(s[i]);
        }
        i++;
    }
    vector<char> v;
    while(st.size() != 0){
        v.push_back(st.top());
        st.pop();
    }
    string res = "";
    i = v.size() - 1;
    while(i >= 0){
        res = res + v[i];
        i--;
    }
    return res;
}
