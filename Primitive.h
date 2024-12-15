#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <iostream>
#include <memory>
#include <string>

class Primitive {
public:
    virtual ~Primitive() = default;
    virtual void draw() const = 0;
    virtual std::string getType() const = 0;
};

class Circle : public Primitive {
public:
    void draw() const override {
        std::cout << "Рисуем круг..." << std::endl;
    }

    std::string getType() const override {
        return "Круг";
    }
};

class Rectangle : public Primitive {
public:
    void draw() const override {
        std::cout << "Рисуем прямоугольник..." << std::endl;
    }

    std::string getType() const override {
        return "Прямоугольник";
    }
};

using PrimitivePtr = std::shared_ptr<Primitive>;

#endif 
