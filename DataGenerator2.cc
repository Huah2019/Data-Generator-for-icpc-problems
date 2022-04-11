#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 gen(time(0));
//随机生成[l,r]内的整数
int rdint(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}
const int N=1e6+5,mod=998244353;
int a,b;
void getoutput()
{//运行标程，需要同一文件夹内存在可执行文件std.exe
    system("std");
}
void Getgenerators(vector<pair<pair<int,int>,function<void()>>>&generators)
{
    function<void()>gen;
    gen=[&]()
    {//a>=0且b>=0的数据
        int a=rdint(0,1000000000),b=rdint(0,1000000000);
        printf("%d %d\n",a,b);
    };
    generators.push_back({{1,2},gen});//{数据组数[1,2]，生成器1}
    gen=[&]()
    {//a<=0且b>=0的数据
        int a=-1*rdint(0,1000000000),b=rdint(0,1000000000);
        printf("%d %d\n",a,b);
    };
    generators.push_back({{3,6},gen});//{数据组数[3,6]，生成器2}
    gen=[&]()
    {//a<=0且b<=0的数据
        int a=-1*rdint(0,1000000000),b=-1*rdint(0,1000000000);
        printf("%d %d\n",a,b);
    };
    generators.push_back({{7,8},gen});//{数据组数[7,8]，生成器3}
    gen=[&]()
    {//a>=0且b<=0的数据
        int a=rdint(0,1000000000),b=-1*rdint(0,1000000000);
        printf("%d %d\n",a,b);
    };
    generators.push_back({{9,10},gen});//{数据组数[9,10]，生成器4}
}
void work(string in,string out,function<void()>getinput)
{
    cout<<in<<' '<<out<<endl;
    freopen(in.data(),"w",stdout);
    getinput();
    freopen("CON","w",stdout);
    freopen(in.data(),"r",stdin);
    freopen(out.data(),"w",stdout);
    getoutput();
    freopen("CON","r",stdin);
    freopen("CON","w",stdout);
}
string tostring(int x)
{
    if(x==0) return "0";
    string ans="";
    while(x)
    {
        ans+=(char)(x%10+'0');
        x/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
void genData()
{
    vector<pair<pair<int,int>,function<void()>>>generators;
    Getgenerators(generators);
    for(auto x:generators)
    {
        for(int id=x.first.first;id<=x.first.second;id++)
            work("data/"+tostring(id)+".in","data/"+tostring(id)+".out",x.second);
    }
}
int main()
{
    srand(time(0));
    genData();
    cout<<"OK"<<endl;
}
