#include "s21_smart_calc.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Инициализация стека
void initStack(Stack *stack) { stack->top = -1; }

// Проверка, пуст ли стек
int isEmpty(Stack *stack) { return stack->top == -1; }

// Проверка, полон ли стек
int isFull(Stack *stack) { return stack->top == MAX_SIZE - 1; }

// Добавление элемента в стек
void push(Stack *stack, char element) {
  if (isFull(stack)) {
    printf("Error: Stack is full\n");
    exit(1);
  }
  stack->data[++stack->top] = element;
}

// Удаление элемента из стека
char pop(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Error: Stack is empty\n");
    exit(1);
  }
  return stack->data[stack->top--];
}

// Получение верхнего элемента стека без удаления
char peek(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Error: Stack is empty\n");
    exit(1);
  }
  return stack->data[stack->top];
}

// Инициализация стека для чисел типа double
void initDoubleStack(DoubleStack *stack) { stack->top = -1; }

// Проверка, пуст ли стек для чисел типа double
int isDoubleStackEmpty(DoubleStack *stack) { return stack->top == -1; }

// Проверка, полон ли стек для чисел типа double
int isDoubleStackFull(DoubleStack *stack) { return stack->top == MAX_SIZE - 1; }

// Добавление элемента в стек для чисел типа double
void pushDouble(DoubleStack *stack, double element) {
  if (isDoubleStackFull(stack)) {
    printf("Error: Double Stack is full\n");
    exit(1);
  }
  stack->data[++stack->top] = element;
}

// Удаление элемента из стека для чисел типа double
double popDouble(DoubleStack *stack) {
  if (isDoubleStackEmpty(stack)) {
    printf("Error: Double Stack is empty\n");
    return NAN;
  }
  return stack->data[stack->top--];
}

// Приоритет оператора
int getPriority(char operat) {
  if (operat == '+' || operat == '-')
    return 1;
  else if (operat == '*' || operat == '/' || operat == '_' || operat == '%')
    return 2;
  else if (operat == '^' || operat == 's' || operat == 'c' || operat == 't' ||
           operat == 'S' || operat == 'C' || operat == 'T' || operat == 'q' ||
           operat == 'l' || operat == 'L')
    // s = sin   c = cos   t = tan   S = asin   C = acos   T = atan   q = sqrt
    // l = log   L = ln
    return 3;
  else
    return 0;
}

// Перевод строки в польскую нотацию
char *convertToRPN(const char *expression) {
  Stack operatorStack;
  Stack outputStack;
  initStack(&operatorStack);
  initStack(&outputStack);
  size_t i;
  for (i = 0; i < strlen(expression); i++) {
    char currentChar = expression[i];
    if (currentChar >= '0' && currentChar <= '9') {
      while (expression[i] >= '0' && expression[i] <= '9') {
        push(&outputStack, expression[i]);
        i++;
        if (expression[i] == '.') {
          push(&outputStack, '.');
          i++;
        }
      }
      i--;
      push(&outputStack, ' ');
    } else if (currentChar == '(') {
      push(&operatorStack, currentChar);
    } else if (currentChar == ')') {
      while (peek(&operatorStack) != '(') {
        push(&outputStack, pop(&operatorStack));
      }
      pop(&operatorStack);
    } else if (currentChar == '+' || currentChar == '*' || currentChar == '/' ||
               currentChar == '^' || currentChar == '%') {
      while (!isEmpty(&operatorStack) &&
             getPriority(peek(&operatorStack)) >= getPriority(currentChar)) {
        push(&outputStack, pop(&operatorStack));
      }
      push(&operatorStack, currentChar);
    } else if (currentChar == '-') {
      if (i == 0 || expression[i - 1] == '(' || expression[i - 2] == '(') {
        currentChar = '_';
        push(&operatorStack, currentChar);
      } else {
        while (!isEmpty(&operatorStack) &&
               getPriority(peek(&operatorStack)) >= getPriority(currentChar)) {
          push(&outputStack, pop(&operatorStack));
        }
        push(&operatorStack, currentChar);
      }
    } else if (currentChar == 's') {  // sin and sqrt
      if (expression[i + 1] == 'i' && expression[i + 2] == 'n') {
        while (!isEmpty(&operatorStack) &&
               getPriority(peek(&operatorStack)) >= getPriority(currentChar)) {
          push(&outputStack, pop(&operatorStack));
        }
        push(&operatorStack, currentChar);
        i += 2;
      } else if (expression[i + 1] == 'q' && expression[i + 2] == 'r' &&
                 expression[i + 3] == 't') {
        currentChar = 'q';
        while (!isEmpty(&operatorStack) &&
               getPriority(peek(&operatorStack)) >= getPriority(currentChar)) {
          push(&outputStack, pop(&operatorStack));
        }
        push(&operatorStack, currentChar);
        i += 3;
      } else {
        printf("Error: Unknown function\n");
        exit(1);
      }
    } else if (currentChar == 'c') {  // cos
      if (expression[i + 1] == 'o' && expression[i + 2] == 's') {
        while (!isEmpty(&operatorStack) &&
               getPriority(peek(&operatorStack)) >= getPriority(currentChar)) {
          push(&outputStack, pop(&operatorStack));
        }
        push(&operatorStack, currentChar);
        i += 2;
      } else {
        printf("Error: Unknown function\n");
        exit(1);
      }
    } else if (currentChar == 't') {  // tan
      if (expression[i + 1] == 'a' && expression[i + 2] == 'n') {
        while (!isEmpty(&operatorStack) &&
               getPriority(peek(&operatorStack)) >= getPriority(currentChar)) {
          push(&outputStack, pop(&operatorStack));
        }
        push(&operatorStack, currentChar);
        i += 2;
      } else {
        printf("Error: Unknown function\n");
        exit(1);
      }
    } else if (currentChar == 'a') {  // asin, acos and atan
      if (expression[i + 1] == 's' && expression[i + 2] == 'i' &&
          expression[i + 3] == 'n') {
        currentChar = 'S';
        while (!isEmpty(&operatorStack) &&
               getPriority(peek(&operatorStack)) >= getPriority(currentChar)) {
          push(&outputStack, pop(&operatorStack));
        }
        push(&operatorStack, currentChar);
        i += 3;
      } else if (expression[i + 1] == 'c' && expression[i + 2] == 'o' &&
                 expression[i + 3] == 's') {
        currentChar = 'C';
        while (!isEmpty(&operatorStack) &&
               getPriority(peek(&operatorStack)) >= getPriority(currentChar)) {
          push(&outputStack, pop(&operatorStack));
        }
        push(&operatorStack, currentChar);
        i += 3;
      } else if (expression[i + 1] == 't' && expression[i + 2] == 'a' &&
                 expression[i + 3] == 'n') {
        currentChar = 'T';
        while (!isEmpty(&operatorStack) &&
               getPriority(peek(&operatorStack)) >= getPriority(currentChar)) {
          push(&outputStack, pop(&operatorStack));
        }
        push(&operatorStack, currentChar);
        i += 3;
      } else {
        printf("Error: Unknown function\n");
        exit(1);
      }
    } else if (currentChar == 'l') {  // log and ln
      if (expression[i + 1] == 'o' && expression[i + 2] == 'g') {
        while (!isEmpty(&operatorStack) &&
               getPriority(peek(&operatorStack)) >= getPriority(currentChar)) {
          push(&outputStack, pop(&operatorStack));
        }
        push(&operatorStack, currentChar);
        i += 2;
      } else if (expression[i + 1] == 'n') {
        currentChar = 'L';
        while (!isEmpty(&operatorStack) &&
               getPriority(peek(&operatorStack)) >= getPriority(currentChar)) {
          push(&outputStack, pop(&operatorStack));
        }
        push(&operatorStack, currentChar);
        i += 1;
      } else {
        printf("Error: Unknown function\n");
        exit(1);
      }
    }
  }

  while (!isEmpty(&operatorStack)) {
    push(&outputStack, pop(&operatorStack));
  }

  char *result = (char *)malloc((outputStack.top + 2) * sizeof(char));
  for (int j = 0; j <= outputStack.top; j++) {
    result[j] = outputStack.data[j];
  }
  result[outputStack.top + 1] = '\0';
  return result;
}

// Вычисления
double evaluateRPN(char *expression) {
  DoubleStack numberStack;
  initDoubleStack(&numberStack);
  size_t i;
  for (i = 0; i < strlen(expression); i++) {
    char currentChar = expression[i];
    if ((currentChar >= '0' && currentChar <= '9') || currentChar == '.') {
      double number = currentChar - '0';
      while (expression[i + 1] >= '0' && expression[i + 1] <= '9') {
        number = number * 10 + expression[i + 1] - '0';
        i++;
      }
      if (expression[i + 1] == '.') {
        int j = -1;
        i++;
        while (expression[i + 1] >= '0' && expression[i + 1] <= '9') {
          number = number + (expression[i + 1] - '0') * pow(10, j);
          j = j - 1;
          i++;
        }
      }
      pushDouble(&numberStack, number);
    } else if (currentChar == '+' || currentChar == '-' || currentChar == '*' ||
               currentChar == '/' || currentChar == '^' || currentChar == '%') {
      double operand2 = popDouble(&numberStack);
      double operand1 = popDouble(&numberStack);
      double result;
      switch (currentChar) {
        case '+':
          result = operand1 + operand2;
          break;
        case '-':
          result = operand1 - operand2;
          break;
        case '*':
          result = operand1 * operand2;
          break;
        case '/':
          if (operand2 == 0) {
            printf("Error: Division by zero\n");
          }
          result = operand1 / operand2;
          break;
        case '^':
          result = pow(operand1, operand2);
          break;
        case '%':
          if (operand2 == 0) {
            printf("Error: Division by zero\n");
          }
          result = fmod(operand1, operand2);
          break;
      }
      pushDouble(&numberStack, result);

    } else if (currentChar == '_') {
      double number = popDouble(&numberStack);
      number = number * -1;
      pushDouble(&numberStack, number);
    } else if (currentChar == 's' || currentChar == 'c' || currentChar == 't' ||
               currentChar == 'S' || currentChar == 'C' || currentChar == 'T' ||
               currentChar == 'q' || currentChar == 'l' || currentChar == 'L') {
      double operand = popDouble(&numberStack);
      if (isnan(operand)) {
        return NAN;
      }
      double result;
      switch (currentChar) {
        case 's':
          result = sin(operand);
          break;
        case 'c':
          result = cos(operand);
          break;
        case 't':
          result = tan(operand);
          break;
        case 'S':
          result = asin(operand);
          break;
        case 'C':
          result = acos(operand);
          break;
        case 'T':
          result = atan(operand);
          break;
        case 'q':
          result = sqrt(operand);
          break;
        case 'l':
          result = log10(operand);
          break;
        case 'L':
          result = log(operand);
          break;
      }
      pushDouble(&numberStack, result);
    }
  }

  return popDouble(&numberStack);
}
