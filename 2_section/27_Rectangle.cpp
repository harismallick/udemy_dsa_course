#include <iostream>
using namespace std;

class Rectangle {
    private:
        int length;
        int breadth;
    public:
        Rectangle(int l, int b) {
            this->length = l;
            this->breadth = b;
        }
        int area() {
            return length * breadth;
        }
        int perimeter() {
            return 2 * (length + breadth);
        }
        void getDimensions();
};

// Defining the function outside the class in cpp:
void Rectangle::getDimensions() {
    cout << "The length is " << length << " and the breadth is " << breadth << endl;
}

int main() {
    Rectangle r(10, 5);
    cout << "Area: " << r.area() << endl;
    cout << "Perimeter: " << r.perimeter() << endl;
    r.getDimensions();
    return 0;
}