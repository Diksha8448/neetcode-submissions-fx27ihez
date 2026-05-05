class Solution {
public:
    //encode size+#+string itself simpleeeee
    string encode(vector<string>& strs) {
          string result="";

          for(string s:strs){
              result+=to_string(s.size())+"#"+s;
          }

          return result;
    }
    // decode 
    vector<string> decode(string s) {
          vector<string>result;

          int i=0;
          while(i<s.size()){
            int j=i;
            while(s[j]!='#'){
                j++;
            }

            int len=stoi(s.substr(i,j-i));
            string word=s.substr(j+1,len);

            result.push_back(word);

            i=j+len+1;
          }

          return result;
    }
};
