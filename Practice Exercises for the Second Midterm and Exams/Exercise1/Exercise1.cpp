#include <iostream>
#include <cstring>
using namespace std;

class Book{
protected:
    char isbn[20];
    char title[50];
    char author[30];
    double price;

public:
    Book(const char *isbn, const char *title, const char *author, double price){
        strcpy(this->isbn, isbn);
        strcpy(this->title, title);
        strcpy(this->author, author);
        this->price = price;
    }

    virtual double bookPrice() = 0;

    bool operator>(Book &book){
        return bookPrice() > book.bookPrice();
    }

    friend ostream &operator<<(ostream &os, Book &b){
        os << b.isbn << ": " << b.title << ", "
           << b.author << " " << b.bookPrice() << endl;
        return os;
    }

    void setISBN(const char *isbn){
        strcpy(this->isbn, isbn);
    }

    virtual ~Book(){}
};

class OnlineBook : public Book{
private:
    char *url;
    int size;

public:
    OnlineBook(const char *isbn, const char *title, const char *author,
               double price, const char *url, int size)
        : Book(isbn, title, author, price){

        this->size = size;
        this->url = new char[strlen(url) + 1];
        strcpy(this->url, url);
    }

    OnlineBook(const OnlineBook &ob)
        : Book(ob.isbn, ob.title, ob.author, ob.price){

        size = ob.size;
        url = new char[strlen(ob.url) + 1];
        strcpy(url, ob.url);
    }

    OnlineBook &operator=(const OnlineBook &ob){
        if(this != &ob){
            strcpy(isbn, ob.isbn);
            strcpy(title, ob.title);
            strcpy(author, ob.author);
            price = ob.price;
            size = ob.size;

            delete[] url;
            url = new char[strlen(ob.url) + 1];
            strcpy(url, ob.url);
        }
        return *this;
    }

    double bookPrice(){
        return size > 20 ? price * 1.2 : price;
    }

    ~OnlineBook(){
        delete[] url;
    }
};

class PrintBook : public Book{
private:
    bool stock;
    double weight;

public:
    PrintBook(const char *isbn, const char *title, const char *author,
              double price, double weight, bool stock)
        : Book(isbn, title, author, price){

        this->stock = stock;
        this->weight = weight;
    }

    double bookPrice(){
        return weight > 0.7 ? price * 1.15 : price;
    }
};

void mostExpensiveBook(Book **books, int n){
    int numOnline = 0;
    int numPrint = 0;

    Book *mostExpensive = books[0];

    for(int i = 0; i < n; i++){
        OnlineBook *online = dynamic_cast<OnlineBook*>(books[i]);

        if(online != 0){
            numOnline++;
        }
        else{
            numPrint++;
        }

        if(*books[i] > *mostExpensive){
            mostExpensive = books[i];
        }
    }

    cout << "FINKI-Education" << endl;
    cout << "Total number of online books: " << numOnline << endl;
    cout << "Total number of print books: " << numPrint << endl;
    cout << "The most expensive book is: " << endl;
    cout << *mostExpensive;
}

int main(){
    char isbn[20], title[50], author[30], url[100];
    int size, type;
    float price, weight;
    bool inStock;

    Book **books;
    int n = 0;

    int testCase;
    cin >> testCase;

    if(testCase == 1){
        cout << "====== Testing OnlineBook class ======" << endl;
        cin >> n;
        books = new Book*[n];

        for(int i = 0; i < n; i++){
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price >> url >> size;

            cout << "CONSTRUCTOR" << endl;
            books[i] = new OnlineBook(isbn, title, author, price, url, size);

            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }

        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;

        if(*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    else if(testCase == 2){
        cout << "====== Testing OnlineBook CONSTRUCTORS ======" << endl;
        cin >> isbn;
        cin.get();
        cin.getline(title, 50);
        cin.getline(author, 30);
        cin >> price >> url >> size;

        cout << "CONSTRUCTOR" << endl;
        OnlineBook ob1(isbn, title, author, price, url, size);
        cout << ob1 << endl;

        cout << "COPY CONSTRUCTOR" << endl;
        OnlineBook ob2(ob1);
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;

        cout << "OPERATOR =" << endl;
        ob1 = ob2;
        cin >> isbn;
        ob2.setISBN(isbn);
        cout << ob1 << endl;
        cout << ob2 << endl;
    }
    else if(testCase == 3){
        cout << "====== Testing PrintBook class ======" << endl;
        cin >> n;
        books = new Book*[n];

        for(int i = 0; i < n; i++){
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price >> weight >> inStock;

            cout << "CONSTRUCTOR" << endl;
            books[i] = new PrintBook(isbn, title, author, price, weight, inStock);

            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }

        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;

        if(*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    else if(testCase == 4){
        cout << "====== Testing method mostExpensiveBook() ======" << endl;
        cin >> n;
        books = new Book*[n];

        for(int i = 0; i < n; i++){
            cin >> type >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;

            if(type == 1){
                cin >> url >> size;
                books[i] = new OnlineBook(isbn, title, author, price, url, size);
            }
            else{
                cin >> weight >> inStock;
                books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
            }
        }

        mostExpensiveBook(books, n);
    }

    if(testCase == 1 || testCase == 3 || testCase == 4){
        for(int i = 0; i < n; i++){
            delete books[i];
        }
        delete[] books;
    }

    return 0;
}
