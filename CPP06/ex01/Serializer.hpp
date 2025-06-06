#pragma once
#include <iostream>
#include <cstdint>

struct Data {
	std::string mes;
	int num;
};

class Serializer {
	public:
		Serializer() = delete;
		~Serializer() = delete;
		Serializer(Serializer const& copy) = delete;
		Serializer& operator=(Serializer const& copy) = delete;

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};