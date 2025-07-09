Acionamento de Música com TMC123G

## 📝 Descrição Técnica

Este repositório contém o desenvolvimento de um sistema embarcado para acionar uma trilha sonora. O projeto foi concebido como parte dos requisitos avaliativos da disciplina SM66A - Sistemas Microcontrolados.

## ✨ Funcionalidades Implementadas 

- Reprodução de Música
- Controle de Início e Velocidade da Música
- Visualização da batida com LEDs

## ✨ Periféricos Utilizados 

- GPIO - Piezo Buzzer, RGB LEDs, Botões;
- PWM - Intensidade da cor do LED, Sinal Quadrado para o buzzer;
- Interrupt - Mudança de tempo imediato associado ao botão para variar a velocidade de repodução;
- Timer - Durações e frequências para o Delay e Tone utilizados no código.


## 🛠️ Hardware e Componentes 

* Microcontrolador: TM4C123G
* Sensores: Botões de Entrada
* Atuadores: Piezo Buzzer, LEDS RGB

## ⚙️ Procedimento de Montagem e Execução

1.  Diagrama Elétrico:
![image](https://github.com/user-attachments/assets/1f1ccb4c-b55b-42ae-9317-8f56d2ffdf68)
![image](https://github.com/user-attachments/assets/c2d2ed0c-4e48-4e10-9885-6a53549f4ce1)
![image](https://github.com/user-attachments/assets/19c587b7-6149-4c4f-a906-a1352f441b36)

Utilização das portas 32 (Botão SW1), 33 (Botão SW2), 37 (Led Azul), 38 (Led Verde), 39 (Led Vermelho), 40 (Piezo Buzzer). 

3.  Configuração do Ambiente: 
 - Energia.h
 - Código feito a partir do Energia e convertido para o Code Composer Studio.

4.  Compilação e Upload:
- Texas Instruments TM4C123
- BOOSTXL-MKII
- É necessário acoplar o BOOSTXL-MKII no TM4C123 de acordo com o mapeamento do datasheet e carregar o código pelo Code Composer Studio fazendo a importação do Energia. 

## 🚀 Cronograma e Evolução (Roadmap)

- [ ] Definição da arquitetura de software.
- ![image](https://github.com/user-attachments/assets/c2d03bdf-6285-45c6-8fc9-9924004ef966)

- [ ] Implementação do módulo de leitura de sensores.
- [ ] Implementação da lógica de controle.
- [ ] Validação e testes funcionais.
