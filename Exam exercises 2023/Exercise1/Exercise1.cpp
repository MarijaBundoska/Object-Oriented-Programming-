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
    OnlineBook(char *isbn, char *title, char *author, double price=0, char *url, int size=0):Book(isbn, title, author, price){
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



