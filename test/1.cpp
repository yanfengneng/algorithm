#include <iostream>
#include <thread>
 
void fun()
{
   std::cout << "A new thread!" << std::endl;
}
 
int main()
{
    std::thread t(fun);
    t.join();
    std::cout << "Main thread!" << std::endl;
}