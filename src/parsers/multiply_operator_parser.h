#pragma once

#include <memory>

class IParser;
class BaseParser;
class ParseCursor;
class IParsedObjectRouter;

class MultiplyOperatorParser : public BaseParser {
public:
    MultiplyOperatorParser(std::unique_ptr<IParser> next_parser, std::shared_ptr<IParsedObjectRouter> parsed_object_router)
        : BaseParser(std::move(next_parser), std::move(parsed_object_router)) {}
    
    void Parse(const ParseCursor& cursor, bool& is_parsed) override;
};
