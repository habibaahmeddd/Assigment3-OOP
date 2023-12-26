// File name: A3_SheetPb4_20220102.cpp
// Purpose:solve problem 4
// Author(s):habiba ahmed yousef
// ID(s):20220102
// Section:s21
// Date:12/6/2023
#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
template <typename T>
class set {
private:
    vector<T>items;
    int  size;
public:
    set(int s=0):size(s){}


    void add(const T &item){
        if(!ifcontains(item)){
            items.push_back(item);
            size++;
        }

    }
    void remove(const T &item){
        auto it = find(items.begin(), items.end(),
                       item);

        if (it != items.end()) {
            items.erase(it);
            size--;
        }
    }
    int getsize()const{
        return size;
    }
    bool ifcontains(const T &item)const{
        auto it = find(items.begin(), items.end(), item);
        if (it != items.end()) {
            return true;

        }
        else{
            return false;
        }
    }
    T* toArray() const {
        T *result = new T[size];
        copy(items.begin(), items.end(), result);
        return result;
    }
};
int main() {
    set<int> intset;
    intset.add(1);
    intset.add(2);
    intset.add(3);
    cout << "Size of intSet: " << intset.getsize() << endl;
    intset.remove(2);
    cout << "Size of intSet after removing 2: " << intset.getsize() << endl;
    cout << "Is 3 in intSet? " << (intset.ifcontains(3) ? "Yes" : "No") << endl;
    int *intArray = intset.toArray();
    cout << "Items in intSet: ";
    for (size_t i = 0; i < intset.getsize(); ++i) {
        std::cout << intArray[i] << " ";
    }
    cout << endl;
    set<string> stringSet;
    stringSet.add("habiba");
    stringSet.add("aisha");
    stringSet.add("shahd");

    cout << "Size of Set: " << stringSet.getsize() <<endl;

    stringSet.remove("habiba");
    cout << "Size after removing 'habiba': " << stringSet.getsize() <<endl;

    if (stringSet.ifcontains("shahd")) {
        cout << "stringSet contains 'shahd'." << endl;
    }
    else{
        cout<<"stringset does not contain shahd";
    }

    string* stringArray = stringSet.toArray();
    cout << "Contents of stringSet: ";
    for (size_t i = 0; i < stringSet.getsize(); ++i) {
        cout << stringArray[i] << " ";
    }
    cout <<endl;


}