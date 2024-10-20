//�����: ������ �. �. ���-23
#include <iostream>
#include <cstdlib> // ��� ������� rand()
#include <ctime> // ��� ������������� ���������� ��������� �����
#include <cassert> // ��� assert
#include <cmath> // ��� ������� abs
#include <random> // ��� ��������� �����
#include <fstream> //���������� ��� ������ � ���������� �������
#include <vector> // ��� vector
#include "number136.h" // ������������ ������
//������ - ��� ���������, ������� ������ �������� ������ ���� � ����������� ���������� �������.
//������� ������������� ��������� �������, ��� ��������� ���� ������ ������ � ������ ������ � ���� ����� �������.


int main() {
	//constexpr � ��� ������������ � C++, ������� ���������, 
	//��� �������� ���������� ��� ��������� ������� ����� ���� �������� �� ����� ����������.
	constexpr int min = 1;
	constexpr int max = 15;
	size_t size = 5;

	//�������� �1
	int* test1 = new int[size]; // �������� ������ ��� ������������� �������
	// �������������� ������
	test1[0] = 1;
	test1[1] = 2;
	test1[2] = 3;
	test1[3] = 4;
	test1[4] = 5;
	assert(fabs(namespace_array::result_mass(test1, size) - 120) < 0.00000001);

	//�������� �2
	int* test2 = new int[size]; // �������� ������ ��� ������������� �������
	// �������������� ������
	test2[0] = -3;
	test2[1] = 2;
	test2[2] = 4;
	test2[3] = 7;
	test2[4] = -5;
	assert(fabs(namespace_array::result_mass(test2, size) - 840) < 0.00000001);

	//�������� �3
	int* test3 = new int[size]; // �������� ������ ��� ������������� �������
	// �������������� ������
	test3[0] = 2;
	test3[1] = 6;
	test3[2] = 7;
	test3[3] = 12;
	test3[4] = 9;
	assert(fabs(namespace_array::result_mass(test3, size) - 9072) < 0.00000001);

	std::cout << "Enter size array: ";
	std::cin >> size; //������ �������

	int* array = new int[size]; // ������� ������������ ������
	if (array == nullptr) { //�������� �� ������� ���������� ������ (������ ������)
		std::cerr << "Memory allocation failed!" << std::endl;
		return 1;
	}

	try {
		namespace_array::rand_mass(array, size, min, max); //���������� ������� ���������� �������
		//namespace_array::input_mass(array, size); //���������� ������� � �������

		namespace_array::print_mass(array, size); //����� �������
		namespace_array::write_mass_to_file(array, size); //������ � ����

		namespace_array::read_mass_from_file(array, size);//���������� ������� �� �����

		const int result = namespace_array::result_mass(array, size);
		std::cout << "Result: " << fabs(result) << std::endl; //����� ����������

	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		delete[] array; //����������� ������
		return 1;
	}
	delete[] array; //����������� ������

	return 0;
}