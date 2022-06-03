#include <iostream>

const char k_newline = '\n';

const int k_digit_divisor = 10;

const int k_digit_conversion = 10;

const int k_max_size = 9;

const int k_maximum_isbn = 999999999;

const char k_digit_replacer = 'X';

int main()
{
	std::cout << "Enter the first nine digits of the ISBN > ";
	auto number = 0;
	std::cin >> number;

	while (std::cin.fail() || number > k_maximum_isbn || number <= 0)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), k_newline);
		std::cout << "Invalid entry" << std::endl;
		std::cout << "Enter the first nine digits of the ISBN > ";
		std::cin >> number;
	}
	
	auto sum = 0;
	auto working_copy = number;
	for (auto counter = k_max_size; counter >= 1; counter--)
	{
		auto digit = working_copy % k_digit_divisor;
		working_copy /= k_digit_divisor;
		auto working_number = counter * digit;
		sum = sum + working_number;
	}

	auto checksum_digit = sum % 11;
	
	if (checksum_digit == k_digit_conversion)
	{
		auto k_digit_conversion = k_digit_replacer;
	} //else, display digit. do_nothing();

	std::cout << " The final ISBN-10 number is > " << number + checksum_digit << std::endl;

	return 0;
}