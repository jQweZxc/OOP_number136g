//Автор: Караев Л. П. ИВТ-23
#include <iostream>
#include <cstdlib> // для функции rand()
#include <ctime> // для инициализации генератора случайных чисел
#include <cassert> // для assert
#include <cmath> // для функции abs
#include <random> // Для рандомных чисел
#include <fstream> //библиотека для работы с текстовыми файлами
#include <vector> // для vector
#include "number136.h" // подключаемый модуль
//Вектор - это контейнер, который хранит элементы одного типа в динамически изменяемом массиве.
//Векторы автоматически управляют памятью, что уменьшает риск утечек памяти и делает работу с ними более удобной.


int main() {
	//constexpr — это спецификатор в C++, который указывает, 
	//что значение переменной или результат функции может быть вычислен во время компиляции.
	constexpr int min = 1;
	constexpr int max = 15;
	size_t size = 5;

	//Проверка №1
	int* test1 = new int[size]; // выделяем память для динамического массива
	// инициализируем массив
	test1[0] = 1;
	test1[1] = 2;
	test1[2] = 3;
	test1[3] = 4;
	test1[4] = 5;
	assert(fabs(namespace_array::result_mass(test1, size) - 120) < 0.00000001);

	//Проверка №2
	int* test2 = new int[size]; // выделяем память для динамического массива
	// инициализируем массив
	test2[0] = -3;
	test2[1] = 2;
	test2[2] = 4;
	test2[3] = 7;
	test2[4] = -5;
	assert(fabs(namespace_array::result_mass(test2, size) - 840) < 0.00000001);

	//Проверка №3
	int* test3 = new int[size]; // выделяем память для динамического массива
	// инициализируем массив
	test3[0] = 2;
	test3[1] = 6;
	test3[2] = 7;
	test3[3] = 12;
	test3[4] = 9;
	assert(fabs(namespace_array::result_mass(test3, size) - 9072) < 0.00000001);

	std::cout << "Enter size array: ";
	std::cin >> size; //размер массива

	int* array = new int[size]; // создаем динамический массив
	if (array == nullptr) { //проверка на успешно выделенную память (массив пустой)
		std::cerr << "Memory allocation failed!" << std::endl;
		return 1;
	}

	try {
		namespace_array::rand_mass(array, size, min, max); //заполнение массива случайными числами
		//namespace_array::input_mass(array, size); //заполнение массива с консоли

		namespace_array::print_mass(array, size); //вывод массива
		namespace_array::write_mass_to_file(array, size); //запись в файл

		namespace_array::read_mass_from_file(array, size);//заполнение массива из файла

		const int result = namespace_array::result_mass(array, size);
		std::cout << "Result: " << fabs(result) << std::endl; //вывод результата

	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		delete[] array; //освобождаем память
		return 1;
	}
	delete[] array; //освобождаем память

	return 0;
}