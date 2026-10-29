cmake_minimum_required(VERSION 4.3)
project(cadastro_aluno C)

set(CMAKE_C_STANDARD 11)

add_executable(cadastro_aluno
        contato.h
        operacoes.c)
