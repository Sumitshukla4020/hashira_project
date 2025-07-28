# 📌 Catalog Placements Assignment – Shamir's Secret Sharing (C++)

## 📝 Problem Statement

This assignment implements a simplified version of **Shamir's Secret Sharing** using **Lagrange Interpolation** to recover the constant term (`c`) from an unknown polynomial of degree `m = k - 1`.

---

## 📂 Project Structure

📁 sss problem/
├── main.cpp // C++ implementation
├── testcase1.json // First test case
├── testcase2.json // Second test case
├── nlohmann/json.hpp // JSON parsing header
└── README.md // This file


---

## ⚙️ Features

- ✅ Reads input from JSON files
- ✅ Decodes values encoded in arbitrary bases (e.g., binary, octal, base-15, etc.)
- ✅ Uses **Lagrange interpolation** to solve for the constant term `c`
- ✅ Handles large values (up to 64-bit safe range using `MOD = 2^61 - 1`)
- ✅ Ignores corrupted points by checking all `k`-combinations

---

## 📥 Input Format

```json
{
  "keys": {
    "n": 4,
    "k": 3
  },
  "1": {
    "base": "10",
    "value": "4"
  },
  ...
}


Each numbered key is an (x, y) point:

x = key (e.g., "1")

y = value (base encoded)



Secret from Testcase 1: 137925164384090225
Secret from Testcase 2: 1643316824411125


🚀 How to Compile & Run
✅ Prerequisite: C++17 Compatible Compiler (tested on GCC 15 via MSYS2)
🛠️ Compile

g++ -std=c++17 main.cpp -o shamir

▶️ Run

./shamir

📦 Dependencies
nlohmann/json — header-only JSON parser

Modern C++17-compatible compiler (__int128 not required in final solution)

🧪 Test Cases
Two testcases are provided (testcase1.json, testcase2.json). The output prints the recovered constant (c) for both cases.

✅ Notes
The solution uses a safe 64-bit modulus:

const ull MOD = 2305843009213693951ULL; // 2^61 - 1

Can be extended to arbitrary precision using GMP or Boost.Multiprecision if needed for 256-bit range.

🙌 Author
Sumit Shukla
Catalog Placements — Assignment Submission
GitHub Repo: github.com/Sumitshukla4020/hashira_project


---

Let me know if you'd like:
- A zipped version of the entire folder
- A LaTeX version of this README
- Or a README badge/shield for GitHub (e.g., C++ | JSON | Lagrange Interpolation)

You're 100% ready for submission now ✅
