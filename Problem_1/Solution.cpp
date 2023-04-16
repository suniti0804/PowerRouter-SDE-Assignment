#include<bits/stdc++.h>
using namespace std;

int find_current_index_member_index(vector<char> old_task_queue, int current_index, vector<char> new_task_queue) {
    // Determine the Current Index Member in the Old Task Queue
    char current_index_member = old_task_queue[current_index];
    
    // Find the index of the Current Index Member in the Old Task Queue
    int old_index = find(old_task_queue.begin(), old_task_queue.end(), current_index_member) - old_task_queue.begin();
    
    // Remove all inactive members from the Old Task Queue to obtain the Updated Task Queue
    vector<char> updated_task_queue;
    for (char member : old_task_queue) {
        if (find(new_task_queue.begin(), new_task_queue.end(), member) != new_task_queue.end()) {
            updated_task_queue.push_back(member);
        }
    }
    
    // Determine the index of the Current Index Member in the Updated Task Queue
    int new_index = find(updated_task_queue.begin(), updated_task_queue.end(), current_index_member) - updated_task_queue.begin();
    
    // If the Current Index Member in the Old Task Queue is inactive, find the next available member to the Current Index Member in the Updated Task Queue
    if (new_index == updated_task_queue.size()) {
        for (int i = 1; i < updated_task_queue.size(); i++) {
            int index = (old_index + i) % updated_task_queue.size();
            if (find(new_task_queue.begin(), new_task_queue.end(), updated_task_queue[index]) != new_task_queue.end()) {
                return index;
            }
        }
    }
    
    return new_index;
}

int main() {
    // Get the old task queue from the user
    cout << "Enter the old task queue, separated by spaces: ";
    vector<char> old_task_queue;
    char member;
    while (cin >> member) {
        old_task_queue.push_back(member);
    }
    
    // Get the current index from the user
    cout << "Enter the current index: ";
    int current_index;
    cin >> current_index;
    
    // Get the new task queue from the user
    cout << "Enter the new task queue, separated by spaces: ";
    vector<char> new_task_queue;
    while (cin >> member) {
        new_task_queue.push_back(member);
    }
    
    // Find the index of the Current Index Member in the New Task Queue
    int new_index = find_current_index_member_index(old_task_queue, current_index, new_task_queue);
    cout << "The index of the Current Index Member in the New Task Queue is: " << new_index << endl;
    
    return 0;
}
