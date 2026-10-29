#include <iostream>
#include <cstring>
using namespace std;

enum Type {
    pop, rap, rock
};

class Song {
private:
    char *name;
    int minutes;
    Type type;

    void copySong(const Song &other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->minutes = other.minutes;
        this->type = other.type;
    }

public:
    Song(const char *name = "", const int minutes = 1,
         const Type type = pop) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->minutes = minutes;
        this->type = type;
    }

    Song(const Song &other) {
        copySong(other);
    }

    Song &operator=(const Song &other) {
        if (this != &other) {
            delete[] this->name;
            copySong(other);
        }
        return *this;
    }

    int getMinutes() {
        return minutes;
    }

    Type getType() {
        return type;
    }

    void print() {
        cout << "\"" << name << "\"" << "-" << minutes << "min\n";
    }

    ~Song() {
        delete[] name;
    }
};

class CD {
private:
    Song songs[10];
    int number;
    int length;

    void copyCD(const CD &other) {
        for (int i = 0; i < other.number; i++) {
            this->songs[i] = other.songs[i];
        }
        this->number = other.number;
        this->length = other.length;
    }

public:
    CD(int length) {
        this->number = 0;
        this->length = length;
    }

    CD(const CD &other) {
        copyCD(other);
    }

    CD &operator=(const CD &other) {
        if (this != &other) {
            copyCD(other);
        }
        return *this;
    }

    Song getSong(int index) {
        return songs[index];
    }

    int getNumber() {
        return number;
    }

    void addSong(Song song) {
        int currentMinutes = 0;

        for (int i = 0; i < number; i++) {
            currentMinutes += songs[i].getMinutes();
        }

        if (number < 10 &&
            currentMinutes + song.getMinutes() <= length) {
            songs[number++] = song;
        }
    }

    void printSongsByType(Type type) {
        for (int i = 0; i < number; i++) {
            if (songs[i].getType() == type) {
                songs[i].print();
            }
        }
    }

    ~CD() {}
};

int main() {
    // The task is tested modularly
    int testCase;
    cin >> testCase;

    int n, minutes, songType;
    char songName[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;

        cin >> songName;
        cin >> minutes;
        cin >> songType;

        Song song(songName, minutes, (Type)songType);
        song.print();
    }
    else if (testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;

        CD favorite(20);
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> songName;
            cin >> minutes;
            cin >> songType;

            Song song(songName, minutes, (Type)songType);
            favorite.addSong(song);
        }

        for (int i = 0; i < n; i++) {
            (favorite.getSong(i)).print();
        }
    }
    else if (testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;

        CD favorite(20);
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> songName;
            cin >> minutes;
            cin >> songType;

            Song song(songName, minutes, (Type)songType);
            favorite.addSong(song);
        }

        for (int i = 0; i < favorite.getNumber(); i++) {
            (favorite.getSong(i)).print();
        }
    }
    else if (testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;

        CD favorite(20);
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> songName;
            cin >> minutes;
            cin >> songType;

            Song song(songName, minutes, (Type)songType);
            favorite.addSong(song);
        }

        cin >> songType;
        favorite.printSongsByType((Type)songType);
    }
    else if (testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;

        CD favorite(20);
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> songName;
            cin >> minutes;
            cin >> songType;

            Song song(songName, minutes, (Type)songType);
            favorite.addSong(song);
        }

        cin >> songType;
        favorite.printSongsByType((Type)songType);
    }

    return 0;
}
