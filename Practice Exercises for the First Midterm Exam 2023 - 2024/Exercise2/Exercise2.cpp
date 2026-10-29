#include <iostream>
#include <cstring>
using namespace std;

#define MAX 25

class List {
private:
    int *numbers;
    int length;

    void copyList(const List &other) {
        this->numbers = new int[other.length];

        for (int i = 0; i < other.length; i++) {
            this->numbers[i] = other.numbers[i];
        }

        this->length = other.length;
    }

public:
    List() {
        numbers = nullptr;
        length = 0;
    }

    List(int *numbers, int length) {
        this->numbers = new int[length];

        for (int i = 0; i < length; i++) {
            this->numbers[i] = numbers[i];
        }

        this->length = length;
    }

    List(const List &other) {
        copyList(other);
    }

    List& operator=(const List &other) {
        if (this != &other) {
            delete[] this->numbers;
            copyList(other);
        }

        return *this;
    }

    int getLength() {
        return length;
    }

    void print() {
        cout << length << ": ";

        for (int i = 0; i < length; i++) {
            cout << numbers[i] << " ";
        }

        cout << "sum: " << sum()
             << " average: " << average() << endl;
    }

    int sum() {
        int total = 0;

        for (int i = 0; i < length; i++) {
            total += numbers[i];
        }

        return total;
    }

    double average() {
        return (double)sum() / length;
    }

    ~List() {
        delete[] numbers;
    }
};

class ListContainer {
private:
    List *lists;
    int length;
    int attempts;

    void copyContainer(const ListContainer &other) {
        this->lists = new List[MAX];

        for (int i = 0; i < other.length; i++) {
            this->lists[i] = other.lists[i];
        }

        this->length = other.length;
        this->attempts = other.attempts;
    }

public:
    ListContainer() {
        this->lists = new List[MAX];
        this->length = this->attempts = 0;
    }

    ListContainer(const ListContainer &other) {
        copyContainer(other);
    }

    ListContainer& operator=(const ListContainer &other) {
        if (this != &other) {
            delete[] lists;
            copyContainer(other);
        }

        return *this;
    }

    void print() {
        if (length <= 0) {
            cout << "The list is empty" << endl;
            return;
        }

        for (int i = 0; i < length; i++) {
            cout << "List number: " << (i + 1) << " List info: ";
            lists[i].print();
        }

        cout << "Sum: " << sum() << " Average: " << average() << endl;
        cout << "Successful attempts: " << length
             << " Failed attempts: " << (attempts - length) << endl;
    }

    void addNewList(List list) {
        attempts++;

        for (int i = 0; i < length; i++) {
            if (lists[i].sum() == list.sum()) {
                return;
            }
        }

        lists[length++] = list;
    }

    int sum() {
        int total = 0;

        for (int i = 0; i < length; i++) {
            total += lists[i].sum();
        }

        return total;
    }

    double average() {
        int totalElements = 0;

        for (int i = 0; i < length; i++) {
            totalElements += lists[i].getLength();
        }

        return (double)sum() / totalElements;
    }

    ~ListContainer() {
        delete[] lists;
    }
};

int main() {
    ListContainer lc;
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int n;
        int numbers[100];

        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> numbers[j];
        }

        List list = List(numbers, n);
        lc.addNewList(list);
    }

    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "Test case for operator =" << endl;

        ListContainer lc1;
        lc1.print();

        cout << lc1.sum() << " " << lc.sum() << endl;

        lc1 = lc;
        lc1.print();

        cout << lc1.sum() << " " << lc.sum() << endl;

        lc1.sum();
        lc1.average();
    }
    else {
        lc.print();
    }

    return 0;
}
