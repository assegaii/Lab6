#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "Primitive.h"
#include <vector>
#include <memory>

class Document {
private:
    std::vector<PrimitivePtr> primitives;
    int id;

public:
    explicit Document(int id) : id(id) {}

    void addPrimitive(const PrimitivePtr& primitive) {
        primitives.push_back(primitive);
        std::cout << "Добавлена примитива: " << primitive->getType() << " в документ " << id << std::endl;
    }

    void removePrimitive(size_t index) {
        if (index < primitives.size()) {
            std::cout << "Удаленна примитива: " << primitives[index]->getType() << " из документа " << id << std::endl;
            primitives.erase(primitives.begin() + index);
        } else {
            std::cout << "Invalid index." << std::endl;
        }
    }

    void drawPrimitives() const {
        std::cout << "Обновляем документ " << id << ":" << std::endl;
        for (const auto& primitive : primitives) {
            primitive->draw();
        }
    }

    int getId() const {
        return id;
    }
};

using DocumentPtr = std::shared_ptr<Document>;

#endif 
