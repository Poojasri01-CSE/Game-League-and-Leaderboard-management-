#include <iostream>
#include <string>
using namespace std;
class Player
{
private:
    int playerID;
    string gamerName;
    string teamName;
    string gameName;
    string playerType;
    int matchesPlayed;
    int wins;
    int losses;
    int draws;
    int score;
public:
    void inputPlayer()
    {
        cout << "\nEnter Player ID: ";
        cin >> playerID;
        cout << "Enter Gamer Name: ";
        cin >> gamerName;
        cout << "Enter Team Name: ";
        cin >> teamName;
        cout << "Enter Game Name: ";
        cin >> gameName;
        cout << "Enter Player Type: ";
        cin >> playerType;
        matchesPlayed = 0;
        wins = 0;
        losses = 0;
        draws = 0;
        score = 0;
    }
    int getPlayerID()
    {
        return playerID;
    }
    void recordResult()
    {
        int choice;

        cout << "\n1. Win";
        cout << "\n2. Loss";
        cout << "\n3. Draw";
        cout << "\nEnter match result: ";
        cin >> choice;
        if (choice == 1)
        {
            wins++;
            matchesPlayed++;
            score = score + 3;

            cout << "Win recorded successfully!\n";
        }
        else if (choice == 2)
        {
            losses++;
            matchesPlayed++;

            cout << "Loss recorded successfully!\n";
        }
        else if (choice == 3)
        {
            draws++;
            matchesPlayed++;
            score = score + 1;

            cout << "Draw recorded successfully!\n";
        }
        else
        {
            cout << "Invalid match result!\n";
        }
    }
    int getTotalPoints()
    {
        return (wins * 3) + (draws * 1);
    }
    float getAverageScore()
    {
        if (matchesPlayed == 0)
        {
            return 0;
        }
        return (float)score / matchesPlayed;
    }
    float getWinPercentage()
    {
        if (matchesPlayed == 0)
        {
            return 0;
        }
        return ((float)wins / matchesPlayed) * 100;
    }
    string getPlayerLevel()
    {
        float percentage = getWinPercentage();
        if (percentage >= 80)
        {
            return "Elite";
        }
        else if (percentage >= 60)
        {
            return "Pro";
        }
        else if (percentage >= 40)
        {
            return "Intermediate";
        }
        else
        {
            return "Beginner";
        }
    }
    void updateScore()
    {
        int newScore;
        cout << "Enter new score: ";
        cin >> newScore;
        if (newScore < 0)
        {
            cout << "Score cannot be negative!\n";
        }
        else
        {
            score = newScore;
            cout << "Score updated successfully!\n";
        }
    }
    int getScore()
    {
        return score;
    }
    int getWins()
    {
        return wins;
    }
    void displayPlayer()
    {
        cout << "\n----------------------------------\n";
        cout << "Player ID       : " << playerID << endl;
        cout << "Gamer Name      : " << gamerName << endl;
        cout << "Team Name       : " << teamName << endl;
        cout << "Game Name       : " << gameName << endl;
        cout << "Player Type     : " << playerType << endl;
        cout << "Matches Played  : " << matchesPlayed << endl;
        cout << "Wins            : " << wins << endl;
        cout << "Losses          : " << losses << endl;
        cout << "Draws           : " << draws << endl;
        cout << "Score           : " << score << endl;
        cout << "Total Points    : " << getTotalPoints() << endl;
        cout << "Average Score   : " << getAverageScore() << endl;
        cout << "Win Percentage  : " << getWinPercentage() << "%" << endl;
        cout << "Player Level    : " << getPlayerLevel() << endl;
    }
};
int searchPlayer(Player players[], int n, int id)
{
    for (int i = 0; i < n; i++)
    {
        if (players[i].getPlayerID() == id)
        {
            return i;
        }
    }
    return -1;
}
void displayAllPlayers(Player players[], int n)
{
    if (n == 0)
    {
        cout << "\nNo players available.\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        players[i].displayPlayer();
    }
}
void recordMatch(Player players[], int n)
{
    int id;
    cout << "\nEnter Player ID: ";
    cin >> id;
    int position = searchPlayer(players, n, id);

    if (position == -1)
    {
        cout << "Player not found!\n";
    }
    else
    {
        players[position].recordResult();
    }
}
void updatePlayerScore(Player players[], int n)
{
    int id;
    cout << "\nEnter Player ID: ";
    cin >> id;
    int position = searchPlayer(players, n, id);
    if (position == -1)
    {
        cout << "Player not found!\n";
    }
    else
    {
        players[position].updateScore();
    }
}
void comparePlayers(Player players[], int n)
{
    int id1, id2;
    cout << "\nEnter first Player ID: ";
    cin >> id1;
    cout << "Enter second Player ID: ";
    cin >> id2;
    int p1 = searchPlayer(players, n, id1);
    int p2 = searchPlayer(players, n, id2);
    if (p1 == -1 || p2 == -1)
    {
        cout << "One or both players not found!\n";
        return;
    }
    cout << "\nPlayer " << id1;
    cout << "\nTotal Points: " << players[p1].getTotalPoints();
    cout << "\nWins: " << players[p1].getWins();
    cout << "\nScore: " << players[p1].getScore();
    cout << "\n\nPlayer " << id2;
    cout << "\nTotal Points: " << players[p2].getTotalPoints();
    cout << "\nWins: " << players[p2].getWins();
    cout << "\nScore: " << players[p2].getScore();
    if (players[p1].getTotalPoints() >
        players[p2].getTotalPoints())
    {
        cout << "\n\nPlayer " << id1 << " is better.\n";
    }
    else if (players[p2].getTotalPoints() >
             players[p1].getTotalPoints())
    {
        cout << "\nPlayer " << id2 << " is better.\n";
    }
    else
    {
        cout << "\nBoth players have the same points.\n";
    }
}
void displayLeaderboard(Player players[], int n)
{
    if (n == 0)
    {
        cout << "\nNo players available.\n";
        return;
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (players[i].getTotalPoints() <
                players[j].getTotalPoints())
            {
                Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }
    cout << "\nLEADERBOARD\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Rank " << i + 1
             << "   Player ID: "
             << players[i].getPlayerID()
             << "   Points: "
             << players[i].getTotalPoints()
             << endl;
    }
}
void findTopPlayer(Player players[], int n)
{
    if (n == 0)
    {
        cout << "\nNo players available.\n";
        return;
    }
    int position = 0;
    for (int i = 1; i < n; i++)
    {
        if (players[i].getTotalPoints() >
            players[position].getTotalPoints())
        {
            position = i;
        }
    }
    cout << "\n TOP PLAYER\n";
    players[position].displayPlayer();
}
void findHighestScorer(Player players[], int n)
{
    if (n == 0)
    {
        cout << "\nNo players available.\n";
        return;
    }
    int position = 0;
    for (int i = 1; i < n; i++)
    {
        if (players[i].getScore() >
            players[position].getScore())
        {
            position = i;
        }
    }
    cout << "\nHIGHEST SCORER\n";
    players[position].displayPlayer();
}
void findMostConsistent(Player players[], int n)
{
    if (n == 0)
    {
        cout << "\nNo players available.\n";
        return;
    }
    int position = 0;

    for (int i = 1; i < n; i++)
    {
        if (players[i].getWinPercentage() >
            players[position].getWinPercentage())
        {
            position = i;
        }
    }
    cout << "\n MOST CONSISTENT PLAYER\n";
    players[position].displayPlayer();
}
void findChampion(Player players[], int n)
{
    if (n == 0)
    {
        cout << "\nNo players available.\n";
        return;
    }
    int position = 0;
    for (int i = 1; i < n; i++)
    {
        if (players[i].getTotalPoints() >
            players[position].getTotalPoints())
        {
            position = i;
        }
    }
    cout << "\nLEAGUE CHAMPION\n";
    players[position].displayPlayer();
}
int main()
{
    int n;
    cout << "Enter number of players: ";
    cin >> n;
    Player players[100];
    for (int i = 0; i < n; i++)
    {
        cout << "\nPLAYER " << i + 1 << "\n";
        players[i].inputPlayer();
        for (int j = 0; j < i; j++)
        {
            if (players[i].getPlayerID() ==
                players[j].getPlayerID())
            {
                cout << "Duplicate Player ID!\n";
                cout << "Please enter a different ID.\n";
                i--;
                break;
            }
        }
    }
    int choice;
    do
    {
        cout << "\n GAMING LEAGUE MANAGEMENT SYSTEM";
        cout << "\n1. Display All Players";
        cout << "\n2. Search Player";
        cout << "\n3. Record Match Result";
        cout << "\n4. Update Score";
        cout << "\n5. Compare Players";
        cout << "\n6. Display Leaderboard";
        cout << "\n7. Top Player";
        cout << "\n8. Highest Scorer";
        cout << "\n9. Most Consistent Player";
        cout << "\n10. League Champion";
        cout << "\n11. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
                displayAllPlayers(players, n);
                break;
            case 2:
            {
                int id;
                cout << "\nEnter Player ID: ";
                cin >> id;
                int position = searchPlayer(players, n, id);
                if (position == -1)
                {
                    cout << "Player not found!\n";
                }
                else
                {
                    players[position].displayPlayer();
                }
                break;
            }
            case 3:
                recordMatch(players, n);
                break;
            case 4:
                updatePlayerScore(players, n);
                break;
            case 5:
                comparePlayers(players, n);
                break;
            case 6:
                displayLeaderboard(players, n);
                break;
            case 7:
                findTopPlayer(players, n);
                break;
            case 8:
                findHighestScorer(players, n);
                break;
            case 9:
                findMostConsistent(players, n);
                break;
            case 10:
                findChampion(players, n);
                break;
            case 11:
                cout << "\nThank you!\n";
                break;
            default:
                cout << "\nInvalid menu choice!\n";
        }
    } while (choice != 11);
    return 0;
}