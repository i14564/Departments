// Copyright 2015 <Artem Krinitsyn>
#define _CRT_SECURE_NO_WARNINGS
#include "Exceptions.h"
#include <string>
#include "Employee.h"

EmployeeNotFound::EmployeeNotFound(const int id) {
    this->id = id;
}
EmployeeNotFound::~EmployeeNotFound() {
}

const char* EmployeeNotFound::what() const {
    char* c_what = new char[40];
    _snprintf(c_what, 40*sizeof(char), "Employee with id = %d not found", id);
    return c_what;
}

EmployeeAlreadyExist::EmployeeAlreadyExist(const Employee& a) {
    this->out = "Employee " + a.get_name() + " already exist";
}

EmployeeAlreadyExist::~EmployeeAlreadyExist() {
}

const char* EmployeeAlreadyExist::what() const {
    return out.c_str();
}
