#include <iostream>
#include "Date.h"

int main() {
    try {
        Date date1;
        Date date2(100); 

        std::cout << "output\n";
        date1.print();
        std::cout << std::endl;

        date2.print();
        std::cout << std::endl;

        std::cout << "assignment\n";
        date1 = date2;
        date1.print();
        std::cout << std::endl;

        std::cout << "arithmetic\n";
        Date date4 = date1 + 900;
        date4.print();
        std::cout << std::endl;

        Date date5 = date4 - 500;
        date5.print();
        std::cout << std::endl;
      
        std::cout << "accumulation\n";
        date5 += 700;
        date5.print();
        std::cout << std::endl;

        date5 -= 200;
        date5.print();
        std::cout << std::endl;

        std::cout << "unary\n";
        ++date5;
        date5.print();
        std::cout << std::endl;

        date5++;
        date5.print();
        std::cout << std::endl;

        --date5;
        date5.print();
        std::cout << std::endl;

        date5--;
        date5.print();
        std::cout << std::endl;

        std::cout << "logical\n";
        
        if (date5 == date4) {
            std::cout << "date5 is equal to date4" << std::endl;
        }
        else {
            if (date5 < date4) {
                std::cout << "date5 is less than date4" << std::endl;
            }

            if (date5 > date4) {
                std::cout << "date5 is more than date4" << std::endl;
            }
        }

        std::cout << "conversion\n";
        int days = static_cast<int>(date5);
        std::cout << "days since 01.01.1970: " << days << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "exception: " << e.what() << std::endl;
    }

    return 0;
}
