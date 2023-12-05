#include <iostream>
#include <thread>

void hello()
{
    std::cout<<"hello world\n";
}

int main()
{
    std::thread t(hello);
    t.join();
    return 0;
}