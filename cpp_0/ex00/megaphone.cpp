/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iheb <iheb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:57:40 by iheb              #+#    #+#             */
/*   Updated: 2025/07/07 14:51:03 by iheb             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    char up_char;
    if (argc == 1)
        std :: cout << "* LOUD AND UNBEREABLE FEEDBACK NOISE *\n";
    for (int i = 1; argv[i]; i++)
    {
        for (int j = 0; argv[i][j]; j++)
        {
            up_char = toupper(argv[i][j]);
            std::cout << up_char;
        }
    }
    std::cout << std::endl;
    return 0;
}