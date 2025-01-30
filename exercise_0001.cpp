#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::unordered_map<int, int> hash;
		for (int i = 0; i < nums.size(); i++) {
			hash[nums[i]] = i;
		}
		
		for (int i = 0; i < nums.size(); i++) {
			int complement = target - nums[i];
			if (hash.find(complement) != hash.end() && hash[complement] != i) {
				return {i, hash[complement]};
			}
		}
		return {};
	}
};

void test() {
	Solution solution;
	{
		std::vector<int> nums = {2, 7, 11, 15};
		int target = 9;
		std::vector<int> result = solution.twoSum(nums, target);
		std::vector<int> expected = {0, 1};
		assert(result == expected);
		std::cout << "Test Case 1 Passed" << std::endl;
	}
	{
		std::vector<int> nums = {3, 2, 4};
		int target = 6;
		std::vector<int> result = solution.twoSum(nums, target);
		std::vector<int> expected = {1, 2};
		assert(result == expected); 
		std::cout << "Test Case 2 Passed" << std::endl;
	}
	{
		std::vector<int> nums = {3, 3};
		int target = 6;
		std::vector<int> result = solution.twoSum(nums, target);
		std::vector<int> expected = {0, 1};
		assert(result == expected);
		std::cout << "Test Case 3 Passed" << std::endl;
	}
}