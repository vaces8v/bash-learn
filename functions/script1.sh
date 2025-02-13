#!/usr/bin/env bash

set -Eeuo pipefail # Настройка окружения для предсказуемых ошибок как в языках высокого уровня

read -p "Enter count: " value # Ввод данных в переменную value

# Объявление и описание логики функции
# Простой цикл, который выводит количество итераций
function main() {
	i=0
	while [ $i -le $value ]
		do
			echo "$i"
			i=$(( $i+1 ))
		done
}
main # Вызов функции
