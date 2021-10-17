class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        /* 初始化度与解 */
        metric = 0; answer =0;

        for (int i = 0; i < nums.size(); i ++ ) {
            /* 记录不同数值首次出现的坐标 AND 度 */
            if (!map[nums[i]].second){
                map[nums[i]].second++ ;
                map[nums[i]].first = i; 
            } else {
                map[nums[i]].second++ ;
            } 

            /* 更大的度，答案更新成最小的。 */
            if (metric < map[nums[i]].second){ 
                metric = map[nums[i]].second;
                /* 1 2 2 3 : 迭代记录[2 2]，最短的即为2 2*/
                answer = i - map[nums[i]].first + 1;
            }

            /* 遇到有多个度相同的则取最小的子数组长 */
            if (metric == map[nums[i]].second) 
            {
                answer = min(answer, i - map[nums[i]].first + 1);
            }
        }
        return answer;
    }
private:
    int metric;
    int answer;
    unordered_map<int, pair<int, int>> map;
};

