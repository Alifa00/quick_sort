#include <iostream>
#include <sstream>

using namespace std;
void sort(int * arr, int lng) {
    int size = lng;
    int t = 0;
    int c = arr[lng / 2];
    do {
        while (arr[t] < c) t++;
        while (arr[lng] > c) lng--;
        if (t <= lng) {
            swap(arr[t], arr[lng]);
            t++;
            lng--;
        }
    }
    while (t <= lng);
    if (lng > 0) sort(arr, lng);
    if (size > t) sort(arr + t, size - t);
}
int main() {
    int lng = 0;
    string str;
    getline(cin, str);
    istringstream stream1(str);
    if (!(stream1 >> lng)) {
        cout <<"An error has occuried while reading input data." <<endl;
        exit(0);
    }
    int * arr = new int[lng];
    string arr_str;
    getline(cin, arr_str);
    istringstream stream(arr_str);
    for (int i = 0; i < lng; i++) {
        if (!(stream >> arr[i])) {
            cout <<"An error has occuried while reading input data." <<endl;
            delete[] arr;
            exit(0);
        }
    }
    sort(arr, lng - 1);
    for (int i = 0; i < lng; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
    return 0;
}


