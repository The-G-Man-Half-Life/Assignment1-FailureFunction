```markdown
# Assignment 1: KMP Failure Function Implementation

This repository contains the implementation of the failure function described in image 3.19

##Environment and Tools

* **Operating System:** [Windows 11]
* **Programming Language:** C++ (Standard C++11)
* **Compiler:** [GCC (g++)]
* **IDE / Text Editor:** [Visual Studio Code]

##How to Run the Program

To compile and execute the program from the terminal, follow these steps:

1. **Open your terminal** and navigate to the directory where the source code (`main.cpp`) is located.
2. **Compile the code** using a C++ compiler (like `g++`). Run the following command:
   ```bash
   g++ main.cpp -o "main.exe"
   ```
3. **Run the executable:**
   * On **Linux/macOS**:
     ```bash
     ./main
     ```
   * On **Windows**:
     ```cmd
     ./main.exe
     ```

### Program Usage
Once the program is running, you will be presented with a menu:
* **Option 1:** Allows you to type any word you wish and the program will print the word processed by the functioon alongside the table.
* **Option 2:** Automatically computes and displays the failure function for the strings provided in **Exercise 3.4.3** (`abababaab`, `aaaaaa`, `abbaabb`).
* **Any other key:** Exits the program safely.

---

## Algorithm Explanation

### What the failure function does
The failure function (often denoted as $f(s)$) computes the length of the **longest proper prefix that is also a suffix** for every possible substring (from the beginning up to the current character) of a given pattern. It will generate an array, indicating by each position the length of the longest sufix = prefix obtained from that substring

### What it is used for
In the context of compiler design, the failure function is used for **token recognition** during the **lexical analysis phase**. It is the backbone of the Knuth-Morris-Pratt (KMP) string-matching algorithm. By knowing the longest matching prefix-suffix, avoids re-reading characters it has already seen when a mismatch occurs, making pattern matching significantly faster ($O(n)$ time complexity).

### How the Algorithm Works (Figure 3.19)
Unlike a brute-force approach, this algorithm calculates the values efficiently by using previously computed data:
1. It uses two pointers/trackers: `currentPosition` (iterating through the string starting at index 1) and `lastPrefixLength` (tracking the length of the current matching prefix).
2. **Match:** If the character at `currentPosition` matches the character at `lastPrefixLength`, the prefix length grows by 1, the value is stored in the array, and both trackers move forward.
3. **Mismatch (The optimization):** If the characters do not match and `lastPrefixLength > 0`, the algorithm *does not* reset to zero. Instead, it looks up the last known valid prefix length (`failurePlaces[lastPrefixLength - 1]`) and falls back to that position. preventing redudant comparisons.
4. **Base Case:** If it falls back all the way to 0 and there is still no match, it records `0` for that position and moves to the next character.

---
**Authors:** Mateo Montoya Ospina & Juan Pablo Lopez Lideña
