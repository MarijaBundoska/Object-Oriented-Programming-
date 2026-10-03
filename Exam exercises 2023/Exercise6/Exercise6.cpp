#include <iostream>
#include <cstring>
using namespace std;

class ExistingGame{
private:
    char msg[256];
public:

    ExistingGame(char *msgTxt){
        strcpy(this->msg, msgTxt);
    }
    void message(){
        cout<<this->msg<<endl;
    }
};

class Game{
protected:
    char name[100];
    float price;
    bool onSale;
public:

    Game(){
        name[0] = '\0';
    }

    Game(char *name, float price, bool onSale=false){
        strcpy(this->name,name);
        this->price = price;
        this-> onSale = onSale;
    }

    virtual float getPrice(){
        if(onSale){
            return price * 0.3F;
        }
        return price;
    }

    bool operator==(Game &g){
        return !strcmp(this->name, g.name);
    }

    friend ostream &operator<<(ostream &o, const Game &g);
    friend istream &operator>>(istream &i, Game &g);
};
class SubscriptionGame : public Game{
protected:
    float monthlyFee;
    int month;
    int year;
public:
    SubscriptionGame(){
        name[0] = '\0';
    }

    SubscriptionGame(char *name, float price, bool onSale, float monthlyFee, int month, int year):Game(name, price, onSale){
        this->monthlyFee = monthlyFee;
        this->month = month;
        this->year = year;
    }

    float getPrice(){
        float price = Game::getPrice();

        int months = 0;
        if(year < 2018){
            months = (12 - this->month) + (2017 - year) * 12 + 5;
        }else{
            months = 5 - this->month;
        }
        price += months * monthlyFee;
        return price;
    }

    friend ostream &operator<<(ostream &out, SubscriptionGame & sg);
    friend istream &operator>>(istream &in, SubscriptionGame &g);
};

ostream &operator<<(ostream &out, const Game &g){
    out<<"Game: "<<g.name<<", regular price: $"<<g.price;

    if(g.onSale){
        out<<", bought on sale";
    }
    return out;
}

ostream &operator<<(ostream &out, SubscriptionGame &sg){
    Game * tmp = dynamic_cast<Game*>(&sg);

    out<<*tmp;

    out<<", monthly fee: $"<<sg.monthlyFee<<", purchased: "<<sg.month<<"-"<<sg.year<<endl;
    return out;
}

istream &operator>>(istream &in, Game &g){
    in.get();
    in.getline(g.name,100);
    in>>g.price>>g.onSale;
    return in;
}

istream &operator>>(istream &in, SubscriptionGame &g){
    in.get();
    in.getline(g.name, 100);
    in>>g.price>>g.onSale;
    in>>g.monthlyFee>>g.month>>g.year;
    return in;
}
class User{
private:

    void copy(const User *orig, User *cpy){
        strcpy(cpy->username, orig->username);
        cpy->numGames = orig->numGames;

        cpy->games = new Game *[cpy->numGames];

        for(int i=0; i<cpy->numGames; i++){
            cpy->games[i] = new Game(*(orig->games[i]));
        }
    }
protected:
    char username[100];
    Game ** games;
    int numGames;
public:

    User(char const * const username=""){
        strcpy(this->username, username);
        this->games = 0;
        this->numGames = 0;
    }

    User (const User & orig){
        copy(&orig, this);
    }

    ~User(){
        for(int i=0; i<this->numGames; i++){
            delete this->games[i];
        }
        delete[] games;
    }

    User &operator=(User &orig){
        if(&orig != this){

            for(int i=0; i<this->numGames; i++){
                delete this->games[i];
            }
            delete[] this->games;

            copy(&orig, this);
        }
        return *this;
    }

    User &operator+=(Game &g){
        Game ** newGames = new Game*[this->numGames+1];

        for(int i=0; i<(this->numGames); i++){
            if( ((*this->games[i])) == g){
                throw ExistingGame("The game is already in the collection");
            }
            newGames[i] = games[i];
        }
        for(int i=0; i<(this->numGames); i++){
            newGames[i] = games[i];
        }

        SubscriptionGame * sg = dynamic_cast<SubscriptionGame*>(&g);
        if(sg){
            newGames[numGames] = new SubscriptionGame(*sg);
        }else{
            newGames[numGames] = new Game(g);
        }

        delete[] this -> games;
        this->games = newGames;
        this->numGames++;

        return *this;
    }

    Game &getGame(int i){
        return (*(this->games[i]));
    }

    float total_spent(){
        float sum = 0.0f;
        for(int i=0; i<this->numGames; i++){
            sum+= games[i]->getPrice();
        }
        return sum;
    }

    char const * const getUsername(){
        return this->username;
    }

    int getGamesNumber(){
        return this->numGames;
    }
};

ostream &operator<<(ostream &out, User &u){
    out<<"\nUser: "<<u.getUsername()<<"\n";

    for(int i=0; i<u.getGamesNumber(); i++){
        Game *g;
        SubscriptionGame *sg;
        g = &(u.getGame(i));

        sg = dynamic_cast<SubscriptionGame*> (g);

        if(sg){
            cout<<"- "<<(*sg);
        }else{
            cout<<"- "<<(*g);
        }
        cout<<"\n";
    }
    return out;
}

int main(){
    int test_case_num;

    cin>>test_case_num;

    // for Game
    char game_name[100];
    float game_price;
    bool game_on_sale;

    // for SubscritionGame
    float sub_game_monthly_fee;
    int sub_game_month, sub_game_year;

    // for User
    char username[100];
    int num_user_games;

    if (test_case_num == 1){
        cout<<"Testing class Game and operator<< for Game"<<std::endl;
        cin.get();
        cin.getline(game_name,100);
        //cin.get();
        cin>>game_price>>game_on_sale;

        Game g(game_name, game_price, game_on_sale);

        cout<<g;
    }
    else if (test_case_num == 2){
        cout<<"Testing class SubscriptionGame and operator<< for SubscritionGame"<<std::endl;
        cin.get();
        cin.getline(game_name, 100);

        cin>>game_price>>game_on_sale;

        cin>>sub_game_monthly_fee;
        cin>>sub_game_month>>sub_game_year;

        SubscriptionGame sg(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
        cout<<sg;
    }
    else if (test_case_num == 3){
        cout<<"Testing operator>> for Game"<<std::endl;
        Game g;

        cin>>g;

        cout<<g;
    }
    else if (test_case_num == 4){
        cout<<"Testing operator>> for SubscriptionGame"<<std::endl;
        SubscriptionGame sg;

        cin>>sg;

        cout<<sg;
    }
    else if (test_case_num == 5){
        cout<<"Testing class User and operator+= for User"<<std::endl;
        cin.get();
        cin.getline(username,100);
        User u(username);

        int num_user_games;
        int game_type;
        cin >>num_user_games;

        try {

            for (int i=0; i<num_user_games; ++i){

                cin >> game_type;

                Game *g;
                // 1 - Game, 2 - SubscriptionGame
                if (game_type == 1){
                    cin.get();
                    cin.getline(game_name, 100);

                    cin>>game_price>>game_on_sale;
                    g = new Game(game_name, game_price, game_on_sale);
                }
                else if (game_type == 2){
                    cin.get();
                    cin.getline(game_name, 100);

                    cin>>game_price>>game_on_sale;

                    cin>>sub_game_monthly_fee;
                    cin>>sub_game_month>>sub_game_year;
                    g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
                }

                //cout<<(*g);


                u+=(*g);
            }
        }catch(ExistingGame &ex){
            ex.message();
        }

        cout<<u;

//    cout<<"\nUser: "<<u.get_username()<<"\n";

//    for (int i=0; i < u.get_games_number(); ++i){
//        Game * g;
//        SubscriptionGame * sg;
//        g = &(u.get_game(i));

//        sg = dynamic_cast<SubscriptionGame *> (g);

//        if (sg){
//          cout<<"- "<<(*sg);
//        }
//        else {
//          cout<<"- "<<(*g);
//        }
//        cout<<"\n";
//    }

    }
    else if (test_case_num == 6){
        cout<<"Testing exception ExistingGame for User"<<std::endl;
        cin.get();
        cin.getline(username,100);
        User u(username);

        int num_user_games;
        int game_type;
        cin >>num_user_games;

        for (int i=0; i<num_user_games; ++i){

            cin >> game_type;

            Game *g;
            // 1 - Game, 2 - SubscriptionGame
            if (game_type == 1){
                cin.get();
                cin.getline(game_name, 100);

                cin>>game_price>>game_on_sale;
                g = new Game(game_name, game_price, game_on_sale);
            }
            else if (game_type == 2){
                cin.get();
                cin.getline(game_name, 100);

                cin>>game_price>>game_on_sale;

                cin>>sub_game_monthly_fee;
                cin>>sub_game_month>>sub_game_year;
                g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month, sub_game_year);
            }

            //cout<<(*g);

            try {
                u+=(*g);
            }
            catch(ExistingGame &ex){
                ex.message();
            }
        }

        cout<<u;

//      for (int i=0; i < u.get_games_number(); ++i){
//          Game * g;
//          SubscriptionGame * sg;
//          g = &(u.get_game(i));

//          sg = dynamic_cast<SubscriptionGame *> (g);

//          if (sg){
//            cout<<"- "<<(*sg);
//          }
//          else {
//            cout<<"- "<<(*g);
//          }
//          cout<<"\n";
//      }
    }
    else if (test_case_num == 7) {
        cout << "Testing total_spent method() for User" << std::endl;
        cin.get();
        cin.getline(username, 100);
        User u(username);

        int num_user_games;
        int game_type;
        cin >> num_user_games;

        for (int i = 0; i < num_user_games; ++i) {

            cin >> game_type;

            Game *g;
            // 1 - Game, 2 - SubscriptionGame
            if (game_type == 1) {
                cin.get();
                cin.getline(game_name, 100);

                cin >> game_price >> game_on_sale;
                g = new Game(game_name, game_price, game_on_sale);
            } else if (game_type == 2) {
                cin.get();
                cin.getline(game_name, 100);

                cin >> game_price >> game_on_sale;

                cin >> sub_game_monthly_fee;
                cin >> sub_game_month >> sub_game_year;
                g = new SubscriptionGame(game_name, game_price, game_on_sale, sub_game_monthly_fee, sub_game_month,
                                         sub_game_year);
            }

            //cout<<(*g);


            u += (*g);
        }

        cout << u;

        cout << "Total money spent: $" << u.total_spent() << endl;
    }
        return 0;

}
