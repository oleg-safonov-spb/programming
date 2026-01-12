// Copyright 2026 Oleg Safonov

#ifndef IP_VALIDATOR_H
#define IP_VALIDATOR_H

/**
 * Проверяет строку на соответствие формату IPv4 и диапазону 0-255.
 * Возвращает 1, если адрес корректен, и 0 в противном случае.
 */
int validate_ip_full(const char *ip);

#endif
