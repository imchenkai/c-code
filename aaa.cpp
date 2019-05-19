#include<iostream>
using namespace std;
int ok(int t,int *z,int bit);
int a[9];
int main()
{
	int m,n,o,count=0;
	cout<<"将1到9 这九个数字分成4个数"<<endl;
    cout<<"要求"<<endl;
    cout<<"(1)4个数符合算式○○×○○=○○×○○○ "<<endl;
    cout<<"(2)正好用尽1到9这九个数字,数中数字不能有重复。"<<endl;
    cout<<"\n\n满足条件的结果如下"<<endl;
	for(m=12;m<=98;m++) /*试探可能的第一个数*/
      for(n=m+1;n<=98;n++) /*试探可能的第二个数*/ //保证算出的结果没有重复，如果n=12则结果为14组合
		  for(o=12;o<=98;o++)/*试探可能的第三个数*/
		{/*如果前两个数的乘积不能整除第三个数，排除掉该组合*/
		   if((m*n%o==0)&&ok(m,a,2)&&ok(n,a+2,2)&&ok(o,a+4,2)&&ok((m*n)/o,a+6,3)) /*若满足题意*/
	           cout<<"No."<<++count<<": "<<m<<"×"<<n<<"="<<o<<"×"<<(m*n)/o<<endl;/*输出结果*/
		}
     return 0;
}


int ok(int t,int *z,int bit) /*分解t的值，将其存入z指向的数组元素，若满足分解得到的各个数没有0或者无重复返回1，其中bit表示要分解的数的个数*/
{
	int *p1,*p2;
	for(p1=z;p1<z+bit;p1++)
	{
	*p1=t%10; /*分解整数*/
	if(*p1==0) return 0; //若分解得到0，则不符合要求，返回0
	t/=10;
	for(p2=a;p2<p1;p2++) /*查询分解出的数字是否已经出现过*/
	    if(*p2==*p1)return 0; /*如果出现重复数字则返回0*/
	}
	return 1; /*否则返回1*/
}