#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Document.h"
#include "Primitive.h"
#include <vector>
#include <iostream>
#include <memory>
#include <string>

class Controller {
private:
    std::vector<DocumentPtr> documents;
    int nextDocumentId = 1;

public:
    DocumentPtr createDocument() {
        auto doc = std::make_shared<Document>(nextDocumentId++);
        documents.push_back(doc);
        std::cout << "Создан документ " << doc->getId() << std::endl;
        return doc;
    }

    void importDocument(const std::string& filename) {
        std::cout << "Импорт изображения из " << filename << std::endl;
    }

    void exportDocument(const DocumentPtr& doc, const std::string& filename) {
        if (doc) {
            std::cout << "Изображение " << doc->getId() << " экспортировано как " << filename << std::endl;
        } else {
            std::cout << "Invalid Document." << std::endl;
        }
    }

    void addPrimitiveToDocument(const DocumentPtr& doc, const PrimitivePtr& primitive) {
        if (doc) {
            doc->addPrimitive(primitive);
        } else {
            std::cout << "Invalid Document." << std::endl;
        }
    }

    void removePrimitiveFromDocument(const DocumentPtr& doc, size_t index) {
        if (doc) {
            doc->removePrimitive(index);
        } else {
            std::cout << "Invalid Document." << std::endl;
        }
    }

    void updateView(const DocumentPtr& doc) const {
        if (doc) {
            doc->drawPrimitives();
        } else {
            std::cout << "Invalid Document." << std::endl;
        }
    }
};

#endif 
