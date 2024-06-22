#include "../headers/errors/SyntaxError.h"
#include "../headers/Parser.h"
#include "../headers/ast/AstValue.h"
#include "../headers/ast/TrueValue.h"
#include "../headers/ast/FalseValue.h"
#include "../headers/ast/NullValue.h"
#include "../headers/ast/NumberValue.h"
#include "../headers/ast/StringValue.h"
#include "../headers/ast/ArrayValue.h"
#include "../headers/ast/ObjectValue.h"
#include <iostream>

Parser::Parser(Lexer &lexer) : lexer(lexer)
{
    this->lexer.generate_token();
}

Node Parser::parse()
{
    auto node = this->parse_value();

    if (!node)
        throw SyntaxError("Parsing error: unrecognized token");

    return std::move(node.value());
}

Token Parser::must_be(TokenType token_type)
{
    auto token = this->lexer.get_current().value();
    if (token.get_type() != token_type)
        throw SyntaxError("Expected: " + std::to_string(token_type) + ", got: " + std::to_string(token.get_type()));

    return this->lexer.generate_token();
}

std::optional<Node> Parser::parse_value()
{
    std::optional<Node> node;

    if (
        (node = this->parse_true()) ||
        (node = this->parse_false()) ||
        (node = this->parse_null()) ||
        (node = this->parse_number()) ||
        (node = this->parse_string()) ||
        (node = this->parse_array()) ||
        (node = this->parse_object()))
    {
        return node;
    }

    return std::nullopt;
}

std::optional<Node> Parser::parse_true()
{
    Token token = this->lexer.get_current().value();
    if (token.get_type() != TokenType::TRUE)
    {
        return std::nullopt;
    }

    auto node = Node(std::make_unique<TrueValue>(), token.get_position());
    this->must_be(TokenType::TRUE);
    std::cout << "created true\n";
    return node;
}

std::optional<Node> Parser::parse_false()
{
    auto token = this->lexer.get_current().value();
    if (token.get_type() != TokenType::FALSE)
    {
        return std::nullopt;
    }

    auto node = Node(std::make_unique<FalseValue>(), token.get_position());
    this->must_be(TokenType::FALSE);
    std::cout << "created false\n";
    return node;
}

std::optional<Node> Parser::parse_null()
{
    auto token = this->lexer.get_current().value();
    if (token.get_type() != TokenType::NONE)
    {
        return std::nullopt;
    }

    auto node = Node(std::make_unique<NullValue>(), token.get_position());
    this->must_be(TokenType::NONE);
    std::cout << "created null\n";
    return node;
}

std::optional<Node> Parser::parse_number()
{
    auto token = this->lexer.get_current().value();
    if (token.get_type() != TokenType::FLOAT && token.get_type() != TokenType::INT)
    {
        return std::nullopt;
    }

    auto value_str = std::get<std::string>(token.get_value());
    auto node = Node(std::make_unique<NumberValue>(value_str), token.get_position());
    this->lexer.generate_token();
    std::cout << "created number\n";
    return node;
}

std::optional<Node> Parser::parse_string()
{
    auto token = this->lexer.get_current().value();
    if (token.get_type() != TokenType::STRING)
    {
        return std::nullopt;
    }

    auto value_str = std::get<std::string>(token.get_value());
    auto node = Node(std::make_unique<StringValue>(value_str), token.get_position());
    this->must_be(TokenType::STRING);
    std::cout << "created string\n";
    return node;
}

std::optional<Node> Parser::parse_array()
{
    auto token = this->lexer.get_current().value();
    if (token.get_type() != TokenType::BRACKET_OPEN)
        return std::nullopt;

    this->must_be(TokenType::BRACKET_OPEN);
    auto nodes = this->parse_array_inner();
    this->must_be(TokenType::BRACKET_CLOSE);

    auto node = Node(std::make_unique<ArrayValue>(std::move(nodes)), token.get_position());
    std::cout << "created array\n";
    return node;
}

std::vector<std::unique_ptr<Node>> Parser::parse_array_inner()
{
    std::vector<std::unique_ptr<Node>> nodes;

    auto node = this->parse_value();
    if (!node)
        return nodes;

    nodes.push_back(std::make_unique<Node>(std::move(node.value())));

    auto token = this->lexer.get_current().value();
    while (token.get_type() == TokenType::COMMA)
    {
        this->must_be(TokenType::COMMA);
        node = this->parse_value();
        if (!node)
            throw SyntaxError("Should be a valid value in array");

        nodes.push_back(std::make_unique<Node>(std::move(node.value())));
        token = this->lexer.get_current().value();
    }

    return nodes;
}

std::optional<Node> Parser::parse_object()
{
    auto token = this->lexer.get_current().value();
    if (token.get_type() != BRACE_OPEN)
        return std::nullopt;

    this->must_be(TokenType::BRACE_OPEN);
    auto map = this->parse_object_inner();
    this->must_be(TokenType::BRACE_CLOSE);

    auto node = Node(std::make_unique<ObjectValue>(std::move(map)), token.get_position());
    std::cout << "created object\n";
    return node;
}

std::map<std::string, std::unique_ptr<Node>> Parser::parse_object_inner()
{
    auto token = this->lexer.get_current().value();
    std::map<std::string, std::unique_ptr<Node>> map;

    if (token.get_type() != TokenType::STRING)
        return map;

    auto key = std::get<std::string>(token.get_value());
    this->must_be(TokenType::STRING);
    token = this->must_be(TokenType::COLON);
    auto value = this->parse_value();
    if (!value)
        throw SyntaxError("Bad or no value in object.\nAt " + token.get_position().to_string());
    map[key] = std::make_unique<Node>(std::move(value.value()));
    token = this->lexer.get_current().value();

    while (token.get_type() == TokenType::COMMA)
    {
        this->must_be(TokenType::COMMA);
        token = this->lexer.get_current().value();
        key = std::get<std::string>(token.get_value());
        this->must_be(TokenType::STRING);
        token = this->must_be(TokenType::COLON);
        value = this->parse_value();
        if (!value)
            throw SyntaxError("Bad or no value in object.\nAt " + token.get_position().to_string());
        if (map.find(key) != map.end())
            throw SyntaxError("Key '" + key + "' already exists.\nAt " + token.get_position().to_string());
        map[key] = std::make_unique<Node>(std::move(value.value()));
        token = this->lexer.get_current().value();
    }

    return map;
}
