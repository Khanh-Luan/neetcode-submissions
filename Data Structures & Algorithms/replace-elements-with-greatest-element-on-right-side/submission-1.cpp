class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int highestele = -1;
        vector<int> ans(arr.size());
        for(int i = arr.size()-1; i>=0; i--){
            ans[i] = highestele;
            highestele = max(highestele, arr[i]);
        }
        return ans;
    }
};