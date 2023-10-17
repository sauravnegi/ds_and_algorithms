// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<int, int> mp;
        int j=0;
        int i=0;
        int max=0;
        
        while(j<s.length()){
            
            mp[s[j]]++;
            
            if(mp[s[j]] <= 1){
                //no duplicates  
                
                if(j-i+1 > max){
                    max = j-i+1;
                }
                
                j++;
            }
            else{
                //duplicate came
                
                //delete from left till the duplicate element is erased.
                while(!mp.empty() && mp[s[j]] > 1){
                    
                    mp[s[i]]--;
                    
                    if(mp[s[i]] == 0)
                        mp.erase(s[i]);
                    
                    i++;
                }
                
                j++;
            }
        }
        
        return max;
    }
};