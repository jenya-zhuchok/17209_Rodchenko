#pragma once

#include "Header.h"


class Value {
private:
	std::string name;
	unsigned int age;
	unsigned int weight;

public:
	Value();
	Value(const Key name, unsigned int a, unsigned int w);
	Value(const Value& v);
	~Value();
	void operator=(const Value& v);

	std::string get_name() const;
	unsigned int get_age() const;
	unsigned int get_weight() const;


	bool operator==(const Value& v) const;
	bool operator==(Value *v) const;

	bool operator!=(Value& v) const;
	bool operator!=(Value *v) const;
};
