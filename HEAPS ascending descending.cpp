#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <thread>
#include <chrono>

using namespace std;

// ANSI color codes for text color
const string RESET = "\033[0m";
const string GREEN = "\033[32m";
const string CYAN = "\033[36m";

vector<int> heap;

// Function to display the heap (just the inputs)
void displayHeap(const vector<int>& heap) {
    cout << CYAN << "Current Heap: ";
    for (int value : heap) {
        cout << value << " ";
    }
    cout << RESET << endl;
}

// Function to insert an element into the heap (inputs only)
void insertHeap(vector<int>& heap, int value) {
    cout << GREEN << "Inserting " << value << " into the Heap." << RESET << endl;
    heap.push_back(value);
    displayHeap(heap);
}

// Function to build and display the Max-Heap in descending order
void buildMaxHeap(vector<int>& heap) {
    cout << GREEN << "Building Max-Heap (descending order) from the inputs..." << RESET << endl;
    vector<int> maxHeap = heap;
    sort(maxHeap.begin(), maxHeap.end(), greater<int>()); // Sort in descending order
    cout << CYAN << "Max-Heap (descending): ";
    for (int value : maxHeap) {
        cout << value << " ";
    }
    cout << RESET << endl;
}

// Function to build and display the Min-Heap in ascending order
void buildMinHeap(vector<int>& heap) {
    cout << GREEN << "Building Min-Heap (ascending order) from the inputs..." << RESET << endl;
    vector<int> minHeap = heap;
    sort(minHeap.begin(), minHeap.end()); // Sort in ascending order
    cout << CYAN << "Min-Heap (ascending): ";
    for (int value : minHeap) {
        cout << value << " ";
    }
    cout << RESET << endl;
}

int main() {
    int value;
    string welcomeMessage = "Hello we are Kirby and James! Welcome, insert a number\n";

    // Display welcome message with typing effect
    for (char c : welcomeMessage) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(25));
    }

    // User input loop
    while (true) {
        cout << "Enter a number to insert into the Heap (or -1 to stop): ";
        cin >> value;
        if (value == -1) break; // Exit condition
        insertHeap(heap, value);
    }

    cout << "\nFinal Heap (inputs only): ";
    displayHeap(heap);

    // Build and display heaps
    buildMaxHeap(heap);
    buildMinHeap(heap);

    cout << "Thank you bye!" << endl;
    return 0;
}