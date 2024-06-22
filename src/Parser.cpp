#include "../headers/Parser.h"
#include "../headers/ast/AstValue.h"
#include "../headers/ast/TrueValue.h"
#include "../headers/ast/FalseValue.h"
#include "../headers/ast/NullValue.h"
#include "../headers/ast/NumberValue.h"
#include "../headers/ast/StringValue.h"
#include <iostream>

Parser::Parser(Lexer& lexer) : lexer(lexer) {
    this->lexer.generate_token();
}

Node Parser::parse() {
    std::optional<Node> node;

    if (
        (node = this->parse_true()) ||
        (node = this->parse_false()) ||
        (node = this->parse_null()) ||
        (node = this->parse_number()) ||
        (node = this->parse_string())
    ) {
        return std::move(node.value());
    }

    throw std::runtime_error("Parsing error: unrecognized token");
}

std::optional<Node> Parser::parse_true() {
    Token token = this->lexer.get_current().value();
    if (token.get_type() != TokenType::TRUE) {
        return std::nullopt;
    }

    Node node = Node(std::make_unique<TrueValue>(), token.get_position());
    this->lexer.generate_token();
    std::cout << "created true\n";
    return node;
}

std::optional<Node> Parser::parse_false() {
    Token token = this->lexer.get_current().value();
    if (token.get_type() != TokenType::FALSE) {
        return std::nullopt;
    }

    Node node = Node(std::make_unique<FalseValue>(), token.get_position());
    this->lexer.generate_token();
    std::cout << "created false\n";
    return node;
}

std::optional<Node> Parser::parse_null() {
    Token token = this->lexer.get_current().value();
    if (token.get_type() != TokenType::NONE) {
        return std::nullopt;
    }

    Node node = Node(std::make_unique<NullValue>(), token.get_position());
    this->lexer.generate_token();
    std::cout << "created null\n";
    return node;
}

std::optional<Node> Parser::parse_number() {
    Token token = this->lexer.get_current().value();
    if (token.get_type() != TokenType::FLOAT && token.get_type() != TokenType::INT) {
        return std::nullopt;
    }

    std::string value_str = std::get<std::string>(token.get_value());
    Node node = Node(std::make_unique<NumberValue>(value_str), token.get_position());
    this->lexer.generate_token();
    std::cout << "created number\n";
    return node;
}

std::optional<Node> Parser::parse_string() {
    Token token = this->lexer.get_current().value();
    if (token.get_type() != TokenType::STRING) {
        return std::nullopt;
    }

    std::string value_str = std::get<std::string>(token.get_value());
    Node node = Node(std::make_unique<StringValue>(value_str), token.get_position());
    this->lexer.generate_token();
    std::cout << "created string\n";
    return node;
}
