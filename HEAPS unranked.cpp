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
    for (int age : heap) {
        cout << age << " ";
    }
    cout << RESET << endl;
}

// Function to insert an element into the heap (inputs only)
void insertHeap(vector<int>& heap, int age) {
    cout << GREEN << "Inserting age " << age << " into the Heap." << RESET << endl;
    heap.push_back(age);
    displayHeap(heap);
}

// Function to convert the heap into a Max-Heap
void buildMaxHeap(vector<int>& heap) {
    cout << GREEN << "Building Max-Heap from the inputs..." << RESET << endl;
    vector<int> maxHeap = heap;
    make_heap(maxHeap.begin(), maxHeap.end());
    cout << CYAN << "Max-Heap: ";
    for (int age : maxHeap) {
        cout << age << " ";
    }
    cout << RESET << endl;
}

// Function to convert the heap into a Min-Heap
void buildMinHeap(vector<int>& heap) {
    cout << GREEN << "Building Min-Heap from the inputs..." << RESET << endl;
    vector<int> minHeap = heap;
    make_heap(minHeap.begin(), minHeap.end(), greater<>());
    cout << CYAN << "Min-Heap: ";
    for (int age : minHeap) {
        cout << age << " ";
    }
    cout << RESET << endl;
}

int main() {
    int age;
    string welcomeMessage = "Hello we are Kirby and James! Welcome, insert a number\n";

    for (char c : welcomeMessage) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(25));
    }

    while (true) {
        cout << "Enter age to insert into the Heap (or -1 to stop): ";
        cin >> age;
        if (age == -1) break;
        insertHeap(heap, age);
    }

    cout << "\nFinal Heap (inputs only): ";
    displayHeap(heap);

    buildMaxHeap(heap);
    buildMinHeap(heap);

    cout << "Thank you bye!" << endl;
    return 0;
}