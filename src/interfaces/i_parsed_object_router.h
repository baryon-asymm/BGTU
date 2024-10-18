#pragma once

#include <memory>

class ParsedObject;

class IParsedObjectRouter {
public:
    virtual ~IParsedObjectRouter() = default;

    virtual void Route(std::unique_ptr<ParsedObject> parsed_object) = 0;
};
