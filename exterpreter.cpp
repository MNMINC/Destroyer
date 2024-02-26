#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main()
{
  ofstream ofs;
  ofs.open("token.txt");
  if (!ofs){
    cerr << "File open Error \n";
    exit(0);
  }
    
  bool c1 = true;
  bool c2 = true;
  for (int i = 0; i < 100; ++i) 
  {
    ofs << i << ":";
    bool e1 = false;
    bool e2 = false;
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
        }
      }
    }
    ofs << e1 << e2 << "/";
    if (!e1) 
      c1 = false;
    if (!e2) 
      c2 = false;
  }
  ofs << c1 << c2;
}

bool IsPrime(int n) 
{
  for (int f = 2; f < n; ++f)
    if (n % f == 0)
      return false; 
  return true;
}