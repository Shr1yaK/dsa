class Solution {
public:
    string simplifyPath(string path) 
    {
        string temp = "";
        stack <string> st;
        for (int i = 0; i<path.size();i++)
        {
            if (path[i]=='/')
            {
                if (temp == "" || temp == ".")
                {
                    temp="";
                    continue;
                }

                else if (temp=="..")
                {
                    if (!st.empty())
                        st.pop();
                }

                else
                    st.push(temp);

                temp = "";
            }

            else
                temp+=path[i];
        }

        if (temp == "..")
        {
            if (!st.empty()) 
                st.pop();
        }
            
        else if (temp != "" && temp != ".")
        {
            st.push(temp);
            temp="";
        }

        vector <string> v;
        while (!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        reverse (v.begin(), v.end());
        
        string answer = "";
        for (string s: v)
        {
            answer +="/";
            answer +=s;
        }

        if (answer=="")
            answer="/";


        return answer;   
    }
};