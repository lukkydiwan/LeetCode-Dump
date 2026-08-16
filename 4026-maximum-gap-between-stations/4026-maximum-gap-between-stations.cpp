class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size();
        int m = station.size();
        vector<int> earliest(n);
        vector<int> latest(skill.size());
        int j=0;
        for(int i = 0; i < n; i++) {
            while(station[j] != skill[i]) {
                j++;
            }

            earliest[i] = j;
            j++;
        }
       j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (station[j] != skill[i]) {
                j--;
            }
            latest[i] = j;
            j--;
        }
        int ans=0;
        for(int i=1; i<skill.size(); i++){
            ans=max(ans,latest[i]-earliest[i-1]);
        }
        return ans;
    }
};