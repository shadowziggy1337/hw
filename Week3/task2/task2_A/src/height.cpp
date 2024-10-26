#include "height.hpp"
#include <iostream>

void pyramidheight (int height) {
	for  (int a = 1; a <= height; ++a){
                for (int b = 0; b < height - a; ++b) {
                        std::cout << " ";
                }
                for (int c = 0; c < a; ++c) {
                        std::cout << "#";
                }
                std::cout << "  ";
                for (int c = 0; c < a; ++c) {
                        std::cout << "#";
                }
                std::cout << std::endl;
        }
}
