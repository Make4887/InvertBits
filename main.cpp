#include <iostream>
#include <array>
#include <bitset>

using namespace std;

void InvertBits(uint8_t* begin, uint64_t size, bool even) {
	uint8_t* end = begin + size;
	uint8_t mask;
	if (even) {
		mask = 0b01010101;
	}
	else {
		mask = 0b10101010;
	}
	for (; begin != end; ++begin) {
		*begin ^= mask;
	}
}

int main() {
	array<uint8_t, 5> data = { 0xFF, 0x00, 0xF0, 0xAB, 0xA0};

	std::cout << "Original data:" << std::endl;
	for (int i = 0; i < sizeof(data); i++) {
		std::cout << std::bitset<8>(data[i]) << ' ';
	}
	std::cout << std::endl;

	std::cout << "Invert even bits in data:" << std::endl;
	InvertBits(&data[0], sizeof(data), true);
	for (int i = 0; i < sizeof(data); i++) {
		std::cout << std::bitset<8>(data[i]) << ' ';
	}
	std::cout << std::endl;

	std::cout << "Invert odd bits in data:" << std::endl;
	InvertBits(&data[0], sizeof(data), false);
	for (int i = 0; i < sizeof(data); i++) {
		std::cout << std::bitset<8>(data[i]) << ' ';
	}
	std::cout << std::endl;

	return 0;
}