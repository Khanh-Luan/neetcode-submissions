class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> s;

        for(const string& op: operations) {
            if(op == "C") {
                s.pop_back();
            } else if(op == "D") {
                s.push_back(2*s.back());
            } else if(op == "+") {
                int n = s.size();
                s.push_back(s[n-1] + s[n-2]);
            } else {
                s.push_back(stoi(op));
            }
        }
        
        return accumulate(s.begin(),s.end(),0);
    }
};