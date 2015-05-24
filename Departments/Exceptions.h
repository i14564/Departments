// Copyright 2015 <Krinitsyn Artem>
#pragma once

#include <exception>
#include <string>
#include "Employee.h"

class EmployeeNotFound : public std::exception {
 public:
    explicit EmployeeNotFound(const int id);
    ~EmployeeNotFound();
    const char* what() const;
 private:
     int id;
};

class EmployeeAlreadyExist : public std::exception {
 public:
    explicit EmployeeAlreadyExist(const Employee& a);
    ~EmployeeAlreadyExist();
    const char* what() const;
 private:
    std::string out;
};


