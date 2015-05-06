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
    this->name = "";
    this->id = 0;
    this->adjacent_department_id = 0;
    this->head_id = 0;
}

Department::Department(const std::string name,
    const int id,
    const int adjacent_id) {
    this->name = name;
    this->id = id;
    this->adjacent_department_id = adjacent_id;
    this->head_id = 0;
}

Department::~Department() {
}

Department::Department(const Department &a) {
    this->name = a.name;
    this->id = a.id;
    this->adjacent_department_id = a.adjacent_department_id;
    this->head_id = a.head_id;
    for (Department::const_iterator pos = a.begin(); pos != a.end(); ++pos) {
        this->add(*pos);
    }
}

void Department::add(const Employee &a) {
    Employee z = a;
    if (this->has(z)) {
        throw EmployeeAlreadyExist(z);
    } else {
        z.set_id(this->size() + 1);
        this->push_back(z);
    }
}

void Department::add(std::string name, int salary, int age) {
    Employee z(name, salary, age);
    this->add(z);
}

void Department::remove(const int id) {
    std::vector<Employee>::iterator pos2 = this->end();
    for (std::vector<Employee>::iterator pos = this->begin();
        pos != this->end(); ++pos) {
        if (pos->get_id() == id)
            pos2 = pos;
    }
    if (pos2 == this->end())
        throw EmployeeNotFound(id);
    else
        this->erase(pos2);
}

const bool Department::has(const Employee &a) {
    for (std::vector<Employee>::iterator pos = this->begin();
        pos != this->end(); ++pos) {
        if (*pos == a)
            return true;
    }
    return false;
}

void Department::set_name(const std::string name) {
    this->name = name;
}

const std::string Department::get_name() {
    return this->name;
}

void Department::set_id(const int id) {
    this->id = id;
}

const int Department::get_id() {
    return this->id;
}

void Department::print() {
    std::cout << "\n =========================================" << std::endl;
    std::cout << "\n" << ' ' << "department name" << ' '
        << "id" << "  " << "head_id" << " " << std::endl;
    std::cout << "\n" << ' ' << name << "           "
        << id << "    " << head_id << " \n _______  " << std::endl;
    std::cout << "\n" << ' ' << "name" << ' ' << "salary"
        << "  " << "age" << "  " << "id" << std::endl;
    for (Department::iterator pos = this->begin(); pos != this->end(); ++pos)
        pos->print();
}

void Department::set_head(const int id) {
    this->head_id = id;
}

const int Department::get_head() {
    return this->head_id;
}

void Department::generate() {
    char alphanum[] = "abcdefghijklmnopqrstuvwxyz";
    unsigned int a[6] = {0};
    for (int i = 0; i < 3; i++) {
        std::string s;
        for (int i = 0; i < 5; i++) {
            rand_s(&a[0]);
            s += alphanum[a[0] % sizeof(alphanum) - 1];
        }
        rand_s(&a[1]);
        rand_s(&a[2]);
        Employee a(s, 10000 + a[1] % 10000, 25 + a[2] % 40);
        this->add(a);
    }
    int b = 0;
    rand_s(&a[3]);
    std::string s;
    for (int i = 0; i < 5; i++) {
        rand_s(&a[4]);
        s += alphanum[a[4] % sizeof(alphanum) - 1];
    }
    this->name = s;
    rand_s(&a[5]);
    this->id = a[5] % 100;
    this->head_id = 1;
    this->adjacent_department_id = b;
}

void Department::set_adjacent(const int id) {
    this->adjacent_department_id = id;
}

const int Department::get_adjacent() {
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
    if (*this == a)
        return *this;

    this->clear();
    for (Department::const_iterator pos = a.begin(); pos != a.end(); ++pos) {
        this->add(*pos);
    }

    this->name = a.name;
    this->head_id = a.head_id;
    this->id = a.id;
    this->adjacent_department_id = a.adjacent_department_id;
    return *this;
}

Department  operator+(const Department &a, const Department &b) {
    Department out(a);
    for (Department::const_iterator pos = b.begin(); pos != b.end(); ++pos) {
        out.add(*pos);
    }
    return out;
}

bool operator == (const Department &a, const Department &b) {
    if (a.size() == b.size()) {
        if (a.name == b.name &&
            a.id == b.id &&
            a.adjacent_department_id == b.adjacent_department_id &&
            a.head_id == b.head_id) {
            int count = 0;
            for (Department::const_iterator pos1 = b.begin();
                pos1 != b.end(); ++pos1) {
                for (Department::const_iterator pos2 = b.begin();
                    pos2 != b.end(); ++pos2) {
                    if (pos1 == pos2)
                        ++count;
                }
            }
            if (count == a.size())
                return true;
        }
    }
    return false;
}

Department operator+(const Department &a, const Employee &e) {
    Department out(a);
    out.add(e);
    return out;
}

const Employee Department::operator[](const int id) {
    Department out(*this);
    for (Department::iterator pos = out.begin(); pos != out.end(); ++pos) {
        if (pos->get_id() == id) {
            return(*pos);
        }
    }
    throw EmployeeNotFound(id);
}
const int Department::get_Count() {
    int count = 0;
    for (Department::const_iterator pos = this->begin();
        pos != this->end(); ++pos) {
        ++count;
    }
    return count;
}
