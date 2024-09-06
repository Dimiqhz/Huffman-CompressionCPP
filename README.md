# Shannon-Fano Compression Algorithm

## Overview

This Python script implements the Shannon-Fano algorithm for data compression. Shannon-Fano coding is a method of entropy encoding that assigns variable-length codes to input characters based on their frequencies.

## Theory

The Shannon-Fano algorithm is used for lossless data compression. The process includes:

1. **Calculate Probabilities**: Determine the frequency of each character in the input data and compute their probabilities.
2. **Sort Characters**: Arrange characters by their probabilities in descending order.
3. **Split and Encode**: Recursively divide the list of characters into two parts, assigning '0' to one part and '1' to the other. Continue this process for each subset until all characters receive a unique binary code.
4. **Generate Output**: Save the compressed text and encoding dictionary to separate files.

## Code Explanation

### `compress_data(data)`

- **Input**: A string of data to be compressed.
- **Process**:
  1. Calculate frequency and probability of each character.
  2. Sort characters by probability.
  3. Use the `splitter` function to find the optimal split point.
  4. Encode characters with the `encoder` function.
  5. Save compressed data to `compressed_text.txt` and the encoding dictionary to `dict.txt`.
- **Output**: Compressed text and encoding dictionary files.

### `splitter(probability, pointer)`

- **Input**: A list of probabilities and a pointer.
- **Process**: Recursively find the best split point where the difference between sums of probabilities on either side of the split is minimized.
- **Output**: Optimal split point index.

### `encoder(compressor, split)`

- **Input**: List of characters to encode and split point index.
- **Process**: Assign binary codes ('0' and '1') based on the split point. Recursively encode each subset.
- **Output**: Updated encoding codes.

## Usage

1. **Run the Script**: Execute the script to start the compression process.
2. **Choose Input Method**: Select between manual text input or providing a file path.
3. **View Results**: Compressed text will be saved to `compressed_text.txt`, and encoding dictionary will be saved to `dict.txt`.

### Example

```bash
python shannon_fano_compression.py
