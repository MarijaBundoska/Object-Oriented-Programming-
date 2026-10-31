#include <iostream>
#include <cstring>
using namespace std;

enum Type { LINUX, UNIX, WINDOWS };

class OperatingSystem {
    char* name;
    float version;
    Type type;
    float size;

    void copyOS(const OperatingSystem& other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->version = other.version;
        this->type = other.type;
        this->size = other.size;
    }

public:
    OperatingSystem() {
        this->name = new char[4];
        strcpy(this->name, "os");
        this->version = 0.1;
        this->type = LINUX;
        this->size = 1.0;
    }

    OperatingSystem(const char* name, const float version,
                    const Type type, const float size) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->version = version;
        this->type = type;
        this->size = size;
    }

    OperatingSystem(const OperatingSystem& other) {
        copyOS(other);
    }

    OperatingSystem& operator=(const OperatingSystem& other) {
        if (this == &other) {
            return *this;
        }

        delete[] this->name;
        copyOS(other);

        return *this;
    }

    void print() {
        cout << "Ime: " << name
             << " Verzija: " << version
             << " Tip: " << type
             << " Golemina:" << size << "GB"
             << "\n";
    }

    bool isEqual(const OperatingSystem& os) {
        return !strcmp(name, os.name)
            && version == os.version
            && type == os.type
            && size == os.size;
    }

    int compareVersion(const OperatingSystem& os) {
        return version == os.version ? 0
             : version < os.version ? -1
             : 1;
    }

    bool sameFamily(const OperatingSystem& comparison) {
        return !strcmp(name, comparison.name)
            && type == comparison.type;
    }

    ~OperatingSystem() {
        delete[] name;
    }
};

class Repository {
    char name[20];
    OperatingSystem* systems;
    int systemCount;

    void copyRepository(const Repository& other) {
        strcpy(this->name, other.name);

        this->systems = new OperatingSystem[other.systemCount];

        for (int i = 0; i < other.systemCount; i++) {
            this->systems[i] = other.systems[i];
        }

        this->systemCount = other.systemCount;
    }

public:
    Repository() {
        strcpy(this->name, "repo");
        systems = nullptr;
        systemCount = 0;
    }

    Repository(const char* name) {
        strcpy(this->name, name);
        this->systems = nullptr;
        systemCount = 0;
    }

    Repository(const Repository& other) {
        copyRepository(other);
    }

    Repository& operator=(const Repository& other) {
        if (this == &other) {
            return *this;
        }

        delete[] this->systems;
        copyRepository(other);

        return *this;
    }

    void printOperatingSystems() {
        cout << "Repozitorium: " << name << "\n";

        for (int i = 0; i < systemCount; i++) {
            systems[i].print();
        }
    }

    void remove(const OperatingSystem& operatingSystem) {
        int index = -1;

        for (int i = 0; i < systemCount; i++) {
            if (systems[i].isEqual(operatingSystem)) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            return;
        }

        for (int i = index; i < systemCount - 1; i++) {
            systems[i] = systems[i + 1];
        }

        systemCount--;
    }

    void add(const OperatingSystem& newSystem) {
        for (int i = 0; i < systemCount; i++) {
            if (systems[i].sameFamily(newSystem)
                && systems[i].compareVersion(newSystem) == -1) {
                systems[i] = newSystem;
                return;
            }
        }

        OperatingSystem* temp = new OperatingSystem[systemCount + 1];

        for (int i = 0; i < systemCount; i++) {
            temp[i] = systems[i];
        }

        temp[systemCount++] = newSystem;

        delete[] systems;

        this->systems = new OperatingSystem[systemCount];

        for (int i = 0; i < systemCount; i++) {
            this->systems[i] = temp[i];
        }

        delete[] temp;
    }

    ~Repository() {
        delete[] systems;
    }
};

int main() {
    char repositoryName[20];
    cin >> repositoryName;

    Repository repository = Repository(repositoryName);

    int operatingSystemCount = 0;
    cin >> operatingSystemCount;

    char name[20];
    float version;
    int type;
    float size;

    for (int i = 0; i < operatingSystemCount; i++) {
        cin >> name;
        cin >> version;
        cin >> type;
        cin >> size;

        OperatingSystem os =
            OperatingSystem(name, version, (Type)type, size);

        repository.add(os);
    }

    repository.printOperatingSystems();

    cin >> name;
    cin >> version;
    cin >> type;
    cin >> size;

    OperatingSystem os =
        OperatingSystem(name, version, (Type)type, size);

    cout << "=====Brishenje na operativen sistem=====" << endl;

    repository.remove(os);
    repository.printOperatingSystems();

    return 0;
}
