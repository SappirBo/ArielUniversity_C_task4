//
// Created by sappi on 12/24/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int toInt(char num)
{
    int ans = num-48;
    return ans; 
}

int main()
{
    node graph;
    pnode pGraph = &graph;

    char input = NULL;
    while(scanf("%c",&input) != EOF)
    {
        if(input == 'A')
        {
            build_graph_cmd(pGraph);
            scanf("%c",&input);
            while(input == 'n')
            {
                scanf("%d",&id);
                scanf("%c",&input);
                while(input >= 48 && input <= 57)
                {
                    to = toInt(input);
                    scanf("%c",&input);
                    weight = toInt(input);
                    scanf("%c",&input);

                    
                }
            }
        }
    }
}
