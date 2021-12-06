# Go to link

https://www.javatpoint.com/cpp-algorithm-rotate-function

```
    #include <algorithm>  
    #include <iostream>  
    #include <string>  
      
    using namespace std;  
      
    int main() {  
      string str = "Hello";  
      cout << "Before Rotate : "<< str << endl;  
        
      rotate(str.begin(), str.begin() + 2, str.end());  
      cout <<"After Rotate  : " << str << endl;  
        
      return 0;  
    }  
```
Before Rotate : Hello
After Rotate  : lloHe