# AnimalGuessingGame

## Project Overview
This project involves implementing the **Animal Guessing Game**, a simplified version of "20 Questions" where the program tries to guess an animal based on a series of yes/no questions. The program builds and manages a **binary tree** where:
- **Leaf nodes** represent animals.
- **Interior nodes** contain questions used to distinguish between animals.

When the program cannot guess the correct animal, it augments the tree by asking the user for:
1. The animal they were thinking of.
2. A distinguishing question to separate the new animal from the guessed one.

The program dynamically grows the tree, learning and improving its guesses over time.

---

## Key Features
1. **Binary Tree Representation**:
   - Each leaf node represents an animal.
   - Each interior node contains a yes/no question.

2. **Tree Augmentation**:
   - If the program cannot correctly guess the animal, it expands the tree with:
     - A new question.
     - A new leaf node for the user's animal.

3. **User Interaction**:
   - The program interacts with the user via the command line, asking questions and learning from incorrect guesses.

4. **Pre-built Framework**:
   - Skeleton code is provided, and the developer adds missing functionality and comments.

---

## Objectives
The primary goals of this project are:
- To gain hands-on experience with **binary trees**, including dynamic creation and traversal.
- To understand and implement pointer-based data structures in C.
- To practice dynamic memory allocation and recursion.
- To work with existing code and understand its structure through commenting.

---

## Implementation Details

### **Core Components**
1. **Binary Tree**:
   - Nodes in the tree contain:
     - A question (interior nodes) or an animal name (leaf nodes).
     - Pointers to two child nodes (`yes` and `no`).

2. **Tree Operations**:
   - **Dynamic Tree Augmentation**:
     - Adds new questions and animals to the tree based on user input.
   - **Tree Traversal**:
     - Uses recursion to navigate the tree and ask the user yes/no questions.

3. **Files Provided**:
   - `animals.c`: The main file where missing code and comments are added.
   - `node_utils.c`: Auxiliary functions for working with tree nodes.
   - `node_utils.h`: Header file for `node_utils.c`.
   - `data.dat`: Input file with initial tree structure.
   - `ben` or `ben.exe`: An executable file showing expected program behavior.

---

### **Steps to Run the Program**
1. **Setup**:
   - Download the appropriate project archive based on your operating system:
     - `assignment1_cygwin.tgz` (Windows/Cygwin)
     - `assignment1_macos.tgz` (macOS)
     - `assignment1_linux.tgz` (Linux)

2. **Unpack the Files**:
   - Use the following commands in a shell:
     ```bash
     mkdir assignment1
     cd assignment1
     tar -xzvf filename.tgz
     ```

3. **Compile the Program**:
   - Compile the code using:
     ```bash
     gcc -o animals animals.c node_utils.c
     ```

4. **Run the Program**:
   - Execute the program:
     ```bash
     ./animals
     ```

5. **Compare Output**:
   - Run the provided executable (`./ben`) to compare your program's output:
     ```bash
     ./ben
     ```

---

## Example Workflow

**Tree Example**:
- Initial tree:
  ```
  Is it a feline?
     /       \
  tiger     dog
  ```
- User thinks of a bear:
  - The program asks for a distinguishing question: "Is it canine?"
  - The program updates the tree as follows:
    ```
    Is it a feline?
       /       \
    tiger      Is it a canine?
                   /       \
                dog       bear
    ```

---

## Development Notes
1. **Code Additions**:
   - Complete missing procedures in `animals.c`.
   - Add comments explaining the logic behind provided and added code.

2. **Debugging**:
   - Use recursion effectively for tree traversal.
   - Test the program frequently to ensure proper tree updates and navigation.

3. **Testing**:
   - Compare the program's behavior with the provided executable (`ben` or `ben.exe`) to ensure correctness.

---

## Deliverables
- Submit the modified `animals.c` file only.
- Ensure the program compiles and runs as expected.

---

This project is an excellent opportunity to deepen your understanding of binary trees, recursion, and dynamic memory allocation while building an interactive program that learns and improves over time.
