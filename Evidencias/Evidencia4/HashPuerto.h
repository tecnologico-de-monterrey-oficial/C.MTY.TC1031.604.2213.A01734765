#ifndef Hash_h
#define Hash_h

using namespace std;

class Hash {
private:
    string hashTable[99];
    bool status[99];
public:
    Hash();
    int hashFunction(string Dato);
    bool findDato(string Dato);
    void addDato(string Dato);
    void deleteDato(string Dato);
    void print();
    string findIndex(int index);
};

Hash::Hash() {}

int Hash::hashFunction(string Dato) {
    try {
        int numDato = stoi(to_string(Dato[Dato.size()-1]) + to_string(0)) ;
        return numDato % 99;
    } catch (invalid_argument &e) {
        return -1;
    }   
}

bool Hash::findDato(string Dato) {
    int index = hashFunction(Dato);
    int baseIndex = index;
    if (index >= 0) {
        while (hashTable[index] != "" || status[index]) {
            if (hashTable[index] == Dato) {
                return true;
            } else {
                index = (index + 1) % 99;
                if (index == baseIndex) {
                    return false;
                }
            }
        }
        return false;
    } else {
        return false;
    }
}

void Hash::addDato(string Dato) {
    int index = hashFunction(Dato);
    int baseIndex = index;
    if (index >= 0) {
        while (hashTable[index] != "") {
            index = (index + 1) % 99;
            if (index == baseIndex) {
                throw invalid_argument("La tabla esta llena");
                return;
            }
        }
        hashTable[index] = Dato;
        status[index] = false;
    } else {
        throw invalid_argument("El dato no es correcto");
    }
}

void Hash::deleteDato(string Dato) {
    int index = hashFunction(Dato);
    int baseIndex = index;
    if (index >= 0) {
        while (hashTable[index] != "" || status[index]) {
            if (hashTable[index] == Dato) {

                hashTable[index] = "";
                status[index] = true;
                return;
            } else {
                index = (index + 1) % 99;
                if (index == baseIndex) {
                    throw invalid_argument("El dato no se encuentra");
                    return; 
                }
            }
        }
        throw invalid_argument("El dato no se encuentra");
    } else {
        throw invalid_argument("El dato no es correcto");
    }
}

void Hash::print() {
    for (int i=0; i<99; i++) {
        cout << i << " " << hashTable[i] << endl;
    }
}

string Hash::findIndex(int index) {
    return hashTable[index];
}


#endif