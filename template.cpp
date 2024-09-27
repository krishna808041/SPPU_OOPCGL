#include <iostream>
using namespace std;

template<typename T>
void sort(T a[], int n) {
    int pass_min;
    T temp;
    for (int i = 0; i < n - 1; i++) {
        pass_min = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[pass_min]) {
                pass_min = j;
            }
        }
        if (pass_min != i) {
            temp = a[i];
            a[i] = a[pass_min];
            a[pass_min] = temp;
        }
    }
    
    cout << "\nSorted elements are:\n";
    for (int i = 0; i < n; i++) {
        cout << "\t" << a[i];
    }
    cout << endl;
}

int main() {
    int n, ch;
    int a[10];
    float b[10];
    
    do {
        cout << "\nSelection Sort using function template";
        cout << "\n1. Sort Integer numbers.";
        cout << "\n2. Sort Float numbers.";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                cout << "\nSorting integers now..." << endl;
                cout << "Enter the number of integers (max 10): " << endl;
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cin >> a[i];
                }
                sort<int>(a, n);
                break;

            case 2:
                cout << "\nSorting floats now..." << endl;
                cout << "Enter the number of floats (max 10): " << endl;
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cin >> b[i];
                }
                sort<float>(b, n);
                break;

            case 3:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (ch != 3);

    return 0;
}

