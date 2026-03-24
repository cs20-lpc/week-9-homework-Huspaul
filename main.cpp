#include <iostream>
#include <cstdlib>
#include <ctime>
#include "QueueFactory.hpp"
using namespace std;

// -------------------------------------------------------
// Simulation 1: Ticket Counter (bounded, max 10 customers)
//   - Uses ArrayQueue because there is a fixed maximum capacity
//   - Random number in [-1, 1]:
//       negative  -> dequeue (customer is served and leaves)
//       0 or pos  -> enqueue (new customer arrives)
// -------------------------------------------------------
void simulateTicketCounter() {
    cout << "========================================" << endl;
    cout << "  Simulation 1: Ticket Counter          " << endl;
    cout << "  (ArrayQueue, max capacity = 10)        " << endl;
    cout << "========================================" << endl;

    // Factory returns ArrayQueue because a max size is given
    Queue<int>* line = QueueFactory::GetQueue(10);

    int customerID = 1;

    for (int i = 1; i <= 100; i++) {
        int r = (rand() % 3) - 1;  // -1, 0, or 1

        cout << "Step " << i << ": ";

        if (r < 0) {
            if (!line->isEmpty()) {
                int served = line->front();
                line->dequeue();
                cout << "Customer #" << served << " was served and left. ";
            } else {
                cout << "No one to serve (line is empty). ";
            }
        } else {
            try {
                line->enqueue(customerID);
                cout << "Customer #" << customerID << " joined the line. ";
                customerID++;
            } catch (string& e) {
                cout << "Customer #" << customerID << " was turned away (line full). ";
                customerID++;
            }
        }

        cout << "[Line length: " << line->getLength() << "]" << endl;
    }

    cout << endl;
    cout << "Final line length: " << line->getLength() << endl;
    if (!line->isEmpty()) {
        cout << "Next to be served: Customer #" << line->front() << endl;
    }

    delete line;
    cout << endl;
}

// -------------------------------------------------------
// Simulation 2: Bank Service Line (unbounded, dynamic)
//   - Uses LinkedQueue because there is NO fixed capacity
//   - Random number in [-1, 2]:
//       negative  -> dequeue (customer finishes service)
//       0 or pos  -> enqueue (new customer arrives)
// -------------------------------------------------------
void simulateBankLine() {
    cout << "========================================" << endl;
    cout << "  Simulation 2: Bank Service Line       " << endl;
    cout << "  (LinkedQueue, no max capacity)         " << endl;
    cout << "========================================" << endl;

    // Factory returns LinkedQueue because no size is specified
    Queue<int>* line = QueueFactory::GetQueue();

    int customerID = 1;

    for (int i = 1; i <= 100; i++) {
        int r = (rand() % 4) - 1;  // -1, 0, 1, or 2

        cout << "Step " << i << ": ";

        if (r < 0) {
            if (!line->isEmpty()) {
                int served = line->front();
                line->dequeue();
                cout << "Customer #" << served << " finished service and left. ";
            } else {
                cout << "No one to serve (line is empty). ";
            }
        } else {
            line->enqueue(customerID);
            cout << "Customer #" << customerID << " joined the line. ";
            customerID++;
        }

        cout << "[Line length: " << line->getLength() << "]" << endl;
    }

    cout << endl;
    cout << "Final line length: " << line->getLength() << endl;
    if (!line->isEmpty()) {
        cout << "Next to be served: Customer #" << line->front() << endl;
    }

    delete line;
    cout << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(0)));

    simulateTicketCounter();
    simulateBankLine();

    return 0;
}
