#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Process {
    int id;
    int capacity;
    int deadline;
    int period;
    int remaining_capacity;
    int next_deadline;
};

struct GanttChartEntry {
    int process_id;
    int start_time;
    int end_time;
};

// Comparator function to sort processes based on the next deadline
bool compareDeadline(const Process& a, const Process& b) {
    return a.next_deadline < b.next_deadline;
}

// Function to compute the greatest common divisor (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute the least common multiple (LCM)
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

void scheduleEDF(vector<Process>& processes, int total_time, vector<GanttChartEntry>& gantt_chart) {
    int time = 0;

    while (time < total_time) {
        // Update deadlines and capacities of processes
        for (auto& p : processes) {
            if (time % p.period == 0) {
                p.next_deadline = time + p.deadline;
                p.remaining_capacity = p.capacity;
            }
        }

        // Sort processes by their next deadline
        sort(processes.begin(), processes.end(), compareDeadline);

        // Find the next process to execute
        for (auto& p : processes) {
            if (p.remaining_capacity > 0) {
                cout << "At time " << time << ", executing process " << p.id << " (remaining capacity: " << p.remaining_capacity << ")\n";
                gantt_chart.push_back({ p.id, time, time + 1 });
                p.remaining_capacity--;
                break;
            }
        }

        time++;
    }
}

void printGanttChart(const vector<GanttChartEntry>& gantt_chart) {
    cout << "\nGantt Chart:\n";
    /*int temp = 0;
    for (const auto& entry : gantt_chart) {
    aa:
        if (entry.start_time == temp) {
            cout << "P " << entry.process_id << " (" << entry.start_time << " - " << entry.end_time << ")  ||  ";
            temp = entry.end_time;
        }
        else {
            cout << "IDLE (" << temp << " - " << temp + 1 << ")  || ";
            temp++;
            goto aa;
        }
    }
    cout << endl << endl;*/
    for (const auto& entry : gantt_chart) {
        cout << "P " << entry.process_id << " (" << entry.start_time << " - " << entry.end_time << ")  ||  ";
    }
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "\n\n";

    vector<Process> processes(n);
    for (int i = 0; i < n; ++i) {
        processes[i].id = i + 1;
        cout << "Process# " << processes[i].id << endl;
        cout << "Capacity: ";
        cin >> processes[i].capacity;
        cout << "Deadline: ";
        cin >> processes[i].deadline;
        cout << "Period: ";
        cin >> processes[i].period;
        processes[i].remaining_capacity = processes[i].capacity;
        processes[i].next_deadline = processes[i].deadline;
        cout << endl;
    }

    // Calculate the total scheduling time as the LCM of all periods
    int total_time = processes[0].period;
    for (int i = 1; i < n; ++i) {
        total_time = lcm(total_time, processes[i].period);
    }

    cout << "The total scheduling time is: " << total_time << "\n\n";

    vector<GanttChartEntry> gantt_chart;
    scheduleEDF(processes, total_time, gantt_chart);

    printGanttChart(gantt_chart);

    return 0;
}
