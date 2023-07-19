//Problem link: https://practice.geeksforgeeks.org/problems/check-frequencies4211/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
#include <string>
#include <vector>

class Solution {
public:
    bool isSame(std::vector<int>& freq) {
        int temp = 0;
        for(auto it:freq){
            if(it>0)
            {
                temp=it;
                break;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (temp != freq[i]&&freq[i]!=0)
                return false;
        }
        return true;
    }

    bool sameFreq(std::string s) {
        std::vector<int> freq(26, 0);
        for (auto it : s) {
            freq[it - 'a']++;
        }
        if (isSame(freq))
            return true;
        for (int i = 0; i < 26; i++) {
            if(freq[i]>0){
                freq[i]--;
                if (isSame(freq))
                return true;
                //cout<<i<<" "<<freq[i]<<" ";
            freq[i]++;
            }
        }
        return false;
    }
};