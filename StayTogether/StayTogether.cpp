#include "StayTogether.h"

#define Max(a,b) (a>b?a:b)

/* 今日面试题：巧妙排序
排序只有1，2，3三个元素的数组，不能统计1，2，3的个数。
希望大家能够相出多多的思路。比如，最小的空间，最少的次数。
===================
相伴一生分析：
原题
给定一个数组，数组中只包含0和1。请找到一个最长的子序列，其中0和1的数量是相同的。
例1：10101010 结果就是其本身。
例2：1101000 结果是110100
请大家展开自己的思路。
分析*/

/*
 *Author : Xiaowang99
 *Time : 2013-07-21
*/

/*分析：
  将字符串内0的字符都变成数字-1，而1都变成数字1，那么从头对字符串进行相加
  得到新的字符串，此时只需要从新的字符串和里面取得所有相同加数的长度就可以
  比如 010123210，那么最长的就是8
*/

int main(int argc, char** argv)
{
	int key;
	cout<<LongestPair("01110")<<endl;
	cin>>key;
	return 1;
}

int LongestPair(string input)
{
	string temp = input;
	int strLen = input.length();

	int* p = (int*)malloc(sizeof(int) * (strLen+1)); 
	p[0] = 0;
	for(int i = 0; i< strLen; i++)
	{
		p[i+1] = p[i] + (input[i] == '1'?1:-1);

		cout<<"Number "<<i<<" :"<<p[i]<<endl;
	}

	return LongestDis(p,strLen + 1);
}

int LongestDis(int *p, int intLen)
{
	/*找到一个数组里面相同数据的最长长度，我的思路是遍历里面所有可能的数值*/
	int maxDis = 0;
	int maxTempDis = 0;

	for(int i = 0; i< intLen; i++)
	{
		maxDis = Max(maxDis,maxTempDis);
		maxTempDis = 0;
		for(int j = intLen-1;j >= i; j--)
		{
			if(p[j] == p[i])
			{
				maxTempDis = j-i;
				break;
			}
		}
	}
	
	return maxDis;
}
