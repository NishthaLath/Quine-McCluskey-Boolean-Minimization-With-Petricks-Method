Certainly! I'll format the output result from your code and incorporate it into the README file, providing a well-structured example of the program's output.

---

### Updated README with Output Example:

```markdown
# Quine-McCluskey and Petrick's Method Boolean Minimization

This repository contains a C++ implementation of both the **Quine-McCluskey method** and **Petrick's method** for minimizing Boolean functions. The project systematically reduces Boolean expressions into their minimal Sum-of-Products (SOP) form, offering a detailed, step-by-step approach from generating prime implicants to applying Petrick’s method to find the optimal set of implicants.

## Features

- **Quine-McCluskey Method**: A tabular method that simplifies Boolean functions by grouping and combining minterms and don't-care terms that differ by only one variable, producing a set of prime implicants.
- **Petrick’s Method**: A combinatorial technique that identifies the minimal set of prime implicants required to cover all minterms, ensuring the most optimized solution.
- **Binary String Manipulation**: Includes helper functions to convert integers to binary, count ones, and identify differences between binary terms.
- **Prime Implicant Generation**: Efficiently groups minterms based on binary representations and iterates through them to form prime implicants.
- **Prime Implicant Chart Construction**: Constructs a chart to determine which prime implicants cover which minterms, simplifying the identification of essential prime implicants.

## Program Input

- **Number of Variables**: The number of Boolean variables in the function.
- **Minterms**: The minterms of the Boolean function.
- **Don't-Care Terms**: The don't-care terms that can be used for simplification.

## Program Output Example

```bash
Enter the number of variables: 4
Enter minterm numbers (-1 for end): 2 3 7 9 11 13 -1
Enter don't-care term numbers (-1 for end): 1 10 15 -1

Group No.       Minterms        Binary of Minterms
==================================================
    4:
                15        1111
--------------------------------------------------
    3:
                7        0111
                11        1011
                13        1101
--------------------------------------------------
    2:
                3        0011
                9        1001
                10        1010
--------------------------------------------------
    1:
                2        0010
                1        0001
--------------------------------------------------
Unmarked elements (Prime Implicants) of this table: 

Group No.       Minterms        Binary of Minterms
==================================================
    3:
                7,15        -111
                11,15        1-11
                13,15        11-1
--------------------------------------------------
    2:
                3,7        0-11
                3,11        -011
                9,11        10-1
                9,13        1-01
                10,11        101-
--------------------------------------------------
    1:
                2,3        001-
                2,10        -010
                1,3        00-1
                1,9        -001
--------------------------------------------------
Unmarked elements (Prime Implicants) of this table: 

Group No.       Minterms        Binary of Minterms
==================================================
    2:
                3,7,11,15        --11
                9,11,13,15        1--1
--------------------------------------------------
    1:
                2,3,10,11        -01-
                1,3,9,11        -0-1
--------------------------------------------------
Unmarked elements (Prime Implicants) of this table: None

All Prime Implicants: -01-, --11, -0-1, 1--1, 

Prime Implicants chart:

    Minterms    | 2  3  7  9  11  13
==================================
    -01-        | X  X        X
----------------------------------
     --11       |    X  X     X
----------------------------------
     -0-1       |    X     X  X
----------------------------------
     1--1       |          X  X  X
----------------------------------
Essential Prime Implicants: -01-, --11, 1--1,

Solution: F = B'C + CD + AD
```

## How to Use

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/YourUsername/Quine-McCluskey-Petricks-Method.git
   ```

2. **Compile the Code**:
   Use any C++ compiler to compile the program:
   ```bash
   g++ QuineMcCluskey.cpp -o quine_mccluskey
   ```

3. **Run the Program**:
   After compiling, run the program using the following command:
   ```bash
   ./quine_mccluskey
   ```

4. **Input Requirements**:
   - **Number of Variables**: Enter the number of Boolean variables in the function.
   - **Minterms**: Input the minterms of the Boolean function.
   - **Don't-Care Terms**: Provide the don't-care terms to be used for further simplification.

## Requirements

- C++11 or higher
- A basic understanding of Boolean algebra and logic minimization

## Potential Applications

- **Digital Logic Design**: Simplify complex logic circuits.
- **Boolean Algebra**: Optimize Boolean expressions for use in hardware and software applications.
- **Teaching and Learning**: An educational tool for understanding Boolean function minimization techniques.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
```

---
