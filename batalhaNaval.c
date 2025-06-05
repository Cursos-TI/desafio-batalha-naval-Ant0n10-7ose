#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.


int main() {
    // === DECLARAÇÃO DAS CONSTANTES ===
    const int TAMANHO_TABULEIRO = 10;
    const int TAMANHO_NAVIO = 3;
    const int TAMANHO_HABILIDADE = 7;  // Matrizes 7x7 para habilidades
    
    // Códigos de representação
    const int AGUA = 0;
    const int NAVIO = 3;
    const int HABILIDADE = 5;
    const int AREA_ATIVA = 1;
    const int AREA_INATIVA = 0;
    
    // === DECLARAÇÃO DAS MATRIZES ===
    // Tabuleiro principal
    int tabuleiro[10][10];
    
    // Matrizes de habilidades (7x7)
    int habilidade_cone[7][7];
    int habilidade_cruz[7][7];
    int habilidade_octaedro[7][7];
    
    // Variáveis auxiliares
    int i, j;
    int linha_origem, coluna_origem;
    int linha_tabuleiro, coluna_tabuleiro;
    int centro_habilidade = TAMANHO_HABILIDADE / 2;  // Centro da matriz de habilidade
    
    // Coordenadas das habilidades no tabuleiro
    int cone_linha = 2, cone_coluna = 2;
    int cruz_linha = 6, cruz_coluna = 6;
    int octaedro_linha = 1, octaedro_coluna = 7;
    
    // === APRESENTAÇÃO DO PROGRAMA ===
    printf("╔══════════════════════════════════════════════════════════╗\n");
    printf("║             BATALHA NAVAL - NÍVEL MESTRE                ║\n");
    printf("║           Habilidades Especiais e Áreas de Efeito       ║\n");
    printf("╚══════════════════════════════════════════════════════════╝\n\n");
    
    printf("⚡ Sistema de Habilidades Especiais:\n");
    printf("• Tabuleiro: %dx%d\n", TAMANHO_TABULEIRO, TAMANHO_TABULEIRO);
    printf("• Matrizes de habilidade: %dx%d\n", TAMANHO_HABILIDADE, TAMANHO_HABILIDADE);
    printf("• Água: %d | Navios: %d | Área de Efeito: %d\n\n", AGUA, NAVIO, HABILIDADE);
    
    printf("🎯 Habilidades Disponíveis:\n");
    printf("• CONE: Área em forma de cone expandindo para baixo\n");
    printf("• CRUZ: Área em forma de cruz centrada\n");
    printf("• OCTAEDRO: Área em forma de losango (vista frontal)\n\n");
    
    // === INICIALIZAÇÃO DO TABULEIRO PRINCIPAL ===
    printf("🌊 Inicializando tabuleiro principal...\n");
    
    // Loop aninhado para inicializar tabuleiro
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
    
    // Posicionamento de alguns navios para demonstração
    tabuleiro[1][1] = NAVIO; tabuleiro[1][2] = NAVIO; tabuleiro[1][3] = NAVIO;  // Horizontal
    tabuleiro[5][8] = NAVIO; tabuleiro[6][8] = NAVIO; tabuleiro[7][8] = NAVIO;  // Vertical
    tabuleiro[8][2] = NAVIO; tabuleiro[9][3] = NAVIO; tabuleiro[8][4] = NAVIO;  // Diagonal
    
    printf("✓ Tabuleiro inicializado com navios de demonstração!\n\n");
    
    // === CRIAÇÃO DA HABILIDADE CONE ===
    printf("🔥 Gerando habilidade CONE...\n");
    
    // Inicializar matriz do cone com zeros
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade_cone[i][j] = AREA_INATIVA;
        }
    }
    
    // Lógica condicional para criar formato de cone
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Distância do centro horizontalmente
            int distancia_centro = abs(j - centro_habilidade);
            
            // Cone: largura aumenta conforme desce
            // Na linha 0 (topo): apenas centro
            // Na linha 1: centro ± 1
            // Na linha 2: centro ± 2, etc.
            if (distancia_centro <= i && i <= centro_habilidade + 1) {
                habilidade_cone[i][j] = AREA_ATIVA;
            }
        }
    }
    
    printf("✓ Habilidade CONE criada! Formato: ponto no topo expandindo\n\n");
    
    // === CRIAÇÃO DA HABILIDADE CRUZ ===
    printf("✝️  Gerando habilidade CRUZ...\n");
    
    // Inicializar matriz da cruz com zeros
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade_cruz[i][j] = AREA_INATIVA;
        }
    }
    
    // Lógica condicional para criar formato de cruz
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Cruz: linha central horizontal E coluna central vertical
            if (i == centro_habilidade || j == centro_habilidade) {
                habilidade_cruz[i][j] = AREA_ATIVA;
            }
        }
    }
    
    printf("✓ Habilidade CRUZ criada! Formato: linhas perpendiculares\n\n");
    
    // === CRIAÇÃO DA HABILIDADE OCTAEDRO (LOSANGO) ===
    printf("💎 Gerando habilidade OCTAEDRO (losango)...\n");
    
    // Inicializar matriz do octaedro com zeros
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            habilidade_octaedro[i][j] = AREA_INATIVA;
        }
    }
    
    // Lógica condicional para criar formato de losango (octaedro frontal)
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Distâncias do centro
            int dist_vertical = abs(i - centro_habilidade);
            int dist_horizontal = abs(j - centro_habilidade);
            
            // Losango: soma das distâncias <= raio
            if (dist_vertical + dist_horizontal <= centro_habilidade) {
                habilidade_octaedro[i][j] = AREA_ATIVA;
            }
        }
    }
    
    printf("✓ Habilidade OCTAEDRO criada! Formato: losango centrado\n\n");
    
    // === EXIBIÇÃO DAS MATRIZES DE HABILIDADE ===
    printf("╔══════════════════════════════════════════════════════════╗\n");
    printf("║                 MATRIZES DE HABILIDADE                  ║\n");
    printf("╚══════════════════════════════════════════════════════════╝\n\n");
    
    // Exibir habilidade CONE
    printf("🔥 HABILIDADE CONE (%dx%d):\n", TAMANHO_HABILIDADE, TAMANHO_HABILIDADE);
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        printf("   ");
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade_cone[i][j] == AREA_ATIVA) {
                printf("3 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");
    
    // Exibir habilidade CRUZ
    printf("✝️  HABILIDADE CRUZ (%dx%d):\n", TAMANHO_HABILIDADE, TAMANHO_HABILIDADE);
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        printf("   ");
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade_cruz[i][j] == AREA_ATIVA) {
                printf("3 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");
    
    // Exibir habilidade OCTAEDRO
    printf("💎 HABILIDADE OCTAEDRO (%dx%d):\n", TAMANHO_HABILIDADE, TAMANHO_HABILIDADE);
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        printf("   ");
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade_octaedro[i][j] == AREA_ATIVA) {
                printf("3 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");
    
    // === APLICAÇÃO DA HABILIDADE CONE NO TABULEIRO ===
    printf("⚡ Aplicando habilidade CONE no tabuleiro...\n");
    printf("📍 Ponto de origem: (%d, %d)\n", cone_linha, cone_coluna);
    
    // Loop aninhado para sobrepor habilidade ao tabuleiro
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Se a posição está ativa na matriz de habilidade
            if (habilidade_cone[i][j] == AREA_ATIVA) {
                // Calcular posição correspondente no tabuleiro
                linha_tabuleiro = cone_linha - centro_habilidade + i;
                coluna_tabuleiro = cone_coluna - centro_habilidade + j;
                
                // Verificar se está dentro dos limites do tabuleiro
                if (linha_tabuleiro >= 0 && linha_tabuleiro < TAMANHO_TABULEIRO &&
                    coluna_tabuleiro >= 0 && coluna_tabuleiro < TAMANHO_TABULEIRO) {
                    
                    // Aplicar efeito apenas se não for navio (preservar navios)
                    if (tabuleiro[linha_tabuleiro][coluna_tabuleiro] != NAVIO) {
                        tabuleiro[linha_tabuleiro][coluna_tabuleiro] = HABILIDADE;
                    }
                }
            }
        }
    }
    
    printf("✓ Habilidade CONE aplicada!\n\n");
    
    // === EXIBIÇÃO DO TABULEIRO COM CONE ===
    printf("╔══════════════════════════════════════════════════════════╗\n");
    printf("║              TABULEIRO COM HABILIDADE CONE              ║\n");
    printf("╚══════════════════════════════════════════════════════════╝\n\n");
    
    printf("🗺️  Legenda: 0=Água | 3=Navio | 5=Área de Efeito\n\n");
    
    // Cabeçalho
    printf("   ");
    for (j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf(" %d ", j);
    }
    printf("\n");
    
    // Exibir tabuleiro com habilidade aplicada
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d |", i);
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
    
    // === RESETAR TABULEIRO E APLICAR CRUZ ===
    // Limpar efeitos anteriores
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == HABILIDADE) {
                tabuleiro[i][j] = AGUA;
            }
        }
    }
    
    printf("⚡ Aplicando habilidade CRUZ no tabuleiro...\n");
    printf("📍 Ponto de origem: (%d, %d)\n", cruz_linha, cruz_coluna);
    
    // Aplicar habilidade CRUZ
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade_cruz[i][j] == AREA_ATIVA) {
                linha_tabuleiro = cruz_linha - centro_habilidade + i;
                coluna_tabuleiro = cruz_coluna - centro_habilidade + j;
                
                if (linha_tabuleiro >= 0 && linha_tabuleiro < TAMANHO_TABULEIRO &&
                    coluna_tabuleiro >= 0 && coluna_tabuleiro < TAMANHO_TABULEIRO) {
                    
                    if (tabuleiro[linha_tabuleiro][coluna_tabuleiro] != NAVIO) {
                        tabuleiro[linha_tabuleiro][coluna_tabuleiro] = HABILIDADE;
                    }
                }
            }
        }
    }
    
    printf("✓ Habilidade CRUZ aplicada!\n\n");
    
    // === EXIBIÇÃO DO TABULEIRO COM CRUZ ===
    printf("╔══════════════════════════════════════════════════════════╗\n");
    printf("║              TABULEIRO COM HABILIDADE CRUZ              ║\n");
    printf("╚══════════════════════════════════════════════════════════╝\n\n");
    
    printf("🗺️  Legenda: 0=Água | 3=Navio | 5=Área de Efeito\n\n");
    
    // Cabeçalho
    printf("   ");
    for (j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf(" %d ", j);
    }
    printf("\n");
    
    // Exibir tabuleiro com cruz
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d |", i);
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
    
    // === RESETAR E APLICAR OCTAEDRO ===
    // Limpar efeitos da cruz
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == HABILIDADE) {
                tabuleiro[i][j] = AGUA;
            }
        }
    }
    
    printf("⚡ Aplicando habilidade OCTAEDRO no tabuleiro...\n");
    printf("📍 Ponto de origem: (%d, %d)\n", octaedro_linha, octaedro_coluna);
    
    // Aplicar habilidade OCTAEDRO
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade_octaedro[i][j] == AREA_ATIVA) {
                linha_tabuleiro = octaedro_linha - centro_habilidade + i;
                coluna_tabuleiro = octaedro_coluna - centro_habilidade + j;
                
                if (linha_tabuleiro >= 0 && linha_tabuleiro < TAMANHO_TABULEIRO &&
                    coluna_tabuleiro >= 0 && coluna_tabuleiro < TAMANHO_TABULEIRO) {
                    
                    if (tabuleiro[linha_tabuleiro][coluna_tabuleiro] != NAVIO) {
                        tabuleiro[linha_tabuleiro][coluna_tabuleiro] = HABILIDADE;
                    }
                }
            }
        }
    }
    
    printf("✓ Habilidade OCTAEDRO aplicada!\n\n");
    
    // === EXIBIÇÃO FINAL COM OCTAEDRO ===
    printf("╔══════════════════════════════════════════════════════════╗\n");
    printf("║            TABULEIRO COM HABILIDADE OCTAEDRO            ║\n");
    printf("╚══════════════════════════════════════════════════════════╝\n\n");
    
    printf("🗺️  Legenda: 0=Água | 3=Navio | 5=Área de Efeito\n\n");
    
    // Cabeçalho
    printf("   ");
    for (j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf(" %d ", j);
    }
    printf("\n");
    
    // Exibir tabuleiro final
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d |", i);
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf(" %d ", tabuleiro[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
    
    // === ANÁLISE FINAL ===
    printf("╔══════════════════════════════════════════════════════════╗\n");
    printf("║                    ANÁLISE FINAL                        ║\n");
    printf("╚══════════════════════════════════════════════════════════╝\n\n");
    
    // Contar posições afetadas por cada habilidade
    int posicoes_afetadas = 0;
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            if (tabuleiro[i][j] == HABILIDADE) {
                posicoes_afetadas++;
            }
        }
    }
    
    printf("📊 ESTATÍSTICAS DAS HABILIDADES:\n");
    printf("• Habilidades implementadas: 3 (Cone, Cruz, Octaedro)\n");
    printf("• Tamanho das matrizes: %dx%d\n", TAMANHO_HABILIDADE, TAMANHO_HABILIDADE);
    printf("• Posições afetadas no tabuleiro: %d\n", posicoes_afetadas);
    printf("• Algoritmos condicionais: Utilizados para todas as formas\n");
    printf("• Validação de limites: Implementada para sobreposição\n\n");
    
    printf("🎯 TÉCNICAS IMPLEMENTADAS:\n");
    printf("✓ Loops aninhados para construção de matrizes\n");
    printf("✓ Condicionais complexas para formas geométricas\n");
    printf("✓ Sobreposição de matrizes com validação de limites\n");
    printf("✓ Preservação de elementos existentes (navios)\n");
    printf("✓ Visualização dinâmica com diferentes representações\n\n");
    
    printf("🏆 NÍVEL MESTRE CONCLUÍDO COM SUCESSO!\n");
    printf("🚀 Sistema de habilidades especiais implementado!\n");
    
    return 0;
}