class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack <int> st;
        for (int i = 0; i<asteroids.size(); i++)
        {
            bool alive = true;
            
            while (!st.empty() && st.top()>0 && asteroids[i]<0)
            {
                if (abs(asteroids[i]) < st.top())
                {
                    alive = false;
                    break;
                }

                    else if (abs(asteroids[i]) == st.top())
                    {
                        st.pop();
                        alive=false;
                        break;
                    }

                else
                    st.pop();    
            }

            if (alive==true)
                st.push(asteroids[i]);
        }

        vector <int> answer;
        while(!st.empty())
        {
            answer.push_back(st.top());
            st.pop();
        }
        reverse(answer.begin(), answer.end());
        
        return answer;
    }
};