#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");    
    int number;
    cout << "”кажите число: ";
    cin >> number; 
    cout << "„исло на 1 больше: " << (number + 1) << endl;
    cout << "„исло на 1 меньше: " << (number - 1) << endl;
    return 0;
}
