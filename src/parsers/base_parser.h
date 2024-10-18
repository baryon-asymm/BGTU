#pragma once

#include <memory>

class IParser;
class ParseCursor;
class IParsedObjectRouter;

class BaseParser : public IParser {
public:
    BaseParser(std::unique_ptr<IParser> next_parser, std::shared_ptr<IParsedObjectRouter> parsed_object_router)
        : next_parser_(std::move(next_parser)), parsed_object_router_(std::move(parsed_object_router)) {}

    virtual void Parse(const ParseCursor& cursor, bool& is_parsed) = 0;

protected:
    std::unique_ptr<IParser> next_parser_;
    std::shared_ptr<IParsedObjectRouter> parsed_object_router_;
};
