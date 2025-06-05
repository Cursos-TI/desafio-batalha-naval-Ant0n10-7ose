#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // === DECLARAÇÃO DAS VARIÁVEIS ===
    
    // Definições do tabuleiro e navios
    const int TAMANHO_TABULEIRO = 10;
    const int TAMANHO_NAVIO = 3;
    const int AGUA = 0;
    const int NAVIO = 3;
    
    // Matriz do tabuleiro 10x10
    int tabuleiro[10][10];
    
    // Vetores para representar os navios
    int navio_horizontal[3] = {3, 3, 3};  // Navio horizontal
    int navio_vertical[3] = {3, 3, 3};    // Navio vertical
    
    // Coordenadas dos navios (definidas no código)
    int navio1_linha = 2;     // Navio horizontal na linha 2
    int navio1_coluna = 3;    // Começando na coluna 3
    int navio2_linha = 6;     // Navio vertical começando na linha 6
    int navio2_coluna = 7;    // Na coluna 7
    
    // Variáveis auxiliares
    int i, j;                 // Para loops
    int posicao_valida = 1;   // Flag para validação
    
    // === APRESENTAÇÃO DO PROGRAMA ===
    printf("╔══════════════════════════════════════════════════════════╗\n");
    printf("║           BATALHA NAVAL - NÍVEL NOVATO                  ║\n");
    printf("║          Posicionamento de Navios no Tabuleiro          ║\n");
    printf("╚══════════════════════════════════════════════════════════╝\n\n");
    
    printf("🚢 Configuração do jogo:\n");
    printf("• Tabuleiro: %dx%d\n", TAMANHO_TABULEIRO, TAMANHO_TABULEIRO);
    printf("• Tamanho dos navios: %d posições\n", TAMANHO_NAVIO);
    printf("• Água representada por: %d\n", AGUA);
    printf("• Navios representados por: %d\n\n", NAVIO);
    
    // === INICIALIZAÇÃO DO TABULEIRO ===
    printf("🌊 Inicializando tabuleiro com água...\n");
    
    // Loop aninhado para inicializar todo o tabuleiro com água (0)
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;  // Preenche com água
        }
    }
    
    printf("✓ Tabuleiro inicializado com sucesso!\n\n");
    
    // === VALIDAÇÃO DAS POSIÇÕES DOS NAVIOS ===
    printf("🔍 Validando posições dos navios...\n");
    
    // Validação do navio horizontal
    if (navio1_linha < 0 || navio1_linha >= TAMANHO_TABULEIRO ||
        navio1_coluna < 0 || navio1_coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("❌ Erro: Navio horizontal fora dos limites do tabuleiro!\n");
        posicao_valida = 0;
    }
    
    // Validação do navio vertical
    if (navio2_linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO || navio2_linha < 0 ||
        navio2_coluna < 0 || navio2_coluna >= TAMANHO_TABULEIRO) {
        printf("❌ Erro: Navio vertical fora dos limites do tabuleiro!\n");
        posicao_valida = 0;
    }
    
    // Verificação de sobreposição (simples)
    // Verifica se os navios se cruzam
    if (navio1_linha == navio2_linha && 
        navio2_coluna >= navio1_coluna && 
        navio2_coluna < navio1_coluna + TAMANHO_NAVIO) {
        printf("❌ Erro: Navios se sobrepõem!\n");
        posicao_valida = 0;
    }
    
    if (posicao_valida) {
        printf("✓ Posições dos navios são válidas!\n\n");
    } else {
        printf("❌ Posições inválidas! Encerrando programa.\n");
        return 1;
    }
    
    // === POSICIONAMENTO DO NAVIO HORIZONTAL ===
    printf("🚢 Posicionando navio horizontal...\n");
    printf("📍 Posição: linha %d, colunas %d-%d\n", 
           navio1_linha, navio1_coluna, navio1_coluna + TAMANHO_NAVIO - 1);
    
    // Loop para posicionar o navio horizontal
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio1_linha][navio1_coluna + i] = navio_horizontal[i];
    }
    
    printf("✓ Navio horizontal posicionado!\n\n");
    
    // === POSICIONAMENTO DO NAVIO VERTICAL ===
    printf("🚢 Posicionando navio vertical...\n");
    printf("📍 Posição: linhas %d-%d, coluna %d\n", 
           navio2_linha, navio2_linha + TAMANHO_NAVIO - 1, navio2_coluna);
    
    // Loop para posicionar o navio vertical
    for (i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio2_linha + i][navio2_coluna] = navio_vertical[i];
    }
    
    printf("✓ Navio vertical posicionado!\n\n");
    
    // === EXIBIÇÃO DO TABULEIRO ===
    printf("╔══════════════════════════════════════════════════════════╗\n");
    printf("║                    TABULEIRO FINAL                      ║\n");
    printf("╚══════════════════════════════════════════════════════════╝\n\n");
    
    printf("🗺️  Legenda: %d = Água | %d = Navio\n\n", AGUA, NAVIO);
    
    // Cabeçalho com números das colunas
    printf("   ");  // Espaço para números das linhas
    for (j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf(" %d ", j);
    }
    printf("\n");
    
    // Linha separadora
    printf("   ");
    for (j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("---");
    }
    printf("\n");
    
    // Loop aninhado para exibir o tabuleiro
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d |", i);  // Número da linha
        
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("|\n");  // Fechamento da linha
    }
    
    // Linha separadora inferior
    printf("   ");
    for (j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("---");
    }
    printf("\n\n");
    
    // === RESUMO DOS NAVIOS POSICIONADOS ===
    printf("╔══════════════════════════════════════════════════════════╗\n");
    printf("║                  RESUMO DA FROTA                        ║\n");
    printf("╚══════════════════════════════════════════════════════════╝\n\n");
    
    printf("🚢 NAVIO 1 (Horizontal):\n");
    printf("   • Tamanho: %d posições\n", TAMANHO_NAVIO);
    printf("   • Posição: Linha %d, Colunas %d, %d, %d\n", 
           navio1_linha, navio1_coluna, navio1_coluna + 1, navio1_coluna + 2);
    printf("   • Orientação: Horizontal (→)\n\n");
    
    printf("🚢 NAVIO 2 (Vertical):\n");
    printf("   • Tamanho: %d posições\n", TAMANHO_NAVIO);
    printf("   • Posição: Linhas %d, %d, %d, Coluna %d\n", 
           navio2_linha, navio2_linha + 1, navio2_linha + 2, navio2_coluna);
    printf("   • Orientação: Vertical (↓)\n\n");
    
    // === ESTATÍSTICAS DO TABULEIRO ===
    int posicoes_agua = 0;
    int posicoes_navio = 0;
    
    // Conta posições de água e navios
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == AGUA) {
                posicoes_agua++;
            } else if (tabuleiro[i][j] == NAVIO) {
                posicoes_navio++;
            }
        }
    }
    
    printf("📊 ESTATÍSTICAS:\n");
    printf("   • Total de posições: %d\n", TAMANHO_TABULEIRO * TAMANHO_TABULEIRO);
    printf("   • Posições com água: %d\n", posicoes_agua);
    printf("   • Posições com navios: %d\n", posicoes_navio);
    printf("   • Navios posicionados: 2\n\n");
    
    printf("🎯 Tabuleiro de Batalha Naval criado com sucesso!\n");
    printf("🚀 Pronto para a próxima fase do desenvolvimento!\n");
    
    return 0;
}