import heapq

def dijkstra(graph, source):
    # Inicializa as distâncias com infinito e a fonte com 0
    dist = {node: float('inf') for node in graph}
    dist[source] = 0

    # Fila de prioridade para processar os vértices
    pq = [(0, source)]  # (distância, vértice)

    while pq:
        current_dist, current_node = heapq.heappop(pq)

        # Se a distância atual for maior do que a já registrada, continue
        if current_dist > dist[current_node]:
            continue

        # Verifica os vizinhos do nó atual
        for neighbor, weight in graph[current_node].items():
            distance = weight

            # Relaxamento: Se encontrar um caminho mais curto, atualize a distância
            if distance < dist[neighbor]:
                dist[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))

    return dist

# Exemplo de uso
if __name__ == "__main__":
    # Grafo direcionado representado como um dicionário de dicionários
    # Cada nó tem um dicionário com seus vizinhos e os pesos das arestas
    graph = {
        'A': {'B': 5, 'C': 4},
        'B': {'D': 9},
        'C': {'B': 7, 'D': 2},
        'D': { }
    }

    source = 'A'
    dist = dijkstra(graph, source)

    # Imprime as distâncias mais curtas a partir do vértice fonte
    print(f"Distâncias MINIMAS a partir do vértice {source}:")
    for node in dist:
        print(f"Vértice {node} - Distância: {dist[node]}")

import heapq

def dijkstra_min(grafo, origem):
    # Inicializa as distâncias com infinito e a fonte com 0
    distancia = {node: float('-inf') for node in grafo}
    distancia[origem] = 0

    # Fila de prioridade para processar os vértices
    pq = [(0, origem)]  # (distância, vértice)

    while pq:
        dist_atual, V_atual = heapq.heappop(pq)

        # Se a distância atual for maior do que a já registrada, continue
        if dist_atual > distancia[V_atual]:
            continue

        # Verifica os vizinhos do nó atual
        for vizinho, peso in grafo[V_atual].items():
            dist_alternativa = peso

            # Se encontrar um caminho mais curto, atualize a distância
            if dist_alternativa > distancia[vizinho]:
                distancia[vizinho] = dist_alternativa
                heapq.heappush(pq, (dist_alternativa, vizinho))

    return distancia

# Exemplo de uso
if __name__ == "__main__":
    # Grafo direcionado representado como um dicionário de dicionários
    # Cada nó tem um dicionário com seus vizinhos e os pesos das arestas
    grafo = {
        'A': {'B': 5, 'C': 4},
        'B': {'D': 9},
        'C': {'B': 7, 'D': 2},
        'D': { }
    }

    fonte = 'A'
    dist = dijkstra_min(grafo, fonte)

    # Imprime as distâncias mais curtas a partir do vértice fonte
    print(f"Distâncias MAXIMAS a partir do vértice {fonte}:")
    for num in dist:
        print(f"Vértice {num} - Distância: {dist[num]}")
