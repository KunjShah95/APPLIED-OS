#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task
{
    int id;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
};

void fcfsScheduling(vector<Task> &tasks)
{
    int current_time = 0;
    sort(tasks.begin(), tasks.end(), [](const Task &a, const Task &b)
         { return a.arrival_time < b.arrival_time; });

    for (auto &task : tasks)
    {
        task.start_time = max(current_time, task.arrival_time);
        task.completion_time = task.start_time + task.burst_time;
        current_time = task.completion_time;

        cout << "Task " << task.id
             << " | Start: " << task.start_time
             << " | End: " << task.completion_time
             << " | Waiting: " << (task.start_time - task.arrival_time)
             << " | Turnaround: " << (task.completion_time - task.arrival_time) << endl;
    }
}

int main()
{
    vector<Task> tasks = {
        {1, 0, 5}, // id, arrival, burst
        {2, 1, 3},
        {3, 2, 2}};

    cout << "FCFS Scheduling:\n";
    fcfsScheduling(tasks);
    return 0;
}