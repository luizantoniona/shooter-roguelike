#pragma once

#include <jsoncpp/json/json.h>

#include <Factory/FactoryGlobals.h>

#include <Entity/Map/Background/Background.h>

using Entity::Background;

BEGIN_FACTORY_NAMESPACE

class BackgroundFactory {
public:
    static Background generateBackground( Json::Value& backgroundJson );
};

END_FACTORY_NAMESPACE
