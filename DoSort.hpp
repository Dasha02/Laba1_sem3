//
//  DoSort.hpp
//  LABA1
//
//  Created by Даша Пархоменко on 17.12.2022.
//

#ifndef DoSort_hpp
#define DoSort_hpp

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
#include "Menu.hpp"

using namespace std;
template <typename T>
void DoArraySort(ArraySequence<T> * seq);
template <typename T>
void ArraySort(ArraySequence<T> * seq);


template <typename T>
void DoArraySort(ArraySequence<T> * seq)
{
    ArraySequence<T> obj_1 = ArraySequence<T>(seq);
    ArraySequence<T> obj_2 = ArraySequence<T>(seq);
    ArraySequence<T> obj_3 = ArraySequence<T>(seq);

    for (int i = 0; i < seq->GetLength(); i++)
    {
        obj_1.Set_(seq->Get_(i), i);
        obj_2.Set_(seq->Get_(i), i);
        obj_3.Set_(seq->Get_(i), i);
    }
    
    
    //auto begin1 = chrono::steady_clock::now();
    //mergeSort<T>(&obj_1, 0, obj_1.GetLength() - 1);
    //auto end1 = chrono::steady_clock::now();
    //auto elapsed_ms1 = chrono::duration_cast<chrono::milliseconds>(end1 - begin1);
    //cout<<"Время выполнениия сортировки MergeSort = " <<  elapsed_ms1.count() <<" ms" <<endl;
    //int er1 = test_sort(&obj_1);
    
    auto begin2 = chrono::steady_clock::now();
    selectionSort<T>(obj_2);
    auto end2 = chrono::steady_clock::now();
    auto elapsed_ms2 = chrono::duration_cast<chrono::milliseconds>(end2 - begin2);
    cout<<"Время выполнениия сортировки SelectionSort = " <<  elapsed_ms2.count() <<" ms" <<endl;
    int er2 = test_sort(&obj_2);
    
    //auto begin3 = chrono::steady_clock::now();
    //shellSort<T>(&obj_3);
    //auto end3 = chrono::steady_clock::now();
    //auto elapsed_ms3 = chrono::duration_cast<chrono::milliseconds>(end3 - begin3);
    //cout<<"Время выполнениия сортировки ShellSort = " <<  elapsed_ms3.count() <<" ms" <<endl;
    //int er3 = test_sort(&obj_3);
    
    //if (input_print())
    {
        cout<<"Результат выполнениия сортировки MergeSort: " <<endl;
        obj_1->Print_();
        cout<<"Результат выполнениия сортировки SelectionSort: " <<endl;
        obj_2->Print_();
        cout<<"Результат выполнениия сортировки ShellSort: " <<endl;
        obj_3->Print_();
    }
}

template <typename T>
void ArraySort(ArraySequence<T> * seq)
{
selectionSort<T>(seq);
}
#endif /* DoSort_hpp */
