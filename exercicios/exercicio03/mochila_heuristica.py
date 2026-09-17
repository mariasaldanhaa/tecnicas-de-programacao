import itertools

i = 0
itens = []

print('Digite algum valor negativo para sair do sistema.')
capacidade = int(input('Informe a capacidade: '))

while True:
    i += 1
    lista_peso = int(input(f'Informe o peso {i}: '))
    lista_valor = int(input(f'Informe o valor {i}: '))

    if lista_valor < 0 or lista_peso < 0:
        print("Saindo...")
        break

    itens.append((lista_peso, lista_valor))

melhor_valor = 0
melhor_combinacao = None
melhor_peso = 0

for qtd in range(1, len(itens) + 1):
    combinacoes = itertools.combinations(itens, qtd)

    for combinacao in combinacoes:
        peso_total = sum(p for p, v in combinacao)
        valor_total = sum(v for p, v in combinacao)

        if peso_total <= capacidade:
            if valor_total > melhor_valor:
                melhor_valor = valor_total
                melhor_combinacao = combinacao
                melhor_peso = peso_total

print(f'Melhor combinação: {melhor_combinacao}')
print(f'Melhor peso: {melhor_peso}')
print(f'Melhor valor: {melhor_valor}')