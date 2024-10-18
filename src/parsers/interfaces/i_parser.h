#pragma once

class ParseCursor;

class IParser {
public:
    virtual ~IParser() = default;

    virtual void Parse(const ParseCursor& cursor, bool& is_parsed) = 0;
};
