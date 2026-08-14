#include <cassert>
class DynamicArray {
public:

    DynamicArray(int capacity) {
        assert(capacity > 0);
        cap = capacity;
        arr = new int[cap];
    }

    int get(int i) {
        if(i < count)
        {
            return arr[i];
        }
        return -1;
    }

    void set(int i, int n) {
        arr[i] = n;

    }

    void pushback(int n) {
        if(count == cap)
        {
            resize();
        }
        arr[count] = n;
        count = count + 1;

    }

    int popback() {
        if(count > 0)
        {
            int ele = arr[count-1];
            count = count - 1;
            return ele;
        }
        return -1;
    }

    void resize() {
        cap = cap*2;
        int *new_arr = new int[cap];
        for(int i = 0; i<count; i++)
        {
            new_arr[i] = arr[i];
        }
        delete [] arr;
        arr = new_arr;

    }

    int getSize() {
        return count;

    }

    int getCapacity() {
        return cap;

    }
private:
    int cap = 0;
    int count = 0;
    int *arr = nullptr;
};
