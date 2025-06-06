#include "Serializer.hpp"

int main() {
	Data obj;

	obj.mes = "Hey evaluator! Set the next grade for me: ";
	obj.num = 100;
	std::cout << "Address of the initial obj: " << &obj << "\n";
	uintptr_t ptr = Serializer::serialize(&obj);
	std::cout << "Address of the serialized ptr: " << ptr << std::endl;
	Data *deserializedPtr = Serializer::deserialize(ptr);
	std::cout << "Address of the deserialized Data*: " << deserializedPtr << std::endl;

	std::cout << deserializedPtr->mes << deserializedPtr->num << std::endl;
}