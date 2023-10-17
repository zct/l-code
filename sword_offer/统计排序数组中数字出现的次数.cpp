
#include <bits/stdc++.h>

using namespace std;

Class Solution{
 public:
    int count(vector<int> nums, int target){
        int begin = 0;
        int end = nums.size() -1;
        while(begin <= end){
            int middle = (begin+end) / 2;
            if(nums[middle] > target ){
                end = middle -1;
            } else if ( nums[middle] < target){
                begin = middle +1;
            } else { //相等
                if(middle > 0 && nums[middle-1] == target){
                    end = middle -1;
                } else {
                    return middle;
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums{1,2,2,3,3,3,4,5};
    Solution s;
    int aIndex= s.count(nums, 3);
    cout << aIndex << endl;
}

