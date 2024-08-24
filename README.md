This repository contains a C++ implementation of the Earliest Deadline First (EDF) scheduling algorithm. The EDF algorithm is a dynamic scheduling algorithm used in real-time systems to prioritize tasks based on their deadlines. The task with the earliest deadline is given the highest priority.

**Overview**

The code simulates the scheduling of multiple periodic processes using the EDF algorithm. The processes have defined capacities (execution times), deadlines, and periods. The scheduler runs through a time frame determined by the least common multiple (LCM) of the periods of all processes. During each time unit, the process with the nearest deadline and remaining capacity is executed.

**Features**
1. Dynamic Scheduling: The scheduler dynamically adjusts the order of execution based on the deadlines of the processes.
2. LCM Calculation: The total scheduling time is computed as the LCM of all process periods, ensuring that the schedule is complete and periodic.
3. Gantt Chart: A Gantt chart is generated to visualize the execution timeline of each process.
   
**Code Structure**
1. Process Structure: Each process is represented by a structure containing its ID, capacity, deadline, period, remaining capacity, and next deadline.
2. GanttChartEntry Structure: Represents an entry in the Gantt chart, containing the process ID, start time, and end time of execution.
3. Functions:
   
    1) compareDeadline: Comparator to sort processes based on their next deadline.
  
    2) gcd and lcm: Utility functions to compute the greatest common divisor and least common multiple, respectively.
  
    3) scheduleEDF: The main function that simulates the EDF scheduling.
  
    4) printGanttChart: Outputs the Gantt chart showing the process execution timeline.
