/*
4
26 3 17 5
*/
#include<bits/stdc++.h>
using namespace std;
int sumarray(int arr[],int n)
{
    if(n== 0)
    {
        return 0;
    }
    return arr[n-1] + sumarray(arr,n-1);
}
int main()
{
    int n;
    cin>>n;
    int arr[1000];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum = sumarray(arr,n);
    cout<<sum<<endl;

}