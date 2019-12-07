#include<bits/stdc++.h>
using namespace std;

void fun(string pcs[],int bt[],int ar[],int qntm,int n)
{
    int rem_bt[n];
    int tat[n],wt[n];
    int time=0,remain,i;
    remain=n;
    for(i=0;i<n;i++)
    {
        rem_bt[i]=bt[i];
    }
    i=0;
    while(remain!=0)
    {
       if(rem_bt[i]<=qntm&&rem_bt[i]>0)
       {    cout<<pcs[i]<<"->";
           time+=rem_bt[i];
           rem_bt[i]=0;
           wt[i]=time-bt[i]-ar[i];
           tat[i]=time-ar[i];
           remain--;

       }
       else if(rem_bt[i]>qntm)
       {   cout<<pcs[i]<<"->";
           time+=qntm;
           rem_bt[i]-=qntm;

       }

       if(i==n-1)
        i=0;
       else if(ar[i+1]<=time)
        i++;
       else i=0;
    }

    cout<<"\n";
    int avgtotal=0,avgwait=0;

    for(int j=0;j<n;j++)
    {
        avgtotal+=tat[j];
        avgwait+=wt[j];
       cout<<pcs[j]<<"-->"<<"wait:"<<wt[j]<<" tat:"<<tat[j]<<endl;
    }

     cout<<"AvgTat:"<<(float(avgtotal)/float(n))<<"AvgWait:"<<(float(avgwait)/float(n))<<endl;



}

int main()
{
    cout<<"Enter Number of procese"<<endl;
    int n;
    cin>>n;
    int bt[n],ar[n];
    string pcs[n];

    for(int i=0;i<n;i++)
    {
      cin>>pcs[i];
      cin>>bt[i];
      cin>>ar[i];
    }

    cout<<"Enter quantam"<<endl;
    int qntm,j,key,key1;
    string key2;
    cin>>qntm;

    for(int i=1;i<n;i++)
    {
        key=ar[i];
        key1=bt[i];
        key2=pcs[i];
        j=i-1;
        while(j>=0&&ar[j]>key)
        {
            ar[j+1]=ar[j];
            pcs[j+1]=pcs[j];
            bt[j+1]=bt[j];
            j=j-1;
        }
        ar[j+1]=key;
        bt[j+1]=key1;
        pcs[j+1]=key2;
    }

    fun(pcs,bt,ar,qntm,n);
}
