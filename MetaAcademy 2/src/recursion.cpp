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
        throw
    }
    cout << "[recursion serpinskii called]" << endl;
}

int floodFill(GBufferedImage& image, int x, int y, int newColor) {
    // your code here
    cout << "[recursion flood fill called]" << endl;
    return 0;
}

void personalCurriculum(Map<string, Vector<string>> & prereqMap,string goal) {
    // your code here
    cout << "[recursion personal curriculum called]" << endl;
}

string generate(Map<string, Vector<string> > & grammar, string symbol) {
    // your code here
    cout << "[recursion generate called]" << endl;
    return "";
}
