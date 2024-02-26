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
    
  ofs << name << score1 << score2;
}
