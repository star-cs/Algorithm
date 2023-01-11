/*
给定一个长度为n的字符串，再给定m个询问，每个询问包含四个整数 l_1,r_1,l_2,r_2​，
请你判断 [l_1,r_1] 和 [l_2,r_2] 这两个区间所包含的字符串子串是否完全相同。

字符串中只包含大小写英文字母和数字。

数据范围  1≤n,m≤105

分析：
字符串前缀哈希法，将字符串变成一个p进制数字，实现不同的字符串映射到不同的数字
对字符串 X_1X_2X_3...X_{n-1}X_{n} ​，采用字符的ascii码乘上P的次方来计算哈希值

映射公式：(X1​∗Pn−1+X2​∗Pn−2+...+Xn−1​∗P1+Xn​∗P0) mod Q

注意：
1、任何字符不可映射为0
2、冲突问题，通过巧妙设置P为131或13331，Q= 2^{64}，一般不会产生冲突

比较不同区间的子串是否相同，就转为对应的哈希值是否相同

求l-r一段的哈希值公式 h[r]-h[l-1]*P^{r-l+1}
*/
#include<iostream>
using namespace std;
typedef unsigned long long ull;//ull溢出相当于对2^64取模 
const int N=100010, P=131;//P一般取131或13331
int n,m;
char str[N];
ull h[N],p[N];
ull get(int l,int r){
	//求l~r一段的哈希值公式 
	return h[r]-h[l-1]*p[r-l+1];
} 
int main(){
	scanf("%d%d%s",&n,&m,str+1);
	p[0]=1;
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]*P;//求p的次幂 
		h[i]=h[i-1]*P+str[i];//求前缀哈希值 
	}
	while(m--){
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		if(get(l1,r1)==get(l2,r2)) puts("Yes");
		else puts("No");
	}
	return 0;
}
