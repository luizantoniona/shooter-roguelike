#pragma once

#include <jsoncpp/json/json.h>
#include <queue>

#include <Factory/FactoryGlobals.h>

#include <Renderables/Entities/Map/Wave/Wave.h>

using Entities::Wave;

BEGIN_FACTORY_NAMESPACE

class WaveFactory {
public:
    static std::queue<Wave> generateWaves( Json::Value& wavesJson );
};

END_FACTORY_NAMESPACE
