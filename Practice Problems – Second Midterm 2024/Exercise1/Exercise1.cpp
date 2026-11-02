#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

void wtf() {
    ofstream fout("input.txt");
    string line;
    while (getline(cin, line)) {
        if (line == "----") {
            break;
        }
        fout << line << endl;
    }
}

void rff(string path) {
    ifstream fin(path);
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
}

class NoProductFoundException {
public:
    string category;

    NoProductFoundException(string category) : category(category) {}
};

class Product {
private:
    string name;
    string category;
    int price;
    int quantity;

public:
    Product(string name = "", string category = "",
            int price = 0, int quantity = 0)
        : name(name), category(category),
          price(price), quantity(quantity) {}

    int totalPrice() const {
        return price * quantity;
    }

    string getCategory() const {
        return category;
    }

    friend ostream& operator<<(ostream& out, const Product& p) {
        out << p.name << " (" << p.category << ") "
            << p.price << " x " << p.quantity
            << " = " << p.totalPrice();

        return out;
    }
};

class Store {
private:
    Product *products;
    int n;

public:
    Store() {
        products = nullptr;
        n = 0;
    }

    Store(const Store& other) {
        n = other.n;
        products = new Product[n];

        for (int i = 0; i < n; i++) {
            products[i] = other.products[i];
        }
    }

    Store& operator=(const Store& other) {
        if (this != &other) {
            delete[] products;

            n = other.n;
            products = new Product[n];

            for (int i = 0; i < n; i++) {
                products[i] = other.products[i];
            }
        }

        return *this;
    }

    Store& operator+=(const Product& p) {
        Product *temp = new Product[n + 1];

        for (int i = 0; i < n; i++) {
            temp[i] = products[i];
        }

        temp[n] = p;

        delete[] products;
        products = temp;
        n++;

        return *this;
    }

    Store fromCategory(string& category) {
        Store result;

        for (int i = 0; i < n; i++) {
            if (products[i].getCategory() == category) {
                result += products[i];
            }
        }

        if (result.n == 0) {
            throw NoProductFoundException(category);
        }

        return result;
    }

    friend ostream& operator<<(ostream& out, const Store& s) {
        for (int i = 0; i < s.n; i++) {
            out << s.products[i] << endl;
        }

        return out;
    }

    ~Store() {
        delete[] products;
    }
};

int main() {
    wtf();

    Store s;

    // TODO your code starts here
    // Read the products from the file and add them in the store `s`

    ifstream fin("input.txt");

    string name;
    string productCategory;
    int quantity, price;

    while (getline(fin, name)) {
        getline(fin, productCategory);
        fin >> quantity;
        fin >> price;
        fin.ignore();

        Product p(name, productCategory, price, quantity);
        s += p;
    }

    fin.close();

    // DO NOT MODIFY THE CODE BETWEEN THIS AND THE NEXT COMMENT

    string category;
    cin >> category;

    // DO NOT MODIFY THE CODE BETWEEN THIS AND THE PREVIOUS COMMENT

    // TODO Save the results in the files output1.txt and output2.txt after this line

    ofstream fout1("output1.txt");
    fout1 << s;
    fout1.close();

    ofstream fout2("output2.txt");

    try {
        Store filtered = s.fromCategory(category);
        fout2 << filtered;
    }
    catch (NoProductFoundException& e) {
        cout << "No products from category " << e.category
             << " were found in the store" << endl;
    }

    fout2.close();

    // DO NOT MODIFY THE CODE BELOW

    cout << "All products:" << endl;
    rff("output1.txt");

    cout << "Products from category " << category << ": " << endl;
    rff("output2.txt");

    return 0;
}
