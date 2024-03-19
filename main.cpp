#include "IntegerArray.h"

int main() {
    try {
        IntegerArray arr(5);
        for (size_t i = 0; i < arr.getSize(); ++i) {
            arr[i] = static_cast<int>(i * 10);
        }

        arr.insertAt(2, 25); 
        arr.removeAt(4); 

        for (size_t i = 0; i < arr.getSize(); ++i) {
            std::cout << arr[i] << std::endl;
        }

        std::cout << arr[10] << std::endl;
    }
    catch (const bad_range& e) {
        std::cout << "Caught bad_range exception: " << e.what() << std::endl;
    }
    catch (const bad_length& e) {
        std::cout << "Caught bad_length exception: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Caught std::exception: " << e.what() << std::endl;
    }

    return 0;
}