#include <iostream>
#include <vector>
#include <sstream>

long long int calc_factorial(int n) {
    long long int factorial = 1;
    while (n) {
        factorial *= n;
        n -= 1;
    }
    return factorial;
}

void print_vector(const std::vector<int>& vec) {
    for (const auto& n: vec) {
        std::cout << n;
    }
    std::cout << std::endl;
}

std::vector<int> number_to_vector(int n) {
    std::vector<int> vec;
    while (n > 0) {
        vec.push_back(n % 10);
        n /= 10;
    }
    std::reverse(vec.begin(), vec.end());
    return vec;
}

void multiply_vectors(int a, int b) {
    std::vector<int> vec_a = number_to_vector(a);
    std::vector<int> vec_b = number_to_vector(b);
    print_vector(vec_a);
    print_vector(vec_b);


    std::vector<int> final_res;
    for (int i = vec_b.size() - 1; i >= 0; --i) { // иду по нижнему числу с конца
        auto multyplier = vec_b[i];
        int r = 0;
        std::vector<int> res;
        for (int j = vec_a.size() - 1; j >= 0; --j) { // умножаю верхнее число на vec_b[i]
            auto n = vec_a[j] * multyplier;
            n += r;
            r = 0;
            if (n >= 10) {
                r += n / 10;
                n %= 10;
            }
            res.push_back(n);
        }
        if (r != 0)
            res.push_back(r);
        std::reverse(res.begin(), res.end());
//        print_vector(res);

        if (i != vec_b.size() - 1) {
            // final_res += res
            int delta = vec_b.size() - 1 - i;
            for (int k = 0; k < delta; ++k)
                res.push_back(0);
            while (final_res.size() < res.size()) {
                final_res.insert(final_res.begin(), 0);
            }

            std::vector<int> new_res;
            int r = 0;
            for (int j = final_res.size() - 1; j >= 0; --j) {
                int n = final_res[j] + res[j];
                n += r;
                r = 0;
                if (n >= 10) {
                    r += n / 10;
                    n %= 10;
                }
                new_res.push_back(n);
            }
            print_vector(new_res);
        }
        else{
            final_res = res;
        }
    }

}

int main() {
    multiply_vectors(321, 65);
    return 0;
}
