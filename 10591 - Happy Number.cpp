/***
**     Author: Khairul Anam Mubin
**     Bangladesh University of Business and Technology,
**     Dept. of CSE.
***/

using namespace std;

int main()
{
    long int a[10000],r,s,x,t,i,n,c,j,flag;

    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n;
        x=n;
        s=0;
        c=1;
        flag=1;
        while(s!=1){
            while(x!=0){
                r=x%10;
                s=s+(r*r);
                x/=10;
            }
            if(s==7){
                flag=1;
                break;
            }
            if(s!=1){
                a[c]=s;
                x=s;
                s=0;
                for(j=1;j<c;j++){
                    if(a[j]==x){
                        flag=0;
                        break;
                    }
                }
            }
            if(flag==0){
                break;
            }
            c++;
        }
        if(flag)
			printf("Case #%ld: %ld is a Happy number.\n",i,n);
        else
            printf("Case #%ld: %ld is an Unhappy number.\n",i,n);
    }
    return 0;
}
