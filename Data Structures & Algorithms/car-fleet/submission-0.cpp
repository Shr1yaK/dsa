class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        vector <pair<int,int>> cars;
        for (int i = 0; i<position.size(); i++)
        {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());

        stack <double> fleet;
        for (int j = cars.size()-1; j>=0; j--)
        {
            double t = (double)(target - cars[j].first)/cars[j].second;
            if (fleet.empty() || t>fleet.top())
                fleet.push(t);
        }
        return fleet.size();
    }
};