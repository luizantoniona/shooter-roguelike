#pragma once

#include <Renderables/Components/ComponentsGlobals.h>

#include "Bar.h"

BEGIN_COMPONENTS_NAMESPACE

class HealthBar : public Bar {
public:
    HealthBar( float maxHealth );

    void setHealth( float health );

private:
    float _maxHealth;
};

END_COMPONENTS_NAMESPACE
