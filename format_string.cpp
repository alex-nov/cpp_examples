#include <iostream>
#include <cstring>

int main()
{
    size_t size = 4;
    char mass[size][100] = { "%s %s %s" , "one", "two", "three"};
    
    char rezult[100] = "%s %s %s";

//    char * formater = mass[0];
    for( int i = 1; i < size; ++i )
    {
        char tmp[100] = {};
        std::cout << mass[i] << std::endl;
        sprintf(tmp, "%s %s %s", mass[i]);
        std::cout << i << ": " << tmp << std::endl;
        //strcpy(rezult, tmp);
    }
    return 0; 
}
