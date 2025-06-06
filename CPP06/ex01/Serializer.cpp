#include "Serializer.hpp"

uintptr_t  Serializer::serialize(Data* ptr) {
	uintptr_t serializePtr = reinterpret_cast<uintptr_t>(ptr);
	return serializePtr;
}

Data* Serializer::deserialize(uintptr_t raw) {
	Data* deserializedPtr = reinterpret_cast<Data*>(raw);
	return deserializedPtr;
}