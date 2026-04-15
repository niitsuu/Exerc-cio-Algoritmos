#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

float calc(float a, float b, float c){
    return (a + b + c)/3.0;
}

int main(){
    int opcao, indice = 0;
    string situacao, melhorAluno;
    float media, maiorNota;
    struct alunos {
        string nome; 
        float nota1; 
        float nota2; 
        float nota3;
    }; 
    
    alunos aluno[5];
    do {
        cout << "---------------------------------------------------\n";
        cout << "       1- Adicionar aluno\n";
        cout << "       2- Calcular média\n";
        cout << "       3- Encerrar\n";
        cout << endl << "\tQual opção você deseja? ";
        cin >> opcao;
        switch (opcao) {
            case 1:
                cout << "\tQuantos alunos você quer adicionar (Max 5)? ";
                cin >> indice;
                while (indice < 1 or indice > 5) {
                    cout << endl << "\tValor inválido, digite entre 1 e 5: ";
                    cin >> indice;
                }
                
                for (int i = 0; i < indice; i++) {
                cout << "\n\tDigite o nome do aluno: ";
                cin.ignore();
                getline(cin,aluno[i].nome); fflush(stdin);
                cout << "\n\tDigite as 3 notas deste aluno: ";
                cin >> aluno[i].nota1 >> aluno[i].nota2 >> aluno[i].nota3;
                }
                break;
                
            case 2:
                maiorNota = 0;
                melhorAluno = "";
                if (indice == 0) {
                    cout << "\n\tAdicione pelo menos um aluno para calcular sua média\n";
                } else {
                    cout << endl << "---------------------------------------------------" << endl << endl;
                    cout << left;
                    cout << setw(10) << "ALUNO"
                        << setw(6) << "N1"
                        << setw(6) << "N2"
                        << setw(6) << "N3"
                        << setw(8) << "MÉDIA"
                        << setw(12) << "SITUAÇÃO" << endl;
                    
                    for (int i = 0; i < indice; i++){
                        media = calc(aluno[i].nota1, aluno[i].nota2, aluno[i].nota3);
                        if (media >= 7){
                            situacao = "APROVADO";
                        } else {
                            situacao = "REPROVADO";
                        }
                        
                        if (media > maiorNota) {
                            maiorNota = media;
                            melhorAluno = aluno[i].nome;
                        }
                        cout << fixed << setprecision(1);
                        cout << setw(10) << aluno[i].nome 
                            << setw(6) << aluno[i].nota1 
                            << setw(6) << aluno[i].nota2 
                            << setw(6) << aluno[i].nota3 
                            << setw(8) << media 
                            << setw(12) << situacao << endl;
                        
                }
                cout << endl << "---------------------------------------------------" << endl << endl;
                cout << "A maior média foi " << maiorNota << " do aluno " << melhorAluno << endl;
                opcao = 3;
                }
                break;
            case 3:
                cout << "\n\tPrograma encerrado.";
                break;
            default: 
                cout << "\n\tValor fora de faixa\n";
        }
    } while (opcao != 3);
    return 0;
}