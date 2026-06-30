class Solution {
public:
    string addBinary(string a, string b) 
    {
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        int sum = 0;
        string answer = "";
        while (i>=0 || j>=0 || carry!=0)
        {
            sum = carry;
            if (i>=0) sum = sum + a[i]-'0'; 
            if (j>=0) sum = sum + b[j]-'0';
            answer += ((sum%2) + '0');
            carry = sum/2;
            i--;
            j--;
        }  
        reverse(answer.begin(), answer.end());
        return answer;
    }
};