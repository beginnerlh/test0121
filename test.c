//����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�
//
//��������ֻ�������һ�ʽ��ף������������һ֧��Ʊ�������һ���㷨�����������ܻ�ȡ���������
//
//ע���㲻���������Ʊǰ������Ʊ��
//
//ʾ�� 1:
//
//���� : [7, 1, 5, 3, 6, 4]
//��� : 5
// ���� : �ڵ� 2 �죨��Ʊ�۸� = 1����ʱ�����룬�ڵ� 5 �죨��Ʊ�۸� = 6����ʱ��������������� = 6 - 1 = 5 ��
//	  ע���������� 7 - 1 = 6, ��Ϊ�����۸���Ҫ��������۸�
//	  ʾ�� 2 :
//
//  ���� : [7, 6, 4, 3, 1]
//   ��� : 0
//	���� : �����������, û�н������, �����������Ϊ 0��



//�������������������� nums1 �� nums2���� nums2 �ϲ��� nums1 �У�ʹ�� num1 ��Ϊһ���������顣
//
//˵�� :
//
//��ʼ�� nums1 �� nums2 ��Ԫ�������ֱ�Ϊ m �� n��
//����Լ��� nums1 ���㹻�Ŀռ䣨�ռ��С���ڻ���� m + n�������� nums2 �е�Ԫ�ء�
//ʾ�� :
//
//���� :
//	nums1 = [1, 2, 3, 0, 0, 0], m = 3
//	nums2 = [2, 5, 6], n = 3
//
//��� : [1, 2, 2, 3, 5, 6]
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