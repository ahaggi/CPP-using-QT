#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

//mutex mlock;
//int main() {
//    thread t1([]{
//        mlock.lock();
//        for(int i=0;i<N;++i) ++a;
//        mlock.unlock(); });

//    thread t2([]{
//        mlock.lock();
//        cout << a << '\n';
//        mlock.unlock(); });
//    t1.join();
//    t2.join();
//}



using namespace std;

struct Konto {
    explicit Konto(int num) : beloep{num} {}

    int beloep;
    std::mutex mlock; //OBS hver objk har sitt eget lock
};

void transfer(Konto &k1, Konto &k2, int num)
{
    // don't actually take the locks yet
    std::unique_lock<std::mutex> lock1(k1.mlock, std::defer_lock);
    std::unique_lock<std::mutex> lock2(k2.mlock, std::defer_lock);

    // lock both unique_locks without deadlock
    std::lock(lock1, lock2);

    k1.beloep -= num;
    k2.beloep += num;

    // 'from.m' and 'to.m' mutexes unlocked in 'unique_lock' dtors
}

int main()
{
    Konto k1(100);
    Konto k2(50);

    cout << "Konto 1 har beloep " << k1.beloep << "  Konto 2 har beloep " << k2.beloep << endl;

    std::thread t1(transfer, std::ref(k1), std::ref(k2), 10);
    std::thread t2(transfer, std::ref(k2), std::ref(k1), 5);

    t1.join();
    t2.join();

    cout << "Konto 1 har beloep " << k1.beloep << "  Konto 2 har beloep " << k2.beloep << endl;

}
