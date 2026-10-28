#include <iostream>
#include <cstring>
using namespace std;
class Number{
private:
    int n;
public:
    Number(){
        this->n=0;
    }
    int get(){
        return this->n;
    }
    Number(int number){
        this->n=number;
    }
    void decreaseNumber(int k){
        if(this->n-k<0){
            this->n=0;
            cout<<"Difference is less than 0"<<endl;
        }else{
            this->n-=k;
        }
    }
    void set(int s){
        n=s;
    }
    void print(){
        cout<<this->n<<endl;
    }
};
int main(){
    Number obj;
    int n;
    cin >> n;
    int cmd;
    int k;
    for (int i = 0; i < n; i++) {
        cin >> cmd;
        switch (cmd) {
            case 1: {
                cin >> k;
                obj.set(k);
                obj.print();
                break;
            }
            case 2: {
                cin >> k;
                obj.decreaseNumber(k);
                obj.print();
                break;
            }
            case 3: {
                Number obj2;
                cin >> k;
                obj2.set(k);
                cin >> k;
                obj2.decreaseNumber(k);
                obj2.print();
                break;
            }
            default: {
                obj.print();
                break;
            }
        }
    }
    return 0;
}
