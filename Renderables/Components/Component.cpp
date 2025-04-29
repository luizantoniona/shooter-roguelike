#include "Component.h"

BEGIN_COMPONENTS_NAMESPACE

Component::Component( std::string componentName ) :
    _componentName( componentName ) {
}

std::string Component::getComponentName() const {
    return _componentName;
}

END_COMPONENTS_NAMESPACE
