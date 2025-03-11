#include "Runner.h"

BEGIN_RUNNER_NAMESPACE

Runner::Runner( sf::RenderWindow& window, sf::View& view ) :
    _window( window ),
    _view( view ) {
}

Runner::~Runner() {
}

END_RUNNER_NAMESPACE