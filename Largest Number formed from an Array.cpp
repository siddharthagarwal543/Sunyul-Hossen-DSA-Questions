//https://leetcode.com/problems/largest-number/description/

class Solution {//TC O(N^2) SC O(1) using selection sort
public:
    bool compare(int s1,int s2){
        string a=to_string(s1),b=to_string(s2);
        string case1=a+b,case2=b+a;//if two nums are given, there are two cases possible
        for(int i=0;i<case1.size();i++){//checking for the pivot point
            if(case1[i]-'0'>case2[i]-'0')//at pivot point if case1 is greater i.e s1 should come before s2 in string, so return true
            {
                return true;
            }
            else if(case1[i]-'0'<case2[i]-'0')//by similar logic return false
            {
                return false;
            }
        }
        return true;
    }
    string largestNumber(vector<int>& nums) {
         string ans="";
        for(int i=0;i<nums.size();i++){//applying selection sort
            int temp=i;
            for(int j=i+1;j<nums.size();j++){
                if(compare(nums[j],nums[temp]))
                temp=j;
            }
            swap(nums[i],nums[temp]);
            ans+=to_string(nums[i]);

        }
         bool all_zero=true;//checking for corner case [0,0] ans should be "0"
        for(auto it:ans){
            if(it!='0')
            {all_zero=false;
            break;}
        }
        if(all_zero)
        return "0";
        return ans;
    }
};

class Solution {//TC O(nlogn) SC O(1) Using STL Sort function
public:
    static bool compare(int s1,int s2){
        return to_string(s1)+to_string(s2)>to_string(s2)+to_string(s1);
    }
    string largestNumber(vector<int>& nums) {
         string ans="";
         sort(nums.begin(),nums.end(),compare);
        for(int i=0;i<nums.size();i++){//making resultant string
            ans+=to_string(nums[i]);
        }
         bool all_zero=true;//checking for corner case [0,0] ans should be "0"
        for(auto it:ans){
            if(it!='0')
            {all_zero=false;
            break;}
        }
        if(all_zero)
        return "0";
        return ans;
    }
};