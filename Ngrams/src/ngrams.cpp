// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "queue.h"
#include "console.h"
#include "map.h"
#include "vector.h"
#include "tokenscanner.h"

using namespace std;

Queue<string> pickStart(Map<Queue<string>,Vector<string>>& map){
    Queue<string> resule;
    Vector<Queue<string>> keys = map.keys();
    int size = keys.size();
    int i = randomInteger(0,size-1);
    return keys[i];
}

string Delivery(Vector<string> &currentVector){
    int i = randomInteger(0,currentVector.size()-1);
    return currentVector[i];
}


void Write(int length,Map<Queue<string>,Vector<string>> & map){
    Queue<string> current = pickStart(map);
    cout << "...";
    int i = 0;
    while(i<length){
        Vector<string> currentVector = map.get(current);
        string next = Delivery(currentVector);
        cout << next << " ";
        current.dequeue();
        current.enqueue(next);
        i++;
    }
    cout << "..." << endl;
}

void BuildMap(int n,ifstream &infile,Map<Queue<string>,Vector<string>> &map){
    TokenScanner scanner(infile);
    scanner.ignoreWhitespace();
    Queue<string> window;
    Vector<string> temp;
    int flag = 1;
    while(scanner.hasMoreTokens()){
        string token = scanner.nextToken();
        temp.add(token);
        if(flag < n){
            window.enqueue(token);
            flag++;
            continue;
        }
        if(map.containsKey(window)){
            Vector<string> suffixes;
            suffixes.add(token);
            map.put(window,suffixes);
        }else{
            Vector<string> pref = map.get(window);
            pref.add(token);
            map[window] = pref;
        }
        string temp = window.dequeue();
        window.enqueue(token);
    }
}

int main() {
    Map<Queue<string>,Vector<string>> map;
    ifstream infile;
    string file_name;
    int value,length;
    cout << "This program makes random text based on a document.\n"
         << "Give me an input file and an 'N' value for groups of words, and I'll create random text for you.\n"
         << "input file name?" << endl;
    cin >> file_name;
    infile.open(file_name);

    cout << "Value of N?" << endl;
    cin >> value;
    cout << "# of random words to generate (0 to quit)?" << endl;
    cin >> length;

    BuildMap(value,infile,map);
    Write(length,map);

    cout << "Exiting." << endl;
    return 0;
}

