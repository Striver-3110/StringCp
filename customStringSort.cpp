#include <bits/stdc++.h>

class Solution
{
public:
    string customSortString(string order, string s)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < 26; i++)
        {
            mp[(char)(i + 97)] = 0;
        }
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            mp[s[i]]++;
        }
        string ans = "";
        int olen = order.length();
        for (int j = 0; j < olen; j++)
        {
            int freq = mp[order[j]];
            while (freq--)
            {
                ans += order[j];
                mp[order[j]]--;
            }
        }
        for (auto it : mp)
        {
            if (it.second != 0)
            {
                for (int i = 0; i < it.second; i++)
                    ans += it.first;
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;

    // Example usage
    std::string order = "cba";
    std::string s = "abcd";

    std::string result = solution.customSortString(order, s);

    std::cout << "Custom Sorted String: " << result << std::endl;

    return 0;
}
