#include "StayTogether.h"

#define Max(a,b) (a>b?a:b)

/* ���������⣺��������
����ֻ��1��2��3����Ԫ�ص����飬����ͳ��1��2��3�ĸ�����
ϣ������ܹ��������˼·�����磬��С�Ŀռ䣬���ٵĴ�����
===================
���һ��������
ԭ��
����һ�����飬������ֻ����0��1�����ҵ�һ����������У�����0��1����������ͬ�ġ�
��1��10101010 ��������䱾��
��2��1101000 �����110100
����չ���Լ���˼·��
����*/

/*
 *Author : Xiaowang99
 *Time : 2013-07-21
*/

/*������
  ���ַ�����0���ַ����������-1����1���������1����ô��ͷ���ַ����������
  �õ��µ��ַ�������ʱֻ��Ҫ���µ��ַ���������ȡ��������ͬ�����ĳ��ȾͿ���
  ���� 010123210����ô��ľ���8
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
	/*�ҵ�һ������������ͬ���ݵ�����ȣ��ҵ�˼·�Ǳ����������п��ܵ���ֵ*/
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
