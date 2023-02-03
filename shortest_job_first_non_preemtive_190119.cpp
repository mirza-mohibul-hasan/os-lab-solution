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

struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

int main()
{
    int n;
    struct process p[100];
    float avg_waiting_time;

    int total_waiting_time = 0;
    int total_response_time = 0;
    int total_idle_time = 0;
    float throughput;
    int is_completed[100];
    memset(is_completed, 0, sizeof(is_completed));
    cout << "Enter the number of processes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time of process " << i + 1 << ": ";
        cin >> p[i].arrival_time;
        p[i].pid = i + 1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Enter burst time of process " << i + 1 << ": ";
        cin >> p[i].burst_time;
    }

    int current_time = 0;
    int completed = 0;
    int prev = 0;
    while (completed != n)
    {
        int idx = -1;
        int mn = 10000000;
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival_time <= current_time && is_completed[i] == 0)
            {
                if (p[i].burst_time < mn)
                {
                    mn = p[i].burst_time;
                    idx = i;
                }
                if (p[i].burst_time == mn)
                {
                    if (p[i].arrival_time < p[idx].arrival_time)
                    {
                        mn = p[i].burst_time;
                        idx = i;
                    }
                }
            }
        }
        if (idx != -1)
        {
            p[idx].start_time = current_time;
            p[idx].completion_time = p[idx].start_time + p[idx].burst_time;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
            total_waiting_time += p[idx].waiting_time;
            total_idle_time += p[idx].start_time - prev;

            is_completed[idx] = 1;
            completed++;
            current_time = p[idx].completion_time;
            prev = current_time;
        }
        else
        {
            current_time++;
        }
    }
    avg_waiting_time = (float)total_waiting_time / n;
    cout << "P-ID  "
         << "Arival "
         << "Burst "
         << "Waitting " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << p[i].pid << "\t" << p[i].arrival_time << "\t" << p[i].burst_time << "\t" << p[i].waiting_time << "\t"
             << "\n"
             << endl;
    }
    cout << "Total Waiting Time = " << total_waiting_time << nl;
    cout << setprecision(2) << fixed << "Average Waiting Time = " << avg_waiting_time << nl;
}