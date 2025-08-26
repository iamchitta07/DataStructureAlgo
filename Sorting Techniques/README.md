# Sorting Techniques in C

## 📜 Overview
This project implements multiple **Sorting Algorithms** in C inside a **menu-driven program**.  
It allows users to dynamically input an array, choose different sorting algorithms, and view the results.  

The project is structured as follows:
- **`sortingTechniques.c`** → Main program (menu-driven)  
- **`functions.c`** → Function definitions for sorting and utilities  
- **`functions.h`** → Header file with function declarations  

---

## ⚙ Features
1. **Dynamic Memory Allocation**  
   - User inputs the size of the array at runtime.  
   - Memory for the array is allocated using `malloc` to handle flexible input sizes.  
   - After program execution, memory is released using `free()`.  
   - This ensures efficient memory usage.  

2. **Menu-Driven Program**  
   - User can enter the array dynamically.  
   - Select a sorting technique from the menu.  
   - View the sorted array after applying the chosen algorithm.  
   - Repeat until exit.  

3. **Sorting Algorithms Implemented**
   - Bubble Sort  
   - Selection Sort  
   - Insertion Sort  
   - Merge Sort  
   - Quick Sort  
   - Counting Sort  
   - Radix Sort  

---

## ⏳ Time Complexity
| Algorithm       | Best Case | Average Case | Worst Case | Notes |
|-----------------|-----------|--------------|------------|-------|
| **Bubble Sort** | O(n)      | O(n²)        | O(n²)      | Optimized with a flag for best case |
| **Selection Sort** | O(n²)  | O(n²)        | O(n²)      | Independent of input order |
| **Insertion Sort** | O(n)   | O(n²)        | O(n²)      | Best for nearly sorted data |
| **Merge Sort**  | O(n log n) | O(n log n)  | O(n log n) | Divide & Conquer, stable sort |
| **Quick Sort**  | O(n log n) | O(n log n)  | O(n²)      | Worst case when pivot choice is poor |
| **Counting Sort** | O(n + k) | O(n + k)    | O(n + k)   | Works for integers, requires extra space |
| **Radix Sort**  | O(nk)     | O(nk)        | O(nk)      | k = number of digits, uses Counting Sort internally |

---

## 💾 Space Complexity
| Algorithm       | Space Complexity | Notes |
|-----------------|------------------|-------|
| **Bubble Sort** | O(1)  | In-place |
| **Selection Sort** | O(1) | In-place |
| **Insertion Sort** | O(1) | In-place |
| **Merge Sort**  | O(n)  | Extra arrays used for merging |
| **Quick Sort**  | O(log n) | Recursive stack (average), O(n) worst case |
| **Counting Sort** | O(n + k) | Extra frequency/count arrays |
| **Radix Sort**  | O(n + k) | Uses Counting Sort as subroutine |

---

## 📂 File Structure
```
├── sortingTechniques.c   # Main program
├── functions.c           # Sorting functions implementation
├── functions.h           # Header file
└── README.md             # Documentation
```

---

## 🖥 Compilation & Execution

### **Windows**
```bash
clear; g++ sortingTechniques.c functions.c -o sortingTechniques.exe; .\sortingTechniques.exe
```

### **Mac & Linux**
```bash
clear && g++ sortingTechniques.c functions.c -o sortingTechniques && ./sortingTechniques
```

---

## 📌 Notes
- Dynamic memory (`malloc`) allows flexibility in handling arrays of **any size** specified at runtime.  
- `free()` is used to prevent **memory leaks**.  
- Menu-driven design makes it **easy to test and compare** sorting algorithms in one place.  

---

## 🧑‍💻 Author
**Chittajit Nath**  
National Institute of Technology, Durgapur
