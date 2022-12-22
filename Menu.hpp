//
//  Menu.hpp
//  LABA1
//
//  Created by Даша Пархоменко on 17.12.2022.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <stdio.h>

#include <iostream>
#include <chrono>
#include "DynamicArray.hpp"
#include "LinkedList.hpp"
#include "Sequence.hpp"
#include "ArraySequence.hpp"
#include "Tests.hpp"
#include "random_all.hpp"
#include "Sort&Compare.hpp"
#include "LinkedListSequence.hpp"
//#include "DoSort.hpp"

using namespace std;
int menu_var(int count);
int main_menu ();
int second_menu ();
int third_menu ();
int input_count ();

int input_print();


void menu();

int menu_var(int count)
{
    int v;
    cin>>v;
    while ( v < 0 || v > count) {
        cout<<("ошибка, попробйте еще раз==>"); // выводим сообщение об ошибке
        cin>>v; // считываем строку повторно
    }
    return v;
}

int main_menu ()
{
    int r;
    cout<<"ОСНОВНОЕ ДИАЛОГОВОЕ МЕНЮ!"<< endl;
    cout<<"#############################################################"<< endl;
    cout<<"1 - Тесты DynamicArray & LinkedList & ArraySequence & __     "<< endl;
    cout<<"2 - Перейти в меню создания объекта Sequence и сортировки____"<< endl;
    cout<<"0 - ВЫХОД ИЗ ПРОГРАММЫ!"<<endl;
    cout<<"#############################################################"<< endl;
    cout<<"Введите цифру от 0 до 2 ==> ";
    r=menu_var(2);
    return r;
}

int second_menu ()
{
    int r;
    cout<<"МЕНЮ СОЗДАНИЯ ОБЪЕКТОВ Sequence!"<< endl;
    cout<<"-------------------------------------------------------------"<< endl;
    cout<<"1 - Создать случайный объект ArraySequence <Int>_____________"<< endl;
    cout<<"2 - Создать случайный объект ArraySequence <Double>__________"<< endl;
    cout<<"3 - Создать случайный объект LinkeListSequence <Int>_________"<< endl;
    cout<<"4 - Создать случайный объект LinkeListSequence <Double>_______"<< endl;
    cout<<"0 - возврат!"<<endl;
    cout<<"-------------------------------------------------------------"<< endl;
    cout<<"Введите цифру от 0 до 4 ==> ";
    r=menu_var(4);
    return r;
}

int third_menu ()
{
    int r;
    cout<<"МЕНЮ СОРТИРОВКИ ОБЪЕКТОВ Sequence!"<< endl;
    cout<<"-------------------------------------------------------------"<< endl;
    cout<<"1 - Вывод на экран текущего объекта Sequence_________________"<< endl;
    cout<<"2 - Выполнить программу сортировки к объекту Sequence________"<< endl;
    cout<<"3 - Скопировать в объект Sequence результат сортировки_______"<< endl;
    cout<<"4 - Выполнить обратную сортировку и скопировать в объект_____"<< endl;
    cout<<"0 - возврат!"<<endl;
    cout<<"-------------------------------------------------------------"<< endl;
    cout<<"Введите цифру от 0 до 3 ==> ";
    r=menu_var(4);
    return r;
}


int input_count ()
{
    int result;
    cout<<"Ввод размерности ==> ";
    cin>> result;
    while (result<=0)
    {
        cout<<"ошибка, попробуйте еще раз (введите положительное целое число)"<<endl;
        cout<<"Ввод размерности ==> ";
        cin>> result;
    }
    return result;
}


int input_print ()
{
    int result;
    cout<<"Вывести на экран результат сортировки ( 1 - да/ 0 - нет) ";
    cin>> result;
    while (result<0 || result>1)
    {
        cout<<"ошибка, попробуйте еще раз (введите положительное целое число)"<<endl;
        cout<<"Ввод размерности ==> ";
        cin>> result;
    }
    return result;
}




void menu()
{
    int c;
    while (1==1)
    {
        c = main_menu();
        switch (c)
        {
            case 0:
                return;
                
            case 1:
            {
                TestDynamicArray();
                TestLinkedList();
                TestArraySequence();
                //0Tests_();
            //    TestLinkedListSequence()
            }
                break;
                
                
            case 2:  //  создание объекта
            {
                int c2,q2=1;
                while (q2)
                {
                    c2 = second_menu();
                    switch (c2)
                    {
                        case 0:
                            q2=0;
                            break;
                            
                        case 1: // создать случайный объект ArraySequence <Int>
                        {
                            int c3,q3=1, item_random;
                            int count = input_count();
                            ArraySequence<int> obj_0 = ArraySequence<int>(0, count);
                            for (int i = 0; i < count; i++)
                            {
                                item_random = random_int(1000000, -1000000);
                                obj_0.Set_(item_random, i);
                            }
                            obj_0.Print_();
                            
                            ArraySequence<int> obj_1 = ArraySequence<int>(0, obj_0.GetLength_());
                            ArraySequence<int> obj_2 = ArraySequence<int>(0, obj_0.GetLength_());
                            ArraySequence<int> obj_3 = ArraySequence<int>(0, obj_0.GetLength_());
                            ArraySequence<int> obj_4 = ArraySequence<int>(0, obj_0.GetLength_());
                            ArraySequence<int> obj_5 = ArraySequence<int>(0, obj_0.GetLength_());
                            for (int i = 0; i < obj_0.GetLength_(); i++)
                            {
                                obj_1.Set_(obj_0.Get_(i), i);
                                obj_2.Set_(obj_0.Get_(i), i);
                                obj_3.Set_(obj_0.Get_(i), i);
                                obj_4.Set_(obj_0.Get_(i), i);
                                obj_5.Set_(obj_0.Get_(i), i);
                            }
                            
                            
                            while (q3)
                            {
                                c3 = third_menu();
                                switch (c3) {
                                    case 0:
                                        q3 = 0;
                                        break;
                                    
                                    case 1: // печать объекта
                                    {
                                        cout<<"Вывод на экран текущего объекта (obj_0), сколичество данных = " << obj_0.GetLength_() <<endl;
                                        cout<<"=========================="<<endl;
                                        obj_0.Print_();
                                        cout<<"=========================="<<endl;
                                    }
                                        break;
                                        
                                    case 2:  // проведение 3-4 сортировок - создание соотвествующих объектов
                                        
                                    {
                                        auto begin1 = chrono::steady_clock::now();
                                        selectionSort<int>(&obj_1); //сортировка выбором
                                        auto end1 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort1 = chrono::duration_cast<chrono::milliseconds>(end1 - begin1);
                                        cout<<"Время выполнениия сортировки SelectionSort = " <<  elapsed_ms_selectionSort1.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er1 = test_sort(&obj_1);
                                        if (input_print())
                                            obj_1.Print_();
                                        
                                        auto begin2 = chrono::steady_clock::now();
                                        shellSort<int>(&obj_2); //сортировка выбором
                                        auto end2 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort2 = chrono::duration_cast<chrono::milliseconds>(end2 - begin2);
                                        cout<<"Время выполнениия сортировки ShellSort = " <<  elapsed_ms_selectionSort2.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er2 = test_sort(&obj_2);
                                        if (input_print())
                                            obj_2.Print_();
                                        
                                        auto begin3 = chrono::steady_clock::now();
                                        shellSort<int>(&obj_3); //сортировка выбором
                                        auto end3 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort3 = chrono::duration_cast<chrono::milliseconds>(end3 - begin3);
                                        cout<<"Время выполнениия сортировки MergeSort = " <<  elapsed_ms_selectionSort3.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er3 = test_sort(&obj_3);
                                        if (input_print())
                                            obj_3.Print_();
                                        
                                        auto begin4 = chrono::steady_clock::now();
                                        BubbleSort<int>(&obj_4); //сортировка выбором
                                        auto end4 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort4 = chrono::duration_cast<chrono::milliseconds>(end4 - begin4);
                                        cout<<"Время выполнениия сортировки BubleSort = " <<  elapsed_ms_selectionSort4.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er4 = test_sort(&obj_4);
                                        if (input_print())
                                            obj_4.Print_();
                                        
                                    }
                                        
                                        break;
                                        
                                    case 3:  // перезапись объекта оnсротированным объектом
                                        for (int i = 0; i < obj_0.GetLength_(); i++)
                                        {
                                            obj_0.Set_(obj_1.Get_(i), i);
                                        }
                                        
                                        break;
                                    case 4:
                                    {
                                        auto begin5 = chrono::steady_clock::now();

                                        BubbleSortDown <int>(&obj_5); //сортировка выбором
                                        auto end5 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort5 = chrono::duration_cast<chrono::milliseconds>(end5 - begin5);
                                        cout<<"Время выполнениия сортировки BubleSortDown2 = " <<  elapsed_ms_selectionSort5.count() <<" ms" <<endl;
                                        
                                        for (int i = 0; i < obj_0.GetLength_(); i++)
                                        {
                                            obj_0.Set_(obj_5.Get_(i), i);
                                        }
                                    }
                                        break;
                                        
                                    default:
                                        break;
                                }
                            }
                            
                        }
                            break;
                            
                        case 2: // cоздать случайный объект ArraySequence <Double>
                        {
                            
                            int c3,q3=1;
                            double item_random;
                            int count = input_count();
                            ArraySequence<double> obj_0 = ArraySequence<double>(0.0, count);
                            for (int i = 0; i < count; i++)
                            {
                                item_random = random_double(100000.0, -100000.0);
                                obj_0.Set_(item_random, i);
                            }
                            obj_0.Print_();
                            
                            ArraySequence<double> obj_1 = ArraySequence<double>(0.0, obj_0.GetLength_());
                            ArraySequence<double> obj_2 = ArraySequence<double>(0.0, obj_0.GetLength_());
                            ArraySequence<double> obj_3 = ArraySequence<double>(0.0, obj_0.GetLength_());
                            ArraySequence<double> obj_4 = ArraySequence<double>(0.0, obj_0.GetLength_());
                            ArraySequence<double> obj_5 = ArraySequence<double>(0.0, obj_0.GetLength_());
                            
                            for (int i = 0; i < obj_0.GetLength_(); i++)
                            {
                                obj_1.Set_(obj_0.Get_(i), i);
                                obj_2.Set_(obj_0.Get_(i), i);
                                obj_3.Set_(obj_0.Get_(i), i);
                                obj_4.Set_(obj_0.Get_(i), i);
                                obj_5.Set_(obj_0.Get_(i), i);
                                
                            }
                            
                            
                            while (q3)
                            {
                                c3 = third_menu();
                                switch (c3) {
                                    case 0:
                                        q3 = 0;
                                        break;
                                        
                                    case 1: // печать объекта
                                    {
                                        cout<<"Вывод на экран текущего объекта (obj_0), сколичество данных = " << obj_0.GetLength_() <<endl;
                                        cout<<"=========================="<<endl;
                                        obj_0.Print_();
                                        cout<<"=========================="<<endl;
                                    }
                                        break;
                                        
                                    case 2:  // проведение 3-4 сортировок - создание соотвествующих объектов
                                        
                                    {
                                        auto begin1 = chrono::steady_clock::now();
                                        selectionSort<double>(&obj_1); //сортировка выбором
                                        auto end1 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort1 = chrono::duration_cast<chrono::milliseconds>(end1 - begin1);
                                        cout<<"Время выполнениия сортировки SelectionSort = " <<  elapsed_ms_selectionSort1.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er1 = test_sort(&obj_1);
                                        if (input_print())
                                            obj_1.Print_();
                                        
                                        auto begin2 = chrono::steady_clock::now();
                                        shellSort<double>(&obj_2); //сортировка выбором
                                        auto end2 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort2 = chrono::duration_cast<chrono::milliseconds>(end2 - begin2);
                                        cout<<"Время выполнениия сортировки ShellSort = " <<  elapsed_ms_selectionSort2.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er2 = test_sort(&obj_2);
                                        if (input_print())
                                            obj_2.Print_();
                                        
                                        auto begin3 = chrono::steady_clock::now();
                                        shellSort<double>(&obj_3); //сортировка выбором
                                        auto end3 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort3 = chrono::duration_cast<chrono::milliseconds>(end3 - begin3);
                                        cout<<"Время выполнениия сортировки MergeSort = " <<  elapsed_ms_selectionSort3.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er3 = test_sort(&obj_2);
                                        if (input_print())
                                            obj_3.Print_();
                                        
                                        auto begin4 = chrono::steady_clock::now();
                                        BubbleSort<double>(&obj_4); //сортировка выбором
                                        auto end4= chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort4 = chrono::duration_cast<chrono::milliseconds>(end4 - begin4);
                                        cout<<"Время выполнениия сортировки BubbleSort = " <<  elapsed_ms_selectionSort4.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er4 = test_sort(&obj_2);
                                        if (input_print())
                                            obj_4.Print_();
                                    }
                                        
                                        break;
                                        
                                    case 3:  // перезапись объекта оnсротированным объектом
                                        for (int i = 0; i < obj_0.GetLength_(); i++)
                                        {
                                            obj_0.Set_(obj_1.Get_(i), i);
                                        }
                                        
                                        break;
                                        
                                    case 4:
                                    {
                                        auto begin5 = chrono::steady_clock::now();
                                        BubbleSortDown <double>(&obj_5); //сортировка выбором
                                        auto end5 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort5 = chrono::duration_cast<chrono::milliseconds>(end5 - begin5);
                                        cout<<"Время выполнениия сортировки BubleSort = " <<  elapsed_ms_selectionSort5.count() <<" ms" <<endl;
                                        
                                        for (int i = 0; i < obj_0.GetLength_(); i++)
                                        {
                                            obj_0.Set_(obj_5.Get_(i), i);
                                        }
                                    }
                                        break;
                                        
                                        
                                    default:
                                        break;
                                }
                            }
                            
                        }
                        
                            break;
                            
                        case 3: // cоздать случайный объект LinkcedList <int>
                        {
                            int c3,q3=1, item_random;
                            int count = input_count();
                            ArraySequence<int> obj_0 = ArraySequence<int>(0, count);
                            for (int i = 0; i < count; i++)
                            {
                                item_random = random_int(1000000, -1000000);
                                obj_0.Set_(item_random, i);
                            }
                            obj_0.Print_();
                            
                            ArraySequence<int> obj_1 = ArraySequence<int>(0, obj_0.GetLength_());
                            ArraySequence<int> obj_2 = ArraySequence<int>(0, obj_0.GetLength_());
                            ArraySequence<int> obj_3 = ArraySequence<int>(0, obj_0.GetLength_());
                            ArraySequence<int> obj_4 = ArraySequence<int>(0, obj_0.GetLength_());
                            ArraySequence<int> obj_5 = ArraySequence<int>(0, obj_0.GetLength_());
                            for (int i = 0; i < obj_0.GetLength_(); i++)
                            {
                                obj_1.Set_(obj_0.Get_(i), i);
                                obj_2.Set_(obj_0.Get_(i), i);
                                obj_3.Set_(obj_0.Get_(i), i);
                                obj_4.Set_(obj_0.Get_(i), i);
                                obj_5.Set_(obj_0.Get_(i), i);
                            }
                            
                            
                            while (q3)
                            {
                                c3 = third_menu();
                                switch (c3) {
                                    case 0:
                                        q3 = 0;
                                        break;
                                    
                                    case 1: // печать объекта
                                    {
                                        cout<<"Вывод на экран текущего объекта (obj_0), сколичество данных = " << obj_0.GetLength_() <<endl;
                                        cout<<"=========================="<<endl;
                                        obj_0.Print_();
                                        cout<<"=========================="<<endl;
                                    }
                                        break;
                                        
                                    case 2:  // проведение 3-4 сортировок - создание соотвествующих объектов
                                        
                                    {
                                        auto begin1 = chrono::steady_clock::now();
                                        selectionSort<int>(&obj_1); //сортировка выбором
                                        auto end1 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort1 = chrono::duration_cast<chrono::milliseconds>(end1 - begin1);
                                        cout<<"Время выполнениия сортировки SelectionSort = " <<  elapsed_ms_selectionSort1.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er1 = test_sort(&obj_1);
                                        if (input_print())
                                            obj_1.Print_();
                                        
                                        auto begin2 = chrono::steady_clock::now();
                                        shellSort<int>(&obj_2); //сортировка выбором
                                        auto end2 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort2 = chrono::duration_cast<chrono::milliseconds>(end2 - begin2);
                                        cout<<"Время выполнениия сортировки ShellSort = " <<  elapsed_ms_selectionSort2.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er2 = test_sort(&obj_2);
                                        if (input_print())
                                            obj_2.Print_();
                                        
                                        auto begin3 = chrono::steady_clock::now();
                                        shellSort<int>(&obj_3); //сортировка выбором
                                        auto end3 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort3 = chrono::duration_cast<chrono::milliseconds>(end3 - begin3);
                                        cout<<"Время выполнениия сортировки MergeSort = " <<  elapsed_ms_selectionSort3.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er3 = test_sort(&obj_3);
                                        if (input_print())
                                            obj_3.Print_();
                                        
                                        auto begin4 = chrono::steady_clock::now();
                                        BubbleSort<int>(&obj_4); //сортировка выбором
                                        auto end4 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort4 = chrono::duration_cast<chrono::milliseconds>(end4 - begin4);
                                        cout<<"Время выполнениия сортировки BubleSort = " <<  elapsed_ms_selectionSort4.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er4 = test_sort(&obj_4);
                                        if (input_print())
                                            obj_4.Print_();
                                        
                                    }
                                        
                                        break;
                                        
                                    case 3:  // перезапись объекта оnсротированным объектом
                                        for (int i = 0; i < obj_0.GetLength_(); i++)
                                        {
                                            obj_0.Set_(obj_1.Get_(i), i);
                                        }
                                        
                                        break;
                                    case 4:
                                    {
                                        auto begin5 = chrono::steady_clock::now();
                                        BubbleSortDown <int>(&obj_5);
                                        auto end5 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort5 = chrono::duration_cast<chrono::milliseconds>(end5 - begin5);
                                        cout<<"Время выполнениия сортировки BubleSortDown = " <<  elapsed_ms_selectionSort5.count() <<" ms" <<endl;
                                        
                                        for (int i = 0; i < obj_0.GetLength_(); i++)
                                        {
                                            obj_0.Set_(obj_5.Get_(i), i);
                                        }
                                    }
                                        break;
                                        
                                    default:
                                        break;
                                }
                            }
                            
                            
                        }
                            break;
                            
                        case 4: // cоздать случайный объект LinkeListSequence <Double>
                        {
                            int c3,q3=1;
                            double item_random;
                            int count = input_count();
                            ArraySequence<double> obj_0 = ArraySequence<double>(0.0, count);
                            for (int i = 0; i < count; i++)
                            {
                                item_random = random_double(100000.0, -100000.0);
                                obj_0.Set_(item_random, i);
                            }
                            obj_0.Print_();
                            
                            ArraySequence<double> obj_1 = ArraySequence<double>(0.0, obj_0.GetLength_());
                            ArraySequence<double> obj_2 = ArraySequence<double>(0.0, obj_0.GetLength_());
                            ArraySequence<double> obj_3 = ArraySequence<double>(0.0, obj_0.GetLength_());
                            ArraySequence<double> obj_4 = ArraySequence<double>(0.0, obj_0.GetLength_());
                            ArraySequence<double> obj_5 = ArraySequence<double>(0.0, obj_0.GetLength_());
                            for (int i = 0; i < obj_0.GetLength_(); i++)
                            {
                                obj_1.Set_(obj_0.Get_(i), i);
                                obj_2.Set_(obj_0.Get_(i), i);
                                obj_3.Set_(obj_0.Get_(i), i);
                                obj_4.Set_(obj_0.Get_(i), i);
                                obj_5.Set_(obj_0.Get_(i), i);
                            }
                            
                            
                            while (q3)
                            {
                                c3 = third_menu();
                                switch (c3) {
                                    case 0:
                                        q3 = 0;
                                        break;
                                    
                                    case 1: // печать объекта
                                    {
                                        cout<<"Вывод на экран текущего объекта (obj_0), сколичество данных = " << obj_0.GetLength_() <<endl;
                                        cout<<"=========================="<<endl;
                                        obj_0.Print_();
                                        cout<<"=========================="<<endl;
                                    }
                                        break;
                                        
                                    case 2:  // проведение 3-4 сортировок - создание соотвествующих объектов
                                        
                                    {
                                        auto begin1 = chrono::steady_clock::now();
                                        selectionSort<double>(&obj_1); //сортировка выбором
                                        auto end1 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort1 = chrono::duration_cast<chrono::milliseconds>(end1 - begin1);
                                        cout<<"Время выполнениия сортировки SelectionSort = " <<  elapsed_ms_selectionSort1.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er1 = test_sort(&obj_1);
                                        if (input_print())
                                            obj_1.Print_();
                                        
                                        auto begin2 = chrono::steady_clock::now();
                                        shellSort<double>(&obj_2); //сортировка выбором
                                        auto end2 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort2 = chrono::duration_cast<chrono::milliseconds>(end2 - begin2);
                                        cout<<"Время выполнениия сортировки ShellSort = " <<  elapsed_ms_selectionSort2.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er2 = test_sort(&obj_2);
                                        if (input_print())
                                            obj_2.Print_();
                                        
                                        auto begin3 = chrono::steady_clock::now();
                                        shellSort<double>(&obj_3); //сортировка выбором
                                        auto end3 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort3 = chrono::duration_cast<chrono::milliseconds>(end3 - begin3);
                                        cout<<"Время выполнениия сортировки MergeSort = " <<  elapsed_ms_selectionSort3.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er3 = test_sort(&obj_2);
                                        if (input_print())
                                            obj_3.Print_();
                                        
                                        auto begin4 = chrono::steady_clock::now();
                                        BubbleSort<double>(&obj_4); //сортировка выбором
                                        auto end4= chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort4 = chrono::duration_cast<chrono::milliseconds>(end4 - begin4);
                                        cout<<"Время выполнениия сортировки BubbleSort = " <<  elapsed_ms_selectionSort4.count() <<" ms" <<endl;
                                        // тестирование корректности сортировки
                                        int er4 = test_sort(&obj_2);
                                        if (input_print())
                                            obj_4.Print_();
                                    }
                                        
                                        break;
                                        
                                    case 3:  // перезапись объекта оnсротированным объектом
                                        for (int i = 0; i < obj_0.GetLength_(); i++)
                                        {
                                            obj_0.Set_(obj_1.Get_(i), i);
                                        }
                                        
                                        break;
                                    
                                    case 4:
                                    {
                                        auto begin5 = chrono::steady_clock::now();
                                        BubbleSortDown <double>(&obj_5); //сортировка выбором
                                        auto end5 = chrono::steady_clock::now();
                                        auto elapsed_ms_selectionSort5 = chrono::duration_cast<chrono::milliseconds>(end5 - begin5);
                                        cout<<"Время выполнениия сортировки BubleSortDown = " <<  elapsed_ms_selectionSort5.count() <<" ms" <<endl;
                                        
                                        for (int i = 0; i < obj_0.GetLength_(); i++)
                                        {
                                            obj_0.Set_(obj_5.Get_(i), i);
                                        }
                                    }
                                        break;
                                    default:
                                        break;
                                }
                            }
                            
                        }
                            break;
                            
                            
                        default:
                            break;
                    }
                }
            }
                break;
                
                
            default:
                break;
        }
    }
}

#endif /* Menu_hpp */
