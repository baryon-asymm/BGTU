#pragma once

class IParser;
class ParseCursor;

class TerminationParser : public IParser {
public:
    void Parse(const ParseCursor& cursor, bool& is_parsed) override;
};
