#pragma once

#include <GUI/GUIGlobals.h>

#include "Bar.h"

BEGIN_GUI_NAMESPACE

class HealthBar : public Bar {
public:
    HealthBar( float maxHealth );

    void setHealth( float health );

private:
    float _maxHealth;
};

END_GUI_NAMESPACE