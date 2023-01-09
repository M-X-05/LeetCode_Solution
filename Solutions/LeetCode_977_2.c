#include<malloc.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize)
{
	*returnSize = numsSize;
	int* answer = (int*)malloc(numsSize * sizeof(int));
	//����ָ�뽻���ƶ���Ԫ�ص�������answer
	int left = 0, right = numsSize - 1;
	int p = numsSize - 1;
	while (p >= 0)
	{
		if (nums[left] + nums[right] >= 0)
		{
			answer[p] = nums[right] * nums[right];
			right--;
			p--;
		}
		else
		{
			answer[p] = nums[left] * nums[left];
			left++;
			p--;
		}
	}
	return answer;
}