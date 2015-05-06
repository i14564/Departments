// Copyright 2015 <Artem Krinitsyn>
#define _CRT_SECURE_NO_WARNINGS
#include "Exceptions.h"
#include <string>
#include "Employee.h"


EmployeeNotFound::EmployeeNotFound() {
}

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

EmployeeAlreadyExist::EmployeeAlreadyExist() {
}

EmployeeAlreadyExist::EmployeeAlreadyExist(const Employee &a) {
    Employee out(a);
    this->name = out.get_name();
}

EmployeeAlreadyExist::~EmployeeAlreadyExist() {
}

const char* EmployeeAlreadyExist::what() const {
    char* c_what = new char[40];
    _snprintf(c_what, 40*sizeof(char),
    "Employee %s not found", this->name.c_str());
    return c_what;
}
