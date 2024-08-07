#include<iostream>
#include<vector>
#include<list>
using namespace std;

class HashMap{
private:
    int tableSize = 10;
    vector<list<pair<int,int>>> hm;
    
    int hashFunction(int key){
        int index = key%tableSize;
        return index;
    }

public:
    HashMap(){
        hm.resize(tableSize);
    }

    int get(int key){
        int index = hashFunction(key);
        for(const auto& pair : hm[index] ){
            if(pair.first == key){
                return pair.second;
            }
        }
        return -1;
    }

    bool contains(int key){
        int index = hashFunction(key);
        for(const auto& pair : hm[index]){
            if(pair.first == key){
                return true;
            }
        }
        return false;
    }

    bool insert(int key,int value){
        int index = hashFunction(key);
        for(auto& pair: hm[index]){
            if(pair.first == key){
                pair.second = value;
                return;
            }
        }
        hm[index].push_back({key,value});
    }

    void remove(int key){
        int index = hashFunction(key);
        auto& pairs = hm[index];
        for(auto it = pairs.begin();it!= pairs.end();it++){
            if(it->first == key){
                pairs.erase(it);
                return;
            }
        }
    }
};

int main()
{
    
    return 0;
}