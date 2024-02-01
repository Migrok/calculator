#ifndef S21_SMART_CALC_H
#define S21_SMART_CALC_H

#define MAX_SIZE 1000

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  char data[MAX_SIZE];
  int top;
} Stack;

void initStack(Stack* stack);
int isEmpty(Stack* stack);
int isFull(Stack* stack);
void push(Stack* stack, char element);
char pop(Stack* stack);
char peek(Stack* stack);

typedef struct {
  double data[MAX_SIZE];
  int top;
} DoubleStack;

void initDoubleStack(DoubleStack* stack);
int isDoubleStackEmpty(DoubleStack* stack);
int isDoubleStackFull(DoubleStack* stack);
void pushDouble(DoubleStack* stack, double element);
double popDouble(DoubleStack* stack);
double peekDouble(DoubleStack* stack);

int getPriority(char operat);
char* convertToRPN(const char* expression);
double evaluateRPN(char* expression);

#ifdef __cplusplus
}
#endif

#endif
