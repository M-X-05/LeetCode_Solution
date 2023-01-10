int minSubArrayLen(int target, int* nums, int numsSize)
{
	int left = 0, right = 0, sum = nums[0], min_length = 100001;
	//left和right组成滑动窗口，sum超过target时移动left，否则移动right，窗口不断右移至终点
	while (1)
	{
		if (sum < target)
		{
			right++;
			if (right >= numsSize)
				break;
			sum += nums[right];
		}
		else if (sum >= target)
		{
			min_length = right - left + 1 < min_length ? right - left + 1 : min_length;
			sum -= nums[left];
			left++;
		}
	}
	if (min_length == 100001)
		min_length = 0;
	return min_length;
}