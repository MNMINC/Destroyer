#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool IsPrime(int n) 
{
  for (int f = 2; f < n; ++f)
    if (n % f == 0)
      return false; 
  return true;
}

int main()
{
  ofstream ofs;
  ofs.open("token.file");
  if (!ofs){
    cerr << "The file could not be oppened :(\n";
    exit(0);
  }
  int primary = 10;
    
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
          if (s1 * s2 * s3 != 0 && (i % s1 + i % s2 + i % s3) == i)
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
