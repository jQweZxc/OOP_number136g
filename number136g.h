//јвтор:  араев Ћ.ѕ. »¬“-23
// 
//ѕространство имен дл€ динамических массивов
namespace namespace_array {

	//заполнение массива с консоли, где arr-указатель на массив, size-размер массива
	template <typename T>
	input_mass(T* arr, T size);

	//«аполнение массива случайными числами, где arr-указатель на массив, size-размер массива, 
	//min,max-минимальное и максимальное число дл€ рандомайзера (диапазон случайных чисел)
	template <typename T>
	rand_mass(T* arr, size_t size, T min, T max);

	//вывод массива, где arr-указатель на массив, size-размер массива
	template <typename T>
	print_mass(T* arr, T size);

	//перемножение чисел массива, нули игнорируютс€, где arr-указатель на массив, 
	//size-размер массива
	template <typename T>
	result_mass(T* arr, T size);

	//«апись в файл, где arr - указатель на массив, size - размер массива
	//записываем указыва€ путь "C:\\Users\\Maestro-V\\Desktop\\учЄба\\прога\\result.txt"
	template <typename T>
	write_mass_to_file(T* arr, size_t size);

	// «аполнение массива из файла "C:\\Users\\Maestro-V\\Desktop\\учЄба\\прога\\result.txt", 
	// где arr - указатель на массив, size - размер массива
	template <typename T>
	read_mass_from_file(T* arr, size_t size);
}

//ѕространство имен дл€ векторов
namespace namespace_vector {
	//заполнение вектора с консоли, где vec-указатель на массив
	template <typename T>
	input_mass(std::vector<T>& vec);

	//«аполнение вектора случайными числами, где vec-указатель на массив, size-размер массива, 
	//min,max-минимальное и максимальное число дл€ рандомайзера (диапазон случайных чисел)
	template <typename T>
	rand_mass(std::vector<T>& vec, T size, const T min, const T max);

	//вывод массива, где vec-указатель на массив
	template <typename T>
	print_mass(const std::vector<T>& vec);

	//перемножение чисел массива, нули игнорируютс€, где vec-указатель на массив
	template <typename T>
	result_mass(const std::vector<T>& vec);

	//запись вектора в файл, где vec-указатель на массив, 
	//записываем указыва€ путь "C:\\Users\\Maestro-V\\Desktop\\учЄба\\прога\\result.txt"
	template <typename T>
	write_mass_to_file(const std::vector<T>& vec, const std::string& filename);

	//заполнение вектора из файла, где vec-указатель на массив
	template <typename T>
	read_mass_from_file(std::vector<T>& vec, const std::string& filename);
}