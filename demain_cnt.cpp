class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        for(const string& str : cpdomains){
            string tmp_str = "", domains = "";
            for(const char& ch : str){
                if(ch == ' ')
                    break;
                tmp_str += ch;
        }

            int acc_cnt = atoi(tmp_str.c_str());
            
            for(int i = str.size() - 1; i >= tmp_str.size(); i--){
                if(str[i] == '.' || str[i] == ' '){
                    map[domains] += acc_cnt;
                }
                domains = str[i] + domains;
            }
        }

        for(unordered_map<string, int>::iterator iter = map.begin(); iter != map.end(); iter++){
            data.emplace_back(to_string(iter->second) + " " + iter->first);
        }
        return data;
    }
private:
    unordered_map<string, int> map;
    vector<string> data;
};
