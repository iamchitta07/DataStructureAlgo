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

## 🧑‍💻 Author
Created by **Chittajit Nath**
National Institute of Technology, Durgapur
