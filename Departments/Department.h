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

    void add(const Employee& e);
    void add(const std::string name, int salary, int age);

    void remove(const int id);
    bool has(const Employee &a) const;

    void set_name(const std::string name);
    const std::string& get_name() const;

    void set_id(const int id);
    int get_id() const;

    void print() const;

    void set_head(const int id);
    int get_head() const;

    void generate();

    void set_adjacent(const int id);
    int get_adjacent() const;

    void add_vacation(const int days);
    void leave_of_absence(const int days);

    int get_Count() const;

    Department & operator=(const Department& a);

    friend Department operator+ (const Department& a, const Department& b);
    friend bool operator == (const Department& a, const Department& b);

    friend Department operator + (const Department& a, const Employee& e);
    Employee* operator[](const int id);
    const Employee* operator[](const int id) const;

 private:
    std::string name;
    int id;
    int head_id;
    int adjacent_department_id;
    int cur_id;
};
