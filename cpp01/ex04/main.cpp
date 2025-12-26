/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 03:55:37 by abendrih          #+#    #+#             */
/*   Updated: 2025/12/26 04:13:30 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv)
{
    if (argc != 4) 
    {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    // Ouvrir le fichier en lecture
    std::ifstream infile(filename.c_str());
    if (!infile.is_open()) 
    {
        std::cerr << "Error: cannot open file " << filename << std::endl;
        return 1;
    }

    // Ouvrir le fichier de sortie
    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile.is_open()) 
    {
        std::cerr << "Error: cannot create output file" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(infile, line)) 
    {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        outfile << line << std::endl;
    }
    infile.close();
    outfile.close();
    return 0;
}