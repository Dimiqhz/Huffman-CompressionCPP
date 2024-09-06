# Huffman Coding Compression Algorithm

## Overview

This C++ program implements the Huffman coding algorithm for data compression. Huffman coding is an entropy encoding algorithm that assigns variable-length codes to input characters based on their frequencies. This technique is used to achieve efficient data compression.

## Theory

The Huffman coding algorithm is used for lossless data compression. The process includes:

1. **Calculate Frequencies**: Determine the frequency of each character in the input data.
2. **Create Nodes**: Generate a node for each character with its frequency.
3. **Build Huffman Tree**: Construct a binary tree where each node represents a character or an internal node with combined frequencies. Nodes with lower frequencies are merged first.
4. **Generate Codes**: Traverse the Huffman tree to assign binary codes to each character. Characters that occur more frequently are assigned shorter codes.
5. **Compress Data**: Encode the input data using the generated Huffman codes.
6. **Generate Output**: Save the compressed data and encoding dictionary to separate files.

## Code Explanation

### `struct Node`

- **Purpose**: Defines the structure for each node in the Huffman tree.
- **Members**:
  - `char character`: The character represented by the node (for leaf nodes).
  - `double probability`: The probability of the character occurring in the input data.
  - `string code`: The Huffman code assigned to the character.
  - `Node* left`, `Node* right`: Pointers to the left and right children of the node.

### `struct CompareNode`

- **Purpose**: A comparison struct used to create a min-heap of `Node` pointers based on their `probability`.
- **Method**:
  - `bool operator()(Node* lhs, Node* rhs)`: Returns `true` if the `lhs` node has a higher probability than the `rhs` node, ensuring that nodes with lower probabilities are merged first.

### `void buildHuffmanTree(vector<Node*>& nodes)`

- **Input**: A vector of pointers to `Node` objects.
- **Process**:
  1. Initialize a priority queue (min-heap) with the nodes.
  2. Repeatedly merge the two nodes with the smallest probabilities to create new internal nodes.
  3. Build the Huffman tree and assign binary codes to characters using a recursive traversal function.
- **Output**: Huffman tree with codes assigned to characters.

### `string compressData(const string& data)`

- **Input**: A string of data to be compressed.
- **Process**:
  1. Calculate the frequency of each character.
  2. Create nodes for each character and build the Huffman tree.
  3. Generate a map of characters to their Huffman codes.
  4. Encode the input data using the Huffman codes.
  5. Save the compressed data to `compressed_text.txt` and the encoding dictionary to `dict.txt`.
- **Output**: Compressed text and encoding dictionary files.

### `int main()`

- **Purpose**: Handles user interaction and program flow.
- **Process**:
  1. Prompt the user to choose between manual text input or loading text from a file.
  2. Read the input text based on the user's choice.
  3. Call `compressData` to process the text and generate output files.
- **Output**: Notifies the user that the data and dictionary have been saved to files.

## Usage

1. **Compile the Program**:
   ```bash
   g++ -o huffman huffman.cpp
