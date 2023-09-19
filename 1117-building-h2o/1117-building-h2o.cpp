using namespace std;
class H2O {
public:
    mutex m;
    condition_variable cv;
    int turn=0;
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex>lock (m);
        while(turn==2)
            cv.wait(lock);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        turn++;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        unique_lock<mutex>lock (m);
        while(turn<2)
            cv.wait(lock);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        //releaseHydrogen();
        turn++;
       
        releaseOxygen();
        turn=0;
         cv.notify_all();
    }
};