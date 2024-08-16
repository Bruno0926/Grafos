#include <iostream>

class No {
public:
    int elemento;
    No *proximo;

    No(int elemento) {
        this->elemento = elemento;
        this->proximo = nullptr;
    }
};

class Pilha {
private:
    No *raiz;

public:
    Pilha() {
        this->raiz = nullptr;
    }

    void inserir(int elemento) {
        No *novo = new No(elemento);

        if (this->raiz == nullptr) {
            this->raiz = novo; // Se a pilha estiver vazia, o novo elemento é a raiz
        } else {
            No *atual = this->raiz; // Ponteiro para percorrer a pilha
            while (atual->proximo != nullptr) { // Percorre a pilha até o elemento sem próximo
                atual = atual->proximo;
            }
            atual->proximo = novo; // Adiciona o novo elemento
        }

        std::cout << "Elemento " << elemento << " inserido" << std::endl;
    }

    void remover() {
        if (this->raiz == nullptr) {
            std::cout << "Pilha Vazia" << std::endl;
            return;
        } else if (this->raiz->proximo == nullptr) { // Verifica se há apenas um elemento na pilha
            int elemento = this->raiz->elemento;
            delete this->raiz;
            this->raiz = nullptr;
            std::cout << "Elemento " << elemento << " removido" << std::endl;
        } else {
            No *atual = this->raiz;
            No *anterior = nullptr;

            while (atual->proximo != nullptr) {
                anterior = atual;
                atual = atual->proximo;
            }
            int x = atual->elemento; // para printar
            anterior->proximo = nullptr; // remove o último elemento
            delete atual;

            std::cout << "Elemento " << x << " removido" << std::endl;
        }
    }

    void mostrar() {
        if (this->raiz == nullptr) {
            std::cout << "Pilha Vazia" << std::endl;
            return;
        }

        No *atual = this->raiz;
        while (atual != nullptr) {
            std::cout << atual->elemento << " ";
            atual = atual->proximo;
        }
        std::cout << std::endl;
    }

    bool buscar(int elemento) {
        if (this->raiz == nullptr) {
            std::cout << "Pilha Vazia" << std::endl;
            return false;
        }

        No *atual = this->raiz;
        while (atual != nullptr) {
            if (atual->elemento == elemento) {
                std::cout << "Elemento " << atual << " encontrado" << std::endl;
                return true;
            }
            atual = atual->proximo;
        }
        return false;
    }
};

int main() {
    // Inicializa a pilha E a opção
    int opcao;
    Pilha pilha;

    do {
        // Menu
        std::cout << std::endl;
        std::cout << "1) Inserir na Pilha" << std::endl;
        std::cout << "2) Remover da Pilha" << std::endl;
        std::cout << "3) Imprimir Pilha" << std::endl;
        std::cout << "4) Buscar na Pilha" << std::endl;
        std::cout << "0) Sair" << std::endl;

        // Le a opção
        std::cout << "\nOpção: ";
        std::cin >> opcao;
        std::cout << std::endl;

        switch (opcao) {
        case 1: {
            // Recebe o elemento
            int elemento;
            std::cout << "Digite o elemento: ";
            std::cin >> elemento;

            // Inserir
            pilha.inserir(elemento);
            break;
        }

        case 2: {
            // Remover
            pilha.remover();
            break;
        }

        case 3: {
            pilha.mostrar();
            break;
        }

        case 4: {
            // Recebe o elemento
            int elemento;
            std::cout << "Digite o elemento: ";
            std::cin >> elemento;

            // Buscar
            bool encontrado = pilha.buscar(elemento);
            if (encontrado) {
                std::cout << "Elemento " << elemento << " encontrado na pilha." << std::endl;
            } else {
                std::cout << "Elemento " << elemento << " não encontrado na pilha." << std::endl;
            }
            break;
        }
        }
    } while (opcao != 0);

    return 0;
}
