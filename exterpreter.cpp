#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int primary = 20;

bool IsPrime(int n) 
{
  for (int f = 2; f < n; ++f)
    if (n % f == 0)
      return false; 
  return true;
}

bool SharesFactors(int n1, int n2)
{
  int factors1[primary];
  int factors2[primary];
  for(int i = 0; i < primary; i++) {
    factors1[i] = 0;
    factors2[i] = 0;
  }
  int c = 0;
  for (int f = 2; f < n1; ++f)
    if (n1 % f == 0)
    {
      factors1[c] = f;
      c++;
    }

  c = 0;
  for (int f = 2; f < n2; ++f)
    if (n2 % f == 0)
    {
      factors2[c] = f;
      c++;
    }

  for (int f1 = 0; f1 < primary; ++f1)
    for (int f2 = 0; f2 < primary; ++f2)
      if (factors1[f1] == factors2[f2] && factors1[f1] != 0 && factors1[f1] != 1)
        return true;
  return false;

}

int main()
{
  ofstream ofs;
  ofs.open("token.file");
  if (!ofs){
    cerr << "The file could not be oppened :(\n";
    exit(0);
  }
    
  bool c1 = true;
  bool c2 = true;
  bool c3 = true;
  for (int i = 0; i < primary; ++i) 
  {
    ofs << i << ":";
    bool e1 = false;
    bool e2 = false;
    bool e3 = false;
    for (int s1 = 0; s1 < i; ++s1)
    {    
      for (int s2 = 0; s2 < i; ++s2)
      {      
        for (int s3 = 0; s3 < i; ++s3)
        {
          if (pow(s1, 3) + pow(s2, 3) + pow(s3, 3) == pow(i, 3))
          {
            ofs << s1 << "." << s2 << "." << s3 << "|";
            e1 = true;
          }
          if (IsPrime(s1) && IsPrime(s2) && IsPrime(s3) && s1 + s2 + s3 == i)
          {
            ofs << s1 << "-" << s2 << "-" << s3 << "|";
            e2 = true;
          }
          if (s1 * s2 * s3 != 0 && !SharesFactors(s1 * s2 * s3, i) && SharesFactors(i % s1 * i % s2 * i % s3, i))
          {
            ofs << s1 << "*" << s2 << "*" << s3 << "|";
            e3 = true;
          }
        }
      }
    }
    ofs << e1 << e2 << e3 << "/";
    if (!e1) 
      c1 = false;
    if (!e2) 
      c2 = false;
    if (!e3) 
      c3 = false;
  }
  ofs << c1 << c2 << c3;
  /*for (int i = 0; i < primary; ++i)
  {
    double chip;
    do
    {
      chip = (rand() % primary);
    } while (chip == 0);
    
    chip = log(2 / (1 / chip + 1) - 1) / -2;
    ofs << chip;
  }*/
}
