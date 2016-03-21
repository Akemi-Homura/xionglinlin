#include <bits/stdc++.h>
using namespace std;
#define MAX 150100
bool tag[MAX];
map<int,set<int>>flag;
vector<int>pos;
int a[MAX],n,ans;
bool checkPos(int p)
{
	if(!p || p==n)return true;
	if((p&1) && a[p]>=a[p+1])return false;
	if(!(p&1) && a[p]<=a[p+1])return false;
	return true;
}
void trySwap(int p)
{
	//printf("p=%d\n",p);
	for(int i=1;i<=n;i++)
	{
		if(p!=i)
		{
			swap(a[p],a[i]);
			bool ok=false;
			for(auto c:pos)
				if(!checkPos(c))
				{
					ok=false;
					return;
				}
			if(checkPos(p) && checkPos(p-1) && checkPos(i) && checkPos(i-1))
			{
				printf("i=%d j=%d\n",p,i);
				if(flag[p].find(i)==flag[p].end() && flag[i].find(p) == flag[i].end())
				{
					flag[p].insert(i);	flag[i].insert(p);
					++ans;
				}
			}
			swap(a[p],a[i]);
		}
	}
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		if(!checkPos(i) && !tag[i])
		{
			tag[i]=tag[i+1]=true;
			pos.push_back(i);
			pos.push_back(i+1);
		}
	}
	if(pos.size()>4)
	{
		printf("0\n");
		return 0;
	}
	trySwap(pos[0]);
	trySwap(pos[0]+1);
	cout<<ans<<endl;
	return 0;
}