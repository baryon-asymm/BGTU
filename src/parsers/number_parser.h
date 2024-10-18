#pragma once

#include <regex>

class IParser;
class BaseParser;
class ParseCursor;
class IParsedObjectRouter;

class NumberParser : public BaseParser {
private:
    const std::regex number_regex = std::regex("[0-9]*\\.?[0-9]+([eE][-+]?[0-9]+)?$");

public:
    NumberParser(std::unique_ptr<IParser> next_parser, std::shared_ptr<IParsedObjectRouter> parsed_object_router)
        : BaseParser(std::move(next_parser), std::move(parsed_object_router)) {}
    
    void Parse(const ParseCursor& cursor, bool& is_parsed) override;
};
