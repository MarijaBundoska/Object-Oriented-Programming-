#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Song {
private:
    string title;
    string author;
    string performer;
    int duration;

public:
    Song() {
        title = "";
        author = "";
        performer = "";
        duration = 0;
    }

    Song(string title, string author, string performer, int duration) {
        this->title = title;
        this->author = author;
        this->performer = performer;
        this->duration = duration;
    }

    void set(string title, string author, string performer, int duration) {
        this->title = title;
        this->author = author;
        this->performer = performer;
        this->duration = duration;
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    string getPerformer() const {
        return performer;
    }

    int getDuration() const {
        return duration;
    }

    friend istream& operator>>(istream& in, Song& s) {
        getline(in, s.title);
        getline(in, s.author);
        getline(in, s.performer);
        in >> s.duration;
        in.ignore(1000, '\n');

        return in;
    }

    void print(ofstream& out) {
        out << "Song title: " << title
            << ", Author: " << author
            << ", Interpreted by: " << performer
            << ", " << duration << " sek." << endl;
    }

    bool operator==(const Song& s) const {
        return title == s.title &&
               author == s.author &&
               performer == s.performer &&
               duration == s.duration;
    }
};

class Festival {
private:
    string name;
    string city;
    string date;
    Song* songs;
    int n;

public:
    Festival() {
        name = "Empty Festival";
        city = "No city";
        date = "XX/XX/XXXX";
        songs = nullptr;
        n = 0;
    }

    Festival(string name, string city, string date, Song* songs, int n) {
        this->name = name;
        this->city = city;
        this->date = date;
        this->n = n;

        this->songs = new Song[n];

        for (int i = 0; i < n; i++) {
            this->songs[i] = songs[i];
        }
    }

    Festival(const Festival& f) {
        name = f.name;
        city = f.city;
        date = f.date;
        n = f.n;

        songs = new Song[n];

        for (int i = 0; i < n; i++) {
            songs[i] = f.songs[i];
        }
    }

    Festival& operator=(const Festival& f) {
        if (this != &f) {
            delete[] songs;

            name = f.name;
            city = f.city;
            date = f.date;
            n = f.n;

            songs = new Song[n];

            for (int i = 0; i < n; i++) {
                songs[i] = f.songs[i];
            }
        }

        return *this;
    }

    ~Festival() {
        delete[] songs;
    }

    friend istream& operator>>(istream& in, Festival& f) {
        getline(in, f.name);
        getline(in, f.city);
        getline(in, f.date);

        in >> f.n;
        in.ignore(1000, '\n');

        delete[] f.songs;
        f.songs = new Song[f.n];

        for (int i = 0; i < f.n; i++) {
            in >> f.songs[i];
        }

        return in;
    }

    Festival& operator-=(const Song& s) {
        if (n == 0) {
            cout << "Trying to delete from an empty list!" << endl;
            return *this;
        }

        int newN = 0;

        for (int i = 0; i < n; i++) {
            if (!(songs[i] == s)) {
                newN++;
            }
        }

        Song* temp = new Song[newN];
        int j = 0;

        for (int i = 0; i < n; i++) {
            if (!(songs[i] == s)) {
                temp[j++] = songs[i];
            }
        }

        delete[] songs;
        songs = temp;
        n = newN;

        return *this;
    }

    void print(ofstream& out) {
        out << "Festival: " << name << " - "
            << city << ", " << date << endl;

        for (int i = 0; i < n; i++) {
            songs[i].print(out);
        }
    }

    Festival notFromAuthor(string author) {
        Festival result;

        result.name = name;
        result.city = city;
        result.date = date;

        int count = 0;

        for (int i = 0; i < n; i++) {
            if (songs[i].getAuthor() != author) {
                count++;
            }
        }

        result.n = count;
        result.songs = new Song[count];

        int j = 0;

        for (int i = 0; i < n; i++) {
            if (songs[i].getAuthor() != author) {
                result.songs[j++] = songs[i];
            }
        }

        return result;
    }
};

void wtf() {
    ofstream fout("vlezna.txt");
    string line;
    while (getline(std::cin, line)) {
        if (line == "----"){
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

int main() {

    wtf();

    Festival festival;
    //TODO your code here
    //TODO Read the data from the file and store them in `festival`

    ifstream fin("vlezna.txt");
    fin >> festival;
    fin.close();

    Song s;
    festival -= s;

    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE NEXT COMMENT
    string author;
    getline(cin, author);
    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE PREVIOUS COMMENT

    //TODO Save the results in the files izlezna1.txt and izlezna2.txt after this line

    ofstream fout1("izlezna1.txt");
    festival.print(fout1);
    fout1.close();

    Festival filtered = festival.notFromAuthor(author);

    ofstream fout2("izlezna2.txt");
    filtered.print(fout2);
    fout2.close();

    //DO NOT MODIFY THE CODE BELLOW

    cout << "All the data for the festival:" << endl;
    rff("izlezna1.txt");
    cout << "Songs NOT from the author " << author << ": " << endl;
    rff("izlezna2.txt");

    return 0;
}
