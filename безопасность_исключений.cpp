#include <iostream>
#include <cstdlib>
#include <memory>
#include <exception>
using namespace std;

//1
class first {
private:
    static unsigned int next_unique;

public:
    unsigned int n;

    first() {
        n = next_unique;
        next_unique++;
    }
    ~first() 
};

unsigned int first::next_unique = 0;

int main_1() {
    try {
        first a[5];
        throw;
        first* b = new first[5];
    }
    catch (exception& e) {
        cout << e.what();
    }

    return EXIT_SUCCESS;
}
//2
class second {
private:
    static unsigned int next_unique;

public:
    unsigned int n;

    second() {
        n = next_unique;
        cout << "Created: " << n << "\n";
        next_unique++;
    }

    ~second() {
        cout << "Removed: " << n << "\n";
    }
};

unsigned int second::next_unique = 0;

int main_2() {
    try {
        second a[5];
        throw;
        second* b = new second[5];
    }
    catch (exception& e) {
        cout << e.what() ;
    }

    return EXIT_SUCCESS;
}
//3 
class third {
private:
    static unsigned int next_unique;

public:
    unsigned int n;

    third() {
        n = next_unique;
        next_unique++;
    }

    ~third() 
};
unsigned int third::next_unique = 0;

int main_3() {
    try {
        third a[5];
        throw;
        unique_ptr<third> b(new third[5]);
    }
    catch (exception& e) {
        cout << e.what() << "\n";
    }

    return EXIT_SUCCESS;
}
//4
class SeventhObjectException {};

class fourth {
private:
    static unsigned int next_unique;

public:
    unsigned int n;

    fourth() {
        if (next_unique == 6)
            throw SeventhObjectException();
        n = next_unique;
        next_unique++;
    }

    ~fourth() 
};
unsigned int fourth::next_unique = 0;

int main_4() {
    try {
        fourth a[10];
    }
    catch (SeventhObjectException) 
    

    return EXIT_SUCCESS;
}

//5
class fifth {
private:
    static unsigned int next_unique;

public:
    unsigned int n;

    fifth() {
        if (next_unique == 6)
            throw SeventhObjectException();
        n = next_unique;
        next_unique++;
    }

    ~fifth() 
};
unsigned int fifth::next_unique = 0;

class Bar {
private:
    fifth* arr;

public:
    Bar() {
        arr = new fifth[10];
    }

    ~Bar() {
        delete[] arr;
    }
};

int main_5() {
    try {
        Bar a;
    }
    catch (SeventhObjectException) {
    }

    return EXIT_SUCCESS;
}

//6
class sixth {
private:
    static unsigned int next_unique;

public:
    unsigned int n;

    sixth() {
        if (next_unique == 6)
            throw SeventhObjectException();
        n = next_unique;
        next_unique++;
    }

    ~sixth() 
};
unsigned int sixth::next_unique = 0;

class Bar {
private:
    unique_ptr<sixth[]> arr;

public:
    Bar() {
        arr = unique_ptr<sixth[]>(new sixth[10]);
    }

    ~Bar() {
        arr.reset();
    }
};

int main_6() {
    try {
        Bar a;
    }
    catch (SeventhObjectException) 

    return EXIT_SUCCESS;
}

//7
class SeventhObjecAssignmentException {};

class seventh {
private:
    static unsigned int next_unique;

public:
    unsigned int n;

    seventh() {
        n = next_unique;
        next_unique++;
    }

    ~seventh() 

    seventh& operator=(const seventh& a) {
        if (a.n == 6) {
            throw SeventhObjecAssignmentException();
        }
        n = a.n;

        return *this;
    }
};
unsigned int seventh::next_unique = 0;

template <class T>
class vector {
private:
    unique_ptr<T[]> arr;
    unsigned int length;

public:
    vector(unsigned int size) { 
        arr = unique_ptr<T[]>(new T[size]);
        length = size;
    }

    ~vector() {
        arr.reset();
    }

    vector& operator=(const vector& v) {
        try {
            for (int i = 0; i < length; i++) {
                arr[i] = v.arr[i];
            }
        }
        catch (SeventhObjecAssignmentException) 

        return *this;
    }
};

int main_7() {
    vector<seventh> a(5);
    vector<seventh> b(5);
    a = b;
    return EXIT_SUCCESS;
}



