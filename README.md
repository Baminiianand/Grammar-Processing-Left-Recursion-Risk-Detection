Grammar Processing – Left Recursion Risk Detection

Project Overview

In compiler design, grammar rules define the syntax of programming languages. Some grammars contain **left recursion**, where a non-terminal appears at the beginning of its own production. This causes issues for **top-down parsers** like recursive descent parsers, leading to infinite loops.

This project detects **left recursion** in grammar rules and computes a feature called **Recursion_Depth**, which measures how many times the left-hand side symbol appears in the right-hand side of a rule.

Objectives

* Identify whether a grammar rule contains **left recursion**
* Compute **Recursion_Depth** for each rule
* Provide structured output for parser analysis
* Improve grammar preprocessing before parsing

Features

* 📥 Accepts grammar rules as raw string input
* 🔍 Detects left recursion automatically
* 🔢 Calculates recursion depth
* 📊 Outputs analysis with flags:

  * `Has_Left_Recursion = 1` → Left recursion present
  * `Has_Left_Recursion = 0` → No left recursion

How It Works

1. Read grammar rules as input
2. Extract:

   * **LHS (Left-Hand Side)** → First symbol
   * **RHS (Right-Hand Side)** → After `->`
3. Count occurrences of LHS in RHS → **Recursion_Depth**
4. Check if RHS starts with LHS → Detect left recursion
5. Display results

Algorithm

```
1. Input grammar rule
2. Extract LHS and RHS
3. Initialize count = 0
4. For each character in RHS:
       If character == LHS:
           count++
5. If RHS starts with LHS:
       Has_Left_Recursion = 1
   Else:
       Has_Left_Recursion = 0
6. Print results
```

---

Sample Input

```
E->E+T
T->T*F
F->(E)
```

---

Sample Output

```
Rule: E->E+T
Recursion_Depth: 1
Has_Left_Recursion: 1

Rule: T->T*F
Recursion_Depth: 1
Has_Left_Recursion: 1

Rule: F->(E)
Recursion_Depth: 1
Has_Left_Recursion: 0
```

Technologies Used

* Programming Language: **C**
* Concepts:

  * Compiler Design
  * String Processing
  * Recursion Analysis

Applications

* Compiler construction
* Syntax analysis
* Grammar optimization
* Parser design

Advantages

* Simple and efficient implementation
* Helps avoid infinite loops in parsers
* Improves grammar quality
* Easy to integrate into compiler tools

Limitations

* Handles only basic grammar rules
* Assumes single-character non-terminals
* Does not handle indirect left recursion

Future Enhancements

* Detect **indirect left recursion**
* Support multi-character non-terminals
* Convert left-recursive grammar to non-left-recursive form
* Add GUI or visualization

Conclusion

This project demonstrates how grammar rules can be analyzed using simple string processing techniques. It effectively detects left recursion and measures recursion complexity, helping in building efficient and reliable parsing systems.
