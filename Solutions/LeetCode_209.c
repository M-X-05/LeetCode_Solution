int minSubArrayLen(int target, int* nums, int numsSize)
{
	int left = 0, right = 0, sum = nums[0], min_length = 100001;
	//left��right��ɻ������ڣ�sum����targetʱ�ƶ�left�������ƶ�right�����ڲ����������յ�
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