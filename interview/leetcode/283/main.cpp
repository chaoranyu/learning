// A C++ program to move all zeroes at the end of numsay
#include <iostream>
#include <vector>
using namespace std;

// Function which pushes all zeros to end of an numsay.
void moveZeroes(vector<int>& nums) {
    for (int r=0, w=0; r<nums.size(); ++r)
        if (nums[r])
            swap(nums[r], nums[w++]);
}

// Driver program to test above function
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(8);
    nums.push_back(9);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(0);
    cout << "nums before:\n";
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout<<endl;

    moveZeroes(nums);
    cout << "nums after:\n";
    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout<< endl;
    return 0;
}
