#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <string>
#include <sstream>
#include <functional>

using namespace std;

struct Node {
    char character;
    double probability;
    string code;
    Node* left;
    Node* right;

    Node(char ch, double prob) : character(ch), probability(prob), left(nullptr), right(nullptr) {}
};

struct CompareNode {
    bool operator()(Node* lhs, Node* rhs) {
        return lhs->probability > rhs->probability;
    }
};

void buildHuffmanTree(vector<Node*>& nodes) {
    priority_queue<Node*, vector<Node*>, CompareNode> minHeap;
    for (auto node : nodes) {
        minHeap.push(node);
    }

    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* internalNode = new Node('\0', left->probability + right->probability);
        internalNode->left = left;
        internalNode->right = right;

        minHeap.push(internalNode);
    }

    Node* root = minHeap.top();

    function<void(Node*, string)> generateCodes = [&](Node* node, string currentCode) {
        if (!node) return;
        if (node->character != '\0') {
            node->code = currentCode;
        }
        generateCodes(node->left, currentCode + "0");
        generateCodes(node->right, currentCode + "1");
        };

    generateCodes(root, "");
}

string compressData(const string& data) {
    unordered_map<char, int> frequency;
    for (char ch : data) {
        frequency[ch]++;
    }

    vector<Node*> nodes;
    for (const auto& pair : frequency) {
        nodes.push_back(new Node(pair.first, static_cast<double>(pair.second) / data.size()));
    }

    buildHuffmanTree(nodes);

    unordered_map<char, string> huffmanCodes;
    for (auto node : nodes) {
        if (node->character != '\0') {
            huffmanCodes[node->character] = node->code;
        }
    }

    stringstream compressedText;
    for (char ch : data) {
        compressedText << huffmanCodes[ch];
    }

    ofstream compressedFile("compressed_text.txt");
    compressedFile << compressedText.str();
    compressedFile.close();

    ofstream dictFile("dict.txt");
    for (const auto& pair : huffmanCodes) {
        dictFile << "Symbol - " << pair.first << " :: Code - " << pair.second << "\n";
    }
    dictFile.close();

    return compressedText.str();
}

int main() {
    setlocale(LC_ALL, "English");

    int choice;
    cout << "Enter 1 to enter text manually, 2 to load from a file: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        cout << "Enter the text to compress: ";
        string text;
        getline(cin, text);
        compressData(text);
        cout << "Data saved to file compressed_text.txt" << endl;
        cout << "Dictionary saved to file dict.txt" << endl;
    }
    else if (choice == 2) {
        cout << "Specify the path to the file to load text: ";
        string filePath;
        getline(cin, filePath);
        ifstream file(filePath);
        if (!file.is_open()) {
            cerr << "File '" << filePath << "' not found." << endl;
            return 1;
        }
        stringstream buffer;
        buffer << file.rdbuf();
        string text = buffer.str();
        file.close();
        compressData(text);
        cout << "Data saved to file compressed_text.txt" << endl;
        cout << "Dictionary saved to file dict.txt" << endl;
    }
    else {
        cerr << "Invalid option selected." << endl;
        return 1;
    }

    return 0;
}
