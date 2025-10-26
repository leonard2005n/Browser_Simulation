# Browser Simulation

This project simulates the implementation of a simple web browser using data structures such as a stack and a circular doubly linked list with a sentinel.

- The **stack** is used to store the history (backward and forward pages) of each tab.  
- The **circular doubly linked list** is used to store the tabs in the order they were opened.

---

## Data Structures

- **Stack** – Maintains backward and forward navigation history for each tab.  
- **Circular Doubly Linked List (with sentinel)** – Stores browser tabs in a circular fashion, allowing easy movement between tabs.

---

## Browser Operations

### NEW_TAB
Opens a new tab in the browser.  
- Creates a new tab with **page 0** as the current page.  
- Calls `add_cir_node()` to add the tab to the circular linked list.

---

### CLOSE
Closes the current tab.  
- If the current tab is **tab 0**, an error message is returned (cannot close the last tab).  
- Otherwise, the function determines the position of the current tab in the list and calls `remove_cir_node()` to remove it.

---

### NEXT
Moves the current tab pointer to the next tab in the list.  
- If the pointer reaches the dummy node, it wraps around to the first tab.

---

### PREV
Moves the current tab pointer to the previous tab in the list.  
- If the pointer reaches the dummy node, it wraps around to the last tab.

---

### PAGE
Changes the current page of the tab.  
- If the page does not exist, returns an error message.  
- Saves the current page in the backward stack and clears the forward stack.  
- Updates the current page pointer to the new page.

---

### BACKWARD
Simulates the browser’s back button.  
- If the backward stack is empty, returns an error message.  
- Otherwise:
  1. Saves the current page in the forward stack.  
  2. Pops the top element from the backward stack.  
  3. Updates the tab to display that page.

---

### FORWARD
Simulates the browser’s forward button.  
- If the forward stack is empty, returns an error message.  
- Otherwise:
  1. Saves the current page in the backward stack.  
  2. Pops the top element from the forward stack.  
  3. Updates the tab to that page.

---

### PRINT
Displays all the tab IDs in the browser once, starting from the current tab.  
- Traverses the circular list from the current tab node until it loops back.  
- Prints the tab IDs and the current page description.

---

### PRINT_HISTORY
Prints the navigation history for a specific tab.  
- If the tab does not exist, returns an error message.  
- Otherwise:
  1. Calls `print
