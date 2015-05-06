// Copyright 2015 <Artem Krinitsyn>
#pragma once

#include <vector>
#include <string>
#include "Employee.h"

class Department : public std::vector < Employee > {
 public:
    Department();
    ~Department();
    Department(const std::string name, const int id, const int adjacent_id);
    Department(const Department &a);

    void add(const Employee &e);
    void add(const std::string name, int salary, int age);

    void remove(const int id);
    const bool has(const Employee &a);

    void set_name(const std::string name);
    const std::string get_name();

    void set_id(const int id);
    const int get_id();

    void print();

    void set_head(const int id);
    const int get_head();

    void generate();

    void set_adjacent(const int id);
    const int get_adjacent();

    void add_vacation(const int days);
    void leave_of_absence(const int days);

    const int get_Count();

    Department & operator=(const Department &a);

    friend Department operator+ (const Department &a, const Department &b);
    friend bool operator == (const Department &a, const Department &b);

    friend Department operator + (const Department &a, const Employee &e);
    const Employee operator[](const int id);

 private:
    std::string name;
    int id;
    int head_id;
    int adjacent_department_id;
};
