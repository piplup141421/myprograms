#include <iostream>
using namespace std;

/* implement */
class Rectangle{
    public:
        void setLength(int l){
            length=l;
        }
        void setWidth(int w){
            width=w;
        }
        int perimeter(){
            return width+width+length+length;
        }
        int area(){
            return width*length;
        }
    private:
        int width;
        int length;
};


int main(){
	Rectangle rect;
	int l, w;
	cin >> l >> w;
	rect.setLength(l);
	rect.setWidth(w);
	cout << "Perimeter: " << rect.perimeter() << endl;
	cout << "Area: " << rect.area() << endl;
	return 0;
}