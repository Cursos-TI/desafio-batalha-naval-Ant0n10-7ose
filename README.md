# ⚓ Batalha Naval MateCheck - Nível Mestre

Sistema avançado de Batalha Naval com habilidades especiais e áreas de efeito, desenvolvido em C usando matrizes bidimensionais e algoritmos condicionais complexos.

## 📋 Índice

- [Sobre o Projeto](#sobre-o-projeto)
- [Funcionalidades](#funcionalidades)
- [Pré-requisitos](#pré-requisitos)
- [Como Compilar](#como-compilar)
- [Como Executar](#como-executar)
- [Sistema de Habilidades](#sistema-de-habilidades)
- [Exemplos de Uso](#exemplos-de-uso)
- [Estrutura do Código](#estrutura-do-código)
- [Técnicas Implementadas](#técnicas-implementadas)

## 🎯 Sobre o Projeto

O **Batalha Naval MateCheck** é um sistema avançado que demonstra técnicas de programação em C através da implementação de habilidades especiais com áreas de efeito geométricas. O projeto representa o **Nível Mestre** com algoritmos condicionais complexos e manipulação avançada de matrizes.

### Características Principais:
- 🗺️ **Tabuleiro 10x10**: Matriz bidimensional para o campo de batalha
- ⚓ **Sistema de Navios**: Posicionamento estratégico no tabuleiro
- ⚡ **3 Habilidades Especiais**: Cone, Cruz e Octaedro
- 🎯 **Áreas de Efeito**: Matrizes 7x7 com padrões geométricos
- 🔄 **Sobreposição Dinâmica**: Aplicação de habilidades no tabuleiro
- 🛡️ **Preservação de Navios**: Proteção de elementos existentes

## 🚀 Funcionalidades

### 1. Sistema de Tabuleiro
- **Inicialização automática** com água (valor 0)
- **Posicionamento de navios** de demonstração
- **Visualização organizada** com coordenadas

### 2. Habilidades Especiais
- **CONE**: Área expandindo do topo para baixo
- **CRUZ**: Linhas perpendiculares centradas  
- **OCTAEDRO**: Formato losango (vista frontal)

### 3. Sistema de Aplicação
- **Sobreposição de matrizes** com validação de limites
- **Preservação de navios** durante aplicação
- **Reset automático** entre habilidades
- **Contagem de posições** afetadas

## 🛠️ Pré-requisitos

Para compilar e executar este programa, você precisa de:

- **Compilador C**: GCC, Clang, ou similar
- **Sistema Operacional**: Windows, Linux, macOS
- **Terminal/Prompt de Comando**

### Instalação do GCC:

**Windows:**
```bash
# Instalar MinGW-w64
# Ou usar Dev-C++, Code::Blocks, Visual Studio
```

**Linux (Ubuntu/Debian):**
```bash
sudo apt update
sudo apt install gcc
```

**macOS:**
```bash
xcode-select --install
```

## ⚙️ Como Compilar

### Compilação Básica:
```bash
gcc batalha_naval_matecheck.c -o batalha_naval
```

### Compilação com Debugging:
```bash
gcc -Wall -Wextra -g batalha_naval_matecheck.c -o batalha_naval
```

### Compilação Otimizada:
```bash
gcc -O2 batalha_naval_matecheck.c -o batalha_naval
```

## ▶️ Como Executar

### Windows:
```bash
batalha_naval.exe
```

### Linux/macOS:
```bash
./batalha_naval
```

## ⚡ Sistema de Habilidades

### Habilidade CONE 🔥
- **Formato**: Triângulo expandindo para baixo
- **Algoritmo**: `distancia_centro <= i && i <= centro_habilidade + 1`
- **Posição**: (2, 2)
- **Área**: Cresce linearmente por linha

### Habilidade CRUZ ✝️
- **Formato**: Linhas perpendiculares
- **Algoritmo**: `i == centro_habilidade || j == centro_habilidade`
- **Posição**: (6, 6)
- **Área**: Linha e coluna central

### Habilidade OCTAEDRO 💎
- **Formato**: Losango centrado
- **Algoritmo**: `dist_vertical + dist_horizontal <= centro_habilidade`
- **Posição**: (1, 7)
- **Área**: Distância Manhattan do centro

## 💡 Exemplos de Uso

### Exemplo 1: Inicialização do Sistema
```
╔══════════════════════════════════════════════════════════╗
║             BATALHA NAVAL - NÍVEL MESTRE                ║
║           Habilidades Especiais e Áreas de Efeito       ║
╚══════════════════════════════════════════════════════════╝

⚡ Sistema de Habilidades Especiais:
• Tabuleiro: 10x10
• Matrizes de habilidade: 7x7
• Água: 0 | Navios: 3 | Área de Efeito: 5

🎯 Habilidades Disponíveis:
• CONE: Área em forma de cone expandindo para baixo
• CRUZ: Área em forma de cruz centrada
• OCTAEDRO: Área em forma de losango (vista frontal)
```

### Exemplo 2: Matriz da Habilidade CONE
```
🔥 HABILIDADE CONE (7x7):
   0 0 0 3 0 0 0 
   0 0 3 3 3 0 0 
   0 3 3 3 3 3 0 
   3 3 3 3 3 3 3 
   3 3 3 3 3 3 3 
   0 0 0 0 0 0 0 
   0 0 0 0 0 0 0 
```

### Exemplo 3: Matriz da Habilidade CRUZ
```
✝️  HABILIDADE CRUZ (7x7):
   0 0 0 3 0 0 0 
   0 0 0 3 0 0 0 
   0 0 0 3 0 0 0 
   3 3 3 3 3 3 3 
   0 0 0 3 0 0 0 
   0 0 0 3 0 0 0 
   0 0 0 3 0 0 0 
```

### Exemplo 4: Matriz da Habilidade OCTAEDRO
```
💎 HABILIDADE OCTAEDRO (7x7):
   0 0 0 3 0 0 0 
   0 0 3 3 3 0 0 
   0 3 3 3 3 3 0 
   3 3 3 3 3 3 3 
   0 3 3 3 3 3 0 
   0 0 3 3 3 0 0 
   0 0 0 3 0 0 0 
```

### Exemplo 5: Tabuleiro com Habilidade Aplicada
```
╔══════════════════════════════════════════════════════════╗
║              TABULEIRO COM HABILIDADE CONE              ║
╚══════════════════════════════════════════════════════════╝

🗺️  Legenda: 0=Água | 3=Navio | 5=Área de Efeito

    0  1  2  3  4  5  6  7  8  9 
0 | 0  0  5  0  0  0  0  0  0  0 |
1 | 0  3  3  3  5  0  0  0  0  0 |
2 | 5  5  5  5  5  0  0  0  0  0 |
3 | 5  5  5  5  5  5  5  0  0  0 |
4 | 5  5  5  5  5  5  5  0  0  0 |
5 | 0  0  0  0  0  0  0  0  3  0 |
6 | 0  0  0  0  0  0  0  0  3  0 |
7 | 0  0  0  0  0  0  0  0  3  0 |
8 | 0  0  3  0  3  0  0  0  0  0 |
9 | 0  0  0  3  0  0  0  0  0  0 |
```

## 🏗️ Estrutura do Código

### Constantes Principais:
```c
const int TAMANHO_TABULEIRO = 10;    // Tabuleiro 10x10
const int TAMANHO_HABILIDADE = 7;    // Matrizes de habilidade 7x7
const int AGUA = 0;                  // Representação da água
const int NAVIO = 3;                 // Representação dos navios
const int HABILIDADE = 5;            // Representação das áreas de efeito
```

### Estruturas de Dados:
```c
int tabuleiro[10][10];               // Tabuleiro principal
int habilidade_cone[7][7];           // Matriz da habilidade cone
int habilidade_cruz[7][7];           // Matriz da habilidade cruz
int habilidade_octaedro[7][7];       // Matriz da habilidade octaedro
```

### Algoritmos Principais:

#### 1. Algoritmo do Cone:
```c
int distancia_centro = abs(j - centro_habilidade);
if (distancia_centro <= i && i <= centro_habilidade + 1) {
    habilidade_cone[i][j] = AREA_ATIVA;
}
```

#### 2. Algoritmo da Cruz:
```c
if (i == centro_habilidade || j == centro_habilidade) {
    habilidade_cruz[i][j] = AREA_ATIVA;
}
```

#### 3. Algoritmo do Octaedro:
```c
int dist_vertical = abs(i - centro_habilidade);
int dist_horizontal = abs(j - centro_habilidade);
if (dist_vertical + dist_horizontal <= centro_habilidade) {
    habilidade_octaedro[i][j] = AREA_ATIVA;
}
```

### Fluxo Principal:
1. **Inicialização**: Criação do tabuleiro e posicionamento de navios
2. **Geração de Habilidades**: Criação das matrizes com algoritmos condicionais
3. **Exibição de Matrizes**: Visualização dos padrões geométricos
4. **Aplicação no Tabuleiro**: Sobreposição com validação de limites
5. **Análise Final**: Contagem de posições afetadas

## 🎯 Técnicas Implementadas

### 1. Loops Aninhados
- **Inicialização de matrizes**: Preenchimento sistemático
- **Criação de padrões**: Algoritmos geométricos
- **Sobreposição**: Aplicação controlada no tabuleiro

```c
for (i = 0; i < TAMANHO_HABILIDADE; i++) {
    for (j = 0; j < TAMANHO_HABILIDADE; j++) {
        // Lógica condicional para cada habilidade
    }
}
```

### 2. Condicionais Complexas
- **Algoritmos geométricos**: Criação de formas específicas
- **Validação de limites**: Prevenção de acessos inválidos
- **Preservação de elementos**: Proteção de navios existentes

```c
if (linha_tabuleiro >= 0 && linha_tabuleiro < TAMANHO_TABULEIRO &&
    coluna_tabuleiro >= 0 && coluna_tabuleiro < TAMANHO_TABULEIRO) {
    if (tabuleiro[linha_tabuleiro][coluna_tabuleiro] != NAVIO) {
        tabuleiro[linha_tabuleiro][coluna_tabuleiro] = HABILIDADE;
    }
}
```

### 3. Manipulação de Matrizes
- **Sobreposição controlada**: Coordenação entre diferentes matrizes
- **Transformação de coordenadas**: Conversão entre sistemas
- **Reset seletivo**: Limpeza de efeitos específicos

### 4. Algoritmos Matemáticos
- **Distância Manhattan**: Para formato losango
- **Distância linear**: Para formato cone
- **Interseção de linhas**: Para formato cruz

## 📊 Resumo Técnico

| Habilidade | Algoritmo | Formato | Posição | Técnica |
|------------|-----------|---------|---------|---------|
| **CONE** | Distância linear crescente | Triângulo ▽ | (2,2) | Condicionais aninhadas |
| **CRUZ** | Interseção linha/coluna | Cruz ✝️ | (6,6) | Operadores lógicos |
| **OCTAEDRO** | Distância Manhattan | Losango ◊ | (1,7) | Soma de distâncias |

### Conceitos Demonstrados:
- ✅ **Matrizes bidimensionais** com múltiplas camadas
- ✅ **Algoritmos condicionais** para formas geométricas
- ✅ **Validação de limites** em tempo real
- ✅ **Sobreposição de estruturas** com preservação
- ✅ **Visualização dinâmica** de dados complexos
- ✅ **Contagem e análise** estatística

### Estrutura de Arquivos:
```
batalha_naval_matecheck/
├── batalha_naval_matecheck.c    # Código principal
├── README.md                    # Este documento  
└── batalha_naval.exe           # Executável (após compilação)
```

## 📝 Licença

Este projeto é desenvolvido para fins educacionais e demonstração de técnicas avançadas de programação em C.

## 👨‍💻 Autor

**Antonio José** - Desenvolvimento do sistema Batalha Naval MateCheck

---

### 🎯 Dicas de Uso:

- **Análise de Padrões**: Observe como cada algoritmo cria formas diferentes
- **Experimentação**: Modifique coordenadas e tamanhos para testar limites
- **Debugging**: Use flags de compilação para análise detalhada
- **Visualização**: Compare as matrizes puras com a aplicação no tabuleiro

**Explore o poder das matrizes e algoritmos condicionais! ⚓**