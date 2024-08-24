//main.cpp
 
#include <iostream>
#include <vector> // Include the vector header
#include "function.h"

using namespace std;

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
