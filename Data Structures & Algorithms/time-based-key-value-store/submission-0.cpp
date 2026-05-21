class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        // here we have to do that sorting 

        // if we do not find then print ""
        if(mp.find(key)==mp.end()){
            return "";
        }

        // assigning a vector to store the value of mp[key] 
        // which is vector of {timestamp,value}

        auto &vec=mp[key];

        string ans="";

        int left=0;
        int right=vec.size()-1;

        while(left<=right){
            int mid=left+(right-left)/2;
            if (vec[mid].first<=timestamp){
                ans=vec[mid].second;

                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
    }
};
