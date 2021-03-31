#ifndef RK_H
#define RK_H


class RK
{
public:
  RK();
 static int* ReadFile(int* a,int N);
 static bool Savedata(int* arr, int N);

 static void FirstTask(int N);
 static void SecondTask(int N);
 static void ThirdTask();
 static void FourthTask();
 static char* ToH(char* chislo,char* NewChislo);
 static char* ToD(char* chislo,char* NewChislo);
};
#endif // RK_H
