//�����: ������ �.�. ���-23
// 
//������������ ���� ��� ������������ ��������
namespace namespace_array {

	//���������� ������� � �������, ��� arr-��������� �� ������, size-������ �������
	template <typename T>
	input_mass(T* arr, T size);

	//���������� ������� ���������� �������, ��� arr-��������� �� ������, size-������ �������, 
	//min,max-����������� � ������������ ����� ��� ������������ (�������� ��������� �����)
	template <typename T>
	rand_mass(T* arr, size_t size, T min, T max);

	//����� �������, ��� arr-��������� �� ������, size-������ �������
	template <typename T>
	print_mass(T* arr, T size);

	//������������ ����� �������, ���� ������������, ��� arr-��������� �� ������, 
	//size-������ �������
	template <typename T>
	result_mass(T* arr, T size);

	//������ � ����, ��� arr - ��������� �� ������, size - ������ �������
	//���������� �������� ���� "C:\\Users\\Maestro-V\\Desktop\\�����\\�����\\result.txt"
	template <typename T>
	write_mass_to_file(T* arr, size_t size);

	// ���������� ������� �� ����� "C:\\Users\\Maestro-V\\Desktop\\�����\\�����\\result.txt", 
	// ��� arr - ��������� �� ������, size - ������ �������
	template <typename T>
	read_mass_from_file(T* arr, size_t size);
}

//������������ ���� ��� ��������
namespace namespace_vector {
	//���������� ������� � �������, ��� vec-��������� �� ������
	template <typename T>
	input_mass(std::vector<T>& vec);

	//���������� ������� ���������� �������, ��� vec-��������� �� ������, size-������ �������, 
	//min,max-����������� � ������������ ����� ��� ������������ (�������� ��������� �����)
	template <typename T>
	rand_mass(std::vector<T>& vec, T size, const T min, const T max);

	//����� �������, ��� vec-��������� �� ������
	template <typename T>
	print_mass(const std::vector<T>& vec);

	//������������ ����� �������, ���� ������������, ��� vec-��������� �� ������
	template <typename T>
	result_mass(const std::vector<T>& vec);

	//������ ������� � ����, ��� vec-��������� �� ������, 
	//���������� �������� ���� "C:\\Users\\Maestro-V\\Desktop\\�����\\�����\\result.txt"
	template <typename T>
	write_mass_to_file(const std::vector<T>& vec, const std::string& filename);

	//���������� ������� �� �����, ��� vec-��������� �� ������
	template <typename T>
	read_mass_from_file(std::vector<T>& vec, const std::string& filename);
}