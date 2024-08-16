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

class Lista{
    private:
        No *raiz;
    
    public: 
        Lista(){
            this->raiz = nullptr;
        }

    void inseririnicio(int elemento){
        No *novo = new No(elemento);

        if (this->raiz == nullptr)
        {
            this->raiz = novo;
        } else {
            novo->proximo = this->raiz; // passando a raiz p frente
            this->raiz = novo;
        }
    }

    void inserir(int elemento){
        No *novo = new No(elemento);

        if (this->raiz == nullptr)
        {
            this->raiz = novo;
        } else if (elemento <= this->raiz->elemento)
        {
            novo->proximo = this->raiz;
            this->raiz = novo;
        }else
        {
            No *atual = this->raiz;
            while (atual->proximo != nullptr && elemento > atual->proximo->elemento)
            {
                atual = atual->proximo;
            }
            novo->proximo = atual->proximo;
            atual->proximo = novo;
        }
        std::cout << "Elemento " << elemento << " inserido" << std::endl;
    }

    void inserirfim(int elemento){
        No *novo = new No(elemento);

        if (this->raiz == nullptr)
        {
            this->raiz = novo;
        } else{
            No *atual = this->raiz;

            while (atual->proximo != nullptr)
            {
                atual = atual->proximo; // avançando até não haver posições na frente, para alocar o elemento na prx posição vazia.
            }

            atual->proximo = novo;
            
        }
        std::cout << "Elemento " << elemento << " inserido" << std::endl;
    }

    void removerinicio(){
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

    void removerfim(){
        if (this->raiz == nullptr)
        {
            std::cout << "Lista vazia" << std::endl;
        } else if (this->raiz->proximo == nullptr)
        {
            {
                int elemento = this->raiz->elemento;
                delete this->raiz; // deletar se tiver apenas um elemento. Pois o fim será o primeiro.
                this->raiz = nullptr;
                std::cout << "Elemento " << elemento << " removido" << std::endl;
            }
        } else 
        {
            No *atual = this->raiz;
            No *ant = nullptr;

            while (atual->proximo != nullptr)
            {
                ant = atual;
                atual = atual->proximo; 
            }
            int elemento = atual->elemento;
            ant->proximo = nullptr;
            delete atual;
            std::cout << "Elemento " << elemento << " removido" << std::endl;
        }
    }

    void remover(int elemento){
         if (this->raiz = nullptr)
        {
            std::cout << "Lista vazia" << std::endl;
            return;
        } else 
        {
            No *anterior = nullptr;
            No *atual = this->raiz;
            while (atual != nullptr && atual->elemento != elemento)
            {
                anterior = atual;
                atual = atual->proximo;
            }
            if (atual == nullptr)
            {
                std::cout << "Elemento não encontrado" << std::endl;
                return;
            }
            else if (raiz->elemento == elemento)
            {
                atual->proximo = this->raiz;
                delete atual;
            } else 
            {
                anterior->proximo = atual->proximo; // nulo
                delete atual;
            }
            std::cout << "Elemento " << elemento << " removido" << std::endl;
        }
    }

    void mostrar(){
        if (this->raiz == nullptr)
        {
            std::cout << "Lista Vazia" << std::endl;
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

   bool buscar(int elemento)
    {
        if (this->raiz == nullptr)
        {
            std::cout << "Lista Vazia" << std::endl;
            return false;
        }

        No *atual = this->raiz;
        while (atual != nullptr)
        {
            if (atual->elemento == elemento)
            {
                return true;
            }

            atual = atual->proximo;
        }

        return false;
    }
};

int main()
{
    // Inicializa a lista E a opção
    int opcao;
    Lista lista;

    do
    {
        // Menu
        std::cout << std::endl;
        std::cout << "1) Inserir Elemento na Lista" << std::endl;
        std::cout << "2) Inserir no Final da Lista" << std::endl;
        std::cout << "3) Inserir no Inicio da Lista" << std::endl;
        std::cout << std::endl;
        std::cout << "4) Remover Elemento da Lista" << std::endl;
        std::cout << "5) Remover do Inicio da Lista" << std::endl;
        std::cout << "6) Remover do Final da Lista" << std::endl;
        std::cout << std::endl;
        std::cout << "7) Imprimir Lista" << std::endl;
        std::cout << "8) Buscar na Lista" << std::endl;
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
            lista.inserir(elemento);
            break;
        }
        case 2:
        {
            // Recebe o elemento
            int elemento;
            std::cout << "Digite o elemento: ";
            std::cin >> elemento;

            // Inserir
            lista.inserirfim(elemento);
            break;
        }
        case 3:
        {
            // Recebe o elemento
            int elemento;
            std::cout << "Digite o elemento: ";
            std::cin >> elemento;

            // Inserir
            lista.inseririnicio(elemento);
            break;
        }
        case 4:
        {
            // Recebe o elemento
            int elemento;
            std::cout << "Digite o elemento: ";
            std::cin >> elemento;

            // Remover
            lista.remover(elemento);
            break;
        }
        case 5:
        {
            // Remover
            lista.removerinicio();
            break;
        }
        case 6:
        {
            // Remover
            lista.removerfim();
            break;
        }
        case 7:
        {
            lista.mostrar();
            break;
        }
        case 8:
        {
            // Recebe o elemento
            int elemento;
            std::cout << "Digite o elemento: ";
            std::cin >> elemento;

            // Buscar
            bool encontrado = lista.buscar(elemento);
            if (encontrado)
            {
                std::cout << "Elemento " << elemento << " encontrado na lista." << std::endl;
            }
            else
            {
                std::cout << "Elemento " << elemento << " não encontrado na lista." << std::endl;
            }
            break;
        }
        }
    } while (opcao != 0);

    return 0;
}