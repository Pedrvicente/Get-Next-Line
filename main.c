/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedde-al <pedde-al@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:18:47 by pedde-al          #+#    #+#             */
/*   Updated: 2025/12/02 11:08:16 by pedde-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
    int     fd;
    char    *line;

    // Abrir o ficheiro (O_RDONLY = Apenas Leitura)
    fd = open("test.txt", O_RDONLY);
    
    // 1. Verificar se a abertura foi bem-sucedida
    if (fd == -1)
    {
        perror("Erro ao abrir o ficheiro");
        return (1);
    }

    // 2. Loop principal: Chama GNL até devolver NULL
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // CRÍTICO: Libertar a memória alocada por GNL
    }

    // 3. Fechar e terminar
    close(fd);
    return (0);
}