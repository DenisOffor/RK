#include "rk.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <time.h>
#include <QCoreApplication>
#include <qmath.h>

RK::RK()
{

}
int* RK::ReadFile(int* a,int N)
{
  QFile file("C:\\Users\\Public\\Sortirovki.txt");
  file.open(QIODevice::ReadOnly);
  QTextStream out(&file);
  for(int i=0;i<N;i++)
    out>>a[i];
  file.close();
  return a;
}

bool RK::Savedata(int *arr, int N)
{
  QFile file("C:\\Users\\Public\\Arr.txt");
  if(!(file.open(QIODevice::WriteOnly)))
  return false;
  QTextStream in(&file);
  for(int i=0;i<N;i++)
    in<<arr[i]<<"\n";
  file.close();
  return true;
}

void RK::FirstTask(int N)
{
    int* kucha=new int[N];
    RK::ReadFile(kucha,N);
    float E;
    int m1,m2,m;
    for(int i=0;i<N;i++)
      m+=kucha[i];
    E= m / N;
    m1=kucha[0];
    m2=kucha[1];
    for(int i=2;i<N;i++)
      if(abs(2-m1)<E)           //ЗАДАЧА 1
        {
        m1+=kucha[i];
        m2+=kucha[i+1];
        }
      else{
        if(m2>m1)
          m1+=kucha[i];
              else
              m2+=kucha[i];
        }
    delete[] kucha;

}

void RK::SecondTask(int N)
{
    srand(time(0));
  int* array = new int[N];
  for(int i=0;i<N;i++)
    array[i]=rand()%20;
  for(int i = 0;i<N;i++)
    {
    for(int j = 0;j<N;j++)
      if(array[j]==array[i] && i!=j){
                     array[i]=rand()%20;
                      for(int k = 0;k<N;k++)       //ЗАДАЧА 2
                        if(array[i]==array[k])
                         j=-1;
    }
    }
    RK::Savedata(array,N);
    delete [] array;
}

void RK::ThirdTask()
{
    int x1=1;
    while(x1!=0)
      {
        int x2,y1,y2;
        std::cout<<"Input one:";
        std::cin>>x1>>y1;
        std::cout<<"Input two:";
        std::cin>>x2>>y2;
        if(x1<9 && x2<9 && y1<9 && y2<9)                   //ЗАДАЧА 3
          {
            std::cin>>x2>>y2;
            if(x1+y1==x2+y2 || abs(x1-y1)==abs(x2-y2))
              std::cout<<"Woooooooooooooooooow"<<"\n";
            if(x1-y1==-(x2-y2) && x1!=y1 && x1 !=y2 && x2!=y1)
              std::cout << "Wow"<<"\n";
          }
      }
}

void RK::FourthTask()
{
  char* NewChislo = new char;
  char* chislo = new char;
 std::cin>>chislo;
  if(chislo[0] == 'd')
   ToH(chislo+1,NewChislo);
  else
    ToD(chislo+1, NewChislo);
  std::cout<< NewChislo;
  delete NewChislo;
}


char* RK::ToH(char* chislo,char* NewChislo)
{
  int s = atoi(chislo);
  int s2=s;
  int N = 0;
  NewChislo[0]= 'h';
  while(s2!=0)
    {N++;
    s2/=16;}
  while(s!=0)
    {
      if(s%16<10)
        NewChislo[N--]=s%16+48;
      if(s%16>=10)
        NewChislo[N--]=s%16+55;
      s/=16;
    }
  return NewChislo;
}

char* RK::ToD(char* chislo,char* NewChislo)
{
  int N = strlen(chislo)-1;
  int i=0;
  NewChislo[0]='d';
  int NewD=0;
  int s=0;
  while(N!=-1)
    {
     if(chislo[N]>64)
       NewD = chislo[N] - 55;
     else
       NewD= chislo[N]-48;
    s+=NewD*pow(16,i++);
    N--;
   }
  itoa(s,(NewChislo+1),10);
  return NewChislo;
}

int strlen(char* String)
{
  int iter=0;
  while(String[iter] != '\0')
        iter++;
  return iter;
}
