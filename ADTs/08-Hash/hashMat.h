#pragma once

#ifndef HashMat_h
#define HashMat_h


class HashMat{
    private:
        string hashTable[99];
        bool status [99];
    public:
    HashMat();
    int hashFunction(string matricula);
    bool findMatricula (string matricula);
    void addMatricula (string matricula); 
    void deleteMatricula(string matricula)
};

int HashMat::hashFunction(string matricula){
  try {
    int numMatricula = stoi(matricula.substr(1,8));
    return numMatricula % 99;
    }catch(invalid_argument &e){
        cout << e.what() << endl;
        return -1;
    }
}

bool HashMat::findMatricula(string matricula){
    int index = hashFunction(matricula);
    int baseIndex = index;
    if (index >= 0){
        while(hashTable[index] != "" || status[index]){
            if(hashTable[index] == matricula){
                return true;
            } else {
                index = (index + 1) % 99;
                if (index == baseIndex){
                    return false;
                }
            }
        }
        return false;
    } else {
        return false;
    }
}

void HashMat::addMatricula(string matricula){
    int index = hashFunction(matricula);
    int baseIndex = index;

    if (index >= 0){
        while(hashTable[index] != ""){
            index = (index + 1) % 99;
            if (index == baseIndex){
                throw std::invalid_argument("la tabla esta llena");
                return;
            }
        }
        hashTable[index] = matricula;
        status[index] = false;
    }
}

void HashMat::deleteMatricula(string matricula){
    int index = hashFunction(matricula);
    int baseIndex = index;
    if (index >= 0){
        while(hashTable[index] != "" || status[index]){
            if(hashTable[index] == matricula){
                hashTable[index] = "";
                status[index] = true;
            } else {
                index = (index + 1) % 99;
                if (index == baseIndex){
                throw std::invalid_argument("la matricula no se encuentra");
                return;
                }
            }
        }
        throw std::invalid_argument("la matricula no se encuentra");
        
    } else {
        throw std::invalid_argument("la matricula no es una matricula");
    }
}

#endif