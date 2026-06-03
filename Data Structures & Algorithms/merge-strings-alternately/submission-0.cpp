class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        int n1 = word1.size();
        int n2 = word2.size();
        string mergedstring;

        int p1=0;
        int p2=0;
        while (p1<n1 && p2<n2)
        {
            mergedstring += word1[p1++];
            mergedstring += word2[p2++];
        }

        // cout<<p1;
        // cout<<p2;

        if (p1<n1)
        {
            while (p1<n1)
                mergedstring += word1[p1++];
        }

        if (p2<n2)
        {
            while (p2<n2)
                mergedstring += word2[p2++];
        }

        return mergedstring;
    }
};