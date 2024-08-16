#include <iostream>
#include <vector>

class No{
    public:
        int elemento;
        No *proximo;

        No(int elemento){
            this->elemento = elemento;
            this->proximo = nullptr;
        }
};

class fila{
    private:
        No *raiz;
    
    public: 
        fila(){
            this->raiz = nullptr;
        }

    void inserir(int elemento){
        No *novo = new No(elemento);

        if (this->raiz == nullptr)
        {
            this->raiz = novo;
        } else
        {
            No *atual = this->raiz;

            while (atual->proximo != nullptr)
            {
                atual = atual->proximo; // avançando até não haver posições na frente, para alocar o elemento na prx posição vazia.
            }

            atual->proximo = novo;
            
        }
        std::cout << "Elemento " << elemento << " inserido" << std::endl;
    }

    void remover(){
        if (this->raiz == nullptr)
        {
            std::cout << "Lista vazia" << std::endl;
            return;
        } else 
        {
            int elemento = raiz->elemento; // salva o elemento
            No *pos = raiz; // salva a raiz
            raiz = raiz->proximo; // avança a raiz p frente
            delete pos; // deleta 

            std::cout << "Elemento " << elemento << " removido" << std::endl;
        }
    }

    void mostrar(){
        if (this->raiz == nullptr)
        {
            std::cout << "Fila Vazia" << std::endl;
            return;
        }else
        {
            No *atual = this->raiz;
            while (atual != nullptr)
            {
            std::cout << atual->elemento << " ";
            atual = atual->proximo;
            }
        }
    }

    bool buscar(int elemento){
        if(this->raiz == nullptr){
            std::cout << "Pilha Vazia" << std::endl;
            return false;
        } else 
        {
            No *atual = this->raiz;
            while (atual != nullptr)
            {
                if (atual->elemento == elemento)
                {
                    std::cout << "Elemento " << atual << " encontrado" << std::endl;
                    return true;
                } 
                atual = atual->proximo;
            } 
        }
        return false;
    }
};

int main()
{
    // Inicializa a Fila E a opção
    int opcao;
    fila fila;

    do
    {
        // Menu
        std::cout << std::endl;
        std::cout << "1) Inserir na Fila" << std::endl;
        std::cout << "2) Remover da Fila" << std::endl;
        std::cout << std::endl;
        std::cout << "3) Imprimir Fila" << std::endl;
        std::cout << "4) Buscar na Fila" << std::endl;
        std::cout << "0) Sair" << std::endl;

        // Le a opção
        std::cout << "\nOpção: ";
        std::cin >> opcao;
        std::cout << std::endl;

        switch (opcao)
        {

        case 1:
        {
            // Recebe o elemento
            int elemento;
            std::cout << "Digite o elemento: ";
            std::cin >> elemento;

            // Inserir
            fila.inserir(elemento);
            break;
        }

        case 2:
        {
            // Remover
            fila.remover();
            break;
        }
    
        case 3:
        {
            fila.mostrar();
            break;
        }
        case 4:
        {
            // Recebe o elemento
            int elemento;
            std::cout << "Digite o elemento: ";
            std::cin >> elemento;

            // Buscar
            bool encontrado = fila.buscar(elemento);
            if (encontrado)
            {
                std::cout << "Elemento " << elemento << " encontrado na fila." << std::endl;
            }
            else
            {
                std::cout << "Elemento " << elemento << " não encontrado na fila." << std::endl;
            }
            break;
        }
        }
    } while (opcao != 0);

    return 0;
}