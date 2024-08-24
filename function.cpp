// function.cpp

#include "function.h"
#include <iostream>
#include <algorithm>

bool compareDeadline(const Process& a, const Process& b) {
    return a.next_deadline < b.next_deadline;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

void scheduleEDF(std::vector<Process>& processes, int total_time, std::vector<GanttChartEntry>& gantt_chart) {
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
        std::sort(processes.begin(), processes.end(), compareDeadline);

        // Find the next process to execute
        for (auto& p : processes) {
            if (p.remaining_capacity > 0) {
                std::cout << "At time " << time << ", executing process " << p.id << " (remaining capacity: " << p.remaining_capacity << ")\n";
                gantt_chart.push_back({ p.id, time, time + 1 });
                p.remaining_capacity--;
                break;
            }
        }

        time++;
    }
}

void printGanttChart(const std::vector<GanttChartEntry>& gantt_chart) {
    std::cout << "\nGantt Chart:\n";
    for (const auto& entry : gantt_chart) {
        std::cout << "P " << entry.process_id << " (" << entry.start_time << " - " << entry.end_time << ")  ||  ";
    }
}
