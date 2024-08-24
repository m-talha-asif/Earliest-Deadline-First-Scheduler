// function.h

#ifndef FUNCTION_H
#define FUNCTION_H

#include <vector>

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

bool compareDeadline(const Process& a, const Process& b);
int gcd(int a, int b);
int lcm(int a, int b);
void scheduleEDF(std::vector<Process>& processes, int total_time, std::vector<GanttChartEntry>& gantt_chart);
void printGanttChart(const std::vector<GanttChartEntry>& gantt_chart);

#endif
