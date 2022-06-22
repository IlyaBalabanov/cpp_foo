#ifndef UNTITLED1_FUNC_H
#define UNTITLED1_FUNC_H

#include <istream>

// указатели
bool contates(int*, int , int );

bool contates2(int*, int* , int );

int max_element(int*, int*);

// указатели задачи

unsigned strlen_v(const char *);

int strstr1(const char*, const char*);

void sum_u(int ,int ,int *,int *);

// ссылки

void swap(int&, int&);

void sum_s(int ,int , int &, int &);

//динамическая память

int din(int );

char *resize(const char *, unsigned, unsigned);

char *getline();

// Многомерные массивы

int **create_array_2d(size_t, size_t);

void free_array_2d(int **, size_t );

int ** transpose(const int * const * , unsigned , unsigned );

void swap_min(int *[], unsigned , unsigned );


// структуры


struct point{
    double x;
    double y;
    void shift(double x, double y );
    point() : x(0),y(0)
    {}
    point(double x, double y): x(x),y(y)
    {}
};

struct Segment {
    point p1;
    point p2;
    Segment() {};
   explicit Segment(double length): p2(length,0)
    {};

};

double LenS(Segment );


struct String {
    size_t size;
    char *str;
    /* Реализуйте этот конструктор */
    explicit String(const char *str = ""){
        this->size= strlen(str);
        this->str = new char [size+1];
        strcpy(this->str,str);


    };
    /* Реализуйте этот конструктор */
    String(size_t n, char c){
        char *p = new char[n];
        for(int i =0; i<n;i++){
            p[i]=c;
        }
        p[n+1]='\0';
        size = n+1;
        this->str=p;

    };

    /* и деструктор */
    ~String()
    {
        delete [] str;
    }
    void append(String &other){
        size_t double_size;
        double_size = size + other.size;
        char *new_string = new char [double_size];
        for (int i=0; i<size;i++)
        {
            new_string[i] = str[i];
        }
        for (int j =0; j<other.size;j++)
        {
            new_string[size+j]= other.str[j];
        }
        delete []str;
        str = new char [double_size+1];
        for(int so=0; so<double_size;so++)
            str[so]=new_string[so];
        str[double_size+1]='\0';
        size = double_size;
        delete [] new_string;
    }
};







#endif //UNTITLED1_FUNC_H
