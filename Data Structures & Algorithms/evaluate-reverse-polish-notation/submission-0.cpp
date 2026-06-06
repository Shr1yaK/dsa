class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack <int> st;
        for (int i = 0; i<tokens.size(); i++)
        {
            string token = tokens[i];
            if (token=="+")
            {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                int z = x+y;
                st.push(z);
            }
            
            if (token=="-")
            {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                int z = y-x;
                st.push(z);
            }

            if (token=="*")
            {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                int z = x*y;
                st.push(z);
            }

            if (token=="/")
            {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                int z = y/x;
                st.push(z);
            }

            if (token != "+" && token != "-" && token != "*" && token != "/")
                st.push(stoi(token));
        }

        return st.top();
    }
};