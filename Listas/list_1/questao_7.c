/* As variáveis em C estão organizadas em classes : auto, extern, register e static. Explique
cada uma delas. */

#auto
Variável auto só é visivel na área do programa ou dentro de um bloco delimitado por{}.Por exemplo, quando uma função é chamada,
    as variáveis são criadas e logo em seguida após o término, elas são excluidas automaticamente.São variáveis locais, raramente usada pois toda variável local da lingaguem C são "auto" por definição.

#extern
                                                                                                                        São variaveis globais,
    declaradas antes do main().Elas podem ser acessadas tanto para leitura quanto para alteração do seu valor.

#register
    São aplicadas na declaração do tipo char e int.Essa classe força o compilador C a manter a variavel em algum registrador da CPU.Uma variável armazenada direto no registrador CPU tem uma velocidade muito superior,
    pois a CPU nao precisa acessa - la a memória.

#static
                                    São como vairaveis locais,
    a diferença entre a auto é que a static nao são destruidas após a função ou bloco acabar,
    elas continuam existindo e conseguem guardar o ultimo valor atribuido.