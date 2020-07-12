/*
* @Description: 113. 特殊排序
* @Author: Xiaobin Ren
* @Date:   2020-07-12 10:44:20
* @Last Modified time: 2020-07-12 12:23:09
*/


// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.

class Solution {
public:
    vector<int> specialSort(int N) {
        vector<int> v;
        for(int i = 1; i <= N; i++) v.push_back(i);
        stable_sort(v.begin(), v.end(), compare);
        return v;
    }
};