#include <iostream>
#include <thread>
#include <mutex>

class thread_object
{
public:
    void operator()(int &x, std::mutex &mtx)
    {
        for (int i = 0; i < 10000; ++i)
        {
            std::lock_guard<std::mutex> lock(mtx);
            x++;
        }
    }
};

int main()
{
    int x = 0;
    std::mutex mtx;
    thread_object obj;
    std::thread t1(std::ref(obj), std::ref(x), std::ref(mtx));
    std::thread t2(std::ref(obj), std::ref(x), std::ref(mtx));
    t1.join();
    t2.join();
    std::cout << "Final x: " << x << "\n";
}