/*
 * =====================================================================================
 *
 *       Filename:  3.q8_array-cyclic-permutation.cpp
 *
 *    Description: creates an array and cyclic rearranges it 
 *
 *        Version:  1.0
 *        Created:  05/19/20 22:23:38
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Artur
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    srand(0);
    const int size = 9;

    int nums[size];
        for (int &x: nums) {
            x = rand() % 9;
            cout << x << ", ";
        }
        cout << endl;
    int shift;
        cout << "Shift: ";
        cin >> shift;
        shift = shift % size;       // %  - мы же не хотим делать лишнюю
        if (shift == 0) {           //      работу, верно?
            for (int &x: nums)      // if - бесконечный цикл тоже отсеиваем
                cout << x << ", ";
            cout << endl;
            return 0;
        }

    // Можно было сделать и по простому, т.е. двигать весь массив по 1, пока
    // не подвинем достаточно, но зачем столько раз перебирать элементы? Здесь
    // мы изменяем каждый элемент только один раз. Каждый элемент сначала
    // сохраняется в буфер и сразу же заменятся предыдущим элементом, который
    // идёт ровно на сдвиг левее. Если мы добираемся до конца массива, то
    // продолжаем с его начала. Так, мы начинаем с 0-го элемента, вставляя
    // в него тот, что левее (но слева обрыв, поэтому отсчитываем с конца),
    // и передвигаемся на свдиг вправо, повторяя действие. И так покругу. Если
    // выйдет так, что мы попадём на то, что уже обработали, то это значит, что
    // или мы уже всё прошли, или так совпало. Поэтому мы сохраняем тот
    // элемент, что стоит перед сдвигом, и проверяем его каждый раз, когда
    // такая натыкаемся на уже пройденный элемент (мы проверяем начальный).
    // Такая петля случается довольно редко, но если она случилась, то мы
    // начинаем цикл заного, но теперь стартуем с 1-го элемента.
    int cur_id,                     // cur_id - id текущего элемента
        buf_cur,                    // buf_cur - буфер для текущего элемента,
        buf_last,                   //           который станет buf_last для
        lch_id = 0,                 //           следующего
        check = nums[shift - 1];    // lch_id  - стартовая для цикла точка
                                    //           в случае петли
                                    // check   - наш контрольный элемент. Если
                                    //           в массиве он не изменился, то
                                    //           продолжаем работать
    while (nums[shift - 1] == check) {
        cur_id = lch_id;
        buf_cur = nums[size - shift + lch_id];
        do {
            buf_last = buf_cur;
            buf_cur = nums[cur_id];
            nums[cur_id] = buf_last;
        
            cur_id = (cur_id + shift) % size;
        } while (cur_id != lch_id);
        lch_id++;
    }
    
    for (int &x: nums)
        cout << x << ", ";
    cout << endl;
    return 0;
}
