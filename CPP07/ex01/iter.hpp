#pragma once
#include <iostream>

template<typename T, typename Func>
void iter(T* address, size_t size, Func func) {
	for (size_t i = 0; i < size; ++i) {
		func(address[i]);
	}
}