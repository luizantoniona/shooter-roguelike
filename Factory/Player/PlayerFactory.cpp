#include "PlayerFactory.h"

BEGIN_FACTORY_NAMESPACE

Player* PlayerFactory::createPlayer( const Map& map ) {

    // TODO: Ajustar constructor de Player
    Player* player = new Player();

    // TODO Buscar dados de um arquivo ou banco de dados;
    // Verificar qual melhor solução;

    return player;
}

END_FACTORY_NAMESPACE