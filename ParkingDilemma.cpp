#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Sort positions, then slide a window of size k.
// For each window, roof length = rightmost - leftmost + 1.
// Return the minimum such length.
int carParkingRoof(vector<int>& cars, int k) {
    // Sort positions so adjacent cars in array are adjacent on the lot
    sort(cars.begin(), cars.end());

    int n = cars.size();
    int minLength = INT_MAX;

    // Slide a window of exactly k cars across the sorted array
    for (int i = 0; i <= n - k; i++) {
        // Roof must span from cars[i] to cars[i+k-1] (inclusive)
        int roofLength = cars[i + k - 1] - cars[i] + 1;
        minLength = min(minLength, roofLength);
    }

    return minLength;
}

int main() {
    // ── Test 1: Problem example ──────────────────────────────
    // cars = [6, 2, 12, 7], k = 3
    // Sorted: [2, 6, 7, 12]
    // Windows: [2,6,7]→6, [6,7,12]→7  →  min = 6
    vector<int> cars1 = {6, 2, 12, 7};
    cout << "Test 1: " << carParkingRoof(cars1, 3) << "  (expected 6)" << endl;

    // ── Test 2: Cover all cars ───────────────────────────────
    // k = n, so entire range must be covered
    // Sorted: [1, 3, 5] → length = 5 - 1 + 1 = 5
    vector<int> cars2 = {1, 3, 5};
    cout << "Test 2: " << carParkingRoof(cars2, 3) << "  (expected 5)" << endl;

    // ── Test 3: k = 1 ───────────────────────────────────────
    // Only need to cover 1 car → minimum roof = 1
    vector<int> cars3 = {10, 50, 100};
    cout << "Test 3: " << carParkingRoof(cars3, 1) << "  (expected 1)" << endl;

    // ── Test 4: Already consecutive spots ───────────────────
    // Sorted: [3, 4, 5, 6], k = 3
    // All windows have length 3 → min = 3
    vector<int> cars4 = {3, 4, 5, 6};
    cout << "Test 4: " << carParkingRoof(cars4, 3) << "  (expected 3)" << endl;

    // ── Test 5: Large gap between clusters ──────────────────
    // Sorted: [1, 2, 100, 101], k = 2
    // Windows: [1,2]→2, [2,100]→99, [100,101]→2  →  min = 2
    vector<int> cars5 = {1, 2, 100, 101};
    cout << "Test 5: " << carParkingRoof(cars5, 2) << "  (expected 2)" << endl;

    return 0;
}