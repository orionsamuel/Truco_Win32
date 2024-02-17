# INF1900 Projeto Final (G11)

## Índice
- Autores
- Descrição do Projeto
- Funcionalidades
- Como jogar
- Tecnologias utilizadas

## Autores
- [@andysonraphaell](https://www.github.com/andysonraphaell)
- [@henriquefl](https://www.github.com/henriquefl)
- [@orionsamuel](https://www.github.com/orionsamuel)
- [@silvathiago](https://www.github.com/silvathiago)

## Descrição do Projeto
O Truco Win32 é um jogo de truco desenvolvido para a plataforma Windows. Este projeto se refere à atividade final do curso de C++ INF1900 da Unicamp. São utilizados conceitos de Orientação a Objetos, Concorrência e Multithreading, Tratamento de Exceção, Interface de Usuário, Smart Pointers, Serialização e Persistência e Padrão arquitetural. 
O programa gerado emula um jogo de truco com regras baseadas no truco paulista onde as partidas são divididos em mãos e vazas.

## Funcionalidades
- Jogo de truco para dois jogadores
- Interface gráfica intuitiva
- Regras do truco paulista
## Como jogar

1. Inicie o jogo clicando em Play Game.
2. Os jogadores recebem cartas do deck no início de cada mão.
3. Os jogadores se revezam para fazer suas jogadas. Para escolher, basta clicar na carta escolhida.
4. A mão continua até que todas as cartas sejam jogadas.
5. O vencedor da mão é determinado com base nas regras padrões do truco, levando em consideração as cartas na mão dos jogadores e a carta Manilha que fica na região acima da tela.

## Tecnologias utilizadas
O projeto foi desenvolvido utilizando as seguintes tecnologias:
- C++
- Win32 API

### Classes Principais

1. **game**
Armazena as informações necessárias para o gerenciamento de um jogo completo de truco contendo mãos e vazas.

- `playerList`: Lista dos jogadores participantes;
- `handList`: Conjunto de mãos do jogo;
- `winnerPlayer`: Jogador vencedor da partida;
- `teamList`: Lista de times participantes no jogo;

2. **hand**
Armazena as informações necessárias para o gerenciamento de uma mão do truco contendo vazas

- `manilha`: Carta manilha;
- `keyCard`: Última carta a ser exibida;
- `setList`: Conjunto de sets contidos na mão;
- `winner`: Player que foi o vencedor da mão;
- `maoValue`: Valor da mão;
- `trucoPlayer`: Player que pediu truco;
- `startPlayer`: Player que começa a vaza;

3. **set**
Armazena as informações necessárias para o gerenciamento de uma vaza do truco

- `cardList`: Lista de cartas do set;
- `currentPlayer`: Player que está na vez de jogar;
- `winnerPlayer`: Player vencedor da vaza;
- `strongestCard`: Carta mais forte da vaza;
- `startPlayer`: Player que inicia a vaza;

4. **deck**
Armazena uma coleção de cartas, pode ser interpretado como o baralho ou mesmo a coleção de cartas de cada jogador.

- `baseCards`: Coleção de cartas, pode ser interpretado como o baralho ou mesmo a coleção de cartas de cada jogador;

5. **card**
Representa uma carta individual, contendo valor e naipe.

- `suit`: Naipe da carta;
- `value`: Valor da carta;

6. **player**
Contém informações sobre o jogador, incluindo o nome e o tipo.

- `name`: Nome do jogador;
- `type`: Tipo do jogador (CPU or Player);

7. **team**
Contém informações sobre o time.

- `teamId`: Código do time
- `teamName`: Nome do time;
- `members`: Conjunto de Players que estão no time;
- `score`: Pontuação atual do time;

## Diagrama de Classes
![Diagrama de classes](Documents/diagrama.drawio.png?raw=true "Title")




