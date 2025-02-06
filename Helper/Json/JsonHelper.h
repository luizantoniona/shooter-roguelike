#pragma once

#include <jsoncpp/json/json.h>

#include <Helper/HelperGlobals.h>

BEGIN_HELPER_NAMESPACE

class JsonHelper {
public:
    static Json::Value loadJson( const std::string& filePath );
};

END_HELPER_NAMESPACE