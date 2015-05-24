// Copyright 2015 <Artem Krinitsyn>

#define _CRT_RAND_S
#include "Department.h"
#include "Exceptions.h"
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

Employee zEmpl;

Department::Department() {
    this->cur_id = 1;
    this->name = "";
    this->id = 0;
    this->adjacent_department_id = 0;
    this->head_id = 0;
}

Department::Department(const std::string name,
    const int id,
    const int adjacent_id) {
    this->cur_id = 1;
    this->name = name;
    this->id = id;
    this->adjacent_department_id = adjacent_id;
    this->head_id = 0;
}

Department::~Department() {
}

Department::Department(const Department& a) {
    this->operator=(a);
}

void Department::add(const Employee& a) {
    if (this->has(a)) {
        throw EmployeeAlreadyExist(a);
    } else {
        this->push_back(a);
        (this->back()).set_id(cur_id++);
    }
}

void Department::add(std::string name, int salary, int age) {
    Employee z(name, salary, age);
    this->add(z);
}

void Department::remove(const int id) {
    if (id > this->get_Count() - 1) {
        throw EmployeeNotFound(id);
    } else {
        Department::iterator pos = this->begin();
        std::advance(pos, id);
        this->erase(pos);
    }
}

bool Department::has(const Employee& a) const {
    return (this->end() != find(this->begin(), this->end(), a));
}

void Department::set_name(const std::string name) {
    this->name = name;
}

const std::string& Department::get_name() const {
    return this->name;
}

void Department::set_id(const int id) {
    this->id = id;
}

int Department::get_id() const {
    return this->id;
}

void Department::print() const {
    std::cout << "\n =========================================" << std::endl;
    std::cout << "\n" << ' ' << "department name" << ' '
        << "id" << "  " << "head_id" << " " << std::endl;
    std::cout << "\n" << ' ' << name << "           "
        << id << "    " << head_id << " \n _______  " << std::endl;
    std::cout << "\n" << ' ' << "name" << ' ' << "salary"
        << "  " << "age" << "  " << "id" << std::endl;
    for (Department::const_iterator pos = this->begin();
         pos != this->end(); ++pos)
        pos->print();
}

void Department::set_head(const int id) {
    this->head_id = id;
}

int Department::get_head() const {
    return this->head_id;
}

void Department::generate() {
    char alphanum[] = "abcdefghijklmnopqrstuvwxyz";
    unsigned int a[6] = {0};
    for (int i = 0; i < 3; i++) {
        std::string s;
        for (int i = 0; i < 5; i++) {
            rand_s(a);
            s += alphanum[a[0] % sizeof(alphanum) - 1];
        }
        rand_s(a+1);
        rand_s(a+2);
        Employee a(s, 10000 + a[1] % 10000, 25 + a[2] % 40);
        this->add(a);
    }
    int b = 0;
    rand_s(a+3);
    std::string s;
    for (int i = 0; i < 5; i++) {
        rand_s(a+4);
        s += alphanum[a[4] % sizeof(alphanum) - 1];
    }
    this->name = s;
    rand_s(a+5);
    this->id = a[5] % 100;
    this->head_id = 1;
    this->adjacent_department_id = b;
}

void Department::set_adjacent(const int id) {
    this->adjacent_department_id = id;
}

int Department::get_adjacent() const {
    return this->adjacent_department_id;
}

void Department::add_vacation(const int days) {
    for (std::vector<Employee>::iterator pos = this->begin();
        pos != this->end(); ++pos) {
        pos->add_vacation(days);
    }
}

void Department::leave_of_absence(const int days) {
    for (std::vector<Employee>::iterator pos = this->begin();
        pos != this->end(); ++pos) {
        pos->leave_of_absence(days);
    }
}

Department & Department::operator=(const Department& a) {
    if (this != &a) {
        this->clear();
        this->std::vector<Employee>::operator=(a);
        this->name = a.name;
        this->head_id = a.head_id;
        this->id = a.id;
        this->cur_id = a.cur_id;
        this->adjacent_department_id = a.adjacent_department_id;
    }
    return *this;
}

Department  operator+(const Department& a, const Department& b) {
    Department out(a);
    for (Department::const_iterator pos = b.begin(); pos != b.end(); ++pos) {
        out.add(*pos);
    }
    return out;
}

bool operator == (const Department& a, const Department& b) {
    if (a.size() == b.size()) {
        if (a.name == b.name &&
            a.id == b.id &&
            a.adjacent_department_id == b.adjacent_department_id &&
            a.head_id == b.head_id) {
            return(std::equal(a.begin(), a.end(), b.begin()));
        }
    }
    return false;
}

Department operator+(const Department& a, const Employee& e) {
    Department out(a);
    out.add(e);
    return out;
}

const Employee* Department::operator[](const int id) const {
    for (std::vector<Employee>::const_iterator pos = this->begin();
         pos != this->end(); ++pos) {
        if (pos->get_id() == id) {
            return &(*pos);
        }
    }
    throw EmployeeNotFound(id);
}

Employee* Department::operator[](const int id) {
    for (std::vector<Employee>::iterator pos = this->begin();
         pos != this->end(); ++pos) {
        if (pos->get_id() == id) {
            return &(*pos);
        }
    }
    throw EmployeeNotFound(id);
}

int Department::get_Count() const {
    return this->size();
}
