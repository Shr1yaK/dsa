class Solution {
public:
    int calPoints(vector<string>& operations) 
    {
        stack<int> st;
        for (int i = 0; i<operations.size(); i++)
        {
            if (isdigit(operations[i][0]) || operations[i][0] == '-')
                st.push(stoi(operations[i]));
            
            if (operations[i][0]=='C')
                st.pop();
            
            if (operations[i][0]=='D')
                st.push(2*st.top());
            
            if (operations[i][0]=='+')
            {
                int x = st.top();
                st.pop();
                int y = st.top();
                int rec = x+y;
                st.push(x);
                st.push(rec);
            }
        }
        
        int sum = 0;
        while(st.empty()!=true)
        {
            sum+=st.top();
            st.pop();
        }

        return sum;
    }
};