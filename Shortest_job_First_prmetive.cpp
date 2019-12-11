#include<bits/stdc++.h>
using namespace std;

struct proc{
      string p;
      int bt;
      int art;

};
void wtTime(proc pcs[],int wt[],int n)
{
    int complt=0,shortest=0, minn=INT_MAX,t=0,finish;

    int rem_bt[n];
    for(int i=0;i<n;i++)
        rem_bt[i]=pcs[i].bt;

    while(complt!=n)
    {
        for(int j=0;j<n;j++)
        {
            if(pcs[j].art<=t&&rem_bt[j]<minn&&rem_bt[j]>0)
            {
                minn=rem_bt[j];
                shortest=j;

            }
        }

        rem_bt[shortest]--;
        minn=rem_bt[shortest];

        if(rem_bt[shortest]==0)
        {
            complt++;
            finish=t+1;
            wt[shortest]=finish-pcs[shortest].bt-pcs[shortest].art;
            minn=INT_MAX;
        }
        t++;

    }
}

void avgTime(proc pcs[],int n)
{
    int wt[n],tat[n];
    wtTime(pcs,wt,n);
    for(int i=0;i<n;i++)
        cout<<wt[i]<<endl;
}

int main()
{
    cout<<"Enter Number of process"<<endl;
    int n;
    cin>>n;
    struct proc pcs[n];
    for(int i=0;i<n;i++)
    {
        cin>>pcs[i].p;
        cin>>pcs[i].bt;
        cin>>pcs[i].art;
    }
    avgTime(pcs,n);

}
