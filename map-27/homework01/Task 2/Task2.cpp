#include <iostream>
#include <vector>
#include <thread>
#include <array>
#include <chrono>
#include <random>

void add(const std::vector<int>& vec, int begin, int end, int& sum)
{
    for(; begin < end; ++begin)
    {
        sum += vec.at(begin);
    }
}

double single_thread_sum(std::vector<int>& vec)
{
    auto start{std::chrono::system_clock::now()};
    int sum{};
    add(vec, 0, vec.size(), sum);
    auto end{std::chrono::system_clock::now()};
    std::chrono::duration<double, std::milli> time{(end - start) / 1000.};
    return time.count();
}

double dual_thread_sum(std::vector<int>& vec)
{
    auto start{std::chrono::system_clock::now()};
    int sum{};
    std::array<int, 2> sums{};
    std::thread t1(add, vec, 0, vec.size()/2, std::ref(sums[0]));
    std::thread t2(add, vec, vec.size()/2, vec.size(), std::ref(sums[1]));
    t1.join();
    t2.join();
    for(const int& num: sums)
        sum += num;
    auto end{std::chrono::system_clock::now()};
    std::chrono::duration<double, std::milli> time{(end - start) / 1000.};
    return time.count();
}

double quad_thread_sum(std::vector<int>& vec)
{
    auto start{std::chrono::system_clock::now()};
    int sum{};
    std::array<int, 4> sums{};
    std::thread t1(add, vec, 0, vec.size()/4, std::ref(sums[0]));
    std::thread t2(add, vec, vec.size()/4, vec.size()/2, std::ref(sums[1]));
    std::thread t3(add, vec, vec.size()/2, static_cast<int>(vec.size()/1.33), std::ref(sums[2]));
    std::thread t4(add, vec, static_cast<int>(vec.size()/1.33), vec.size(), std::ref(sums[3]));
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    for(const int& num: sums)
        sum += num;
    auto end{std::chrono::system_clock::now()};
    std::chrono::duration<double, std::milli> time{(end - start) / 1000.};
    return time.count();
}

double eight_thread_sum(std::vector<int>& vec)
{
    auto start{std::chrono::system_clock::now()};
    int sum{};
    std::array<int, 8> sums{};
    std::thread t1(add, vec, 0, vec.size()/8, std::ref(sums[0]));
    std::thread t2(add, vec, vec.size()/8, vec.size()/4, std::ref(sums[1]));
    std::thread t3(add, vec, vec.size()/4, static_cast<int>(vec.size()/2.66), std::ref(sums[2]));
    std::thread t4(add, vec, static_cast<int>(vec.size()/2.66), vec.size()/2, std::ref(sums[3]));
    std::thread t5(add, vec, vec.size()/2, static_cast<int>(vec.size()/1.6), std::ref(sums[4]));
    std::thread t6(add, vec, static_cast<int>(vec.size()/1.6), static_cast<int>(vec.size()/1.33), std::ref(sums[5]));
    std::thread t7(add, vec, static_cast<int>(vec.size()/1.33), static_cast<int>(vec.size()/1.14), std::ref(sums[6]));
    std::thread t8(add, vec, static_cast<int>(vec.size()/1.14), vec.size(), std::ref(sums[7]));
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
    for(const int& num: sums)
        sum += num;
    auto end{std::chrono::system_clock::now()};
    std::chrono::duration<double, std::milli> time{(end - start) / 1000.};
    return time.count();
}

double sixteen_thread_sum(std::vector<int>& vec)
{
    auto start{std::chrono::system_clock::now()};
    int sum{};
    std::array<int, 16> sums{};
    std::thread t1(add, vec, 0, vec.size()/16, std::ref(sums[0]));
    std::thread t2(add, vec, vec.size()/16, vec.size()/8, std::ref(sums[1]));
    std::thread t3(add, vec, vec.size()/8, static_cast<int>(vec.size()/5.33), std::ref(sums[2]));
    std::thread t4(add, vec, static_cast<int>(vec.size()/5.33), vec.size()/4, std::ref(sums[3]));
    std::thread t5(add, vec, vec.size()/4, static_cast<int>(vec.size()/3.2), std::ref(sums[4]));
    std::thread t6(add, vec, static_cast<int>(vec.size()/3.2), static_cast<int>(vec.size()/2.66), std::ref(sums[5]));
    std::thread t7(add, vec, static_cast<int>(vec.size()/2.66), static_cast<int>(vec.size()/2.28), std::ref(sums[6]));
    std::thread t8(add, vec, static_cast<int>(vec.size()/2.28), vec.size()/2, std::ref(sums[7]));
    std::thread t9(add, vec, vec.size()/2, static_cast<int>(vec.size()/1.77), std::ref(sums[8]));
    std::thread t10(add, vec, static_cast<int>(vec.size()/1.77), static_cast<int>(vec.size()/1.6), std::ref(sums[9]));
    std::thread t11(add, vec, static_cast<int>(vec.size()/1.6), static_cast<int>(vec.size()/1.45), std::ref(sums[10]));
    std::thread t12(add, vec, static_cast<int>(vec.size()/1.45), static_cast<int>(vec.size()/1.33), std::ref(sums[11]));
    std::thread t13(add, vec, static_cast<int>(vec.size()/1.33), static_cast<int>(vec.size()/1.23), std::ref(sums[12]));
    std::thread t14(add, vec, static_cast<int>(vec.size()/1.23), static_cast<int>(vec.size()/1.14), std::ref(sums[13]));
    std::thread t15(add, vec, static_cast<int>(vec.size()/1.14), static_cast<int>(vec.size()/1.06), std::ref(sums[14]));
    std::thread t16(add, vec, static_cast<int>(vec.size()/1.06), vec.size(), std::ref(sums[15]));
    t1.join(); t2.join();
    t3.join(); t4.join();
    t5.join(); t6.join();
    t7.join(); t8.join();
    t9.join(); t10.join();
    t11.join(); t12.join();
    t13.join(); t14.join();
    t15.join(); t16.join();
    for(const int& num: sums)
        sum += num;
    auto end{std::chrono::system_clock::now()};
    std::chrono::duration<double, std::milli> time{(end - start) / 1000.};
    return time.count();
}

int main()
{
    std::cout << "Количество аппаратных ядер - " << std::thread::hardware_concurrency() << '\n';

    std::vector<int> vec1_000(1'000);
    std::vector<int> vec10_000(10'000);
    std::vector<int> vec100_000(100'000);
    std::vector<int> vec1_000_000(1'000'000);

    std::mt19937 mt{};
    std::uniform_int_distribution<int> dis0to1_000{0, 1'000};
    std::uniform_int_distribution<int> dis0to10_000{0, 10'000};
    std::uniform_int_distribution<int> dis0to100_000{0, 100'000};
    std::uniform_int_distribution<int> dis0to1_000_000{0, 1'000'000};

    auto rand_num0to1_000([=]() mutable {return dis0to1_000(mt);});
    auto rand_num0to10_000([=]() mutable {return dis0to10_000(mt);});
    auto rand_num0to100_000([=]() mutable {return dis0to100_000(mt);});
    auto rand_num0to1_000_000([=]() mutable {return dis0to1_000_000(mt);});
    
    std::generate(std::begin(vec1_000), std::end(vec1_000), rand_num0to1_000);
    std::generate(std::begin(vec10_000), std::end(vec10_000), rand_num0to10_000);
    std::generate(std::begin(vec100_000), std::end(vec100_000), rand_num0to100_000);
    std::generate(std::begin(vec1_000_000), std::end(vec1_000_000), rand_num0to1_000_000);

    std::cout << "\t" << 1'000 << "\t\t\t" << 10'000 << "\t\t\t" << 100'000 << "\t\t\t" << 1'000'000 << '\n';
    std::cout << "1 потоков " 
        << single_thread_sum(vec1_000) << "s\t\t"
        << single_thread_sum(vec10_000) << "s\t\t"
        << single_thread_sum(vec100_000) << "s\t\t"
        << single_thread_sum(vec1_000_000) << "s\n2 потоков "
        << dual_thread_sum(vec1_000) << "s\t\t"
        << dual_thread_sum(vec10_000) << "s\t\t"
        << dual_thread_sum(vec100_000) << "s\t\t"
        << dual_thread_sum(vec1_000_000) << "s\n4 потоков "
        << quad_thread_sum(vec1_000) << "s\t\t"
        << quad_thread_sum(vec10_000) << "s\t\t"
        << quad_thread_sum(vec100_000) << "s\t\t"
        << quad_thread_sum(vec1_000_000) << "s\n8 потоков "
        << eight_thread_sum(vec1_000) << "s\t\t"
        << eight_thread_sum(vec10_000) << "s\t\t"
        << eight_thread_sum(vec100_000) << "s\t\t"
        << eight_thread_sum(vec1_000_000) << "s\n16 потоков "
        << sixteen_thread_sum(vec1_000) << "s\t\t"
        << sixteen_thread_sum(vec10_000) << "s\t\t"
        << sixteen_thread_sum(vec100_000) << "s\t\t"
        << sixteen_thread_sum(vec1_000_000) << "s\n";

    return 0;
}
