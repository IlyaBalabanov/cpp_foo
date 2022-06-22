#include "func.h"
#include <iostream>
bool contates(int *m, int size, int value )
{
    for (int i=0;i!=size;i++)
    {
        if (m[i]==value)
            return true;
    }
    return false;
}

bool contates2(int *p, int *q, int value)
{
    for (; p!=q;++p)
        if (*p==value)
            return true;
        return false;
}

int max_element(int *p, int *q)
{
    int max= *p;
    for (;p!=q;++p)
        if (*p>max)
            max=*p;
  return max;
}

unsigned strlen_v(const char *str)
{
    unsigned int count=0;
    for (;  *str != '\0'; str++)
    {
        count+=1;
    }
    return count;
}

int strstr1(const char *text, const char *pattern)
{
    int pos=0;
    if (strlen_v(text)< strlen_v(pattern))
        return -1;
    if (*text=='\0') {
        if (*pattern=='\0')
            return 0;
        else
            return -1;
    } else {
        for (; *text != '\0'; text++, pos++) {
            if (*pattern == '\0')
                return 0;

            if (*text == *pattern) {
                while (*text == *pattern) {
                    text++;
                    pattern++;
                    if (*pattern == '\0' && *(pattern - 1) == *(text - 1))
                        return pos;
                    else
                        continue;
                }
            }
        }
        return -1;
    }
}

void swap(int &a, int &b )
{
    int tmp=a;
    a=b;
    b=tmp;
}

void sum_s(int a,int b, int &sum, int &mult)
{
    sum=a+b;
    mult=a*b;
}


void sum_u(int a,int b,int *sum,int *nult)
{
    *sum=a+b;
    *nult=a*b;
}

int din(int n)
{
    int *m=new int(n);
    return *m;
}

char *resize(const char *str, unsigned size, unsigned new_size)
{
    char *array = new char [new_size];
    if (new_size> size) {
        for (int i = 0; i < size; i++) {
            array[i] = str[i];
        }
        delete[] str;
    }
    else {
        for (int k=0;k<new_size;k++)
            array[k]=str[k];
        delete [] str;
    }

    return array;

}

char *getline()
{
    int i = 0;
    char c;
    char * tmp = new char[1];
    while (std::cin.get(c) && (c != '\n')) {
        i++;
        tmp[i-1] = c;
        char * new_tmp = new char[i+1];
        for (int n=0;n<i;n++) new_tmp[n] = tmp[n];
        delete [] tmp;
        tmp = new_tmp;
    }
    tmp[i] = '\0';
    return tmp;
}

int **create_array_2d(size_t row_size, size_t column_size){
    int **m = new int *[row_size];
    for (size_t i=0;i!=row_size;++i){
        m[i]=new int[column_size];
    }
    return m;
}


void free_array_2d(int **m, size_t row_size){
    for (size_t i = 0;i != row_size;++i){
        delete[] m[i];
    }
    delete [] m;
}


int ** transpose(const int * const * m, unsigned rows, unsigned cols)
{
    int  **Tmatrix = create_array_2d(cols,rows);
    for (int i=0;i<cols;++i){
        for (int j =0; j<rows;++j){
            Tmatrix[i][j]=m[j][i];
        }
    }
    return Tmatrix;
}

void swap_min(int *m[], unsigned rows, unsigned cols){

    int *tmp = new int[cols];
    int min = m[0][0];
    int save_row = 0;
    for (int i = 0 ;i<rows;i++)
        for (int j = 0; j < cols; j++)
            if (m[i][j] < min) {
                save_row = i;
                min = m[i][j];
            }

    for (int sw=0;sw<cols;++sw)
        tmp[sw]=m[0][sw];

    for (int sw=0;sw<cols;++sw)
        m[0][sw]=m[save_row][sw];

    for (int sw=0;sw<cols;++sw)
        m[save_row][sw]=tmp[sw];

}



double LenS(Segment a)
{
    double dx = a.p1.x - a.p2.x;
    double dy = a.p1.y - a.p2.y;
    return sqrt(dx*dx+dy*dy);
}

void point::shift(double x, double y) {
    this->x+=x;
    this->y+=y;
}