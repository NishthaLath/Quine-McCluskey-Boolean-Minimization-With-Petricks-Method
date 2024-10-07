Based on the content of the file, your project implements both the **Quine-McCluskey method** and **Petrick's method** for minimizing Boolean functions. This includes the calculation of the minimized Sum-of-Products (SOP) form, covering intermediate steps such as prime implicant generation and finding the essential prime implicants. Here's a refined README that accurately reflects your implementation:

---

# Quine-McCluskey and Petrick's Method Boolean Minimization

This repository contains a C++ implementation of both the **Quine-McCluskey method** and **Petrick's method** for minimizing Boolean functions. The project systematically reduces Boolean expressions into their minimal Sum-of-Products (SOP) form, offering a detailed, step-by-step approach from generating prime implicants to applying Petrick’s method to find the optimal set of implicants.

## Features

- **Quine-McCluskey Method**: A tabular method that simplifies Boolean functions by grouping and combining minterms and don't-care terms that differ by only one variable, producing a set of prime implicants.
- **Petrick’s Method**: A combinatorial technique that identifies the minimal set of prime implicants required to cover all minterms, ensuring the most optimized solution.
- **Binary String Manipulation**: Includes helper functions to convert integers to binary, count ones, and identify differences between binary terms.
- **Prime Implicant Generation**: Efficiently groups minterms based on binary representations and iterates through them to form prime implicants.
- **Prime Implicant Chart Construction**: Constructs a chart to determine which prime implicants cover which minterms, simplifying the identification of essential prime implicants.

## Methods and Functions

- **Conversion Functions**:
  - `intToBinary`: Converts an integer into its binary string representation.
  - `countOnes`: Counts the number of ones in a binary string.

- **Combining Functions**:
  - `differByOneBit`: Checks if two binary strings differ by exactly one bit.
  - `combine`: Merges two binary strings that differ by one bit into a single string with a '-' in the differing position.

- **Main Functions**:
  - `generatePrimeImplicants`: Implements the Quine-McCluskey method to generate all prime implicants from minterms and don't-care terms.
  - `petrickMethod`: Applies Petrick’s method to simplify the prime implicants and find the minimal set of essential implicants.
  - `printResult`: Outputs the final minimized Boolean expression in the Sum-of-Products (SOP) form.

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

5. **Output**:
   - **Groupings of Minterms and Don't-Care Terms**: Displays the binary representations and groupings based on the number of ones.
   - **Prime Implicant Chart**: Outputs a chart showing which prime implicants cover which minterms.
   - **Essential Prime Implicants**: Provides the minimal set of prime implicants.
   - **Final SOP Form**: Outputs the minimized Boolean function in the Sum-of-Products (SOP) form.

## Program Output Example
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
     -01-       | X  X        X
----------------------------------
     --11       |    X  X     X
----------------------------------
     -0-1       |    X     X  X
----------------------------------
     1--1       |          X  X  X
----------------------------------
Essential Prime Implicants: -01-, --11, 1--1,

Solution: F = B'C + CD + AD

## Potential Applications

- **Digital Logic Design**: Simplify complex logic circuits.
- **Boolean Algebra**: Optimize Boolean expressions for use in hardware and software applications.
- **Teaching and Learning**: An educational tool for understanding Boolean function minimization techniques.

## Conclusion

This project successfully implements the Quine-McCluskey method and Petrick’s method for Boolean function minimization. It provides intermediate steps and a clear, final minimized Boolean expression, making it suitable for functions with up to 10 variables.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---
![Screenshot 2024-10-07 215141](https://github.com/user-attachments/assets/5ca798db-10e7-440d-a42f-216a5b8863dc)
![Screenshot 2024-10-07 215121](https://github.com/user-attachments/assets/6c089a97-e91c-4e36-a0ca-398a9caa16db)
![Screenshot 2024-10-07 215107](https://github.com/user-attachments/assets/91fbb43d-1843-4343-a58a-d98518d38cee)
