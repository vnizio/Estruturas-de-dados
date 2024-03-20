#include <iostream>

using namespace std;


struct Conjunto{
  
    char array[5];
    int n;
    
};

void inicializar(Conjunto &C) {
    
    C.n = 0;
    
}

bool cheia(Conjunto &C) {
    
    bool result = (C.n >= 5) ? true : false; 
    return result;
    
}

bool vazia(Conjunto &C) {
    
    bool result = (C.n == 0) ? true : false;
    return result;
    
}

int getIndex(Conjunto &C, char elemento, bool adicionar) { // busca binária

    int i = 0, f = C.n-1, index = C.n;
    
    while(i <= f) {
        
        
        int m = (i+f)/2;
        if(C.array[m] == elemento and adicionar == false) {
            
            return m;
            
        } else if(adicionar == true and C.array[m] < elemento and (m == C.n-1 or C.array[m+1] > elemento)) {
                
            return m;
        
        } else if(C.array[m] > elemento){
            
            f = m - 1;
            
        } else if(C.array[m] < elemento){
            
            i = m + 1;
            
        }
    }
    return index;
    
}

bool pertence(Conjunto &C, char elemento) {
    
    bool result = (getIndex(C, elemento, false) != -1) ? true : false;
    return result;
    
}

void adicionarNovo(Conjunto &C, char elemento) {
    
    if(!cheia(C)){
        
        for(int i = C.n-1; i>=getIndex(C, elemento, true) ;i--){
            
            C.array[i+1] = C.array[i];
            
        }
        C.array[getIndex(C, elemento, true)] = elemento;
        C.n++;
        
        cout << "o elemento " <<  elemento << " foi adicionado no espaço " << getIndex(C, elemento, true) << endl;
    
    } else {
        
        cout << "conjunto já esta cheio\n";
        
    }
}

void adicionarSeNovo(Conjunto &C, char elemento) {
    
    if(!pertence(C, elemento)) {
        
        adicionarNovo(C, elemento);
        
    } else {
        
        cout << "elemento já  pertecente ao conjunto\n";
        
    }
}

void remover(Conjunto &C, char elemento) {
    
    if(pertence(C, elemento) and !vazia(C)) {
        
        cout << "o elemento " << elemento << " foi removido\n";
        
        for(int i=getIndex(C, elemento, false) ; i<C.n ; i++) {
            
            C.array[i] = C.array[i+1];
            
        }
        C.n--;
        
    } else {
        
        cout << "o elemento não pertence ao conjunto ou o conjunto esta vazi0\n";
        
    }
}

void getConjunto(Conjunto &C) { // para teste

    for(int i=0 ; i<C.n ; i++){  
        
        cout << C.array[i];
        
    }
    cout << endl;
    
}

int main() {
    
    Conjunto C;
    inicializar(C);
    
    int opc = -1;
    char elemento;
    
    while (opc != 0){
        
        cout << "================= MENU ==================\n" << endl << "escolha a operação:" << endl <<"1 - inserir\n2 - inserir se novo\n3 - remover\n4 - vazio\n5 - cheio\n0 - para encerrar o programa\n\n"; 
        cin >> opc;
        
        switch (opc){
            
            case 1:
                cout << "digite o elemento que deseja inserir\n";
                cin >> elemento;
                adicionarNovo(C, elemento);
                break;
            case 2:
                cout << "digite o elemento que deseja inserir\n";
                cin >> elemento;
                adicionarSeNovo(C, elemento);
                break;
            case 3:
                cout << "qual elemento deseja remover\n";
                cin >> elemento;
                remover(C, elemento);
                break;
            case 4:
                if(vazia(C)) 
                cout << "o conjunto está vazio\n";
                else 
                cout << "o conjunto não está vazio\n";
                break;
            case 5:
                if(cheia(C)) 
                cout << "o conjunto está cheio\n";
                else 
                cout << "o conjunto não está cheio\n";
                break;
            case 6:
                getConjunto(C);
                break;
            default:
            cout << "operação invalida\n";
                break;
        }
        
        
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
}