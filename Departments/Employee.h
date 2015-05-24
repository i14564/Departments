// Copyright 2015 <Artem Krinitsyn>
#pragma once

#include <string>

class Employee {
 public:
    Employee();
    ~Employee();
    Employee(const std::string name, const int salary, const  int age);
    Employee(const Employee &a);

    void edit(const std::string name, const int salary, const int age);

    const std::string& get_name() const;
    void set_name(const std::string name);

    int get_id() const;
    void set_id(const int id);

    int get_salary() const;
    void set_salary(const int salary);

    void add_vacation(const int days);
    int get_vacation() const;

    void print() const;

    void leave_of_absence(const int days);

    friend bool operator ==(const Employee& a, const Employee& b);
    Employee & operator =(const Employee& a);

 protected:
    int id;
    int salary;
    int age;
    int vacation;
    std::string name;
};

