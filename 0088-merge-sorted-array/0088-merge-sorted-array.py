class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        nums = nums1[:m]
        i1,i2,i = 0,0,0
        while (i1 < m) and (i2 < n):
            if nums[i1] < nums2[i2]:
                nums1[i] = nums[i1]
                i1+=1
            else:
                nums1[i] = nums2[i2]
                i2+=1
            i+=1
        while i1<m:
            nums1[i] = nums[i1]
            i+=1
            i1+=1
        while i2<n:
            nums1[i] =nums2[i2]
            i+=1
            i2+=1
        

        