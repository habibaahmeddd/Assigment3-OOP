//File name:A3_SheetPb3_20220199.cpp
//Purpose: Solving problem 3 (Search Engine)
//Author: Abdallah Ahmed Elsayed
//ID: 20220199
//Section: S21
//Date: 4 - 12 -2023

#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

map<string, int> freq;

class SearchEngine {
private:
    string final;
//    vector<string> searchedWords;
public:
    SearchEngine();

    SearchEngine(string t) {
        string x = "";
        for (int i = 0; i < t.length(); ++i) {
            if ((int(tolower(t[i])) >= 97 && int(tolower(t[i])) <= 122) || t[i] == '-') {
                x += (tolower(t[i]));
            }
        }
        int y = 1;
        if (freq.count(x) == 1) {
            freq[x]++;
        } else {
            freq.insert({x, y});
        }
    }
    ~SearchEngine(){
    }
};

int main() {
    string s;
    ifstream MyReadFile("../test.txt");
    while (getline(MyReadFile, s)) {
        SearchEngine b(s);
    }
        cout<<"Words     :      Times of appearance"<<endl;
        for (auto i: freq) {
            cout << i.first <<"                 " << i.second << endl;
        }

//cout<<int('-');
}
