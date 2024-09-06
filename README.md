# Shannon-Fano Encoding

This repository contains a C++ implementation of the **Shannon-Fano Coding Algorithm**, a method used for lossless data compression. Shannon-Fano coding assigns shorter binary codes to more frequent characters and longer codes to less frequent ones, thereby reducing the overall size of the compressed data.

## How Shannon-Fano Coding Works

Shannon-Fano coding is an early data compression technique based on the relative probabilities of each symbol in the data. The core idea is to recursively split the set of symbols into two groups such that the sum of probabilities in both groups is approximately equal. The symbols in the first group are assigned binary codes starting with `0`, while the symbols in the second group are assigned codes starting with `1`.


## Shannon-Fano Coding Overview

Shannon-Fano coding is a method for compressing data by creating a variable-length, prefix-free binary code for each symbol in the data. The algorithm works by recursively splitting the symbols into two parts with equal total probabilities and assigning binary codes (`0` and `1`) to each part. The key advantage of Shannon-Fano coding is its simplicity, though it may not always achieve the same compression efficiency as Huffman coding, a similar algorithm that constructs an optimal binary tree.

Shannon-Fano coding is still useful for learning the basic principles of entropy-based compression, and its concepts are foundational to other, more advanced algorithms.

## Files Generated

- `compressed_text.txt`: Contains the compressed binary data.
- `dict.txt`: Contains the dictionary of characters and their corresponding Shannon-Fano codes.

### Key Steps:
1. **Calculate Probabilities**: The frequency of each character in the input data is computed to determine its probability of occurrence.
2. **Sort by Probability**: The characters are sorted in decreasing order based on their probabilities.
3. **Split the Characters**: The sorted characters are split into two groups with approximately equal total probabilities.
4. **Assign Codes**: Characters in the first group are assigned codes starting with `0`, and characters in the second group are assigned codes starting with `1`. This process is recursively applied to each group until each character has a unique code.
5. **Compression**: The input text is compressed by replacing each character with its corresponding binary code.

## Features

- Compresses text using Shannon-Fano coding.
- Supports manual text input or file-based input.
- Outputs the compressed data to `compressed_text.txt`.
- Generates a dictionary of symbols and their corresponding Shannon-Fano codes in `dict.txt`.

## Functions

### `split(vector<Symbol>& symbols, int start, int end)`
- **Purpose**: Splits the symbols into two parts with approximately equal total probabilities.
- **Process**: The function calculates the cumulative probabilities and returns the index where the list should be split to minimize the difference in probabilities between the two groups.

### `encoder(vector<Symbol>& symbols, int start, int end)`
- **Purpose**: Recursively assigns binary codes to the symbols based on their position in the two groups created by the split function.
- **Process**: Symbols in the first group receive a `0`, and symbols in the second group receive a `1`. The process is repeated for each group until all symbols have codes.

### `compressData(const string& data)`
- **Purpose**: Compresses the input text using Shannon-Fano coding and saves the compressed data and coding dictionary to files.
- **Process**:
    - Calculates character frequencies and creates a list of symbols.
    - Sorts the symbols by probability.
    - Calls `encoder` to assign binary codes to each symbol.
    - Writes the compressed text to `compressed_text.txt` and the dictionary to `dict.txt`.

## How to Use

1. Clone the repository:
    ```bash
    git clone https://github.com/Dimiqhz/Shannon-Fano-Encoding.git
    ```
2. Compile the code using a C++ compiler:
    ```bash
    g++ -o shannon_fano shannon_fano.cpp
    ```
3. Run the executable:
    ```bash
    ./shannon_fano
    ```
4. You will be prompted to either manually enter the text or load it from a file:
    ```
    Enter 1 to enter text manually, or 2 to load from a file: 
    ```
5. After selecting your option and entering the text or file path, the program will output:
    - The compressed data saved to `compressed_text.txt`
    - The coding dictionary saved to `dict.txt`
