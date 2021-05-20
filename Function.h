#pragma once
#include<iostream>
#define MaxSize 50
int GetPriority(char c);
void InfixToSufix(char c[], char outstack[], int& outtop);
void InfixToPrefix(char c[], int lens, char outstack[], int& outtop);
float Calculate(float v1, char op, float v2);
float CalSufix(char WaitCal[]);
float Calprefix(char WaitCal[], int lens);
float CalInfix(char c[]);

