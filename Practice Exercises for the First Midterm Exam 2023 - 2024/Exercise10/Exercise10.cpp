#include <iostream>
using namespace std;

struct Player {
    char username[15];
    int level;
    int points;
};

struct ComputerGame {
    char name[20];
    Player players[30];
    int n;
};

void bestPlayer(ComputerGame *games, int n) {
    int indexMostPlayers = 0;

    for (int i = 1; i < n; i++) {
        if (games[i].n > games[indexMostPlayers].n)
            indexMostPlayers = i;
    }

    ComputerGame mostPopular = games[indexMostPlayers];
    int maxIndex = 0;

    for (int i = 1; i < mostPopular.n; i++) {
        if (mostPopular.players[i].points > mostPopular.players[maxIndex].points)
            maxIndex = i;
        else if (mostPopular.players[i].points == mostPopular.players[maxIndex].points) {
            if (mostPopular.players[i].level > mostPopular.players[maxIndex].level)
                maxIndex = i;
        }
    }

    cout << "Najdobar igrac e igracot so korisnicko ime ";
    cout << mostPopular.players[maxIndex].username;
    cout << " koj ja igra igrata ";
    cout << mostPopular.name;
}

int main() {
    int n, m;
    char name[20];

    cin >> n;
    ComputerGame games[100];

    for (int i = 0; i < n; i++) {
        ComputerGame newGame;
        cin >> newGame.name >> newGame.n;

        Player players[30];

        for (int j = 0; j < newGame.n; j++) {
            Player newPlayer;
            cin >> newPlayer.username >> newPlayer.level >> newPlayer.points;
            newGame.players[j] = newPlayer;
        }

        games[i] = newGame;
    }

    bestPlayer(games, n);

    return 0;
}
