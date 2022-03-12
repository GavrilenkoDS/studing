#include <iostream>
#include <fstream>
#include <cstdlib>
#include <filesystem>
#include <string>
#include <limits>

using namespace std;

//1
class div_zero {};

double _div(int a, int b) {
    if (b == 0)
        throw div_zero();
    return (double)a / b;
}

int main_1() {
    int a, b;
    cin >> a >> b;
    int c;
    try {
        c = _div(a, b);
    }
    catch (div_zero) {
        return EXIT_FAILURE;
    }
    
    cout << c ;

    return EXIT_SUCCESS;
}
//2
class file_not_found {};
class overwr {};

void fcopy(const char* from_path, const char* to_path) {
    ifstream check;

    check.open(from_path);
    if (!check)
        throw file_not_found();

    check.close();
    check.open(to_path);
    if (check)
        throw overwr();
    check.close();

    ifstream from(from_path, ios::binary);
    ofstream to(to_path, ios::binary);

    to << from.rdbuf();

    to.close();
    from.close();
}

int main_2() {
    string from, to;
    while (true) {
        cin >> from;
        cin >> to;
        try {
            fcopy(from.c_str(), to.c_str());
            break;
        }
        catch (file_not_found) {
            cout <<  from ;
        }
        catch (overwr) {
            cout << to ;
        }
    }
    return EXIT_SUCCESS;
}
//3
class memory {};
class range {};

class vector {
private:
    double* arr;
    int length = 0;
public:
    vector() {
        arr = nullptr;
        length = 0;
    }

    vector(int n) {
        try {
            arr = new double [n];
            length = n;
        }
        catch (bad_alloc) {
            throw memory();
        }
    }
    vector(vector& v) {
        arr = v.arr;
        length = v.length;
    }
    vector& operator=(const vector& v) {
        arr = v.arr;
        length = v.length;
        return *this;
    }
    double& operator[](int n) {
        if (n >= length || n < 0)
            throw range();
        return arr[n];
    }
};

int main_3() {
    int n;
    vector v;

    while (true) {
        cin >> n;
        try {
            v = vector(n);
            break;
        }
        catch (memory)  
    }

    while (true) {
        int n;
        cin >> n;

        try {
            v[n];
            cout << "v[" << n << "] = " << v[n] << "\n";
            break;
        }
        catch (range) 
    }

    return EXIT_SUCCESS;
}
//4
class Ex {
private:
    double x;

public:
    Ex(double a) {
        x = a;
    }  
};

class Bar {
private:
    double y;

public:
    Bar() {
        y = 0;
    }

    void set(double a) {
        if (y + a > 100)
            throw Ex(a*y);
        else
            y = a;
    }
};

int main_4() {
    int n;
    Bar x;

    while (n != 0) {
        try {
            cin >> n;
            if (n == 0)
                break;

            x.set(n);            
        }
        catch (Ex& e) {
            cout << e.x ;
        }
    }

    return EXIT_SUCCESS;
}
//5
class field_ex {
private:
    int o_p[2];
    int n_p[2];

public:
    field_ex(int o_p[2], int n_p[2]) {
        this->o_p[0] = o_p[0];
        this->o_p[1] = o_p[1];
        this->n_p[0] = n_p[0];
        this->n_p[1] = n_p[1];
    }

    string message() {
        return (to_string(o_p[0]) + " " + to_string(o_p[1])  + " " + to_string(n_p[0]) + " " + to_string(n_p[1]) );
    }
};

class ime {
private:
    int o_p[2];
    int n_p[2];

public:
    ime(int o_p[2], int n_p[2]) {
        this->o_p[0] = o_p[0];
        this->o_p[1] = o_p[1];
        this->n_p[0] = n_p[0];
        this->n_p[1] = n_p[1];
    }
    string message() {
        return ( + to_string(o_p[0]) + " " + to_string(o_p[1]) + " " + to_string(n_p[0]) + " " + to_string(n_p[1]) );
    }
};

class robot {
private:
    int pos[2];

public:
    robot() {
        pos[0] = 0;
        pos[1] = 0;
    }

    robot(int x, int y) {
        pos[0] = x;
        pos[1] = y;
    }

    void move(int n_p[2]) {
        if (abs(pos[0] - n_p[0]) + abs(pos[1] - n_p[1]) != 1)
            throw ime(pos, n_p);

        if ((min(n_p[0], n_p[1]) < 0) || (max(n_p[0], n_p[1]) > 9))
            throw field_ex(pos, n_p);

        pos[0] = n_p[0];
        pos[1] = n_p[1];
    }
};

int main_5() {
    robot r;
    int n_p[2];


    while (true) {
        cin >> n_p[0] >> n_p[1];
        if (n_p[0] == -1 && n_p[1] == -1)
            break;

        try {
            r.move(n_p);
        }
        catch (ime& e) {
            cout << e.message() ;
        }
        catch (field_ex& e) {
            cout << e.message() ;
        }
    }

    return EXIT_SUCCESS;
}
//6
class long_ex {};
class out_of_string {};
class a_many_ex {};

class arr_str {
private:
    char a[50];
    int length;
    int a_count;

public:
    arr_str() {
        a[0] = '\0';
        a_count = 0;
    }

    void write(const char* str) {
        if (strlen(str) > 50)
            throw long_ex();

        length = strlen(str);

        for (int i = 0; i < strlen(str); i++) {
            a[i] = str[i];
            if (str[i] == 'a')
                a_count++;
        }
    }

    void modify(int index, char symb) {
        if (index >= length)
            throw out_of_string();

        if (symb == 'a' && a_count+1 > 10)
            throw a_many_ex();

        a[index] = symb;
        if (symb == 'a')
            a_count++;   
    }
};

int main_6() {
    arr_str a;
    int command;

    while (true) {
        cin >> command;

        if (command == 0)
            break;

        if (command == 1) {
            string str;
            while (true) {
                cin >> str;

                try {
                    a.write(str.c_str());
                    break;
                }
                catch (long_ex) {
                }
            }
        }

        if (command == 2) {
            char c;
            int index;
            while (true) {
                cin >> index >> c;

                try {
                    a.modify(index, c);
                    break;
                }
                catch (out_of_string) {
                }
                catch (a_many_ex) {
                    return EXIT_FAILURE;
                }
            }
        }
    }

    return EXIT_SUCCESS;
}


