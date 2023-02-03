/*Mirza Mohibul Hasan*/
/*CSE-19@JUST*/
#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define mod 1000000007
#define ll long long
#define li long int
#define ld long double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define nl "\n"
#define fast_run ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
int main()
{
    fast_run;
    int processes[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof processes / sizeof processes[0];
    int burst_time[] = {12, 9, 7, 15, 6, 4};

    // int n;
    // cout<<"Enter number of the process"
    // cin >> n;
    // int processes[n];
    // int burst_time[n];
    // for (int i = 0; i < n; i++)
    // {
    //     processes[i]=i+1;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> burst_time[i];
    // }

    int wt[n], total_wt = 0, total_tat = 0;
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = burst_time[i - 1] + wt[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        cout << "Waitting time for P["<<i+1<<"] = " << wt[i] << endl;
    }

    cout << "Average waiting time = " << (1.00)*total_wt /n;
    return 0;
}