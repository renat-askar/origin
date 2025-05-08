#include <thread>
#include <chrono>
#include <iostream>

using namespace std::chrono_literals;

static int client_count{};

void client(size_t max_client_count)
{
    while(max_client_count)
    {
        ++client_count;
        --max_client_count;
        std::cout << "New client. Client count: " << client_count << '\n';
        std::this_thread::sleep_for(1s);
    }
}

void teller()
{
    while(client_count)
    {
        --client_count;
        std::cout << "Teller decrease counts of clients. Client count: " << client_count << '\n';
        std::this_thread::sleep_for(2s);
    }
}

int main()
{
    std::thread client{::client, 10};
    std::thread teller{::teller};

    client.join();
    teller.join();

    return 0;
}
