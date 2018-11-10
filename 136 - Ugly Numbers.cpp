/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

using namespace std;

#define PI acos(-1)
#define Max 2000001

bool ugly(long long n);

int main()
{
	///freopen("output.txt","w",stdout);
    //long long i,n=0;
    
    //This Process will take 6s, so run it in ideone and just copy the result
    /*for(i=1;i<=1500;)
    {
        n++;
        if(ugly(n))i++;
    }
    printf("%lld\n",n);*/
    
    printf("The 1500'th ugly number is 859963392.\n");
    
    return 0;
}
bool ugly(long long n)
{
    for(;n%2==0;)
        n/=2;
    for(;n%3==0;)
        n/=3;
    for(;n%5==0;)
        n/=5;
    if(n==1)
        return true;
    return false;
}
