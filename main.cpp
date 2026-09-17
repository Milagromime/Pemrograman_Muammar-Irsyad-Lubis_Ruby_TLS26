#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;

    cout << "Enter number of astronauts (N): ";
    cin >> n;
    cout << "Enter starting elimination value (K): ";
    cin >> k;

    // Create the circle of astronauts numbered 1 to N
    vector<int> astronauts;
    for (int i = 1; i <= n; i++) {
        astronauts.push_back(i);
    }

    vector<int> eliminationOrder;
    int currentIndex = 0; // counting starts from astronaut number 1 (index 0)

    while (astronauts.size() > 1) {
        int size = astronauts.size();

        // find index of the astronaut who receives the K-th count
        int eliminatedIndex = (currentIndex + k - 1) % size;
        int eliminatedNumber = astronauts[eliminatedIndex];

        eliminationOrder.push_back(eliminatedNumber);
        astronauts.erase(astronauts.begin() + eliminatedIndex);

        // update K based on the eliminated astronaut's number
        if (eliminatedNumber % 2 == 0) {
            k += 2; // even -> increase by 2
        } else {
            k -= 1; // odd -> decrease by 1
        }
        if (k < 2) {
            k = 2; // K cannot be less than 2
        }

        // next counting starts with the astronaut immediately after the eliminated one
        if (astronauts.empty()) {
            break;
        }
        currentIndex = eliminatedIndex % astronauts.size();
    }

    cout << "\nElimination order: ";
    for (int num : eliminationOrder) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Last astronaut remaining: " << astronauts[0] << endl;

    return 0;
}
