#include<fstream>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int a,b;
int main()
{
    ifstream input("input");
    ifstream user_output("user_output");
    input>>a>>b;
    int x;
    user_output>>x;
    if(x!=a+b) return true;//答案错误
    return false;//答案正确
}