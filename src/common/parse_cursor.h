#pragma once

#include <string>
#include <memory>

class ParseCursor {
private:
    std::unique_ptr<std::string> source_;
    int position_;
    char* sequence_;
    int sequence_length_;
    
public:
    ParseCursor(std::unique_ptr<std::string> input);

    bool HasCurrentChar() const noexcept;
    char GetCurrentChar() const;

    bool HasNextChar() const noexcept;
    char GetNextChar() const;

    bool HasPreviousChar() const noexcept;
    char GetPreviousChar() const;

    std::unique_ptr<std::string> GetSequence() const;
    std::unique_ptr<std::string> GetSequenceWithNextChar() const;

    int GetSequenceLength() const noexcept;
    void FlushSequence() noexcept;
    void MakeStep();
};
