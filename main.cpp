#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");    
    int number;
    cout << "������� �����: ";
    cin >> number; 
    cout << "����� �� 1 ������: " << (number + 1) << endl;
    cout << "����� �� 1 ������: " << (number - 1) << endl;
    return 0;
}
