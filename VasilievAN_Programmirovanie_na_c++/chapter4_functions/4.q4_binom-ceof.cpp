/*
 * =====================================================================================
 *
 *       Filename:  4.q4_binom-ceofs.cpp
 *
 *    Description: computes binomial coefs with func 
 *
 *        Version:  1.0
 *        Created:  05/31/20 18:33:24
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

int binom_coef(int k, int n);


int main()
{
    int k = 2,
        n = 4;
    cout << "There are " << binom_coef(k, n)
         << " ways to select " << k << " items from " << n << endl;
    return 0;
}


int binom_coef(int k, int n)
{
    if (k < 0 || n < k)
        return 0;
    int chance = 1;             // chance - тут мне пришлось понимать логику
    for (int i = 0; i < k; i++) //   бинома Ньютона заного. Да, программка
        chance *= n - i;        //   на эту тему была ещё в первой главе, тогда
    for (int i = 1; i <=k; i++) //   я, наверное, неделю потратил, чтобы его
        chance /= i;            //   понять. Видимо понял недостаточно, т.к.
    return chance;              //   сейчас не смог повторить. Сейчас я не
}                               //   буду делать ту же ошибку, т.к. запишу
                                //   мысли понятным языком. В общем так:
                                //   Тебе нужно купить
                                //   коробку яиц на завтрак, молоко, хлеб и
                                //   курятину в упаковке. Сколько есть
                                //   способов купить их? У нас есть 4 кандидата
                                //   отправиться в корзину для покупок пырвым.
                                //   Допустим, тебя потянуло за молоком. Где-то
                                //   в параллельной вселенной та отправился за
                                //   хлебом, а где-то за курицей. И так, у тебя
                                //   было 4 пути для выбора первой покупки.
                                //   Молоко взяли, отлично. Вычёркиваем его из
                                //   списка покупок. Осталось купить ещё три
                                //   вещи. Кто же попадёт в корзину покупок
                                //   вторым? Ты вдруг вспомнил как хороша была
                                //   курятина, которую ты ел в прошлый четверг
                                //   и положил в корзину именно курятину, хотя
                                //   ты мог бы легко отправиться за яицами или
                                //   хлебом. Вычёркиваем курицу в списке
                                //   второй. Итого у нас было 4*3=12 разных
                                //   способов купить первые два продукта из
                                //   списка покупок. Но погоди, нам же без
                                //   разницы кто попал в корзину первым: молоко
                                //   или курятина. Здесь мы сначала купили
                                //   молоко, а затем курицу, но мы могли купить
                                //   сначала курятину, а затем молоко. Корзина
                                //   в обоих случаях хранилы бы молоко с
                                //   курятиной. И так для каждого из 12 путей
                                //   есть брат-близнец. Значит, 12/2=6
                                //   абсолютно разных вариаций корзин. Ты не
                                //   найдёшь в них одинаковой начинки. Только
                                //   что мы нашли биномиальный коэффициент для
                                //   k=2, n=4. А что было для k=1? А k=1 - это
                                //   и был наш первый шаг. Мы на нём молоко
                                //   выбирали, а было у нас 4 пути. Также без
                                //   близнецов. Мы уже разобрали пути для k=1
                                //   и k=2. Дальше идёт третий выбор. Нам
                                //   осталось купить хлеб и яица. Теперь у нас
                                //   развилка на две дороги, значит для каждой
                                //   из возмножных предыдущих путей появляется
                                //   по паре новых вариаций. Значит для k=3
                                //   будет 4*3*2=24 путей. Отсекаем близнецов:
                                //   ( (4*3)/2 )*2/3 = 4. Делим на 3, т.к.
                                //   помимо тех первых двух отсичённых
                                //   близнецов может получится ещё три. Если
                                //   объявнять на пальцах, то сначала у нас
                                //   было a b, но, т.к. могло получится и b a,
                                //   мы поделили возможности на 2. Теперь
                                //   добавлятеся c. Может получится a b c,
                                //   может c a b, а может a c b. Три одинаковых
                                //   корзины с разным расположение продуктов.
                                //   "Схлопываем" эти корзины в одну, делив
                                //   все вариации на три. А возьмём мы яица.
                                //   Ну и смотрим что осталось. А выбор у нас
                                //   только один - хлеб. Он нам не привносит
                                //   новых вариаций, а только схлопывает всё
                                //   до одного варианта, ведь наполнить корзину
                                //   четырьмя разными продуктами можно только
                                //   одним способом. Говоря цифрами, 4/4=1.
                                //   Итого мы получаем числа возможных
                                //   различных путей для каждого шага, начиная
                                //   с первого, т.е. того, когда мы вошли
                                //   в магазин: 4, 6, 4, 1. Но погоди, есть
                                //   ещё один шаг - попросту не идти в магазин!
                                //   А сколько у нас есть возможностей не идти
                                //   за продуктами? Ровно 1. Этот шаг мы решаем
                                //   ещё до того, как мы прибываем в магазин.
                                //   И наш конечный результат - и есть ряд
                                //   биномиальных коэффициентов:
                                //   1, 4, 6, 4, 1. Как и пологается, он
                                //   симметричен
