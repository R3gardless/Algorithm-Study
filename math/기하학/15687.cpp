// 15687번 = 직사각형

#include <iostream>

using namespace std;

class Rectangle {
    private: 
        int width;
        int height;
    public:
        Rectangle(int width, int height) {
            this->height = height;
            this->width = width;
        }
        int get_width() const {
            return width;
        }
        int get_height() const {
            return height;
        }
        void set_width(int width) {
            if(width <= 0 || width > 1000) return;
            else this->width = width;
        }
        void set_height(int height) {
            if(height <= 0 || height > 2000) return;
            else this->height = height;
        }
        int area() const{
            return height * width;
        }
        int perimeter() const{
            return 2 * (height + width);
        }
        bool is_square() const {
            if(height == width) return true;
            else return false;
        }
};

int main() {

    ios::sync_with_stdio(false); cin.tie(NULL);

    Rectangle rect(3,3);
    cout << rect.is_square() << '\n';

    return 0;

}