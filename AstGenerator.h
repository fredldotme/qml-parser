#pragma once

#ifndef AST_GENERATOR_H
#define AST_GENERATOR_H

#include <nlohmann/json.hpp>
#include <qmljs/qmljsdocument.h>

#include "AstGeneratorBase.h"

using namespace QmlJS;
using namespace QmlJS::AST;
using namespace nlohmann;

class AstGenerator : protected AstGeneratorBase {
  using AstGeneratorBase::AstGeneratorBase;

  json ast;

public:
  json operator()(Node *node);

protected:
  void accept(Node *node);
  void appendItems(const json &items);

  bool visit(UiImport *node) override;
  bool visit(UiObjectDefinition *node) override;
  bool visit(UiObjectInitializer *node) override;
  bool visit(UiParameterList *list) override;
  bool visit(UiPublicMember *node) override;
  bool visit(UiObjectBinding *node) override;
  bool visit(UiScriptBinding *node) override;
  bool visit(UiArrayBinding *node) override;
  bool visit(UiArrayMemberList *node) override;
  bool visit(FunctionDeclaration *node) override;
  bool visit(FunctionExpression *node) override;
  bool visit(UiHeaderItemList *node) override;
  bool visit(UiObjectMemberList *node) override;
};

#endif // AST_GENERATOR_H