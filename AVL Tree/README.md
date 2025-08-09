# AVL Tree Implementation in C

## 📜 Overview
This project implements an **AVL (Adelson-Velsky and Landis) Binary Search Tree** in C.
The program allows users to dynamically insert values, view the tree traversals, delete values while maintaining height balance, and view the height of the tree.

It uses:
- **`AVL.c`** → Main program (menu-driven)
- **`functions.c`** → Function definitions
- **`functions.h`** → Header file with function declarations

---

## ⚙ Features
1. **Dynamic Input Allocation**
   - User enters the number of elements.
   - Input stored in a dynamically allocated array (`malloc`).

2. **Menu-Driven Program**
   - **View Tree** → Displays Preorder, Inorder, and Postorder traversals.
   - **Delete Value** → Deletes a value from the tree.
     - If the value is **not found**, it displays `"Value not found in the tree"`.
     - After deletion, the AVL tree remains **height-balanced**.
   - **Height of Tree** → Displays the height of the current AVL tree.
   - **Exit** → Ends the program.

---

## 📂 File Structure
```
├── AVL.c          # Main program
├── functions.c    # AVL tree functions implementation
├── functions.h    # Header file
└── README.md      # Documentation
```

---

## 🖥 Compilation & Execution

### **Windows**
```bash
g++ AVL.c functions.c -o AVL.exe
AVL.exe
```

Or in a single command:
```bash
g++ AVL.c functions.c -o AVL.exe ; AVL.exe
```

### **Mac & Linux**
```bash
g++ AVL.c functions.c -o AVL
./AVL
```

Or in a single command:
```bash
g++ AVL.c functions.c -o AVL && ./AVL
```

---

## 📌 Notes
- The AVL Tree automatically balances itself after each insertion and deletion.
- Height is calculated as **the number of edges on the longest path** from the root to a leaf.
- This project is **menu-driven** and runs until the user chooses to exit.

---



---

## ⏳ Time Complexity
| Operation | Average Case | Worst Case | Notes |
|-----------|--------------|------------|-------|
| **Insertion** | O(log n) | O(log n) | Balanced tree ensures logarithmic depth |
| **Deletion** | O(log n) | O(log n) | Includes search + possible rotations |
| **Search** *(inside delete)* | O(log n) | O(log n) | Standard BST search in balanced tree |
| **Rotations** | O(1) | O(1) | LL, RR, LR, RL each take constant time |
| **Traversals** | O(n) | O(n) | Visits every node exactly once |
| **Height Calculation** *(current code)* | O(n) | O(n) | Uses recursive computation, could be O(1) with stored heights |
| **Balance Factor Calculation** | O(n) | O(n) | Calls `height()` twice per node in current code |

---

## 💾 Space Complexity
| Operation | Complexity | Notes |
|-----------|------------|-------|
| **Insertion/Deletion** | O(log n) | Due to recursion stack in balanced tree |
| **Traversals** | O(log n) | Recursion depth equals tree height |
| **Height Calculation** | O(log n) | Recursive calls stack depth equals tree height |
| **Storage for Tree** | O(n) | Each node stored with `left`, `right`, `val` |
| **Dynamic Input Array** | O(n) | Allocated via `malloc` |

## 🧑‍💻 Author
- Created by **Chittajit Nath**
- B-Tech, Computer Science and Engineering
- National Institute of Technology, Durgapur
