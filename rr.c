#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

struct Process {
    int id;
    int burst_time;
    int remaining_time;
};

void roundRobinScheduling(struct Process processes[], int n, int quantum) {
    int time = 0;
    int total_remaining_time = 0;
    
    for (int i = 0; i < n; i++) {
        total_remaining_time += processes[i].burst_time;
        processes[i].remaining_time = processes[i].burst_time;
    }

    while (total_remaining_time > 0) {
        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                int execution_time = (processes[i].remaining_time < quantum) ? processes[i].remaining_time : quantum;
                processes[i].remaining_time -= execution_time;
                total_remaining_time -= execution_time;

                printf("Time %d: Process %d is running for %d units\n", time, processes[i].id, execution_time);
                time += execution_time;

                if (processes[i].remaining_time == 0) {
                    printf("Time %d: Process %d has completed\n", time, processes[i].id);
                }
            }
        }
    }
}

int main() {
    int n, quantum;
    struct Process processes[MAX_PROCESSES];

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    printf("Enter burst times for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        scanf("%d", &processes[i].burst_time);
    }

    roundRobinScheduling(processes, n, quantum);

    return 0;
}
