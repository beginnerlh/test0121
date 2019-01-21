//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
//
//如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
//
//注意你不能在买入股票前卖出股票。
//
//示例 1:
//
//输入 : [7, 1, 5, 3, 6, 4]
//输出 : 5
// 解释 : 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6 - 1 = 5 。
//	  注意利润不能是 7 - 1 = 6, 因为卖出价格需要大于买入价格。
//	  示例 2 :
//
//  输入 : [7, 6, 4, 3, 1]
//   输出 : 0
//	解释 : 在这种情况下, 没有交易完成, 所以最大利润为 0。



//给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
//
//说明 :
//
//初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
//你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
//示例 :
//
//输入 :
//	nums1 = [1, 2, 3, 0, 0, 0], m = 3
//	nums2 = [2, 5, 6], n = 3
//
//输出 : [1, 2, 2, 3, 5, 6]
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
int maxProfit(int* prices, int pricesSize) {
	int max = 0;
	int b = 0;
	for (int i = 0; i<pricesSize - 1; i++)
	{
		int a = prices[i + 1] - prices[i];
		b += a;
		if (b<0)
		{
			b = 0;
		}
		if (b>max)
		{
			max = b;
		}
	}
	return max;
}

void merge(int* nums1, int m, int* nums2, int n) {

	for (int i = m; i<m + n; i++)
	{

		nums1[i] = nums2[i - m];

	}
	for (int i = 0; i<n + m - 1; i++)
	{
		for (int j = i + 1; j<n + m; j++)
		{
			if (nums1[i]>nums1[j])
			{
				int temp = nums1[i];
				nums1[i] = nums1[j];
				nums1[j] = temp;
			}
		}

	}
	for (int i = 0; i<n + m; i++)
	{
		printf("%d ", nums1[i]);
	}
	printf("\n");

}
int main()
{
	//int arr[] = { 7, 1, 5, 3, 6, 4 };
	//int len = sizeof(arr) / sizeof(int);
	//int a = maxProfit(arr, len);
	//printf("%d\n", a);
	/*nums1 = [1, 2, 3, 0, 0, 0], m = 3
		nums2 = [2, 5, 6], n = 3*/
	int nums1[1000] = { 1, 2, 3 };
	int nums2[] = { 2, 5, 6 };
	merge(nums1, 3, nums2, 3);
	system("pause");
	return 0;
}