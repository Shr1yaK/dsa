class Solution {
public:
    string decodeString(string s) 
    {
        stack<int> counts;
        stack<string> strings;
        string curr = "";
        int num = 0;

        for (char c : s)
        {
            if (isdigit(c))
            {
                num = num * 10 + (c-'0');
            }
            else if (c=='[')
            {
                counts.push(num);
                strings.push(curr);
                num=0;
                curr = "";
            }
            else if (c>='a' && c<='z')
            {
                curr+=c;
            }
            else
            {
                string temp = curr;

                curr = strings.top();
                strings.pop();

                int repeat = counts.top();
                counts.pop();

                while (repeat--)
                {
                    curr += temp;
                }
            }
        }
        return curr;    
    }
};