#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

struct KnapsackItem {
    int weight, profit;

    static bool comparator(KnapsackItem& a, KnapsackItem& b) { // Used for sorting the items in order of profits
        return a.profit > b.profit;
    }
};

struct Knapsack {
    vector<KnapsackItem> items;
    int weightLimit;

    void print() {
        cout << "The knapsack items (weight, profit) are: " << endl;
        for (KnapsackItem item : items)
            cout << "(" << item.weight << ", " << item.profit << ")" << endl;
        cout << "The knapsack capacity is: " << weightLimit << endl;
    }
};

class State {
    private: 
        int cost;
        int currentLevel = -1;
        vector<int> elements;
        // each element of elements can be -1, 0 or 1
        // 0 means that element of the knapsack will not be included in this state
        // 1 means that element of the knapsack will included in this state
        // -1 means that element of the knapsack is undecided
    
    public:
        State() {} // Default constructor needed by the priority_queue, it is never actually used
        State(int numberOfItems) { elements.assign(numberOfItems, -1); } // Initialize everything to -1
        State(vector<int>& _elements, int _currentLevel, bool shouldInclude) : 
            elements{_elements}, 
            currentLevel{_currentLevel} 
        {
            elements[currentLevel] = shouldInclude;
        }

        bool operator() (State* a, State* b) { // Will be used for ordering in the priority queue
            return a->cost < b->cost; // Return true if cost of A is less than cost of B
        }

        void print() {
            cout << "The chosen elements are: ";
            for (int i : elements) cout << i << " ";
            cout << endl;
            cout << "The maximum profit is: " << cost;
        }

        pair<State*, State*> branch() {
            // This function branches the current state at the specified 'level'
            // And returns the branched states in a pair
            // If state can not be branched, then returns a pair of nullptrs

            if (currentLevel == elements.size()) return make_pair(nullptr, nullptr); // Can not branch further

            // Create two copies of the current state, one level higher
            // one including 'level' and other excluding 'level'
            return make_pair(
                new State(elements, currentLevel + 1, true),
                new State(elements, currentLevel + 1, false)
            );
        }

        bool bound(Knapsack& knapsack) {
            // This function calculates the greedy cost for this state
            // It will return false if the selected elements exceed knapsack capacity
            // Otherwise it will return true

            int target = knapsack.weightLimit;
            for (int i = 0; i < elements.size(); i++) {
                if (elements[i] == 1) { 
                    // Take the entire item
                    cost += knapsack.items[i].profit;
                    target -= knapsack.items[i].weight;

                } else if (elements[i] == -1) { // We make a greedy choice here
                    if (target < knapsack.items[i].weight) { // If you can't take the entire item
                        // Try to take its fraction
                        float profitByWeight = float(knapsack.items[i].profit) / float(knapsack.items[i].weight);
                        if (profitByWeight <= target) { // Can you take its fraction?
                            cost += target * profitByWeight;
                            target -= target;
                        }

                    } else { // If you can take the entire item, take it
                        cost += knapsack.items[i].profit;
                        target -= knapsack.items[i].weight;
                    }
                }
            }

            if (target < 0) return false; // We overstuffed the knapsack
            return true;
        }
};

typedef priority_queue<State*, vector<State*>, State> States;

State solve(Knapsack& knapsack) {
    States liveStates; // This is a priority queue that orders states based on their cost (or bound) in descending order
    // Therefore, liveState.top() is always the highest cost state

    liveStates.push(new State(knapsack.items.size())); // Store initial state in the queue
    liveStates.top()->bound(knapsack); // Calculate its bound

    while (true) {
        pair<State*, State*> branches = liveStates.top()->branch(); // branch the highest cost state
        liveStates.pop(); // Remove the highest cost state

        if (branches.first == nullptr) break; // No more branches possible for the highest cost state

        // Calculate bounds for both and add them to the queue if the bounding is successful
        if (branches.first->bound(knapsack)) liveStates.push(branches.first); else delete branches.first;
        if (branches.second->bound(knapsack)) liveStates.push(branches.second); else delete branches.second;
    }

    // After the loop has ended, the highest cost state is the answer
    // Create its copy
    State answer = *(liveStates.top());
    // Free up all memory
    while (!liveStates.empty()) liveStates.pop();

    return answer;
}

int main() {
    // Sample Questions
    // Knapsack knapsack = { {{10, 60}, {20, 100}, {30, 120}}, 50 }; // {weight, profit}, weightLimit
    // Knapsack knapsack = { {{3, 2}, {4, 3}, {6, 1}, {5, 4}}, 8 }; // {weight, profit}, weightLimit
    Knapsack knapsack = { {{2, 4}, {3, 5}, {1, 3}, {4, 7}}, 5 }; // {weight, profit}, weightLimit
    // Sort by profits
    std::sort(knapsack.items.begin(), knapsack.items.end(), KnapsackItem::comparator);
    knapsack.print();

    State answer = solve(knapsack);
    answer.print();

    return 0;
}