/* 
 * TODO: put your own comments here. Also you should leave comments on
 * each of your methods.
 */

#include <math.h>
#include "recursion.h"
#include "map.h"
#include "vector.h"
#include "set.h"
#include "gwindow.h"
#include "gobjects.h"
#include "tokenscanner.h"
using namespace std;

int gcd(int a, int b) {
    cout << "gcd(" << a << ", " << b << ") = " ;
    if(b == 0){
        cout << a << endl;
    }else{
        int c = a;
        a = b;
        b = c % b;
        cout << "gcd(" << a << ", " << b << ")" << endl;
        gcd(a,b);
    }
    cout << "[recursion gcd called]" << endl;
    return 0;
}

void serpinskii(GWindow &w, int leftX, int leftY, int size, int order) {
    if(order < 0){
        throw ("error");
        return;
    }else if(order == 1){
        w.drawLine(leftX, leftY, leftX+size, leftY );
        w.drawLine(leftX+size, leftY, leftX+size/2, leftY+size*(sqrt(3)/2));
        w.drawLine(leftX+size/2, leftY+size*(sqrt(3)/2), leftX, leftY);
    }else {
        w.drawLine(leftX+size/2, leftY, leftX+size/4, leftY+size*(sqrt(3)/4));
        w.drawLine(leftX+size/2, leftY, leftX+(size/4*3), leftY+size*(sqrt(3)/4));
        w.drawLine(leftX+size/4, leftY+size*(sqrt(3)/4), leftX+size/4*3, leftY+size*(sqrt(3)/4));
        serpinskii(w, leftX, leftY, size/2, order-1);
        serpinskii(w, leftX+size/2, leftY, size/2, order-1);
        serpinskii(w, leftX+size/4, leftY+size*(sqrt(3)/4), size/2, order-1);
    }
    cout << "[recursion serpinskii called]" << endl;
}

int changeColor(GBufferedImage & image, int x, int y, int newColor, int oldColor, int count){
    count += 1;
    if(image.inBounds(x,y) && image.getRGB(x, y) == oldColor){
        image.setRGB(x, y, newColor);
        count = changeColor(image, x+1, y, newColor, oldColor, count);
        count = changeColor(image, x, y+1, newColor, oldColor, count);
        count = changeColor(image, x-1, y, newColor, oldColor, count);
        count = changeColor(image, x, y-1 ,newColor, oldColor, count);
    }
    return count;
}

int floodFill(GBufferedImage& image, int x, int y, int newColor) {
    int oldColor = image.getRGB(x,y);
    if(newColor == oldColor){
        return 0;
    }else{
        int pixels;
        pixels = changeColor(image, x, y, newColor, oldColor, pixels);
        return pixels;
    }
    cout << "[recursion flood fill called]" << endl;
}

void search(Map<string, Vector<string>> & prereqMap,string goal, Set<string> &pref){
    Vector<string> current = prereqMap.get(goal);
    for(string s:current){
        if(!pref.contains(s)){
            pref.add(s);
        }
        if(!prereqMap.get(s).isEmpty()){
            search(prereqMap, s, pref);
        }
    }
}
void personalCurriculum(Map<string, Vector<string>> & prereqMap,string goal) {
    Set<string> pref;
    search(prereqMap, goal, pref);
    for(string s:pref){
        cout << s << endl;
    }
    cout << goal << endl;
    cout << "[recursion personal curriculum called]" << endl;
}

int mystery(int level, int x){
    if(level == 0){
        return 5;
    }else {
        int r = mystery(level - 1, r);
        return r%x + 1;
    }
}

string generate(Map<string, Vector<string> > & grammar, string symbol) {
    string expand,s;
    Vector<string> vec;
    if(grammar.containsKey(symbol)){
        vec = grammar[symbol];
        s = vec[randomInteger(0, vec.size()-1)];
        TokenScanner scanner(s);
        while(scanner.hasMoreTokens()){
            string token = scanner.nextToken();
            expand += generate(grammar, token);
        }
    }else{
        expand += symbol;
    }
    return expand;
    cout << "[recursion generate called]" << endl;
}

