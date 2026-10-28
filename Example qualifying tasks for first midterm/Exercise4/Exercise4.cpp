#include <iostream>

using namespace std;
class Temperature{
private:
    float t;
public:
    Temperature(){
        t=0;
    }
    Temperature(float t){
        this->t=t;
    }
    void changeTemp(){
        if(this->t<0){
            this->t+=1;
        }else{
            this->t-=1;
        }
    }
    void print(){
        cout<<t<<endl;
    }
    void set(float t){
        this->t=t;
    }
};
int main() {
    Temperature obj;
    int n;
    cin >> n;
    int cmd;
    float k;
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
                obj.changeTemp();
                obj.print();
                break;
            }
            case 3: {
                Temperature obj3;
                cin >> k;
                obj3.set(k);
                obj3.changeTemp();
                obj3.print();
                break;
            }
            default: {
                obj.print();
                break;
            }
        }
    }
}
