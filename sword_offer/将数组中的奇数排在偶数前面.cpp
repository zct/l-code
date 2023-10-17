class Solution
{
public:
    void resort(vector<int> &nums)
    {
        int begin = 0;
        int end = nums.size() - 1;
        while (begin < end)
        {
            while (nums[begin] % 2 != 0)
            {
                begin++;
            }
            while (nums[end] % 2 == 0)
            {
                end--;
            }
            if (begin >= end)
                break;
            swap(nums[begin++], nums[end--]);
        }
    }
};

int main()
{
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8};
    Solution s;
    s.resort(nums);
    for (auto &num : nums)
    {
        cout << num << endl;
    }
}