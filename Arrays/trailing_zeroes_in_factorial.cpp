 #include <iostream> 
using namespace std; 
  
int findTrailingZeros(int n) 
{ 
    int count=0;
    int i=5;
    while(i<=n)
    {
        count=count+(n/i);
        i=i*5;
    }
    return count;
} 

int main() 
{ 
    int n = 100; 
    cout << "Count of trailing 0s in " << 100 
         << "! is " << findTrailingZeros(n); 
    return 0; 
}