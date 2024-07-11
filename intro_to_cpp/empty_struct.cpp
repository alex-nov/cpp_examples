#include <iostream>

struct test_empty {
};


struct test1 {
  int t;
  char ch;
  double d;
};

struct test2 {
  int t;
  double d;
  char ch;
};

int main()
{
	/*
	Потому что два указателя на различные объекты обязаны быть различными.
	Если даже что-то может занимать 0 байт, то ему всё равно нужен уникальный адрес, а минимальным
	адресуемым пространством является байт.
	Вот и получается, что пустая структура занимает этот байт, хотя никак его не использует.
	*/
	std::cout << "empty " << sizeof(test_empty) << std::endl;
	std::cout << "test1 " << sizeof(test1) << std::endl;
	std::cout << "test2 " << sizeof(test2) << std::endl;

	return 0;
}

