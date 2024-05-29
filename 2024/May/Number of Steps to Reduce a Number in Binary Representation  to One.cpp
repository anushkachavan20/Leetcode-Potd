class Solution {
public:
    int numSteps(string s) {
 
        
        int ans = 0;
        int i = s.size()-1;
        
        while(s != "1"){
            if(s[s.size()-1] == '1'){
                s[s.size()-1] = '0';
                //carry in
                int j = s.size()-1-1;
                while(j >= 0 && s[j] == '1'){
                    s[j] = '0';
                    j--;
                }
                if(j == -1){
                    s = '1' + s;
                }else{
                    s[j] = '1';
                }
                ans++;
            }
            
            // cout << "s: " << s << ", ans: " << ans << endl;
            
            while(s[s.size()-1] == '0'){
                s.erase(s.size()-1, 1);
                ans++;
            }
            
            // cout << "s: " << s << ", ans: " << ans << endl;
        }
        
        
        return ans;
    }
};
