#include <iostream>
#include <cstdlib>
using namespace std;
int allocated_servers = 0;
void simulateAutoscaling(double cpu_utilization) {
    int min_size = 1;
    int max_size = 10;
    cout << "CPU Utilization: " << cpu_utilization << "%" <<endl;
    int desired_capacity = max(min_size,min(static_cast<int>(cpu_utilization / 10.0), max_size));

    if (desired_capacity > allocated_servers) {
        cout << "Allocating " << (desired_capacity - allocated_servers) << " servers..." << endl;
        allocated_servers = desired_capacity;
    }
    else if (desired_capacity < allocated_servers) {
        cout << "Deallocating " << (allocated_servers - desired_capacity) << " servers..." <<endl;
        allocated_servers = desired_capacity;
    }
}

double generateRandomCPUUtilization() {
    return (rand() % 100) + 1;
}

int main() {

cout << "Options:" <<endl;
    cout << "1. Monitor" <<endl;
    cout << "2. Exit" <<endl;

    int choice;
    while (1) {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                while (true) {
                    double cpu_utilization = generateRandomCPUUtilization();
                    simulateAutoscaling(cpu_utilization);
                    cout << "Press 'm' to return to the main menu, or any other key to continue monitoring: ";
                    char ch;
                    cin >> ch;
                    if (ch == 'm' || ch == 'M') {
                        break;
                    }
                }
                break;
            }
            case 2:
                cout << "Exiting..." << endl;
                return 0;
            default:
               cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
