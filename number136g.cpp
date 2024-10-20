//Автор: Караев Л. П. ИВТ-23

#include <iostream>
#include <cstdlib> // для функции rand()
#include <ctime> // для инициализации генератора случайных чисел
#include <cassert> // для assert
#include <cmath> // для функции abs
#include <random> // Для рандомных чисел
#include <fstream> //библиотека для работы с текстовыми файлами
#include <vector> // для vector
#include "number136g.h" // подключаем модуль
//Вектор - это контейнер, который хранит элементы одного типа в динамически изменяемом массиве.
//Векторы автоматически управляют памятью, что уменьшает риск утечек памяти и делает работу с ними более удобной.

//Пространство имен для динамических массивов
namespace namespace_array {
	//заполнение массива с консоли, где arr-указатель на массив, size-размер массива
	template <typename T>
	void input_mass(T* arr, size_t size) {
		std::cout << "Enter numbers: " << std::endl;
		for (int i = 0; i < size; i++) {
			std::cin >> arr[i];
		}
	}

	//Заполнение массива случайными числами, где arr-указатель на массив, size-размер массива, 
	//min,max-минимальное и максимальное число для рандомайзера (диапазон случайных чисел)
	template <typename T>
	void rand_mass(T* arr, size_t size, T min, T max) {
		// Инициализируем генератор случайных чисел
		srand(static_cast<unsigned int>(time(0)));
		// Заполняем массив случайными числами
		for (int i = 0; i < size; i++) {
			arr[i] = min + rand() % (max - min + 1);
		}
	}

	//вывод массива, где arr-указатель на массив, size-размер массива
	template <typename T>
	void print_mass(T* arr, size_t size) {
		// Выводим массив на экран по 10 элементов в строке
		for (int i = 0; i < size; i++) {
			std::cout << arr[i] << " ";
			if ((i + 1) % 10 == 0) {
				std::cout << std::endl;
			}
		}
		std::cout << std::endl;
	}

	//перемножение чисел массива, нули игнорируются, где arr-указатель на массив, 
	//size-размер массива, sum - все перемноженные числа
	template <typename T>
	int result_mass(T* arr, size_t size) {
		T sum = 1;
		for (int i = 0; i < size; i++) {
			if (arr[i] == 0) {
				break;
			}
			sum *= fabs(arr[i]);
		}
		return sum;
	}

	//Запись в файл, где arr - указатель на массив, size - размер массива
	//записываем указывая путь "C:\\Users\\Maestro-V\\Desktop\\учёба\\прога\\result.txt"
	template <typename T>
	void write_mass_to_file(T* arr, size_t size) {
		std::ofstream file("C:\\Users\\Maestro-V\\Desktop\\учёба\\прога\\result.txt");
		if (file.is_open()) {
			for (int i = 0; i < size; i++) {
				file << arr[i] << " ";
			}
			file.close();
			std::cout << "The array is written to a file." << std::endl;
		}
		else {
			std::cout << "The file could not be opened." << std::endl;
		}
	}

	// Заполнение массива из файла "C:\\Users\\Maestro-V\\Desktop\\учёба\\прога\\result.txt", 
	// где arr - указатель на массив, size - размер массива
	template <typename T>
	void read_mass_from_file(T* arr, size_t size) {
		std::ifstream file("C:\\Users\\Maestro-V\\Desktop\\учёба\\прога\\result.txt");
		if (file.is_open()) {
			for (int i = 0; i < size; i++) {
				if (!(file >> arr[i])) {
					std::cout << "Error reading from the file." << std::endl;
					break;
				}
			}
			file.close();
			std::cout << "The vector is filled from the file." << std::endl;
		}
		else {
			std::cout << "The file could not be opened." << std::endl;
		}
	}
}

//Пространство имен для vector
namespace namespace_vector {
	//заполнение вектора с консоли vec - указатель на массив, size - размер массива,
	//num - элементы массива
	template <typename T>
	void input_mass(std::vector<T>& vec, size_t size) {
		std::cout << "Enter numbers: " << std::endl;
		T num = 0;
		for (int i = 0; i < size; i++) {
			std::cin >> num;
			vec.push_back(num);
		}
	}

	//Заполнение вектор случайными числами, где vec-указатель на массив, size-размер массива, 
	//min,max-минимальное и максимальное число для рандомайзера (диапазон случайных чисел)
	template <typename T>
	void rand_mass(std::vector<T>& vec, size_t size, T min, T max) {
		// Инициализируем генератор случайных чисел
		std::random_device rd; // Получаем случайное значение
		std::mt19937 mt(rd()); // Инициализируем генератор
		std::uniform_int_distribution<int> dist(min, max);
		int random_number = dist(mt);
		// Заполняем массив случайными числами
		for (int i = 0; i < size; i++) {
			vec.push_back(dist(mt));
		}
	}

	//вывод вектора где vec-указатель на массив
	template <typename T>
	void print_mass(const std::vector<T>& vec) {
		// Выводим вектор на экран по 10 элементов в строке
		for (int i = 0; i < vec.size(); i++) {
			std::cout << vec[i] << " ";
			if ((i + 1) % 10 == 0) {
				std::cout << std::endl;
			}
		}
		std::cout << std::endl;
	}

	//перемножение чисел вектора нули игнорируются, где vec-указатель на массив, 
	//sum - все перемноженные числа
	template <typename T>
	int result_mass(const std::vector<T>& vec) {
		T sum = 1;
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i] == 0) {
				break;
			}
			sum *= fabs(vec[i]);
		}
		return sum;
	}
	//запись вектора в файл, где vec-указатель на массив, 
	//записываем указывая путь "C:\\Users\\Maestro-V\\Desktop\\учёба\\прога\\result.txt"
	template <typename T>
	void write_mass_to_file(const std::vector<T>& vec) {
		std::ofstream file("C:\\Users\\Maestro-V\\Desktop\\учёба\\прога\\result.txt");
		if (file.is_open()) {
			for (int i = 0; i < vec.size(); i++) {
				file << vec[i] << " ";
			}
			file.close();
			std::cout << "The vector is written to a file " << std::endl;
		}
		else {
			std::cout << "The file could not be opened " << std::endl;
		}
	}

	//заполнение вектора из файла, где vec-указатель на массив, num - элементы массива
	template <typename T>
	void read_mass_from_file(std::vector<T>& vec) {
		std::ifstream file("C:\\Users\\Maestro - V\\Desktop\\учёба\\прога\\result.txt");
		if (file.is_open()) {
			T num;
			while (file >> num) {
				vec.push_back(num);
			}
			file.close();
			std::cout << "The vector is filled from the file " << std::endl;
		}
		else {
			std::cout << "The file could not be opened " << std::endl;
		}
	}
}