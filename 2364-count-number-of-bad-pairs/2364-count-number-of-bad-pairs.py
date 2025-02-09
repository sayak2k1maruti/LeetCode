class Solution(object):
    def countBadPairs(self, nums):
        nums1 = [nums[i]-i for i in range(0,len(nums))]
        good_count_dict = {}
        for n in nums1:
            if n in good_count_dict:
                good_count_dict[n] += 1
            else:
                good_count_dict[n] = 1
        good_pair = 0
        for good_count in good_count_dict.values():
            good_pair += good_count * (good_count - 1)/2
        return len(nums) * (len(nums) - 1)/2 - good_pair
        