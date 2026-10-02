#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Image.hpp"	
#include "processing.hpp"
using namespace std;

static int how_to_use() {
    cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n" << "WIDTH and HEIGHT must be less than or equal to original" << endl;
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc != 4 and argc != 5)
        return how_to_use();

    string name = argv[1];

    ifstream fin(name);

    if (!fin.is_open()) {
        cout << "Error opening file: " << name << endl;
        return 1;
    }

    Image img;
    Image_init(&img, fin);

    int w = stoi(argv[3]);

    int h = Image_height(&img);
    if (argc == 5) {
        h = stoi(argv[4]);
    }
    
    if ( w <= 0 ) {
        return how_to_use();
    } else if ( w > Image_width(&img)) {
        return how_to_use();
    } else if ( h <= 0) {
        return how_to_use();
    } else if ( h > Image_height(&img)) {
        return how_to_use();
    }
       
    seam_carve(&img, w, h);

    string out = argv[2];
    ofstream fout(out);
    if (!fout.is_open()) {
        cout << "Error opening file: " << out << endl;
        return 1;
    }
    Image_print(&img, fout);
}