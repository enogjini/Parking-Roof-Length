# 🚗 Car Parking Roof Length (C++ Solution)

## 📌 Overview

This project solves the problem of finding the **minimum length of a roof** required to cover `k` cars parked along a street.

Each car is parked at a specific integer position. The goal is to cover **exactly `k` cars** with the shortest possible continuous roof.

---

## 🧠 Approach

The solution uses **sorting + sliding window**.

### 🔍 Key Idea

- Sort the car positions.
- Use a window of size `k` to examine consecutive groups of cars.
- For each group:
  - Roof length = `max_position - min_position + 1`
- Return the **minimum roof length** among all possible groups.

---

## ⚙️ Algorithm Steps

1. Sort the array of car positions.
2. Initialize `minLength` to a large value.
3. Slide a window of size `k` across the array:
   - Compute the roof length for each window.
   - Update the minimum length.
4. Return the smallest roof length found.

---

## 💻 Implementation

- Language: **C++**
- Concepts Used:
  - Sorting
  - Sliding Window
  - Greedy Optimization

---

## ⏱️ Complexity Analysis

| Type              | Complexity |
|------------------|-----------|
| Time Complexity   | **O(N log N)** (sorting) |
| Space Complexity  | **O(1)** (in-place) |

---

## 🧪 Test Cases

### Example

```cpp
cars = [6, 2, 12, 7], k = 3
Sorted = [2, 6, 7, 12]

Windows:
[2, 6, 7] → length = 6
[6, 7, 12] → length = 7

Result = 6
```

---

## ▶️ Example Output

```bash
Test 1: 6  (expected 6)
Test 2: 5  (expected 5)
Test 3: 1  (expected 1)
Test 4: 3  (expected 3)
Test 5: 2  (expected 2)
```

---

## 🚀 How to Run

```bash
g++ solution.cpp -o solution
./solution
```

---

## 📚 Concepts Covered

- Sorting
- Sliding Window Technique
- Greedy Algorithms

---

## 💡 Notes

- Sorting ensures we only consider consecutive cars efficiently.
- The `+1` accounts for inclusive roof coverage.
- Works efficiently for large inputs.

---

## 🔮 Possible Improvements

- Handle very large inputs with faster I/O
- Extend to return the actual segment of cars covered
