#include <iostream>
using namespace std;

#include "Imagine.h"

using namespace std;

int main(){
Imagine a,b,c,d,e,f;
a.setNum(23.2,7.0);
a.getNum();

b.setNum(34.0,0.0);
c = a + b;
d = a - b;
e = a * b;
f = !a;
b.getNum();
c.getNum();
d.getNum();
e.getNum();
f.getNum();
}
