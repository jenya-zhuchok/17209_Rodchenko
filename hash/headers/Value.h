#pragma once

#include "Header.h"

struct Value {
private:
	string name;
	unsigned int age;
	unsigned int weight;

public:
	Value();
	Value(const Key name, unsigned int a, unsigned int w);
	Value(const Value& v);
	~Value();
	Value& operator=(const Value& v);

	bool operator==(Value& v) const;
	bool operator==(Value *v) const;

	bool operator!=(Value& v) const;
	bool operator!=(Value *v) const;
};
