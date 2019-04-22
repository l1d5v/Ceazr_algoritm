#pragma once

#include<iostream>
#include<time.h>
#include<string>

using namespace std;

// Функции для алгоритма цезаря

int find_lng(string lng);
string crypto(string msg, int max_lng, int key, int choise);
int rand_key();
int convert_C(string msg, int i);
char convert_A(int num);
int cezar_algoritm();

