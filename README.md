Acionamento de Música com TMC123G

## 📝 Descrição Técnica

Este repositório contém o desenvolvimento de um sistema embarcado para de acionar uma trilha sonora. O projeto foi concebido como parte dos requisitos avaliativos da disciplina SM66A - Sistemas Microcontrolados.

## ✨ Funcionalidades Implementadas (mínimo de 1)

- Reprodução de Música
- Controle de Início e Velocidade da Música
- Visualização da batida com LEDs

## ✨ Periféricos Utilizados (mínimo de 4)

- GPIO - Piezo Buzzer, RGB LEDs, Botões;
- PWM - Intensidade da cor do LED, Sinal Quadrado para o buzzer;
- Interrupt - Mudança de tempo imediato associado ao botão para variar a velocidade de repodução;
- Timer - Durações e frequências para o Delay e Tone utilizados no código.


## 🛠️ Hardware e Componentes (mínimo 1)

* Microcontrolador: TM4C123G
* Sensores: Botões de Entrada
* Atuadores: Piezo Buzzer, LEDS RGB

## ⚙️ Procedimento de Montagem e Execução

*(Esta seção deve ser detalhada ao longo do desenvolvimento)*

1.  Diagrama Elétrico:
![image](https://github.com/user-attachments/assets/1f1ccb4c-b55b-42ae-9317-8f56d2ffdf68)
![image](https://github.com/user-attachments/assets/c2d2ed0c-4e48-4e10-9885-6a53549f4ce1)
![image](https://github.com/user-attachments/assets/19c587b7-6149-4c4f-a906-a1352f441b36)

3.  **Configuração do Ambiente:** Detalhamento das bibliotecas e configurações da IDE necessárias.
4.  **Compilação e Upload:** Instruções para compilar o firmware e transferi-lo para o microcontrolador.

## 🚀 Cronograma e Evolução (Roadmap)

- [ ] Definição da arquitetura de software.
- [ ] Implementação do módulo de leitura de sensores.
- [ ] Implementação da lógica de controle.
- [ ] Validação e testes funcionais.
