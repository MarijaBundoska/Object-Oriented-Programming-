#include <iostream>
#include <cstring>
using namespace std;
enum Size{
    small, large, family
};

class Pizza{
protected:
    string name;
    string ingredients;
    double price_;
private:

    void copy(const Pizza &other){
        this->name = other.name;
        this->ingredients = other.ingredients;
        this->price_ = other.price_;
    }
public:
    Pizza(const string &name = "", const string &ingredients = "", double price = 0.0){
        this->name = name;
        this->ingredients = ingredients;
        this->price_ = price;
    }
    Pizza(const Pizza &other){
        copy(other);
    }
    Pizza &operator =(const Pizza &other){
        if(this != &other){
            copy(other);
        }
        return *this;
    }
    virtual ~Pizza(){}

    virtual double price() const{
        return price_;
    }
    bool operator<(const Pizza &other) const{
        return this->price() < other.price();
    }
    bool operator>(const Pizza &other) const{
        return this->price() > other.price();
    }
    virtual void print(ostream &out) const = 0;

    friend ostream &operator<<(ostream &out, const  Pizza &p){
        p.print(out);
        return out;
    }
};

class FlatPizza: public Pizza{
protected:
    Size type;
public:
    FlatPizza(const string &name = "", const string &ingredients = "", double price_ = 0.0, Size type= small):Pizza(name, ingredients, price_){
        this->type = type;
    }

    ~FlatPizza(){}

    virtual double price() const override{
        double tempPrice = price_;
        if(type == small){
            return tempPrice * 1.1;
        } else if(type == large){
            return tempPrice * 1.2;
        } else if(type == family){
            return tempPrice * 1.3;
        }
        else{
            return tempPrice;
        }
    }
    void print(ostream &out) const override{
        out<<name<<": "<<ingredients<<", ";
        if(type == small){
            out<<"small - "<<price() <<endl;
        }else if(type == large){
            out<<"large - "<<price() <<endl;
        }else if(type == family){
            out<<"family - "<<price() <<endl;
        }
    }
};
class FoldedPizza: public Pizza{
protected:
    bool flour;
public:
    FoldedPizza(const string &name = "", const string &ingredients = "", double price_ = 0.0, bool flour=true): Pizza(name, ingredients, price_){
        this->flour = flour;
    }
    FoldedPizza(const FoldedPizza &tmp) : Pizza(tmp){
        this->flour = tmp.flour;
    }
    ~FoldedPizza(){}

    void setWhiteFlour(bool temp){
        flour = temp;
    }
    virtual double price() const{
        double temp = price_;
        if(flour){
            return temp * 1.1;
        }
        else{
            return temp * 1.3;
        }
    }
    void print(ostream &out) const override{
        out<< name <<": "<<ingredients<<", ";
        if(flour) out<<"wf - ";
        else out << "nwf - ";
        out<< price() <<endl;
    }
};
void expensivePizza(Pizza **pizzas, int n){
    if(n == 0) return;
    double maxPrice = pizzas[0]->price();
    int index = 0;

    for(int i=1; i<n; i++){
        double currentPrice = pizzas[i]->price();
        if(currentPrice > maxPrice){
            maxPrice = currentPrice;
            index = i;
        }
    }
    cout<< *pizzas[index];
}

int main(){
    int test_case;
    char name[20];
    char ingredients[100];
    float inPrice;
    Size size;
    bool whiteFlour;

    cin >> test_case;
    if (test_case == 1) {
        // Test Case FlatPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FlatPizza fp(name, ingredients, inPrice);
        cout << fp;
    } else if (test_case == 2) {
        // Test Case FlatPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        int s;
        cin>>s;
        FlatPizza fp(name, ingredients, inPrice, (Size)s);
        cout << fp;

    } else if (test_case == 3) {
        // Test Case FoldedPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza fp(name, ingredients, inPrice);
        cout << fp;
    } else if (test_case == 4) {
        // Test Case FoldedPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name,20);
        cin.getline(ingredients,100);
        cin >> inPrice;
        FoldedPizza fp(name, ingredients, inPrice);
        fp.setWhiteFlour(false);
        cout << fp;

    } else if (test_case == 5) {
        // Test Cast - operator <, price
        int s;

        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        cin >> s;
        FlatPizza *fp1 = new FlatPizza(name, ingredients, inPrice, (Size) s);
        cout << *fp1;

        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        cin >> s;
        FlatPizza *fp2 = new FlatPizza(name, ingredients, inPrice, (Size) s);
        cout << *fp2;

        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        FoldedPizza *fp3 = new FoldedPizza(name, ingredients, inPrice);
        cout << *fp3;

        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        FoldedPizza *fp4 = new FoldedPizza(name, ingredients, inPrice);
        fp4->setWhiteFlour(false);
        cout << *fp4;
        cout << "Lower price: " << endl;
        if (*fp1 < *fp2)
            cout << fp1->price() << endl;
        else cout << fp2->price() << endl;

        if (*fp1 < *fp3)
            cout << fp1->price() << endl;
        else cout << fp3->price() << endl;

        if (*fp4 < *fp2)
            cout << fp4->price() << endl;
        else cout << fp2->price() << endl;

        if (*fp3 < *fp4)
            cout << fp3->price() << endl;
        else cout<<fp4->price()<<endl;

    } else if (test_case == 6) {
        // Test Cast - expensivePizza
        int num_p;
        int pizza_type;

        cin >> num_p;
        Pizza **pi = new Pizza *[num_p];
        for (int j = 0; j < num_p; ++j) {

            cin >> pizza_type;
            if (pizza_type == 1) {
                cin.get();
                cin.getline(name,20);

                cin.getline(ingredients,100);
                cin >> inPrice;
                int s;
                cin>>s;
                FlatPizza *fp = new FlatPizza(name, ingredients, inPrice, (Size)s);
                cout << (*fp);
                pi[j] = fp;
            }
            if (pizza_type == 2) {

                cin.get();
                cin.getline(name,20);
                cin.getline(ingredients,100);
                cin >> inPrice;
                FoldedPizza *fp =
                        new FoldedPizza (name, ingredients, inPrice);
                if(j%2)
                    (*fp).setWhiteFlour(false);
                cout << (*fp);
                pi[j] = fp;

            }
        }

        cout << endl;
        cout << "The most expensive pizza:\n";
        expensivePizza(pi,num_p);


    }
    return 0;
}
