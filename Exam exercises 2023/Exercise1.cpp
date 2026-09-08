// # Exam exercise - FINKI-Education

// ## English Description
// FINKI-Education publishing house issues online and printed books. For each book, information about the ISBN (array of max 20 characters), title (array of max 50 characters), 
//   author (array of max 30 characters), and base price in $ (real number) is stored. The base class for describing books is abstract.

// For each online book, additional data is kept for the download URL (dynamically allocated character array) and size in MB (integer).
// For each printed book, additional data is kept for weight in kg (real number) and whether it is in stock (boolean).

// Implement the following methods for derived classes:
// - `bookPrice()`: Calculates the selling price (Online: +20% base price if size > 20MB; Printed: +15% base price if weight > 0.7kg).
// - Operator `>`: Compares two books by selling price.
// - Operator `<<`: Prints book details.
// - Global function `mostExpensiveBook(Book** books, int n)`: Counts online and printed books, then prints details of the most expensive book.

// ---

// ## Испитна задача - FINKI-Education
// Издавачката куќа FINKI-Education издава онлајн и печатени книги. За секоја книга се чуваат податоци за ISBN бројот (низа од најмногу 20 знаци), насловот (низа од најмногу 50 знаци),
// авторот (низа од најмногу 30 знаци) и основната цена изразена во $ (реален број). Класата за опишување на книгите е апстрактна.

// За секоја онлајн книга дополнително се чуваат податоци за url од каде може да се симне (динамички резервирана низа од знаци) и големината изразена во MB (цел број).
// За секоја печатена книга дополнително се чуваат податоци за масата изразена во килограми (реален број) и дали ја има на залиха (логичка променлива).

// За секој објект од двете изведени класи треба да бидат на располагање следниве методи:
// - `bookPrice()`: Пресметување на продажната цена (Онлајн: +20% од основната цена ако е > 20MB; Печатена: +15% од основната цена ако е > 0.7kg).
// - Преоптоварен оператор `>` за споредба на две книги според нивната цена.
// - Преоптоварен оператор `<<` за печатење на податоците за книгите.
// - Глобална функција `mostExpensiveBook(Book** books, int n)` која го печати вкупниот број на онлајн и печатени книги посебно, а потоа ја наоѓа и печати најскапата книга.

#include <iostream>
#include <cstring>
using namespace std;

class Book{
protected:
    char isbn[21];
    char title[51];
    char author[31];
    double price;
public:
    Book(char *isbn, char *title, char *author, double price=0){
        strcpy(this->isbn,isbn);
        strcpy(this->title,title);
        strcpy(this->author,author);
        this->price=price;
    }
    virtual double bookPrice() = 0;

    bool operator>(Book &book){
        return bookPrice() > book.bookPrice();
    }
    friend ostream &operator<<(ostream &os, Book &b){
        os<<b.isbn<<": "<<b.title<<", "<<b.author<<" "<<b.bookPrice()<<endl;
        return os;
    }
    void setISBN(char *isbn){
        strcpy(this->isbn, isbn);
    }
    virtual ~Book() {}
};
class OnlineBook: public Book{
private:
    char *url;
    int size;

    void copy(const OnlineBook &other){
        strcpy(this->isbn, other.isbn);
        strcpy(this->title, other.title);
        strcpy(this->author, other.author);
        this->price = other.price;
        this->size = other.size;

        this->url = new char[strlen(other.url)+1];
        strcpy(this->url, other.url);
    }
public:
    OnlineBook(char *isbn, char *title, char *author, double price, char *url, int size=0):Book(isbn, title, author, price){
        this->size = size;
        this->url = new char[strlen(url)+1];
        strcpy(this->url, url);
    }
    OnlineBook(const OnlineBook &other):Book(other){
        copy(other);
    }
    OnlineBook &operator=(const OnlineBook &other){
        if(this!= &other){
            delete[] this->url;
            copy(other);
        }
        return *this;
    }

    double bookPrice(){
        return size>20 ? price * 1.20 : price;
    }

    ~OnlineBook(){
        delete[] url;
    }
};

class PrintBook: public Book{
private:
    bool stock;
    double weight;
public:
    PrintBook(char *isbn, char *title, char *author, double price=0, double weight=0, bool stock=false):Book(isbn, title, author, price){
        this->stock = stock;
        this->weight = weight;
    }
    double bookPrice(){
        return weight > 0.7 ? price*1.15 : price;
    }
};

void mostExpensiveBook(Book **books, int n){

    if(n <=0) return;
    int numOnline=0;
    int numPrint=0;
    Book *mostExpensive = books[0];

    for(int i=0; i<n; i++){
        if(dynamic_cast<OnlineBook*>(books[i])){
            numOnline++;
        }else{
            numPrint++;
        }
        if(*books[i] > *mostExpensive){
            mostExpensive = books[i];
        }
    }
    cout<<"FINKI-Education"<<endl;
    cout<<"Total number of online books: "<<numOnline<<endl;
    cout<<"Total number of print books: "<<numPrint<<endl;
    cout<<"The most expensive book is: "<<endl;
    cout<<*mostExpensive<<endl;
}
int main(){
    char isbn[20], title[50], author[30], url[100];
    int size, tip;
    float price, weight;
    bool inStock;
    Book **books;
    int n;

    int testCase;
    cin>>testCase;


    if (testCase == 1){
        cout << "====== Testing OnlineBook class ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++){
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> url;
            cin >> size;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new OnlineBook(isbn, title, author, price, url, size);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 2){
        cout << "====== Testing OnlineBook CONSTRUCTORS ======" << endl;
        cin >> isbn;
        cin.get();
        cin.getline(title, 50);
        cin.getline(author, 30);
        cin >> price;
        cin >> url;
        cin >> size;
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
    if (testCase == 3){
        cout << "====== Testing PrintBook class ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i < n; i++){
            cin >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            cin >> weight;
            cin >> inStock;
            cout << "CONSTRUCTOR" << endl;
            books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
            cout << "OPERATOR <<" << endl;
            cout << *books[i];
        }
        cout << "OPERATOR >" << endl;
        cout << "Rezultat od sporedbata e: " << endl;
        if (*books[0] > *books[1])
            cout << *books[0];
        else
            cout << *books[1];
    }
    if (testCase == 4){
        cout << "====== Testing method mostExpensiveBook() ======" << endl;
        cin >> n;
        books = new Book *[n];

        for (int i = 0; i<n; i++){

            cin >> tip >> isbn;
            cin.get();
            cin.getline(title, 50);
            cin.getline(author, 30);
            cin >> price;
            if (tip == 1) {

                cin >> url;
                cin >> size;

                books[i] = new OnlineBook(isbn, title, author, price, url, size);

            }
            else {
                cin >> weight;
                cin >> inStock;

                books[i] = new PrintBook(isbn, title, author, price, weight, inStock);
            }
        }

        mostExpensiveBook(books, n);
    }

    for (int i = 0; i<n; i++) delete books[i];
    delete[] books;
    return 0;
}

