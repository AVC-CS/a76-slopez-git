[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=23930177)
# A76: Construct Multi-Array from babyname.txt

**Code your program here:** [https://classroom.github.com/a/267S4tAg](https://classroom.github.com/a/267S4tAg)

---

## 3. Elaborate on Errors and Troubleshooting

- Programming algorithms used
- Errors encountered and troubleshooting steps taken
- Error experiences and lessons learned (how you identified and fixed each error)

---

## [Programming Assignment Guide]

**Read the Assignment Directions below, then complete the following main.cpp in your cloned Repository.**

In this assignment, you will complete **makeNameRecord()** and **findNames()** in main.hpp. The data file babyname.txt has 4080 records of the form *state gender year name count*. **Do NOT edit main.cpp**.

Full assignment instructions are embedded below. Read them carefully before coding.

Implementation Hint

| Function 1: int makeNameRecord(string state[], string gender[], int year[], string name[], int count[]) |
|---|
| • Open babyname.txt with ifstream. If it fails to open, print an error and exit.<br>• Read each record into the parallel arrays using the stream operator: inputfile >> state[cnt] >> gender[cnt] >> year[cnt] >> name[cnt] >> count[cnt].<br>• Increment cnt for each successful read and return it as the total record count. |

Implementation Hint

| Function 2: int findNames(int cnt, string state[], string gender[], int year[], string name[], int count[], char starting, string stname) |
|---|
| • Loop through all cnt records.<br>• Use name[i].rfind(starting, 0) == 0 to test whether the name starts with the given character.<br>• If the state matches stname AND the name starts with starting, print that record with printoutcontents() and increment a local counter.<br>• Return the counter (the number of matching lines). |

**How to compile and run your program:**

- To compile your program in VS Code, open the new terminal (ctrl-`) and type: g++ main.cpp -o main
- To run your program: ./main

**How to test your program:**

- To run all tests: make test
- To run a specific test (e.g., T1): make test ARGS="[T1]"

**[Expected Output]**

*Your output should contain the correct values. The exact wording or formatting may differ — tests check values only, not the entire output.*

Example run (state=TX, starting='J'):

```cpp
Total lines:  4080
The list of names in TX and starting with J
   TX   F   2011    Jasmine        260
   TX   F   2011    Julia        202
   ...
total lines: 10
```

**How to pass the test:**

Test items: **compile, run, T1, T2, T3, T4**

| Test | Input | Expected Values (checked by test) | Points |
|---|---|---|---|
| T1 | makeNameRecord on babyname.txt; check first record | cnt == 4080; first record IN/F/2011/Emma/453 | 20 |
| T2 | findNames 'S' in CA; findNames 'J' in TX | 11 and 10 | 20 |
| T3 | findNames 'A' in CA; findNames 'M' in NY | 2 and 12 | 20 |
| T4 | findNames in nonexistent state 'XX'; starting char '9' (no name) | 0 and 0 (edge cases) | 20 |

To test your program, type the command in your terminal: make test

**Make sure that your program passes the test and there is ✓ in your GitHub Classroom Repository.**

