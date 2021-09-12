/*
 * =====================================================================================
 *
 *       Filename:  6.6_copy-construct.cpp
 *
 *    Description:  creates recursive class with constructor for copy and list
 *                  of it
 *
 *        Version:  1.0
 *        Created:  06/15/20 16:04:53
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

class CharNode {
public:
   char c;
   CharNode *next;

   CharNode(char _c) {
      c = _c;
      next = NULL;
   }
   CharNode(CharNode &obj) {
      obj.next = this;  // CharNode() - это конструкор копий. Он стоит на ряду
      c = obj.c + 1;    //   с конструктором и деструктором. При команде
   }                    //   obj1 = obj2; вызывается именно он. Компилятор
   ~CharNode() {        //   также вставляет такой в класс по умолчанию
      if (next) {       //   (вместе с обычным конструктором и деструктором),
         delete next;   //   если ты не добавил свой. Конструктор копий по
      }                 //   умолчанию просто копирует все поля. В объявлении
                        //   есть один нюанс: если конструктор копий будет
                        //   принимать параметр по значению, то для того, чтобы
                        //   это значение получить, нужно копировать значение
                        //   из места вызова функции в переменную внутри
                        //   функции, которая параметр. Значит придётся вызвать
                        //   этот же конструктор копии. А чтобы использовать
                        //   конструктор копии, нужно опять вызвать конструктор
                        //   копий, и так до бесконечности. g++ это увидит, и
                        //   выдвинет ошибку, предлагая поставить &. Также
                        //   можно передавать указатель на тип класса, но это
                        //   уже не будет считаться конструктором копий. Стоит
                        //   сказать, что для переменной которой присваивается
                        //   другая переменная, не вызывается обычный
                        //   конструктор
      cout << c << " has been deleted" << endl;
   }

   void print_recursive() {
      cout << c << " ";
      if (next)
         next->print_recursive();
      else
         cout << endl;
   }
};


int main()
{
   CharNode *p_head = new CharNode('A');
   {
      CharNode *p_node = p_head;
      for (int _ = 0; _ < 10; _++) {
         p_node = new CharNode(*p_node);  // CharNode() - тут это выглядит как
      }                                   //   стандартный вызов конструктора
      p_node->next = NULL;
   }

   p_head->print_recursive();
   cout << endl;

   delete p_head;
   return 0;
}
