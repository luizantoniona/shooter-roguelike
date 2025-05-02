#include "ShapeFactory.h"

BEGIN_FACTORY_NAMESPACE

std::unique_ptr<Shapes::Shape> ShapeFactory::createShape( const Shapes::ShapeType& shapeType ) {

    // TODO: Ao finalizar arquitetura do Shape, setar aqui
    //  auto playerShape = player->getShape();
    //  playerShape->setSides( 3 );
    //  playerShape->setSize( 20.f ); // TODO: Como configurar o tamanho?
    //  playerShape->setPosition( sf::Vector2f( map.getWidth() / 2.0, map.getHeight() / 2.0 ) );
    //  playerShape->setColor( sf::Color::Green );
    //  playerShape->build();
}

END_FACTORY_NAMESPACE
