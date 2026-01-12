// Copyright 2026 Oleg Safonov

#include "bracket.h"

#include "stack.h"

BracketResult check_brackets(const char *expr) {
  Stack s;
  init_stack(&s);
  bool found_any = false;

  for (int i = 0; expr[i] != '\0'; i++) {
    char ch = expr[i];

    // Проверяем, является ли символ открывающей скобкой
    if (ch == '(' || ch == '[' || ch == '{') {
      found_any = true;
      push(&s, ch);
    } else if (ch == ')' || ch == ']' || ch == '}') {
      // Проверяем, является ли символ закрывающей скобкой
      found_any = true;
      if (is_empty(&s)) {
        clear_stack(&s);
        return BRACKETS_ERROR;
      }
      char top = pop(&s);
      if ((ch == ')' && top != '(') || (ch == ']' && top != '[') ||
          (ch == '}' && top != '{')) {
        clear_stack(&s);
        return BRACKETS_ERROR;
      }
    }
  }

  // Если скобки не найдены вообще
  if (!found_any) {
    clear_stack(&s);
    return BRACKETS_NONE;
  }

  // Если в стеке что-то осталось —
  // значит, не для всех открытых была закрывающая
  bool final_check = is_empty(&s);
  clear_stack(&s);

  return final_check ? BRACKETS_BALANCED : BRACKETS_ERROR;
}
