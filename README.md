# Smart-Swapper---Page-Replacement-Algorithm-Simulator


An educational simulation tool that implements and compares three classical page replacement algorithms—**FIFO**, **LRU**, and **Optimal**—through a clean **C++/CLI Windows Forms GUI**. It helps students and OS enthusiasts visualize how memory management policies impact system performance.



## Project Overview

Efficient memory management is a key feature of operating systems. This project demonstrates:

* **First-In-First-Out (FIFO)** – replaces the oldest page in memory.
* **Least Recently Used (LRU)** – replaces the least recently accessed page.
* **Optimal** – replaces the page that won't be used for the longest time in future.



## Features

* **Graphical User Interface** (C++/CLI Windows Forms)
* Custom reference string and memory frame input
* Step-by-step frame visualization with page fault tracking
* Comparative analysis of algorithms in a single run
* Highlighting best-performing algorithm
* Input validation and robust error handling



## Tools & Technologies

* Language: **C++** with **C++/CLI**
* IDE: **Visual Studio**
* GUI Framework: **Windows Forms**
* STL Libraries: `<vector>`, `<iostream>`, `<algorithm>`, `<limits>`



##  How It Works

1. **Input Phase**:

   * User provides:

     * Number of frames
     * Reference string
     * Total number of pages
     * Algorithm selection (FIFO, LRU, Optimal, or All)

2. **Processing Phase**:

   * Each algorithm processes the input
   * Memory frames are updated step-by-step
   * Page faults are counted and visualized

3. **Output Phase**:

   * Final page fault count is displayed
   * Frame-by-frame simulation is shown in tabs
   * Best algorithm (with least page faults) is highlighted



## 🖼️ GUI Preview

The GUI includes:

* Input panels for frames/pages/reference string
* Algorithm dropdown
* Dynamic results section
* Step-by-step data grid for frame visualization



##  Example

**Input:**

```
Reference String: 7 0 1 2 0 3 0 4 2 3 0 3 2
Frames: 3
```

**Results:**

* FIFO: 10 page faults
* LRU: 8 page faults
* Optimal: 7 page faults

 **Best Algorithm**: Optimal



## Testing

Tested with multiple custom inputs and frame configurations. Input validation ensures:

* Only integers accepted
* Frame/page count must be positive
* Reference string must match total pages

![WhatsApp Image 2025-06-04 at 23 36 20](https://github.com/user-attachments/assets/353b3da0-c57a-4a24-afb1-945f6d4f1d77)

![WhatsApp Image 2025-06-04 at 23 36 20 (1)](https://github.com/user-attachments/assets/e0081fee-660e-4433-bec5-9c32913f8f75)


## Challenges Faced

* LRU timestamp management using arrays
* Predictive logic in Optimal algorithm
* Clean dynamic GUI layout handling
* Invalid input filtering and robustness



## Future Enhancements

* Real-time **graphical visualization** using SDL/SFML
* Add more algorithms (e.g., **Clock**, **LFU**, **NRU**)
* **Export logs** as `.txt` or `.csv`
* Build a **web version** using JavaScript for easier access



## References

1. Silberschatz, Galvin, & Gagne – *Operating System Concepts*
2. Tanenbaum & Bos – *Modern Operating Systems*
3. [GeeksforGeeks – Page Replacement](https://www.geeksforgeeks.org/page-replacement-algorithms/)
4. [TutorialsPoint – Virtual Memory](https://www.tutorialspoint.com/operating_system/os_virtual_memory.htm)

