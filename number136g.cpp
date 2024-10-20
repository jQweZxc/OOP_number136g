//�����: ������ �. �. ���-23

#include <iostream>
#include <cstdlib> // ��� ������� rand()
#include <ctime> // ��� ������������� ���������� ��������� �����
#include <cassert> // ��� assert
#include <cmath> // ��� ������� abs
#include <random> // ��� ��������� �����
#include <fstream> //���������� ��� ������ � ���������� �������
#include <vector> // ��� vector
#include "number136g.h" // ���������� ������
//������ - ��� ���������, ������� ������ �������� ������ ���� � ����������� ���������� �������.
//������� ������������� ��������� �������, ��� ��������� ���� ������ ������ � ������ ������ � ���� ����� �������.

//������������ ���� ��� ������������ ��������
namespace namespace_array {
	//���������� ������� � �������, ��� arr-��������� �� ������, size-������ �������
	template <typename T>
	void input_mass(T* arr, size_t size) {
		std::cout << "Enter numbers: " << std::endl;
		for (int i = 0; i < size; i++) {
			std::cin >> arr[i];
		}
	}

	//���������� ������� ���������� �������, ��� arr-��������� �� ������, size-������ �������, 
	//min,max-����������� � ������������ ����� ��� ������������ (�������� ��������� �����)
	template <typename T>
	void rand_mass(T* arr, size_t size, T min, T max) {
		// �������������� ��������� ��������� �����
		srand(static_cast<unsigned int>(time(0)));
		// ��������� ������ ���������� �������
		for (int i = 0; i < size; i++) {
			arr[i] = min + rand() % (max - min + 1);
		}
	}

	//����� �������, ��� arr-��������� �� ������, size-������ �������
	template <typename T>
	void print_mass(T* arr, size_t size) {
		// ������� ������ �� ����� �� 10 ��������� � ������
		for (int i = 0; i < size; i++) {
			std::cout << arr[i] << " ";
			if ((i + 1) % 10 == 0) {
				std::cout << std::endl;
			}
		}
		std::cout << std::endl;
	}

	//������������ ����� �������, ���� ������������, ��� arr-��������� �� ������, 
	//size-������ �������, sum - ��� ������������� �����
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

	//������ � ����, ��� arr - ��������� �� ������, size - ������ �������
	//���������� �������� ���� "C:\\Users\\Maestro-V\\Desktop\\�����\\�����\\result.txt"
	template <typename T>
	void write_mass_to_file(T* arr, size_t size) {
		std::ofstream file("C:\\Users\\Maestro-V\\Desktop\\�����\\�����\\result.txt");
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

	// ���������� ������� �� ����� "C:\\Users\\Maestro-V\\Desktop\\�����\\�����\\result.txt", 
	// ��� arr - ��������� �� ������, size - ������ �������
	template <typename T>
	void read_mass_from_file(T* arr, size_t size) {
		std::ifstream file("C:\\Users\\Maestro-V\\Desktop\\�����\\�����\\result.txt");
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

//������������ ���� ��� vector
namespace namespace_vector {
	//���������� ������� � ������� vec - ��������� �� ������, size - ������ �������,
	//num - �������� �������
	template <typename T>
	void input_mass(std::vector<T>& vec, size_t size) {
		std::cout << "Enter numbers: " << std::endl;
		T num = 0;
		for (int i = 0; i < size; i++) {
			std::cin >> num;
			vec.push_back(num);
		}
	}

	//���������� ������ ���������� �������, ��� vec-��������� �� ������, size-������ �������, 
	//min,max-����������� � ������������ ����� ��� ������������ (�������� ��������� �����)
	template <typename T>
	void rand_mass(std::vector<T>& vec, size_t size, T min, T max) {
		// �������������� ��������� ��������� �����
		std::random_device rd; // �������� ��������� ��������
		std::mt19937 mt(rd()); // �������������� ���������
		std::uniform_int_distribution<int> dist(min, max);
		int random_number = dist(mt);
		// ��������� ������ ���������� �������
		for (int i = 0; i < size; i++) {
			vec.push_back(dist(mt));
		}
	}

	//����� ������� ��� vec-��������� �� ������
	template <typename T>
	void print_mass(const std::vector<T>& vec) {
		// ������� ������ �� ����� �� 10 ��������� � ������
		for (int i = 0; i < vec.size(); i++) {
			std::cout << vec[i] << " ";
			if ((i + 1) % 10 == 0) {
				std::cout << std::endl;
			}
		}
		std::cout << std::endl;
	}

	//������������ ����� ������� ���� ������������, ��� vec-��������� �� ������, 
	//sum - ��� ������������� �����
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
	//������ ������� � ����, ��� vec-��������� �� ������, 
	//���������� �������� ���� "C:\\Users\\Maestro-V\\Desktop\\�����\\�����\\result.txt"
	template <typename T>
	void write_mass_to_file(const std::vector<T>& vec) {
		std::ofstream file("C:\\Users\\Maestro-V\\Desktop\\�����\\�����\\result.txt");
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

	//���������� ������� �� �����, ��� vec-��������� �� ������, num - �������� �������
	template <typename T>
	void read_mass_from_file(std::vector<T>& vec) {
		std::ifstream file("C:\\Users\\Maestro - V\\Desktop\\�����\\�����\\result.txt");
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