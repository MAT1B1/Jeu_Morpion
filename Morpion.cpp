#include <iostream> 

void display(char *plateau);
bool is_win(char *plateau);
bool is_tie(char *plateau);
void play(char *plateau, char signe);
void erase(char *plateau);

int main(){
    char plateau[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char signe[] = {'o', 'x'};
    int player = 1;
    char is_play;
    do
    {
        display(plateau);
        do
        {
            player = player == 0 ? 1 : 0;
            play(plateau, signe[player]);
            
            display(plateau);
        } while (!is_tie(plateau) && !is_win(plateau));
        if(is_win(plateau))
        {
            std::cout << "\njoueur " << player+1 << " a gagne !!!\n";
        }
        else
        {
            std::cout << "\nc'est une egalite\n";
        }
        do
        {
            std::cout << "\nvoulez vous rejouer ? [y/n]: ";
            std::cin >> is_play;
        } while (is_play != 'y' && is_play != 'n');
        erase(plateau);
    } while (is_play == 'y');
    
    return 0;
}

void display(char *plateau)
{   
    std::cout << "\n\nJEU DU MORPION\n";
    std::cout << "\n\n     |     |\t\t* signes: joueur 1 = 'o'\n";
    std::cout << "  " << plateau[0] << "  |  " << plateau[1] << "  |  " << plateau[2] << "\t\t\t  joueur 2 = 'x'";
    std::cout << "\n_____|_____|_____\n     |     |\t\t* les cases sont:\n";
    std::cout << "  " << plateau[3] << "  |  " << plateau[4] << "  |  " << plateau[5] << "\t\t\t 1 2 3";
    std::cout << "\n     |     |\t\t\t 4 5 6\n_____|_____|_____\t\t 7 8 9\n     |     |\n";
    std::cout << "  " << plateau[6] << "  |  " << plateau[7] << "  |  " << plateau[8];
    std::cout << "\n     |     |\n";
}
bool is_win(char *plateau)
{   
    int win[][3] = {{0, 1, 2},
                    {3, 4, 5},
                    {6, 7, 8},
                    {0, 3, 6},
                    {1, 4, 7},
                    {2, 5, 8},
                    {0, 4, 8},
                    {2, 4, 6}};
    
    for(int i = 0; i < 8; i++)
    {   
        if(plateau[win[i][0]] != ' ' && plateau[win[i][0]] == plateau[win[i][1]] && plateau[win[i][1]] == plateau[win[i][2]])
        {
            return true;
        }
    }    
    return false;
}
bool is_tie(char *plateau)
{   
    for(int i = 0; i < 9; i++)
    {
        if(plateau[i] == ' ')
        {
            return false;
        }
    }
    return true;
}
void play(char *plateau, char signe)
{
    int pos;
    std::cout << '\n';
    do
    {
        std::cout << (signe == 'o' ? "joueur 1" : "joueur 2") << ", indiquer la case ou mettre le signe: ";
        std::cin >> pos;
    } while (1 > pos || pos > 9 || plateau[pos-1] != ' ');
    
    plateau[pos-1] = signe;
}
void erase(char *plateau)
{
    for(int i = 0; i < 9; i++)
    {
        plateau[i] = ' ';
    }
}