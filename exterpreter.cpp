#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ofstream ofs;
  ofs.open("token.txt");
  if (!ofs){
    cerr << "File open Error \n";
    exit(0);
  }
    
  for (int i = 0; i < 100; ++i) 
  {
    ofs << i;
    for (int s1 = 0; s1 < i; ++s1)
    {    
      for (int s2 = 0; s2 < i; ++s2)
      {      
        for (int s3 = 0; s3 < i; ++s3)
        {
          if (s1 * s1 * s1 + s2 * s2 * s2 + s3 * s3 * s3 == i * i * i)
          {
            ofs << s1 << s2 << s3;
          }
        }
      }
    }
  }
}

bool IsPrime(int n) 
{
  for (int f = 2; f < n; ++f)
    if (n % f == 0)
      return false; 
  return true;
}