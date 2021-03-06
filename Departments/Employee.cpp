// Copyright 2015 <Artem Krinitsyn>
#include "Employee.h"
#include <string>
#include <iostream>

Employee::Employee() {
    this->name = "";
    this->id = 0;
    this->salary = 0;
    this->age = 0;
    this->vacation = 0;
}

Employee::~Employee() {
}

Employee::Employee(std::string name, int salary, int age) {
    this->name = name;
    this->salary = salary;
    this->age = age;
    this->vacation = 0;
    this->id = 0;
}

Employee::Employee(const Employee& a) {
    this->age = a.age;
    this->id = a.id;
    this->vacation = a.vacation;
    this->name = a.name;
    this->salary = a.salary;
}

void Employee::edit(std::string name, int salary, int age) {
    this->name = name;
    this->age = age;
    this->salary = salary;
    this->vacation = 0;
}

int Employee::get_id() const {
    return this->id;
}

void Employee::set_id(const int id) {
    this->id = id;
}

void Employee::print() const {
    std::cout << "\n" << ' ' << this->name
                      << ' ' << this->salary
                      << "  " << this->age
                      << "   " << this->id
                      << std::endl;
}

void Employee::set_name(std::string name) {
    this->name = name;
}

const std::string& Employee::get_name() const {
    return this->name;
}

void Employee::set_salary(const int salary) {
    this->salary = salary;
}

int Employee::get_salary() const {
    return this->salary;
}

void Employee::add_vacation(const int days) {
    this->vacation += days;
}

int Employee::get_vacation() const {
    return this->vacation;
}

void Employee::leave_of_absence(const int days) {
    if (this->vacation > days)
        this->vacation -= days;
}

bool operator ==(const Employee& a, const Employee& b) {
    return (b.age == a.age &&
            b.vacation == a.vacation &&
            b.name == a.name &&
            b.salary == a.salary);
}

Employee & Employee::operator= (const Employee& a) {
    if (this != &a) {
        this->age = a.age;
        this->id = a.id;
        this->vacation = a.vacation;
        this->name = a.name;
        this->salary = a.salary;
    }
    return *this;
}
