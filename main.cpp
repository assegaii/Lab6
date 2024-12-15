#include "Controller.h"
#include <iostream>

int main() {
    Controller controller;

    
    auto doc = controller.createDocument();

   
    controller.addPrimitiveToDocument(doc, std::make_shared<Circle>());
    controller.addPrimitiveToDocument(doc, std::make_shared<Rectangle>());

   
    controller.updateView(doc);

    
    controller.removePrimitiveFromDocument(doc, 0);

    
    controller.updateView(doc);

   
    controller.exportDocument(doc, "output.svg");

    
    controller.importDocument("input.svg");


    return 0;
}
