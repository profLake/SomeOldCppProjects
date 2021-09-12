/*
 * =====================================================================================
 *
 *       Filename:  4.12_pointer-as-func-result_arr-pointer-max.cpp
 *
 *    Description: creates an int array and demonstrates using func returning
 *                 pointer of max 
 *
 *        Version:  1.0
 *        Created:  05/30/20 16:37:37
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

void show(int *_arr, int _size);
int* get_max(int *_arr, int _size);


int main()
{
    const int size = 10;
    
    int nums[size] = {1, 5, 8, 2, 4, 9, 11, 9, 12, 3};
        show(nums, size);

    int *p_max = get_max(nums, size);
        cout << "Max is    " << *p_max << endl;

    *p_max = -100;      // *.. - напоминаю, что это называется разымёнывание
    show(nums, size);

    int max = *get_max(nums, size);
        cout << "Max is    " << max << endl;

    max = -200;
    show(nums, size);

    cout << "Max is    " << *get_max(nums, size) << endl;
    cout << "Max id is " << get_max(nums, size) - nums << endl;
                        // int* - int* - тут есть одна интересная, но весьма
                        //   коварная особенность: арифметика указателей,
                        //   работает не как арифметика простых чисел. Она
                        //   довольно сильно зависит от типа, на который она
                        //   указывает. Как мы знаем, указатель указывает на
                        //   отдельный байт в памяти. int занимает 4 байта.
                        //   Значит, если наше число имеет id 6 в массиве, то
                        //   на самом деле оно отдалено на 24 байта от первого
                        //   байта первого элемента. Но если мы явно не укажем
                        //   какой тип нам нужен, то p_max - nums выдаст нам
                        //   именно 6, т.к. расстоияние между этими байтами
                        //   ещё поделится на 4 байта, чтобы получилая разница
                        //   именно в int-объектах. В итоге получаем
                        //   (xxxx44 - xxxx20)/4 = 6. Ровно 6 int-объектов в
                        //   памяти надо пройти, чтобы добраться до нужного
                        //   байта. И ещё: Указатели не умеют складываться
                        //   друг с другом. Видимо боятся, что мы попадём за
                        //   пределы памяти (ну, во всяком случае g++ ругается
                        //   на это). Хотя указатель с числом вполне в этом
                        //   плане уживаются
            // Пока наблюдал за всем этим заметил, что если в printf()
            // поставить спецификатор %i для вывода адреса (да, я делал и
            // такое), то  предлагает заменить его на %n. Такого я раньше
            // не встречал, поэтому сразу же полез в инет. В общем, это
            // довольно интересная штука. Она может записать в переменную
            // число уже выведенных символов. Разумеется, для этого к ней нужно
            // подсунуть адрес переменной. Например, у нас есть n = -1. Тогда
            // printf("Hello!%n %i", &n, n); выведет Hello! -1. Да, маленько
            // странно. Можно было ожидать, что будет Hello! 6. Но если
            // использовать n дальше, то окажется, что в ней именно 6
    return 0;
}


void show(int *_arr, int _size)
{
    for (int i = 0; i < _size; i++)
        cout << _arr[i] << ", ";
    cout << endl;
}

int* get_max(int *_arr, int _size)
{
    int max_id = 0;
    for (int i = 1; i < _size; i++)
        if (_arr[i] > _arr[max_id])
            max_id = i;
    return _arr + max_id;
}