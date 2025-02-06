#include "JsonHelper.h"

#include <fstream>
#include <iostream>

BEGIN_HELPER_NAMESPACE

Json::Value JsonHelper::loadJson( const std::string& filePath ) {
    std::ifstream file( filePath );
    if ( !file.is_open() ) {
        std::cerr << "Could not open file: " << filePath << std::endl;
        return Json::Value();
    }

    Json::Value jsonData;
    file >> jsonData;
    return jsonData;
}

END_HELPER_NAMESPACE