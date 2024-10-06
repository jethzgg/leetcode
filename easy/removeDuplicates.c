int removeDuplicates(int* nums, int numsSize) {
    int last = nums[0], counts = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != last) {
            counts += 1;
            nums[counts-1] = nums[i];
            last = nums[i];
        }
    }
    return counts;
}