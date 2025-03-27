#include <iostream>
#include <cstring>

using namespace std;

struct Artifact {
    string id;
    unsigned int m;
};

void insertionSort (Artifact* arr, int n) {
    for (int i = 1; i < n; ++i) {
        Artifact key = arr[i];
        int j = i - 1;
        while (j >= 0 && (arr[j].m > key.m)) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    unsigned int t;
    unsigned int n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        Artifact* artifacts = new Artifact[n];
        for (int j = 0; j < n; ++j){
            cin >> artifacts[j].id >> artifacts[j].m;
        }
        insertionSort(artifacts, n);
        unsigned long long total = 0;
        unsigned long long mass = 0;
        for (int j = 0; j < n; ++j) {
            total += mass + artifacts[j].m;
            mass += artifacts[j].m;
        }
        cout << total << '\n';
        for (int j = 0; j < n; ++j) {
            cout << artifacts[j].id;
            if (j < n - 1) {
                cout << ' ';
            }
        }
        cout << '\n';
        delete[] artifacts;
    }
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.