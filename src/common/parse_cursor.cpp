#include <stdexcept>

#include "parse_cursor.h"

ParseCursor::ParseCursor(std::unique_ptr<std::string> input) {
    source_ = std::move(input);
    position_ = 0;
    sequence_ = new char[source_->length()];
    sequence_length_ = 0;
}

bool ParseCursor::HasCurrentChar() const noexcept {
    return sequence_length_ > 0;
}

char ParseCursor::GetCurrentChar() const {
    return sequence_[sequence_length_ - 1];
}

bool ParseCursor::HasNextChar() const noexcept {
    return position_ < source_->length();
}

char ParseCursor::GetNextChar() const {
    return source_->at(position_);
}

bool ParseCursor::HasPreviousChar() const noexcept {
    return sequence_length_ > 1;
}

char ParseCursor::GetPreviousChar() const {
    return sequence_[sequence_length_ - 2];
}

std::unique_ptr<std::string> ParseCursor::GetSequence() const {
    return std::make_unique<std::string>(sequence_, sequence_length_);
}

std::unique_ptr<std::string> ParseCursor::GetSequenceWithNextChar() const {
    sequence_[sequence_length_] = source_->at(position_);
    return std::make_unique<std::string>(sequence_, sequence_length_ + 1);
}

int ParseCursor::GetSequenceLength() const noexcept {
    return sequence_length_;
}

void ParseCursor::FlushSequence() noexcept {
    sequence_length_ = 0;
}

void ParseCursor::MakeStep() {
    if (position_ >= source_->length()) {
        throw std::runtime_error("Cursor is out of bounds");
    }

    sequence_[sequence_length_] = source_->at(position_);
    sequence_length_++;
    position_++;
}
