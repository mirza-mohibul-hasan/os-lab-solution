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

struct process {
    int process_id;
    int arrival_time;
    int burst_time;
    int start_time;
    int waiting_time;
    int response_time;
};

int main() {
    int n;
    struct process p[100];
    float avg_waiting_time;
    int total_waiting_time = 0;
    int burst_remaining[100];
    int is_completed[100];
    memset(is_completed,0,sizeof(is_completed));

    cout<<"Enter the number of processes: ";
    cin>>n;

    for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time of process "<<i+1<<": ";
        cin>>p[i].arrival_time;
        p[i].process_id = i+1;
    }
    for(int i = 0; i < n; i++) {
        cout<<"Enter burst time of process "<<i+1<<": ";
        cin>>p[i].burst_time;
        p[i].process_id = i+1;
        burst_remaining[i] = p[i].burst_time;
    }

    int current_time = 0;
    int completed = 0;
    int prev = 0;
    while(completed != n) {
        int idx = -1;
        int mn = 10000000;
        for(int i = 0; i < n; i++) {
            if(p[i].arrival_time <= current_time && is_completed[i] == 0) {
                if(burst_remaining[i] < mn) {
                    mn = burst_remaining[i];
                    idx = i;
                }
                if(burst_remaining[i] == mn) {
                    if(p[i].arrival_time < p[idx].arrival_time) {
                        mn = burst_remaining[i];
                        idx = i;
                    }
                }
            }
        }

        if(idx != -1) {
            if(burst_remaining[idx] == p[idx].burst_time) {
                p[idx].start_time = current_time;
            }
            burst_remaining[idx] -= 1;
            current_time++; 
            if(burst_remaining[idx] == 0) {
                p[idx].waiting_time = current_time - p[idx].arrival_time - p[idx].burst_time;
                total_waiting_time += p[idx].waiting_time;
                is_completed[idx] = 1;
                completed++;
            }
        }
        else {
             current_time++;
        }  
    }
    avg_waiting_time = (float) total_waiting_time / n;
    cout << "P-ID  "<< "Arival "<< "Burst "<<"Waitting "<< nl;

    for (int i = 0; i < n; i++)
    {
        cout << p[i].process_id << "\t" << p[i].arrival_time << "\t" << p[i].burst_time << "\t"<< p[i].waiting_time<< "\t"<< "\n"<< nl;
    }
    cout << "Total Waiting Time = " << total_waiting_time << nl;
    cout<< setprecision(2) << fixed << "Average Waiting Time = " << avg_waiting_time << nl;

}