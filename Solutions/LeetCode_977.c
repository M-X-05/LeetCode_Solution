#include<malloc.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize)
{
	*returnSize = numsSize;
	int* answer = (int*)malloc(numsSize * sizeof(int));
	//1.全负全正
	if (nums[0] >= 0)
	{
		for (int i = 0; i < numsSize; i++)
			answer[i] = nums[i] * nums[i];
		return answer;
	}
	else if (nums[numsSize - 1] <= 0)
	{
		for (int i = numsSize - 1; i >= 0; i--)
			answer[numsSize - 1 - i] = nums[i] * nums[i];
		return answer;
	}
	//2.二分查找寻找负与非负交界点
	int length = (numsSize + 1) / 2, negative = (numsSize + 1) / 2, flag = 0;
	while (1)
	{
		if (nums[negative] >= 0)
		{
			length = (length + 1) / 2;  //length+1防止length为0进入死循环
			negative -= length;
		}
		else if (nums[negative + 1] < 0)
		{
			length = (length + 1) / 2;
			negative += length;
		}
		else
			break;
	}
	//3.左右指针交替移动，结果填入answer
	int p = 0;
	int nonnegative = negative + 1;
	while (negative >= 0 && nonnegative < numsSize)
	{
		if (nums[negative] + nums[nonnegative] >= 0)
		{
			answer[p] = nums[negative] * nums[negative];
			negative--;
			p++;
		}
		else
		{
			answer[p] = nums[nonnegative] * nums[nonnegative];
			nonnegative++;
			p++;
		}
	}
	while (negative >= 0)
	{
		answer[p] = nums[negative] * nums[negative];
		negative--;
		p++;
	}
	while (nonnegative < numsSize)
	{
		answer[p] = nums[nonnegative] * nums[nonnegative];
		nonnegative++;
		p++;
	}
	return answer;
}