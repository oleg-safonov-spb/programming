// Copyright 2026 Oleg Safonov

#ifndef BRACKETS_H
#define BRACKETS_H

typedef enum { BRACKETS_BALANCED, BRACKETS_ERROR, BRACKETS_NONE } BracketResult;

BracketResult check_brackets(const char *expr);

#endif
