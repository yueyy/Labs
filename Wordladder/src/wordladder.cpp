
#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "lexicon.h"
#include "vector.h"
#include "queue.h"
#include "stack.h"

using namespace std;

void Input(string &start,string &end);
Vector<string> Show(string start,string end,Lexicon lex);
//int Search(string &word,vector<string> &dic);

int main() {
    string start,end;
    string file;
    cout << "Please give me two English words, and I will change the first into the second by changing one letter at a time."
         << endl;
    cout << "Dictionary file name?";
    cin >> file;
    try{
        Lexicon lex(file);
    }catch (ErrorException &ex){
        cout << "Unable to open that file." << "Try again." << endl;
        cout << "Dictionary file name?";
        cin >> file;
    }
    Lexicon lex(file);
    Input(start,end);
    if(start==end){
        cout << "The two words must be different." << endl;
        Input(start,end);
    }else if(start.length()!=end.length()){
        cout << "The two words must be the same length." << endl;
        Input(start,end);
    }else if(!lex.contains(start)&&!lex.contains(end)){
        cout << "not fount" << endl;
        Input(start,end);
    }else {
        cout << "A ladder from data back to code:" << endl;
        cout << "Word ladder: " << endl;

        Vector<string> wordLadder;
        wordLadder = Show(start,end,lex);
        if(!wordLadder.isEmpty()){
            for(auto word : wordLadder){
                cout << word << " " << endl;
            }
        }else{
            cout << "not found" << endl;
        }

    }
    cout << "Have a nice day." << endl;
    return 0;
}

void Input(string &start,string &end){
    cout << "Word #1 (or Enter to quit):" << endl;
    cin >> start;
    cout << "Word #2 (or Enter to quit):" << endl;
    cin >> end;
}

Vector<string> Show(string start,string end,Lexicon lex){
    Lexicon prevWords;
    Lexicon sameLength;
    prevWords.add(start);
    Vector<string> left(1,start);
    Queue<Vector<string>> queue;
    queue.enqueue(left);
// 与start同长度的单词
    for (auto s : lex) {
        if(s.length() == start.length()){
            sameLength.add(s);
        }
    }

    while(!queue.isEmpty()){
        Vector<string> current = queue.dequeue();
        string last = current[current.size()-1];

        if (last == end){
            return current;
        }else{

            int flag = 0;
            while(flag<start.length()){
                for(char c = 'a';c<='z';c++){
                    string current_word = last;
                    current_word[flag] = c;

                    if(sameLength.contains(current_word) && !prevWords.contains(last)){
                        Vector<string> n = current;
                        n += current_word;
                        queue.enqueue(n);
                        prevWords.add(current_word);
                        return current;
                    }
                }
            }
            flag++;
        }

    }
    Vector<string> notfound(1,"please try again");
    return notfound;
}

// 二分法
//int Search(string &word,vector<string> &dic){
//    int left = 0;
//    int right = dic.size()-1;

//    while (left < right){
//        int middle = (left + right )/2;
//        if (word < dic[middle]){
//            right = middle - 1;
//        }else if (word > dic[middle]){
//            left = middle + 1;
//        }else{
//            return middle;
//        }
//    }
//    return -1;
//}